#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "Point.hpp"
#include "Constants.hpp"
#include "Table.hpp"
#include <string>

class Robot
{
public:
    Robot();
    unsigned int getRobotId();
    OperationStatus place(Table &table, Point destination, Direction direction);
    OperationStatus move(Table &table);
    OperationStatus left();
    OperationStatus right();
    OperationStatus report();
    Point getRobotLocation();
    Direction getRobotDirection();
    
private:
    bool checkDestinationValidity(Table &table, Point &destination);
    OperationStatus computeDestinationXY(Point &destination);
    OperationStatus computeNewDirection(std::string rotation);
    void setRobotLocation(Point destination);
    void setRobotDirection(Direction newDirection);

    unsigned int mRobotId;
    bool mIsPlaced;
    Point mLocation;
    Direction mDirection;
};

#endif // _ROBOT_HPP_