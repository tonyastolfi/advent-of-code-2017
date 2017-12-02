#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string line;
  long checksum = 0;
  long quotient_sum = 0;
  while (cin.good()) {
    getline(cin, line);
    istringstream iss(line);
    long line_min;
    iss >> line_min;
    if (!iss.good()) {
      continue;
    }
    long line_max = line_min;
    vector<long> nums = {line_min};
    while (iss.good()) {
      long next;
      iss >> next;
      if (iss.bad()) {
        break;
      }
      line_min = min(line_min, next);
      line_max = max(line_max, next);
      for (long n : nums) {
        long num = max(n, next);
        long div = min(n, next);
        if (num % div == 0) {
          quotient_sum += num / div;
        }
      }
      nums.push_back(next);
    }
    checksum += line_max - line_min;
  }
  cout << "part-1: " << checksum << endl;
  cout << "part-2: " << quotient_sum << endl;
  return 0;
}
