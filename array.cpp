#include "array.h"
#include "muscompclass.h"
#include "popyriclass.h"

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <QString>

using namespace std;

Array::Array(){
    objects = NULL;
    size = 0;
}

Array::Array(MusCompClass* obj){
    objects = NULL;
    size = 0;
    this->pushBack(obj);
}

Array::Array(const Array &oldArray){
    size = oldArray.getSize();
    objects = new MusCompClass*[size];

    for(int i = 0; i < size; i++){
        MusCompClass *music = oldArray.getObject(i);
        if (music->get_class() == "MusCompClass")
            objects[i] = new MusCompClass(*music);
        else{
            PopyriClass* popyri = (PopyriClass*) music;
            objects[i] = new PopyriClass(*popyri);
        }
    }
}

Array::~Array(){
    delete [] objects;
}

void Array::pushBack(MusCompClass* newObj) {
    addOnePlace();
    if (newObj->get_class() == "MusCompClass")
        objects[size] = new MusCompClass(*newObj);
    else{
        PopyriClass* popyri = (PopyriClass*) newObj;
        objects[size] = new PopyriClass(*popyri);
    }
    size++;
}

void Array::insert(MusCompClass* newObj, int num) {
    if (size == 0 && num == 0)
        this-> pushBack(newObj);
    else {
        MusCompClass** newArr = new MusCompClass*[size+1];
        for (int i = 0; i < size; i++) {
            MusCompClass *music = this->getObject(i);
            if (music->get_class() == "MusCompClass")
                newArr[i] = new MusCompClass(*music);
            else{
                PopyriClass* popyri = (PopyriClass*) music;
                newArr[i] = new PopyriClass(*popyri);
            }
        }
        delete[] objects;
        objects = newArr;
        int i;
        objects[size] = objects[size - 1];
        for (i = size - 1; i >= num; i--) {
            MusCompClass *music = this->getObject(i);
            if (music->get_class() == "MusCompClass")
                objects[i + 1] = new MusCompClass(*music);
            else{
                PopyriClass* popyri = (PopyriClass*) music;
                objects[i + 1] = new PopyriClass(*popyri);
            }
        }
        if (newObj->get_class() == "MusCompClass")
            objects[i + 1] = new MusCompClass(*newObj);
        else{
            PopyriClass* popyri = (PopyriClass*) newObj;
            objects[i + 1] = new PopyriClass(*popyri);
        }
        size++;
    }
}

void Array::del(){
    MusCompClass** newArr = new MusCompClass*[size-1];
    for (int i = 0; i < size - 1; i++){
        MusCompClass *music = this->getObject(i);
        if (music->get_class() == "MusCompClass")
            newArr[i] = new MusCompClass(*music);
        else{
            PopyriClass* popyri = (PopyriClass*) music;
            newArr[i] = new PopyriClass(*popyri);
        }
    }
    delete [] objects;
    size--;
    objects = newArr;
}

void Array::del(int num){
    if (num < 0 || num > size) {
        cout << "Error. Object with num " << num << " don't exist!" << endl;
        return;
    }

    MusCompClass **newArr = new MusCompClass*[size-1];
    int i;

    for(i=0; i < num; i++){
        MusCompClass *music = this->getObject(i);
        if (music->get_class() == "MusCompClass")
            newArr[i] = new MusCompClass(*music);
        else{
            PopyriClass* popyri = (PopyriClass*) music;
            newArr[i] = new PopyriClass(*popyri);
        }
    }

    for(i = i + 1; i < size; i++){
        MusCompClass *music = this->getObject(i);
        if (music->get_class() == "MusCompClass")
            newArr[i-1] = new MusCompClass(*music);
        else{
            PopyriClass* popyri = (PopyriClass*) music;
            newArr[i-1] = new PopyriClass(*popyri);
        }
    }

    delete [] objects;
    size--;
    objects = newArr;
}

void Array::delAll() {
    delete [] objects;
    objects = NULL;
    size = 0;
}

