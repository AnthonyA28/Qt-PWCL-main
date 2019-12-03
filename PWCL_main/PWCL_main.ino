
//  DEDICATION
//  To the memory of Dr. Leonard (Lenny) Bernstein, an inspiring chemical engineer,
//  climate scientist, and novelist, who provided tremendous guidance and resources
//  to improve the educational experience of our students.

//  OVERVIEW
/*  PERSONAL PORTABLE WET PROCESS CONTROL LAB
 *
 *  Using the Arduino UNO microcontroller attached via the USB port to a laptop,
 *  this software and associated hardware controls the temperature of a water-filled
 *  cylindrical container with thin walls of high thermal conductivity (e.g., an
 *  aluminum can) by low frequency pulse width modulation (PWM) of a 125W beverage
 *  heater (immersion coil).  This is done by turning on or off a relay.  For safety,
 *  either a completely enclosed electromagnetic relay or an enclosed and
 *  finger-protected solid state relay should be used.  In addition, two 5V fans
 *  powered from the Arduino (peak draw current 180 mA each) are used to increase the
 *  maximum cooling rate, the fraction of time the heater is on at safe temperatures,
 *  and to provide disturbances. The fan velocity can be changed by using
 *  Arduino-provided low frequency PWM of a logic level MOSFET which controls both
 *  fans.  The temperature is measured using a DS18B20 waterproof sensor.
 *
 *  Authored by Spyros A Svoronos, Department of Chemical Engineering, University of
 *  Florida, Dec 2016 - Oct 2017
 *  Adapted to new desktop application by Anthony Arrowood
 *  Web site: https://faculty.eng.ufl.edu/spyros-svoronos/lab/
 */


