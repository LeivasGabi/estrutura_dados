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
  Contato contato;
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
	  getchar ();

	  printf ("Digite o nome: ");
	  fgets (contato.nome, sizeof (contato.nome), stdin);

	  printf ("Digite o sobrenome: ");
	  fgets (contato.sobrenome, sizeof (contato.sobrenome), stdin);

	  printf ("Digite o email: ");
	  fgets (contato.email, sizeof (contato.email), stdin);

	  printf ("Digite o fone: ");
	  fgets (contato.fone, sizeof (contato.fone), stdin);

	  retorno = inserir (&cabecalho, contato);
	  
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
