#include "rules.h"

#include <QHash>

Rules::Rules()
{

}

void Rules::checkRule1(QHash<QString,QString> &profNames,Sentence sentence)
{
    foreach(Token token,sentence.tokens){
        if((token.pos == Token::NN || token.pos == Token::NNP) && token.ner == Token::PERSON &&
                token.compoundDep != -1 &&
                (sentence.getById(token.compoundDep).pos == Token::NN || sentence.getById(token.compoundDep).pos == Token::NNP)
                && sentence.getById(token.compoundDep).ner == Token::TITLE){

            profNames.insert(token.word,sentence.getById(token.compoundDep).word);
        }
    }
}
void Rules::checkRule2(QHash<QString,QString> &profNames,Sentence sentence)
{
    foreach(Token token,sentence.tokens){
        if((token.pos == Token::NN || token.pos == Token::NNP) && token.ner == Token::PERSON &&
                token.amodDep != -1 &&
                (sentence.getById(token.amodDep).pos == Token::NN || sentence.getById(token.amodDep).pos == Token::NNP)
                && sentence.getById(token.amodDep).ner == Token::TITLE &&
                sentence.getById(token.amodDep).word[0].isUpper()){

            profNames.insert(token.word,sentence.getById(token.amodDep).word);
        }
    }
}
void Rules::checkRule3(QHash<QString,QString> &profNames,Sentence sentence,QStringList profList)
{
    for(int i = 0; i<sentence.tokens.size() - 2;i++){
        if((sentence.tokens[i].pos == Token::NN || sentence.tokens[i].pos == Token::NNP) &&
                sentence.tokens[i].ner == Token::PERSON && sentence.tokens[i+1].lemma == "be" &&
                (sentence.tokens[i+2].pos == Token::NN || sentence.tokens[i+2].pos == Token::NNP) &&
                (sentence.tokens[i+2].ner == Token::TITLE || profList.indexOf(sentence.tokens[i+2].lemma) != -1)){
                profNames.insert(sentence.tokens[i].word,sentence.tokens[i+2].word);
        }
    }
}

void Rules::checkRule4(QHash<QString, QString> &profNames, Sentence sentence)
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
void Rules::checkRule5(QHash<QString, QString> &profNames, Sentence sentence)
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

void Rules::checkRule6(QHash<QString, QString> &profNames, Sentence sentence)
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

void Rules::checkRule7(QHash<QString, QString> &profNames, Sentence sentence)
{
    for(int i = 1; i<sentence.tokens.size();i++){
        if((sentence.tokens[i].pos == Token::NN || sentence.tokens[i].pos == Token::NNP) &&
                sentence.tokens[i].ner == Token::PERSON && sentence.tokens[i-1].lemma == "reign"){

                profNames.insert(sentence.tokens[i].word,"King");
        }
    }
}

void Rules::checkRule8(QHash<QString, QString> &profNames, Sentence sentence,QStringList profList){
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
