#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "InputCheck.h"
using namespace std;

void InputCheck::checkInput(char &inVar, char reqIn1, char reqIn2, char reqIn3, char reqIn4){
  //If input is not valid, give 3 attempts to enter valid input.
  if(inVar != reqIn1 && inVar != reqIn2 && inVar != reqIn3 && inVar != reqIn4){
    for(count = 3; count > 0; count--){
      cout << "Invalid entry. Try again(" << count << " attempts remaining): ";
      cin >> inVar;

      //If input is valid within 3 attempts, break the loop.
      if(inVar == reqIn1 || inVar == reqIn2 || inVar == reqIn3 || inVar == reqIn4){
        break;
      }
    }

    //If all 3 attempts are exhausted, exit the program.
    if(count == 0){
      cout << "All 3 attempts exhausted. Exiting program....." << endl;
      exit(1);
    }
  }
}
