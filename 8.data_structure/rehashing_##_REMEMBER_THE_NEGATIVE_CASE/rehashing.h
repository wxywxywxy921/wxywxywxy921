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
   * @param hashTable: A list of The first node of linked list
   * @return: A list of The first node of linked list which have twice size
   */    
  vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
    // write your code here
        
    int size = hashTable.size();
    int i;
    ListNode *temp, *backup;
    vector<ListNode *> ret(size* 2, NULL);
        
    if(!size)
    {
      return ret;
    }
        
    for(i = 0; i < hashTable.size(); i++)
    {
      temp = hashTable[i];
            
      while(temp)
      {
        backup = temp->next;
        insertHash(temp, ret);
        temp = backup;
      }
    }
        
    return ret;
  }
    
  void insertHash(ListNode *node, vector<ListNode*> &hash)
  {
    int idx;
    ListNode *temp;
        
    if(node->val > 0)
    {
      idx = node->val % hash.size();
    }
    else
    {
      idx = (hash.size() + node->val) % hash.size();
    }
        
    if(!hash[idx])
    {
      hash[idx] = node;
    }
    else
    {
      ListNode *temp = hash[idx];
            
      while(temp->next)
      {
        temp = temp->next;
      }
            
      temp->next = node;
    }
        
    node->next = NULL;
    return;
  }
};
