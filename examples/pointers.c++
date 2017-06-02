#include<iostream>



void pointed_app(int * a){
  *a= *a+10;
}

int main(){
  int numbers[11]={1,2,3,4,5,123,123,123,213};

  int * p;
  //each pointer is a array and each array is a pointer...
  p = numbers;
  //std::cout << &p[1] << '\n';
  //p = &numbers[0];//p is a pointer of nubmer[0]
  //*p = 123;
  *(p+2)=3435;
  std::cout << p[2] << '\n';

  //std::cerr << numbers[0] << '\n';
/*
  int * x;
  int y = 99;
  x = &y;
  pointed_app(x);
  std::cout << y << '\n';

 int * first,* second;
  int second_value=12;
  int first_value=10;
  first = &first_value;
  second = &second_value;
  * second = * first;
  std::cout << second_value << '\n';
  ------simple example----

*/
}
