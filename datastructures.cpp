#include<iostream>
using namespace std;
struct user{
  int user_id;
  string user_name;
} user_container;
int main(){
  user_container.user_name = "WoodProgrammer";
  std::cout << user_container.user_name << '\n';


}
