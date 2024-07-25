#ifndef debounce_lib_h
#define debounce_lib_h
#include <Arduino.h>

class debouncer {
    public:
        debouncer();
        void setDebounce(uint16_t new_debounce);
        void setColdown(uint16_t new_coldown);
        bool tick();
        
        bool setValue(int16_t input_value);
        int16_t getValue();
        bool isTrig();
        //bool isHolded();
    private:
        uint16_t _debounce  = 300;
        uint32_t _debounce_timer = 0;
        bool _debounce_flag = false;

        uint16_t _coldown   = 800;
        uint32_t _coldown_timer = 0;
        bool _coldown_flag = false;
        
        int16_t _value = -1;
        int16_t _debounced_value = _value;
        int16_t _last_value = _value; 

        bool _isTrig_flag = false;
};

#endif