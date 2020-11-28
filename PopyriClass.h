#ifndef LAB1_POPYRICLASS_H
#define LAB1_POPYRICLASS_H

#include "ParentClass.h"
#include <string>

using namespace std;

struct moodPopyri{
    double startMood;
    double finishMood;
};

class PopyriClass : public ParentClass{
public:
    PopyriClass() = default;
    PopyriClass(const string& newName, const moodPopyri& newMood);
    PopyriClass(const PopyriClass& existPopyri);
    virtual ~PopyriClass() {};

    [[nodiscard]] const string& getPopyriName()const;
    [[nodiscard]] const moodPopyri& getPopyriMood()const;

    void setPopyriName(const string& newName);
    void setPopyriMood(const moodPopyri& newMood);
    void setPopyriMood(const double& sMood, const double& fMood);

    virtual string get_class() override {return "PopyriClass";};
private:
    string popyriName {"no name"};
    moodPopyri popyriMood {0.0, 0.0};
};


#endif //LAB1_POPYRICLASS_H
