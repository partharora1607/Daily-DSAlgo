#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

vector<int> solve(vector<int> &a, vector<vector<int>> &queries) {
  unordered_map<int, int> mp;
  for (int i = 0; i < a.size(); i++) {
    mp[a[i]]++;
  }
  vector<int> res;
  for (int i = 0; i < queries.size(); i++) {
    int x, y;
    x = queries[i][0], y = queries[i][1];
    int val = a[x - 1] - y;
    if (--mp[a[x - 1]] == 0) {
      mp.erase(a[x - 1]);
    }
    mp[val]++;
    res.push_back((int)mp.size());
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int m;
  cin >> m;
  vector<vector<int>> queries(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    queries[i] = {x, y};
  }
  vector<int> res = solve(a, queries);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "\n";
  }
  return 0;
}
