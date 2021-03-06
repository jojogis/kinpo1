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
    QStringList perpList = {"sir","ser","esq.","monsieu","lady","magister","brother","sister","father","dr.",
                           "princess","prince","king","queen","lord"};
    bool compareMultiHash(const QMultiHash<QString,QString> &actual,const QMultiHash<QString,QString> &expected,QString &message);

private slots:
    void checkRuleCompound_no_prof();
    void checkRuleCompound_one_prof();
    void checkRuleCompound_compProf();
    void checkRuleCompound_prof_withoutTitleNotInList();
    void checkRuleCompound_clergyman();
    void checkRuleCompound_notInList();
    void checkRuleCompound_notNN();
    void checkRuleAmod_no_prof();
    void checkRuleAmod_one_prof();
    void checkRuleAmod_likeProf();
    void checkRuleAmod_compProf();
    void checkRuleAmod_notInList();
    void checkRuleAmod_compProfNotInList();
    void checkRuleAmod_notJJ();
    void checkRuleAmod_notUppercase();
    void checkRuleToBe_noProf();
    void checkRuleToBe_oneProf();
    void checkRuleToBe_twoProf();
    void checkRuleToBe_profInList();
    void checkRuleToBe_twoCharacters();
    void checkRuleToBe_notInList();
    void checkRuleToBe_twoCharactersAndManyProf();
    void checkRuleToBe_compProf();
    void checkRuleToBe_twoPersAndCompProfs();
    void checkRuleToBe_profAndCompProf();
    void checkRuleToBe_twoPersAndCompProfsInList();
    void checkRuleToBe_twoPersAndCompProfsNotInList();
    void checkRuleToBe_twoPersProfAndCompProfNotInList();
    void checkRuleToBe_twoPersProfAndCompProfInList();
    void checkRuleToBe_withoutArticul();
    void checkRuleToBe_notTITLE();
    void checkRuleToBe_wrongArticul();
    void checkRuleAppos1_noProf();
    void checkRuleAppos1_oneProf();
    void checkRuleAppos1_compProf();
    void checkRuleAppos1_twoProf();
    void checkRuleAppos1_notInList();
    void checkRuleAppos1_compProfNotInList();
    void checkRuleAppos1_compProfsOneInList();
    void checkRuleAppos1_notNN();
    void checkRuleAppos1_noPunct();
    void checkRuleAppos2_noProf();
    void checkRuleAppos2_oneProf();
    void checkRuleAppos2_compProf();
    void checkRuleAppos2_notInList();
    void checkRuleAppos2_compProfNotInList();
    void checkRuleAppos2_twoProfs();
    void checkRuleAppos2_profAndCompProf();
    void checkRuleAppos2_noApposDep();
    void checkRuleAppos2_notPERSON();
    void checkRuleAppos2_notNN();
    void checkRuleAppos2_noPunctDep();
    void checkRuleToWork_oneProf();
    void checkRuleToWork_compProf();
    void checkRuleToWork_fewProf();
    void checkRuleToWork_NotInList();
    void checkRuleToWork_twoCompProf();
    void checkRuleToWork_profAndCompProfNotInList();
    void checkRuleToWork_twoPersons();
    void checkRuleToWork_noNsubjDep();
    void checkRuleToWork_noObjDep();
    void checkRuleToWork_notPerson();
    void checkRuleToWork_personIsNotNN();
    void checkRuleToWork_noTitle();
    void checkRuleToWork_titleIsNotNN();
    void checkRuleReignOf_oneProf();
    void checkRuleReignOf_twoCharacter();
    void checkRuleReignOf_profNotToPerson();
    void checkRuleReignOf_profNotToPersons();
    void checkRuleReignOf_OnlyToOnePerson();
    void checRuleJob_oneProf();
    void checRuleJob_twoProf();
    void checRuleJob_compProf();
    void checRuleJob_notInList();
    void checRuleJob_twoCompProfNotInList();
    void checRuleJob_twoCompProfInList();
    void checRuleJob_twoCompProfOneInList();
    void checRuleJob_profAndCompProfNotInList();
    void checRuleJob_twoPers();
    void checRuleJob_twoPersAndTwoProfs();
    void checRuleJob_twoPersOneWithProf();
    void checRuleJob_twoPersWithoutProf();
    void checRuleJob_mix1();
    void checRuleJob_jobNotNN();
    void checRuleJob_noJobWord();
    void checRuleJob_noNmodDep();
    void checRuleJob_personNotNN();
    void checRuleJob_noApostrophe();
    void checRuleJob_noPerson();
    void checRuleJob_noCaseDep();
    void checkRuleToPractice_oneProf();
    void checkRuleToPractice_twoProf();
    void checkRuleToPractice_compProf();
    void checkRuleToPractice_notInList();
    void checkRuleToPractice_twoCompProfInList();
    void checkRuleToPractice_twoCompProfOneInList();
    void checkRuleToPractice_twoCompProfNotInList();
    void checkRuleToPractice_noNsubjDep();
    void checkRuleToPractice_noObjDep();
    void checkRuleToPractice_personNotNN();
    void checkRuleToPractice_noPerson();
    void checkRuleToPractice_titleNotNN();
    void analyzeFileWithNames_1();
    void analyzeFileWithNames_2();
    void getCompoundProf_notComp();
    void getCompoundProf_oneDepWord();
    void getCompoundProf_twoDepWord();
    void getCompoundProf_profInList();
    void getCompoundProf_profNotInList();
    void getCompoundProf_twoProfInList();

};

MainTests::MainTests()
{

}

MainTests::~MainTests()
{

}

bool MainTests::compareMultiHash(const QMultiHash<QString,QString> &actual,const QMultiHash<QString,QString> &expected,QString &message){
    bool isEqual = true;
    for(auto item = actual.begin(); item != actual.end(); item++) {
        if(!expected.contains(item.key(),item.value())){
            message += "лишний элемент: ('"+item.key()+"','"+item.value()+"')\n";
            isEqual = false;
        }
    }
    for(auto item = expected.begin(); item != expected.end(); item++) {
        if(!actual.contains(item.key(),item.value())){
            message += "недостающий элемент: ('"+item.key()+"','"+item.value()+"')\n";
            isEqual = false;
        }
    }
    return isEqual;
}

void MainTests::checkRuleCompound_no_prof()
{
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());
}


