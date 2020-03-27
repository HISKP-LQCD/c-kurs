
// dieses struct wird immer und immer wieder deklariert werden
struct test_struct1 {
  double x;
  int k;
  float b;
  char c[20];
};

#ifndef TEST_INCLUDE_H
#define TEST_INCLUDE_H
// diese Deklaration wird nur einmal stattfinden
struct test_struct2 {
  double x;
  int k;
  unsigned long int w;
};
#endif // ifndef(TEST_INCLUDE_H)
