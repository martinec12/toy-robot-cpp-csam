#include "Parser.hpp"
#include <memory>
#include <istream>

CommandLineParser::CommandLineParser()
{
    mInputStream = std::make_unique<std::istream>(std::cin.rdbuf());
}
