#include "rules.h"

#include <QHash>

Rules::Rules()
{

}

void Rules::checkRuleCompound(QHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if((token.pos == Token::NN || token.pos == Token::NNP) && token.ner == Token::PERSON &&
                token.compoundDep != -1 &&
                (sentence.getById(token.compoundDep).pos == Token::NN || sentence.getById(token.compoundDep).pos == Token::NNP)
                && (sentence.getById(token.compoundDep).ner == Token::TITLE ||
                isInProfList(sentence.getById(token.compoundDep).lemma,profList) ) ){
            QString prof;
            getCompoundProf(sentence,token.compoundDep,prof,profList);
            profNames.insert(token.word,prof);
        }
    }
}
void Rules::checkRuleAmod(QHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if((token.pos == Token::NN || token.pos == Token::NNP) && token.ner == Token::PERSON &&
                token.amodDep != -1 &&
                sentence.getById(token.amodDep).pos == Token::JJ
                && sentence.getById(token.amodDep).ner == Token::TITLE &&
                sentence.getById(token.amodDep).word[0].isUpper()){
            QString prof;
            getCompoundProf(sentence,token.amodDep,prof,profList);
            profNames.insert(token.word,prof);
        }
    }
}
void Rules::checkRuleToBe(QHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList)
{
    for(int i = 0; i<sentence.tokens.size() - 2;i++){
        if((sentence.tokens[i].pos == Token::NN || sentence.tokens[i].pos == Token::NNP) &&
                sentence.tokens[i].ner == Token::PERSON && sentence.tokens[i+1].lemma == "be" &&
                (sentence.tokens[i+2].pos == Token::NN || sentence.tokens[i+2].pos == Token::NNP) &&
                (sentence.tokens[i+2].ner == Token::TITLE || profList.indexOf(sentence.tokens[i+2].lemma) != -1)){
                profNames.insert(sentence.tokens[i].word,sentence.tokens[i+2].word);
        }
    }
    for(int i = 0; i<sentence.tokens.size() - 3;i++){
        if((sentence.tokens[i].pos == Token::NN || sentence.tokens[i].pos == Token::NNP) &&
                sentence.tokens[i].ner == Token::PERSON && sentence.tokens[i+1].lemma == "be" &&
                sentence.tokens[i+2].lemma == "a" &&
                (sentence.tokens[i+3].pos == Token::NN || sentence.tokens[i+3].pos == Token::NNP) &&
                (sentence.tokens[i+3].ner == Token::TITLE || profList.indexOf(sentence.tokens[i+2].lemma) != -1)){
                profNames.insert(sentence.tokens[i].word,sentence.tokens[i+3].word);
        }
    }
}

void Rules::checkRuleAppos1 (QHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if((token.pos == Token::NN || token.pos == Token::NNP) && token.ner == Token::PERSON &&
                token.apposDep != -1 &&
                (sentence.getById(token.apposDep).pos == Token::NN || sentence.getById(token.apposDep).pos == Token::NNP)
                && sentence.getById(token.apposDep).ner == Token::TITLE && token.punctDep != -1){

            profNames.insert(token.word,sentence.getById(token.apposDep).word);
        }
    }
}
void Rules::checkRuleAppos2(QHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if((token.pos == Token::NN || token.pos == Token::NNP) && token.ner == Token::PERSON &&
                token.apposDep != -1 &&
                (sentence.getById(token.apposDep).pos == Token::NN || sentence.getById(token.apposDep).pos == Token::NNP)
                && sentence.getById(token.apposDep).ner == Token::TITLE && sentence.getById(token.apposDep).punctDep != -1){

            profNames.insert(token.word,sentence.getById(token.apposDep).word);
        }
    }
}

void Rules::checkRuleToWork(QHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if(token.lemma == "work" && token.nsubjDep != -1 && token.objDep != -1){
            Token person = sentence.getById(token.nsubjDep);
            Token title = sentence.getById(token.objDep);
            if((person.pos == Token::NN || person.pos == Token::NNP) && person.ner == Token::PERSON &&
                    (title.pos == Token::NN || title.pos == Token::NNP) && title.ner == Token::TITLE){
                profNames.insert(person.word,title.word);
            }

        }
    }
}

void Rules::checkRuleReignOf(QHash<QString, QString> &profNames, const Sentence &sentence)
{
    for(int i = 1; i<sentence.tokens.size();i++){
        if((sentence.tokens[i].pos == Token::NN || sentence.tokens[i].pos == Token::NNP) &&
                sentence.tokens[i].ner == Token::PERSON && sentence.tokens[i-1].lemma == "reign"){

                profNames.insert(sentence.tokens[i].word,"King");
        }
    }
}

void Rules::checkRuleJob(QHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList){
    foreach(Token token,sentence.tokens){
        if((token.pos == Token::NN || token.pos == Token::NNP) &&
                (token.ner == Token::TITLE || profList.indexOf(token.lemma) != -1) &&
                token.nsubjDep != -1 &&
                (sentence.getById(token.nsubjDep).pos == Token::NN || sentence.getById(token.nsubjDep).pos == Token::NNP) &&
                sentence.getById(token.nsubjDep).lemma == "job"){
            Token job = sentence.getById(token.nsubjDep);
            if((job.pos == Token::NN || job.pos == Token::NNP) && job.nmodDep != -1 &&
                    (sentence.getById(job.nmodDep).pos == Token::NN || sentence.getById(job.nmodDep).pos == Token::NNP) &&
                    sentence.getById(job.nmodDep).ner == Token::PERSON){
                Token person = sentence.getById(job.nmodDep);
                if(person.caseDep != -1 && sentence.getById(person.caseDep).lemma == "'s"){
                    profNames.insert(person.word,token.word);
                }

            }
        }
    }
}

void Rules::getCompoundProf(const Sentence &sentence, int id, QString &res,const QStringList &profList)
{
    //int depId = sentence.getById(id).compoundDep;
    //if(depId != -1){
    //    if(id < depId)res = sentence.getById(id).word + " " + sentence.getById(depId).word;
    //    else res = sentence.getById(depId).word + " " + sentence.getById(id).word;
    //}else{
    //    res = sentence.getById(id).word;
    //}
    QString curWord = sentence.getById(id).word;
    if(id != 0){
        QString prevWordProf = sentence.getById(id - 1).word + " " + curWord;
        if(profList.contains(prevWordProf.toLower())){
            res = prevWordProf;
            return;
        }
    }
    QString nextWordProf = curWord + " " + sentence.getById(id + 1).word;
    if(profList.contains(nextWordProf.toLower())){
        res = nextWordProf;
        return;
    }
    res = curWord;
}

bool Rules::isInProfList(const QString prof, const QStringList &profList)
{
    QString profLower = prof.toLower();
    for(QString profInList : profList){
        if(profInList.split(' ').contains(profLower))return true;
    }
    return false;
}
