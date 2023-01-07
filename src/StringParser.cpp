#include "Parser.hpp"
#include <memory>
#include <string>
#include <sstream>

StringParser::StringParser(std::string inputString)
{
    mInputStream = std::make_unique<std::stringstream>(inputString);
}
