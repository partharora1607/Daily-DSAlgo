#include <iostream>
#include <string>
using namespace std;

// Convert Function which takes in
// 24-hour time and converts it to
// 12-hour format without seconds

void convert12(string str) {
  // Get Hours
  int h1 = (int)str[0] - '0';
  int h2 = (int)str[1] - '0';

  int hh = h1 * 10 + h2;

  // Finding out the Meridien of time
  // ie. AM or PM
  string Meridien;
  if (hh < 12) {
    Meridien = "AM";
  } else
    Meridien = "PM";

  hh %= 12;

  // Handle 00 and 12 case separately
  if (hh == 0) {
    cout << "12";
  } else {
    // Ensure leading zero if hour is single digit
    if (hh < 10) {
      cout << "0";
    }
    cout << hh;
  }

  // Printing minutes
  for (int i = 2; i < 5; ++i) {
    cout << str[i];
  }

  // After time is printed
  // cout Meridien
  cout << " " << Meridien << '\n';
}

void Solve() {
  string s;
  cin >> s;
  convert12(s);
}

int32_t main() {
  int t = 1;

  cin >> t;
  for (int i = 1; i <= t; i++) {
    // cout << "Case #" << i << ": ";
    Solve();
  }
  return 0;
}
