/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
  /**
   * @param lists: a list of ListNode
   * @return: The head of one sorted list.
   */
     
  ListNode *mergeTwoLists(ListNode *left, ListNode *right)
  {
    ListNode *dummy = new ListNode;
    ListNode *dummy_curr = dummy;
    ListNode *left_curr = left;
    ListNode *right_curr = right;
    ListNode *ret;
        
    while(left_curr != NULL && right_curr != NULL)
    {
      if(left_curr->val < right_curr->val)
      {
        dummy_curr->next = left_curr;
        dummy_curr = dummy_curr->next;
        left_curr = left_curr->next;
      }
      else
      {
        dummy_curr->next = right_curr;
        dummy_curr = dummy_curr->next;
        right_curr = right_curr->next;
      }
    }
        
    if(left_curr == NULL)
    {
      dummy_curr->next = right_curr;
    }
    else
    {
      dummy_curr->next = left_curr;
    }
        
    ret = dummy->next;
    delete[] dummy;
    return ret;
  }
     
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // write your code here
        
    if(lists.size() == 0)
      return NULL;
            
    ListNode *ret;
        
    ret = mergeKLists_helper(lists, 0, lists.size() - 1);
        
    return ret;
  }
    
  ListNode *mergeKLists_helper(vector<ListNode *> &lists, int begin, int end) 
  {
    ListNode *left, *right, *ret;
    int mid;
        
    if(begin > end)
      return NULL;
            
    if(begin == end)
      return lists[begin];
        
    if(begin + 1 < end)
    {
      mid = (begin + end) / 2;
            
      left = mergeKLists_helper(lists, begin, mid);
      right = mergeKLists_helper(lists, mid + 1, end);
      ret = mergeTwoLists(left, right);
    }
    else
    {
      ret = mergeTwoLists(lists[begin], lists[end]);
    }
        
    return ret;
  }
};


