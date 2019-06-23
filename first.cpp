#include<iostream>
#include<omp.h>

using namespace std;

int main()
{
	#pragma omp parallel
	{
		int ID = 0;
		cout<<"just a test ("<<ID<<")"<<endl;

	}
	return 0;

}