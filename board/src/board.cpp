// Includes

#include <Arduino.h> // Serial, HardwareSerial, millis
#include <string.h>  // memset

// Defines

#define _DEKSTOP_SERIAL           Serial
#define _DESKTOP_BAUDRATE         115200
#define _DESKTOP_SEND_INTERVAL_MS 1000

#define _SHARED_DATA_LENGTH       2
#define _SHARED_DATA_BOARD_PART   1
#define _SHARED_DATA_DESKTOP_PART 0

// Propriedades

HardwareSerial *_desktop;
unsigned char _shared_data[_SHARED_DATA_LENGTH];
unsigned long _target_millis;

// Protótipos

void _desktop_init(HardwareSerial *serial);
void _desktop_recv_data(void);
void _desktop_send_data(void);

// Métodos públicos

void board_setup(void) {
    _DEKSTOP_SERIAL.begin(_DESKTOP_BAUDRATE);

    _desktop_init(&_DEKSTOP_SERIAL);
}

void board_loop(void) {
    _desktop_recv_data();
    _desktop_send_data();
}

// Métodos privados

void _desktop_init(HardwareSerial *serial) {
    _desktop = serial;
    memset(_shared_data, 0, _SHARED_DATA_LENGTH);
    _target_millis = 0;
}

void _desktop_recv_data(void) {
}

void _desktop_send_data(void) {
    unsigned long now = millis();
    if (now < _target_millis) {
        return;
    }
    _target_millis = now + _DESKTOP_SEND_INTERVAL_MS;

    while (!_desktop->availableForWrite())
        ;
    _desktop->write(_shared_data, _SHARED_DATA_LENGTH);
    while (!_desktop->availableForWrite())
        ;

    _shared_data[_SHARED_DATA_BOARD_PART]++;
}
