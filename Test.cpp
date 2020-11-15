#include "Test.h"
#include "MusCompClass.h"
#include <string>
#include <assert.h>

using namespace std;
const string DEFAULT_NAME = "no name";
const string DEFAULT_AUTHOR = "no author";
const mood DEFAULT_MOOD = {1,2};

const string TEST_NAME = "Nutcracker";
const string TEST_AUTHOR = "Tchaikovsky";
const mood TEST_MOOD =  {1,2};

void testDefaultConstructorAndSets() {
    MusCompClass defaultMusic;
    assert(defaultMusic.getName() == DEFAULT_NAME);
    assert(defaultMusic.getAuthor() == DEFAULT_AUTHOR);
//    assert(defaultMusic.getMood() == DEFAULT_MOOD);

    defaultMusic.setName("Nutcracker");
    defaultMusic.setAuthor("Tchaikovsky");
//    defaultMusic.setMood("Good");
    assert(defaultMusic.getName() == TEST_NAME);
    assert(defaultMusic.getAuthor() == TEST_AUTHOR);
//    assert(defaultMusic.getMood() == TEST_MOOD);
}

void testInitAndCopyConstructor() {
    MusCompClass initMusic(TEST_NAME, TEST_AUTHOR, TEST_MOOD);
    assert(initMusic.getName() == TEST_NAME);
    assert(initMusic.getAuthor() == TEST_AUTHOR);
//    assert(initMusic.getMood() == TEST_MOOD);

    MusCompClass copyMusic(initMusic);
    assert(copyMusic.getName() == TEST_NAME);
    assert(copyMusic.getAuthor() == TEST_AUTHOR);
//    assert(copyMusic.getMood() == TEST_MOOD);
}