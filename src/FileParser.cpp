#include "Parser.hpp"
#include <memory>
#include <fstream>

FileParser::FileParser(const char * fileName)
{
    mInputStream = std::make_unique<std::ifstream>(fileName);
}

FileParser::~FileParser()
{
    static_cast<std::ifstream*>(mInputStream.get())->close();
}
