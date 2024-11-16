#include <stdio.h>
#include <omp.h>

void main()
{
    omp_set_num_threads(4);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("Section 1 with thread %d\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("Section 2 with thread %d\n", omp_get_thread_num());
        }
    }   
}