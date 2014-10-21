/*
 * Project Euler
 * Problem 3
 *
 * What is the largest prime factor of 600851475143?
 */

#include <algorithm>
#include <iostream>

using namespace std;

bool is_prime(unsigned long long num);

int main() {

  unsigned long long large = 600851475143;
  unsigned long long factor = 1;
  unsigned long long big_factor = 0;

  while (factor < large / 2) {
    factor++;
    if (large % factor != 0) continue;
    if (is_prime(factor)) {
      // if (factor < big_factor) break;
      // big_factor = factor;
      cout << "Prime Factor: " << factor << endl;
    }
  }

  return 0;
}

bool is_prime(unsigned long long num) {

  if (num % 2 == 0 && num % 3 == 0) return false;
  unsigned long long i = num - 1;

  while (i > 4) {
    if (num % i == 0) return false;
    i--;
  }

  return true;
}
