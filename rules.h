#ifndef RULES_H
#define RULES_H

#include "sentence.h"



class Rules
{
public:
    Rules();
    static void checkRuleCompound(QHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    static void checkRuleAmod(QHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    static void checkRuleToBe(QHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    static void checkRuleAppos1(QHash<QString,QString> &profNames,const Sentence &sentence,const QStringList &profList);
    static void checkRuleAppos2(QHash<QString, QString> &profNames,const  Sentence &sentence,const QStringList &profList);
    static void checkRuleToWork(QHash<QString, QString> &profNames,const  Sentence &sentence,const QStringList &profList);
    static void checkRuleReignOf(QHash<QString, QString> &profNames,const  Sentence &sentence);
    static void checkRuleJob(QHash<QString, QString> &profNames, const Sentence &sentence,const QStringList &profList);
    static void checkRuleToPractice (QHash<QString, QString> &profNames, const Sentence &sentence);
    static void getCompoundProf(const Sentence &sentence, int id, QString &res,const QStringList &profList);
    static bool isInProfList(const QString prof,const QStringList &profList);

};

#endif // RULES_H
