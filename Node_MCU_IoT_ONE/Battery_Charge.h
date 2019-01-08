#include "Arduino.h"

class Battery{
    private:
        const static int  min_battery_vol;          // if input voltage is below this then it means no battery is connected.
        const static int threshold ;                // if input voltage is below this then charge the battery
        const static unsigned long charge_time;     // charge time in milliseconds
        const static float RatioFactor;
        unsigned long start_charge_time;            // to record time when charging started
        int voltage_check_pin;                      // battery voltage check pin                                    
        int charge_enable_pin;                      // enable charge pin
        int power_supply_check_pin;                 // to check power supply
        bool is_charging;                           // checking charging status
        float check_voltage();                      // returns voltage of battery on pin voltage_check_pin
        bool power_supply();                        // returns if power supply is present or not 
        bool battery_present();                     // returns if battery is presnt or not
        bool battery_discharged();                  // returns if battery is discharged or not
        void start_charging();                      // starts charging battery and notes time
        void stop_charging();                       // stops charging battery
    public:
        Battery(int Tvoltage_check_pin,int Tcharge_enable_pin,int Tpower_supply_check_pin);
        void charge_check();
};