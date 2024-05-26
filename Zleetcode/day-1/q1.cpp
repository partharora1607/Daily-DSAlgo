

// method - 1 using prefix sum

class Solution {
public:
  int longestWPI(vector<int> &hours) {
    // Compute prefix sum: +1 if hours > 8, -1 otherwise
    vector<int> prefix_sum;
    int sum = 0;
    for (int h : hours) {
      sum += (h > 8) ? 1 : -1;
      prefix_sum.push_back(sum);
    }

    // Running max from the right
    vector<int> max_prefix_sum = prefix_sum;

    for (int i = hours.size() - 2; i >= 0; i--) {
      max_prefix_sum[i] = max(prefix_sum[i], max_prefix_sum[i + 1]);
    }

    // Sliding window: find max-length interval [i,j] with positive sum
    int i = 0, j = 0, result = 0;
    while (i < hours.size() && j < hours.size()) {
      int curr_sum = max_prefix_sum[j] - ((i > 0) ? prefix_sum[i - 1] : 0);
      if (curr_sum > 0) {
        result = max(result, j - i + 1);
        j++;
      } else {
        i++;
      }
    }

    return result;
  }
};

// Method - 2 using map

class Solution {
public:
  int longestWPI(vector<int> &a) {
    int ans = 0, sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < a.size(); i++) {
      sum += a[i] > 8 ? 1 : -1;
      if (sum > 0)
        ans = i + 1;
      else {
        if (mp.count(sum) == 0)
          mp[sum] = i;
        if (mp.count(sum - 1))
          ans = max(ans, i - mp[sum - 1]);
      }
    }
    return ans;
  }
};

// method - 3 brute force

class Solution {
public:
  int longestWPI(vector<int> &a) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
      int sum = 0;
      for (int j = i; j < a.size(); j++) {
        sum += a[j] > 8 ? 1 : -1;
        if (sum > 0)
          ans = max(ans, j - i + 1);
      }
    }
    return ans;
  }
};