#include <string>
#include <vector>
#include <iostream>
#include "ConvertableJson.h"
#include "nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;


bool ConvertableJson::Initialize(std::string outFile)  {

    if (_outFile.is_open()){
        _outFile.close();
    }

    if (!_jsonDocument.empty()){
        _jsonDocument.clear();
    }

    try {
        _outFile.open(outFile);
    }
    catch (std::exception ex) {
        std::cout << ex..message();
    }
    return _outFile.good();
}

void ConvertableJson::Close() {

    if (_outFile.is_open()) {
        _outFile << _jsonDocument;
        _outFile.close();
    }
}

bool ConvertableJson::WriteLine(const std::vector<std::string> lineOfCsv) {

    if (lineOfCsv.empty() || !_outFile.is_open() || _outFile.bad()) {
        return false;
    }

    // Create a json object with name 'record' that contains, as an array,
    // the contains of lineOfCsv
    json jLine;
    jLine["record"] = json(lineOfCsv);
    _jsonDocument.push_back(jLine);
    return true;
}