#include <stdio.h>
#include <string.h>
#include "agenda.h"
#include <stdlib.h>

#define TEXTO_DO_MENU "1- imprimir lista \n2- Inserir Contato \n3- Remover Contato \n4- Pesquisar Contato \n0- Sair \n"

#define IMPRIMIR_LISTA 1
#define INSERIR_CONTATO 2
#define REMOVER_CONTATO 3
#define PESQUISA_LISTA 4
#define SAIR 0


int
main ()
{
  int opcao;
  Cabecalho cabecalho;
  Contato contato;
  int retorno;
  int posicaoDeletar;
  int posicao;

  inicializar (&cabecalho);

  do
    {
      printf (TEXTO_DO_MENU);
      scanf ("%i", &opcao);
      getchar ();

      switch (opcao){
    	case IMPRIMIR_LISTA:
    	    imprimir(&cabecalho);
    	  break;
    
    	case INSERIR_CONTATO:
    	  printf ("Digite o nome: ");
    	  fgets (contato.nome, sizeof (contato.nome), stdin);
    
    	  printf ("Digite o sobrenome: ");
    	  fgets (contato.sobrenome, sizeof (contato.sobrenome), stdin);
    
    	  printf ("Digite o email: ");
    	  fgets (contato.email, sizeof (contato.email), stdin);
    
    	  printf ("Digite o fone: ");
    	  fgets (contato.fone, sizeof (contato.fone), stdin);
    
    	  retorno = inserir(&cabecalho, contato);
    	  
    	  break;
    
    	case REMOVER_CONTATO:
    	    printf("Digite qual posiÃ§Ã£o voce deja remover: ");
            scanf("%i", &posicaoDeletar);
            
            retorno = deletar(&cabecalho, posicaoDeletar);
            if(retorno == 0){
            printf("\n\nERRO nÃ£o foi possivel remover\n\n");
            }
            if(retorno == 1){
            printf("\n\nNÃ³ removido com sucesso\n\n");
            }
        break;
        
        case PESQUISA_LISTA:
        
        printf("Digite a posicao que voce deseja visualizar: ");
        scanf("%d", &posicao);
        
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
