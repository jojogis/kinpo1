#include "sentence.h"

Sentence::Sentence()
{

}
const Token& Sentence::getById(int id) const{
    for(int i = 0; i < tokens.size();i++){
        if(tokens.at(i).id == id)return tokens.at(i);
    }
    return tokens.at(0);
}
Token& Sentence::getById(int id){
    for(int i = 0; i < tokens.size();i++){
        if(tokens.at(i).id == id)return tokens[i];
    }
    return tokens[0];
}

QString Sentence::getString() const
{
    QString res;
    for(int i = 0; i < tokens.size();i++){
        res += tokens.at(i).word + " ";
    }
    return res.left(res.size() - 1);
}
