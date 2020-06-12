#ifndef RULES_H
#define RULES_H

#include "sentence.h"



class Rules
{
public:
    Rules();
    static void checkRuleCompound(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    static void checkRuleAmod(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    static void checkRuleToBe(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    static void checkRuleAppos1(QMultiHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    static void checkRuleAppos2(QMultiHash<QString, QString> &profNames,const  Sentence &sentence,const QStringList &profList);
    static void checkRuleToWork(QMultiHash<QString, QString> &profNames,const  Sentence &sentence,const QStringList &profList);
    static void checkRuleReignOf(QMultiHash<QString, QString> &profNames,const  Sentence &sentence);
    static void checkRuleJob(QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList);
    static void checkRuleToPractice (QMultiHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList);
    static void getCompoundProf(const Sentence &sentence, int id, QString &res,const QStringList &profList);
    static bool isInProfList(const Token prof,const QStringList &profList);
    static void checkForAnd(const Sentence &sentence, int id,const QStringList &profList,QMultiHash<QString, QString> &profNames,const QString name);
    static bool isNN(const Token token);
    static void analyzeFileWithNames(QStringList names,QMultiHash<QString,QString> &profNames,const QStringList &perpList);
};

#endif // RULES_H
