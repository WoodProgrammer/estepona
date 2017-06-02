#include<iostream>



void pointed_app(int * a){
  *a= *a+10;
}

int main(){
  int numbers[11];
  int * p;

  int * x;
  int y = 99;
  x = &y;
  pointed_app(x);
  std::cout << y << '\n';

/*  int * first,* second;
  int second_value=12;
  int first_value=10;
  first = &first_value;
  second = &second_value;
  * second = * first;
  std::cout << second_value << '\n';
  ------simple example----

*/
}
