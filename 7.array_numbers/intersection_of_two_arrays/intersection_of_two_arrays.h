class Solution {
public:
  /**
   * @param nums1 an integer array
   * @param nums2 an integer array
   * @return an integer array
   */
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // Write your code here
        
    int i = 0, j = 0;
    vector<int> ret;
        
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
        
    while(i < nums1.size() && j < nums2.size())
    {
      if(nums1[i] == nums2[j])
      {
        if(ret.size() && nums1[i] != ret[ret.size() - 1])
        {
          ret.push_back(nums1[i]);
        }
        else if(!ret.size())
        {
          ret.push_back(nums1[i]);
        }
                
        i ++;                      // [xywu] forgot this at the beginning
        j ++;
      }
      else if(nums1[i] < nums2[j])
      {
        i ++;
      }
      else
      {
        j ++;
      }
    }
        
    return ret;
  }
};
