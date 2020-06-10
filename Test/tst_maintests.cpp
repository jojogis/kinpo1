#include <QtTest>
#include "../token.h"
#include "../sentence.h"
#include "../rules.h"

#include "../token.cpp"
#include "../sentence.cpp"
#include "../rules.cpp"


// add necessary includes here

class MainTests : public QObject
{
    Q_OBJECT

public:
    MainTests();
    ~MainTests();
    QStringList perpList = {"sir","ser","esq.","monsieu","lady","magister","brother","sister","father","master","Dr.",
                           "princess","prince","king","queen","lord"};
private slots:
    void rule_1_no_prof();
    void rule_1_one_prof();
    void rule_1_compProf();
    void rule_1_prof_withoutTitleNotInList();
    void rule_1_clergyman();
    void rule_2_no_prof();
    void rule_2_one_prof();
    void rule_2_likeProf();
    void rule_2_compProf();
    void rule_3_noProf();
    void rule_3_oneProf();

};

MainTests::MainTests()
{

}

MainTests::~MainTests()
{

}

void MainTests::rule_1_no_prof()
{
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token("Jon","jon",1,"NNP","PERSON"));
    sentence.tokens.append(Token("found","find",2,"VBD",""));
    sentence.tokens[1].setDep("nsubj",1);
    sentence.tokens[1].setDep("xcomp",4);
    sentence.tokens.append(Token("it","it",3,"PRP",""));
    sentence.tokens.append(Token("hard","hard",4,"JJ",""));
    sentence.tokens[3].setDep("nsubj",3);
    sentence.tokens[3].setDep("xcomp",6);
    sentence.tokens.append(Token("to","to",5,"TO",""));
    sentence.tokens.append(Token("look","look",6,"VB",""));
    sentence.tokens[5].setDep("mark",5);
    sentence.tokens[5].setDep("advmod",7);
    sentence.tokens.append(Token("away","away",7,"RB",""));
    Rules::checkRuleCompound(profNames,sentence,profList);
    QHash<QString,QString> expected;
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}


