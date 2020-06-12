#ifndef CSVTOANY_CSVENGINE_H
#define CSVTOANY_CSVENGINE_H

#include <string>
#include "Convertable.h"


class CsvEngine
{
public:
    //
    // Given 'csvFile', writes to a Convertable object by calling on
    // it SerializeToFile() function.
    //
    bool Convert(std::string csvFile, Convertable &output);

private:
    void ReadLine(std::ifstream &inStream, std::vector<std::string> &outLine);
};


#endif //CSVTOANY_CSVENGINE_H
