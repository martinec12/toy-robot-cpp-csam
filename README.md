```
title: Toy Robot Code Challenge
author: Martin Louis C. Condes
```

# Toy Robot Code Challenge

This project contains a solution to the toy robot coding challenge using C++ language.

  

## Brief description

This is a simulation of a toy robot moving on a square table top.

Here are the default specifications or constraints:

* The table size is 5x5 units.

* There are no obstructions on the table surface.

* The robot can understand specific commands for its movement.

* The robot is free to roam around the table but should not fall outside the table.

* Any movement resulting to outside the table should be prevented, but further movement commands must still be entertained.

* All commands before the first valid *PLACE* command are ignored.

## Assumptions

1. The south-western corner of the table is at **(0,0)**
2. The coordinates can only be non-negative
3. Input commands can be given either via the standard input or via a file


## Valid Commands

1. Place - to deploy or place the robot anywhere on the table that is unoccupied

* Syntax: <strong>PLACE X,Y,F</strong>, where *X* and *Y* are coordinates and *F* is direction

* The origin point <strong>(0,0)</strong> is the South-west-most point of the table.

* The valid directions are *NORTH*, *EAST*, *SOUTH*, and *WEST*

* This should be the first command. Other commands before the first instance of place is ignored. Place can be issued multiple times.

2. Move - to move 1 unit towards the current direction

* Syntax: <strong>MOVE</strong>

* Ignored when no prior Place command is issued.

3. Right - to change direction towards the right or clockwise

* Syntax: <strong>RIGHT</strong>

* Ignored when no prior Place command is issued.

4. Left - to change direction towards the left or counter clockwise

* Syntax: <strong>LEFT</strong>

* Ignored when no prior Place command is issued.

5. Report - prints the current location on the table and current direction the robot is facing

* Syntax: <strong>REPORT</strong>

* Ignored when no prior Place command is issued.

  

## Project directory structure

```

```

project

│ README.md

│

└───<strong>build</strong> (go here to execute make command)

│ │ Makefile

└───<strong>obj</strong> (where object files are created)

│

└───<strong>src</strong> (location of toy robot source code)

│

└───<strong>test</strong> (location of test source code)

│

└───<strong>third_party</strong> (location of gtest source code and libraries for easy building of test source code)

  

```

```

## How to build and execute the toy robot program (Linux)

1. Go to the <strong>build</strong> directory and perform the following:

* make clean

* make toyrobot-exe

* ./toyrobot-exe

* or ./toyrobot-exe \<input  file  with  commands\>

2. The console will wait for user input or read the file if it is supplied. If entering from the console, see [Valid Commands](#valid-commands)


## How to build and execute the test

1. Go to the <strong>build</strong> directory and perform the following:

* make clean

* make testtoyrobot

* ./testtoyrobot

2. This executes all the tests written inside the **test** directory

3. The test is written with the help of *googletest* framework. For ease of building, the *googletest* folder is saved in the <strong>third_party</strong> directory.
