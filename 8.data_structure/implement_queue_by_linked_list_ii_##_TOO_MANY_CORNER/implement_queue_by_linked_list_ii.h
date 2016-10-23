struct Node
{
  int val;
  Node *next;
    
Node(int a): val(a), next(NULL){};
};

class Dequeue {
    
  Node *head;
  Node *curr;
    
public:    
  Dequeue() {
    // do initialize if necessary
        
    head = curr = NULL;
  }

  void push_front(int item) {
    // Write your code here
        
    Node *temp = new Node(item);
        
    temp->next = head;
    head = temp;
        
    if(!curr)
      curr = head;
  }

  void push_back(int item) {
    // Write your code here
        
    Node *temp = new Node(item);
        
    if(!curr)
    {
      head = curr = temp;
    }
    else
    {
      curr->next = temp;
      curr = temp;
    }
  }

  int pop_front() {
    // Write your code here
    int ret = 0;
    Node *temp = head;
        
    if(head)
    {
      ret = head->val;
            
      if(head->next)
      {
        head = head->next;
      }
      else
      {
        head = curr = NULL;
      }
            
      delete[] temp;
    }
        
    return ret;
  }

  int pop_back() {
    // Write your code here
        
    int ret = 0;
    Node *temp = curr;
        
    if(curr == head)
    {
      ret = curr->val;
      curr = head = NULL;
      return ret;
    }
        
    if(curr)
    {
      ret = curr->val;
      curr = head;
            
      while(curr->next &&curr->next != temp)
      {
        curr = curr->next;
      }
      curr->next = NULL;
      delete[] temp;
    }
        
    return ret;
  }
};
	
