#include <iostream>

class B {
  public:
    B(const char* str = "\0") {
      std::cout << "Default constructor called" << std::endl;
    }

    B(const B& b) {
      std::cout << "Copy constructor called" << std::endl;
    }

    ~B() {
      std::cout << "Destructor called" << std::endl;
    }
};

int main() {
  // B ob = "copy me" can be translated to B ob = B("copy me");
  // A temporary object is created with B("copy me") and that
  // temporary object is copied to that object "ob"
  // But the modern compiler is smart and it does ->
  // B ob("copy me")
  //
  // Using argument - -fno-elide-constructors can be used to
  // disable copy elision
  B ob = "copy me";
  B oc = ob;
  return 0;
}
