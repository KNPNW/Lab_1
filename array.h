#ifndef ARRAY_H
#define ARRAY_H
#include "muscompclass.h"


class Array {
public:
    Array();
    Array(MusCompClass* obj);
    Array(const Array& oldArray);
    ~Array();

    void pushBack(MusCompClass* newObj);
    void insert(MusCompClass* newObj, int num);
    void del();
    void del(int num);
    void delAll();
    void copyArray(const Array& fromArray);

    const int getSize() const;
    MusCompClass* getObject(int num) const;
    MusCompClass* getLastObject() const;
    Array sortLimit(double minFMood, double maxFMood, double minSMood, double maxSMood);
    void fromFile(const string &nameFile);
    void toFile(const string& nameFile);
    const bool comparison(const Array& secondArray) const;
private:
    MusCompClass **objects;
    int size;
    void addOnePlace();
};

void printAllArray(const Array& arr);

void printAllArray(const Array& arr);
#endif // ARRAY_H
