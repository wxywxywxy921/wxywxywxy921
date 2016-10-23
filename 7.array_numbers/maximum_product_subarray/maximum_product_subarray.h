class Solution {
public:
  /**
   * @param nums: a vector of integers
   * @return: an integer
   */
  int maxProduct(vector<int>& nums) {
    // write your code here
        
    int local_max, local_min, global_max, i;
    int local_max_temp, local_min_temp; 
        
    global_max = -999999;
        
    for( i = 0; i < nums.size(); i++)
    {
      if(!i)
      {
        local_max = local_min = nums[0];
      }
      else
      {
        local_max_temp = max(max(nums[i] * local_max, nums[i] * local_min), nums[i]); // IMPORTANT TO HAVE TEMP
        local_min_temp = min(min(nums[i] * local_max, nums[i] * local_min), nums[i]);
                
        local_max = local_max_temp;
        local_min = local_min_temp;
      }
            
      if(local_max > global_max)
      {
        global_max = local_max;
      }
    }
        
    return global_max;
  }
};
