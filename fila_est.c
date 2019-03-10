#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 15

typedef struct{
int itens[max];
int inicio, fim;
}fila;


void ciraFilaVazia(fila *q){
    q->inicio = 0;
    q->fim = 0;
}

int filaVazia(fila *q){
    return (q->inicio == q->fim);
}

int filaCheia(fila *q){
    return (q->inicio == (q->fim+1)%max);
}

void enfileira(fila *q, int x){
    if(filaCheia(q)){
        printf("Overflow: fila cheia \n");    
    }
    else{
        q->itens[q->fim] = x;
        q->fim = (q->fim+1)%max;
    }
}


int desenfileira(fila *q){
int x = -1;

if(filaVazia(q)){
    printf("Underflow: fila vazia \n");
    return x;
}    

else{
    x = q->itens[q->inicio];
    q->inicio = (q->inicio+1)%(max);
    return x;
}

} 


int main(){
srand(time(NULL));
fila *q;
q = malloc(sizeof(fila));
int i=0;
int aux;
while(!filaCheia(q)){
    aux = 0 + rand()%max;
    enfileira(q,aux);
    printf("Elemento enfileirado %d \n",aux);
    i++;
   
}

while(!filaVazia(q)){
    i = desenfileira(q);
    printf("Elemento desenfileirado %d \n",i);
}

free(q);
return 0;
}
