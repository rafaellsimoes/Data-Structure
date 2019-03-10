#include<stdio.h>
#include<stdlib.h>

#include "lista_dupla.h"

void criaListaVazia(lista *l){
	l->prim = NULL;
	l->ult = NULL;
} 

int listaVazia(lista *l){
	return (l->prim == NULL);
}

nodo *pesquisaLista(lista *l, int x){
nodo *aux;
aux = l->prim;
while(aux != NULL && aux->item != x){
	aux = aux->prox;
}
return aux;
}

nodo *pesquisaPosicao(lista *l, int p){
nodo *aux;
aux = l->prim;
int c = 1;
while(aux != NULL && c<p){
	aux = aux->prox;	
	c++;
}
return aux;
} 

void inserirInicio(lista *l, int x){
nodo *novo = malloc(sizeof(nodo));
novo->item = x;
novo->prox = l->prim;
if(listaVazia(l)){
	l->ult = novo;
}
else{
	l->prim->ant = novo;
}
l->prim = novo;
l->prim->ant = NULL;
}

void inserirFinal(lista *l, int x){
nodo *novo = malloc(sizeof(nodo));
novo->item = x;
novo->prox = NULL;

if(listaVazia(l)){
	l->prim = novo;
}

else{
	l->ult->prox = novo;
}

novo->ant = l->ult;
l->ult = novo;
}

void inserirPosicao(lista *l, int x, int p){
nodo *novo = malloc(sizeof(nodo));
nodo *anterior;
nodo *posterior;
if(p == 1)
	inserirInicio(l,x);

else{
	novo->item = x;
	anterior = pesquisaPosicao(l,p-1);
	posterior = anterior->prox;
	anterior->prox = novo;
	novo->ant = anterior;
	novo->prox = posterior;
	if(posterior == NULL)
		l->ult = novo;
	else
		posterior->ant = novo;

}

}

int removerInicio(lista *l){
int x;
nodo *aux = malloc(sizeof(nodo));

if(listaVazia(l)){
	printf("Underflow: Lista Vazia \n");
	return x = -1;
	}
else{
	aux = l->prim;
	x = aux->item;
	l->prim = l->prim->prox;
	// verifica se tem apenas um nodo
	if(l->prim == NULL){
		l->ult = NULL;
	}
	else{
		l->prim->ant = NULL;	
	}
	aux->prox = NULL;
	aux->ant = NULL;
	free(aux);
	return x;	
}
}

int removerFinal(lista *l){
int x;
nodo *aux = malloc(sizeof(nodo));
nodo *anterior;
if(listaVazia(l)){
	printf("Underflow: Lista Vazia \n");
	return x = -1;
	}
else{
	if(l->prim == l->ult && !listaVazia(l)){	
		aux = l->prim;
		l->prim = NULL;
		l->ult = NULL;
		}
	else{
		anterior = l->ult->ant;
		aux = l->ult;
		anterior->prox = NULL;
		l->ult = anterior;
		}
	x = aux->item;
	aux->prox = NULL;
	aux->ant = NULL;
	free(aux);
	return x;	
	}
}

int removerPosicao(lista *l, int p){
int x;
nodo *aux = malloc(sizeof(nodo));
nodo *anterior;
nodo *posterior;
if(listaVazia(l)){
	printf("Underflow: Lista Vazia \n");
	return x = -1;
	}
else{
	if(p == 1){
		removerInicio(l);
		}	
	else{
		anterior = pesquisaPosicao(l,p-1);
		aux = anterior->prox;
		posterior = aux->prox;
		anterior->prox = posterior;
		if(aux == l->ult){
			l->ult = anterior;
			}
		else{
			posterior->ant = anterior;
			}
		x = aux->item;
		aux->prox = NULL;
		aux->ant = NULL;
		free(aux);
		return x;
		}
	}
}

void imprimir_linear(lista *l){
nodo *aux;
aux = l->prim;
while(aux != NULL){
	printf("Na Lista %d \n",aux->item);	
	aux = aux->prox;
}
free(aux);
}



void imprimir_reversa(lista *l){
nodo *aux;
aux = l->ult;
while(aux != NULL){
	printf("Na Lista %d \n",aux->item);	
	aux = aux->ant;
}
free(aux);
}

void apagaLista(lista *l){
nodo *aux = l->prim;
while(l->prim = NULL){
	l->prim = l->prim->prox;
	free(aux);
	aux = l->prim;
}
}

int main(){
lista *l = malloc(sizeof(lista));
criaListaVazia(l);
int y;
int i,n=8;

for(i=0;i<n; i++){
	inserirInicio(l,i);
}
inserirPosicao(l,67,4);
inserirPosicao(l,90,9);
imprimir_linear(l);
//y = removerPosicao(l,5);
//printf("Fora da Lista %d \n",y);
while(!listaVazia(l)){
	y = removerInicio(l);
	printf("Fora da Lista %d \n",y);
}


apagaLista(l);
free(l);
return 0;
}
