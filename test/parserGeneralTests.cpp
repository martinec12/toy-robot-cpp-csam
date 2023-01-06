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
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, InvalidCommandString1)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "abcd";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, InvalidCommandString2)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "1234 ABCD !?";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidMoveCommand)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "MOVE";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidRightCommand)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "RIGHT";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidLeftCommand)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "LEFT";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidReportCommand)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "REPORT";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidNonPlaceCommandSpaces)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "  REPORT  ";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, ValidNonPlaceCommandCase)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "moVe";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_NE(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, InvalidNonPlaceCommandRepeating)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "RIGHT RIGHT";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserGeneralTests, InvalidOtherCommand)
{
    Robot r;
    Table t;
    int dummyArgs = 1;
    const char * dummyArgv[] = {"dummy.exe"};
    std::stringstream commandStringStream;
    Parser p(dummyArgs, dummyArgv, commandStringStream);

    std::string commandString = "BATTLE!";
    commandStringStream.str(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}
