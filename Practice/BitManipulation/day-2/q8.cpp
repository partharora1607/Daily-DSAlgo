Since the range of nums[i] is small, We can iterate through each bit and count the no. of subsets in which the bit will be set.
Suppose the bit is set in m elements in the array(I use m in the explanation in place of variable count in the code). Now, the subsets in which the bit will be set can be formed by
taking odd number of elements(1,3,5...etc.) out of the m elements that have the bit set in them. Thus the no. of subsets :

image

if the bit is not set, there are no subsets having the bit set and hence we ignore the contribution from that bit.

Those elemets that don't have the bit set can either be choosen or ignored (hence two choices for each of them). Hence the factor 2^(N-m) for them. (N denotes the size of array).

Now the contribution for each bit i is the no. of times it is set in the subsets multiplied by 2^i. Hence we add the contribution for each bit and add it to the ans.

In the code below, I have iterated through all the 32 bits( in C++, ints are of 32 bits) so that the code works for larger values of nums[i] which makes it O(Nlog(max(nums[i])), though in the que nums[i]<20 and hence we hardly need to iterate through 6 bits making it O(N).

Hope the explanation helps. Upvote if you liked it.

class Solution {
public:
    
    
    int subsetXORSum(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0; i<32; i++)
        {
  int mask = 1 << i;
  int count = 0;
  for (int j = 0; j < nums.size(); j++) {
    if (nums[j] & mask)
      count++;
  }
  if (count) {
    ans += mask * (1 << (count - 1)) * (1 << (nums.size() - count));
  }
        }
        return ans;
}
}
;