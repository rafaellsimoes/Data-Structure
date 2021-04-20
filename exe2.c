#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

Cliente *cria_cliente(Cliente *cliente){
  // alocação dinâmica da variálvel Cliente
  cliente = malloc(sizeof(Cliente));
  return cliente;
}

void  apagar_cliente(Cliente *cliente) {
  Cliente *aux;
  aux = cliente;
  free(aux);
}


int main(){
  Cliente *cliente;
  cliente = cria_cliente(cliente);
  
  apagar_cliente(cliente);
  return 0;
}
