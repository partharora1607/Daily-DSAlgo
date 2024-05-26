class Solution {
public:
  bool hasAlternatingBits(int n) {
    string s = bitset<32>(n).to_string();
    int i = 0;
    for (; i < n; i++) {
      if (s[i] == '1')
        break;
    }
    cout << i << "\n";
    // for (; i < n - 1; i++) {
    //   if (s[i] == '1' && s[i + 1] == '1')
    //     return false;
    //   else if (s[i] == '0' && s[i + 1] == '0')
    //     return false;
    // }
    // return true;
  }
};