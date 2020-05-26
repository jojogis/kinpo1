#include "sentence.h"

Sentence::Sentence()
{

}
Token& Sentence::getById(int id){
    for(int i = 0; i < tokens.size();i++){
        if(tokens.at(i).id == id)return tokens[i];
    }
    return tokens[0];
}
