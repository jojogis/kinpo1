/*!
\file
\brief Заголовочный файл главной функции
*/


#ifndef MAIN_H
#define MAIN_H
#include "sentence.h"
#include "rules.h"
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDomDocument>


void readFileWithTextFast(QString fileName,QString &error,QList<Sentence> &res);
/*!
\brief Читает файл со списком профессий
\param[in] fileName имя файла
\param[out] error текст ошибки
\param[out] res список профессий
\throw 11 Недопустимый формат файла со списком профессий
\throw 12 Ошибка открытия файла со списком профессий: {описание системной ошибки}
\throw 13 Ошибка файла со списком профессий: Файл должен содержать только латиницу
*/
void readFileWithProfessions(QString fileName,QString &error,QStringList &res);
/*!
\brief Читает файл с разбором текста
\param[in] fileName имя файла
\param[out] error текст ошибки
\param[out] res список предложений
\throw 1 Недопустимый формат файла с разбором текста
\throw 2 Ошибка открытия файла с текстом: {описание системной ошибки}
\throw 7 Ошибка открытия файла с текстом: Не удается найти тэг «pos»
\throw 8 Ошибка открытия файла с текстом: Не удается найти тэг «dependencies»
\throw 9 Ошибка открытия файла с текстом: Не удается найти тэг «sentence»
*/
void readFileWithText(QString fileName,QString &error,QList<Sentence> &res);
/*!
\brief Читает файл со списком имен
\param[in] fileName имя файла
\param[out] error текст ошибки
\param[out] res список имен
\throw 3 Недопустимый формат файла со списком персонажей
\throw 4 Ошибка открытия файла со списком персонажей: {описание системной ошибки}
\throw 5 Пустой файл со списком имен
\throw 6 Ошибка файла со списком персонажей: Файл должен содержать только латиницу
*/
void readFileWithNames(QString fileName,QString &error,QStringList &res);
/*!
\brief Удаляет одинаковые пары имя-профессия
\param[in,out] hash список имен - профессий
*/
void removeEqualPairs(QMultiHash<QString,QString> &hash);
/*!
\brief Выводит результат в Xml файл
\param[in] fileName имя файла
\param[in] hash список пар имя-профессия
*/
void writeResultToXml(const QString filename,const QMultiHash<QString,QString> &hash);
/*!
\brief Выводит результат в txt файл
\param[in] fileName имя файла
\param[in] hash список пар имя-профессия
*/
void writeResultToTxt(const QString filename,const QMultiHash<QString,QString> &hash);

#endif // MAIN_H
