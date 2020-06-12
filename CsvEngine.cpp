#include "CsvEngine.h"
#include <string>
#include <sstream>


bool CsvEngine::Convert(std::string csvFile, Convertable &output)
{
    std::ifstream instream;
    instream.open(csvFile);
    if (instream.bad())
        return false;

    std::vector<std::string> line;

    // for each line in csfFile, return a tokenized vector
    while (!instream.eof()){
        ReadLine(instream, line);
        if (line.size() > 0)
            output.WriteLine(line);
    };
}

//
// Reads a line of csv into a vector
// Upgrade: Use an iterator to tokenize the stream. 1, possible two fewer copies
void CsvEngine::ReadLine(std::ifstream &inStream, std::vector<std::string> &outLine)
{
    outLine.clear();

    if (inStream.eof() || inStream.bad())
        return;

    // Read a line. 1st copy
    std::string line;
    std::getline(inStream, line);
    if (line.empty()) {
        return;
    }

    // create a stringstream from the line. 2nd copy
    std::string word;
    std::stringstream ss(line);

    // tokenize the string into a vector. 3rd copy
    while (std::getline(ss, word, ',')) {
        if (word.empty()){
            break;
        }

        // copy the word to a vector.  4th copy!
        outLine.emplace_back(word);
    }
}