// SYSTEM COMPONENTS AND ASSOCIATED CODE
/* 1. Temperature Probe
 *    A DS18B20 probe (http://www.best-microcontroller-projects.com/ds18b20.html
 *    and http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)
 *    in waterproof housing was selected due to the combination of good
 *    performance in the target temperature range and low cost.  It is digital and
 *    outputs to a single UNO digital input/output pin (pin 2 is used).  It has
 *    resolution 9 to 12 bits and requires about 750 ms to complete a reading at the
 *    highest resolution.  It is supported by the OneWire library originally developed
 *    by Jim Studt.  The library can be downloaded from http://bildr.org/2011/07/ds18b20-arduino/
 *    by clicking the download button located on the upper left side of the code window.
 *    The above referenced bildr.org site simplified code from the official Arduino site,
 *    and I have slightly modified this code and incorporated it in the present program.
 *    The DS18B20 can operate in normal mode or in parasitic mode where it powers up
 *    from the communication wire.  I have used the normal mode and powered the probe
 *    from the UNO 5V pin (the current drawn is only up to 1.5 mA).
 *
 * 2. Immersion Heater and Relay
 *    Safety concerns put an upper limit to the temperature at which the experiments
 *    should run (I am not using a set-point above 50 C in a classroom setting).
 *    In addition, evaporative losses become significant at higher temperatures.
 *    Thus the target range of heater operation is 25-50 degrees C.  Given the low
 *    temperatures, a minimal power heater is desired.  The lowest power AC
 *    heater I could locate was the 125W Lewis N' Clark immersion heater.
 *    To manipulate its heating output, a 0-5V input relay is controlled by the
 *    UNO using low frequency (this program currently uses 4 Hz) pulse width
 *    modulation (PWM).  Although the lowest PWM frequency of an UNO PWM pin (31 Hz)
 *    could be used for solid state relays, PWM is implemented by manual coding of
 *    digital pin 5 to enable usage of electromagnetic relays which cannot handle
 *    31 Hz.  Safety considerations prohibit replacing the relay by a MOSFET as this
 *    would require passing outlet AC current through the breadboard.
 *    The safest type of relay to use is a totally enclosed relay that provides
 *    a normally open outlet for plugging in the heater.  I have used in my research
 *    for a long time the Powerswitch Tail II and I highly recommend it.  I also briefly
 *    tested the lower cost IoT relay and found it satisfactory. However, there is a small
 *    safety concern as it provides two normally closed outlets in addition to the two
 *    normally open outlets. I would ask students to tape over the normally closed
 *    outlets.  Both of these relays are electromagnetic and make loud switching sounds.
 *    As the experimental setup presented here requires significant inactive
 *    time for many experiments, it is intended for usage in a classroom where the
 *    instructor lectures while the experiment progresses.  For large classes,
 *    the switching sounds of the electromagnetic relays would be a major distraction.
 *    Solid state relays (SSRs) are silent, but there is no commercial unit that
 *    integrates a suitable SSR with an AC outlet.  I investigated several SSRs and
 *    concluded that a good option is to use the OMRON G3NA-210B (load 24-240VAC,
 *    input 5-24VDC), which is totally enclosed and has finger protection over the
 *    screw terminals to prevent user shocks.  Its cost is relative low, it has an
 *    LED that indicates when it is closed, and it does not require a heat sink for
 *    this application.  This relay must be coupled with a power cord (where the heater
 *    plugs in), and a polarized two-prong cord is recommended.  The hot wire must be
 *    separated, cut and stripped, and then connected to the relay screw terminal.
 *    Although this is a simple operation, to avoid any danger to the students, it is
 *    recommended that a professional or an experienced instructor connects the power
 *    cords to the SSRs.
 *
 * 3. Cooling Fans and Their Control
 *    To increase the maximum rate of cooling and the fraction of time the heater
 *    is on in the target temperature range of 25-50 degrees C, the water-filled
 *    container is sandwiched between two 5V cooling fans.  The fan speeds can be
 *    manipulated via PWM allowing them to be used as disturbance inputs.
 *    (It is also planned to modify the code to allow using fan speed as an
 *    alternative manipulated input for narrow temperature ranges).  As the
 *    current drawn by each fan is much higher than the 20 mA UNO PWM pins can
 *    safely provide, the speed of both fans is manipulated via PWM of a single logic
 *    level N-channel MOSFET.  A 10 kohm pull-down resistor is used to
 *    ensure proper MOSFET output at all times and two rectifier diodes have
 *    been added to protect the MOSFET from reverse voltages as explained in
 *    http://enricosimonetti.com/control-a-motor-speed-with-arduino/ and in
 *    http://bildr.org/2012/03/rfp30n06le-arduino/, which also provides an
 *    excellent beginners tutorial on using MOSFETS for motor control.
 *    In addition, a 220 ohm current-limiting resistor has been added to protect
 *    the UNO as suggested in http://www.oddwires.com/using-a-mosfet-to-control-a-dc-motor/
 *    and in
 *    http://fritzing.org/media/fritzing-repo/projects/m/mosfet-motor-example/images/MOSFET%20Motor.png.
 *
 *    The MOSFET gate is controlled by PWM using UNO digital pin 9.  To obtain
 *    optimal fan performance and reduce fan noise, the PWM frequency had to be lowered
 *    from the default 488 Hz to the lowest available, 31 Hz, using the code provided
 *    in http://playground.arduino.cc/Code/PwmFrequency?action=sourceblock&num=2
 *    Note that the above link warns that changes on pins 3, 5, 6, or 11 may cause
 *    the delay() and millis() functions to stop working.
 *
 *    To avoid needing more than two outlets (one for the laptop and one for the
 *    heater), it is desirable to power the UNO through a laptop USB port.  In this
 *    case the UNO is limited by the 500 mA maximum of USB 2 ports. The
 *    UNO draws about 100 mA ,and if we add what the relay and other components
 *    draw, we are left with about 370 mA.  Therefore the two fans must be powered
 *    from the UNO 5V pin and not draw more than 360 mA.
 *    I investigated all the 5V fans I could locate and found one model that
 *    perfectly fits the needs of this project, the Evercool EC8025M05CA.  This
 *    draws a peak current of 180 mA, and I measured the steady draw at 140 mA.
 *    No other 5V fan performed well without drawing 300 mA or more.
 *
 *
 * 5. Control Algorithm
 *    The default algorithm used is the velocity form of the PID control law modified
 *    so as to remove set-point derivative kick.  Low-pass filtering can be used for the
 *    derivative term (and is recommended).  Thus the derivative part replaces error
 *    by minus the (filtered) measurement.  The algorithm also incorporates bumpless
 *    transfer from manual to automatic and from automatic to manual, and implements
 *    the constraint: 0 <= percent time the heater is on <= 100.
 *    The user can replace the velocity form of PID by the position form by changing
 *    the value of positionFlag to 1.  The position form implements anti-reset windup
 *    using recommendations found in Brett Beauregard's PID library
 *    (http://playground.arduino.cc/Code/PIDLibrary)
 *
 * 6. Enclosure and Wiring
 *    The UNO and the breadboard are secured on a Sparkfun hoder and this is
 *    mounted inside a mailing box. In this manner, the wiring between UNO and
 *    breadboard is secure.
 */