void Array::addOnePlace(){
    MusCompClass **newArr = new MusCompClass*[size+1];
    for (int i = 0; i < size; i++){
        MusCompClass *music = this->getObject(i);
        if (music->get_class() == "MusCompClass")
            newArr[i] = new MusCompClass(*music);
        else{
            PopyriClass* popyri = (PopyriClass*) music;
            newArr[i] = new PopyriClass(*popyri);
        }
    }
    delete [] objects;
    objects = newArr;
}

const int Array::getSize() const {
    return size;
}

MusCompClass* Array::getObject(int num) const{
    if(num < 0 || num >= size) {
        throw out_of_range("index out of range");
    }
    return objects[num];
}

MusCompClass* Array::getLastObject() const {
    return objects[size-1];
}

Array Array::sortLimit(double minFMood, double maxFMood, double minSMood, double maxSMood){
    if (minFMood < 0){
        cout << "Min first mood can't be less then 0. It changed on 0" << endl;
        minFMood = 0.0;
    }
    if (minSMood < 0){
        cout << "Min second mood can't be less then 0. It changed on 0" << endl;
        minSMood = 0.0;
    }
    if (maxFMood > 10){
        cout << "Max first mood can't be more then 10. It changed on 10" << endl;
        maxFMood = 10.0;
    }
    if (maxSMood > 10){
        cout << "Max second mood can't be more then 10. It changed on 10" << endl;
        maxSMood = 10.0;
    }

    Array middleArr, resultArr;
    mood middleMood, lastMood;
    int minNum = 0;
    double minD = 15, D;
    int newSizeArr;

    for(int i = 0; i < size; i++){
        middleMood = this->getObject(i)->getMood();
        if (middleMood.first >= minFMood && middleMood.first <= maxFMood &&
            middleMood.second >= minSMood && middleMood.second <= maxSMood){
            MusCompClass *music = this->getObject(i);
            if(music->get_class() == "MusCompClass"){
                middleArr.pushBack(music);
            }else{
                PopyriClass* popyri = (PopyriClass*) music;
                middleArr.pushBack(popyri);
            }
        }
    }

    if(middleArr.getSize() == 0)
        return resultArr;


    newSizeArr = middleArr.getSize();
    if(resultArr.getSize() == 0){
        for(int i = 0; i < newSizeArr; i++){
            middleMood = middleArr.getObject(i)->getMood();
            D = sqrt((0 - middleMood.first)*(0 - middleMood.first) + (0 - middleMood.second)*(0 - middleMood.second));
            if (D < minD) {
                minD = D;
                minNum = i;
            }
        }
        MusCompClass *music = middleArr.getObject(minNum);
        if(music->get_class() == "MusCompClass"){
            resultArr.pushBack(music);
        }else{
            PopyriClass* popyri = (PopyriClass*) music;
            resultArr.pushBack(popyri);
        }
        middleArr.del(minNum);
    }

    while (middleArr.getSize() != 0){
        minD = 15;
        minNum = 0;
        lastMood = resultArr.getLastObject()->getMood();
        newSizeArr = middleArr.getSize();
        for(int i = 0; i < newSizeArr; i++){
            middleMood = middleArr.getObject(i)->getMood();
            D = sqrt((lastMood.first - middleMood.first)*(lastMood.first - middleMood.first) + (lastMood.second - middleMood.second)*(lastMood.second - middleMood.second));
            if (D < minD) {
                minD = D;
                minNum = i;
            }
        }
        MusCompClass *music = middleArr.getObject(minNum);
        if(music->get_class() == "MusCompClass"){
            resultArr.pushBack(music);
        }else{
            PopyriClass* popyri = (PopyriClass*) music;
            resultArr.pushBack(popyri);
        }
        middleArr.del(minNum);
    }
    return resultArr;
}

