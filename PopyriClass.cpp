#include "PopyriClass.h"
#include <string>

using namespace std;

PopyriClass::PopyriClass(const string& newName, const moodPopyri& newMood){
    popyriName = newName;
    popyriMood = newMood;
}

PopyriClass::PopyriClass(const PopyriClass& existPopyri):
    popyriName(existPopyri.popyriName),
    popyriMood(existPopyri.popyriMood){}


const string& PopyriClass::getPopyriName() const {
    return popyriName;
}

const moodPopyri& PopyriClass::getPopyriMood() const {
    return popyriMood;
}

void PopyriClass::setPopyriName(const string &newName) {
    popyriName = newName;
}

void PopyriClass::setPopyriMood(const moodPopyri &newMood) {
    popyriMood = newMood;
}

void PopyriClass::setPopyriMood(const double &sMood, const double &fMood) {
    popyriMood = {sMood, fMood};
}



