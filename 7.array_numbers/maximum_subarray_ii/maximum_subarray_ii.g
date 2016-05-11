class Solution {
  public:
  /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
    // write your code here
    
    if(nums.size() == 0)
      return 0;
    
    vector<int> sums;
    vector<int> left_max_sums;
    vector<int> right_max_sums(nums.size(), 0);
    
    int i, sum = 0;
    
    for(i = 0; i < nums.size(); i++)
      {
        sum += nums[i];
        sums.push_back(sum);
      }
    
    // [1] from left to right, find the biggest sum
    int min_sum = 0;
    for(i = 0; i < nums.size(); i++)
      {
        if(i == 0)
          {
            left_max_sums.push_back(sums[0]);
          }
        else
          {
            if((sums[i] - min_sum) > left_max_sums[i - 1])
              {
                left_max_sums.push_back(sums[i] - min_sum);
              }
            else
              {
                left_max_sums.push_back(left_max_sums[i - 1]);
              }
          }
        
        if(sums[i] < min_sum)
          {
            min_sum = sums[i];
          }
      }
    
    // [2] from right to left, find the biggest sum
    int max_sum = sums[sums.size() - 1];
    for(i = (nums.size() - 1); i >= 0; i--)
      {
        if(i == (nums.size() - 1))
          {
            right_max_sums[i] = nums[i];
          }
        else
          {
            if((max_sum - sums[i]) > right_max_sums[i + 1])
              {
                right_max_sums[i] = max_sum - sums[i];
              }
            else
              {
                right_max_sums[i] = right_max_sums[i + 1];
              }
          }
        
        
        if(sums[i] > max_sum)
          {
            max_sum = sums[i];
          }
      }
    
    // [3] find the largest tot sum
    int ret = -99999999; // IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!
    for(i = 0; i < nums.size() - 1; i++)
      {
        if((left_max_sums[i] + right_max_sums[i + 1]) > ret)
          {
            ret = left_max_sums[i] + right_max_sums[i + 1];
          }
      }
    
    return ret;
  }
};
