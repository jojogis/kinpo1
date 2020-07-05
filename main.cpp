/*!
\file
\brief файл с главной функцией
*/

/*!
\mainpage Главная
\section intro_sec Введение
Имея список полных имен и данные разбора текста, предоставляемого программой «Stanford CoreNLP», программа осуществляет поиск профессии и/или должности персонажа
Программа определяет профессию и/или должность персонажа в тексте по определенному набору правил.
\section install_sec Запуск
Программа запускается посредством командной строки с указанием 4 параметров – путь к файлу с разбором теста, путь к файлу со списком имен, путь к файлу со списком профессий и имя выходного файлы.
Пример: OccupationFinder.exe text.xml persons.txt professions.txt out.xml
Если параметры не указаны, то начинается диалог с пользователем с запросами на ввод путей к необходимым файлам.
*/

#include "QTime"
#include "main.h"

#include <QXmlStreamWriter>

QTextStream cin(stdin);

int main(int argc, char *argv[])
{
    QStringList perpList = {"sir", "ser", "esq.", "monsieu", "lady", "magister", "Brother", "sister", "father", "master", "Dr.",
                            "princess", "prince", "king", "queen", "lord"};
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "Russian");
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

        readFileWithText(textFileName, error, sentences);
    } catch (int e) {
        if(e == 1)qDebug() << "Недопустимый формат файла с разбором текста";
        if(e == 2)qDebug() << "Ошибка открытия файла с текстом: " + error;
        if(e == 7)qDebug() << "Ошибка открытия файла с текстом: Не удается найти тэг «pos»";
        if(e == 8)qDebug() << "Ошибка открытия файла с текстом: Не удается найти тэг «dependencies»";
        if(e == 9)qDebug() << "Ошибка открытия файла с текстом: Не удается найти тэг «sentence»";
        if(e == 14)qDebug() << "Ошибка открытия файла с текстом: Пустой файл";
        return 0;
    }
    QStringList names;
    try {
        readFileWithNames(namesFileName, error, names);
    } catch (int e) {
        if(e == 3)qDebug() << "Недопустимый формат файла со списком персонажей";
        if(e == 4)qDebug() << "Ошибка открытия файла со списком персонажей: " + error;
        if(e == 5)qDebug() << "Пустой файл со списком имен";
        if(e == 6)qDebug() << "Ошибка файла со списком персонажей: Файл должен содержать только латиницу";
        return 0;
    }
    QStringList professions;
    try {
        readFileWithProfessions(profFileName, error, professions);
    } catch (int e) {
        if(e == 11)qDebug() << "Недопустимый формат файла со списком профессий";
        if(e == 12)qDebug() << "Ошибка открытия файла со списком профессий: " + error;
        if(e == 13)qDebug() << "Ошибка файла со списком профессий: Файл должен содержать только латиницу";
        return 0;
    }

    QFile outFile(resultFileName);
    QFileInfo info(resultFileName);
    if(!outFile.open(QIODevice::WriteOnly)){
        qDebug() << "Ошибка открытия выходного файла";
        return 0;
    }
    if(info.suffix() != "txt" && info.suffix() != "xml"){
        qDebug() << "Недопустимый формат выходного файла";
    }

    QMultiHash<QString, QString> profNames = QMultiHash<QString, QString>();

    Rules::analyzeFileWithNames(names, profNames, perpList);

    professions.append(perpList);

    foreach(Sentence sentence, sentences){
        Rules::checkRuleCompound (profNames, sentence, professions);
        Rules::checkRuleAmod (profNames, sentence, professions);
        Rules::checkRuleToBe (profNames, sentence, professions);
        Rules::checkRuleAppos1 (profNames, sentence, professions);
        Rules::checkRuleAppos2 (profNames, sentence, professions);
        Rules::checkRuleToWork (profNames, sentence, professions);
        Rules::checkRuleReignOf (profNames, sentence);
        Rules::checkRuleJob (profNames, sentence, professions);
    }

    removeEqualPairs(profNames);
    if(info.suffix() == "txt"){
        writeResultToTxt(resultFileName, profNames);
    }else if(info.suffix() == "xml"){
        writeResultToXml(resultFileName, profNames);
    }


    foreach(QString name, profNames.uniqueKeys()){
        foreach(QString prof, profNames.values(name)){
            QString res = name+":"+prof;
            printf("%ls\n", res.toStdWString().c_str());
        }
    }
    cin.flush();

    return 0;
}
/*!
\brief Выводит результат в txt файл
\param [in] fileName имя файла
\param [in] hash список пар имя-профессия
*/
void writeResultToTxt(const QString filename, const QMultiHash<QString, QString> &hash)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Не удалось открыть выходной файл";
    }else{
        QTextStream out(&file);
        foreach(QString name, hash.uniqueKeys()){
            foreach(QString prof, hash.values(name)){
                out << name << ":" << prof << "\n";
            }
        }
    }
}



