/*
    * Matrices simuladas con vector
    * Operaciones: Suma, Resta y Multiplicacion
    * Author: Jose Zacarias
    * 13-AGO-2024
*/
#include <stdio.h>
#include <stdlib.h>
int SIZE;
int option = 0;

int PD(int i,int j){
   return ((j*(j-1))/2)+(i-1);
}

void printMatrix(int *matriz){
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            if(i>j){
                printf("%d ", 0);
            }else{
                printf("%d ", matriz[PD(i,j)]);
            }
            
        }
        printf("\n");
    }
    printf("\n%s\n", "======================================");
}

void inputMatrix(int *matriz){
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            if(i>j){
                printf("Elemento [%d][%d] = 0\n", i, j);
            }else{
                printf("Elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz[PD(i,j)]);
            }
        }
    }
}

int main() {
    printf("%s\n", "Dimension para Matriz A y B (cuadrada):");
    scanf("%d", &SIZE);
	
    int *A = (int*)malloc(SIZE*SIZE*sizeof(int));
    int *B = (int*)malloc(SIZE*SIZE*sizeof(int));
    int *C = (int*)malloc(SIZE*SIZE*sizeof(int));

    printf("%s\n", "================= Llenando Matriz A =================");
    inputMatrix(A);
    printf("\n%s\n", "================= Llenando Matriz B =================");
    inputMatrix(B);
    printf("\n%s\n", "============== Matriz Tri. Sup. Der ==============");
    printf("\n%s\n", "Matriz A");
    printMatrix(A);
    printf("\n%s\n", "Matriz B");
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
                    if (i <= j) {
                        int k = PD(i,j);
                        C[k] = A[k] + B[k];
                    }   
                }
            }
            printMatrix(C);
            option = 0;
            break;
        
        case 2:
            printf("%s\n\n","============== RESTA A-B ==============");
            for(int i = 1; i <= SIZE; i++) {
                for(int j = 1; j <= SIZE; j++) {
                    if (i <= j) {
                        int k = PD(i,j);
                        C[k] = A[k] - B[k];
                    } 
                }
            }
            printMatrix(C);
            option = 0;
            break;
        case 3:
            printf("%s\n\n","============== MULT AxB ==============");
            for(int i = 1; i <= SIZE; i++) {
                for(int j = 1; j <= SIZE; j++) {
                    if (i <= j) {
                        int k = PD(i,j);
                        C[k] = 0;
                        for(int l = 1; l <= SIZE; l++) {
                            if (i <= l && l <= j) { // Verifica que l esté dentro de la triangular superior
                                C[k] += A[PD(i,l)]*B[PD(l,j)];
                            }
                        }
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