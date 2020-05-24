#include <iostream>
#include <exception>
#include <cxxabi.h>

using namespace std;

void g() /* noexcept */ {
  throw 1;
}

void handle_eptr(std::exception_ptr eptr) // passing by value is ok
{
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
    } catch (...) {
      cout << "caught a exception by handle_eptr" << endl;
    }
}

class A {
public:
  ~A() {
    cout << "a dtor" << endl;
  }
};

int main() {
//   std::exception_ptr eptr;
//  
//  try {
//    g();
//  } catch (...) {
//    cout << "caught a exception" << endl;
//    
//    eptr = std::current_exception();
////    std::nested_exception();
//    std::uncaught_exceptions();
//  }
//   
//  handle_eptr(eptr);
  
  try {
    A a;
    throw 1;
  } catch (int) {
    cout << "caught a exception" << endl;
  }

  return 0;
}
