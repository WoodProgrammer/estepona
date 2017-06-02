#include<iostream>
#include<string.h>
using namespace std;
const double main_const = 12.23231232312324;

void my_first_string_func(){
  string string_for {"HelloFirstString"};
  for (int i = 0; i < 25; i++) {
    std::cout << string_for[i] << '\n';
  }

}

int main(){
  int x (110);
  //int y {2};
  auto y = x;
  std::cout << x << '\n';
  cout << y << '\n';
  my_first_string_func();
  cout << main_const;

}
