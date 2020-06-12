#ifndef CSVTOANY_CONVERTABLEJSON_H
#define CSVTOANY_CONVERTABLEJSON_H

#include <string>
#include <vector>
#include "Convertable.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

class ConvertableJson : public Convertable
{
public:
    //
    // Convertable.h interfaces support
    //

    bool Initialize(std::string outFile);
    void Close();

    // Converts a line of CSV into a JSON object with name "record"
    // and value the array equivalent of line of csv
    bool WriteLine(const std::vector<std::string> lineOfCsv);

private:
    std::ofstream _outFile;
    json _jsonDocument;
};


#endif //CSVTOANY_CONVERTABLEJSON_H