void MainTests::checkRuleCompound_one_prof()
{
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    expected.insert("Openshaw","colonel");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleCompound_compProf()
{
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    expected.insert("Merlin","fire mage");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleCompound_prof_withoutTitleNotInList()
{
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleCompound_clergyman()
{
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    expected.insert("Michael","father");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleCompound_notInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("archer");
    profList.append("king");
    profList.append("jedi");
    profList.append("hunter");
    sentence.tokens.append(Token( "it" , "it" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "destroyed" , "destroy" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "fire" , "fire" , 5 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "mage" , "mage" , 6 , "NN" , "O" ));
    sentence.tokens.append(Token( "Merin" , "merin" , 7 , "NN" , "PERSON" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 7 ).setDep( "case" , 4 );
    sentence.getById( 7 ).setDep( "compound" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    Rules::checkRuleCompound(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleCompound_notNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Which" , "which" , 1 , "WDT" , "O" ));
    sentence.tokens.append(Token( "had" , "have" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "been" , "be" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "destroyed" , "destroy" , 4 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "fool" , "fool" , 6 , "O" , "TITLE" ));
    sentence.tokens.append(Token( "Openshaw" , "Openshaw" , 7 , "NNP" , "PERSON" ));
    sentence.getById( 4 ).setDep( "nsubj" , 1 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    Rules::checkRuleCompound(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}


void MainTests::checkRuleAmod_no_prof(){
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAmod_one_prof(){
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    expected.insert("Freebody","major");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAmod_likeProf(){
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAmod_compProf(){
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","major captain");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAmod_notInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("archer");
    profList.append("king");
    profList.append("jedi");
    profList.append("hunter");
    sentence.tokens.append(Token( "I" , "I" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "like" , "like" , 2 , "VBP" , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "look" , "look" , 4 , "NN" , "O" ));
    sentence.tokens.append(Token( "of" , "of" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Beautiful" , "beautiful" , 6 , "JJ" , "O" ));
    sentence.tokens.append(Token( "Mike" , "Mike" , 7 , "NNP" , "PERSON" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "obj" , 4 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "amod" , 6 );
    sentence.getById( 4 ).setDep( "nmod" , 7 );
    Rules::checkRuleAmod(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleAmod_compProfNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("archer");
    profList.append("jedi");
    profList.append("hunter");
    sentence.tokens.append(Token( "I" , "I" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "like" , "like" , 2 , "VBP" , "O" ));
    sentence.tokens.append(Token( "how" , "how" , 3 , "WRB" , "O" ));
    sentence.tokens.append(Token( "Major" , "major" , 4 , "JJ" , "TITLE" ));
    sentence.tokens.append(Token( "Captain" , "Captain" , 5 , "NNP" , "TITLE" ));
    sentence.tokens.append(Token( "Mike" , "Mike" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 7 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "looking" , "look" , 8 , "VBG" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "amod" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 8 ).setDep( "nsubj" , 6 );
    Rules::checkRuleAmod(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","major Captain");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());
}

void MainTests::checkRuleAmod_notJJ(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);

    sentence.tokens.append(Token( "I" , "I" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "like" , "like" , 2 , "VBP" , "O" ));
    sentence.tokens.append(Token( "how" , "how" , 3 , "WRB" , "O" ));
    sentence.tokens.append(Token( "Major" , "major" , 4 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "Captain" , "Captain" , 5 , "NNP" , "TITLE" ));
    sentence.tokens.append(Token( "Mike" , "Mike" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 7 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "looking" , "look" , 8 , "VBG" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "amod" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 8 ).setDep( "nsubj" , 6 );
    Rules::checkRuleAmod(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());
}

void MainTests::checkRuleAmod_notUppercase(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);

    sentence.tokens.append(Token( "I" , "I" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "like" , "like" , 2 , "VBP" , "O" ));
    sentence.tokens.append(Token( "how" , "how" , 3 , "WRB" , "O" ));
    sentence.tokens.append(Token( "major" , "major" , 4 , "JJ" , "TITLE" ));
    sentence.tokens.append(Token( "Captain" , "Captain" , 5 , "NNP" , "TITLE" ));
    sentence.tokens.append(Token( "Mike" , "Mike" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 7 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "looking" , "look" , 8 , "VBG" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "amod" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 8 ).setDep( "nsubj" , 6 );
    Rules::checkRuleAmod(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());
}

void MainTests::checkRuleToBe_noProf(){
    QMultiHash<QString,QString> profNames;
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
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_oneProf(){
    QMultiHash<QString,QString> profNames;
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
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Illyrio","dealer");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_twoProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Magister" , "Magister" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 2 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 3 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "dealer" , "dealer" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 7 , "DT" , "O" ));
    sentence.tokens.append(Token( "hunter" , "hunter" , 8 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 9 , "." , "O" ));
    sentence.getById( 2 ).setDep( "compound" , 1 );
    sentence.getById( 5 ).setDep( "nsubj" , 2 );
    sentence.getById( 5 ).setDep( "punct" , 9 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Illyrio","dealer");
    expected.insert("Illyrio","hunter");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_profInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("archer");
    sentence.tokens.append(Token( "Manistee" , "Manistee" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 2 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "was" , "be" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "an" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "archer" , "archer" , 5 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "compound" , 1 );
    sentence.getById( 5 ).setDep( "nsubj" , 2 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Illyrio","archer");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_twoCharacters(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("archer");
    profList.append("hunter");
    profList.append("swordsman");
    sentence.tokens.append(Token( "Manistee" , "Manistee" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 2 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "was" , "be" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "an" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "archer" , "archer" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Master" , "Master" , 7 , "NNP" , "O" ));
    sentence.tokens.append(Token( "Grand" , "Grand" , 8 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "was" , "be" , 9 , "VBD" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 10 , "DT" , "O" ));
    sentence.tokens.append(Token( "swordsman" , "swordsman" , 11 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "compound" , 1 );
    sentence.getById( 5 ).setDep( "nsubj" , 2 );
    sentence.getById( 8 ).setDep( "compound" , 7 );
    sentence.getById( 11 ).setDep( "nsubj" , 8 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Illyrio","archer");
    expected.insert("Grand","swordsman");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToBe_notInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "Manistee" , "Manistee" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Ilirion" , "Ilirion" , 2 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "was" , "be" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "an" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "archer" , "archer" , 5 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "compound" , 1 );
    sentence.getById( 5 ).setDep( "nsubj" , 2 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_twoCharactersAndManyProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("farmer");
    profList.append("king");
    profList.append("fisherman");
    profList.append("doctor");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "fisherman" , "fisherman" , 4 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 5 , "CC" , "O" ));
    sentence.tokens.append(Token( "farmer" , "farmer" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "Ryan" , "Ryan" , 8 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "was" , "be" , 9 , "VBD" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 10 , "DT" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 11 , "NN" , "TITLE" ));
    sentence.getById( 4 ).setDep( "nsubj" , 1 );
    sentence.getById( 11 ).setDep( "nsubj" , 8 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Ryan","doctor");
    expected.insert("Mike","fisherman");
    expected.insert("Mike","farmer");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_compProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "police" , "police" , 4 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "officer" , "officer" , 5 , "NN" , "TITLE" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","police officer");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_twoPersAndCompProfs(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "police" , "police" , 4 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "officer" , "officer" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 7 , "NN" , "TITLE" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","police officer");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_profAndCompProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "police" , "police" , 4 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "officer" , "officer" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Clark" , "Clark" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "children" , "child" , 10 , "NNS" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 11 , "NN" , "TITLE" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    sentence.getById( 11 ).setDep( "nsubj" , 7 );
    sentence.getById( 11 ).setDep( "compound" , 10 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","police officer");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToBe_twoPersAndCompProfsInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("Major Captain");
    profList.append("children doctor");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "Major" , "major" , 4 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "Captain" , "captain" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Clark" , "Clark" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "children" , "child" , 10 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 11 , "NN" , "TITLE" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "amod" , 4 );
    sentence.getById( 11 ).setDep( "nsubj" , 7 );
    sentence.getById( 11 ).setDep( "compound" , 10 );
    Rules::checkRuleToBe(profNames,sentence,profList);

    QMultiHash<QString,QString> expected;
    expected.insert("Mike","Major Captain");
    expected.insert("Clark","children doctor");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToBe_twoPersAndCompProfsNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "Cyber" , "Cyber" , 4 , "NNP" , "O" ));
    sentence.tokens.append(Token( "Robot" , "Robot" , 5 , "NNP" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Clark" , "Clark" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "War" , "War" , 10 , "NNP" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "Loard" , "Loard" , 11 , "NNP" , "MISC" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    sentence.getById( 11 ).setDep( "nsubj" , 7 );
    sentence.getById( 11 ).setDep( "compound" , 10 );
    Rules::checkRuleToBe(profNames,sentence,profList);

    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_twoPersProfAndCompProfNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "Cyber" , "Cyber" , 4 , "NNP" , "O" ));
    sentence.tokens.append(Token( "Robot" , "Robot" , 5 , "NNP" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Clark" , "Clark" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 10 , "NN" , "TITLE" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    sentence.getById( 10 ).setDep( "nsubj" , 7 );
    Rules::checkRuleToBe(profNames,sentence,profList);

    QMultiHash<QString,QString> expected;
    expected.insert("Clark","doctor");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_twoPersProfAndCompProfInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("Cyber Robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "Cyber" , "Cyber" , 4 , "NNP" , "O" ));
    sentence.tokens.append(Token( "Robot" , "Robot" , 5 , "NNP" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Clark" , "Clark" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 10 , "NN" , "TITLE" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    sentence.getById( 10 ).setDep( "nsubj" , 7 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Clark","doctor");
    expected.insert("Mike","Cyber Robot");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToBe_withoutArticul(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("Cyber Robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "Cyber" , "Cyber" , 4 , "NNP" , "O" ));
    sentence.tokens.append(Token( "Robot" , "Robot" , 5 , "NNP" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Clark" , "Clark" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 9 , "NN" , "TITLE" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    sentence.getById( 9 ).setDep( "nsubj" , 7 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Clark","doctor");
    expected.insert("Mike","Cyber Robot");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToBe_notTITLE(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("Cyber Robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "Cyber" , "Cyber" , 4 , "NNP" , "O" ));
    sentence.tokens.append(Token( "Robot" , "Robot" , 5 , "NNP" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Clark" , "Clark" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 9 , "NN" , "O" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    sentence.getById( 9 ).setDep( "nsubj" , 7 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","Cyber Robot");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToBe_wrongArticul(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("Cyber Robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "Cyber" , "Cyber" , 4 , "NNP" , "TITLE" ));
    sentence.tokens.append(Token( "Robot" , "Robot" , 5 , "NNP" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Clark" , "Clark" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "is" , "be" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 9 , "NN" , "TITLE" ));
    sentence.getById( 5 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    sentence.getById( 9 ).setDep( "nsubj" , 7 );
    Rules::checkRuleToBe(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Clark","doctor");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleAppos1_noProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
    sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
    sentence.getById( 2 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "nsubj" , 2 );
    sentence.getById( 3 ).setDep( "obj" , 4 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;

    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleAppos1_oneProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
    sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "captain" , "captain" , 10 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 11 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "nsubj" , 2 );
    sentence.getById( 3 ).setDep( "obj" , 4 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 7 ).setDep( "punct" , 8 );
    sentence.getById( 7 ).setDep( "appos" , 10 );
    sentence.getById( 3 ).setDep( "punct" , 11 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Cassel","captain");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleAppos1_compProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("archer");
    profList.append("hunter");
    profList.append("captain of his household guard");
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
    sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "captain" , "captain" , 10 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "of" , "of" , 11 , "IN" , "O" ));
    sentence.tokens.append(Token( "his" , "he" , 12 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "household" , "household" , 13 , "NN" , "O" ));
    sentence.tokens.append(Token( "guard" , "guard" , 14 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 15 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "nsubj" , 2 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 7 ).setDep( "appos" , 10 );
    sentence.getById( 7 ).setDep( "punct" , 8 );
    sentence.getById( 3 ).setDep( "obl" , 7 );
    sentence.getById( 3 ).setDep( "punct" , 8 );
    sentence.getById( 14 ).setDep( "case" , 11 );
    sentence.getById( 14 ).setDep( "nmod" , 12 );
    sentence.getById( 14 ).setDep( "compound" , 13 );
    sentence.getById( 10 ).setDep( "nmod" , 14 );
    sentence.getById( 3 ).setDep( "punct" , 15 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Cassel","captain of his household guard");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos1_twoProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
    sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 9 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 10 , "CC" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 11 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 12 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "nsubj" , 2 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 3 ).setDep( "obl" , 7 );
    sentence.getById( 7 ).setDep( "punct" , 8 );
    sentence.getById( 3 ).setDep( "punct" , 12 );
    sentence.getById( 7 ).setDep( "appos" , 9 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Cassel","doctor");
    expected.insert("Cassel","policeman");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos1_notInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "It" , "it" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "Robin" , "Robin" , 3 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "," , "," , 4 , "," , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "forest" , "forest" , 6 , "NN" , "O" ));
    sentence.tokens.append(Token( "archer" , "archer" , 7 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 3 ).setDep( "punct" , 4 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 3 ).setDep( "appos" , 7 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos1_compProfNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "It" , "it" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "Catrin" , "Catrin" , 3 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "," , "," , 4 , "," , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "forest" , "forest" , 6 , "NN" , "O" ));
    sentence.tokens.append(Token( "queen" , "queen" , 7 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 3 ).setDep( "punct" , 4 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 3 ).setDep( "appos" , 7 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos1_compProfsOneInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("forest archer");
    sentence.tokens.append(Token( "It" , "it" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "Robin" , "Robin" , 3 , "NN" , "PERSON" ));
    sentence.tokens.append(Token( "," , "," , 4 , "," , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "forest" , "forest" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "archer" , "archer" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 8 , "CC" , "O" ));
    sentence.tokens.append(Token( "Stone" , "stone" , 9 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "knight" , "knight" , 10 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 3 ).setDep( "punct" , 4 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 10 ).setDep( "compound" , 9 );
    sentence.getById( 3 ).setDep( "appos" , 6 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Robin","forest archer");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos1_notNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
    sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "captain" , "captain" , 10 , "O" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 11 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "nsubj" , 2 );
    sentence.getById( 3 ).setDep( "obj" , 4 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 7 ).setDep( "punct" , 8 );
    sentence.getById( 7 ).setDep( "appos" , 10 );
    sentence.getById( 3 ).setDep( "punct" , 11 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos1_noPunct(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
    sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
    sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "captain" , "captain" , 10 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 11 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "nsubj" , 2 );
    sentence.getById( 3 ).setDep( "obj" , 4 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 7 ).setDep( "appos" , 10 );
    sentence.getById( 3 ).setDep( "punct" , 11 );
    Rules::checkRuleAppos1(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_noProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "son" , "son" , 2 , "NN" , "O" ));
    sentence.tokens.append(Token( "," , "," , 3 , "," , "O" ));
    sentence.tokens.append(Token( "Marcus" , "Marcus" , 4 , "NNP" , "PERSON" ));
    sentence.getById( 2 ).setDep( "nmod" , 1 );
    sentence.getById( 2 ).setDep( "punct" , 3 );
    sentence.getById( 2 ).setDep( "appos" , 4 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleAppos2_oneProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "honorable" , "honorable" , 2 , "JJ" , "O" ));
    sentence.tokens.append(Token( "host" , "host" , 3 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "," , "," , 4 , "," , "O" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 5 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Mopatis" , "Mopatis" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "." , "." , 7 , "." , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "amod" , 2 );
    sentence.getById( 3 ).setDep( "punct" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 3 ).setDep( "appos" , 6 );
    sentence.getById( 3 ).setDep( "punct" , 7 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mopatis","host");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_compProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("archer");
    profList.append("hunter");
    profList.append("captain of his household guard");
    profList.append("knight of the roundtable");
    sentence.tokens.append(Token( "He" , "he" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "defeated" , "defeat" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "Knight" , "Knight" , 6 , "NNP" , "O" ));
    sentence.tokens.append(Token( "of" , "of" , 7 , "IN" , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "Roundtable" , "Roundtable" , 9 , "NNP" , "O" ));
    sentence.tokens.append(Token( "," , "," , 10 , "," , "O" ));
    sentence.tokens.append(Token( "Lancelot" , "Lancelot" , 11 , "NNP" , "PERSON" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "case" , 4 );
    sentence.getById( 6 ).setDep( "appos" , 11 );
    sentence.getById( 6 ).setDep( "punct" , 10 );
    sentence.getById( 3 ).setDep( "obl" , 6 );
    sentence.getById( 11 ).setDep( "case" , 7 );
    sentence.getById( 11 ).setDep( "compound" , 9 );
    sentence.getById( 11 ).setDep( "punct" , 10 );
    sentence.getById( 6 ).setDep( "nmod" , 11 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Lancelot","knight of the roundtable");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_notInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "He" , "he" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "detained" , "detain" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "cybercop" , "cybercop" , 6 , "NN" , "O" ));
    sentence.tokens.append(Token( "," , "," , 7 , "," , "O" ));
    sentence.tokens.append(Token( "Gideon" , "Gideon" , 8 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "." , "." , 9 , "." , "O" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "case" , 4 );
    sentence.getById( 6 ).setDep( "punct" , 7 );
    sentence.getById( 6 ).setDep( "appos" , 8 );
    sentence.getById( 3 ).setDep( "punct" , 9 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_compProfNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "He" , "he" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "killed" , "kill" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "cyberprisoner" , "cyberprisoner" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "," , "," , 6 , "," , "O" ));
    sentence.tokens.append(Token( "Gideon" , "Gideon" , 7 , "NNP" , "PERSON" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 4 );
    sentence.getById( 3 ).setDep( "obl" , 5 );
    sentence.getById( 5 ).setDep( "punct" , 6 );
    sentence.getById( 5 ).setDep( "appos" , 7 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleAppos2_twoProfs(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "He" , "he" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "saved" , "save" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "detective" , "detective" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
    sentence.tokens.append(Token( "Gideon" , "Gideon" , 9 , "NNP" , "PERSON" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 4 );
    sentence.getById( 3 ).setDep( "obl" , 5 );
    sentence.getById( 5 ).setDep( "punct" , 8 );
    sentence.getById( 5 ).setDep( "appos" , 9 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Gideon","policeman");
    expected.insert("Gideon","detective");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_profAndCompProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "He" , "he" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "was" , "be" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "saved" , "save" , 3 , "VBN" , "O" ));
    sentence.tokens.append(Token( "by" , "by" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "police" , "police" , 5 , "NNS" , "TITLE" ));
    sentence.tokens.append(Token( "officer" , "officer" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "detective" , "detective" , 8 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "," , "," , 9 , "," , "O" ));
    sentence.tokens.append(Token( "Gideon" , "Gideon" , 10 , "NNP" , "PERSON" ));
    sentence.getById( 3 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "case" , 4 );
    sentence.getById( 3 ).setDep( "obl" , 6 );
    sentence.getById( 6 ).setDep( "punct" , 9 );
    sentence.getById( 8 ).setDep( "punct" , 9 );
    sentence.getById( 6 ).setDep( "appos" , 10 );
    sentence.getById( 8 ).setDep( "appos" , 10 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Gideon","police officer");
    expected.insert("Gideon","detective");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_noApposDep(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "honorable" , "honorable" , 2 , "JJ" , "O" ));
    sentence.tokens.append(Token( "host" , "host" , 3 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "," , "," , 4 , "," , "O" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 5 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Mopatis" , "Mopatis" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "." , "." , 7 , "." , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "amod" , 2 );
    sentence.getById( 3 ).setDep( "punct" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 3 ).setDep( "punct" , 7 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_notPERSON(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "honorable" , "honorable" , 2 , "JJ" , "O" ));
    sentence.tokens.append(Token( "host" , "host" , 3 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "," , "," , 4 , "," , "O" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 5 , "NNP" , "O" ));
    sentence.tokens.append(Token( "Mopatis" , "Mopatis" , 6 , "NNP" , "O" ));
    sentence.tokens.append(Token( "." , "." , 7 , "." , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "amod" , 2 );
    sentence.getById( 3 ).setDep( "punct" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 3 ).setDep( "appos" , 6 );
    sentence.getById( 3 ).setDep( "punct" , 7 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_notNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "honorable" , "honorable" , 2 , "JJ" , "O" ));
    sentence.tokens.append(Token( "host" , "host" , 3 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "," , "," , 4 , "," , "O" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 5 , "O" , "PERSON" ));
    sentence.tokens.append(Token( "Mopatis" , "Mopatis" , 6 , "O" , "PERSON" ));
    sentence.tokens.append(Token( "." , "." , 7 , "." , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "amod" , 2 );
    sentence.getById( 3 ).setDep( "punct" , 4 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 3 ).setDep( "appos" , 6 );
    sentence.getById( 3 ).setDep( "punct" , 7 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleAppos2_noPunctDep(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "honorable" , "honorable" , 2 , "JJ" , "O" ));
    sentence.tokens.append(Token( "host" , "host" , 3 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "," , "," , 4 , "," , "O" ));
    sentence.tokens.append(Token( "Illyrio" , "Illyrio" , 5 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "Mopatis" , "Mopatis" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "." , "." , 7 , "." , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 3 ).setDep( "amod" , 2 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 3 ).setDep( "appos" , 6 );
    Rules::checkRuleAppos2(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}


void MainTests::checkRuleToWork_oneProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "we" , "we" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "found" , "find" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "out" , "out" , 3 , "RP" , "O" ));
    sentence.tokens.append(Token( "that" , "that" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 5 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "worked" , "work" , 6 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 7 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "manager" , "manager" , 9 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "compound" , 3 );
    sentence.getById( 6 ).setDep( "nsubj" , 5 );
    sentence.getById( 9 ).setDep( "case" , 7 );
    sentence.getById( 6 ).setDep( "obl" , 9 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Abigail","manager");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_compProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "worked" , "work" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "police" , "police" , 4 , "NNS" , "TITLE" ));
    sentence.tokens.append(Token( "officer" , "officer" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "internal" , "internal" , 7 , "JJ" , "O" ));
    sentence.tokens.append(Token( "security" , "security" , 8 , "NN" , "O" ));
    sentence.tokens.append(Token( "expert" , "expert" , 9 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 9 ).setDep( "case" , 3 );
    sentence.getById( 5 ).setDep( "compound" , 4 );
    sentence.getById( 9 ).setDep( "compound" , 5 );
    sentence.getById( 8 ).setDep( "amod" , 7 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Abigail","police officer");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_fewProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "worked" , "work" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 4 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 5 , "CC" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 6 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 4 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 4 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Abigail","doctor");
    expected.insert("Abigail","policeman");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_NotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "Gabe" , "Gabe" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "works" , "work" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "paperboy" , "paperboy" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "." , "." , 6 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 2 ).setDep( "punct" , 6 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_twoCompProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("war lord");
    profList.append("hunter");
    profList.append("cyberpolice robot");
    sentence.tokens.append(Token( "Gabe" , "Gabe" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "works" , "work" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "cyberpolice" , "cyberpolice" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "robot" , "robot" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "war" , "war" , 8 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "lord" , "lord" , 9 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "case" , 3 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 2 ).setDep( "obl" , 6 );
    sentence.getById( 9 ).setDep( "compound" , 8 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Gabe","cyberpolice robot");
    expected.insert("Gabe","war");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_profAndCompProfNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Gabe" , "Gabe" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "works" , "work" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "detective" , "detective" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "cyberpolice" , "cyberpolice" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "robot" , "robot" , 8 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 8 ).setDep( "case" , 3 );
    sentence.getById( 8 ).setDep( "compound" , 5 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Gabe","cyberpolice");
    expected.insert("Gabe","detective");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_twoPersons(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Gabe" , "Gabe" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "works" , "work" , 2 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "detective" , "detective" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Carl" , "Carl" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "works" , "work" , 8 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 9 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 10 , "DT" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 11 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 8 ).setDep( "nsubj" , 7 );
    sentence.getById( 11 ).setDep( "case" , 9 );
    sentence.getById( 8 ).setDep( "obl" , 11 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Carl","doctor");
    expected.insert("Gabe","detective");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_noNsubjDep(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "we" , "we" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "found" , "find" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "out" , "out" , 3 , "RP" , "O" ));
    sentence.tokens.append(Token( "that" , "that" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 5 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "worked" , "work" , 6 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 7 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "manager" , "manager" , 9 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "compound" , 3 );
    sentence.getById( 9 ).setDep( "case" , 7 );
    sentence.getById( 6 ).setDep( "obl" , 9 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_noObjDep(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "we" , "we" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "found" , "find" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "out" , "out" , 3 , "RP" , "O" ));
    sentence.tokens.append(Token( "that" , "that" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 5 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "worked" , "work" , 6 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 7 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "manager" , "manager" , 9 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "compound" , 3 );
    sentence.getById( 9 ).setDep( "case" , 7 );
    sentence.getById( 6 ).setDep( "nsubj" , 5 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_notPerson(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "we" , "we" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "found" , "find" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "out" , "out" , 3 , "RP" , "O" ));
    sentence.tokens.append(Token( "that" , "that" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "worked" , "work" , 6 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 7 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "manager" , "manager" , 9 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "compound" , 3 );
    sentence.getById( 6 ).setDep( "nsubj" , 5 );
    sentence.getById( 9 ).setDep( "case" , 7 );
    sentence.getById( 6 ).setDep( "obl" , 9 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}


void MainTests::checkRuleToWork_personIsNotNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "we" , "we" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "found" , "find" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "out" , "out" , 3 , "RP" , "O" ));
    sentence.tokens.append(Token( "that" , "that" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 5 , "O" , "PERSON" ));
    sentence.tokens.append(Token( "worked" , "work" , 6 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 7 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "manager" , "manager" , 9 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "compound" , 3 );
    sentence.getById( 6 ).setDep( "nsubj" , 5 );
    sentence.getById( 9 ).setDep( "case" , 7 );
    sentence.getById( 6 ).setDep( "obl" , 9 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}


void MainTests::checkRuleToWork_noTitle(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "we" , "we" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "found" , "find" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "out" , "out" , 3 , "RP" , "O" ));
    sentence.tokens.append(Token( "that" , "that" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 5 , "NN" , "PERSON" ));
    sentence.tokens.append(Token( "worked" , "work" , 6 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 7 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "manager" , "manager" , 9 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "compound" , 3 );
    sentence.getById( 6 ).setDep( "nsubj" , 5 );
    sentence.getById( 9 ).setDep( "case" , 7 );
    sentence.getById( 6 ).setDep( "obl" , 9 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToWork_titleIsNotNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "we" , "we" , 1 , "PRP" , "O" ));
    sentence.tokens.append(Token( "found" , "find" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "out" , "out" , 3 , "RP" , "O" ));
    sentence.tokens.append(Token( "that" , "that" , 4 , "IN" , "O" ));
    sentence.tokens.append(Token( "Abigail" , "Abigail" , 5 , "NN" , "PERSON" ));
    sentence.tokens.append(Token( "worked" , "work" , 6 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 7 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "manager" , "manager" , 9 , "O" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 2 ).setDep( "compound" , 3 );
    sentence.getById( 6 ).setDep( "nsubj" , 5 );
    sentence.getById( 9 ).setDep( "case" , 7 );
    sentence.getById( 6 ).setDep( "obl" , 9 );
    Rules::checkRuleToWork(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleReignOf_oneProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    sentence.tokens.append(Token( "Down" , "down" , 1 , "RB" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 2 , "IN" , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "reign" , "reign" , 4 , "NN" , "O" ));
    sentence.tokens.append(Token( "of" , "of" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Richard" , "Richard" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "II" , "II" , 7 , "NNP" , "PERSON" ));
    sentence.getById( 4 ).setDep( "case" , 2 );
    sentence.getById( 1 ).setDep( "obl" , 4 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 4 ).setDep( "nmod" , 7 );
    Rules::checkRuleReignOf(profNames,sentence);
    QMultiHash<QString,QString> expected;
    expected.insert("Richard","King");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleReignOf_twoCharacter(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    sentence.tokens.append(Token( "Down" , "down" , 1 , "RB" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 2 , "IN" , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "reign" , "reign" , 4 , "NN" , "O" ));
    sentence.tokens.append(Token( "of" , "of" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "Richard" , "Richard" , 6 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "Catherine" , "Catherine" , 8 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "the" , "the" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "Great" , "Great" , 10 , "NNP" , "O" ));
    sentence.tokens.append(Token( "." , "." , 11 , "." , "O" ));
    sentence.getById( 4 ).setDep( "case" , 2 );
    sentence.getById( 1 ).setDep( "obl" , 4 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    sentence.getById( 4 ).setDep( "nmod" , 7 );
    Rules::checkRuleReignOf(profNames,sentence);
    QMultiHash<QString,QString> expected;
    expected.insert("Richard","King");
    expected.insert("Catherine","King");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleReignOf_profNotToPerson(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    sentence.tokens.append(Token( "down" , "down" , 1 , "RB" , "O" ));
    sentence.tokens.append(Token( "to" , "to" , 2 , "IN" , "O" ));
    sentence.tokens.append(Token( "the" , "the" , 3 , "DT" , "O" ));
    sentence.tokens.append(Token( "reign" , "reign" , 4 , "NN" , "O" ));
    sentence.tokens.append(Token( "of" , "of" , 5 , "IN" , "O" ));
    sentence.tokens.append(Token( "his" , "he" , 6 , "PRP$" , "O" ));
    sentence.tokens.append(Token( "son" , "son" , 7 , "NN" , "O" ));
    sentence.getById( 4 ).setDep( "case" , 2 );
    sentence.getById( 1 ).setDep( "obl" , 4 );
    sentence.getById( 7 ).setDep( "case" , 5 );
    sentence.getById( 7 ).setDep( "nmod" , 6 );
    sentence.getById( 4 ).setDep( "nmod" , 7 );
    Rules::checkRuleReignOf(profNames,sentence);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleReignOf_profNotToPersons(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    sentence.tokens.append(Token( "reign" , "reign" , 1 , "NN" , "O" ));
    sentence.tokens.append(Token( "of" , "of" , 2 , "IN" , "O" ));
    sentence.tokens.append(Token( "beautiful" , "beautiful" , 3 , "JJ" , "O" ));
    sentence.tokens.append(Token( "girl" , "girl" , 4 , "NN" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 5 , "CC" , "O" ));
    sentence.tokens.append(Token( "beautiful" , "beautiful" , 6 , "JJ" , "O" ));
    sentence.tokens.append(Token( "man" , "man" , 7 , "NN" , "O" ));
    sentence.getById( 4 ).setDep( "case" , 2 );
    sentence.getById( 4 ).setDep( "amod" , 3 );
    sentence.getById( 1 ).setDep( "nmod" , 4 );
    sentence.getById( 7 ).setDep( "amod" , 6 );
    Rules::checkRuleReignOf(profNames,sentence);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleReignOf_OnlyToOnePerson(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    sentence.tokens.append(Token( "reign" , "reign" , 1 , "NN" , "O" ));
    sentence.tokens.append(Token( "of" , "of" , 2 , "IN" , "O" ));
    sentence.tokens.append(Token( "arl" , "arl" , 3 , "NN" , "PERSON" ));
    sentence.tokens.append(Token( "II" , "ii" , 4 , "CD" , "NUMBER" ));
    sentence.tokens.append(Token( "and" , "and" , 5 , "CC" , "O" ));
    sentence.tokens.append(Token( "beautiful" , "beautiful" , 6 , "JJ" , "O" ));
    sentence.tokens.append(Token( "girl" , "girl" , 7 , "NN" , "O" ));
    sentence.getById( 7 ).setDep( "case" , 2 );
    sentence.getById( 7 ).setDep( "compound" , 3 );
    sentence.getById( 1 ).setDep( "nmod" , 7 );
    Rules::checkRuleReignOf(profNames,sentence);
    QMultiHash<QString,QString> expected;
    expected.insert("arl","King");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checRuleJob_oneProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "builder" , "builder" , 6 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mark","builder");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checRuleJob_twoProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 8 , "DT" , "O" ));
    sentence.tokens.append(Token( "lifeguard" , "lifeguard" , 9 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mark","policeman");
    expected.insert("Mark","lifeguard");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checRuleJob_compProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("treasure hunter");
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "treasure" , "treasure" , 6 , "NN" , "O" ));
    sentence.tokens.append(Token( "hunter" , "hunter" , 7 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 7 ).setDep( "nsubj" , 3 );
    sentence.getById( 7 ).setDep( "compound" , 6 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mark","treasure hunter");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_notInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "vegetation" , "vegetation" , 5 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 5 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_twoCompProfNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 5 , "JJ" , "O" ));
    sentence.tokens.append(Token( "robot" , "robot" , 6 , "NN" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "war" , "war" , 8 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "lord" , "lord" , 9 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    sentence.getById( 6 ).setDep( "amod" , 5 );
    sentence.getById( 9 ).setDep( "compound" , 8 );;
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_twoCompProfInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("cyberpoliceman robot");
    profList.append("war lord");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 5 , "JJ" , "O" ));
    sentence.tokens.append(Token( "robot" , "robot" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "war" , "war" , 8 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "lord" , "lord" , 9 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    sentence.getById( 6 ).setDep( "amod" , 5 );
    sentence.getById( 9 ).setDep( "compound" , 8 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","cyberpoliceman robot");
    expected.insert("Mike","war");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_twoCompProfOneInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("cyberpoliceman robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 5 , "JJ" , "O" ));
    sentence.tokens.append(Token( "robot" , "robot" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "war" , "war" , 8 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "lord" , "lord" , 9 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    sentence.getById( 6 ).setDep( "amod" , 5 );
    sentence.getById( 9 ).setDep( "compound" , 8 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","cyberpoliceman robot");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checRuleJob_profAndCompProfNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("cyberpoliceman robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "are" , "be" , 4 , "VBP" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "war" , "war" , 7 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "lord" , "lord" , 8 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 5 ).setDep( "nsubj" , 3 );
    sentence.getById( 8 ).setDep( "compound" , 7 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","policeman");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_twoPers(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("cyberpoliceman robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Carls" , "Carls" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 8 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 9 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 10 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 11 , "DT" , "O" ));
    sentence.tokens.append(Token( "detective" , "detective" , 12 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 5 ).setDep( "nsubj" , 3 );
    sentence.getById( 9 ).setDep( "nmod" , 7 );
    sentence.getById( 7 ).setDep( "case" , 8 );
    sentence.getById( 12 ).setDep( "nsubj" , 9 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Carls","detective");
    expected.insert("Mike","policeman");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_twoPersAndTwoProfs(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("cyberpoliceman robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "soldier" , "soldier" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 8 , "CC" , "O" ));
    sentence.tokens.append(Token( "Carls" , "Carls" , 9 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 10 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 11 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 12 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 13 , "DT" , "O" ));
    sentence.tokens.append(Token( "detective" , "detective" , 14 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 15 , "CC" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 16 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 5 ).setDep( "nsubj" , 3 );
    sentence.getById( 11 ).setDep( "nmod" , 9 );
    sentence.getById( 9 ).setDep( "case" , 10 );
    sentence.getById( 14 ).setDep( "nsubj" , 11 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Carls","detective");
    expected.insert("Carls","doctor");
    expected.insert("Mike","policeman");
    expected.insert("Mike","soldier");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_twoPersOneWithProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("cyberpoliceman robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Carls" , "Carls" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 8 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 9 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 10 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "fool" , "fool" , 11 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 5 ).setDep( "nsubj" , 3 );
    sentence.getById( 9 ).setDep( "nmod" , 7 );
    sentence.getById( 7 ).setDep( "case" , 8 );
    sentence.getById( 11 ).setDep( "nsubj" , 9 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","policeman");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_twoPersWithoutProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "groot" , "groot" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "Carls" , "Carls" , 7 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 8 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 9 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 10 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "fool" , "fool" , 11 , "NN" , "O" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 5 ).setDep( "nsubj" , 3 );
    sentence.getById( 9 ).setDep( "nmod" , 7 );
    sentence.getById( 7 ).setDep( "case" , 8 );
    sentence.getById( 11 ).setDep( "nsubj" , 9 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_mix1(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "are" , "be" , 4 , "VBP" , "O" ));
    sentence.tokens.append(Token( "policeman" , "policeman" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 6 , "CC" , "O" ));
    sentence.tokens.append(Token( "soldier" , "soldier" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 8 , "CC" , "O" ));
    sentence.tokens.append(Token( "Carls" , "Carls" , 9 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 10 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 11 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 12 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 13 , "DT" , "O" ));
    sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 14 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 5 ).setDep( "nsubj" , 3 );
    sentence.getById( 11 ).setDep( "nmod" , 9 );
    sentence.getById( 9 ).setDep( "case" , 10 );
    sentence.getById( 14 ).setDep( "nsubj" , 11 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","policeman");
    expected.insert("Mike","soldier");
    expected.insert("Carls","cyberpoliceman");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_jobNotNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "O" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "builder" , "builder" , 6 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_noJobWord(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "jodb" , "jodb" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "builder" , "builder" , 6 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}


void MainTests::checRuleJob_noNmodDep(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "builder" , "builder" , 6 , "NN" , "TITLE" ));
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_personNotNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "O" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "builder" , "builder" , 6 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_noApostrophe(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NN" , "PERSON" ));
    sentence.tokens.append(Token( "s" , "s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "builder" , "builder" , 6 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checRuleJob_noPerson(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NN" , "O" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "builder" , "builder" , 6 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 1 ).setDep( "case" , 2 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());
}

void MainTests::checRuleJob_noCaseDep(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "Mark" , "Mark" , 1 , "NN" , "PERSON" ));
    sentence.tokens.append(Token( "'s" , "'s" , 2 , "POS" , "O" ));
    sentence.tokens.append(Token( "job" , "job" , 3 , "NN" , "O" ));
    sentence.tokens.append(Token( "is" , "be" , 4 , "VBZ" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 5 , "DT" , "O" ));
    sentence.tokens.append(Token( "builder" , "builder" , 6 , "NN" , "TITLE" ));
    sentence.getById( 3 ).setDep( "nmod" , 1 );
    sentence.getById( 6 ).setDep( "nsubj" , 3 );
    Rules::checkRuleJob(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());
}

void MainTests::checkRuleToPractice_oneProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "John" , "John" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "for" , "for" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "some" , "some" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "time" , "time" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "barrister" , "barrister" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 7 ).setDep( "case" , 6 );
    sentence.getById( 2 ).setDep( "obl" , 7 );
    sentence.getById( 2 ).setDep( "punct" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("John","barrister");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToPractice_twoProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "John" , "John" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "for" , "for" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "some" , "some" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "time" , "time" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "barrister" , "barrister" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 8 , "CC" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 9 , "DT" , "O" ));
    sentence.tokens.append(Token( "waiter" , "waiter" , 10 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 11 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 7 ).setDep( "case" , 6 );
    sentence.getById( 2 ).setDep( "obl" , 7 );
    sentence.getById( 2 ).setDep( "punct" , 11 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("John","barrister");
    expected.insert("John","waiter");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToPractice_compProf(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("archer");
    profList.append("hunter");
    profList.append("children's doctor");
    profList.append("military doctor");
    sentence.tokens.append(Token( "John" , "John" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "for" , "for" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "some" , "some" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "time" , "time" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 7 , "DT" , "O" ));
    sentence.tokens.append(Token( "military" , "military" , 8 , "JJ" , "O" ));
    sentence.tokens.append(Token( "doctor" , "doctor" , 9 , "NN" , "TITLE" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 9 ).setDep( "case" , 6 );
    sentence.getById( 9 ).setDep( "amod" , 8 );
    sentence.getById( 2 ).setDep( "obl" , 9 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("John","military doctor");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToPractice_notInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("major captain");
    sentence.tokens.append(Token( "Jonh" , "Jonh" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "cyberplayer" , "cyberplayer" , 5 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToPractice_twoCompProfInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("cyberpoliceman robot");
    profList.append("war lord");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 5 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "robot" , "robot" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "war" , "war" , 8 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "lord" , "lord" , 9 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "case" , 3 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 2 ).setDep( "obl" , 6 );
    sentence.getById( 9 ).setDep( "compound" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","cyberpoliceman robot");
    expected.insert("Mike","war");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToPractice_twoCompProfOneInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    profList.append("cyberpoliceman robot");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "robot" , "robot" , 6 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "war" , "war" , 8 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "lord" , "lord" , 9 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "case" , 3 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 2 ).setDep( "obl" , 6 );
    sentence.getById( 9 ).setDep( "compound" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    expected.insert("Mike","cyberpoliceman robot");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToPractice_twoCompProfNotInList(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    profList.append("fire mage");
    profList.append("hunter");
    sentence.tokens.append(Token( "Mike" , "Mike" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "a" , "a" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "robot" , "robot" , 6 , "NN" , "O" ));
    sentence.tokens.append(Token( "and" , "and" , 7 , "CC" , "O" ));
    sentence.tokens.append(Token( "war" , "war" , 8 , "NN" , "CAUSE_OF_DEATH" ));
    sentence.tokens.append(Token( "lord" , "lord" , 9 , "NN" , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 6 ).setDep( "case" , 3 );
    sentence.getById( 6 ).setDep( "compound" , 5 );
    sentence.getById( 2 ).setDep( "obl" , 6 );
    sentence.getById( 9 ).setDep( "compound" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}


void MainTests::checkRuleToPractice_noNsubjDep(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "John" , "John" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "for" , "for" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "some" , "some" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "time" , "time" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "barrister" , "barrister" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    //sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 7 ).setDep( "case" , 6 );
    sentence.getById( 2 ).setDep( "obl" , 7 );
    sentence.getById( 2 ).setDep( "punct" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToPractice_noObjDep(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "John" , "John" , 1 , "NNP" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "for" , "for" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "some" , "some" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "time" , "time" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "barrister" , "barrister" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 7 ).setDep( "case" , 6 );
    //sentence.getById( 2 ).setDep( "obl" , 7 );
    sentence.getById( 2 ).setDep( "punct" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToPractice_personNotNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "John" , "John" , 1 , "O" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "for" , "for" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "some" , "some" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "time" , "time" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "barrister" , "barrister" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 7 ).setDep( "case" , 6 );
    sentence.getById( 2 ).setDep( "obl" , 7 );
    sentence.getById( 2 ).setDep( "punct" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::checkRuleToPractice_noPerson(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "John" , "John" , 1 , "NN" , "O" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "for" , "for" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "some" , "some" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "time" , "time" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "barrister" , "barrister" , 7 , "NN" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 7 ).setDep( "case" , 6 );
    sentence.getById( 2 ).setDep( "obl" , 7 );
    sentence.getById( 2 ).setDep( "punct" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}
void MainTests::checkRuleToPractice_titleNotNN(){
    QMultiHash<QString,QString> profNames;
    Sentence sentence;
    QStringList profList;
    profList.append(perpList);
    sentence.tokens.append(Token( "John" , "John" , 1 , "NN" , "PERSON" ));
    sentence.tokens.append(Token( "practiced" , "practice" , 2 , "VBD" , "O" ));
    sentence.tokens.append(Token( "for" , "for" , 3 , "IN" , "O" ));
    sentence.tokens.append(Token( "some" , "some" , 4 , "DT" , "O" ));
    sentence.tokens.append(Token( "time" , "time" , 5 , "NN" , "O" ));
    sentence.tokens.append(Token( "as" , "as" , 6 , "IN" , "O" ));
    sentence.tokens.append(Token( "barrister" , "barrister" , 7 , "O" , "TITLE" ));
    sentence.tokens.append(Token( "." , "." , 8 , "." , "O" ));
    sentence.getById( 2 ).setDep( "nsubj" , 1 );
    sentence.getById( 5 ).setDep( "case" , 3 );
    sentence.getById( 2 ).setDep( "obl" , 5 );
    sentence.getById( 7 ).setDep( "case" , 6 );
    sentence.getById( 2 ).setDep( "obl" , 7 );
    sentence.getById( 2 ).setDep( "punct" , 8 );
    Rules::checkRuleToPractice(profNames,sentence,profList);
    QMultiHash<QString,QString> expected;
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());

}

void MainTests::analyzeFileWithNames_1(){
    QMultiHash<QString,QString> profNames;
    QStringList names;
    names.append("Jimmy");
    names.append("Dr.Watson");
    names.append("Mr.Adam");
    names.append("Sandra Callen");
    Rules::analyzeFileWithNames(names,profNames,perpList);
    QMultiHash<QString,QString> expected;
    expected.insert("watson","dr.");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());


}

void MainTests::analyzeFileWithNames_2(){
    QMultiHash<QString,QString> profNames;
    QStringList names;
    names.append("Jimmy");
    names.append("King Artur");
    names.append("Miss Huston");
    names.append("Father Jon");
    names.append("Brother Jason");
    Rules::analyzeFileWithNames(names,profNames,perpList);
    QMultiHash<QString,QString> expected;
    expected.insert(" artur","king");
    expected.insert(" jon","father");
    expected.insert(" jason","brother");
    QString message;
    QVERIFY2(compareMultiHash(profNames,expected,message),message.toUtf8());


}
void MainTests::getCompoundProf_notComp(){
       Sentence sentence;
       QStringList profList;
       profList.append(perpList);
       sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
       sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
       sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
       sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
       sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
       sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
       sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
       sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
       sentence.tokens.append(Token( "the" , "the" , 9 , "DT" , "O" ));
       sentence.tokens.append(Token( "captain" , "captain" , 10 , "NN" , "TITLE" ));
       sentence.tokens.append(Token( "." , "." , 11 , "." , "O" ));
       sentence.getById( 2 ).setDep( "nmod" , 1 );
       sentence.getById( 3 ).setDep( "nsubj" , 2 );
       sentence.getById( 3 ).setDep( "obj" , 4 );
       sentence.getById( 7 ).setDep( "case" , 5 );
       sentence.getById( 7 ).setDep( "compound" , 6 );
       sentence.getById( 7 ).setDep( "punct" , 8 );
       sentence.getById( 7 ).setDep( "appos" , 10 );
       sentence.getById( 3 ).setDep( "punct" , 11 );
       QString prof;
       Rules::getCompoundProf(sentence,10,prof,profList);
       QCOMPARE(prof,"captain");
}

void MainTests::getCompoundProf_oneDepWord(){
       Sentence sentence;
       QStringList profList;
       profList.append(perpList);
       profList.append("captain of guard");
       sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
       sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
       sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
       sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
       sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
       sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
       sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
       sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
       sentence.tokens.append(Token( "the" , "the" , 9 , "DT" , "O" ));
       sentence.tokens.append(Token( "captain" , "captain" , 10 , "NN" , "TITLE" ));
       sentence.tokens.append(Token( "of" , "of" , 11 , "IN" , "O" ));
       sentence.tokens.append(Token( "guard" , "guard" , 12 , "NN" , "O" ));
       sentence.tokens.append(Token( "." , "." , 13 , "." , "O" ));
       sentence.getById( 2 ).setDep( "nmod" , 1 );
       sentence.getById( 3 ).setDep( "nsubj" , 2 );
       sentence.getById( 3 ).setDep( "obj" , 4 );
       sentence.getById( 7 ).setDep( "case" , 5 );
       sentence.getById( 7 ).setDep( "compound" , 6 );
       sentence.getById( 7 ).setDep( "punct" , 8 );
       sentence.getById( 7 ).setDep( "appos" , 10 );
       sentence.getById( 3 ).setDep( "punct" , 13 );
       QString prof;
       Rules::getCompoundProf(sentence,10,prof,profList);
       QCOMPARE(prof,"captain of guard");
}
void MainTests::getCompoundProf_twoDepWord(){
       Sentence sentence;
       QStringList profList;
       profList.append(perpList);
       profList.append("captain of his household guard");
       sentence.tokens.append(Token( "His" , "he" , 1 , "PRP$" , "O" ));
       sentence.tokens.append(Token( "father" , "father" , 2 , "NN" , "O" ));
       sentence.tokens.append(Token( "handed" , "hand" , 3 , "VBD" , "O" ));
       sentence.tokens.append(Token( "them" , "they" , 4 , "PRP" , "O" ));
       sentence.tokens.append(Token( "to" , "to" , 5 , "IN" , "O" ));
       sentence.tokens.append(Token( "Jory" , "Jory" , 6 , "NNP" , "PERSON" ));
       sentence.tokens.append(Token( "Cassel" , "Cassel" , 7 , "NNP" , "PERSON" ));
       sentence.tokens.append(Token( "," , "," , 8 , "," , "O" ));
       sentence.tokens.append(Token( "the" , "the" , 9 , "DT" , "O" ));
       sentence.tokens.append(Token( "captain" , "captain" , 10 , "NN" , "TITLE" ));
       sentence.tokens.append(Token( "of" , "of" , 11 , "IN" , "O" ));
       sentence.tokens.append(Token( "his" , "he" , 12 , "PRP$" , "O" ));
       sentence.tokens.append(Token( "household" , "household" , 13 , "NN" , "O" ));
       sentence.tokens.append(Token( "guard" , "guard" , 14 , "NN" , "TITLE" ));
       sentence.tokens.append(Token( "." , "." , 15 , "." , "O" ));
       sentence.getById( 2 ).setDep( "nmod" , 1 );
       sentence.getById( 3 ).setDep( "nsubj" , 2 );
       sentence.getById( 7 ).setDep( "case" , 5 );
       sentence.getById( 7 ).setDep( "compound" , 6 );
       sentence.getById( 7 ).setDep( "appos" , 10 );
       sentence.getById( 7 ).setDep( "punct" , 8 );
       sentence.getById( 3 ).setDep( "obl" , 7 );
       sentence.getById( 3 ).setDep( "punct" , 8 );
       sentence.getById( 14 ).setDep( "case" , 11 );
       sentence.getById( 14 ).setDep( "nmod" , 12 );
       sentence.getById( 14 ).setDep( "compound" , 13 );
       sentence.getById( 10 ).setDep( "nmod" , 14 );
       sentence.getById( 3 ).setDep( "punct" , 15 );
       QString prof;
       Rules::getCompoundProf(sentence,10,prof,profList);
       QCOMPARE(prof,"captain of his household guard");
}


void MainTests::getCompoundProf_profInList(){
       Sentence sentence;
       QStringList profList;
       profList.append(perpList);
       profList.append("cyberpoliceman of his guard");
       sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 1 , "NN" , "O" ));
       sentence.tokens.append(Token( "of" , "of" , 2 , "IN" , "O" ));
       sentence.tokens.append(Token( "his" , "he" , 3 , "PRP$" , "O" ));
       sentence.tokens.append(Token( "guard" , "guard" , 4 , "NN" , "TITLE" ));
       sentence.getById( 4 ).setDep( "case" , 2 );
       sentence.getById( 4 ).setDep( "nmod" , 3 );
       sentence.getById( 1 ).setDep( "nmod" , 4 );
       QString prof;
       Rules::getCompoundProf(sentence,1,prof,profList);
       QCOMPARE(prof,"cyberpoliceman of his guard");
}

void MainTests::getCompoundProf_profNotInList(){
       Sentence sentence;
       QStringList profList;
       profList.append(perpList);
       sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 1 , "NN" , "O" ));
       sentence.tokens.append(Token( "of" , "of" , 2 , "IN" , "O" ));
       sentence.tokens.append(Token( "his" , "he" , 3 , "PRP$" , "O" ));
       sentence.tokens.append(Token( "guard" , "guard" , 4 , "NN" , "TITLE" ));
       sentence.getById( 4 ).setDep( "case" , 2 );
       sentence.getById( 4 ).setDep( "nmod" , 3 );
       sentence.getById( 1 ).setDep( "nmod" , 4 );
       QString prof;
       Rules::getCompoundProf(sentence,1,prof,profList);
       QCOMPARE(prof,"cyberpoliceman");
}

void MainTests::getCompoundProf_twoProfInList(){
       Sentence sentence;
       QStringList profList;
       profList.append(perpList);
       profList.append("cyberpoliceman of his guard");
       profList.append("cyberpoliceman of his cyberguard");
       sentence.tokens.append(Token( "cyberpoliceman" , "cyberpoliceman" , 1 , "NN" , "O" ));
       sentence.tokens.append(Token( "of" , "of" , 2 , "IN" , "O" ));
       sentence.tokens.append(Token( "his" , "he" , 3 , "PRP$" , "O" ));
       sentence.tokens.append(Token( "cyberguard" , "cyberguard" , 4 , "NN" , "O" ));
       sentence.getById( 4 ).setDep( "case" , 2 );
       sentence.getById( 4 ).setDep( "nmod" , 3 );
       sentence.getById( 1 ).setDep( "nmod" , 4 );
       QString prof;
       Rules::getCompoundProf(sentence,1,prof,profList);
       QCOMPARE(prof,"cyberpoliceman of his cyberguard");
}

QTEST_MAIN(MainTests)
#include "debug/tst_maintests.moc"
