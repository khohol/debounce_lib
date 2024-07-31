#ifndef debounce_lib_h
#define debounce_lib_h
#include <Arduino.h>

class Debouncer {
    public:
        Debouncer();
        void setDebounce(uint16_t new_debounce);    // задання часу ігнорування дріб'язку значень
        void setCooldown(uint16_t new_cooldown);    // задання часу "перезарядки"
        bool tick();                                // викликати як можна частіше
        
        bool setValue(int16_t input_value);         // задаємо значення з певною частотою
        int16_t getValue();                         // отримання актуальних значень
        bool isTrig();                              // повертає true, якщо була зміна значення
    private:
        uint16_t _debounce  = 300;
        uint32_t _debounce_timer = 0;
        bool _debounce_flag = false;

        uint16_t _cooldown   = 800;
        uint32_t _cooldown_timer = 0;
        bool _cooldown_flag = false;
        
        int16_t _value = -1;
        int16_t _debounced_value = _value;
        int16_t _last_value = _value; 

        bool _isTrig_flag = false;
};

#endif