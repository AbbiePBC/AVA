// 3. Write a C function reverse_bytes() taking two parameters and returning no result. The first
// parameter is a pointer to a buffer containing n contiguous bytes (each of type unsigned
// char), and the second is a count of the number of bytes. The function should reverse the order
// of the bits in the n contiguous bytes, which is seen as a bitstring of length 8n. For example, the
// first bit of the first byte should be swapped with last bit of the last byte.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE_LEN 8

unsigned char reverse_bits(unsigned char input){

  unsigned char new_char = 0; // initialising
  for (int i = 1; i < BYTE_LEN+1; i ++){
    unsigned char tmp = input % (2*i);
    new_char = new_char | tmp << (BYTE_LEN - i);

  }
  return new_char;
}


void reverse_bytes(char** buffer, int bytes){

  char* new_buf = (char*) malloc(sizeof(char) * (bytes+1));
  char* tmp_buf = *buffer; // not strictly needed
  for (int i = 0; i < bytes; i ++){
    char tmp = tmp_buf[i];
    new_buf[bytes - i] = reverse_bits(tmp);

    // could do this in one go and treat the array as one long data type
    // which would be more efficient, however this is more readable
  }
  new_buf[bytes] = '\n';
  *buffer = new_buf;

}


int main(void){
  int bytes = 4;
  char *buffer = (char*) malloc(sizeof(char) * (bytes+1));
  buffer = "ABCD\n";
  for (int i = 0; i < bytes; i ++){
    printf("%u \n", buffer);
  }

  reverse_bytes(&buffer, bytes);
  for (int i = 0; i < bytes; i ++){
    printf("%u \n", buffer);
  }

  free(buffer);

}