/*!
\brief Выводит результат в Xml файл
\param [in] fileName имя файла
\param [in] hash список пар имя-профессия
*/
void writeResultToXml(const QString filename, const QMultiHash<QString, QString> &hash)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    int id = 0;
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("root");
    xmlWriter.writeStartElement("document");
    xmlWriter.writeStartElement("characters");
    foreach(QString name, hash.uniqueKeys()){
        id++;
        xmlWriter.writeStartElement("character");
        xmlWriter.writeAttribute("id", QString::number(id));
        xmlWriter.writeStartElement("name");
        xmlWriter.writeCharacters(name);
        xmlWriter.writeEndElement();
        foreach(QString prof, hash.values(name)){

            xmlWriter.writeStartElement("title");
            xmlWriter.writeCharacters(prof);
            xmlWriter.writeEndElement();

        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}

/*!
Удаляет одинаковые пары имя-профессия
\param[in, out] hash список имен - профессий
*/
void removeEqualPairs(QMultiHash<QString, QString> &hash){
    foreach(QString name, hash.uniqueKeys()){
        QList<QString> profs = hash.values(name);
        profs.removeDuplicates();
        hash.remove(name);
        foreach(QString prof, profs){
            if(prof == "Brother" || prof == "Sister")prof = "monk";
            if(prof == "Father" || prof == "Mother")prof = "priest";
            hash.insert(name, prof);
        }
    }

}
/*!
\brief Читает файл со списком имен
\param [in] fileName имя файла
\param [out] error текст ошибки
\param [out] res список имен
\throw 3 Недопустимый формат файла со списком персонажей
\throw 4 Ошибка открытия файла со списком персонажей: {описание системной ошибки}
\throw 5 Пустой файл со списком имен
\throw 6 Ошибка файла со списком персонажей: Файл должен содержать только латиницу
*/
void readFileWithNames(QString fileName, QString &error, QStringList &res)
{
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
    file.close();
}

/*!
\brief Читает файл со списком профессий
\param [in] fileName имя файла
\param [out] error текст ошибки
\param [out] res список профессий
\throw 11 Недопустимый формат файла со списком профессий
\throw 12 Ошибка открытия файла со списком профессий: {описание системной ошибки}
\throw 13 Ошибка файла со списком профессий: Файл должен содержать только латиницу
*/
void readFileWithProfessions(QString fileName, QString &error, QStringList &res)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        error = file.errorString();
        throw 12;
    }
    QFileInfo info(fileName);
    if(info.suffix() != "txt"){
        throw 11;
    }
    while(!file.atEnd()){
        QString prof = file.readLine();
        prof = prof.remove("\n").toLower();
        QRegExp latReg("([a-z]|\\s)+");
        if(!latReg.exactMatch(prof))throw 13;
        res.append(prof);
    }
}

