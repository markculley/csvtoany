# csvtoany
Reads a csv file and exports it as a JSON. 

## Setup
csvtoany depends on two externals libraries:

1. JSON for Modern C++
git clone https://github.com/nlohmann/json.git to a folder named json that is a peer of csvtoany

2. ArgumentParser. Not as good as https://github.com/p-ranav/argparse. but p-ranav demands C++17 support that
I don't have in JetBrains CLion. Supposedly NetBeans supports C++17 but it is terrible on Centos7. VS2017 supports C++17 just fine 
but this project is not about VS2017 and Windows.

git clone https://github.com/hbristow/argparse.git

So your folder structure should look like...

~/csvtoany
~/argparse
~/json

# Build
The project was built with CMake. I used CLion. CLion is pretty good. Not bad anyway.

# Extensibility
The design is simple.  Given a csv file as an input, convert it to a json file. Convertable.h declares an abstract class with 
three functions:

    // Create your files, buffers, whatever
    bool virtual Initialize(std::string outFile) = 0;

    // It is expected that any open streams will not
    // be closed until this is called
    void virtual Close() = 0;

    // Write a line of CSV in whatever format you choose
    bool virtual WriteLine(const std::vector<std::string> lineOfCsv) = 0;


The class ConvertableJson inherits from Convertable.
CsvEngine is used by Main to execute the conversion.  CsvEngine has one relevant function:

    //
    // Given 'csvFile', writes to a Convertable object by calling on
    // it SerializeToFile() function.
    //
    bool Convert(std::string csvFile, Convertable &output);

So, as you can see, to extend this tool to export in a different format, simply create a new class that subclasses Convertable and implement WriteLine appropriately.
