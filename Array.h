#ifndef L1_ARRAY_H
#define L1_ARRAY_H
#include "MusCompClass.h"

class Array {
public:
    Array();
    Array(const MusCompClass& obj);
    Array(const Array& oldArray);
    ~Array();

    void pushBack(const MusCompClass& newObj);
    void insert(const MusCompClass& newObj, int num);
    void del();
    void del(int num);
    void delAll();
    void copyArray(const Array& fromArray);

    const int getSize() const;
    MusCompClass &getObject(int num) const;
    MusCompClass &getLastObject() const;
    Array sortLimit(double minFMood, double maxFMood, double minSMood, double maxSMood);
    void fromFile(const string& nameFile);
    void toFile(const string& nameFile);
    const bool comparison(const Array& secondArray) const;
private:
    MusCompClass *objects;
    int size;
    void addOnePlace();
};

void printAllArray(const Array& arr);


#endif //L1_ARRAY_H
