#include "com.h"
/*
void setup_com()
{
  SREG = 0x80;
  bitSet(UCSR0B, RXCIE0);
  bitSet(UCSR0B, RXEN0);
  bitSet(UCSR0B, TXEN0);
  bitSet(UCSR0C, UCSZ01);
  bitSet(UCSR0C, UCSZ00);
  UBRR0 = (F_CPU / 16 / BAUD_RATE - 1);
}

ISR(USART_RX_vect) // for UNO
{
  UCSR0B &= ~(1 << RXCIE0); // Turn off the serial port interrupt
  get_data(); 
  UCSR0B |=  (1 << RXCIE0); // Open serial port interrupt
}

void get_data()
{
  static int i;
  serial_data = UDR0; // Read serial port
  if (rec_flag == 0)
  {
    if (serial_data == 0xff) // Get 0xff for the first time (ie header)
    {
      rec_flag = 1;
      i = 0;
      Costtime = 0;
    }
  }
  else
  {
    if (serial_data == 0xff) // The second time to get 0xff (that is, the end of the package)
    {
      rec_flag = 0;
      if(1) //if (i == 3) // The intermediate data is 3 bytes, indicating that the command is in the correct format.
      {
        communication_decode(i); // Execute command parsing function
      }
      i = 0;
    }
    else
    {
      buffer[i] = serial_data;// Temporary data
      i++;
    }
  }
}

void communication_decode(int i)
{
  for (int index = 0 ; index <= i ; ++index) {
    if (i % 2)
    {
      light_turn_on();
      delay(500);
    }
    else {
      light_turn_off();
    }
  switch(buffer[index] & 0xF0)
    {
      case 0x10:
        // delay
      break;
      case 0x20:
        // save command
      break;
      case 0x30:
        // move
      break;
      case 0x40:
        // head
      break;
      case 0x50:
        // light
        switch(buffer[index] & 0x0F)
        {
          case 0x00:
            light_turn_off();
          break;
          case 0x01:
            light_turn_on();
        }
      break;
    }
  }
}*/
