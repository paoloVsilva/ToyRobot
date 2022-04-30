# TOY ROBOT
Toy Robot exam from Iress

This is a 5x5 board where you can put the robot location
by using the <PLACE {X},{Y},{DIRECTION}> command

```
|-----------------------------|
|    *    *    *    *    *    |
|    *    *    *    *    *    |
|    *    *    *    *    *    |
|    *    *    *    *    *    |
|    *    *    *    *    *    |
|-----------------------------|
```

## COMMANDS
### <PLACE>
 - Place the robot to a certain position

### <MOVE>
 - Move the robot one step to the direction he is facing

### <LEFT>
 - The robot faces to his left without changing it current position.

### <RIGHT>
 - The robot faces to his right without changing it current position.

### <REPORT>
 - Outputs the current position of the robot together with its facing direction

## DIRECTIONS
- NORTH
- EAST
- SOUTH
- WEST

## RULES
 - Robot cannot go outside the 5x5 board

## Usage
 - Run the "build/main" for Linux(This was tested in Ubuntu 18.04 LTS distro)
 - Run the "build/main.exe" for Windows(This was tested in Windows 10)

## Future Improvements
 - Add a turn around command.
 - Make the code into more object oriented approach.
 - Include unit and integration pipelines and testing
 - Build in Mac OS, and other Linux Distro
