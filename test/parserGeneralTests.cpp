#include <gtest/gtest.h>
#include "Parser.hpp"
#include "Robot.hpp"
#include "Table.hpp"
#include "Command.hpp"
#include <memory>
#include <string>
#include <sstream>

TEST(ParserGeneralTests, EmptyCommandString)
{
    Robot r;
    Table t;
    std::string commandString = "";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, InvalidCommandString1)
{
    Robot r;
    Table t;
    std::string commandString = "abcd";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, InvalidCommandString2)
{
    Robot r;
    Table t;
    std::string commandString = "1234 ABCD !?";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidMoveCommand)
{
    Robot r;
    Table t;
    std::string commandString = "MOVE";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidRightCommand)
{
    Robot r;
    Table t;
    std::string commandString = "RIGHT";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidLeftCommand)
{
    Robot r;
    Table t;
    std::string commandString = "LEFT";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidReportCommand)
{
    Robot r;
    Table t;
    std::string commandString = "REPORT";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidNonPlaceCommandSpaces)
{
    Robot r;
    Table t;
    std::string commandString = "  REPORT  ";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidNonPlaceCommandCase)
{
    Robot r;
    Table t;
    std::string commandString = "moVe";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, InvalidNonPlaceCommandRepeating)
{
    Robot r;
    Table t;
    std::string commandString = "RIGHT RIGHT";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, InvalidOtherCommand)
{
    Robot r;
    Table t;
    std::string commandString = "BATTLE!";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}
