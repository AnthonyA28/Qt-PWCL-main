/******shared between C++/Arduino code */
#define i_autoMode     0
#define i_setPoint     1
#define i_percentOn    2
#define i_kc           3
#define i_tauI         4
#define i_tauD         5
#define i_tauF         6
#define i_fanSpeed     7
#define i_filterAll    8
#define i_positionForm 9
#define i_pOnNominal   10
#define i_temperature  11
#define i_tempFiltered 12
#define i_time         13
#define i_X1           14 
#define i_X2           15 
#define i_X3           16
#define i_X4           17
#define i_X5           18 
#define i_X6           19
#define i_X7           20
#define i_X8           21
#define i_X9           22
#define i_X10          23 
#define BUFFERSIZE 500
#define NUMPARAMS 24

#pragma once
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
// Compile for Arduino
#define PRINT_SOURCE Serial.print("(A) ")
#define PRINT(msg) Serial.print(msg)
#define PRINT_FLOAT(val) Serial.print(val, 8)
#define PRINT_INT(val) Serial.print(val)
#else
// Compile for C++
#include <math.h> // for NAN
#include <string>
#include <iostream>
#define PRINT_SOURCE std::cout << "(C) "
#define PRINT(msg) std::cout << msg
#define PRINT_FLOAT(val) printf("%.8f", val)
#define PRINT_INT(val) printf("%u", val)
#endif

class COM
{

public:

COM()
{
    this->arrVals = new float[NUMPARAMS];
    this->arrQueu = new bool[NUMPARAMS];
    // initialize the arrays
    for(int i = 0; i < NUMPARAMS; i ++ ) {
        this->arrQueu[i]=false;
        this->arrVals[i]=0.0;
    }
}

~COM()
{
    delete this->arrVals;
    delete this->arrQueu;
}

void set(int index, float value)
{
    arrVals[index] = value;
    arrQueu[index] = true; 
}

float get(int index)
{
    return arrVals[index];
}


void sendUpdatedValues()
{
    PRINT("[");
    for (int i = 0; i < NUMPARAMS; i ++ ) {
        if (arrQueu[i]) {
            PRINT_INT(i);
            PRINT(">");
            PRINT_FLOAT(arrVals[i]);
            PRINT(",");
        }
    }
    PRINT("]\n");
}


void showCurrentValues()
{
    PRINT("[");
    for (int i = 0; i < NUMPARAMS; i++) {
        PRINT_FLOAT(arrVals[i]);
        PRINT(", ");
    }
    PRINT("]\n");
}

/***
  parses 'input' (which should be in an arrValsay format) for the parameters in the prespecified order
  Ex:
      if input = [23.89, 324]
      then
        arrVals[0] => 23.89
        arrVals[1] => 324
      then you could do..
        COM.get(0);
      which returns 23.89
*/
bool deserialize_array(char* paramStr)
{
    /* Ensure that the input string has the correct format and number of numbers to be parsed*/
    const char*  p = paramStr;
    unsigned int numB   = 0;   // number of brackets
    unsigned int numV   = 0;   // number of values

    while (*p) {
      if (*p == '[') { numB++;
      } else if ( *p == ']' ) {numB++;
      } else if ( *p == ',' ) {numV++;
      } p++;
    }
    if (numB != 2) {
        PRINT_SOURCE;
        PRINT("Parse error: Invalid Message: \n");
        PRINT(paramStr);
        PRINT("\n");
        return false;
    }

    char* pEnd;
    p = paramStr;
    for ( unsigned int i = 0; i < NUMPARAMS; i ++ ) {
        short index = -1; 
        while(*p == '[' || *p == ' ') p ++ ;
        bool isNum = false;  // if the string is a number
        const char* nc = p; // nc will point to the next comma or the closing bracket
        /* Handle NANS */
        if ( (*p == 'N' && *(p+1) == 'A' && *(p+2) == 'N')
        || (*p == 'n' && *(p+1) == 'a' && *(p+2) == 'n') ) {
            this->arrVals[i] = NAN;
            while( *p != ',' && p ) p ++; p ++; // goto past next comma
            continue;
        }
        /* go to the first character that is not a ',' or stop if at end of string */
        while(*nc != ',' && *nc != ']' && *nc) {
            if ((int)*nc >= 48 && (int)*nc <= 57){
                isNum = true;
            }
            nc++;
        }
        if (isNum) {
            index = strtod(p, &pEnd);
            p = pEnd;
        }
        /* Check if the next character is an equal sign*/
        if (*p == '>') { 
            p++;
            float x = strtod(p, &pEnd);
            recieve(index, x);
            p = pEnd;
        }
        while (*p != ',' && *p != ']' && *p){
            p++;
        }
        p++;
    }
    p = paramStr;
    return true;
}

private:


void recieve(int index, float value) 
{
    if(index>=NUMPARAMS) {
        PRINT("ERROR: invalid value change");
        return;
    }
    arrVals[index] = value;   
}

unsigned short numVars = 0;
float* arrVals;
bool* arrQueu;
};
