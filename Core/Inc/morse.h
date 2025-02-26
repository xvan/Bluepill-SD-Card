#ifndef MORSE_H
#define MORSE_H

/* Function declarations */
void morseCodeInterpreter(const char* text);
void blinkCode(const char* morseCode);

/* Implementation Specific */
void morse_led_on(void);
void morse_led_off(void);
void morse_delay(int delay_time_ms);

#endif /* MORSE_H */
