//2. Find the instances of undefined behaviour in the following code:
#include <stdio.h>
#include <stdlib.h> // add malloc library
#include <string.h>
char *f(int m)
{
 //char buf[6];  <- statically declaring the address means that a local copy will be returned

 // I don't know if X is supposed to have a purpose but doesn't look like it

 if (m == 1)
 {
  char* buf = (char*)malloc(sizeof(char) * 7); // size increased to include \0
  // this doesn't have to be above the fn so move it here to avoid having to declare and free if not needed
  // I would probably have used the same buffer for buf and msg but that's not technically a problems
  strcpy(buf, "AAAAAA");
  buf[6] = '\0'; // need to null terminate. Nicer to use strlen/not hardcode length.
  return buf;
 }
 else if (m == 2)
 {
  char *msg = (char *)malloc(100);
  strcpy(msg, "BBBBBB");
  // msg returns BBBBBB....... etc, and will access memory outside of the string we want
  msg[6] = '\0';
  return msg;
 }

 return NULL; // need to return char*
}


int main(int argc, char **argv)
{
 char *m = NULL;
 m = f(argc);
 if (m == NULL){
   // need to check for NULL returned
   return 1;
 }
 // printf("%s\n", m); <- checking output
 putchar(m[0]); // this prints m[0] to terminal; don't need to change size of allocations etc
 // printf("%s\n", m); <- checking output

 free(m); // return dynamically allocated memory; need to free
 return 0;
}