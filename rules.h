#ifndef RULES_H
#define RULES_H

#include "sentence.h"



class Rules
{
public:
    Rules();
    static void checkRuleCompound(QHash<QString,QString> &profNames,Sentence &sentence);
    static void checkRuleAmod(QHash<QString,QString> &profNames,Sentence &sentence);
    static void checkRuleToBe(QHash<QString,QString> &profNames,Sentence &sentence,QStringList &profList);
    static void checkRuleAppos1(QHash<QString,QString> &profNames,Sentence &sentence);
    static void checkRuleAppos2(QHash<QString, QString> &profNames, Sentence &sentence);
    static void checkRuleToWork(QHash<QString, QString> &profNames, Sentence &sentence);
    static void checkRuleReignOf(QHash<QString, QString> &profNames, Sentence &sentence);
    static void checkRuleJob(QHash<QString, QString> &profNames, Sentence &sentence,QStringList &profList);
};

#endif // RULES_H
