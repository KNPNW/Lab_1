#ifndef L1_ARRAY_H
#define L1_ARRAY_H
#include "MusCompClass.h"

class Array {
public:
    Array();
    Array(const Array& oldArray);
    ~Array();

    void add(const MusCompClass& newObj);
    void insert(const MusCompClass& newObj, int num);
    void del();
    void del(int num);
    void delAll();

    const int getSize() const;
    MusCompClass &getObject(int num) const;
    MusCompClass &getLastObject() const;
    Array sortLimit(double minFMood, double maxFMood, double minSMood, double maxSMood);
    void fromFile(const string& nameFile);
private:
    MusCompClass *objects;
    int size;
    void addOnePlace();
};



#endif //L1_ARRAY_H
