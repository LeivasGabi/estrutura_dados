#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agenda.h"

#define false 0
#define true 1

void
inicializar (Cabecalho * cabecalho)
{
  cabecalho->primeiro = NULL;
  cabecalho->ultimo = NULL;
  cabecalho->tamanho = 0;
}

int
descobrirPosicao (Cabecalho * cabecalho, char sobrenome[])
{
  int retornoDaFuncao = 0, retornoCondicao = 0, continua;
  No *proximoNo = cabecalho->primeiro;

  do
    {
      retornoCondicao = strcmp (sobrenome, proximoNo->dado.sobrenome);

      if (retornoCondicao < 0)
	{
	  continua = false;
	}
      else
	{
	  retornoDaFuncao++;

	  if (proximoNo->proximo != NULL)
	    {
	      proximoNo = proximoNo->proximo;
	    }
	  else
	    {
	      continua = false;
	    }
	}

    }
  while (continua != false);

  return retornoDaFuncao;
}

int
inserir (Cabecalho * cabecalho, Contato contato)
{
  No *novoNo = (No *) malloc (sizeof (No));
  int i = 0, posicao = 0, continua = 0;
  No *noDeAjuda;


  if (novoNo == NULL)
    {
      printf ("Problemas ao criar um novo no!");
      return false;
    }

  strcpy (novoNo->dado.nome, contato.nome);
  strcpy (novoNo->dado.sobrenome, contato.sobrenome);
  strcpy (novoNo->dado.email, contato.email);
  strcpy (novoNo->dado.fone, contato.fone);
  novoNo->proximo = NULL;
  novoNo->anterior = NULL;

  if (cabecalho->primeiro == NULL)	// Primeira insercao
    {
      cabecalho->primeiro = novoNo;
      cabecalho->ultimo = novoNo;
      cabecalho->tamanho++;

      return true;
    }

  posicao = descobrirPosicao (cabecalho, contato.sobrenome);

  noDeAjuda = cabecalho->primeiro;

  if (posicao == 0)		// Antes do Primeiro
    {
      novoNo->proximo = noDeAjuda;
      noDeAjuda->anterior = novoNo;
      cabecalho->primeiro = novoNo;
      cabecalho->tamanho++;

      return true;
    }

  if (posicao == cabecalho->tamanho) // Ultimo
    {
      cabecalho->ultimo->proximo = novoNo;
      novoNo->anterior = cabecalho->ultimo;
      cabecalho->ultimo = novoNo;
      cabecalho->tamanho++;

      return true;
    }

  // Qualquer outro
  for (i = 0; i < posicao; i++) 
    {
      noDeAjuda = noDeAjuda->proximo;
    }

  noDeAjuda->anterior->proximo = novoNo;
  novoNo->anterior = noDeAjuda->anterior;
  noDeAjuda->anterior = novoNo;
  novoNo->proximo = noDeAjuda;
  cabecalho->tamanho++;

  return true;
}

int deletar(Cabecalho *cabecalho, int posicaoDeletar) {
    No *aux = cabecalho->primeiro;
    
    if (cabecalho->tamanho == 0) {
        return false;
    }
    
    if (cabecalho->primeiro == cabecalho->ultimo) {
        cabecalho->primeiro = NULL;
        cabecalho->ultimo = NULL;
        
        free(aux);
        cabecalho->tamanho--;
        return true;
    }
    
    
    for (int i = 0; i < posicaoDeletar; i++) {
        aux = aux->proximo;
    }
    
    if (aux == NULL) {
        return false;
    }
        
    if (aux -> proximo != NULL && aux -> anterior != NULL) {
        aux->proximo->anterior = aux->anterior;
        aux->anterior->proximo = aux->proximo;
        
        free(aux);
        cabecalho->tamanho--;
        return true;
    }
    
    if (aux -> anterior == NULL) {
        aux -> proximo -> anterior = NULL;
        cabecalho -> primeiro = aux -> proximo;
        free(aux);
        cabecalho->tamanho--;
        return true;
    }
    
    if (aux -> proximo == NULL) {
        aux -> anterior -> proximo = NULL;
        cabecalho -> ultimo = aux -> anterior;
        free(aux);
        cabecalho->tamanho--;
        return true;
    }
}

void imprimir(Cabecalho*cabecalho){
    No *aux = cabecalho->primeiro;
    while(aux != NULL){
    printf("Nome - %s \n", aux->dado.nome);
    printf("Sobrenome - %s \n", aux->dado.sobrenome);
    printf("E-mail - %s \n", aux->dado.email);
    printf("Celular - %s \n", aux->dado.fone);
    printf("\n\n");

    aux = aux->proximo;
    
    }
	printf("\n\n");
}

void buscar(Cabecalho* cabecalho, int posicao){
    No *aux = cabecalho->primeiro;
    
    for (int i = 0; i < posicao; i++) {
        aux = aux->proximo;
    }
    
    if (aux == NULL) {
        printf("Nao foi possivel encontrar o item na posicao %d!", posicao);
    } else {
    printf("Nome - %s \n", aux->dado.nome);
    printf("Sobrenome - %s \n", aux->dado.sobrenome);
    printf("E-mail - %s \n", aux->dado.email);
    printf("Celular - %s \n", aux->dado.fone);
    printf("\n\n");
    }
}
