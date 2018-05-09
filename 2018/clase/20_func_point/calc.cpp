#include <stdio.h>
#include <stdlib.h>

#define N 16
#define MAX 0x100

int error = 0;
const char *mssg[] = {
    "Todo OK.",
    "Pila vacC-a.",
    "Pila llena."
};

typedef struct {
    char nombre[N];
    double (*op)(double, double);
} Operacion;

typedef struct {
    int data[MAX];
    int cima;
} Pila;


enum {
    suma,
    resta,
    multiplicacion,
    division,
    OPERA
};

bool push(int dato, Pila *pila){
    if (pila->cima >= MAX){
        error = 2;
        return false;
    }
    error = 0;
    pila->data[pila->cima++] = dato;
    return true;
}

int pop(Pila *pila) {
    if (pila->cima == 0){
        error = 1;
        return 0;
    }
    error = 0;
    return pila->data[--pila->cima];
}

double sum(double op1, double op2) { return op1 + op2; }
double res(double op1, double op2) { return op1 - op2; }
double mul(double op1, double op2) { return op1 * op2; }
double div(double op1, double op2) { return op1 / op2; }

int main(){

    Pila op, datos;
    double op1, op2;
    char opera;
    Operacion catalogo[] = {
        {"suma",  &sum},
        {"resta", &res},
        {"multiplicacion", &mul},
        {"division", &div}
    };

    printf("Operacion: ");
    scanf(" %lf %s %lf", &op1, &opera, &op2);
    push(op2, &datos);
    push(op1, &datos);

    switch(opera) {
        case '+':
            push(suma, &op);
            printf("El resultado de la suma es: %lf", &op);
        break;

        case '-':
            push(resta, &op);
            printf("El resultado de la resta es: %lf", &op);
        break;

        case '*':
            push(multiplicacion, &op);
            printf("El resultado de la multiplicacion es: %lf", &op);
        break;

        case '/':
            push(resta, &op);
            printf("El resultado de la division es: %lf", &op);
        break;
    }
    return EXIT_SUCCESS;
}
