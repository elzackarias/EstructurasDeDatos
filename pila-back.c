/*
    * Pila o Stack
    * PUSH, POP, EmptyStack, Tope
    * Author: Jose Zacarias
    * 22-AGO-2024
*/
#include <stdio.h>
#include <stdlib.h>

int SIZE;
int BASE = 1;
int TOP;
int option = 0;
int tmp_data;

void Push(int *stack, int data){
    if(TOP <= SIZE){
        stack[TOP] = data;
        TOP++;
    }else{
        printf("%s\n","La Pila esta llena, no se ingreso el dato");
    }
}
void Pop(int *stack){
    if(TOP > BASE){
        TOP--;
        printf("%s %d\n","El valor es: ",stack[TOP]);
    }else{
        printf("%s\n","Pila vacia");
    }
}

void TopData(int *stack){
    if(TOP==BASE){
        printf("%s\n","No hay datos");
    }else{
        printf("%s %d\n","Dato del tope: ",stack[TOP-1]);
    }
}
void isStackEmpty(int *stack){
    if(TOP == BASE){
        printf("%s\n","La pila SI esta vacia");
    }else{
        printf("%s\n","La pila NO esta vacia");
    }
}
void WholeStack(int *stack){
    printf("%s","Pila: [ ");
    for(int i = 1; i < TOP; i++){
        printf("%d ",stack[i]);
    }
    printf("%s\n","]");
}

int main(){
    printf("%s\n", "Ingrese Longitud de la Pila:");
    scanf("%d", &SIZE);
    TOP = BASE;
    int *A = (int*)malloc(SIZE*SIZE*sizeof(int));
    
    do{
        printf("\n\n%s\n", "Operacion a realizar: ");
        printf("%s\n", "1. Empilar Dato");
        printf("%s\n", "2. Desempilar Dato ");
        printf("%s\n", "3. Obtener Dato del Tope ");
        printf("%s\n", "4. ¿La Pila esta vacia?");
        printf("%s\n", "5. Salir");
        scanf("%d", &option);
        switch (option){
        case 1:
            printf("%s\n","============== EMPILAR DATO ==============");
            printf("%s","Ingrese el Dato: ");
            scanf("%d", &tmp_data);
            Push(A, tmp_data);
            WholeStack(A);
            option = 0;
            break;
        case 2:
            printf("%s\n\n","============== DESEMPILAR DATO ==============");
            Pop(A);
            WholeStack(A);
            option = 0;
            break;
        case 3:
            printf("%s\n\n","============== DATO DEL TOPE ==============");
            TopData(A);
            option = 0;
            break;
        case 4:
            printf("%s\n\n","============== ¿LA PILA ESTA VACIA? ==============");
            isStackEmpty(A);
            option = 0;
            break;
        case 5:
            printf("%s\n","Saliendo...");
            break;
        default:
            printf("\n%s\n\n","Ingresa una opcion correcta");
            option = 0;
            break;  
        }
    }while(option == 0);
    return 0;
}