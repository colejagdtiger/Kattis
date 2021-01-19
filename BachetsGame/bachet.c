#include<stdio.h>
#include<stdbool.h>

int main(void) {
	while (1) {
		int N;
		int M;
		if(scanf("%d", &N) == EOF) {
			break;
		}
		scanf("%d", &M);

		bool positions[N];
		int moves[M];
		int max = 1;
		

		for (int i = 0; i < M; i++) {
			scanf("%d", &moves[i]);
			if (max < moves[i]) {
				max = moves[i];
			}
		}
		
		positions[0] = true;

		for (int i = 1; i <= max; i++) {
			positions[i] = false;


			for (int j = 0; j < M; j++) {

				if ((i + 1) == moves[j]) {
					positions[i] = true;
					break;
				}
				else if (i >= moves[j] & !(positions[i - moves[j]])) {
					positions[i] = true;
					break;
				}
			}
		}

		for (int i = max + 1; i < N; i++) {

			positions[i] = false;

			for (int j = 0; j < M; j++) {

				if (!(positions[i - moves[j]])) {
					positions[i] = true;
					break;
				}
			}
		}

		if (positions[N - 1]) {
			printf("Stan wins\n");
		}
		else {
			printf("Ollie wins\n");
		}
	}
}
