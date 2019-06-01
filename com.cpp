#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
// this is being compiled for an aruino
#define PRINT_SOURCE Serial.print("(A) ")
#define PRINT_MESSAGE( msg ) Serial.print(msg)
#else
// This is being compile for C++
#include "com.h"
#include <string>
#include <cstring>
#include <iostream>
#define PRINT_SOURCE std::cout << "(C++) ";
#define PRINT_MESSAGE( msg ) std::cout << msg
#endif



void COM::set(int index, float value)
{
  arr[index] = value;
}

float COM::get(int index)
{
  return arr[index];
}

void COM::printCurrentValues()
{
  for (int i = 0; i < NUMVARS; i ++ ) {
    PRINT_SOURCE;
    PRINT_MESSAGE("\t");
    PRINT_MESSAGE(arr[i]);
  }
}

/***
  Fills the 'output' char* with a string version of 'value'. at the specified 'bufIndex'
*/
bool COM::fillStr(float value, char* output, unsigned int* i, unsigned short max)
{
  int whole = value;
  unsigned int decimals = ((value - (float)whole)) * 10000; // TODO: FIXME keep getting some kind of overflow if the precision is larger #p3

  char tmp[15];

  sprintf(tmp, "%d.%d,", whole, decimals); // (val, minimum width, precision , tmp)
  int tmpSize = strlen(tmp);


  /* TODO: The premature null termination can be done in prepare output #p2 */
  if (*i >= max-tmpSize-1 || *i >= max-4) {
      const char * null  = "\0";
      memcpy(& output[*i], null, 1);
      return false;
  }

  if (value != value) {
    output[*i]   = 'N';
    output[*i+1] = 'A';
    output[*i+2] = 'N';
    output[*i+3] = ',';
    *i +=4;
    return true;
  }
  /* space is available so write tmp to output */
  memcpy(&output[*i], tmp, tmpSize);
  *i += tmpSize;
  return true;
}

bool COM::prepare_output()
{
    unsigned int bufIndex = 1;
    bool success = true;
    this->buffer[0] = '[';
    for ( int i = 0; i < NUMVARS && success; i ++ ) {
      success = this->fillStr(this->arr[i], this->buffer, &bufIndex, BUFFERSIZE);
    }
    if (success && bufIndex < BUFFERSIZE - 2) {
        this->buffer[bufIndex] = ']';
        this->buffer[bufIndex+1] = '\0';
    }
    return success;
}


/***
  parses 'input' (which should be in an array format) for the parameters in the prespecified order
  Ex:
      if input = [23.89, 324]
      then
        arr[0] => 23.89
        arr[1] => 324
      then you could do..
        COM.get(0);
      which returns 23.89
*/
bool COM::deserialize_array ()
{

    /* Ensure that the input string has the correct format and number of numbers to be parsed*/
    const char*  p = this->buffer;
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
        PRINT_MESSAGE("Parse error, not valid array.. Message: \n");
        PRINT_MESSAGE(this->buffer);
        PRINT_MESSAGE("\n");
        return false;
    }
    if (numV != NUMVARS) {
        PRINT_SOURCE;
        PRINT_MESSAGE("Parse error, incorrect array size.. Message: \n");
        PRINT_MESSAGE(this->buffer);
        PRINT_MESSAGE("\n");
        return false;
    }

   char* pEnd;
   p = this->buffer + 1;
   for ( unsigned int i = 0; i < NUMVARS; i ++ ) {
      bool isNum = false;  // if the string is a number
      const char* nc = p; // nc will point to the next comma or the closing bracket
      /* Handle NANS */
       if ( (*p == 'N' && *(p+1) == 'A' && *(p+2) == 'N')
         || (*p == 'n' && *(p+1) == 'a' && *(p+2) == 'n') ) {
         this->arr[i] != this->arr[i];  // TODO: this probably wont work #p1
         // this->arr[i] = NAN;
         p++;
         continue;
       }
      while(*nc != ',' && *nc != ']' && *nc) {
        if ((int)*nc >= 48 && (int)*nc <= 57)
          isNum = true;
        nc++;
      }
      if (isNum) {
        this->arr[i] = strtod(p, &pEnd);
        p = pEnd;
      }
      while (*p != ',' && *p != ']' && *p) {
        p++;
      }
      p++;
   }
   p = this->buffer;
}
