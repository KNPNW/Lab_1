#include <iostream>
#include "Test.h"
#include "Array.h"
#include "MusCompClass.h"
#include <string>

using namespace std;

int main()
{
    const string TEST_NAME = "Nutcracker";
    const string TEST_AUTHOR = "Tchaikovsky";
    const mood TEST_MOOD = {1, 1};
//    testDefaultConstructorAndSets();
//    testInitAndCopyConstructor();
    std::cout << "Успешно!" << std::endl;
    Array test, testF;
    MusCompClass ttt;
    MusCompClass initMusic(TEST_NAME, TEST_AUTHOR, TEST_MOOD);
    MusCompClass fMusic(TEST_NAME,  "1", TEST_MOOD);
    MusCompClass sMusic(TEST_NAME,  "2", TEST_MOOD);
    MusCompClass tMusic(TEST_NAME,  "3", TEST_MOOD);
    MusCompClass iMusic(TEST_NAME,  "666", TEST_MOOD);
    test.add(fMusic);
    test.add(sMusic);
    test.add(tMusic);
    test.add(initMusic);
    test.add(ttt);
    ttt.setMood(2, 3);
    test.add(ttt);
    test.insert(iMusic, 2);
    cout << test.getObject(0).getAuthor() << endl;
    cout << test.getObject(1).getAuthor() << endl;
    cout << test.getObject(2).getAuthor() << endl;
    cout << test.getObject(3).getAuthor() << endl;
    cout << test.getObject(4).getAuthor() << endl;
    cout << test.getObject(5).getAuthor() << endl;
    cout << test.getObject(6).getAuthor() << endl;
    testF.fromFile("/Users/kirillpadalica/HSE/2nd year/OOP/Laboratory/Lab1/testData.txt");

    cout << testF.getObject(0).getAuthor() << endl;
    Array neww = testF.sortLimit(0.0, 10.0, 0.0, 10.0);
    return 0;
}
