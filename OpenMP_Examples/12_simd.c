#include <stdio.h>
#include <stdlib.h>
#include <omp.h>



float square( float x )
{
    return x * x;
}


void main()
{
    int n = 16;
    float *a = malloc(n*sizeof(float));
    float *c = malloc(n*sizeof(float));

    // Initialize a
    for (int i=0; i<n; ++i)
      a[i] = rand()%10;

    
    #pragma omp simd
    for (int i=0; i<n; ++i)
      {
	c[i] = square(a[i]);    
      }

    // print results
    for (int i=0; i<n; ++i)
      printf("Value of a[%d] is %f and value of c[%d] is %f\n", i, a[i], i, c[i]);
      
    

    free(a);
    free(c);
}
