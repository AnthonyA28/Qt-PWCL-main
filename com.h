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
#define NUMVARS 14
#define BUFFERSIZE 400

class COM
{
private:
    float arr[NUMVARS];
public:

    char buffer[BUFFERSIZE];
    COM(){}
    void printCurrentValues();
    bool prepare_output();
    bool fillStr(float value, char* output, unsigned int* i, unsigned short max);
    bool deserialize_array ();
    float get(int index);
    void set(int index, float value);
};
