#include<iostream>
using namespace std;

namespace git_hooks{
  string user_name;
  string userName(){

    return "WoodProgrammer";
  }

}


int my_func(){

  return 12*23;
}
int my_func(int x){
  return 12*x;

}
template <class SomeType>
SomeType sum (SomeType a,SomeType b){
  return a+b;
}
//OVERLOADING&TEMPLATES

int main(){
  string user_name="WoodProgrammer";
  using git_hooks::user_name;//Nice Error :)) 
  git_hooks::user_name = "WoodProgrammer";


/*
  std::cout<<git_hooks::userName();
  std::cout << git_hooks::user_name << '\n';
  std::cout << my_func(3) << '\n';
  std::cout << sum<int>(10,20) << '\n';
*/



}
