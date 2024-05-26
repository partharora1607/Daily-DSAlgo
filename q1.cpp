#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

vector<int> next_smallest(vector<int> &a) {
  int n = a.size();
  vector<int> res(n);
  // idx
  stack<int> stk;

  for (int i = 0; i < a.size(); i++) {
    while (!stk.empty() && a[i] <= a[stk.top()])
      stk.pop();
    if (stk.empty())
      res[i] = -1;
    else
      res[i] = stk.top();
    stk.push(i);
  }

  return res;
}

int findUnsortedSubarray(vector<int> &a) {
  // first find si then find ei in o(n) time
  vector<int> v = next_smallest(a);

  int n = (int)a.size(), mini = n;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] + 1 != i)
      mini = min(mini, v[i] + 1);
  }

  int maxi = INT_MIN, idx = -1;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] < maxi) {
      idx = i;
    }
    maxi = max(maxi, a[i]);
  }

  return mini == n ? 0 : idx - mini;
}

int main() {
  vector<int> a = {2, 5, 8, 3};
  vector<int> res = next_smallest(a);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
