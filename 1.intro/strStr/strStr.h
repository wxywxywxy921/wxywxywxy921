#include <stdio.h>
#include <string.h>

class Solution {
public:
  /**
   * Returns a index to the first occurrence of target in source,
   * or -1  if target is not part of source.
   * @param source string to be scanned.
   * @param target string containing the sequence of characters to match.
   */
  int strStr(const char *source, const char *target) {
    // write your code here
        
    int i, j;
    int src_len;
    int tar_len;
        
    if(NULL == source)
    {
      return -1;
    }
        
    if(NULL == target)
    {
      return -1;
    }
        
    src_len = strlen(source);
    tar_len = strlen(target);
        
    if(!tar_len)
    {
      return 0;
    }
        
    if(!src_len)
    {
      return -1;
    }
        
    if(!strcmp(source, target))
    {
      return 0;
    }
     
// [xywu] remember the "+ 1"   
    for(i = 0; i < (src_len - tar_len + 1); i++)
    {
      for(j = 0; j < tar_len; j++)
      {
        if(source[i + j] != target[j])
        {
          break;
        }
      }
            
      if(j == tar_len)
      {
        return 1;
      }
    }
    return -1;
  }
};
