#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

#define ll long long
vector<long long> distance(vector<int> &a) {
  ll n = a.size();
  unordered_map<int, unordered_map<ll, pair<ll, ll>>> mp;
  unordered_map<ll, pair<ll, ll>> my_map;
  for (int i = n - 1; i > 0; i--) {
    my_map[a[i]] = {my_map[a[i]].first + 1, my_map[a[i]].second + i};
    mp[i] = my_map;
  }
  vector<ll> ans(n);
  for (int i = 0; i < a.size() - 1; i++) {
    ans[i] = max(0LL, mp[i][a[i]].second - mp[i][a[i]].first * i);
  }
  return ans;
}

int main() {}
