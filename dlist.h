#ifndef DLIST_H
#define DLIST_H

struct ListNode 
{
  /* define your list node type */
  int val;
  ListNode* next;
  ListNode* prev;
};

class DList
{
  public:
  DList();
  /* implement copy constructor, assignment, destructor if needed */
  ListNode* CreateNode(int value);
  void DeleteNode(ListNode* node);
  void add_to_front(int value);
  void add_to_back(int value);
  int first();
  int last();
  void remove(ListNode* node);
  ListNode* previous(ListNode* node);
  ListNode* next(ListNode* node);
  ListNode* search_value(int value);
  void printList();
  void deleteList();

  private:
  /* declare your data */
  int size;
  ListNode* head;
  ListNode* tail;
};

#endif
