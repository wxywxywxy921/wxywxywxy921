class Solution{
public:
  /**
   * @param nums: A list of integer which is 0, 1 or 2 
   * @return: nothing
   */    
  void sortColors(vector<int> &nums) {
    // write your code here
        
    int i, j, k;
        
    i = j = 0;
    k = nums.size() - 1;
        
    if(!nums.size())
      return;
        
    while(1)
    {
      if(nums[i] == 0)
      {
        nums[i] = nums[j];
        nums[j] = 0;
        j ++;
        i ++;
      }
      else if(nums[i] == 2)
      {
        nums[i] = nums[k];
        nums[k] = 2;
        k --;
      }
      else
      {
        i ++;
      }
            
      if(i > k)
      {
        return;
      }
    }
  }
};