// PRELIMINARIES
#include <OneWire.h> //library for DS18B20
#include <Time.h>
#include "com.h"
// Soft serial pins
#define rxPin 8 // connect to green wire of CP210 or to orange wire of FTDI
#define txPin 7 // connect to white wire of CP210 or to yellow wire of FTDI
// Relay pin
#define relayPin 5 //
// Logic level MOSFET pin
#define fetPin 9 // PWM pin 9 or 10 since we might change frequency and need millis()
// DS18S20 Signal pin on digital 2
#define DS18S20_Pin 2
byte pinState = 0;
// Temperature chip i/o
OneWire ds(DS18S20_Pin); // on digital pin 2
// The next statements declare other global variables
unsigned long relayPeriod = 250; // relay pwm period = 0.25 sec. Increase to 2.5 sec for EMR
unsigned long stepSize = 20 * relayPeriod; // sampling period, choose integer * relayPeriod
float Dt = stepSize/1000./60.; // converting stepSize to min
unsigned long probeTime = 800; // probe conversion time = 800 msec
float percentRelayOn = 0; // initial setting to 0 in case the heater is not immersed
float temperature = 25; // reasonable beginning temperatures
float temperaturePrev = temperature; // y(t-1)
float tempFiltPrevPrev = temperature; // yF(t-2)
float tempFiltPrev = temperature; // yF(t-1)
float tempFiltered = temperature; // yF(t)
float error = 0;
float errorPrev = error;
float percentRelayOnNominal = 10; // Nominal value used in the position form of PID, 15% for 40 C
float sumForIntegral = 0;
float TsetPoint = temperature; // deg C
bool noIntegralFlag = 0; // set to 1 for eliminating integral action
float Kc = 0.0; // controller gain (% power on / deg C)
float tauI = 3.0; // integral time constant in min
float KI; // if (proportionalFlag) {KI = 0} else {KI = Kc / tauI}
float tauD = 0.0; // derivative time constant in min
float tauF = 0; // filter time constant in min.  Rule of thumb: Choose it 0.1-0.2 * tauD
float fanSpeed = 255; // range 0 or 115 - 255, startup cannot be as low as when dynamically changing
float prev_val;
unsigned long tRelayStart;
unsigned long startConversionTime;
unsigned long tLoopStart;
bool stopTempHigh = 0; // flag ending the run due to high temperature
float Tmax = 60; // maximum safe temperature
bool filterAll = false; // If not set only the derivative term is filtered
bool positionFlag = false; // set to 1 for the position form of the PID law, to 0 for the velocity form

enum MODE {manual,automatic, custom}; //AA enumerate manual=0, automatic=1, custom=2
enum MODE mode;  
//AA Extra parameters for custom mode 
float x1;
float x2;
float x3;
float x4;
float x5;
float x6;
float x7;
float x8;
float x9;
float x10;

COM con; //AA a datastructure used to read and send parameters to the port (see com.h)

char buffer[BUFFERSIZE]; // a buffer used by COM to store data to and from the port 


/***AA
*   Checks the port for incoming data and reads incoming data into the buffer
*   If there is not message at the port, this returns immediately  
*/
void check_input()
{
  /*AA  
  IF there is data from the port, read UNTIL there is a null chracter, or a closing bracket. 
  This has the potential for locking up if no terminating charcter ']' or '\0' usu found so be careful. 
  Dont use delays in here, as that will cause long strings to be chopped up. 
  Dont use the serial.readString becuse it doesnt work properly (1% of time)   
    https://forum.arduino.cc/index.php?topic=185757.0
    "Serial data should be read as fast as it becomes available." (or faster) 
  */
  if (Serial.available()) {
    for (unsigned int bp = 0; bp < BUFFERSIZE - 2; bp ++) { //AA bp is a pointer to the buffer 
      char ch = Serial.read();
      if ( ch == -1){
        bp -=1; //AA subtract so that this cycle through the loop doesnt increment the pointer to the buffer 
        continue;
      }
      buffer[bp] = ch; //AA place this character in the input buffer   
      if ( ch == '[' && bp > 1) { //AA handle cases in which input looks like: [0>1,[0>1,>25.375,] by resetting the pointer i to the first character in the buffer      
        bp = 0; 
      }
      if (ch == ']' || ch == '\0' ) { //AA stop reading chracters if we have read the last bracket or a null charcter
        buffer[bp+1] = '\0'; //AA this will null terminate the buffer
        break;
      }
      if (ch == '!')
        shutdown();
    }
    while (Serial.available())
      char _ = Serial.read(); //AA this throws aways any extra characters in the port 
    con.deserialize_array(buffer);
  }
}

