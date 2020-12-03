#include "popyriclass.h"
#include <iostream>
#include <string>

using namespace std;

PopyriClass::PopyriClass(const string& newName, const string& newAuthor, const mood& newMood, const moodPopyri& newPMood) :
        MusCompClass(newName, newAuthor, newMood){
    popyriMood = newPMood;
}

PopyriClass::PopyriClass(const PopyriClass& existPopyri): MusCompClass(existPopyri){
    setPopyriMood(existPopyri.getPopyriMood());
}

const moodPopyri& PopyriClass::getPopyriMood() const{
    return popyriMood;
}

void PopyriClass::printParams() const{
    cout << "PopyriClass" << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Start mood: " << popyriMood.startMood << endl;
    cout << "Finish mood: " << popyriMood.finishMood << endl;
}

void PopyriClass::setPopyriMood(const moodPopyri &newMood) {
    popyriMood = newMood;
}

void PopyriClass::setPopyriMood(const double &sMood, const double &fMood) {
    popyriMood = {sMood, fMood};
}

bool PopyriClass::equalPObj(PopyriClass* secondObj) {
    return this->getName() == secondObj->getName() &&
           this->getAuthor() == secondObj->getAuthor() &&
           this->getMood().first == secondObj->getMood().first &&
           this->getMood().second == secondObj->getMood().second &&
           popyriMood.startMood == secondObj->getPopyriMood().startMood &&
           popyriMood.finishMood == secondObj->getPopyriMood().finishMood;
}