/*!
\brief Читает файл с разбором текста
\param [in] fileName имя файла
\param [out] error текст ошибки
\param [out] res список предложений
\throw 1 Недопустимый формат файла с разбором текста
\throw 2 Ошибка открытия файла с текстом: {описание системной ошибки}
\throw 7 Ошибка открытия файла с текстом: Не удается найти тэг «pos»
\throw 8 Ошибка открытия файла с текстом: Не удается найти тэг «dependencies»
\throw 9 Ошибка открытия файла с текстом: Не удается найти тэг «sentence»
\throw 14 Ошибка открытия файла с текстом: пустой файл
*/
void readFileWithText(QString fileName, QString &error, QList<Sentence> &res)
{
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
    if(data.size() == 0)throw 14;
    file.close();
    QDomDocument doc("doc");
    int errorLine;int errorColumn;
    if (!doc.setContent(data, &error, &errorLine, &errorColumn)) {
        error = " on "+QString::number(errorLine)+":"+QString::number(errorColumn);
        throw 2;
    }
    //TODO 7-10 ошибки
    QDomNodeList sentencesXml = doc.documentElement().firstChild().namedItem("sentences").childNodes();//document
    if(sentencesXml.size() == 0)throw 9;
    for(int t = 0;t < sentencesXml.size();t++){
        Sentence sentence;
        QDomNodeList tokens = sentencesXml.at(t).namedItem("tokens").childNodes();
        for(int b = 0; b < tokens.size(); b++){
            QString word = tokens.at(b).namedItem("word").toElement().text();
            QString lemma = tokens.at(b).namedItem("lemma").toElement().text();
            int id = tokens.at(b).toElement().attribute("id").toInt();
            if(tokens.at(b).namedItem("POS").isNull())throw 7;
            QString pos = tokens.at(b).namedItem("POS").toElement().text();
            QString ner = tokens.at(b).namedItem("NER").toElement().text();
            Token token = Token(word, lemma, id, pos, ner);
            qDebug() << "sentence.tokens.append(Token(" << word << ", " << lemma << ", " << id << ", " << pos << ", " << ner << "));";
            sentence.tokens.append(token);
        }
        QDomNode depsNode = sentencesXml.at(t).namedItem("dependencies");
        if(depsNode.isNull())throw 8;
        while(depsNode.toElement().attribute("type")!="basic-dependencies")depsNode = depsNode.nextSibling();
        QDomNodeList deps = depsNode.childNodes();
        for(int b = 0; b < deps.size(); b++){
            QString type = deps.at(b).toElement().attribute("type").split(":")[0];
            if(Token::isNeededDep(type)){
                int idGov = deps.at(b).namedItem("governor").toElement().attribute("idx").toInt();
                int idDep = deps.at(b).namedItem("dependent").toElement().attribute("idx").toInt();
                sentence.getById(idGov).setDep(type, idDep);
                qDebug() << "sentence.getById(" << idGov << ").setDep(" << type << ", " << idDep << ");";
            }
        }
        res.append(sentence);
    }


}

void readFileWithTextFast(QString fileName, QString &error, QList<Sentence> &res){
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
    if(data.size() == 0)throw 14;
    file.close();
    QXmlStreamReader xmlDoc(data);
    QXmlStreamReader::TokenType tag = xmlDoc.readNext();
    Sentence sentence;
    QString word, lemma, pos, ner;
    int id;
    bool isDepReaded = false;
    //читаем до завершающего тега sentences
    while (!xmlDoc.atEnd() && !xmlDoc.hasError() && !(tag == QXmlStreamReader::EndElement && xmlDoc.name() == "sentences")) {
        tag = xmlDoc.readNext();
        //читаем слово
        if(tag == QXmlStreamReader::StartElement && xmlDoc.name() == "token"){
            QXmlStreamAttributes attr = xmlDoc.attributes();
            id = attr.value("id").toInt();
            xmlDoc.readNextStartElement();
            word = xmlDoc.readElementText();
            xmlDoc.readNextStartElement();
            lemma = xmlDoc.readElementText();
            xmlDoc.readNextStartElement();
            xmlDoc.readNextStartElement();
            xmlDoc.readNextStartElement();
            xmlDoc.readNextStartElement();
            xmlDoc.readNextStartElement();
            pos = xmlDoc.readElementText();
            xmlDoc.readNextStartElement();
            ner = xmlDoc.readElementText();
            Token token = Token(word, lemma, id, pos, ner);
            sentence.tokens.append(token);
        }
        //читаем зависимости
        if(!isDepReaded && tag == QXmlStreamReader::StartElement && xmlDoc.name() == "dependencies"){
            QXmlStreamAttributes attr = xmlDoc.attributes();
            if(attr.value("type") == "basic-dependencies"){
                isDepReaded = true;
                xmlDoc.readNextStartElement();
                while(xmlDoc.name() == "dep"){
                    attr = xmlDoc.attributes();
                    QString type = attr.value("type").toString().split(":")[0];
                    xmlDoc.readNextStartElement();
                    attr = xmlDoc.attributes();
                    int idGov = attr.value("idx").toInt();
                    xmlDoc.readNextStartElement();
                    xmlDoc.readNextStartElement();
                    attr = xmlDoc.attributes();
                    int idDep = attr.value("idx").toInt();
                    xmlDoc.readNextStartElement();

                    if(Token::isNeededDep(type))sentence.getById(idGov).setDep(type, idDep);

                    xmlDoc.readNextStartElement();
                    xmlDoc.readNextStartElement();
                }
            }
        }
        //если предложение прочитано, добавляем его в список
        if(tag == QXmlStreamReader::EndElement && xmlDoc.name() == "sentence"){
            res.append(sentence);
            sentence.tokens.clear();
            isDepReaded = false;
        }

    }

}