void setFanPwmFrequency(int pin, int divisor)
{
  // From http://playground.arduino.cc/Code/PwmFrequency?action=sourceblock&num=2
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

void relayCare(void)
{         // Continues relay looping
  unsigned long timeHere = millis();
  if (timeHere - tRelayStart <0) {tRelayStart = 0;} //for runs longer than 49 days
  if (timeHere - tRelayStart <= (1.-percentRelayOn/100.)*relayPeriod) {
    digitalWrite(relayPin, LOW);
  }
  else if (timeHere - tRelayStart < relayPeriod) {
    digitalWrite(relayPin, HIGH);
  }
  else{
    digitalWrite(relayPin, LOW);
    tRelayStart = timeHere;
  }
}

void shutdown()
{
  digitalWrite(relayPin, LOW); // turn heater off
  analogWrite(fetPin, 255); // turn fans on to max speed
  mode = manual;
  while (true)
  {
    //AA delay indefinately
    delay(1000);
  }
}

void setup(void)
{
  // define pin modes for tx, rx:
  Serial.begin(9600);
  delay(1000);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // start with relay off
  pinMode(fetPin, OUTPUT);
  setFanPwmFrequency(fetPin, 1024); // 64 = default divisor (use 64,128,256,1024)
  analogWrite(fetPin,(int) fanSpeed); // start fan
  tRelayStart = millis(); // time at beginning of relay period
}

void loop(void)
{
  // SAMPLING PROCESS STARTS - RELAY MUST CONTINUE CYCLING
  tLoopStart = millis(); // not the same as sampling interval start due to delay
  relayCare();
  // The following code calculates the temperature from one DS18B20 in deg Celsius
  // It is adapted from http://bildr.org/2011/07/ds18b20-arduino/
  byte data[12];
  byte addr[8];
  if ( !ds.search(addr)) { // no more sensors on chain, reset search
    ds.reset_search();
  }
  if ( OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println(F("CRC is not valid!"));
  }
  if (addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.println(F("Temperature probe malfunctioning!"));
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44); // start conversion, without parasite power on at the end


  startConversionTime = millis();
  while (millis() - startConversionTime < probeTime) {   //wait for probe to finish conversion
    relayCare();
  }

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read scratchpad

  relayCare();

  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }

  relayCare();

  ds.reset_search();
  byte MSB = data[1];
  byte LSB = data[0];
  float tempRead = ((MSB << 8) | LSB); // using two's compliment
  temperaturePrev = temperature;
  temperature = tempRead / 16;
  tempFiltPrevPrev = tempFiltPrev; // updating filtered measurements
  tempFiltPrev = tempFiltered;
  tempFiltered = Dt/ (Dt + tauF) * temperature + tauF/ (Dt + tauF) * tempFiltPrev;

  // SAMPING INTERVAL STARTS NOW THAT MEASUREMENT IS AVAILABLE

  relayCare();

  // AUTOMATIC CONTROL
  errorPrev = error;
  if (filterAll) {
    error = TsetPoint - tempFiltered;
  } else {
    error = TsetPoint - temperature;
  }
  
  if (mode == automatic) {
    if (!positionFlag) {
      float percentOnPrevious = percentRelayOn;
      float PropInt = percentOnPrevious + Kc * (error - errorPrev) + Dt * Kc * error / tauI;
      // Note:  To eliminate set-point kick (at the expense of slower responses to set-point changes) use:
      // float PropInt = percentOnPrevious + Kc *(-temperature + temperaturePrev) + Dt * Kc * error / tauI;
      float unconstrainedPercentRelayOn = PropInt + Kc * tauD/Dt * (-tempFiltered + 2. * tempFiltPrev - tempFiltPrevPrev);
      if (unconstrainedPercentRelayOn < 0.){
        percentRelayOn = 0.;
      }
      else
        if (unconstrainedPercentRelayOn > 100.) {
          percentRelayOn = 100.;
        }
      else {
        percentRelayOn = unconstrainedPercentRelayOn;
      }
    }
    else {
      if (noIntegralFlag) {
        KI = 0;
      } else {
        KI = Kc / tauI;
      }
      sumForIntegral += KI * error;
      float PropInt = percentRelayOnNominal + Kc * error + Dt * sumForIntegral;
      float unconstrainedPercentRelayOn = PropInt + Kc * tauD/Dt * (-tempFiltered + tempFiltPrev);
      if (unconstrainedPercentRelayOn < 0.) {
        float woInt = percentRelayOnNominal + Kc * error + Kc * tauD/Dt * (-tempFiltered + tempFiltPrev);
        sumForIntegral = (0 - woInt) /Dt; // anti reset windup
        percentRelayOn = 0.;
      }
      else if (unconstrainedPercentRelayOn > 100.) {
        float woInt = percentRelayOnNominal + Kc * error + Kc * tauD/Dt * (-tempFiltered + tempFiltPrev);
        sumForIntegral = (100 - woInt) /Dt; // anti reset windup
        percentRelayOn = 100.;
      } else {
        percentRelayOn = unconstrainedPercentRelayOn;
      }
    }
  }


  //AA CUSTOM CONTROL
  if (mode == custom) {
    /*
      Add custom tuning code here 
    */
  }


  relayCare();

  if (temperature > Tmax) {
    Serial.println("Shutting down due to overheat!");
    shutdown();
  }

  /*AA
   Place current values in the output array
   If you add parameters that must be sent to and fro the interface, ensure you call COM.setAndSend() with it.
   */
  con.setAndSend(i_mode, mode);
  if(mode == manual){ con.setAndSend(i_setPoint, temperature); }  //AA if its in manual mode it will sent the current temp in place of the setpoin)t
  else { con.setAndSend(i_setPoint, TsetPoint); }
  con.setAndSend(i_percentOn, percentRelayOn);
  con.setAndSend(i_kc, Kc);
  con.setAndSend(i_tauI, tauI);
  con.setAndSend(i_tauD, tauD);
  con.setAndSend(i_tauF, tauF);
  con.setAndSend(i_fanSpeed, fanSpeed);
  con.setAndSend(i_temperature, temperature);
  con.setAndSend(i_tempFiltered, tempFiltered);
  con.setAndSend(i_time, millis() /60000.0);
  con.setAndSend(i_filterAll, filterAll);
  con.setAndSend(i_positionForm, positionFlag);
  con.setAndSend(i_pOnNominal, percentRelayOnNominal);
  con.setAndSend(i_x1, x1);
  con.setAndSend(i_x2, x2);
  con.setAndSend(i_x3, x3);
  con.setAndSend(i_x4, x4);
  con.setAndSend(i_x5, x5);
  con.setAndSend(i_x6, x6);
  con.setAndSend(i_x7, x7);
  con.setAndSend(i_x8, x8);
  con.setAndSend(i_x9, x9);
  con.setAndSend(i_x10, x10);

  relayCare();

  //AA fill the ouput char buffer with the contents of the output array 
  con.sendUpdatedValues();
  while (millis() < tLoopStart + stepSize) {
    relayCare();
    check_input();
  }

  relayCare();

  /*AA
   Change any values that must be changed based off the input from the port. 
   If you add parameters that must be sent to and fro the interface, ensure you call COM.get() with it.
  */
  if ( mode == con.get(i_mode) && mode ==  automatic){  //AA not changing mode
    TsetPoint = con.get(i_setPoint);   //AA only set the set point when we are NOT changing the mode
  }
  else if ( mode == con.get(i_mode)  && mode != manual  ){   //AA not changing mode
    percentRelayOn = con.get(i_percentOn);    //AA only set the percent on when we are NOT chaning th mode
  }
  else if ( mode != con.get(i_mode) && mode != automatic) {   //AA transition  to automatic
    TsetPoint = temperature;
  }
  mode = (MODE)con.get(i_mode); //AA set the mode 

  //AA If in automatic mode, set the automatic parameters. 
  if (mode == automatic) {
    Kc                    = con.get(i_kc);
    tauI                  = con.get(i_tauI);
    tauD                  = con.get(i_tauD);
    tauF                  = con.get(i_tauF);
    filterAll             = con.get(i_filterAll);
    positionFlag          = con.get(i_positionForm);
    percentRelayOnNominal = con.get(i_pOnNominal);
  }
  //AA If in custom mode, set the custom parameters. 
  if (mode == custom) {
    x1  = con.get(i_x1);
    x2  = con.get(i_x2);
    x3  = con.get(i_x3);
    x4  = con.get(i_x4);
    x5  = con.get(i_x5);
    x6  = con.get(i_x6);
    x7  = con.get(i_x7);
    x8  = con.get(i_x8);
    x9  = con.get(i_x9);
    x10 = con.get(i_x10);
  }

  fanSpeed = con.get(i_fanSpeed);
  analogWrite(fetPin,(int) fanSpeed);

}
