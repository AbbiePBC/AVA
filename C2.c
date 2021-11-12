//2. Find the instances of undefined behaviour in the following code:
#include <stdio.h>
#include <string.h>
char *f(int m)
{
 char buf[6];
 int x;

 if (m == 1 && x--)
 {
 strcpy(buf, "AAAAAA");
 return buf;
 }
 else if (m == 2)
 {
 char *msg = (char *)malloc(100);
 strcpy(msg, "BBBBBB");
 return msg;
 }
}
int main(int argc, char **argv)
{
 char *m;
 m = f(argc);
 putchar(m[0]);
 return 0;
}