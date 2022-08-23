#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cad_Aluno.h"

struct turma
{
  int qtd; /*numero atual de elementos*/
  Aluno *A;
};

turma *SSList_create()
{

  turma *L = (turma *)malloc(sizeof(turma));

  if (L != NULL)
  {
    L->qtd = 0;
    L->A = malloc(50 * sizeof(Aluno));
    return L;
  }

  return 0;
}

int SSList_insert(turma *L, Aluno dados)
{
  if (SSList_full(L) == 0)
  {
    printf("\nLista cheia.\n");
    return -1;
  }
  if (SSList_indexOf(L, dados.Matricula) == -1)
  {
    L->A[L->qtd] = dados;
    L->qtd++;
    puts("Aluno matriculado.");
    SSList_ordenar(L);
    return 1;
  }
  printf("Matricula %d ja existente, altera para %d.\n", dados.Matricula, dados.Matricula + 1);
  dados.Matricula++;
  SSList_insert(L, dados);
  return 1;
}

int SSList_indexOf(turma *L, int chave)
{
  int i;

  for (i = 0; i < L->qtd; i++)
  {
    if (L->A[i].Matricula == chave)
    {
      return i;
    }
  }
  return -1;
}

void SSList_print(turma *L, void (*print)(Aluno dados), int pos)
{

  if (pos == -1)
  {
    for (int i = 0; i < L->qtd; i++)
    {
      puts("");
      print(L->A[i]);
    }
  }
  else
  {
    print(L->A[pos]);
  }
}

int SSList_full(turma *L)
{

  return (L->qtd == 50) ? 0 : 1;
}
int SSList_empty(turma *L)
{

  return (L->qtd == 0) ? 0 : 1;
}