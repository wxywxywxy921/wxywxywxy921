class Solution {
public:
  /*
   * @param n: An integer
   * @return: True or false
   */
  bool checkPowerOf2(int n) {
    // write your code here
        
    int found_one = 0;
        
    while(n)
    {
      if(n&0x1)
      {
        found_one ++;
      }
            
      n >>= 1;
            
      if(found_one && n)
        return false;
    }
        
    if(found_one)
      return true;
    else
      return false;
  }
};
