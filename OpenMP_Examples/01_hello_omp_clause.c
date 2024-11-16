#include <stdio.h>
#include <omp.h>

void main()
{
#pragma omp parallel num_threads(4)
    {
        printf("Hello world by thread: %d\n", omp_get_thread_num());
    }
}
