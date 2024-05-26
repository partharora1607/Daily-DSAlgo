// print the value of rsb mask
#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

int main() {
  int a = 10;
  int rsbma = a & -a;
  cout << rsbma << endl;
}
