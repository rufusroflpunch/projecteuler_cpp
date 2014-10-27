#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iostream>

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

/*
 * Add two big numbers together, returned as a string
 */
std::string bignum_add(std::string num1, std::string num2) {
  std::string ret;

  // Determine which string is bigger and pad the other one with zeros at the beginning
  if (num1.size() > num2.size()) num2.insert(0, num1.size() - num2.size(), '0');
  else if (num2.size() > num1.size()) num1.insert(0, num2.size() - num1.size(), '0');

  // Add the strings
  int carry = 0;
  for (int i = num1.size() - 1; i >=0; i--) {
    // Get each digit
    std::string dig1(1, num1[i]);
    std::string dig2(1, num2[i]);

    // Add the strings, plus the carry from the last addition
    int add = std::stoi(dig1) + std::stoi(dig2) + carry;

    // If it's more than 10, carry the one
    if (add >= 10) {
      add -= 10;
      carry = 1;
    }
    else carry = 0; // Reset the carry to zero if it's less than 10

    // Create a string for the added number
    ret.insert(0, std::to_string(add));
    if (i == 0 && carry > 0) ret.insert(0,std::to_string(carry));
  }
  
  return ret;
}


#endif
