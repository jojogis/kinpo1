/*!
    \file
    \brief Файл, содержащий реализацию класса Sentence
*/
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
/*!
    \brief Возвращает слово, по заданному id
    \param [in] id id нужного слова
    \return слово - экземпляр класса Token
*/
Token& Sentence::getById(int id)
{
    for(int i = 0; i < tokens.size();i++){
        if(tokens.at(i).id == id)return tokens[i];
    }
    return tokens[0];
}
/*!
    \brief Возвращает строковое представление предложения
    \return предложение в обычном виде
*/
QString Sentence::getString() const
{
    QString res;
    for(int i = 0; i < tokens.size();i++){
        res += tokens.at(i).word + " ";
    }
    return res.left(res.size() - 1);
}
