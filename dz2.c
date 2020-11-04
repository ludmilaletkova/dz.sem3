#include <stdio.h> 
#include <stdlib.h>

int main(void){

		int m, N, p;
		int i, j;
		
		//проверка графа на связность

		printf("Enter the number of graph vertices: ");
		scanf("%d", &N);

		printf("Enter the number of graph edges: ");
		scanf("%d", &m);

		p = 0.5 * (N - 1) * (N - 2);

		if (m > p) {
			printf("Graph connected\n");
		}
		if (m <= p) {
			printf("Graph not connected\n");
		}

		//объявление указателя на двумерный динамический массив, т.е. сама матрица
		int** A = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++) 
			A[i] = (int*)malloc(N * sizeof(int));


        //заполнение матрицы в консоле
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) 
				scanf("%d", &A[i][j]);
			


		//запись в документ
		FILE* f;
		f = fopen("graph.dot", "w");
		fprintf(f, "digraph G {\n");
			
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				if (A[i][j] != 0){
                                        while(A[i][j]>=1){
					fprintf(f, "%d -> %d; \n", i + 1, j + 1);
                                        A[i][j]--;
                                        }
				}
			}
		fprintf(f, "}");

		fclose(f);

		//очищение
		for (int i = 0; i < N; i++) {
			free(A[i]);
		}
		free(A);

		return 0;
}
