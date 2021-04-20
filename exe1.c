// Implementar uma função que receba um vetor e um valor (do mesmo
//tipo do vetor). A função deve percorrer o vetor recursivamente e retornar 1 caso o
//valor pertença ao vetor e 0 caso contrário

#include <stdio.h>
#include <stdlib.h>

int pesquisa(int vet[], int tam, int valor){
  // caso base primeiro
  if(vet[tam-1] == valor){
    return 1;
  }
  else{
    if(tam >= 0)
      pesquisa(vet,tam-1,valor);
    else
      return 0;
  }
}

int main(){
  printf("Tamanho  do vetor e preenchimento e o valor \n");
  int tam, valor;
  printf("Valor ")
  scanf("%d",&tam);
  scanf("%d",&valor);
  int vet[tam];
  printf("lendo os valores \n");
  for(int i=0;i<tam;i++){
    scanf("%d",&vet[i]);
  }
  printf("mostra os valores \n");

  for(int i=0;i<tam;i++){
    printf("%d",vet[i]);
  }

  printf("\n");

  if(pesquisa(vet,tam,valor))
    printf("Achou \n");
  else
    printf("Não Achou \n");

  return 0;
}
