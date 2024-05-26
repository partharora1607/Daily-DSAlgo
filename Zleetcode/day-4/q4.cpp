#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
#define ll long long

  long long totalCost(vector<int> &a, int k, int x) {
    ll n = a.size();
    ll ans = 0;
    if (n <= 2 * x) {
      sort(a.begin(), a.end());
      for (ll i = 0; i < k; i++) {
        ans += a[i];
      }
      return ans;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pqL, pqR;
    for (ll i = 0; i < x; i++) {
      pqL.push(a[i]);
      pqR.push(a[n - i - 1]);
    }
    ll lidx, ridx;
    lidx = k;
    ridx = n - k - 1;
    while (k && !pqL.empty() && !pqR.empty() && lidx < ridx) {
      if (pqL.top() <= pqR.top()) {
        ans += pqL.top();
        pqL.pop();
        pqL.push(a[lidx++]);
      } else {
        ans += pqR.top();
        pqR.pop();
        pqR.push(a[ridx--]);
      }
      k--;
    }
    if (lidx >= ridx) {
      // sort
      sort(a.begin() + idx)
    }
    while (k && !pqL.empty()) {
      ans += pqL.top();
      pqL.pop();
      k--;
    }
    while (k && !pqR.empty()) {
      ans += pqR.top();
      pqR.pop();
      k--;
    }
    return ans;
  }
};

int main() {}
