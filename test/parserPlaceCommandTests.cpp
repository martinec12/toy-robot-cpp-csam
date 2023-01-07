#include <gtest/gtest.h>
#include "Parser.hpp"
#include "Robot.hpp"
#include "Table.hpp"
#include "Command.hpp"
#include "Constants.hpp"
#include <memory>
#include <string>
#include <sstream>
#include <cstddef>

TEST(ParserPlaceCommandTests, ValidPlaceCommandStandard)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE 0,1,NORTH";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getXCoordinate(), static_cast<std::size_t>(0));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getYCoordinate(), static_cast<std::size_t>(1));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployDirection(), Direction::NORTH);
}

TEST(ParserPlaceCommandTests, ValidPlaceCommandCaseVariation)
{
    Robot r;
    Table t;
    std::string commandString = "plAce 2,2,wESt";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getXCoordinate(), static_cast<std::size_t>(2));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getYCoordinate(), static_cast<std::size_t>(2));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployDirection(), Direction::WEST);
}

TEST(ParserPlaceCommandTests, ValidPlaceCommandLeadingSpaces)
{
    Robot r;
    Table t;
    std::string commandString = "      PLACE 4,2,NORTH";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getXCoordinate(), static_cast<std::size_t>(4));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getYCoordinate(), static_cast<std::size_t>(2));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployDirection(), Direction::NORTH);
}

TEST(ParserPlaceCommandTests, ValidPlaceCommandTrailingSpaces)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE 0,0,SOUTH     ";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getXCoordinate(), static_cast<std::size_t>(0));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getYCoordinate(), static_cast<std::size_t>(0));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployDirection(), Direction::SOUTH);
}

TEST(ParserPlaceCommandTests, ValidPlaceCommandInbetweenSpaces)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE      1,1,EAST";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getXCoordinate(), static_cast<std::size_t>(1));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployPosition().getYCoordinate(), static_cast<std::size_t>(1));
    EXPECT_EQ(dynamic_cast<PlaceCommand*>(cmdPtr.get())->getDeployDirection(), Direction::EAST);
}

TEST(ParserPlaceCommandTests, InvalidPlaceSyntax1)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserPlaceCommandTests, InvalidPlaceSyntax2)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE PLACE";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserPlaceCommandTests, InvalidPlaceSyntax3)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE 0,1,NORTH,SOUTH";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserPlaceCommandTests, InvalidXPlaceParameter)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE word,1,NORTH";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserPlaceCommandTests, InvalidYPlaceParameter)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE 0,Word,NORTH";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserPlaceCommandTests, InvalidDirectionPlaceParameter1)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE 0,1,OTHERWORD";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}

TEST(ParserPlaceCommandTests, InvalidDirectionPlaceParameter2)
{
    Robot r;
    Table t;
    std::string commandString = "PLACE 0,1,25";
    StringParser p(commandString);
    p.readInputCommandString();
    std::unique_ptr<ICommand> cmdPtr = p.convertInputStringToCommand(r, t);
    EXPECT_EQ(nullptr, cmdPtr.get());
}
