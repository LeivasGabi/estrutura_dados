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
  cabecalho->tamanho++;

  if (cabecalho->primeiro == NULL)	// Primeira insercao
    {
      cabecalho->primeiro = novoNo;
      cabecalho->ultimo = novoNo;

      return true;
    }

  posicao = descobrirPosicao (cabecalho, contato.sobrenome);

  noDeAjuda = cabecalho->primeiro;

  if (posicao == 0)		// Antes do Primeiro
    {
      novoNo->proximo = noDeAjuda;
      noDeAjuda->anterior = novoNo;
      cabecalho->primeiro = novoNo;

      return true;
    }

  if (posicao == cabecalho->tamanho) // Ultimo
    {
      cabecalho->ultimo->proximo = novoNo;
      novoNo->anterior = cabecalho->ultimo;
      cabecalho->ultimo = novoNo;

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

  return true;
}

int
deletar (Cabecalho * cabecalho, Contato contato)
{

}