void Array::fromFile(const string& nameFile){

    string author, name, fMoodS, sMoodS, typeClass, startMoodS, finishMoodS;
    double fMood, sMood, finishMood, startMood;

    ifstream file(nameFile);

    if (!file) {
        cout << "File not found" << endl;
    } else {
        if (size != 0)
            this->delAll();
        while(!file.eof()){
            getline(file, typeClass);
            if (typeClass == "MusComp"){
                getline(file, author);
                getline(file, name);
                getline(file, fMoodS);
                getline(file, sMoodS);
                stringstream promF(fMoodS), promS(sMoodS);
                promF >> fMood;
                promS >> sMood;
                MusCompClass* obj = new MusCompClass(name, author, {fMood, sMood});
                this->pushBack(obj);
            }
            else if (typeClass == "Popyri"){
                getline(file, author);
                getline(file, name);
                getline(file, fMoodS);
                getline(file, sMoodS);
                getline(file, startMoodS);
                getline(file, finishMoodS);
                stringstream promF(fMoodS), promS(sMoodS), promStart(startMoodS), promFinish(finishMoodS);
                promF >> fMood;
                promS >> sMood;
                promFinish >> finishMood;
                promStart >> startMood;
                PopyriClass*obj = new PopyriClass(name, author, {fMood, sMood}, {startMood, finishMood});
                this->pushBack(obj);
            }
        };
        file.close();
    }
}

void Array::toFile(const string& nameFile){
    ofstream file(nameFile);
    for(int i = 0; i < size-1; i++){
        MusCompClass *obj = this->getObject(i);
        if(obj->get_class() == "MusCompClass")
            file << "MusComp" << endl << obj->getAuthor() << endl << obj->getName() << endl << obj->getMood().first << endl <<  obj->getMood().second << endl;
        else{
            PopyriClass* objP = (PopyriClass*) obj;
            file << "Popyri" << endl << objP->getAuthor() << endl << objP->getName() << endl << objP->getMood().first << endl <<  objP->getMood().second << endl
                 << objP->getPopyriMood().startMood << endl << objP->getPopyriMood().finishMood << endl;
        }
    }
    MusCompClass *obj = this->getObject(size-1);
    if(obj->get_class() == "MusCompClass")
        file << "MusComp" << endl << obj->getAuthor() << endl << obj->getName() << endl << obj->getMood().first << endl <<  obj->getMood().second;
    else{
        PopyriClass* objP = (PopyriClass*) obj;
        file << "Popyri" << endl << objP->getAuthor() << endl << objP->getName() << endl << objP->getMood().first << endl <<  objP->getMood().second << endl
             << objP->getPopyriMood().startMood << endl << objP->getPopyriMood().finishMood;
    }

    file.close();
}

const bool Array::comparison(const Array& secondArray) const{
    int secondSize = secondArray.getSize();

    if(secondSize != size)
        return false;

    for(int i = 0; i < size; i++){
        if (objects[i]->get_class() == secondArray.getObject(i)->get_class()){
            if (objects[i]->get_class() == "MusCompClass"){
                if (!objects[i]->equalObj(secondArray.getObject(i)))
                    return false;
            }else{
                PopyriClass* obj1 = (PopyriClass*) objects[i];
                PopyriClass* obj2 = (PopyriClass*) secondArray.getObject(i);
                if (!obj1->equalPObj(obj2))
                    return false;
            }
        }else
            return false;
    }
    return true;
}

void Array::copyArray(const Array& fromArray){
    this->delAll();
    int sizeArr = fromArray.getSize();
    for(int i = 0; i < sizeArr; i++) {
        MusCompClass *music = fromArray.getObject(i);
        if (music->get_class() == "MusCompClass")
            this->pushBack(music);
        else{
            PopyriClass* popyri = (PopyriClass*) music;
            this->pushBack(popyri);
        }
    }
}

void printAllArray(const Array& arr){
    int size = arr.getSize();
    for(int i = 0; i < size; i++){
        MusCompClass *music = arr.getObject(i);
        if (music->get_class() == "MusCompClass"){
            cout << "Element MusComp#" << i + 1 << endl;
            cout << music->getAuthor() << endl << music->getName() << endl;
            cout << music->getMood().first << endl <<  music->getMood().second << endl << endl;
        }
        else{
            PopyriClass* popyri = (PopyriClass*) music;
            cout << "Element Popyri#" << i + 1 << endl;
            cout << popyri->getAuthor() << endl << popyri->getName() << endl;
            cout << popyri->getMood().first << endl <<  popyri->getMood().second << endl;
            cout << popyri->getPopyriMood().startMood << endl << popyri->getPopyriMood().finishMood << endl;
        }
    }
}
