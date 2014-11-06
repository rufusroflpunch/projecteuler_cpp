/*
 * Project Euler
 * Problem 17
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 */

#include <iostream>
#include <cassert>
#include "../utility.h"
using namespace std;

string int_to_words(int num);

int main() {
  // cout << int_to_words(1) << endl;
  // cout << int_to_words(74) << endl;
  // cout << int_to_words(99) << endl;
  // cout << int_to_words(111) << endl;
  // cout << int_to_words(153) << endl;
  // cout << int_to_words(981) << endl;
  // cout << int_to_words(1000) << endl;

  string letters = "";
  for (int i = 1; i <= 1000; i++) {
    letters += int_to_words(i);
    cout << int_to_words(i) << endl;
  }

  cout << letters.size() << endl;
  return 0;
}

string int_to_words(int num) {
  vector<string> ones = { "", "one", "two", "three", "four", "five", "six", "seven", "eight",
    "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen" };
  vector<string> tens = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty",
    "seventy", "eighty", "ninety" };

  if (num < 20)
    return ones[num];
  if (num < 100) {
    int ten_dig = num / 10,
        one_dig = num % 10;
    return tens[ten_dig] + ones[one_dig];
  }
  if (num < 1000) {
    int hun_dig = num / 100,
        ten_dig = num % 100 / 10,
        one_dig = num % 100 % 10;
    return ones[hun_dig] + "hundred" +
      (ten_dig > 0 || one_dig > 0 ? "and" : "") +
      (ten_dig == 1 ? ones[ten_dig*10 + one_dig] : "") +
      (ten_dig > 1 ? tens[ten_dig] : "") +
      (one_dig > 0 && ten_dig < 1 ? ones[one_dig] : "") +
      (ten_dig > 1 ? ones[one_dig] : "");
  }
  if (num == 1000)
    return "onethousand";

  return "";
}
