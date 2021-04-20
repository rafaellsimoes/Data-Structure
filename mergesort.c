#include<stdio.h>
#include<stdlib.h>// biblioteca de alocação dinâmica
#include<time.h>// gerar números aleatórios
#define max 100
// flag para definir o tamanho do vetor alocado dinamicamente

//  Algoritmo de ordenação mergesort
// -----------------------------------------------//
void merge(int *v, int ini, int meio, int fim){
  // alocação dinâmica do vetor k
  int *w = malloc(sizeof(int)*(fim - ini +1));
  int i = ini;
  int j = meio;
  int k = 0;
  while( i < meio && j<fim){
      if(v[i] <= v[j]){
        w[k] = v[i];
        i = i+1;
      }
      else{
        w[k] = v[j];
        j = j+1; // j++ sim
      }
      k = k+1; // k++
  }

  while (i < meio) {
    w[k] = v[i];
    i = i+1;
    k = k+1;
  }

  while(j < fim){
    w[k] = v[j];
    j = j+1;
    k = k+1;
  }

  for(i = ini; i<fim; i++){
    v[i] = w[i - ini];
  }

  free(w);
}

void mergesort(int *v, int ini, int fim){
  int i = ini;
  int f = fim;
  int m = 0;
  if(i < f - 1){
    m = (i+f)/2;
    mergesort(v, i,m);
    mergesort(v,m,f);
    merge(v,i,m,f); // ainda a ser implementada
  }


}
int main(){
  // cabeçalho
// -----------------------------------------------//
  srand(time(NULL)); // semente para gerar números aleatórios
  int *vet = malloc(sizeof(int)*max); // alocação dinâmica do vetor
      // preenchimento do vetor com números aleatórios
// -----------------------------------------------//
  for(int i=0; i<max; i++){
    vet[i] = 0 + rand()%max;
  }

  for(int i=0; i<max; i++){
    printf("%d - ", vet[i]);
  }
  printf("\n");
// ---------------------------------------------//
// Algoritmo de ordenação: mergesort
// ---------------------------------------------//
  mergesort(vet,0,max);
// mostrar o vetor  ordenado
  printf("vetor ordenado \n");
  for(int i=0; i<max; i++){
    printf("%d - ", vet[i]);
  }
  printf("\n");
  free(vet);
  return 0;
}
