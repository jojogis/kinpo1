#ifndef SENTENCE_H
#define SENTENCE_H
#include "QList"
#include "token.h"


class Sentence
{
public:
    Sentence();
    QList<Token> tokens;
    const Token& Sentence::getById(int id) const;
    Token& Sentence::getById(int id);
    QString getString() const;
};

#endif // SENTENCE_H
