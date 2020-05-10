#include <assert.h>
#include <math.h>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "test.h"

using namespace std;

void* thread_func(void* f) {
  return NULL;
}

int main() {
//  test();
//
//  std::cout << __func__ << std::endl;
//  std::cout << sin(3.1415) << std::endl;
//  pthread_t thread;
//  int ret = pthread_create(&thread, NULL, thread_func, NULL);
//  assert(ret == 0);
//  pthread_join(thread, NULL);

  cout << std::boolalpha << true << endl;
  cout << "test" << endl;

  test_t<int>(10);
  {
    std::fstream f("test");
    string data("hello world\n");
    if (f.is_open()) {
      cout << "open" << endl;
      f.write(data.c_str(), data.length()); 
    } else {
      cout << "not open" << endl;
    }
  }

  vector<int> vi;
  vi.push_back(1);
  for(auto i : vi) {
    cout << i << endl;
  }
  
              
  return 0;
}
