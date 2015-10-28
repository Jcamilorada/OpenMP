#include <stdio.h>   
#include <omp.h>   


static long MULTIPLIER  = 1366;
static long num_trials  = 100000;
static long ADDEND      = 150889;
static long PMOD        = 714025;

#define MAX_THREADS 128
static unsigned long long seed_array[MAX_THREADS];

unsigned long long random_last = 0;
#pragma omp threadprivate(random_last)

double random_low, random_hi;



double random()
{
    unsigned long long random_next;
    double ret_val;

    random_next = (unsigned long long)((MULTIPLIER  * random_last + ADDEND)% PMOD);
    random_last = random_next;

    ret_val = ((double)random_next/(double)PMOD)*(random_hi-random_low)+random_low;

    return ret_val;
}

void seed(double low_in, double hi_in)
{
    int i, id, nthreads;
    unsigned long long iseed;
    id = omp_get_thread_num();

    #pragma omp single
    {
        if (low_in < hi_in)
        {
            random_low = low_in;
            random_hi = hi_in;
        }
        else
        {
            random_low = hi_in;
            random_hi = low_in;
        }

        nthreads = omp_get_num_threads();

        iseed = PMOD / MULTIPLIER;
        seed_array[0] = iseed;

        for (i = 1; i < nthreads; ++i)
        {
            iseed = (unsigned long long) ((MULTIPLIER * iseed + ADDEND) % PMOD);
            seed_array[i] = iseed;
        }
    }

    random_last = (unsigned long long) seed_array[id];
}


int main()
{
    long Ncirc = 0;
    long i;
    double pi, x, y;
    double r = 1.0;

    #pragma omp parallel
    {
        seed(-r, r);
        #pragma omp for reduction (+:Ncirc) private (x, y)
        for (i = 0; i < num_trials; i++)
        {
            x = random();
            y = random();

            if ((x * x + y * y) <= r * r)
            {
                Ncirc++;
            }
        }
    }

    pi = 4.0 * ((double) Ncirc / (double) num_trials);
    printf("\n %d trials, pi is %f \n", num_trials, pi);

    return 0;
}
