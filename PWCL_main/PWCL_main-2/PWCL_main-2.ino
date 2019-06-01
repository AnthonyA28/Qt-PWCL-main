#include <OneWire.h> //library for DS18B20
#include <Time.h>




/* TODO: Why dont you just make it a vector and initialize all the values the same in both the GUI and the arduino code? */
Why dont you just make it a vector and initialize all the values the same in both the GUI and the arduino code?



/****
    This class exists to transfer parameters from an arduino to  a receiving program such as a GUI program.
    It is designed such that the entire class can be the exact same code in both the receiving program and the arduino program.
*/

template <class T>
class VAR
{
    /*Will need to set updated to false after sending. */
public:

    bool set (T newValue)
    {
        this->current = newValue;
        return true; // should return false if the newValue is out of bounds
    }
    T getCurrent ()
    {
        return this->current;
    }
    T getLast ()
    {
        return this->last;
    }
    bool updated ()
    {
        return ( this->current != this->last );
    }
    bool fillStr(char* output, unsigned int* index, unsigned short max);

    VAR(T initialValue, unsigned short index)
    {
        this->index = index;
        this->current = initialValue;
    }

    unsigned short index;

private:
    /* Fills the str with the current value and changed len to the new length of the str */
    T current;  // The current value of the VAR
    T last;
};

template<>
bool VAR<float>::fillStr(char* output, unsigned int* index, unsigned short max)
{
    // Serial.println( "filling  float");
    // Serial.println( this->getCurrent());
    int whole = this->getCurrent();
    unsigned int decimals = ((this->getCurrent() - (float)whole)) * 10000; // TODO: FIXME keep getting some kind of overflow if the precision is larger #p3

    char tmp[15];
    const char * null  = "\0";

    if (this->updated())
        sprintf(tmp, "%d.%d,", whole, decimals); // (val, minimum width, precision , tmp)
    else
        sprintf(tmp, "," );
    int tmpSize = strlen(tmp);
    memcpy(&output[*index], tmp, tmpSize);
    *index += tmpSize;
    if (*index >= max-tmpSize-1){
        memcpy(& output[*index], null, 1);
        return false;
    }
    return true;
}

template<>
bool VAR<bool>::fillStr(char* output, unsigned int* index, unsigned short max)
{
    // Serial.println( "filling  boolean");
    char tmp[15];
    const char * null  = "\0";

    if (this->updated()){
        if (this->getCurrent() == true)
            sprintf(tmp, "T,");
        else
            sprintf(tmp, "F,");
    }

    else
        sprintf(tmp, "," );
    int tmpSize = strlen(tmp);
    memcpy(&output[*index], tmp, tmpSize);
    *index += tmpSize;
    if (*index >= max-tmpSize-1){
        memcpy(& output[*index], null, 1);
        return false;
    }
        return true;
}

class VARIABLES
{
public:

    /*
        Declare the variables to be transferred here
    */
    VAR<bool>  autoMode         = VAR<bool>(true, 0);
    VAR<float> setPoint         = VAR<float>(29, 1);
    VAR<float> kc               = VAR<float>(0, 2);
    VAR<float> tauI             = VAR<float>(0, 3);
    VAR<float> tauD             = VAR<float>(0, 4);
    VAR<float> tauF             = VAR<float>(0, 5);
    VAR<float> fanSPeed         = VAR<float>(0, 6);
    VAR<bool>  filterAll        = VAR<bool>(false, 7);
    VAR<bool>  positionForm     = VAR<bool>(false, 8);
    VAR<float> percentOnNominal = VAR<float>(0, 9);
    VAR<float> temperature      = VAR<float>(28.99, 10);
    VAR<float> tempFiltered     = VAR<float>(0, 11);
    VAR<float> time             = VAR<float>(0, 12);


    void printCurrentValues()
    {
        Serial.println( "Printing ");
        Serial.print( "\tautoMode: ");
        Serial.println( autoMode.getCurrent() );
        Serial.print("\tsetPoint: ");
        Serial.println(setPoint.getCurrent());
        Serial.print("\tkc: ");
        Serial.println(kc.getCurrent());
        Serial.print("\ttauI: ");
        Serial.println(tauI.getCurrent());
        Serial.print("\ttauD: ");
        Serial.println(tauD.getCurrent());
        Serial.print("\ttauF: ");
        Serial.println(tauF.getCurrent());
        Serial.print("\tfanSPeed: ");
        Serial.println(fanSPeed.getCurrent());
        Serial.print("\tfilterAll: ");
        Serial.println(filterAll.getCurrent());
        Serial.print("\tpositionForm: ");
        Serial.println(positionForm.getCurrent());
        Serial.print("\tpercentOnNominal: ");
        Serial.println(percentOnNominal.getCurrent());
        Serial.print("\ttemperature: ");
        Serial.println(temperature.getCurrent());
        Serial.print("\ttempFiltered: ");
        Serial.println(tempFiltered.getCurrent());
        Serial.print("\ttime: ");
        Serial.println(time.getCurrent());
    }


    bool prepare_output(char * output, int max)
    {
        unsigned int index = 1;
        bool success = false;
        output[0] = '[';
        success = temperature.fillStr(output, &index, max);
        success = autoMode.fillStr(output, &index, max);
        if (success && index < max - 2) {
            output[index] = ']';
            output[index+1] = '\0';
        }
        return success;
    }

};


const unsigned int bufferSize = 500;
char outputBuffer[bufferSize];
VARIABLES vars;

void setup()
{

    Serial.begin(9600);
    Serial.println("Testing");
    vars.printCurrentValues();
    vars.prepare_output(outputBuffer, bufferSize);
    Serial.println(outputBuffer);
    delay(1000);

}

void loop()
{
  // put your main code here, to run repeatedly:

}
