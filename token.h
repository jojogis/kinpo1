#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include <QStringList>



class Token
{
public:
    enum POS{
        NN,NNP,PRP,DT,VBD,VBN,JJ,CC,IN,WDT
    };
    QStringList POSStr = { "NN","NNP","PRP","DT","VBD","VBN","JJ","CC","IN","WDT" };
    enum NER{
        PERSON,TIME,O,TITLE,DATE
    };
    QStringList NERStr = {"PERSON","TIME","O","TITLE","DATE"};

    QString word;
    QString lemma;
    POS pos;
    NER ner;
    int id;
    Token(QString word,QString lemma,int id);
    static bool isNeededDep(QString str);
    void setPOS(QString str);
    int compoundDep = -1;
    int amodDep = -1;
    int apposDep = -1;
    int punctDep = -1;
    int nmodDep = -1;
    int caseDep = -1;
    int nsubjDep = -1;
    int objDep = -1;
    void setDep(QString type,int id);
    void setNER(QString str);

};

#endif // TOKEN_H
