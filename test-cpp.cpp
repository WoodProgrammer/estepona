#include <ctime>
#include <iostream>

void pause(int dur);

int main()
{
std::cout<<"Pausing for 2 secund... ";
pause(2);
std::cout<<"DONE\n";

return 0;
}

void pause(int dur)
{
int temp = time(NULL) + dur;

while(temp > time(NULL));
}
