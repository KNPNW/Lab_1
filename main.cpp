#include <iostream>
#include "Test.h"


using namespace std;

int main()
{
    testDefaultConstructorAndSets();
    testInitAndCopyConstructor();
    testArray();
    std::cout << "Успешно!" << std::endl;
    return 0;
}
