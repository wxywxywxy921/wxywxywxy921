class Solution {
public:
  /**
   * @param key: A String you should hash
   * @param HASH_SIZE: An integer
   * @return an integer
   */
  int hashCode(string key,int HASH_SIZE) {
    // write your code here
        
    int ret = 0;
    int i;
    long long temp = 0;
        
    for(i = 1; i < key.size(); i++)
    {
      temp += key[i];
      if(i != key.size() - 1) temp *= 33;
      temp %= HASH_SIZE;
    }
        
    return (int)temp;
  }
};
