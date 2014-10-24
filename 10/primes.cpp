/*
 * Project Euler
 * Problem 10
 *
 * Find the sum of all the primes below two million.
 */

#include "../utility.h"
#include <iostream>
using namespace std;

int main() {
  
  BigUint sum = 0;

  for (BigUint i = 0; i < 2000000; i++)
    if (is_prime(i)) sum += i;

  cout << sum << endl;

  return 0;
}
