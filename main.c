#include <stdio.h>
#include <string.h>
#include "agenda.h"
#include <stdlib.h>

#define TEXTO_DO_MENU "1- Buscar Contato \n2- Inserir Contato \n3- Remover Contato \n0- Sair \n"

#define BUSCAR_CONTATO 1
#define INSERIR_CONTATO 2
#define REMOVER_CONTATO 3
#define SAIR 0


int
main ()
{
  int opcao;
  Cabecalho cabecalho;
  Contato contato, contatoDois, contatoTres, contatoQuatro;
  int retorno;

  inicializar (&cabecalho);

  do
    {
      printf (TEXTO_DO_MENU);
      scanf ("%i", &opcao);

      switch (opcao)
	{
	case BUSCAR_CONTATO:
	  // Chamar funcao de buscar contato
	  break;

	case INSERIR_CONTATO:
	  // Chamar funcao de inserir contato
	  strcpy (contato.nome, "Ricardo");
	  strcpy (contato.sobrenome, "Balao");
	  strcpy (contato.email, "ricardo@gmail.com");
	  strcpy (contato.fone, "519813123123");

	  retorno = inserir (&cabecalho, contato);
	  printf ("tamanho %d \n", cabecalho.tamanho);

	  strcpy (contatoDois.nome, "Adriano");
	  strcpy (contatoDois.sobrenome, "Casa");
	  strcpy (contatoDois.email, "adriano_casa@gmail.com");
	  strcpy (contatoDois.fone, "519813123123");

	  retorno = inserir (&cabecalho, contatoDois);
	  printf ("tamanho %d \n", cabecalho.tamanho);

	  strcpy (contatoTres.nome, "Roberto");
	  strcpy (contatoTres.sobrenome, "Dado");
	  strcpy (contatoTres.email, "roberto_dado@gmail.com");
	  strcpy (contatoTres.fone, "519813123123");

	  retorno = inserir (&cabecalho, contatoTres);
	  printf ("tamanho %d \n", cabecalho.tamanho);

	  strcpy (contatoQuatro.nome, "Carlos");
	  strcpy (contatoQuatro.sobrenome, "Azul");
	  strcpy (contatoQuatro.email, "carlos_azul@gmail.com");
	  strcpy (contatoQuatro.fone, "519813123123");

	  retorno = inserir (&cabecalho, contatoQuatro);
	  printf ("tamanho %d \n", cabecalho.tamanho);

	  printf ("%s \n", cabecalho.primeiro->dado.sobrenome);
	  printf ("%s \n",
		  cabecalho.primeiro->proximo->anterior->dado.sobrenome);

	  printf ("%s \n", cabecalho.primeiro->proximo->dado.sobrenome);
	  printf ("%s \n",
		  cabecalho.primeiro->proximo->proximo->anterior->dado.
		  sobrenome);

	  printf ("%s \n",
		  cabecalho.primeiro->proximo->proximo->dado.sobrenome);
	  printf ("%s \n",
		  cabecalho.primeiro->proximo->proximo->proximo->anterior->
		  dado.sobrenome);

	  printf ("%s \n",
		  cabecalho.primeiro->proximo->proximo->proximo->dado.
		  sobrenome);
	  printf ("%s \n", cabecalho.ultimo->dado.sobrenome);

	  break;

	case REMOVER_CONTATO:
	  // Chamar funcao de remover contato
	  break;

	case SAIR:
	  printf ("Adeus\n");
	  break;

	default:
	  printf ("Opcao invalida!\n");
	  break;
	}
    }
  while (opcao != SAIR);

  return 0;
}
