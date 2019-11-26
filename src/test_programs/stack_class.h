#ifndef STACK_CLASS
#define STACK_CLASS

#include <deque>

template <typename T>
class Stack {
 public:
  void push(T value);
  T pop();

  size_t size() const;
  bool empty() const;

  // Below are the names of the functions
  typename std::deque<T>::iterator begin() const;
  typename std::deque<T>::iterator end() const;

 private:
  std::deque<T> elems;
};

// Push function pushes the value on top in the stack
template <typename T>
void Stack<T>::push(T value) {
  elems.push_front(value);
}

// Pop function returns the top element in the stack
template <typename T>
T Stack<T>::pop() {
  if (size() > 0) {
    T result = elems.front();
    elems.pop_front();
    return result;
  }
  return NULL;
}

// Size function returns the size of the Stack
template <typename T>
size_t Stack<T>::size() const {
  return elems.size();
}

// Empty function returns if the stack is empty
template <typename T>
bool Stack<T>::empty() const {
  return elems.empty();
}

template <typename T>
typename std::deque<T>::iterator Stack<T>::begin() const {
  return elems.begin();
}

template <typename T>
typename std::deque<T>::iterator Stack<T>::end() const {
  return elems.end();
}

#endif