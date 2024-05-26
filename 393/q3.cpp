class Solution {
public:
#define ll long long
  // return the count of denominations
  ll deno(vector<int> &a, ll x) {
    ll ans = 0, n = (ll)a.size();
    for (ll i = 1; i < (1 << n); i++) {
      ll lcmm = 1;
      for (ll j = 0; j < n; j++) {
        ll msk = (1 << j);
        if (i & msk)
          lcmm = lcm(lcmm, a[j]);
      }
      int cnt = 0, ok = i;
      while (ok != 0) {
        int rmsb = ok & -ok;
        ok ^= rmsb;
        cnt++;
      }
      if (cnt % 2 != 0)
        ans += (x / lcmm);
      else
        ans -= (x / lcmm);
    }
    return ans;
  }

  long long findKthSmallest(vector<int> &a, int k) {
    ll l = 1, r = 5e10, ans = 0;
    while (l <= r) {
      ll m = (l + r) / 2;
      ll cnt_of_d = deno(a, m);
      if (cnt_of_d < k) {
        l = m + 1;
      } else if (cnt_of_d == k) {
        ans = m;
        r = m - 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};