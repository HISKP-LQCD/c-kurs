#include <stdio.h>
int main(void){
  char str[40];
  char str2[40];
  char str3[40];
  double x = 4.2;
  int k = 42;
  snprintf(str, 40, "x = %lf, k = %d", x, k);
  snprintf(str2, 40, "%s", str); 
  printf("%s\n",str);
  printf("%s\n",str2);

  int n = snprintf(str3, 40, "%s %s %s %s %s", str, str, str, str, str);
  if( n > 40 ){
    printf("Zu viele Zeichen im Input\n");
  }
  printf("str3 = %s\n",str3);
  printf("str3[39] = %d \n", (int)str3[39]); 
  printf("n = %d\n", n);

  return 0;
}
