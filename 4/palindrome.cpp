/*
 * Project Eueler
 * Prbolem 4
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <algorithm>

using namespace std;

bool is_palindrome(int num);

int main() {
  int large = 0;

  for (int a = 100; a < 1000; a++) {
    for (int b = 100; b < 1000; b++) {
      if (is_palindrome(a * b) && ( a * b > large )) large = a * b;   
    }
  }

  cout << "Largest palindrome: " << large << endl;

  return 0;
}

bool is_palindrome(int num) {

  if (num % 10 == 0) return false; // If it ends in a 0, it can't be a palindrome
  
  vector<int> digits;
  int rem, old_num = num;

  // Break the number into digits
  while (num != 0) {
    rem = num % 10;
    digits.push_back(rem);
    num -= rem;
    num /= 10;
  }

  // Rebuild the number in reverse
  for (auto i : digits) {
    num += i;
    if (num != old_num) num *= 10;
  }

  return (num == old_num);
}
