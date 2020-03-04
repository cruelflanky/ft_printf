#include <stdio.h>
#include <stdlib.h>

#define UNSIGNED_OVERFLOW -4

unsigned summ(unsigned char num, unsigned first, ...) {
    unsigned sum = 0;
    unsigned testsum = 0;
    unsigned *p = &first;
    while (num--) {
        testsum += *p;
        if (testsum >= sum) {
            sum = testsum;
        } else {
            exit(UNSIGNED_OVERFLOW);
        }
        p++;
    }
    return sum;
}

int main() {
    int sum = summ(5, 1u, 2u, 3u, 4u, 5u);
    printf("summ = %u\n", sum);
    sum = summ(7, 0u, 27u, 0u, 4u, 5u, 60u, 33u);
    printf("summ = %u\n", sum);
    return(0);
}