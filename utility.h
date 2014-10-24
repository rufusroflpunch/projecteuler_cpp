#ifndef UTILITY_H
#define UTILITY_H

typedef unsigned long long BigUint;

/*
 * Determine if a value is a prime number
 */
bool is_prime(unsigned long long num) {

  if (num == 0 || num == 1) return false;
  if (num == 2 || num == 3) return true;
  if (num % 2 == 0) return false;
  unsigned long long i = num / 2;

  while (i > 2) {
    if (num % i == 0) return false;
    i--;
  }

  return true;
}

#endif
