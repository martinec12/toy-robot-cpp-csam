#include <gtest/gtest.h>
#include "Table.hpp"
#include "Robot.hpp"
#include "Point.hpp"
#include "Constants.hpp"
#include <cstddef>

TEST(RobotGeneralTests, RobotExecuteValidPlaceCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 2;
    std::size_t yTest = 1;
    Point p(xTest, yTest);
    Direction d = Direction::NORTH;
    EXPECT_EQ(r.place(t, p, d), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::NORTH);
}

TEST(RobotGeneralTests, RobotExecuteOutOfBoundsPlaceCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 7;
    std::size_t yTest = 6;
    Point p(xTest, yTest);
    Direction d = Direction::NORTH;
    EXPECT_EQ(r.place(t, p, d), OperationStatus::ERROR);
}

TEST(RobotGeneralTests, RobotExecuteMultiplePlaceCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 2;
    std::size_t yTest = 1;
    Point p1(xTest, yTest);
    Direction d1 = Direction::NORTH;
    EXPECT_EQ(r.place(t, p1, d1), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::NORTH);

    xTest = 3;
    yTest = 4;
    Point p2(xTest, yTest);
    Direction d2 = Direction::SOUTH;
    EXPECT_EQ(r.place(t, p2, d2), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::SOUTH);
}

TEST(RobotGeneralTests, RobotExecuteAlreadyOccupiedPlaceCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 2;
    std::size_t yTest = 1;
    Point p(xTest, yTest);
    Direction d = Direction::NORTH;
    t.occupySlot(p);
    EXPECT_EQ(r.place(t, p, d), OperationStatus::ERROR);
}

TEST(RobotGeneralTests, RobotExecuteValidNorthwardMoveCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 1;
    std::size_t yTest = 1;
    Point p(xTest, yTest);
    Direction d = Direction::NORTH;
    r.place(t, p, d);
    EXPECT_EQ(r.move(t), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest + 1);
    EXPECT_EQ(r.getRobotDirection(), Direction::NORTH);
}

TEST(RobotGeneralTests, RobotExecuteValidEastwardMoveCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 1;
    std::size_t yTest = 1;
    Point p(xTest, yTest);
    Direction d = Direction::EAST;
    r.place(t, p, d);
    EXPECT_EQ(r.move(t), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest + 1);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::EAST);
}

TEST(RobotGeneralTests, RobotExecuteValidSouthwardMoveCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 1;
    std::size_t yTest = 1;
    Point p(xTest, yTest);
    Direction d = Direction::SOUTH;
    r.place(t, p, d);
    EXPECT_EQ(r.move(t), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest - 1);
    EXPECT_GE(r.getRobotLocation().getYCoordinate(), static_cast<std::size_t>(0));
    EXPECT_EQ(r.getRobotDirection(), Direction::SOUTH);
}

TEST(RobotGeneralTests, RobotExecuteValidWestwardMoveCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 1;
    std::size_t yTest = 1;
    Point p(xTest, yTest);
    Direction d = Direction::WEST;
    r.place(t, p, d);
    EXPECT_EQ(r.move(t), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest - 1);
    EXPECT_GE(r.getRobotLocation().getXCoordinate(), static_cast<std::size_t>(0));
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::WEST);
}

TEST(RobotGeneralTests, RobotExecuteToOutOfBoundsNorthwardMoveCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 5;
    std::size_t yTest = 5;
    Point p(xTest, yTest);
    Direction d = Direction::NORTH;
    r.place(t, p, d);
    EXPECT_EQ(r.move(t), OperationStatus::ERROR);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::NORTH);
}

TEST(RobotGeneralTests, RobotExecuteToOutOfBoundsEastwardMoveCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 5;
    std::size_t yTest = 5;
    Point p(xTest, yTest);
    Direction d = Direction::EAST;
    r.place(t, p, d);
    EXPECT_EQ(r.move(t), OperationStatus::ERROR);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::EAST);
}

TEST(RobotGeneralTests, RobotExecuteToOutOfBoundsSouthwardMoveCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 0;
    std::size_t yTest = 0;
    Point p(xTest, yTest);
    Direction d = Direction::SOUTH;
    r.place(t, p, d);
    EXPECT_EQ(r.move(t), OperationStatus::ERROR);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::SOUTH);
}

TEST(RobotGeneralTests, RobotExecuteToOutOfBoundsWestwardMoveCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 0;
    std::size_t yTest = 0;
    Point p(xTest, yTest);
    Direction d = Direction::WEST;
    r.place(t, p, d);
    EXPECT_EQ(r.move(t), OperationStatus::ERROR);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::WEST);
}

TEST(RobotGeneralTests, RobotExecuteLeftCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 0;
    std::size_t yTest = 0;
    Point p(xTest, yTest);
    Direction d = Direction::NORTH;
    r.place(t, p, d);
    EXPECT_EQ(r.left(), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::WEST);

    EXPECT_EQ(r.left(), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::SOUTH);

    r.left();
    r.left();
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::NORTH);
}

TEST(RobotGeneralTests, RobotExecuteRightCommand)
{
    Table t;
    Robot r;
    std::size_t xTest = 1;
    std::size_t yTest = 0;
    Point p(xTest, yTest);
    Direction d = Direction::WEST;
    r.place(t, p, d);
    EXPECT_EQ(r.right(), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::NORTH);

    EXPECT_EQ(r.right(), OperationStatus::SUCCESS);
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::EAST);

    r.right();
    r.right();
    r.right();
    EXPECT_EQ(r.getRobotLocation().getXCoordinate(), xTest);
    EXPECT_EQ(r.getRobotLocation().getYCoordinate(), yTest);
    EXPECT_EQ(r.getRobotDirection(), Direction::NORTH);
}

TEST(RobotGeneralTests, RobotExecuteReportCommand)
{
    Table t;
    Robot r;
    Point p(1, 0);
    Direction d = Direction::WEST;
    r.place(t, p, d);
    EXPECT_EQ(r.report(), OperationStatus::SUCCESS);
}

TEST(RobotGeneralTests, RobotExecuteNotPlacedMoveCommand)
{
    Table t;
    Robot r;
    EXPECT_EQ(r.move(t), OperationStatus::ERROR);
}

TEST(RobotGeneralTests, RobotExecuteNotPlacedLeftCommand)
{
    Robot r;
    EXPECT_EQ(r.left(), OperationStatus::ERROR);
}

TEST(RobotGeneralTests, RobotExecuteNotPlacedRightCommand)
{
    Robot r;
    EXPECT_EQ(r.right(), OperationStatus::ERROR);
}

TEST(RobotGeneralTests, RobotExecuteNotPlacedReportCommand)
{
    Robot r;
    EXPECT_EQ(r.report(), OperationStatus::ERROR);
}
