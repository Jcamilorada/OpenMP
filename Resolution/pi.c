#include <stdio.h>
#include <omp.h>
#include <time.h>

static long num_steps = 100000000;

void main()
{
    double x, pi;
    double sum = 0.0;
    double step = 1.0/(double) num_steps;

    clock_t start = clock();
    #pragma omp parallel for private(x) schedule(static, 100) reduction(+:sum)
    for (int i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4.0/(1.0 + x*x);
    }

    pi = step * sum;
    clock_t end = clock();

    printf("elapsed time %f\n", (float)(end - start) / CLOCKS_PER_SEC);
    printf("pi [%lf] step [%lf] sum[%lf]\n", pi, step, sum);
}
