#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 15

typedef struct{
int itens[max];
int topo;
}pilha;


void criaPilhaVazia(pilha *s){
    s->topo = 0;
}

int pilhaVazia(pilha *s){
    return s->topo == 0;
}

int pilhaCheia(pilha *s){
    return s->topo == max;
}

void empilha(pilha *s, int x){
    if(pilhaCheia(s)){
        printf("Erro: Overflow \n ");
        }
    else{
        s->itens[s->topo] = x;
        s->topo = s->topo+1;
    }
}

int desempilha(pilha *s){
int x =-1;
    if(pilhaVazia(s)){
      printf("Erro: Underflow \n "); 
      return x;   
    }
    else{
        x = s->itens[s->topo-1];
        s->topo = s->topo-1;
        return x;
    }

}

int main(){
srand(time(NULL));
pilha *s;
s = malloc(sizeof(pilha));
criaPilhaVazia(s);
int aux = 0;
int i=0;
while(!pilhaCheia(s)){
    aux = 0 + rand()%max;
    empilha(s,aux);
    printf("Emplilhado %d \n",aux);
    i++;  
}
int x;
while(!pilhaVazia(s)){
    x = desempilha(s);
    printf("Elemento desempilhado %d \n",x);
}

if(pilhaVazia(s)){
    printf("Pilha Vazia \n"); 
}

free(s);
return 0;
}
