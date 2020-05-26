#ifndef RULES_H
#define RULES_H

#include "sentence.h"



class Rules
{
public:
    Rules();
    static void checkRule1(QHash<QString,QString> &profNames,Sentence sentence);
    static void checkRule2(QHash<QString,QString> &profNames,Sentence sentence);
    static void checkRule3(QHash<QString,QString> &profNames,Sentence sentence,QStringList profList);
    static void checkRule4(QHash<QString,QString> &profNames,Sentence sentence);
    static void checkRule5(QHash<QString, QString> &profNames, Sentence sentence);
    static void checkRule6(QHash<QString, QString> &profNames, Sentence sentence);
    static void checkRule7(QHash<QString, QString> &profNames, Sentence sentence);
    static void checkRule8(QHash<QString, QString> &profNames, Sentence sentence,QStringList profList);
};

#endif // RULES_H
