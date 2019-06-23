#include<stdio.h>
#include<omp.h>
#include<time.h>

#define NUM_THREADS 1

static long num_steps = 100000;
double step;

		
int main()
{
	double total_time=1.0;
	
	clock_t start,end;
	start = clock();
	double pi=0;
	
	int nthreads;
	step = 1.0/(double)num_steps;
	
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel
	{
		
		int ID = omp_get_thread_num();
		int num_threads= omp_get_num_threads();		
		double x,sum;
		
		if(ID==0) nthreads=num_threads;

		for(int i=ID;i<num_steps;i+=num_threads)
			{
				x = (i+0.5)*step;
				sum+=(4/(1+x*x));
			}
		#pragma omp critical
			pi+=sum*step;
	}
	
	printf(" %lf\n",pi);		
	end = clock();
	
	total_time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("run time: %lf wuth no.of threads: %d\n",total_time,nthreads);
	
	return 0;
}
