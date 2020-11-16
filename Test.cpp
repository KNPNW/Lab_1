#include "Test.h"
#include "MusCompClass.h"
#include "Array.h"
#include <string>
#include <assert.h>
#include <iostream>

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
    firstArray.fromFile("/Users/kirillpadalica/HSE/2nd year/OOP/Laboratory/Lab1/testData.txt");
    Array secondArray(firstArray);
    bool result;
    result = firstArray.comparison(secondArray);
    assert(result == true);
    secondArray.del();
    result = firstArray.comparison(secondArray);
    assert(result == false);
    Array emptyArray;
    secondArray.delAll();
    result = secondArray.comparison(emptyArray);
    assert(result == true);
    MusCompClass obj("Цой", "Кукушка", {5.1, 2.3});
    firstArray.insert(obj, 2);
    MusCompClass getObj = firstArray.getObject(2);
    assert(getObj.getName() == "Цой");
    secondArray.copyArray(firstArray);
    result = firstArray.comparison(secondArray);
    assert(result == true);
    int size = firstArray.getSize();
    assert(size == 13);
    secondArray.toFile("/Users/kirillpadalica/HSE/2nd year/OOP/Laboratory/Lab1/output.txt");
    emptyArray.fromFile("/Users/kirillpadalica/HSE/2nd year/OOP/Laboratory/Lab1/output.txt");
    result = emptyArray.comparison(firstArray);
    assert(result == true);
    Array initArray(obj);
    assert(initArray.getObject(0).getName() == "Цой");
    secondArray.add(obj);
    assert(secondArray.getLastObject().getName() == "Цой");
    secondArray.del();
    assert(secondArray.getLastObject().getName() != "Цой");
    secondArray.insert(obj, 5);
    assert(secondArray.getObject(5).getName() == "Цой");
    secondArray.del(5);
    assert(secondArray.getObject(5).getName() != "Цой");
}