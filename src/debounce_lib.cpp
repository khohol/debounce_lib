#include "debounce_lib.h"


// КОНСТРУКТОР
Debouncer::Debouncer() {
}


// СЕТТЕРИ
void Debouncer::setDebounce(uint16_t new_debounce) {    // задання часу ігнорування дріб'язку значень
    _debounce = new_debounce;
}

void Debouncer::setCooldown(uint16_t new_coldown) {     // задання часу "перезарядки"
    _cooldown = new_coldown;
}


// ОБРОБКА
bool Debouncer::tick() {        // викликати як можна частіше
    if (_last_value != _value) {
        _debounce_timer = millis();
        _debounce_flag = true;
    }

    if (_debounce_flag && millis() - _debounce_timer >= _debounce && millis() - _cooldown_timer >= _cooldown) {
        _debounce_flag = false;
        _cooldown_timer = millis();
        _isTrig_flag = true;
        _debounced_value = _value;
    }

    _last_value = _value;
    return true;
}


bool Debouncer::isTrig() {  // повертає true, якщо була зміна значення
    Debouncer::tick();
    if (_isTrig_flag) {
        _isTrig_flag = false;
        return true;
    } else return false;
}


bool Debouncer::setValue(int16_t input_value) {     // задаємо значення з певною частотою
    _value = input_value;
    return Debouncer::tick();
}


int16_t Debouncer::getValue() {     // отримання актуальних значень
    Debouncer::tick();
    if (_debounced_value == -1) {
        return _value;
    } else {
        return _debounced_value;
    }
}