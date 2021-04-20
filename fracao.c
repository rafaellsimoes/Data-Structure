#include<stdio.h>
#include<stdlib.h>

typedef struct{
  double nm; // numerador
  double dm; // denominador
}fracao;

// criar uma fracao

fracao *cria_fracao( double num, double deno){
  // alocação dinâmica
  fracao *f = malloc(sizeof(fracao)); // -> acessar os campos do TAD
  f->nm = num;
  f->dm = deno;
  return f;
}

// soma
fracao *soma_fracao(fracao *f1, fracao *f2){
  // soma
  fracao *s = malloc(sizeof(fracao));
  s->nm = f1->nm*f2->dm + f1->dm*f2->nm;
  s->dm = f1->dm*f2->dm;
  return s;
}

fracao *produto(fracao *f1, fracao *f2){
  // produto
  fracao *p = malloc(sizeof(fracao));
  p->nm = f1->nm*f2->nm;
  p->dm = f1->dm*f2->dm;
  return p;
}

fracao *divisao(fracao *f1, fracao *f2){
  // divisao
  fracao *d = malloc(sizeof(fracao));
  d->nm = f1->nm*f2->dm;
  d->dm = f1->dm*f2->nm;
  return d;
}

void apaga_fracao( fracao *f){
  fracao *aux;
  aux = f;
  free(aux);
}

int main(){
  printf("fracao \n");
  double n1 = 10,d1 = 25;
  fracao *f1, *f2, *soma, *p, *d; // não é apologia ao uso de entorpecentes
  f1 = cria_fracao(n1,d1);
  f2 = cria_fracao(12,24);
  printf("f1 :%lf / %lf \n", f1->nm, f1->dm);
  printf("f2 :%lf / %lf \n", f2->nm, f2->dm);
  soma = soma_fracao(f1,f2);
  p = produto(f1,f2);
  d = divisao(f1,f2);
  printf("soma \n");
  printf("soma :%lf / %lf \n", soma->nm, soma->dm);
  printf("produto \n");
  printf("produto :%lf / %lf \n", p->nm, p->dm);
  printf("divisão \n");
  printf("divisao :%lf / %lf \n", d->nm, d->dm);
  int a = sizeof(p);
  printf("bytes %d  \n ",a);
  apaga_fracao(soma);
  apaga_fracao(p);
  apaga_fracao(f1);
  apaga_fracao(f2);

}
