#include <iostream>
#include <chrono>
#include <thread> 
#include <time.h>
using namespace std;
using namespace std::chrono;

char * read_html_doc(){

    FILE * pFile;
    long lSize;
    char * buffer;
    size_t result;

    pFile = fopen ( "second.c" , "rb" );

    fseek (pFile , 0 , SEEK_END);   
    lSize = ftell (pFile);
    rewind (pFile);


    buffer = (char*) malloc (sizeof(char)*lSize);

    result = fread (buffer,1,lSize,pFile);
    if (result != lSize) {fputs ("OKUMA HATASI :: read_error .. ",stderr); exit (3);}
    return buffer;
}



int main()
{

    char * data;  
    data = read_html_doc();
    int i = 0;
    while(i<=3){
        cout << "------TESTING-------\n";
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        read_html_doc();
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>( t2 - t1 ).count();
        cout<<duration<<"\n";

        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        cout<<data<<"\n";
        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>( t4 - t3 ).count();
        cout<<duration2;
        
        cout << "----------\n";
        i += 1;
    }


    return 0;
}