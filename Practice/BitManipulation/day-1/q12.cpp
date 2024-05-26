class Solution {
public:
  bool check10x(int a) {
    string s = bitset<8>(a).to_string();
    if (s.substr(0, 2) == "10")
      return true;
    else
      return false;
  }

  bool validUtf8(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
      int a = v[i];
      string s = bitset<8>(a).to_string();
      int cnt = 0;
      for (int i = 0; i < 8; i++) {
        if (s[i] == '1')
          cnt++;
        else
          break;
      }
      if (cnt == 0) {
        continue;
      } else if (cnt == 2) {
        bool f = check10x(v[i + 1]);
        if (f == 0)
          return false;
        i++;
      } else if (cnt == 3) {
        bool f = (check10x(v[i + 1]) && check10x(v[i + 2]));
        if (f == 0)
          return false;
        i += 2;
      } else if (cnt == 4) {
        bool f =
            (check10x(v[i + 1]) && check10x(v[i + 2]) && check10x(v[i + 3]));
        if (f == 0)
          return false;
        i += 3;
      }
    }
    return true;
  }
};