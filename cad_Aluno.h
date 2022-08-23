#ifndef CADALUNO_H_INCLUDED
#define CADALUNO_H_INCLUDED
#define MAX 100

typedef struct
{
  char Aluno[128];
  char cpf[12];
  int Matricula;
} Aluno;

typedef struct turma turma;

turma *SSList_create();
/*
 * Libera os recursos alocados para uma lista estática ordenada.
 * @return Nada
 */
void SSList_destroy(turma *L);
/*
 * Insere um dado do tipo Aluno na lista.
 * @return 1 em caso de sucesso ou 0 em caso de erro.
 */
int SSList_insert(turma *L, Aluno nome);
/*
 * Busca e tenta remover um item na lista, caso a key seja encontrada.
 * @return 1 em caso de sucesso ou 0 em caso de erro.
 */
int SSList_remove(turma *L, int chave);
/*
 * Busca pelo índice de uma item de dados cuja key corresponda ao segundo parâmetro.
 * @return -1 em caso de falha ou o índice em caso de sucesso.
 */
int SSList_indexOf(turma *L, int chave);
/*
 * Imprime a lista. O Segundo parâmetro é um ponteiro para a função especializada na impressão do dado.
 * O terceiro parâmetro é para imprimir apenas um valor da lista, caso seja -1, imprime toda a lista.
 * @return Vazio.
 */
void SSList_print(turma *L, void (*print)(Aluno dados), int pos);
/*
 * Verifica se a lista está cheia.
 * @return 1 se cheia, 0 caso contrário.
 */
int SSList_full(turma *L);
/*
 * Verifica se a lista está vazia.
 * @return 1 se vazia, 0 caso contrário.
 */
int SSList_empty(turma *L);

#endif // CADALUNO_H_INCLUDED