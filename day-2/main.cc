#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string line;
  long checksum = 0;
  while (cin.good()) {
    getline(cin, line);
    istringstream iss(line);
    long line_min;
    iss >> line_min;
    if (!iss.good()) {
      continue;
    }
    long line_max = line_min;
    while (iss.good()) {
      long next;
      iss >> next;
      if (iss.bad()) {
        break;
      }
      line_min = min(line_min, next);
      line_max = max(line_max, next);
    }
    checksum += line_max - line_min;
  }
  cout << checksum << endl;
  return 0;
}
