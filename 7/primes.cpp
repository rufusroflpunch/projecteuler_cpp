/*
 * Project Euler
 * Problem 7
 *
 * What is the 10 001st prime number?*
 */

#include <algorithm>
#include <iostream>

using namespace std;

bool is_prime(unsigned long long num);

int main() {
  int count = 2;
  unsigned long long num = 5, prime = 0;

  while (count < 10001) {
    if (is_prime(num)) { count++; prime = num; }
    num++;
  }

  cout << prime << endl;

  return 0;
}

bool is_prime(unsigned long long num) {

  if (num % 2 == 0 && num % 3 == 0) return false;
  unsigned long long i = num - 1;

  while (i > 1) {
    if (num % i == 0) return false;
    i--;
  }

  return true;
}
