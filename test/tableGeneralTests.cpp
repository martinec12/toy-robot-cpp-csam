#include <gtest/gtest.h>
#include "Table.hpp"
#include "Point.hpp"
#include "Constants.hpp"
#include <cstddef>


TEST(TableGeneralTests, TableDefaultSize)
{
    Table t;
    EXPECT_EQ(t.getTableLength(), static_cast<std::size_t>(5));
    EXPECT_EQ(t.getTableWidth(), static_cast<std::size_t>(5));
}

TEST(TableGeneralTests, TableSpecificSize)
{
    std::size_t length = 4;
    std::size_t width = 3;
    Table t(length, width);
    EXPECT_EQ(t.getTableLength(), length);
    EXPECT_EQ(t.getTableWidth(), width);
}

TEST(TableGeneralTests, TablePointWithinBounds)
{
    Table t;
    Point p(3, 1);
    EXPECT_TRUE(t.isPointWithinTableBounds(p));
}

TEST(TableGeneralTests, TablePointOutOfBounds)
{
    Table t;
    Point p(5, 6);
    EXPECT_FALSE(t.isPointWithinTableBounds(p));
}

TEST(TableGeneralTests, TableOccupySlotVacantSlot)
{
    Table t;
    Point p(1, 1);
    EXPECT_EQ(t.occupySlot(p), OperationStatus::SUCCESS);
}

TEST(TableGeneralTests, TableOccupySlotAlreadyOccupied)
{
    Table t;
    Point p(1, 1);
    t.occupySlot(p);
    EXPECT_EQ(t.occupySlot(p), OperationStatus::ERROR);
}

TEST(TableGeneralTests, TableOccupySlotOutOfBounds)
{
    Table t;
    Point p(6, 5);
    EXPECT_EQ(t.occupySlot(p), OperationStatus::ERROR);
}

TEST(TableGeneralTests, TableReleaseSlotOccupiedSlot)
{
    Table t;
    Point p(1, 1);
    t.occupySlot(p);
    EXPECT_EQ(t.releaseSlot(p), OperationStatus::SUCCESS);
}

TEST(TableGeneralTests, TableReleaseSlotAlreadyVacant)
{
    Table t;
    Point p(1, 1);
    EXPECT_EQ(t.releaseSlot(p), OperationStatus::ERROR);
}

TEST(TableGeneralTests, TableReleaseSlotOutOfBounds)
{
    Table t;
    Point p(5, 6);
    EXPECT_EQ(t.releaseSlot(p), OperationStatus::ERROR);
}

TEST(TableGeneralTests, TableCheckOccupiedWhenOccupied)
{
    Table t;
    Point p(1, 1);
    t.occupySlot(p);
    EXPECT_TRUE(t.isTableOccupied());
}

TEST(TableGeneralTests, TableCheckOccupiedWhenVacant)
{
    Table t;
    Point p(1, 1);
    t.occupySlot(p);
    t.releaseSlot(p);
    EXPECT_FALSE(t.isTableOccupied());
}