void MainTests::rule_1_one_prof()
{
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Which" , "which" , 1 , "WDT" , "O" ));
    sentence.tokens.append(Token( "had" , "have" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "been" , "be" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "destroyed" , "destroy" , 4 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Colonel" , "Colonel" , 6 , "NNP" , "TITLE" ));
    sentence.tokens.append(Token( "Openshaw" , "Openshaw" , 7 , "NNP" , "PERSON" ));
    sentence.getById( 4 ).setDep( "nsubj" , 1 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    Rules::checkRuleCompound(profNames,sentence,profList);
    QHash<QString,QString> expected;
    expected.insert("Openshaw","Colonel");
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

void MainTests::rule_1_compProf()
{
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("Jedi");
    profList.append("dragonknight");
    sentence.tokens.append(Token( "It" , "it" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "destroyed" , "destroy" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "fire" , "fire" , 5 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "mage" , "mage" , 6 , "NN" , "O" ));
    sentence.tokens.append(Token( "Merlin" , "Merlin" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 7 ).setDep( "case" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 3 ).setDep( "punct" , 8 );
    Rules::checkRuleCompound(profNames,sentence,profList);
    QHash<QString,QString> expected;
    expected.insert("Merlin","fire mage");
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}
void MainTests::rule_1_prof_withoutTitleNotInList()
{
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("Jedi");
    profList.append("dragonknight");
    sentence.tokens.append(Token( "He" , "he" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "said" , "say" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "it" , "it" , 3 , "PRP" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "dragonbreaker" , "dragonbreaker" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "Jeremiah" , "Jeremiah" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "." , "." , 7 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "obj" , 3 );
    sentence.getById( 6 ).setDep( "case" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 2 ).setDep( "punct" , 7 );
    Rules::checkRuleCompound(profNames,sentence,profList);
    QHash<QString,QString> expected;
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

void MainTests::rule_1_clergyman()
{
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Father" , "Father" , 1 , "NNP" , "O" ));
    sentence.tokens.append(Token( "Michael" , "Michael" , 2 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "was" , "be" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "resident" , "resident" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "of" , "of" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "that" , "that" , 7 , "DT" , "O" ));
    sentence.tokens.append(Token( "abbey" , "abbey" , 8 , "NN" , "O" ));
    sentence.tokens.append(Token( "." , "." , 9 , "." , "O" ));
    sentence.getById( 2 ).setDep( "compound" , 1 );
    sentence.getById( 5 ).setDep( "nsubj" , 2 );
    sentence.getById( 8 ).setDep( "case" , 6 );
    sentence.getById( 5 ).setDep( "nmod" , 8 );
    sentence.getById( 5 ).setDep( "punct" , 9 );
    Rules::checkRuleCompound(profNames,sentence,profList);
    QHash<QString,QString> expected;
    expected.insert("Michael","Father");
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

void MainTests::rule_2_no_prof(){
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Tyrion" , "Tyrion" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Lannister" , "Lannister" , 2 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "was" , "be" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "sitting" , "sit" , 4 , "VBG" , "O" ));
    sentence.tokens.append(Token( "near" , "near" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Great" , "Great" , 6 , "NNP" , "LOCATION" ));
    sentence.tokens.append(Token( "Hall" , "Hall" , 7 , "NNP" , "LOCATION" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "compound" , 1 );
    sentence.getById( 4 ).setDep( "nsubj" , 2 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 4 ).setDep( "punct" , 8 );
    Rules::checkRuleAmod(profNames,sentence,profList);
    QHash<QString,QString> expected;
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

void MainTests::rule_2_one_prof(){
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "I" , "I" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "like" , "like" , 2 , "VBP" , "O" ));
    sentence.tokens.append(Token( "how" , "how" , 3 , "WRB" , "O" ));
    sentence.tokens.append(Token( "Major" , "major" , 4 , "JJ" , "TITLE" ));
    sentence.tokens.append(Token( "Freebody" , "Freebody" , 5 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 6 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "looking" , "look" , 7 , "VBG" , "O" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "amod" , 4 );
    sentence.getById( 7 ).setDep( "nsubj" , 5 );
    sentence.getById( 2 ).setDep( "punct" , 8 );
    Rules::checkRuleAmod(profNames,sentence,profList);
    QHash<QString,QString> expected;
    expected.insert("Freebody","Major");
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

void MainTests::rule_2_likeProf(){
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "I" , "I" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "like" , "like" , 2 , "VBP" , "O" ));
    sentence.tokens.append(Token( "how" , "how" , 3 , "WRB" , "O" ));
    sentence.tokens.append(Token( "major" , "major" , 4 , "JJ" , "O" ));
    sentence.tokens.append(Token( "Mike" , "Mike" , 5 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 6 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "looking" , "look" , 7 , "VBG" , "O" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 7 ).setDep( "nsubj" , 5 );
    sentence.getById( 2 ).setDep( "punct" , 8 );
    Rules::checkRuleAmod(profNames,sentence,profList);
    QHash<QString,QString> expected;
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

void MainTests::rule_2_compProf(){
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    profList.append("dragonknight");
    sentence.tokens.append(Token( "I" , "I" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "like" , "like" , 2 , "VBP" , "O" ));
    sentence.tokens.append(Token( "how" , "how" , 3 , "WRB" , "O" ));
    sentence.tokens.append(Token( "Major" , "major" , 4 , "JJ" , "TITLE" ));
    sentence.tokens.append(Token( "Captain" , "Captain" , 5 , "NNP" , "TITLE" ));
    sentence.tokens.append(Token( "Mike" , "Mike" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 7 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "looking" , "look" , 8 , "VBG" , "O" ));
    sentence.tokens.append(Token( "." , "." , 9 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "amod" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 8 ).setDep( "nsubj" , 6 );
    sentence.getById( 2 ).setDep( "punct" , 9 );
    Rules::checkRuleAmod(profNames,sentence,profList);
    QHash<QString,QString> expected;
    expected.insert("Mike","Major Captain");
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

void MainTests::rule_3_noProf(){
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Manistee" , "Manistee" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Illytio" , "Illytio" , 2 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 3 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "great" , "great" , 5 , "JJ" , "O" ));
    sentence.tokens.append(Token( "person" , "person" , 6 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "compound" , 1 );
    sentence.getById( 6 ).setDep( "nsubj" , 2 );
    sentence.getById( 6 ).setDep( "amod" , 5 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QHash<QString,QString> expected;
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

void MainTests::rule_3_oneProf(){
    QHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Magister" , "Magister" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 2 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 3 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "dealer" , "dealer" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "in" , "in" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "spices" , "spice" , 7 , "NNS" , "O" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "compound" , 1 );
    sentence.getById( 5 ).setDep( "nsubj" , 2 );
    sentence.getById( 7 ).setDep( "case" , 6 );
    sentence.getById( 5 ).setDep( "nmod" , 7 );
    sentence.getById( 5 ).setDep( "punct" , 8 );
    sentence.tokens.append(Token( "." , "." , 1 , "." , "O" ));
    Rules::checkRuleToBe(profNames,sentence,profList);
    QHash<QString,QString> expected;
    expected.insert("Illyrio","dealer");
    qDebug() << "expected" << expected;
    qDebug() << "result" << profNames;
    QCOMPARE(profNames,expected);
}

QTEST_MAIN(MainTests)
#include "debug/tst_maintests.moc"
