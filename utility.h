#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

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
 * Convert a string of numbers to a vector of digits
 */

std::vector<int> stov(std::string str) {
  std::vector<int> ret;
  std::string builder;

  for (char c : str) {
    builder.push_back(c);
    ret.push_back(std::stoi(builder));
    builder.pop_back();
  }

  return ret;
}

/*
 * Convert a vector of digits to a string of numbers
 */

std::string vtos(std::vector<int> nums) {
  std::string ret;

  for (auto i : nums) ret.append(std::to_string(i));

  return ret;
}

/*
 * Add two big numbers together, returned as a string
 */
std::string bignum_add(std::string num1, std::string num2) {
  std::string ret;

  // Determine which string is bigger and pad the other one with zeros at the beginning
  if (num1.size() > num2.size()) num2.insert(0, num1.size() - num2.size(), 0);
  else if (num2.size() > num1.size()) num1.insert(0, num2.size() - num1.size(), 0);

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

std::string bignum_mul(std::string num1, std::string num2) {
  std::string ret;
  std::vector<std::string> adds;
  int carry = 0;

  // Multiply each level
  for (int i = num1.size() - 1; i >= 0; i--) {
    std::string each_num;
    for (int j = num2.size() - 1; j >= 0; j--) {
      std::string dig1(1, num1[i]);
      std::string dig2(1, num2[j]);

      int mult = std::stoi(dig1) * std::stoi(dig2) + carry;
      
      if (mult > 10) {
        carry = ( mult - (mult % 10) ) / 10;
        each_num.insert(0, std::to_string(mult % 10));
      }
      else {
        carry = 0;
        each_num.insert(0, std::to_string(mult));
      }

      if (j == 0 && carry > 0) each_num.insert(0, std::to_string(carry));
    }
    adds.push_back(std::move(each_num));
  }

  // Add increasing zeros to each level
  for (int i = 0; i < adds.size(); i++) {
    adds[i].append(i,'0');
    // std::cout << adds[i] << std::endl;
  }

  ret = "0";
  for (auto a : adds)
    ret = bignum_add(ret, a);

  return ret;
}


#endif
