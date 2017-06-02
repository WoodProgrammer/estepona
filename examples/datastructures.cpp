#include<iostream>
using namespace std;
struct user{
  int user_id;
  string user_name;
};


int main(){
  user user_container;
  user *user_container_pointer;
  user_container_pointer=&user_container;
  int x  = user_container_pointer->user_id = 90;
  std::cout << x << '\n';
}
