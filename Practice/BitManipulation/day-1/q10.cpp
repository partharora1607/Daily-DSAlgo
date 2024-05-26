#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

string compress11(string s) {
  string ok;
  s += ' ';
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1')
      cnt++;
    else {
      if (cnt > 0)
        ok += cnt + '0';
      if (s[i] != ' ')
        ok += s[i];
      cnt = 0;
    }
  }
  return ok;
}

void pepcoding(string &s) {
  int n = (int)s.size();
  for (int i = 0; i < (1 << n); i++) {
    string ok;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0)
        ok += s[j];
      else
        ok += '1';
    }
    string str = compress11(ok);
    cout << str << "\n";
  }
}

int main() {
  string s;
  cin >> s;
  cout << "\n";
  pepcoding(s);
  return 0;
}
