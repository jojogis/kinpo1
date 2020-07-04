/*!
    \file
    \brief файл, содержащий описание класса Sentence
*/
#ifndef SENTENCE_H
#define SENTENCE_H
#include "QList"
#include "token.h"

/*!
    \brief Класс, описывающий предложение
*/
class Sentence
{
public:
    Sentence();
    QList<Token> tokens;///< список слов, входящих в предложение

    const Token& getById(int id) const;
    /*!
        \brief Возвращает слово, по заданному id
        \param[in] id id нужного слова
        \return слово - экземпляр класса Token
    */
    Token& getById(int id);
    /*!
        \brief Возвращает строковое представление предложения
        \return предложение в обычном виде
    */
    QString getString() const;
};

#endif // SENTENCE_H
