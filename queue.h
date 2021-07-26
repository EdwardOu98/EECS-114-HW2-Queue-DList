#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
  public:
  Queue();
  /* implement copy constructor, assignment, destructor if needed */
  void CreateQueue(int n);
  void deleteQueue();
  void enqueue(float value);
  float dequeue();
  bool checkEmpty();
  bool checkFull();
  void printQueue();

  private:
  /* declare your data */
  int size;
  float* list;
  int head;
  int tail; 
};


#endif
