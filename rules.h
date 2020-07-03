/*!
    \file
    \brief файл, содержащий описание класса Rules
*/
#ifndef RULES_H
#define RULES_H

#include "sentence.h"


/*!
    \brief Класс, содержащий в себе все правила для обработки предложений
*/
class Rules
{
public:
    Rules();
    /*!
        \brief Функция поиска профессии по связи Compound.
        Если часть речи – NN или NNP и тег аннотатора NER – person и присутствует compoundDep и он связывает часть речи
        – NN или NNP со словом с тегом TITLE
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
        \param [in] profList список профессий
    */
    static void checkRuleCompound(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    /*!
        \brief Функция поиска профессии по связи Amod.
        Если часть речи – NN или NNP и тег аннотатора NER – person и присутствует amodDep
        и он связывает часть речи – NN или NNP со словом с тегом TITLE и это слово с заглавной буквы
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
        \param [in] profList список профессий
    */
    static void checkRuleAmod(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    /*!
        \brief Функция поиска профессии по устойчивому выражению to be + a(an)
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
        \param [in] profList список профессий
    */
    static void checkRuleToBe(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    /*!
        \brief Функция поиска профессии по связи Appos и punct, которая является связью от NNP(Person)
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
        \param [in] profList список профессий
    */
    static void checkRuleAppos1(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    /*!
        \brief Функция поиска профессии по связи Appos и punct, которая является связью от NN(Title)
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
        \param [in] profList список профессий
    */
    static void checkRuleAppos2(QMultiHash<QString, QString> &profNames,const  Sentence &sentence,const QStringList &profList);
    /*!
        \brief Функция поиска профессии по устойчивому выражению to work + as a(an)
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
        \param [in] profList список профессий
    */
    static void checkRuleToWork(QMultiHash<QString, QString> &profNames,const  Sentence &sentence,const QStringList &profList);
    /*!
        \brief Функция поиска профессии по устойчивому выражению reign of
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
    */
    static void checkRuleReignOf(QMultiHash<QString, QString> &profNames,const  Sentence &sentence);
    /*!
        \brief Функция поиска профессии по устойчивому выражению job + to be
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
        \param [in] profList список профессий
    */
    static void checkRuleJob(QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList);
    /*!
        \brief Функция поиска профессии по устойчивому выражению to practice
        \param [in,out] profNames список пар имя-профессия
        \param [in] sentence предложение
        \param [in] profList список профессий
    */
    static void checkRuleToPractice (QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList);

    /*!
        \brief Собирает составную профессию
        \param [in] sentence предложение
        \param [in] id id найденной профессии
        \param [in] profList список профессий
        \param [out] res составная профессия, если найдена, иначе - изначальная профессия
    */
    static void getCompoundProf(const Sentence &sentence, int id, QString &res,const QStringList &profList);
    /*!
        \brief Проверяет, есть ли слово в списке профессий
        \param [in] prof слово
        \param [in] profList список профессий
        \return true - если есть, иначе - false
    */
    static bool isInProfList(const Token prof,const QStringList &profList);
    /*!
        \brief Проверяет, на наличие еще одной профессии, отделенной союзом and
        \param [in] sentence предложение
        \param [in] id id найденной профессии
        \param [in] profList список профессий
        \param [in,out] profNames список пар имя-профессия
        \param [in] name имя для найденной професии
    */
    static void checkForAnd(const Sentence &sentence, int id,const QStringList &profList,QMultiHash<QString, QString> &profNames,const QString name);

    /*!
        \brief Проверяет, явлется ли слово подлежащим
        \param [in] token слово
        \return true, если является, иначе - false
    */
    static bool isNN(const Token token);
    /*!
        \brief Производит анализ файла с именами на содержание профессий в именах
        \param [in] names список имен
        \param [in,out] profNames список пар имя-профессия
        \param [in] perpList список приставок
    */
    static void analyzeFileWithNames(QStringList names,QMultiHash<QString,QString> &profNames,const QStringList &perpList);
};

#endif // RULES_H
