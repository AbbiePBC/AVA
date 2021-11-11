// Write a function in a language of your choice which, when passed a decimal digit X, returns the
// value of X+XX+XXX+XXXX. E.g. if the supplied digit is 3 it should return 3702
// (3+33+333+3333).

// == 3000 + 2(300) + 3(30) + 4(3)
// assumption from "digit", that 0<=X<=9

#include <math.h>
#include <stdio.h>
#include <stdint.h>

#define NUM_ADDITIONS 4



uint16_t sum_additions(int X){
  uint16_t result = 0;
  // max val for X = 9 is 11106, so < 2^16 -1
  for (int i = 0; i < NUM_ADDITIONS; i ++){
    result += X*pow(10,i)*(NUM_ADDITIONS-i);
  }
  printf("result: %ld\n", result);
  return result;
}

// testing...

// int main(void){
//   int X = 9;
//   uint16_t result = sum_additions(X);

//   return result;
// }