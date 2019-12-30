#include <cstring>
#include <iostream>
#include <memory>

using std::unique_ptr;

template <typename T>
class SmartPointer {
  public:

    // Constructor
    explicit SmartPointer(T* memory);

    // Copy constuctory 
    SmartPointer(const SmartPointer& other);

    // Assignment operator overload
    // Causes this SmartPointer to stop pointing to the resource it's currently
    // managing and to share the resource held by another SmartPointer. If the
    // smart pointer was the last pointer to its resource, it deletes it.
    SmartPointer& operator=(const SmartPointer& other);

    // Destructor
    ~SmartPointer();

    T& operator*() const;
    T* operator->() const;

    T* get() const;

    std::size_t getShareCount();
    void reset(T* newRes);
  
  private:
    struct Intermediary{
      T* resource;
      std::size_t refCount;
    };
    Intermediary* data;

    // detach would detach the SmartPointer from the shared intermediary
    // and clean up the memory if it was the last pointer to the shared
    // resource
    void detach();
    void attach(Intermediary* other);
};

template <typename T>
SmartPointer<T>::SmartPointer(T *memory) {
  data = new Intermediary;
  data->resource = memory;
  data->refCount = 1;
}

template <typename T>
SmartPointer<T>::~SmartPointer() {
  detach();
}

template <typename T>
T& SmartPointer<T>::operator*() const {
  return *data->resource;
}

template <typename T>
T* SmartPointer<T>::operator->() const {
  return data->resource;
}

template <typename T>
void SmartPointer<T>::detach() {
  --data->refCount;
  if (data->refCount == 0) {
    delete data->resource;
    delete data;
  }
}

template <typename T>
void SmartPointer<T>::attach(Intermediary* to) {
  data = to;
  ++data->refCount;
}

// Implementation of copy constuctor
template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer& other) {
  attach(other.data);
}

// Implementation of assignment operator
template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& other) {
  if (this != &other) {
    detach();
    attach(other.data);
  }
  return *this;
}

template <typename T>
T* SmartPointer<T>::get() const {
  return data->resource;
}

template <typename T>
std::size_t SmartPointer<T>::getShareCount() {
  return data->refCount;
}

template <typename T>
void SmartPointer<T>::reset(T *newRes) {
  SmartPointer::detach();
  // Line below will not work because data variable is already defined
  // Intermediary* data;
  data = new Intermediary;
  data->refCount = 1;
  data->resource = newRes;
}

// Function attempts to take a unique pointer by value (reference) and change
// its value
template <typename UniquePointerType>
void changeUniquePointerLocation(unique_ptr<UniquePointerType> &ptr) {
  UniquePointerType newVar = new UniquePointerType;
  ptr = newVar;
}

int main() {
  // int mainData = 100;
  // int *intPtr = &mainData;
  // SmartPointer<int> smartIntPtr1(intPtr);
  // SmartPointer<int> smartIntPtr2(smartIntPtr1);
  // std::cout << "Num references by Ptr 1: " << smartIntPtr1.getShareCount()
  //           << std::endl;
  // std::cout << "Num references by Ptr 2: " << smartIntPtr1.getShareCount()
  //           << std::endl;
  return 0;
}
