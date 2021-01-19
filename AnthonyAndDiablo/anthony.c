#include<stdio.h>
#include<math.h>

int main(void) {
    float A;
    float N;

    scanf("%f %f", &A, &N);

    if (A <= pow(N, 2) / (4 * M_PI)) {
    	printf("Diablo is happy!");
    }
    else {
    	printf("Need more materials!");
    }

}