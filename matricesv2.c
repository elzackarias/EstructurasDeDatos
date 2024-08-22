/*
    * Programa: Polinomio de Direccionamiento
    * Operaciones: Suma, Resta y Multiplicacion
    * Author: Jose Zacarias Silberio
    * 13-Ago-2024
*/
#include <stdio.h>
#include <stdlib.h>
int SIZE;
int option = 0;
int PD(int i,int j){
   return SIZE*(i-1)+(j-1);
}
void printMatrix(int *matriz){
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            printf("%d ", matriz[PD(i,j)]);
        }
        printf("\n");
    }
    printf("\n%s\n", "======================================");
}

int main() {
    printf("%s\n", "Dimension para Matriz A y B (cuadrada):");
    scanf("%d", &SIZE);

    int *A = (int*)malloc(SIZE*SIZE*sizeof(int));
	int *B = (int*)malloc(SIZE*SIZE*sizeof(int));
	int *C = (int*)malloc(SIZE*SIZE*sizeof(int));

    printf("%s\n", "============== MATRIZ A ==============");
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &A[PD(i,j)]);
        }
    }
    printf("%s\n", "============== MATRIZ B ==============");
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &B[PD(i,j)]);
        }
    }
    printf("\n%s\n", "======================================");
    printf("\n%s\n", "Matriz A:");
    printMatrix(A);

    printf("\n%s\n","Matriz B:");
    printMatrix(B);

    //MENU
    do{
        printf("\n\n%s\n", "Operacion a realizar: ");
        printf("%s\n", "1. Suma ");
        printf("%s\n", "2. Resta ");
        printf("%s\n", "3. Producto ");
        printf("%s\n", "4. Salir ");
        scanf("%d", &option);
        switch (option){
        case 1:
            printf("%s\n\n","============== SUMA A+B ==============");
            for(int i = 1; i <= SIZE; i++) {
                for(int j = 1; j <= SIZE; j++) {
                    int k = PD(i,j);
                    C[k] = A[k]+B[k];
                }
            }
            printMatrix(C);
            option = 0;
            break;
        
        case 2:
            printf("%s\n\n","============== RESTA A-B ==============");
            for(int i = 1; i <= SIZE; i++) {
                for(int j = 1; j <= SIZE; j++) {
                    int k = PD(i,j);
                    C[k] = A[k]-B[k];
                }
            }
            printMatrix(C);
            option = 0;
            break;
        case 3:
            printf("%s\n\n","============== MULT AxB ==============");
            for(int i = 1; i <= SIZE; i++) {
                for(int j = 1; j <= SIZE; j++) {
                    int k = PD(i,j);
                    C[k] = 0;
                    for(int l = 1; l <= SIZE; l++) {
                        C[k] += A[PD(i,l)]*B[PD(l,j)];
                    }
                }
            }
            printMatrix(C);
            option = 0;
            break;
        case 4:
            printf("%s\n","Saliendo...");
            break;
        default:
            printf("\n%s\n\n","Ingresa una opcion correcta");
            option = 0;
            break;  
        }
    }while(option == 0);
}