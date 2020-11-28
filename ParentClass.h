#ifndef LAB1_PARENTCLASS_H
#define LAB1_PARENTCLASS_H

#include <string>

using namespace std;

class ParentClass {
public:
    ParentClass();
    virtual ~ParentClass();
    virtual string get_class(){ return "Parent"; };
};


#endif //LAB1_PARENTCLASS_H
