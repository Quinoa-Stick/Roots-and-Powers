#include <iostream>

//power function -- doesn't work on decimals
void pwr(double *sqr, double y) {
  if (y == 0) {
    *sqr = 1;
    return;
  }
  int s = *sqr;
  for (int i = 1; i < y; i++)
    *sqr *= s;
  return;
}

//square root function
double sqrt(double *s, char *i) {
  double x = 50;
  if (*s == 0) {
    *s = 0;
    return *s;
  }
  if (*s < 0) {
    *i = 'i';
    *s = -*s;
  }
  for (int i = 0; i < 10; i++) {
    x = (x + *s / x) / 2;
  }
  *s = x;
  return *s;
}

//power for nth root function
double power(double *x, double n) {
    if (n == 0) {
    *x = 1;
    return *x;
  }
  int s = *x;
  for (int i = 1; i < n; i++)
    *x *= *x;
  return *x;
}

//nth root
double root(double *s, double rt, char *i) {
  double x = 10;
  double n = rt - 1;
  double p1 = 1 / rt;
  double p2 = 1;
  double p3 = 1;
  double p4 = 1;
  if (rt == 2){
    return sqrt(*&s, *&i);
  } else if (rt == 1)
    return *s;
  else if (*s == 0) {
    *s = 0;
    return *s;
  } else {
    for (int i = 0; i < 50; i++) {
      p2 = n * x;
      for (int q = 0; q < n; q++)
        p3 *= x;
      p4 = *s / p3;
      x = p1 * (p2 + p4);
      std::cout << x << std::endl;
    }
  }
  *s = x;
  return *s;
}

int main() {
  toHigh:
  int choice = 0;
  char i;
  std::cout << "What operation do you need?\nPower:\t1\tSqrt:\t2\tRoot:\t3\n";
  //int choice;
  std::cin >> choice;

  //power
  if (choice == 1) {
    double x, y;

    std::cout << "What number do you need?\n";
    std::cin >> x;
    std::cout << "And to what power?\n";
    std::cin >> y;

    std::cout << x << " to the power of " << y << " is ";

    pwr(&x, y);

    std::cout << x << std::endl;

    //sqrt
  } else if (choice == 2) {
    double s;

    std::cout << "What number do you want square rooted?\n";
    std::cin >> s;

    std::cout << "The square root of " << s << " is ";

    sqrt(&s, &i);

    std::cout << s << i << std::endl;

    //root
  } else if (choice == 3) {
    double s, x;

    std::cout << "What would you like rooted?\n";
    std::cin >> s;
    std::cout << "and to what root?\n";
    std::cin >> x;

    std::cout << s << " to the root of " << x << " is ";

    root(&s, x, &i);

    std::cout << s << i << std::endl;

    //char input
  } else if (isdigit(choice)) {
    goto toHigh;

    //num out of range
  } else {
    goto toHigh;
  }
  return 0;
}