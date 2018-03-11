double function(double a, double b){
  return a*b;
}

double function(float a, float b, int b){
  return (double)(a*b);
}
int main(void){
  double a = function((float)0.1,(float)0.2);
  double b = function((double)0.1, (float)3.0, 4);

  printf("a = %lf , b = %lf\n",a,b);
  return 0;
}
