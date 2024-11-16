#include <stdio.h>
#include <omp.h>

void main() {
    int product = 2; //shared variable
    omp_set_num_threads(4);

#pragma omp parallel
    {
        int id = omp_get_thread_num(); //private variable
        product = product * (id + 1);
        printf("The thread %d get the result %d\r\n", id+1, product); 
    }

    printf("The result is %d\r\n", product);
}
