#include "debounce_lib.h"


// КОНСТРУКТОР
debouncer::debouncer() {
}


// СЕТТЕРИ
void debouncer::setDebounce(uint16_t new_debounce) {
    _debounce = new_debounce;
}

void debouncer::setColdown(uint16_t new_coldown) {
    _coldown = new_coldown;
}


// ОБРОБКА
bool debouncer::tick() {
    if (_last_value != _value) {
        _debounce_timer = millis();
        _debounce_flag = true;
    }

    if (_debounce_flag && millis() - _debounce_timer >= _debounce && millis() - _coldown_timer >= _coldown) {
        _debounce_flag = false;
        _coldown_timer = millis();
        _isTrig_flag = true;
        _debounced_value = _value;
    }

    _last_value = _value;
    return true;
}


bool debouncer::isTrig() {
    debouncer::tick();
    if (_isTrig_flag) {
        _isTrig_flag = false;
        return true;
    } else return false;
}


bool debouncer::setValue(int16_t input_value) {
    input_value = _value;
    return debouncer::tick();
}


int16_t debouncer::getValue() {
    debouncer::tick();
    if (_debounced_value == -1) {
        return _value;
    } else return _debounced_value;
}
