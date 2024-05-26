class Solution {
public:
  int countTriplets(vector<int> &a) {
    int cnt = 0;
    // xor -> sum of indixes where that xor is present , cnt(how many times)
    unordered_map<int, pair<int, int>> mp;
    mp[0] = {-1, 1};
    int x = 0;
    for (int i = 0; i < a.size(); i++) {
      x ^= a[i];
      if (mp.count(x))
        cnt += (mp[x].second * i) - (mp[x].first) - mp[x].second;
      mp[x] = {mp[x].first + i, mp[x].second + 1};
    }
    return cnt;
  }
};