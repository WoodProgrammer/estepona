#include<iostream>
using namespace std;



int main(){
int *a ;
int x = 10 ;
a = &x;

int **b;

b = &a;//pointers of pointers
std::cout << &b<< '\n';
std::cout << &a<< '\n';
std::cout << &x<< '\n';

}
