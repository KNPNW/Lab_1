#include "Test.h"
#include "MusCompClass.h"
#include "Array.h"
#include <string>
#include <assert.h>


using namespace std;
const string DEFAULT_NAME = "no name";
const string DEFAULT_AUTHOR = "no author";
const mood DEFAULT_MOOD = {0,0};

const string TEST_NAME = "Цой";
const string TEST_AUTHOR = "Кукушка";
const mood TEST_MOOD =  {5.1,2.3};

void testDefaultConstructorAndSets() {
    MusCompClass defaultMusic;
    assert(defaultMusic.getName() == DEFAULT_NAME);
    assert(defaultMusic.getAuthor() == DEFAULT_AUTHOR);
    assert(defaultMusic.getMood().first == DEFAULT_MOOD.first);
    assert(defaultMusic.getMood().second == DEFAULT_MOOD.second);

    defaultMusic.setName("Цой");
    defaultMusic.setAuthor("Кукушка");
    defaultMusic.setMood({5.1, 2.3});
    defaultMusic.setMood(5.1, 2.4);
    assert(defaultMusic.getName() == TEST_NAME);
    assert(defaultMusic.getAuthor() == TEST_AUTHOR);
    assert(defaultMusic.getMood().first == TEST_MOOD.first);
    assert(defaultMusic.getMood().second == 2.4);
}

void testInitAndCopyConstructor() {
    MusCompClass initMusic(TEST_NAME, TEST_AUTHOR, TEST_MOOD);
    assert(initMusic.getName() == TEST_NAME);
    assert(initMusic.getAuthor() == TEST_AUTHOR);
    assert(initMusic.getMood().first == TEST_MOOD.first);
    assert(initMusic.getMood().second == TEST_MOOD.second);

    MusCompClass copyMusic(initMusic);
    assert(copyMusic.getName() == TEST_NAME);
    assert(copyMusic.getAuthor() == TEST_AUTHOR);
    assert(initMusic.getMood().first == TEST_MOOD.first);
    assert(initMusic.getMood().second == TEST_MOOD.second);
}

void testArray(){
    Array firstArray;
    firstArray.fromFile("/Users/kirillpadalica/HSE/2nd_year/OOP/Laboratory/Lab1/testData.txt");

    printAllArray(firstArray);

    Array secondArray(firstArray);
    assert(firstArray.comparison(secondArray) == true);

    secondArray.del();
    assert(  firstArray.comparison(secondArray) == false);

    secondArray.delAll();
    assert(secondArray.getSize() == 0);

    MusCompClass obj("Цой", "Кукушка", {5.1, 2.3});
    firstArray.insert(obj, 2);
    assert(firstArray.getObject(2).getName() == "Цой");

    secondArray.copyArray(firstArray);
    assert(firstArray.comparison(secondArray) == true);

    int size = firstArray.getSize();
    assert(size == 13);

    secondArray.del();
    secondArray.toFile("/Users/kirillpadalica/HSE/2nd_year/OOP/Laboratory/Lab1/output.txt");
    firstArray.fromFile("/Users/kirillpadalica/HSE/2nd_year/OOP/Laboratory/Lab1/output.txt");
    assert(firstArray.comparison(secondArray) == true);

    Array initArray(obj);
    assert(initArray.getObject(0).getName() == "Цой");
    assert(initArray.getSize() == 1);

    assert(secondArray.getSize() == 12);
    secondArray.pushBack(obj);
    assert(secondArray.getSize() == 13);
    assert(secondArray.getLastObject().getName() == "Цой");

    assert(secondArray.getSize() == 13);
    secondArray.del();
    assert(secondArray.getSize() == 12);
    assert(secondArray.getLastObject().getName() != "Цой");

    secondArray.insert(obj, 5);
    assert(secondArray.getObject(5).getName() == "Цой");

    secondArray.del(5);
    assert(secondArray.getObject(5).getName() != "Цой");
}