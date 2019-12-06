/******shared between C++/Arduino code */
#define i_mode         0
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
#define i_x1           14 
#define i_x2           15 
#define i_x3           16
#define i_x4           17
#define i_x5           18 
#define i_x6           19
#define i_x7           20
#define i_x8           21
#define i_x9           22
#define i_x10          23 

#define PRECISION 4
#define ERR         0.000001
#define PRECF "%.4f"
#define BUFFERSIZE 500
#define NUMPARAMS 24

#pragma once
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
// Compile for Arduino
#define PRINT_SOURCE Serial.print("(A) ")
#define PRINT(msg) Serial.print(msg)
#define PRINT_FLOAT(val) Serial.print(val, PRECISION)
#define PRINT_INT(val) Serial.print(val)
#else
// Compile for C++
#include <math.h> // for NAN
#include <string>
#include <iostream>
#define PRINT_SOURCE std::cout << "(C) "
#define PRINT(msg) std::cout << msg
#define PRINT_FLOAT(val) printf(PRECF, val)
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

/***
*   Set the value represented by 'index' to 'value'
*   updates the arrQueu[index] flag so the new value is sent to the port
*   if 'value' and arrVals[index] are the same (within the ERR #defined) 
*   the arrQueu[index] will not be updated
*/
void set(int index, float value)
{
    if ( fabs(value) - fabs(arrVals[index]) > ERR) {
        arrVals[index] = value;
        arrQueu[index] = true; 
    }
}


/***
*   Set the values represented by 'index' to 'value'
*   Then send the value to the port regardless of whether it has been changed 
*/  
void setAndSend(int index, float value) {
    arrVals[index] = value;
    arrQueu[index] = true; 
}


/***
*   Retun the value from the port represented by 'index'
*/
float get(int index)
{
    return arrVals[index];
}


/***
*   Send only the updated values to the port 
*/
void sendUpdatedValues()
{
    PRINT("[");
    for (int i = 0; i < NUMPARAMS; i ++ ) {
        if (arrQueu[i]) {
            PRINT_INT(i);
            PRINT(">");
            PRINT_FLOAT(arrVals[i]);
            PRINT(",");
            arrQueu[i] = false; 
        }
    }
    PRINT("]\n");
}


/***
*   Show the current values in arrvals (those from the port) 
*/
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
*  parses 'input' (which should be in an arrValsay format) for the parameters in the prespecified order
*  Ex:
*      if input = [23.89, 324]
*      then
*        arrVals[0] => 23.89
*        arrVals[1] => 324
*      then you could do..
*        COM.get(0);
*      which returns 23.89
*/
bool deserialize_array(char* paramStr)
{
  if( *paramStr == '\n' || *paramStr == '\0' ){return false;}
    /* Ensure that the input string has the correct format and number of numbers to be parsed*/
    const char*  p = paramStr;
    unsigned int numB   = 0;   // number of brackets
    unsigned int numV   = 0;   // number of values
//
//     PRINT("recieved");
//     PRINT(paramStr);
//     PRINT("()\n");

    while (*p) {
      if (*p == '[') { numB++;
      } else if ( *p == ']' ) {numB++;
      } else if ( *p == ',' ) {numV++;
      } p++;
    }
//    if (numB != 2) {
//        PRINT_SOURCE;
//        PRINT("Parse error: Invalid Message: \n");
//        PRINT(paramStr);
//        PRINT("\n");
//        return false;
//    }

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
            recieve(index, x); // todo: this should just use set()
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
