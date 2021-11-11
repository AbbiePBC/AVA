// 3. Write a function in a language of your choice which, when passed a positive integer returns
// true if the decimal representation of that integer contains no odd digits and otherwise returns
// false.

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool find_odd(uint64_t num){
  // assumption that the integer < 2^64 - 1
  while (num/10 != 0){
    printf("%ld = num\n", num);
    if (num%2 != 0){
      return false;
    }
    num = num/10;
  }
  return true;
}



// for testing...
// int main(void){

//   uint64_t num = 22225;
//   bool no_odd = find_odd(num);
//   printf("%d\n", no_odd);

//   return no_odd; // bool can be represented as int

// }