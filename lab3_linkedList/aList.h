
//TODO: Header guards are missing. 
// FIXED

//TODO: Functions which are not to change the calling object are to be declared
//as const. 
// FIXED

//Comment: Your code is very good! Nice job!

#ifndef ALIST_H
#define ALIST_H


class aList
{
public:
  aList();
  ~aList();

  aList(const aList &other);
  aList& operator=(const aList& other);

  aList(aList &&other);
  aList& operator=(aList&& other);

  void insert(const int value);

  void remove(const int value);

  void removeAt(const int index);

  int getAt(const int index) const;

  void clean();

  void print() const;

  bool isEmpty() const;

private:
  struct Node;

  Node *getRecursive(const int index, Node *node) const;

  void deepCopy(const aList &src, aList &dest) const;

  Node *m_head;
};

#endif //ALIST.H
