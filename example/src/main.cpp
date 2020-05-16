#include <iostream>
#include <exception>

using namespace std;

void g() noexcept {
  throw 1;
}

int main() {
  class A;
  
  try {
    g();
  } catch (...) {
    cout << "caught a exception" << endl;
  }

  return 0;
}
