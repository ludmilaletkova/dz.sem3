#include <stdio.h> 
#include <stdlib.h>

int main(void){

		int m, N, k = 0;
		int i, j;
		

		printf("Enter the number of graph vertices: ");
		scanf("%d", &N);

		//объявление указателя на двумерный динамический массив, т.е. сама матрица
		int** A = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++) 
			A[i] = (int*)malloc(N * sizeof(int));


        //заполнение матрицы в консоле
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				scanf("%d", &A[i][j]);
				
				if (A[i][j] == 1)
				   if (i!= j) 
				k++;
				}

				FILE* g;
		g = fopen("g.txt", "w");
		fprintf(g, "proverka\n");	
        if (k > 0.5*((N - 2)*(N - 1))) { 
                             fprintf(g,"svaz\n");
                         }
                        else { 
                             fprintf(g,"ne svaz \n");
                             }
							 fclose(g);

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
