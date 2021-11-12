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
  for (int i = 0; i < BYTE_LEN; i ++){
    unsigned char tmp = input % 2;
    new_char += (tmp << (BYTE_LEN - i -1 ));
    input = input>>1; // could check if zero and terminate early but may take longer to check
  }
  return new_char;
}


void reverse_bytes(unsigned char** buffer, int bytes){

  unsigned char* new_buf = (unsigned char*) malloc(sizeof(unsigned char) * (bytes+1));

  unsigned char* tmp_buf = *buffer; // not strictly needed
  for (int i = 0; i < bytes; i ++){
    unsigned char tmp = tmp_buf[i];
    new_buf[bytes - i - 1] = reverse_bits(tmp);
    // could do this in one go and treat the array as one long data type
    // which would be more efficient, however this is more readable
  }
  new_buf[bytes] = '\n';
  *buffer = new_buf;

}


// int main(void){
//   int bytes = 4;
//   unsigned char *buffer = (unsigned char*) malloc(sizeof(unsigned char) * (bytes+1));
//   for (int i = 0; i < bytes; i ++){
//     buffer[i] = 'C';
//     printf("%u \n", buffer[i]);
//   }

//   reverse_bytes(&buffer, bytes);
//   for (int i = 0; i < bytes; i ++){
//     printf("%u \n", buffer[i]);
//   }

//   free(buffer);

// }