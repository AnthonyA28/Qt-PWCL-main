
#define i_autoMode     0 //  for input & output
#define i_setPoint     1 //  for input & output
#define i_percentOn    2 //  for input & output
#define i_kc           3 //  for input & output
#define i_tauI         4 //  for input & output
#define i_tauD         5 //  for input & output
#define i_tauF         6 //  for input & output
#define i_fanSpeed     7 //  for input & output
#define i_filterAll    8 //  for input & output
#define i_positionForm 9 //  for input & output
#define i_pOnNominal   10 //  for input & output
#define i_temperature  11 //  for input & output
#define i_tempFiltered 12 //  for input & output
#define i_time         13 //  for input & output
#define numVars 13

class COM
{
private:
    float arr[numVars];
public:

    char buffer[400];
    const int bufferSize = 400; //FIXME TODO: this is not good
    COM(){}
    void printCurrentValues();
    bool prepare_output();
    bool fillStr(float value, char* output, unsigned int* i, unsigned short max);
    bool deserialize_array ();
    float get(int index);
    void set(int index, float value);
};

