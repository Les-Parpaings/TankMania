
#include "utils/utils.hpp"
#include <fstream>

namespace utils {

// ****************************************************************************
// READ FILE
// ****************************************************************************

bool charIsSeparator(char c, std::string separator)
{
    for (auto it : separator) {
        if (c == it) {
            return true;
        }
    }
    return false;
}

void readLine(std::string &buffer, std::vector<std::string> &content, std::string separator)
{
    size_t size = buffer.size();
    std::string data;

    // check if separtor is not defined
    if (separator == "")
        separator = ",";

    for (size_t i = 0; i <= size; i++) {
        if (i == size || charIsSeparator(buffer[i], separator)) {
            content.push_back(data);
            data.clear();
        } else {
            data.push_back(buffer[i]);
        }
    }
}

std::vector<std::string> readFile(std::string path)
{
    std::vector<std::string> content;
    std::string buffer;
    std::ifstream file;

    file.open(path);
    while (getline(file, buffer)) {
        content.push_back(buffer);
    }
    file.close();

    return content;
}

// ****************************************************************************
// GET INFO
// ****************************************************************************

std::streampos getFileLine(std::fstream &fs, size_t line)
{
    std::string buf;
    for (size_t i = 0; i < line; i++) {
        std::getline(fs, buf);
    }
    return fs.tellg();
}

std::streampos getFileLine(std::ifstream &fs, size_t line)
{
    std::string buf;
    for (size_t i = 0; i < line; i++) {
        std::getline(fs, buf);
    }
    return fs.tellg();
}

}
