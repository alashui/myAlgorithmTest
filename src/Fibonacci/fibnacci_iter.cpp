#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

//implement of algorithm
unsigned long fibnacci(unsigned long &n) 
{
	unsigned long fib_n(0),fib_n_1(1);
	while(n--)
	{
		fib_n = fib_n +fib_n_1;
		fib_n_1 = fib_n - fib_n_1;
	}
	return fib_n;
}

int main(int argc, char** argv)
{	
    if ( argc != 2 )
    {
        cout<<"please input parameter!"<<endl;
        return 1;
    }
	//variables use to compute the time of algorithm spend
	struct timespec tpstart;
    struct timespec tpend;	
    ////
    
    //data and variables input to algorithm
    string string_temp(argv[1]);
    unsigned long n = atoi(string_temp.c_str());
    unsigned long result(0);
    if ( n < 0 )
    {
        cout<<"please input a positive integer!"<<endl;
        return 1;
    }
    ////
    
    //run myalgorithm() and compute the time of that spend
    clock_gettime(CLOCK_REALTIME, &tpstart);
    
    result=fibnacci(n); //run myalgorithm() 
    
    clock_gettime(CLOCK_REALTIME, &tpend);
    ////
    
    //display the results
    double timedif = (tpend.tv_sec-tpstart.tv_sec)+(tpend.tv_nsec-tpstart.tv_nsec)/1000000000.0;
    printf("clock_gettime time: %.12f\n", timedif);
    
    cout <<"result: "<< result<<endl;
			
	////
}


