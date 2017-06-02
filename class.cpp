#include<iostream>
using namespace std;
class Mainteiners{
  int x;
  int y;
public:

    void set_values (int,int);
    int get_values ();
    void HelloWorld(){
      for (size_t i = 0; i < y; i++) {
        for (size_t i = 0; i < x; i++) {
          std::cout << "HelloWorld";
        }
      }

    }
};


void Mainteiners::set_values(int k,int c){
  x = k;
  y = c;
}
int Mainteiners::get_values(){
  return x;
}

int main(){
  Mainteiners t ;
  Mainteiners *c;
  c = &t;
  t.set_values(10,10);
  //t.HelloWorld();
  std::cout <<c->get_values();
  /*
    c->x = 100;
    */

  // '.' kullanimi obj'dedir. std::cout <<  t.x << '\n';



}
