/**
 * Definition of ArrayReader:
 * 
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index, 
 *          // return -1 if index does not exist.
 *     }
 * };
 */
class Solution {
public:
  /**
   * @param reader: An instance of ArrayReader.
   * @param target: An integer
   * @return: An integer which is the first index of target.
   */
  int searchBigSortedArray(ArrayReader *reader, int target) {
    // write your code here
        
    int begin, end, ret;
        
    begin = 0;
    end = 1;
    ret = -1;
        
    if(reader->get(begin) != -1
       && reader->get(end) != -1)
    {
      while(1)
      {
        if(reader->get(begin) == target)
        {
          return begin;
        }
                
        if(reader->get(end) >= target
           || reader->get(end) == -1)
        {
          break;
        }
                
        begin = end;
        end *= 2;
      } 
    }
    else if(reader->get(end) == -1)
    {
      if(reader->get(begin)== target)
      {
        return begin;
      }
      else
      {
        return -1;
      }
    }
    else
    {
      return -1;
    }
        
    do_work(reader, begin, end, target, ret);
        
    return ret;
  }
    
  void do_work(ArrayReader *reader, int begin, int end,
               int target, int &ret)
  {
    int mid;
                    
    if(begin + 1 < end)
    {
      mid = (begin + end) >> 1;
                        
      if(reader->get(mid) > target)
      {
        do_work(reader, begin, mid, target, ret);
      }
      else if(reader->get(mid) < target)
      {
        do_work(reader, mid, end, target, ret);
      }
      else
      {   
        if(mid < ret || ret == -1)
        {
          ret = mid;
        }
        do_work(reader, begin, mid, target, ret);
      }
    }
    else
    {
      if(reader->get(begin) == target)
      {
        if(begin < ret || ret == -1)
        {
          ret = begin;
        }
      }
      else if(reader->get(end) == target)
      {
        if(end < ret || ret == -1)
        {
          ret = end;
        }
      }
      else
      {
        ret = -1;
      }
                        
      return;
    }
  }
};
