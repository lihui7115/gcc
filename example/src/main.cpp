#include <iostream>
#include <exception>

using namespace std;

int main() {
  try {
    throw 1;
  } catch (...) {
    cout << "caught a exception" << endl;
  }

  return 0;
}
