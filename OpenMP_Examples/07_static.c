#include <stdio.h>
#include <time.h>
#include <omp.h>

void main()
{
    omp_set_num_threads(4);
    int n = 12;

#pragma omp parallel for schedule(static, 4)
    for(int i = 0; i < n; i++) {
        printf("The thread %d process the iteration %d\n", omp_get_thread_num(), i);
    }
    
}  
