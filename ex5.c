#include <stdio.h>

int main() {
    int matrix[3][3] = { 0 };
    int vector[3] = { 0 };
    int result[3] = { 0 };
//matrix
printf("MATRIX\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; ++j){
            printf("Type 3 numbers for %d row: ", i + 1);
            scanf("%d", &matrix[i][j]);
    }
//vector
printf("VECTOR\n");
        for (int a = 0; a < 3; a++){
            printf("%d. Type 3 numbers for vector: ", a + 1);
            scanf("%d", &vector[a]);
    }
//matrix print
printf("\nMATRIX = \n");
	for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j)
            printf("%d ", matrix[i][j]);
            printf("\n");
    }
//vector print
printf("\nVECTOR = \n");
        for (int a = 0; a < 3; a++){
            printf("%d ", vector[a]);
    }
//RESULT (MUltiplication)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
            result[i] += matrix[i][j] * vector[j];
    }
//result print
printf("\n\nRESULT = \n");
    for(int i = 0; i < 3; i++)
        printf("%d\n", result[i]);

printf("\n");
}
