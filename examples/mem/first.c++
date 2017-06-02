#include<iostream>
using namespace std;

void create_own_arr(int *arr_pointer,int size_of_arr){
  arr_pointer = new (nothrow) int [size_of_arr];
  if(arr_pointer == nullptr){
    std::cerr << "NULL POINTER EXCEPTION" << '\n';
  }

  else{
    for (int i = 0; i < size_of_arr; i++) {
      *(arr_pointer+i)=i;
    }
  }

  for (int i = 0; i < size_of_arr; i++) {
    std::cout <<*(arr_pointer+i) << '\n';
  }

}


int main(int argc, char const *argv[]) {
  int * parr;
  create_own_arr(parr,100);
/*
  int *foo;
  foo = new (nothrow) int [23];
  foo[1]=123;
  std::cout << foo[0] << '\n';
  if (foo == nullptr){
    std::cerr << "ERROR" << '\n';

  }
  return 0;*/
}
