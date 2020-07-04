/*!
    \file
    \brief Файл, содержищий реализацию класса Rules
*/
#include "rules.h"

#include <QHash>

Rules::Rules()
{

}
/*!
    \brief Функция поиска профессии по связи Compound.
    Если часть речи – NN или NNP
    и тег аннотатора NER – person и присутствует compoundDep и он связывает часть речи
    – NN или NNP со словом с тегом TITLE
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
    \param [in] profList список профессий
*/
void Rules::checkRuleCompound(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if(isNN(token) && token.ner == Token::PERSON &&
                token.compoundDep != -1 &&
                isNN(sentence.getById(token.compoundDep))
                && isInProfList(sentence.getById(token.compoundDep),profList) ){
            QString prof;
            getCompoundProf(sentence,token.compoundDep,prof,profList);
            profNames.insert(token.word,prof);
        }
    }
}
/*!
    \brief Функция поиска профессии по связи Amod.
    Если часть речи – NN или NNP и тег аннотатора NER – person и присутствует amodDep
    и он связывает часть речи – NN или NNP со словом с тегом TITLE и это слово с заглавной буквы
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
    \param [in] profList список профессий
*/
void Rules::checkRuleAmod(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if(isNN(token) && token.ner == Token::PERSON &&
                token.amodDep != -1 &&
                sentence.getById(token.amodDep).pos == Token::JJ
                && sentence.getById(token.amodDep).ner == Token::TITLE &&
                sentence.getById(token.amodDep).word[0].isUpper()){
            QString prof;
            getCompoundProf(sentence,token.amodDep,prof,profList);
            checkForAnd(sentence,token.amodDep,profList,profNames,token.word);
            profNames.insert(token.word,prof);
        }
    }
}
/*!
    \brief Функция поиска профессии по устойчивому выражению to be + a(an)
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
    \param [in] profList список профессий
*/
void Rules::checkRuleToBe(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList)
{
    for(int i = 0; i<sentence.tokens.size() - 2;i++){
        if(isNN(sentence.tokens[i]) &&
                sentence.tokens[i].ner == Token::PERSON && sentence.tokens[i+1].lemma == "be" &&
                isNN(sentence.tokens[i+2]) &&
                isInProfList(sentence.tokens[i+2],profList)){
                checkForAnd(sentence,i+3,profList,profNames,sentence.tokens[i].word);
                QString prof;
                getCompoundProf(sentence,sentence.tokens[i+2].id,prof,profList);
                profNames.insert(sentence.tokens[i].word,sentence.tokens[i+2].word);
        }
    }
    for(int i = 0; i<sentence.tokens.size() - 3;i++){
        if(isNN(sentence.tokens[i]) &&
                sentence.tokens[i].ner == Token::PERSON && sentence.tokens[i+1].lemma == "be" &&
                sentence.tokens[i+2].lemma == "a" &&
                isNN(sentence.tokens[i+3]) &&
                isInProfList(sentence.tokens[i+3],profList)){
                checkForAnd(sentence,i+4,profList,profNames,sentence.tokens[i].word);
                QString prof;
                getCompoundProf(sentence,sentence.tokens[i+3].id,prof,profList);
                profNames.insert(sentence.tokens[i].word,prof);
        }
    }


}
/*!
    \brief Функция поиска профессии по связи Appos и punct, которая является связью от NNP(Person)
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
    \param [in] profList список профессий
*/
void Rules::checkRuleAppos1 (QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if(isNN(token) && token.ner == Token::PERSON &&
                token.apposDep != -1 &&
                isNN(sentence.getById(token.apposDep))
                && sentence.getById(token.apposDep).ner == Token::TITLE && token.punctDep != -1){
            checkForAnd(sentence,token.apposDep,profList,profNames,token.word);
            QString prof;
            getCompoundProf(sentence,token.apposDep,prof,profList);
            profNames.insert(token.word,prof);
        }
    }
}
/*!
    \brief Функция поиска профессии по связи Appos и punct, которая является связью от NN(Title)
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
    \param [in] profList список профессий
*/
void Rules::checkRuleAppos2(QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if(isNN(token) && isInProfList(token,profList) &&
                token.apposDep != -1 &&
                isNN(sentence.getById(token.apposDep))
                && sentence.getById(token.apposDep).ner == Token::PERSON && token.punctDep != -1){
            checkForAnd(sentence,token.id,profList,profNames,sentence.getById(token.apposDep).word);
            QString prof;
            getCompoundProf(sentence,token.id,prof,profList);
            profNames.insert(sentence.getById(token.apposDep).word,prof);
        }
    }
}
/*!
    \brief Функция поиска профессии по устойчивому выражению to work + as a(an)
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
    \param [in] profList список профессий
*/
void Rules::checkRuleToWork(QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if(token.lemma == "work" && token.nsubjDep != -1 && token.objDep != -1){
            Token person = sentence.getById(token.nsubjDep);
            Token title = sentence.getById(token.objDep);
            if(isNN(person) && person.ner == Token::PERSON &&
                    isNN(title) && title.ner == Token::TITLE){
                QString prof;
                getCompoundProf(sentence,token.objDep,prof,profList);
                checkForAnd(sentence,token.objDep,profList,profNames,person.word);
                profNames.insert(person.word,prof);
            }

        }
    }
}
/*!
    \brief Функция поиска профессии по устойчивому выражению reign of
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
*/
void Rules::checkRuleReignOf(QMultiHash<QString, QString> &profNames, const Sentence &sentence)
{
    for(int i = 2; i<sentence.tokens.size();i++){
        if(isNN(sentence.tokens[i]) &&
                sentence.tokens[i].ner == Token::PERSON && sentence.tokens[i-2].lemma == "reign"){

                profNames.insert(sentence.tokens[i].word,"King");
                if(i < sentence.tokens.size() - 2 && sentence.tokens[i+1].lemma == "and"){
                    profNames.insert(sentence.tokens[i+2].word,"King");
                }
        }
    }
}
/*!
    \brief Функция поиска профессии по устойчивому выражению job + to be
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
    \param [in] profList список профессий
*/
void Rules::checkRuleJob(QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if(isNN(token) &&
                isInProfList(token,profList) &&
                token.nsubjDep != -1 &&
                isNN(sentence.getById(token.nsubjDep)) &&
                sentence.getById(token.nsubjDep).lemma == "job"){
            Token job = sentence.getById(token.nsubjDep);
            if(isNN(job) && job.nmodDep != -1 &&
                    isNN(sentence.getById(job.nmodDep)) &&
                    sentence.getById(job.nmodDep).ner == Token::PERSON){
                Token person = sentence.getById(job.nmodDep);
                if(person.caseDep != -1 && sentence.getById(person.caseDep).lemma == "'s"){
                    QString prof;

                    checkForAnd(sentence,token.id,profList,profNames,person.word);
                    getCompoundProf(sentence,token.id,prof,profList);
                    profNames.insert(person.word,prof);

                }

            }
        }
    }
}
/*!
    \brief Функция поиска профессии по устойчивому выражению to practice
    \param [in,out] profNames список пар имя-профессия
    \param [in] sentence предложение
    \param [in] profList список профессий
*/
void Rules::checkRuleToPractice(QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList)
{
    foreach(Token token,sentence.tokens){
        if(token.lemma == "practice" && token.nsubjDep != -1 && token.objDep != -1){
            Token person = sentence.getById(token.nsubjDep);
            Token title = sentence.getById(token.objDep);
            if(isNN(person) && person.ner == Token::PERSON &&
                    isNN(title) && title.ner == Token::TITLE){
                QString prof;
                getCompoundProf(sentence,token.objDep,prof,profList);
                checkForAnd(sentence,token.objDep,profList,profNames,person.word);
                profNames.insert(person.word,prof);
            }

        }
    }
}
/*!
    \brief Собирает составную профессию
    \param [in] sentence предложение
    \param [in] id id найденной профессии
    \param [in] profList список профессий
    \param [out] res составная профессия, если найдена, иначе - изначальная профессия
*/
void Rules::getCompoundProf(const Sentence &sentence, int id, QString &res,const QStringList &profList)
{

    QString curWord = sentence.getById(id).word.toLower();

    for(QString profInList : profList){
        if(profInList.split(' ').contains(curWord,Qt::CaseInsensitive)){
            if(sentence.getString().contains(profInList,Qt::CaseInsensitive)){
                res = profInList;
                return;
            }
        }
    }
    if(sentence.getById(id+1).ner == Token::TITLE){
        res = curWord + " " +sentence.getById(id+1).word;
        return;
    }
    if(sentence.getById(id-1).ner == Token::TITLE){
        res = sentence.getById(id-1).word + " " + curWord;
        return;
    }

    res = curWord;
}
/*!
    \brief Проверяет, на наличие еще одной профессии, отделенной союзом and
    \param [in] sentence предложение
    \param [in] id id найденной профессии
    \param [in] profList список профессий
    \param [in,out] profNames список пар имя-профессия
    \param [in] name имя для найденной професии
*/
void Rules::checkForAnd(const Sentence &sentence, int id,const QStringList &profList,QMultiHash<QString, QString> &profNames,const QString name)
{
    if(sentence.getById(id + 1).lemma == "and"){
        if(sentence.getById(id + 2).lemma == "a" && isInProfList(sentence.getById(id + 3),profList)){
            profNames.insert(name,sentence.getById(id + 3).lemma);
        }else if(isInProfList(sentence.getById(id + 2),profList)){
            profNames.insert(name,sentence.getById(id + 2).lemma);
        }
    }
}
/*!
    \brief Проверяет, явлется ли слово подлежащим
    \param [in] token слово
    \return true, если является, иначе - false
*/
bool Rules::isNN(const Token &token)
{
    return token.pos == Token::NN || token.pos == Token::NNP;
}
/*!
    \brief Проверяет, есть ли слово в списке профессий
    \param [in] prof слово
    \param [in] profList список профессий
    \return true - если есть, иначе - false
*/
bool Rules::isInProfList(const Token &prof, const QStringList &profList)
{
    if(prof.ner == Token::TITLE)return true;
    QString profLower = prof.lemma.toLower();
    for(QString profInList : profList){
        if(profInList.split(' ').contains(profLower,Qt::CaseInsensitive))return true;
    }
    return false;
}

/*!
    \brief Производит анализ файла с именами на содержание профессий в именах
    \param [in] names список имен
    \param [in,out] profNames список пар имя-профессия
    \param [in] perpList список приставок
*/
void Rules::analyzeFileWithNames(QStringList names,QMultiHash<QString,QString> &profNames,const QStringList &perpList)
{
    foreach (QString name, names) {
        foreach(QString prof,perpList){
            if(name.toLower().indexOf(prof) != -1){
                profNames.insert(name.toLower().remove(prof),prof);
            }
        }
    }
}
