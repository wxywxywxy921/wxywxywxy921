class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return: An integer indicate the value of maximum difference between two
   *          Subarrays
   */
  int maxDiffSubArrays(vector<int> nums) {
    // write your code here
        
    if(!nums.size() || nums.size() == 1)
    {
      return 0;
    }
        
    vector<int> left_max(nums.size());
    vector<int> left_min(nums.size());
    vector<int> right_max(nums.size());
    vector<int> right_min(nums.size());
    vector<int> sums(nums.size());
        
    int i = 0;
    int local_max, local_min;
        
    for(i = 0; i < nums.size(); i++)
    {
      if(!i)
      {
        sums[i] = nums[i];
      }
      else
      {
        sums[i] = sums[i - 1] + nums[i];
      }
    }
        
    local_max = 0;
    local_min = 0;
        
    for(i = 0; i < nums.size(); i++)
    {
      if(i == 0)
      {
        left_max[i] = nums[i];
        left_min[i] = nums[i];
      }
      else
      {
        left_max[i] = max(left_max[i - 1], sums[i] - local_min);
        left_min[i] = min(left_min[i - 1], sums[i] - local_max);
      }
            
      //printf("left_max=%d\n", left_min[i]);
            
      if(sums[i] > local_max)
        local_max = sums[i];
                
      if(sums[i] < local_min)
        local_min = sums[i];
            
    }
        
    local_max = sums[nums.size() - 1];
    local_min = sums[nums.size() - 1];
        
    for(i = nums.size() - 1; i >= 0; i--)
    {
      if(i == nums.size() - 1)
      {
        right_max[i] = nums[i];
        right_min[i] = nums[i];
      }
      else
      {
        right_max[i] = max(right_max[i + 1], local_max - sums[i]);
        right_min[i] = min(right_min[i + 1], local_min - sums[i]);
      }
            
      if(sums[i] > local_max)
        local_max = sums[i];
                
      if(sums[i] < local_min)
        local_min = sums[i];
    }
        
    int ret = -999999;
        
    for(i = 0; i < nums.size() - 1; i++)
    {
      if(abs(right_max[i] - left_min[i]) > ret)
      {
        ret = abs(right_max[i] - left_min[i]);
      }
      if(abs(left_max[i] - right_min[i]) > ret)       // REMEMBER RIGHT ALWAYS + 1
      {
        ret = abs(left_max[i] - right_min[i]);
      }
    }
        
    return ret;
  }
};
