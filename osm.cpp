
#include "osm.h"
#include <time.h>
#include <sys/time.h>
#include <math.h>

#define FAIL -1;

void does_nothing(){}

double osm_function_time(unsigned int iterations)
{
	if (iterations < 1)
	{
		return FAIL;
	}
	timeval start, end;
	gettimeofday(&start, NULL);
    unsigned int num_of_iterations = ceil(iterations / 5);
    for (unsigned int i = 0; i < num_of_iterations; ++i)
	{
		does_nothing();
		does_nothing();
		does_nothing();
		does_nothing();
		does_nothing();
	}
	gettimeofday(&end, NULL);
	return (double) (((end.tv_sec - start.tv_sec) * 10000000000) +
					 ((end.tv_usec - start.tv_usec) * 1000)) / (num_of_iterations * 5);
}

double osm_operation_time(unsigned int iterations)
{
	if (iterations < 1)
	{
		return FAIL;
	}
	timeval start, end;
	gettimeofday(&start, NULL);
	int time_check_operation1 = 0;
    int time_check_operation2 = 0;
    int time_check_operation3 = 0;
    int time_check_operation4 = 0;
    int time_check_operation5 = 0;
    unsigned int num_of_iterations = ceil(iterations / 5);
	for (unsigned int i = 0; i < num_of_iterations; ++i)
	{
		time_check_operation1++;
		time_check_operation2++;
		time_check_operation3++;
		time_check_operation4++;
		time_check_operation5++;
	}
	gettimeofday(&end, NULL);
	return (double) (((end.tv_sec - start.tv_sec) * 10000000000) +
					 ((end.tv_usec - start.tv_usec) * 1000)) / (num_of_iterations * 5);
}

double osm_syscall_time(unsigned int iterations)
{
	if (iterations < 1)
	{
		return FAIL;
	}
	timeval start, end;
	gettimeofday(&start, NULL);
    unsigned int num_of_iterations = ceil(iterations / 5);
	for (unsigned int i = 0; i < num_of_iterations; ++i)
	{
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
	}
	gettimeofday(&end, NULL);
	return (double) (((end.tv_sec - start.tv_sec) * 10000000000) +
					 ((end.tv_usec - start.tv_usec) * 1000)) / (num_of_iterations * 5);
}

