#include "sentence.h"
#include "rules.h"
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDomDocument>

QTextStream cin(stdin);
void analyzeFileWithNames(QStringList names,QHash<QString,QString> &profNames,const QStringList &perpList);
QStringList readFileWithProfessions(QString fileName,QString &error);
QList<Sentence> readFileWithText(QString fileName,QString &error);
void readFileWithNames(QString fileName,QString &error,QStringList &res);


void analyzeFileWithNames(QStringList names,QHash<QString,QString> &profNames);
int main(int argc, char *argv[])
{
    QStringList perpList = {"sir","ser","esq.","monsieu","lady","magister","Brother","sister","father","master","Dr.",
                           "princess","prince","king","queen","lord"};
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL,"Russian");
    QString textFileName;
    if(argc < 2){
        qDebug() << "Введите путь к файлу разбора текста";
        cin >> textFileName;
    }else{
        textFileName = QString(argv[1]);
    }



    QString namesFileName;
    if(argc < 3){
        qDebug() << "Введите путь к файлу со списком имен";
        cin >> namesFileName;
    }else{
        namesFileName = QString(argv[2]);
    }

    QString profFileName;
    if(argc < 4){
        qDebug() << "Введите путь к файлу со списком профессий";
        cin >> profFileName;
    }else{
        profFileName = QString(argv[3]);
    }

    QString resultFileName;
    if(argc < 4){
        qDebug() << "Введите имя выходного файла";
        cin >> resultFileName;
    }else{
        resultFileName = QString(argv[4]);
    }

    QString error;
    QList<Sentence> sentences;
    try {
        sentences = readFileWithText(textFileName,error);
    } catch (int e) {
        if(e == 1)qDebug() << "Недопустимый формат файла с разбором текста";
        if(e == 2)qDebug() << "Ошибка открытия файла с текстом: " + error;
        return e;
    }
    QStringList names;
    try {
        readFileWithNames(namesFileName,error,names);
    } catch (int e) {
        if(e == 3)qDebug() << "Недопустимый формат файла со списком персонажей";
        if(e == 4)qDebug() << "Ошибка открытия файла со списком персонажей: " + error;
        if(e == 5)qDebug() << "Пустой файл со списком имен";
        if(e == 6)qDebug() << "Ошибка файла со списком персонажей: Файл должен содержать только латиницу";
        return e;
    }
    QStringList professions;
    try {
        professions = readFileWithProfessions(profFileName,error);
    } catch (int e) {
        if(e == 11)qDebug() << "Недопустимый формат файла со списком профессий";
        if(e == 12)qDebug() << "Ошибка открытия файла со списком профессий: " + error;
        if(e == 13)qDebug() << "Ошибка файла со списком профессий: Файл должен содержать только латиницу";
        return e;
    }

    QHash<QString,QString> profNames = QHash<QString,QString>();

    analyzeFileWithNames(names,profNames,perpList);

    professions.append(perpList);

    foreach(Sentence sentence,sentences){
        Rules::checkRuleCompound (profNames,sentence,professions);
        Rules::checkRuleAmod(profNames,sentence,professions);
        Rules::checkRuleToBe(profNames,sentence,professions);
        Rules::checkRuleAppos1 (profNames,sentence,professions);
        Rules::checkRuleAppos2 (profNames,sentence,professions);
        Rules::checkRuleToWork (profNames,sentence,professions);
        Rules::checkRuleReignOf (profNames,sentence);
        Rules::checkRuleJob (profNames,sentence,professions);
    }


    foreach(QString name,profNames.keys()){
        qDebug() << name << ":" << profNames.value(name);
    }
    qDebug() << "finish";
    return a.exec();
}

void analyzeFileWithNames(QStringList names,QHash<QString,QString> &profNames,const QStringList &perpList){
    foreach (QString name, names) {
        foreach(QString prof,perpList){
            if(name.indexOf(prof) != -1){
                profNames.insert(name.remove(prof),prof);
            }
        }
    }
}

void readFileWithNames(QString fileName,QString &error,QStringList &res){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        error = file.errorString();
        throw 4;
    }
    QFileInfo info(fileName);
    if(info.suffix() != "txt"){
        throw 3;
    }
    while(!file.atEnd()){
        QString name = file.readLine();
        name= name.remove("\n").toLower();
        QRegExp latReg("([a-z]|\\s)+");
        if(!latReg.exactMatch(name))throw 6;
        res.append(name);
    }
    if(res.size() == 0)throw 5;
}

QStringList readFileWithProfessions(QString fileName,QString &error){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        error = file.errorString();
        throw 12;
    }
    QFileInfo info(fileName);
    if(info.suffix() != "txt"){
        throw 11;
    }
    QStringList res;
    while(!file.atEnd()){
        QString prof = file.readLine();
        prof = prof.remove("\n").toLower();
        QRegExp latReg("([a-z]|\\s)+");
        if(!latReg.exactMatch(prof))throw 13;
        res.append(prof);
    }
    return res;
}


QList<Sentence> readFileWithText(QString fileName,QString &error){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        error = file.errorString();
        throw 2;
    }
    QFileInfo info(fileName);
    if(info.suffix() != "xml"){
        throw 1;
    }
    QString data = file.readAll();
    QDomDocument doc("doc");
    int errorLine;int errorColumn;
     if (!doc.setContent(data,&error,&errorLine,&errorColumn)) {
        error = " on "+QString::number(errorLine)+":"+QString::number(errorColumn);
        throw 2;
     }
     //TODO 7-10 ошибки
     QDomNodeList sentencesXml = doc.documentElement().firstChild().namedItem("sentences").childNodes();//document
     QList<Sentence> res;
     for(int t = 0;t < sentencesXml.size();t++){
         Sentence sentence;
         QDomNodeList tokens = sentencesXml.at(t).namedItem("tokens").childNodes();
         for(int b = 0; b < tokens.size(); b++){
             QString word = tokens.at(b).namedItem("word").toElement().text();
             QString lemma = tokens.at(b).namedItem("lemma").toElement().text();
             int id = tokens.at(b).toElement().attribute("id").toInt();
             QString pos = tokens.at(b).namedItem("POS").toElement().text();
             QString ner = tokens.at(b).namedItem("NER").toElement().text();
             Token token = Token(word,lemma,id,pos,ner);
             qDebug() << "sentence.tokens.append(Token(" << word << "," << lemma << "," << id << "," << pos << "," << ner << "));";
             sentence.tokens.append(token);
         }
         QDomNode depsNode = sentencesXml.at(t).namedItem("dependencies");
         while(depsNode.toElement().attribute("type")!="basic-dependencies")depsNode = depsNode.nextSibling();
         QDomNodeList deps = depsNode.childNodes();
         for(int b = 0; b < deps.size(); b++){
             QString type = deps.at(b).toElement().attribute("type").split(":")[0];
             if(Token::isNeededDep(type)){
             int idGov = deps.at(b).namedItem("governor").toElement().attribute("idx").toInt();
             int idDep = deps.at(b).namedItem("dependent").toElement().attribute("idx").toInt();
             sentence.getById(idGov).setDep(type,idDep);
             qDebug() << "sentence.getById(" << idGov << ").setDep(" << type << "," << idDep << ");";
             }
         }
        res.append(sentence);
     }
     return res;
}
