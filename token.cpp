#include "token.h"

Token::Token(QString word,QString lemma,int id,QString pos,QString ner)
{
    this->word = word;
    this->id = id;
    this->lemma = lemma;
    this->setPOS(pos);
    this->setNER(ner);
}
void Token::setPOS(QString str){
    this->pos = (POS)POSStr.indexOf(str);
}

void Token::setDep(QString type, int id)
{
    if(type=="compound"){
        this->compoundDep = id;
    }else if(type=="amod"){
        this->amodDep = id;
    }else if(type=="appos"){
        this->apposDep = id;
    }else if(type=="punct"){
        this->punctDep = id;
    }else if(type=="nmod"){
        this->nmodDep = id;
    }else if(type=="case"){
        this->caseDep= id;
    }else if(type=="nsubj"){
        this->nsubjDep= id;
    }else if(type=="obj"){
        this->objDep= id;
    }
}
void Token::setNER(QString str){
    this->ner = (NER)NERStr.indexOf(str);
}

bool Token::isNeededDep(QString str){
    QStringList list = {"compound","amod","appos","punct","nmod","case","nsubj","obj"};
    return list.indexOf(str) != -1;
}
