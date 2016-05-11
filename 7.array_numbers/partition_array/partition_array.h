class Solution {
public:
  int partitionArray(vector<int> &nums, int k) {
    // write your code here
        
    int i = 0;
    int j = nums.size() - 1;
        
    while(i <= j)
    {
      while(i <= j)
      {
        if(nums[i] < k)
        {
          i ++;
        }
        else
        {
          break;
        }
      }
            
      while(i <= j)
      {
        if(nums[j] >= k)
        {
          j --;
        }
        else
        {
          break;
        }
      }
            
      if(i <= j)
      {
        int temp;
                
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
        
    return i;
  }
};
