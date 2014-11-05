/*
 * Project Euler
 * Problem 16
 *
 * What is the sum of the digits of the number 2^1000?
 *
 */

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "../utility.h"
using namespace std;

int main() {

  string num = "2", start = "2";
  for (int i = 1; i <= 999; i++) {
    // cout << i << " " << endl;
    num = bignum_mul(start, num);
  }
  cout << num << endl;
  
  auto vnum = stov(num);
  BigUint sum = accumulate(begin(vnum), end(vnum), 0);
  cout << sum << endl;
  // cout << bignum_mul("323249", "3456") << endl;
  return 0;
}
