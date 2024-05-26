class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    int sum_sq = (n * (n + 1) * (2 * n + 1)) / 6;
    int curr_sum = 0;
    int curr_sum_sq = 0;
    for (int i = 0; i < n; i++) {
      curr_sum += nums[i];
      curr_sum_sq += nums[i] * 1ll * nums[i];
    }
    int duplicate_no =
        ((sum - curr_sum) + (sum_sq - curr_sum_sq) / (sum - curr_sum)) / 2;
    int missing_no = duplicate_no - curr_sum + sum;
    return {duplicate_no, missing_no};
  }
};