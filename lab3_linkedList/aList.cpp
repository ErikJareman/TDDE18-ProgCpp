#include <utility>
#include <iostream>

#include "aList.h"

struct aList::Node {
  int m_value;
  Node* m_next;
  
  Node(const int value)
    : m_value(value)
    , m_next(nullptr)
  {}
};

aList::aList() 
  : m_head(nullptr)
{}

aList::~aList() 
{ 
  clean();
}

aList::aList(const aList &other)
  : m_head(nullptr)
{
  std::cout << "copy constructor" << std::endl;
  deepCopy(other, *this);
}

aList& aList::operator=(const aList& other)
{
  std::cout << "copy assigment\n";
  if (&other == this) {
    // to self
    return *this;
  }

  clean();

  deepCopy(other, *this);
  return *this;
}

aList::aList(aList &&other)
  : m_head(other.m_head)
{
  std::cout << "move constructor\n";
  other.m_head = nullptr;
}

aList& aList::operator=(aList&& other)
{
  std::cout << "move assignment\n";
  if (&other == this) {
    // to self
    return *this;
  }

  clean();

  m_head = other.m_head;
  other.m_head = nullptr;
  return *this;
}

aList::Node *aList::getRecursive(const int index, Node *node) const
{
  if ((index == 1) || (node == nullptr)){
    return node;
  } else {
    return getRecursive(index-1, node->m_next);
  }
}

void aList::deepCopy(const aList &src, aList &dest) const
{
  std::cout << "  performing deep copy\n";
  Node *s_node = src.m_head;
  if (s_node) {
    dest.m_head = new Node(s_node->m_value);

    Node *d_node = dest.m_head;
    s_node = s_node->m_next;
    while(s_node) {
      d_node->m_next = new Node(s_node->m_value);
      d_node = d_node->m_next;
      s_node = s_node->m_next;
    }
  }  
}

void aList::insert(const int value)
{
  Node *i_node = new Node(value);
  if (m_head == nullptr) {
    // empty
    m_head = i_node;
  } else {
    Node *node = m_head;
    Node *prev = nullptr;
    while(node) {
      if (value < node->m_value) {
	      break;
      }
      prev = node;
      node = node->m_next;
    }
    
    if (prev == nullptr) {
      // first
      i_node->m_next = m_head;
      m_head = i_node;
    } else if (node) {
      // middle
      prev->m_next = i_node;
      i_node->m_next = node;
    } else {
      // last
      prev->m_next = i_node;
    }
  }
}

void aList::remove(const int value)
{
  if (m_head == nullptr) {
    std::cout << "Missing value " << value << " (empty list)\n";
    return;
  }

  Node *node = m_head;
  Node *prev = nullptr;
  while(node) {
    if (node->m_value == value) {
      break;
    }
    prev = node;
    node = node->m_next;
  }

  if (node == nullptr) {
    std::cout << "Missing value " << value << std::endl;
    return;
  }

  if (prev) {
    // middle, last
    prev->m_next = node->m_next;
  } else {
    // first
    m_head = node->m_next;
  }
  delete node;
}

void aList::removeAt(const int index)
{
  if (m_head == nullptr) {
    std::cout << "Invalid index " << index << " (empty list)\n";
    return;
  }

  Node *r_node;
  if (index == 1) {
    // frist
    r_node = m_head;
    m_head = r_node->m_next;
  } else {
    // middle, last
    Node *prev = getRecursive(index-1, m_head);
    if (prev) {
      r_node = prev->m_next;
      prev->m_next = r_node->m_next;
    } else {
      std::cout << "Invalid index " << index << std::endl;
      return;
    }
  }
  delete r_node;
}

int aList::getAt(const int index) const
{
  Node *node = getRecursive(index, m_head);
  if (node == nullptr) {
    std::cout << "Invalid index " << index << std::endl;
    return -42;
  }
  return node->m_value;
}

void aList::clean()
{
  while(m_head) {
    Node *node = m_head;
    m_head = m_head->m_next;
    delete node;
  }
  m_head = nullptr;
}

void aList::print() const
{
  if (m_head == nullptr) {
    std::cout << "Empty list\n";
    return;
  }

  int ix = 1;
  Node *node = m_head;
  while(node) {
    std::cout << "index " << ix++ << ": " 
	      << node->m_value << std::endl;
    node = node->m_next;
  }
}
bool aList::isEmpty() const
{
  return (m_head == nullptr);
}
