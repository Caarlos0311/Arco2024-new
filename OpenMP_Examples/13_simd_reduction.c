#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void main()
{
    omp_set_num_threads(4);
    int n = 16;
    float *a = malloc(n*sizeof(float));
    float *b = malloc(n*sizeof(float));
    float sum = 0;

    // Initialize a and b
    for (int i=0; i<n; ++i){
      a[i] = rand()%10;
      b[i] = rand()%10;
    }

    
    #pragma omp simd reduction(+:sum)
    for (int i=0; i<n; ++i)
      {
	sum += a[i]+b[i];
      }

    printf("The sum of all values of a and b is %f\n", sum);
      
    free(a);
    free(b);
}
