#include <iostream>
#include <string>
#include "helpers.h"

#define MAX_VALID_COMMAND 5
#define MAX_VALID_DIRECTION 4
#define MAX_VALID_COORDINATES 5
#define COORDINATES_CT 2

using namespace std;

const string _validCommand[MAX_VALID_COMMAND] = {"PLACE", "MOVE", "LEFT", "RIGHT", "REPORT"};
const string _validDirection[MAX_VALID_DIRECTION] = {"NORTH", "EAST", "SOUTH", "WEST"};
unsigned char _currentPosition[COORDINATES_CT];
bool isStartPtAssigned = false;
unsigned char _currentDirection;


/* ------------------------------------------ */
/* check if pattern for place is correct      */
/* ------------------------------------------ */
bool isValidPlace(string input){
  input = trim(input);
  if(input.length() < 14 || input.length() > 15){
    return false;
  }
  // PLACE
  if(input.substr(0, 5) != _validCommand[0]){
    return false;
  }
  // {space}
  if(input.at(5) != ' ') {
    return false;
  }
  // {x coordinate}
  if(input.at(6) < '0' || input.at(6) > '5') {
    return false;
  }
  // {comma}
  if(input.at(7) != ',') {
    return false;
  }
  // {y coordinate}
  if(input.at(8) < '0' || input.at(8) > '5') {
    return false;
  }
  // {comma}
  if(input.at(9) != ',') {
    return false;
  }
  // {DIRECTION}
  if(!checkIfValid(input.substr(10, 5), _validDirection, MAX_VALID_DIRECTION)){
    return false;
  }
  return true;
}

/* ------------------------------------------- */
/* execute place command, coordinates+direction*/
/* ------------------------------------------- */
void placeCommand(string input){
  _currentDirection = (unsigned char) indexOfString(input.substr(10, 5), _validDirection, MAX_VALID_DIRECTION);
  _currentPosition[0] = (unsigned char) (input.at(6) - '0');
  _currentPosition[1] = (unsigned char) (input.at(8) - '0');
}

/* ------------------------------------------------ */
/* execute move command, move the robot forward     */
/* ------------------------------------------------ */
void moveCommand(){
  unsigned char coordinate = (_currentDirection & 0x01) ^ 0x01;
  unsigned char operation = _currentDirection & 0x02;


  if(operation){
    if(_currentPosition[coordinate] > 0){
      _currentPosition[coordinate]--;
    }
  } else {
    if(_currentPosition[coordinate] < MAX_VALID_COORDINATES){
      _currentPosition[coordinate]++;
    }
  }

}

/* ------------------------------------------------ */
/* execute left command, face ther robot to the left*/
/* ------------------------------------------------ */
void leftCommand(){
  _currentDirection--;
  if(_currentDirection >= MAX_VALID_DIRECTION){
    _currentDirection = MAX_VALID_DIRECTION - 1;
  }
}

/* ------------------------------------------------- */
/* execute left command, face ther robot to the right*/
/* ------------------------------------------------- */
void rightCommand(){
  _currentDirection++;
  if(_currentDirection == MAX_VALID_DIRECTION){
    _currentDirection = 0;
  }
}

/* ------------------------------------------------- */
/* execute report command, report current robot pos  */
/* ------------------------------------------------- */
void reportCommand(){
  cout << "Output: " ;
  cout << (int) _currentPosition[0];
  cout << ",";
  cout << (int) _currentPosition[1];
  cout << ",";
  cout << _validDirection[_currentDirection];
  cout << endl;
}

// execute commands by the user
void executeCommands(string input){
  
  // check if initial point is not yet assigned
  if(!isStartPtAssigned){
    if(isValidPlace(input)){
      isStartPtAssigned = true;
      placeCommand(input);
    } else {
      cout << "Invalid Input!" << endl;
    }
  } 
  // can do all of the commands if initial point is already set
  else {
    // check first if the commands is a place command
    if(isValidPlace(input)){
      placeCommand(input);
    }
    // else check if is it other valid command
    else {
      if(checkIfValid(input, _validCommand, MAX_VALID_COMMAND)){
        if( input == _validCommand[1]){
          moveCommand();
        } else if( input == _validCommand[2]){
          leftCommand();
        } else if( input == _validCommand[3]){
          rightCommand();
        } else if( input == _validCommand[4]){
          reportCommand();
        }
      } else {
        cout << "Invalid Input!" << endl;
      }
    }
  }
}


int main(){
  string input;
  cout <<  "----------------------" << endl;
  while(1){
    getline(cin, input);
    executeCommands(input);
  }
}
