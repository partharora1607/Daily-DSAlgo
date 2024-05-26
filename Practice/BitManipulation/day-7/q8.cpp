class Solution {
public:
  vector<int> singleNumber(vector<int> &a) {
    int x = 0;
    for(int i = 0 ; i < a.size(); i++) x^= a[i];
    int rmsb = (x & -x);
    int x1 = 0 , x2 = 0;
    for(int i = 0 ; i < a.size(); i++){
      if((a[i] & rmsb) == 0) x1 ^= a[i];
      else x2 ^= a[i];
    }
    return {x1,x2};
  }
};