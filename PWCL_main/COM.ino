
void VARIABLES::printStream(char* errMsg)
{
    // std::cout <<  errMsg;
    Serial.print(errMsg);
}
void VARIABLES::printStream(float value)
{
    // std::cout <<  value;
    Serial.print(value);
}

void VARIABLES::set(int index, float value)
{
  arr[index] = value;
}

float VARIABLES::get(int index)
{
  return arr[index];
}

void VARIABLES::printCurrentValues()
{
  for (int i = 0; i < numVars; i ++ ) {
    this->printStream("\t");
    this->printStream(arr[i]);
  }
}

/***
  Fills the 'output' char* with a string version of 'value'. at the specified 'bufIndex'
*/
bool VARIABLES::fillStr(float value, char* output, unsigned int* i, unsigned short max)
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

bool VARIABLES::prepare_output()
{
    unsigned int bufIndex = 1;
    bool success = true;
    buffer[0] = '[';
    for ( int i = 0; i < numVars && success; i ++ ) {
      success = this->fillStr(this->arr[i], buffer, &bufIndex, bufferSize);
    }
    if (success && bufIndex < bufferSize - 2) {
        buffer[bufIndex] = ']';
        buffer[bufIndex+1] = '\0';
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
        VARIABLES.get(0);
      which returns 23.89
*/
bool VARIABLES::deserialize_array ()
{
    const char* const input = this->buffer;
    /* Ensure that the input string has the correct format and number of numbers to be parsed*/
    const char*  p = input;
    unsigned int numB   = 0;   // number of brackets
    unsigned int numV   = 0;   // number of values

    while (*p) {
      if (*p == '[') { numB++;
      } else if ( *p == ']' ) {numB++;
      } else if ( *p == ',' ) {numV++;
      } p++;
    }
    if (numB != 2) {
        this->printStream("(C++) Parse error, not valid array\n");
        return false;
    }
    if (numV != numVars) {
        this->printStream("(C++) Parse error, input size incorrect\n");
        return false;
    }

   char* pEnd;
   p = input + 1;
   for ( unsigned int i = 0; i < numVars; i ++ ) {
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
   p = input;
}
