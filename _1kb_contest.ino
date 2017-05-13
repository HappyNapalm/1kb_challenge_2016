
uint8_t tmr_var = 0;

void setup() {
  noInterrupts();
  //Look up data sheets for more information
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 31250;            // compare match register 16MHz/256/[2Hz]
  //0.5 timer
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt

  //establish second timer
  //use this one to drive the servos.
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;
  OCR2A = 200; //(16Mhz/(Freq*8)-1)

  TCCR2A |= (1 << WGM21); //CTC mode
  TCCR2B |= (1 << CS22); //64 prescaler
  TIMSK2 |= (1 << OCIE2A); //enables timer compare interrupt

  PORTB = (1<<PB1); // writes pin 9 high
  DDRB = B11111111; // sets PORTB as output
  interrupts();
  TCNT1H = 0;//clears timer High Byte
  TCNT1L = 0;//clears timer Low Byte 
  
  TCNT2 = 0;//clears timer 2
}
ISR(TIMER1_COMPA_vect){//timer 1
  //PORTB = ~ PORTB;
}
ISR(TIMER2_COMPA_vect){//timer 2 interrupt
  tmr_var++;
}

void loop() {//testing the timers working together You need servos or an oscope to continue.
  if (tmr_var == 1){
    PORTB = ~PORTB;
    tmr_var = 0;
  }
}


