#include "helper.h"

void send_string(char * str)
{
  while(*str)
  {
    send_byte(*str);
    str++;
  }
  send_byte(0x0d);
  send_byte(0x0a);  
}

void send_byte(char c)
{
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
}
