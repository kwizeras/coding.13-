/*
1. 
   - The gettimeofday() function provides microsecond precision. 
     However, the actual precision can be affected by the system’s clock resolution and the overhead of the function call itself.
   - To time an operation precisely, it should take at least a few microseconds. 
     For very short operations, you may need to repeat the operation many times in a loop and measure the total time to get an accurate average.


*/

// 2.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <num_pages> <num_trials>\n", argv[0]);
        return 1;
    }

    int num_pages = atoi(argv[1]);
    int num_trials = atoi(argv[2]);
    int page_size = 4096; // Assuming 4KB pages
    int jump = page_size / sizeof(int);
    int *a = malloc(num_pages * page_size);
    struct timeval start, end;

    // Initialize the array to avoid demand zeroing costs
    for (int i = 0; i < num_pages * jump; i += jump) {
        a[i] = 0;
    }

    gettimeofday(&start, NULL);
    for (int t = 0; t < num_trials; t++) {
        for (int i = 0; i < num_pages * jump; i += jump) {
            a[i] += 1;
        }
    }
    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;

    printf("Time per access: %f microseconds\n", (elapsed / (num_pages * num_trials)) * 1e6);

    free(a);
    return 0;
}


/*4.Visual tools like bar charts, line graphs, and scatter plots make it easier to compare different data points or trends over time. 
    This is much harder to do with raw numbers or text descriptions.
*/ 


/*
5. I can use the volatile keyword to prevent the compiler from optimizing away the loop.
*/

/*
6. That can be achieved by using  `sched_setaffinity` to pin the process to a specific CPU.
*/

/*
7. Yes, it will affect the timing. 
   Initialize the array before starting the timing loop to ensure that all pages are allocated and zeroed can help to counterbalance this.
*/