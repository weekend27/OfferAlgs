#include <iostream>
#include <stdlib.h>
using namespace std;

// 参考：http://www.cnblogs.com/xwdreamer/archive/2012/05/15/2502329.html


bool isInvalidInput = false;

double PowerWithUnsignedExponent(double base, unsigned int absExp) {
  if (absExp == 0) {
    return 1;
  } else if (absExp == 1) {
    return base;
  }
  
  // 递归方法
  double result = PowerWithUnsignedExponent(base, absExp/2);
  result *= result;
  if (absExp % 2 == 1) {  // 指数为奇数时，再乘以一次底数
    result *= base;
  }

  return result;
}

// 因为精度问题，double类型的变量不能用等号进行判等
bool equal(double a, double b) {
  if ((a - b > -0.000001)&&(a - b < 0.000001)) {
    return true;
  } else {
    return false;
  }
}

double Power(double base, int exponent) {
  // 如果底数为0而且指数小于等于0，表明是非法输入
  if (equal(base, 0) && exponent <= 0) {
    isInvalidInput = true;
    return 0;
  }

  unsigned int absExp;
  // 判断指数正负，去掉指数的绝对值
  if (exponent < 0) {
    absExp = (unsigned int)(-exponent);
  } else {
    absExp = (unsigned int)exponent;
  }

  double result = PowerWithUnsignedExponent(base, absExp);

  // 如果指数小于0则取倒数
  return exponent < 0 ? 1 / result : result;
}

int main() {
  double r1 = Power(2.0, 15);
  double r2 = Power(4.786, 7);
  double r3 = Power(0, 0);
  double r4 = Power(0, 2);
  double r5 = Power(0, -7);
  double r6 = Power(9.876, -19);

  cout << "r1 = " << r1 << endl;
  cout << "r2 = " << r2 << endl;
  cout << "r3 = " << r3 << endl;
  cout << "r4 = " << r4 << endl;
  cout << "r5 = " << r5 << endl;
  cout << "r6 = " << r6 << endl;

  return 0;

}
