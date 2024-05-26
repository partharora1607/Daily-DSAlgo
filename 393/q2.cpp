// time complexity = o(√n)

bool isPrime(int n) {
  if (n == 1)
    return false;
  else if (n == 2 || n == 3)
    return true;
  else if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

// time complexity = o(n log log n).

vector<int> seive(int n) {
  vector<int> prime(n + 1, 1);
  // non prime are in the form of a * b where max is root(n);
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = 0;
      }
    }
  }
  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      ans.push_back(i);
    }
  }
  return prime;
}

int maximumPrimeDifference(vector<int> &a) {
  vector<int> prime = seive(100);
  int mx = -1, mn = n + 1;
  for (int i = 0; i < a.size(); i++) {
    if (prime[a[i]]) {
      mn = min(mn, i);
      mx = max(mx, i)
    };
  }
  return mx - mn;
}