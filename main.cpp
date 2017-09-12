/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oscar
 *
 * Created on 11 de septiembre de 2017, 10:46 PM
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACKSIZE 100

typedef char STACKELEMENT;
typedef struct{
    int top;
    STACKELEMENT items[STACKSIZE];
}STACK;

void Clear(STACK *);
int Empty(STACK *);
int Full(STACK *);
STACKELEMENT Pop(STACK *);
void Push(STACK *, STACKELEMENT);

/*
 * 
 */
int main(int argc, char** argv) {

    STACKELEMENT a;
    int p,i;
    STACK b;
    STACK *c=&b;
    b.top=-1;
    clrscr();
    
    /*da la oportunidad de introducir o sacar elementos de la pila 5 veces*/
    for(i=0;i<=4;i++){
        printf("Introducir o sacar de la pila 1/2\n");
        scanf("%d", &p);
        fflush(stdin);
        if(p==1){
            printf("Elemento a introducir\n");
            scanf("%*c %c", &a);
            Push(c,a);
            printf("Elemento introducido con exito\n");
            getch();
        }
        else{
            if(p==2){
                if(Empty(c)){
                    printf("Error: Pila vacia.\n");
                    getch();
                    exit(1);
                }
                else{
                    a=Pop(c);
                    printf("Elemento extraido de la pila: %c\n", a);
                    getch();
                }
            }
            else{
                printf("La proxima vez debe digitar 1 o 2\n");
            }
            getch();
        }
    }
    return (EXIT_SUCCESS);
}

void Clear(STACK *ps){
    ps->top=-1;
}

int Empty(STACK *ps){
    if(ps->top==-1)
        return TRUE;
    else
        return FALSE;
}

int Full(STACK *ps){
    if(ps->top==STACKSIZE-1)
        return TRUE;
    else
        return FALSE;
}

void Push(STACK *ps, STACKELEMENT x){
    if(Full(ps)){
        printf("%s","Pila desbordada");
        exit(1);
    }
    else
        ps->items[++(ps->top)]=x;
}

STACKELEMENT Pop(STACK *ps){
    if(Empty(ps)){
        printf("%s","Pila desbordada");
        exit(1);
    }
    return ps->items[(ps->top)--];
}

