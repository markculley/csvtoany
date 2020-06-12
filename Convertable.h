#ifndef CSVTOANY_CONVERTABLE_H
#define CSVTOANY_CONVERTABLE_H

#include <vector>
#include <string>
#include <fstream>


// An abstract class that defines an interface that CsvEngine supports
// file conversions for.  Subclass this object and implement its members
// to serialize csv files to your file type
class Convertable
{
public:

    // Create your files, buffers, whatever
    bool virtual Initialize(std::string outFile) = 0;

    // It is expected that any open streams will not
    // be closed until this is called
    void Close();

    // Write a line of CSV in whatever format you choose
    bool virtual WriteLine(const std::vector<std::string> lineOfCsv) = 0;

};
#endif //CSVTOANY_CONVERTABLE_H

