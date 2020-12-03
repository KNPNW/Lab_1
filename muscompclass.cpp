#include "muscompclass.h"
#include <iostream>
#include <string>

using namespace std;

MusCompClass::MusCompClass(const string &newName, const string &newAuthor, const mood& newMood){
    musicName = newName;
    musicAuthor = newAuthor;
    musicMood = newMood;
}

MusCompClass::~MusCompClass(){}

MusCompClass::MusCompClass(const MusCompClass& existMusic):
        musicName(existMusic.musicName),
        musicAuthor(existMusic.musicAuthor),
        musicMood(existMusic.musicMood){}

const string& MusCompClass::getName() const {
    return musicName;
}

const string& MusCompClass::getAuthor() const {
    return musicAuthor;
}

const mood& MusCompClass::getMood() const {
    return musicMood;
}

void MusCompClass::printParams() const {
    cout << "MusCompClass" << endl;
    cout << "Name: " << musicName << endl;
    cout << "Author: " << musicAuthor << endl;
    cout << "Mood: " << musicMood.first << " " << musicMood.second << endl;
}

void MusCompClass::setName(const string &newName){
    musicName = newName;
}

void MusCompClass::setAuthor(const string &newAuthor){
    musicAuthor = newAuthor;
}

void MusCompClass::setMood(const mood &newMood){
    musicMood = newMood;
}

void MusCompClass::setMood(const double & fMood, const double & sMood) {
    musicMood = {fMood, sMood};
}

bool MusCompClass::equalObj(MusCompClass* secondObj) {
    return musicName == secondObj->getName() &&
           musicAuthor == secondObj->getAuthor() &&
           musicMood.first == secondObj->getMood().first &&
           musicMood.second == secondObj->getMood().second;
}
