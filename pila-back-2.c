/*
    * Pila o Stack
    * Aplicaciones de la pila
    * Author: Jose Zacarias
    * 27-AGO-2024
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int SIZE;
int BASE = 1;
int TOP;
int option = 0;
int tmp_data;
char exp_infix[100];
char exp_postfix[100];

//Borrar espacios en blanco
char *TrimSpaces(char *str){
  char *end;
  while(isspace((unsigned char)*str)) str++;
  if(*str == 0)
    return str;

  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;
  end[1] = '\0';
  return str;
}

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
int isStackEmpty(int *stack){
    if(TOP == BASE){
        printf("%s\n","La pila SI esta vacia");
        return 1;
    }else{
        printf("%s\n","La pila NO esta vacia");
        return 0;
    }
}
void WholeStack(int *stack){
    printf("%s","Pila: [ ");
    for(int i = 1; i < TOP; i++){
        printf("%d ",stack[i]);
    }
    printf("%s\n","]");
}

void checkParenthesis(char *expression, int *stack){
   for(int i=0;i<strlen(expression);i++){
       switch(expression[i]){
           case '(':
               Push(stack,expression[i]);
               break;
           case ')':
               if(isStackEmpty(stack)){
                   printf("%s\n","Error: Existen mas parentesis de cierre que de apertura");
                   return;
               }else{
                   Pop(stack);
               }
               break;
       }
   } 
}
void infixToPostfix(){
    
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
        printf("%s\n", "6. Test Zone");
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
        case 6:
            printf("%s\n","============== PARENTESIS ==============");
            printf("%s","Ingrese la expresion: ");
            scanf("%s", exp_infix);
            printf("%s",exp_infix);
            //checkParenthesis(expression,A);
            option = 0;
            break;
        default:
            printf("\n%s\n\n","Ingresa una opcion correcta");
            option = 0;
            break;  
        }
    }while(option == 0);
    return 0;
}
