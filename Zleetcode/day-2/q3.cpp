class Solution {
public:
#define ll long long

  vector<ll> left(vector<int> &a) {
    ll n = a.size();
    stack<ll> stk;
    vector<ll> res(n);
    for (ll i = 0; i < a.size(); i++) {
      while (!stk.empty() && a[i] < a[stk.top()])
        stk.pop();
      if (!stk.empty())
        res[i] = stk.top();
      else
        res[i] = -1;
      stk.push(i);
    }
    return res;
  }

  vector<ll> right(vector<int> &a) {
    ll n = a.size();
    vector<ll> res(n);
    stack<ll> stk;
    for (ll i = n - 1; i >= 0; i--) {
      while (!stk.empty() && a[stk.top()] > a[i])
        stk.pop();
      if (!stk.empty())
        res[i] = stk.top();
      else
        res[i] = n;
      stk.push(i);
    }
    return res;
  }

  long long maximumSumOfHeights(vector<int> &a) {
    ll ans = 0, n = a.size();
    vector<ll> dpl(n), dpr(n);

    vector<ll> nsel = left(a);
    vector<ll> nser = right(a);

    for (ll i = 0; i < a.size(); i++) {
      if (i == 0)
        dpl[i] = a[i];
      else if (a[i] > a[i - 1])
        dpl[i] = dpl[i - 1] + a[i];
      else {
        ll idx = nsel[i], e = i - idx;
        dpl[i] = (idx > 0 ? dpl[idx] : 0) + e * a[i];
      }
    }

    for (ll i = n - 1; i >= 0; i--) {
      if (i == n - 1)
        dpr[i] = a[i];
      else if (a[i] > a[i + 1])
        dpr[i] = dpr[i + 1] + a[i];
      else {
        ll idx = nser[i], e = idx - i;
        dpr[i] = (idx < n ? dpr[idx] : 0) + e * a[i];
      }
    }

    ans = max({ans, dpr[0], dpl[n - 1]});

    for (ll i = 0; i < a.size(); i++) {
      ans = max(ans, dpl[i] + dpr[i] - a[i]);
    }

    return ans;
  }
};