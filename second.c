#include<stdio.h>
#include<omp.h>


int main()
{
	#pragma omp parallel
	{
		int ID = 0;
		printf("hello world(%d)",ID);
		printf("world(%d)\n",ID);
	}
	return 0;

}
