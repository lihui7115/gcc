#include <iostream>
#include <string>

#include <filesystem>

using namespace std;

int main() {
//  string s = "hello";
//
//  cout << s << endl;
  
  
  // bug https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95048
  std::filesystem::path p = L"测试";


  return 0;
}
