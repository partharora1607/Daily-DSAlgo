// Method - 1 using stack

class Solution {
public:
  bool checkValidString(string s) {
    // s1 - parenthesis , s2 - *
    stack<int> s1, s2;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        s1.push(i);
      else if (s[i] == '*')
        s2.push(i);
      else {
        if (!s1.empty())
          s1.pop();
        else if (!s2.empty())
          s2.pop();
        else {
          return false;
        }
      }
    }
    while (!s1.empty()) {
      if (s2.empty() || s1.top() > s2.top())
        return false;
      s1.pop();
      s2.pop();
    }
    return s1.empty();
  }
};

// method - 2 using 2D - dp

class Solution {
public:
  bool checkValidString(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*')
        dp[i][i] = 1;
      if (i + 1 < n && (s[i] == '*' || s[i] == '(') &&
          (s[i + 1] == '*' || s[i + 1] == ')')) {
        dp[i][i + 1] = 1;
      }
    }

    for (int size = 3; size <= n; size++) {
      for (int i = 0; i + size <= n; i++) {
        if (s[i] == '*' && dp[i + 1][i + size - 1] == 1)
          dp[i][i + size - 1] = 1;
        else if ((s[i] == '*' || s[i] == '(') &&
                 (s[i + size - 1] == '*' || s[i + size - 1] == ')') &&
                 (dp[i + 1][i + size - 2] == 1)) {
          dp[i][i + size - 1] = 1;
        } else if (s[i + size - 1] == '*' && dp[i][i + size - 2] == 1) {
          dp[i][i + size - 1] = 1;
        } else if (s[i] == '(' || s[i] == '*') {
          for (int k = i + 1; k < i + size - 1; k++) {
            if (dp[i][k] && dp[k + 1][i + size - 1]) {
              dp[i][i + size - 1] = 1;
              break;
            }
          }
        }
      }
    }

    return dp[0][n - 1];
  }
};
