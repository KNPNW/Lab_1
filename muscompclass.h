#ifndef MUSCOMPCLASS_H
#define MUSCOMPCLASS_H

#include <string>

using namespace std;

struct mood{
    double first;
    double second;
};

class MusCompClass{
public:
    MusCompClass() = default;
    MusCompClass(const string& newName, const string& newAuthor, const mood& newMood);
    MusCompClass(const MusCompClass& existMusic);
    virtual ~MusCompClass();

    [[nodiscard]] const string& getName()const;
    [[nodiscard]] const string& getAuthor()const;
    [[nodiscard]] const mood& getMood() const;

    virtual void printParams() const;
    void setName(const string& newName);
    void setAuthor(const string& newAuthor);
    void setMood(const mood& newMood);
    void setMood(const double& fMood, const double& sMood);
    bool equalObj(MusCompClass* secondObj);

    virtual string get_class() {return "MusCompClass";};
private:
    string musicName {"no name"};
    string musicAuthor {"no author"};
    mood musicMood{0.0, 0.0};
};


#endif // MUSCOMPCLASS_H
