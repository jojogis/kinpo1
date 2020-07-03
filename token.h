/*!
    \file
    \brief файл, содержащий описание класса Token
*/

#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include <QStringList>
#include <qhash.h>


/*!
    \brief Класс, описывающий слово
*/
class Token
{
public:
    /// Набор возможных частей речи
    enum POS{
        NN,///<существительное, единственное или множественное
        NNP,///<существительное, единственное число
        JJ ///<прилагательное
    };
    ///Строковые обозначения возможных частей речи
    QStringList POSStr = { "NN","NNP","JJ" };
    enum NER{
        PERSON,TITLE
    };
    QStringList NERStr = {"PERSON","TITLE"};
    ///набор возможных зависимостей
    enum DEPS{COMPOUND,AMOD,APPOS,PUNCT,NMOD,CASE,NSUBJ,OBJ};



    QString word;///<текст слова
    QString lemma;///<текст слова в начальной форме
    POS pos;///<часть речи
    NER ner;
    int id;///<id слова в предложении
    Token(QString word,QString lemma,int id,QString pos,QString ner);
    /*!
    \brief Проверяет, нужна ли зависимость с данным именем
    \param[in] имя зависимости
    \return true - если нужна, иначе - false
    */
    static bool isNeededDep(QString str);
    /*!
    \brief Устанавливает часть речи
    \param[in] str имя части речи
    */
    void setPOS(QString str);
    int compoundDep = -1;///<id зависимого слова по compound
    int amodDep= -1;///<id зависимого слова по amod
    int apposDep= -1;///<id зависимого слова по appos
    int punctDep= -1;///<id зависимого слова по punct
    int nmodDep= -1;///<id зависимого слова по nmod
    int caseDep= -1;///<id зависимого слова по case
    int nsubjDep= -1;///<id зависимого слова по nsubj
    int objDep= -1;///<id зависимого слова по obj
    /*!
    \brief Устанавливает зависимость
    \param [in] type имя зависимости
    \param [in] id id зависимого слова
    */
    void setDep(QString type,int id);
    void setNER(QString str);

};

#endif // TOKEN_H
