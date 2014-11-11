/*
 * Project Euler
 * Problem 22
 *
 * What is the total of all name scores?
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;

int main() {
#include "names.h"

  sort(begin(names), end(names));

  uint64_t score{0};
  for (int i = 0; i < names.size(); i++) {
    int acc{0};
    for (auto &a : names[i]) acc += (a - 64);
    score += acc * (i + 1);
  }
  cout << score << endl;
  return 0;
}
