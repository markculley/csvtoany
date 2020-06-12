#include <iostream>
#include <stdexcept>

#include "argparse.hpp"
#include "CsvEngine.h"
#include "ConvertableJson.h"


int main(int argc, const char* argv[])
{
    ArgumentParser parser;

    // Define required args
    parser.addArgument("-f", "--csvfile", 1, false);
    parser.addArgument("-o", "--outfile", 1, false);
    // Define optional args
    parser.addArgument("--json", false);

    // TODO: Make json an optional arg and add additional output options

    try
    {
        parser.parse(argc, argv);
    }
    catch (const std::exception& err)
    {
        std::cout << err.what() << std::endl;
        std::cout << parser.usage();
        exit(0);
    }

    std::string csvFile = parser.retrieve<std::string>("csvfile");
    std::string outFile = parser.retrieve<std::string>("outfile");

    CsvEngine engine;

    ConvertableJson json;
    json.Initialize(outFile);

    if (!engine.Convert(csvFile, json)) {
        std::cout << "Failed to create" << outFile << "properly" << std::endl;
    }
    else {
        std::cout << outFile << " was created" << std::endl;
    }
    json.Close();


    std::cout << "exit" << "\n";
}

