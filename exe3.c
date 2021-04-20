#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

cliente *cria_cliente(cliente *cli){
  cli = malloc(sizeof(cliente));
  return cli;
}

void apagar_cliente(cliente *cli){
  cliente *aux;
  aux = cli;
  free(aux);
}

void inserir_dados(char nome[], c)

int main(){
  cliente *cli;
  cli = cria_cliente(cli);

  apagar_cliente(cli);
  return 0;
}
