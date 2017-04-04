// Timer0 for Blue Motor position, Timer2 for Red Motor position

void timerSetup (void){

  //set timer5 interrupt at 2kHz
  TCCR5A = 0;// set entire TCCR2A register to 0
  TCCR5B = 0;// same for TCCR2B
  TCNT5  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR5A = 249;// = (16*10^6) / (8000*8) - 1(must be <256)
  // turn on CTC mode
  TCCR5A |= (1 << WGM12);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR5B |= (1 << CS21);  
  // enable timer compare interrupt
  TIMSK5 |= (1 << OCIE5A);

}

