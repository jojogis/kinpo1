#ifndef SENTENCE_H
#define SENTENCE_H
#include "QList"
#include "token.h"


class Sentence
{
public:
    Sentence();
    QList<Token> tokens;
    Token& getById(int id);
};

#endif // SENTENCE_H
