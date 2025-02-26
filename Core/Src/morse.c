#include "morse.h"
#include <stddef.h>
#include <ctype.h>


#define DOT_DURATION 200
#define DASH_DURATION (3*DOT_DURATION)
#define LETTER_CHANGE_DURATON (3*DOT_DURATION)
#define WORD_CHANGE_DURATION (7*DOT_DURATION)

void blink_dot(void);
void blink_dash(void);
void led_on(int delay_time);
void led_off(int delay_time);


#include "stm32f1xx_hal.h"

static const char* morseCodeLetters[] = {".-",   "-...", "-.-.",
								"-..",  ".",    "..-.",
								"--.",  "....", "..",
								".---", "-.-",  ".-..", 				 
								"--",   "-.",   "---",
								".--.", "--.-", ".-.",
								"...",  "-",    "..-",
								"...-", ".--",  "-..-",
								"-.--", "--.."};

static const char* morseCodeNumbers[] = {"-----", ".----", "..---",
                                "...--", "....-", ".....",
                                "-....", "--...", "---..",
                                "----."};


void morseCodeInterpreter(const char* text){

	for (int i = 0; text[i] != '\0'; i++ ){
		char c = toupper(text[i]);
        
        if(c >= '0' && c <= '9'){
            int index = c-'0';
            blinkCode( morseCodeNumbers[index]);
        }
        else if(c >= 'A' && c <= 'Z'){
            int index = c-'A';
            blinkCode(morseCodeLetters[index]);
        }
        else if(isspace(c)){
        	morse_delay(4*DOT_DURATION); //WORD CHANGE 7DOTS: ADD 4 DOT SILENCES TO LETTER_CHANGE SILENCE
        }
    }
}

void blinkCode(const char* morseCode){
    for (int j = 0; morseCode[j] != '\0'; j++){
        if (morseCode[j] == '.'){
        	blink_dot();

        }else if(morseCode[j] == '-'){
            blink_dash();
        }
    }

    morse_delay(2*DOT_DURATION); //LETTER CHANGE 3DOTS: ADD 2 DOT SILENCES TO THE LAST SYMBOL SILENCE
}

void blink_dot(){
    led_on(DOT_DURATION);
    led_off(DOT_DURATION);
}

void blink_dash(){
    led_on(DASH_DURATION);
    led_off(DOT_DURATION);
}

void led_on(int delay_time){
    morse_led_on();
    morse_delay(delay_time);
}

void led_off(int delay_time){
    morse_led_off();
    morse_delay(delay_time);
}    
