#ifndef UTILITY_H
#define UTILITY_H

/*
 * Determine if a value is a prime number
 */
bool is_prime(unsigned long long num) {

  if (num == 2 || num == 3) return true;
  if (num % 2 == 0 && num % 3 == 0) return false;
  unsigned long long i = num - 1;

  while (i > 4) {
    if (num % i == 0) return false;
    i--;
  }

  return true;
}

#endif
