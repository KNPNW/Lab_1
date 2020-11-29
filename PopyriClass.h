#ifndef LAB1_POPYRICLASS_H
#define LAB1_POPYRICLASS_H

#include "MusCompClass.h"
#include <string>

using namespace std;

struct moodPopyri{
    double startMood;
    double finishMood;
};

class PopyriClass : public MusCompClass{
public:
    PopyriClass() = default;
    PopyriClass(const string& newName, const string& newAuthor, const mood& newMood, const moodPopyri& newPMood);
    PopyriClass(const PopyriClass& existPopyri);
    virtual ~PopyriClass() {};

    const moodPopyri& getPopyriMood()const;

    virtual void printParams() const;
    void setPopyriMood(const moodPopyri& newMood);
    void setPopyriMood(const double& sMood, const double& fMood);
    bool equalPObj(PopyriClass* secondObj);

    virtual string get_class() {return "PopyriClass";};
private:
    moodPopyri popyriMood {0.0, 0.0};
};


#endif //LAB1_POPYRICLASS_H
