class Solution {
public:
  vector<int> findErrorNums(vector<int> &a) {
    int n = a.size();
    int sum = (n * (n + 1)) / 2;
    int sq_sum = (n * (n + 1) * (2 * n + 1)) / 6;

    int curr_sum = 0, curr_sq_sum = 0;
    for (int i = 0; i < a.size(); i++) {
      curr_sum += a[i];
      curr_sq_sum = a[i] * 1ll * a[i];
    }

    int duplicate_no = ((curr_sum - sum) + (curr_sq_sum - sq_sum))
  }
};