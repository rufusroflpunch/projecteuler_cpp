/*
 * Project Euler
 * Problem 20
 *
 * Find the sum of the digits in number 100! (factorial).
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include "../utility.h"
using namespace std;

int main() {
  auto fac = string{"1"};
  for (int n = 100; n > 0; n--) {
    fac = bignum_mul(fac, to_string(n));
  }

  auto adds = int{0};
  for (auto &n : fac) adds += stoi(string{n});

  cout << adds << endl;
}
