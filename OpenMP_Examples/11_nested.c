#include <stdio.h>
#include <omp.h>

void main()
{
    omp_set_num_threads(4);
    omp_set_nested(1);

    printf("Nested parallelism is %s\n", omp_get_nested() ? "supported": "not supported");
    
    #pragma omp parallel
    {
      int id = omp_get_thread_num();
        printf("Thread %d executes outer parallel region\n", id);

#pragma omp parallel num_threads(2)
    {
      printf("\tThread %d of %d main thread executes inner parallel region\n", omp_get_thread_num(), id);
    }

    }
}
