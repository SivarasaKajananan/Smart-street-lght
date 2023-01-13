.include "m328Pdef.inc"

; Define sensor and LED pins
.equ IR1 = PINB0
.equ IR2 = PINB1
.equ IR3 = PINB2
.equ IR4 = PINB3
.equ LED1 = PINB4
.equ LED2 = PINB5
.equ LED3 = PINC0
.equ LED4 = PINC1
.equ LED5 = PINC2
.equ LED6 = PINC3
.equ LED7 = PIND0
.equ LED8 = PIND1

.cseg
.org 0x00
    rjmp RESET

; Interrupt Vectors
.org INT0addr
    rjmp INT0_ISR

RESET:
    ; Initialize stack pointer
    ldi r16, LOW(RAMEND)
    out SPL, r16
    ldi r16, HIGH(RAMEND)
    out SPH, r16

    ; Set IR sensor pins as input
    cbi DDRB, IR1
    cbi DDRB, IR2
    cbi DDRB, IR3
    cbi DDRB, IR4

    ; Set LED pins as output
    sbi DDRB, LED1
    sbi DDRB, LED2
    sbi DDRC, LED3
    sbi DDRC, LED4
    sbi DDRC, LED5
    sbi DDRC, LED6
    sbi DDRD, LED7
    sbi DDRD, LED8

main:
    ; Read sensors
    sbic PINB, IR1
    rjmp IR1_DETECTED
    sbic PINB, IR2
    rjmp IR2_DETECTED
    sbic PINB, IR3
    rjmp IR3_DETECTED
    sbic PINB, IR4
    rjmp IR4_DETECTED

    ; If no motion detected, turn off all LEDs
    cbi PORTB, LED1
    cbi PORTB, LED2
    cbi PORTC, LED3
    cbi PORTC, LED4
    cbi PORTC, LED5
    cbi PORTC, LED6
    cbi PORTD, LED7
    cbi PORTD, LED8
    rjmp main

IR1_DETECTED:
    sbi PORTB, LED1
    sbi PORTB, LED2
    cbi PORTC, LED3
    cbi PORTC, LED4
    cbi PORTC, LED5
    cbi PORTC, LED6
    cbi PORTD, LED7
    cbi PORTD, LED8
    rjmp main

IR2_DETECTED:
    cbi PORTB, LED1
    cbi PORTB, LED2
    sbi PORTC, LED3
    sbi PORTC, LED4
    cbi PORTC, LED5
    cbi PORTC, LED6
    cbi PORTD, LED7
    cbi PORTD, LED8
    rjmp main

IR3_DETECTED:
    cbi PORTB, LED1
    cbi PORTB, LED2
    cbi PORTC, LED3
    cbi PORTC, LED4
    sbi PORTC, LED5
    sbi PORTC, LED6
    cbi PORTD, LED7
    cbi PORTD, LED8
    rjmp main

IR4_DETECTED:
    cbi PORTB, LED1
    cbi PORTB, LED2
    cbi PORTC, LED3
    cbi PORTC, LED4
    cbi PORTC, LED5
    cbi PORTC, LED6
    sbi PORTD, LED7
    sbi PORTD, LED8
    rjmp main

; Interrupt Service Routine for external interrupt INT0
INT0_ISR:
    reti

.end
