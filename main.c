#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXTO_DO_MENU                                                          \
  "1- Buscar Contato \n2- Inserir Contato \n3- Remover Contato \n0- Sair \n"

#define BUSCAR_CONTATO 1
#define INSERIR_CONTATO 2
#define REMOVER_CONTATO 3
#define SAIR 0

int main() {
  int opcao;
  Cabecalho cabecalho;
  Contato contato;
  int retorno;
  int posicaoDeletar;

  inicializar(&cabecalho);

  do {
    printf(TEXTO_DO_MENU);
    scanf("%i", &opcao);
    getchar();

    switch (opcao) {
    case BUSCAR_CONTATO:
      // Chamar funcao de buscar contato
      break;

    case INSERIR_CONTATO:
      printf("Digite o nome: ");
      fgets(contato.nome, sizeof(contato.nome), stdin);

      printf("Digite o sobrenome: ");
      fgets(contato.sobrenome, sizeof(contato.sobrenome), stdin);

      printf("Digite o email: ");
      fgets(contato.email, sizeof(contato.email), stdin);

      printf("Digite o fone: ");
      fgets(contato.fone, sizeof(contato.fone), stdin);

      retorno = inserir(&cabecalho, contato);

      break;

    case REMOVER_CONTATO:
      printf("Digite qual posição voce deja remover: ");
      scanf("%i", &posicaoDeletar);

      retorno = deletar(&cabecalho, &posicaoDeletar);
      if(retorno == 0){
        printf("\n\nERRO não foi possivel remover\n\n");
      }
      if(retorno == 1){
        printf("\n\nNó removido com sucesso\n\n");
      }
      break;

    case SAIR:
      printf("Adeus\n");
      break;

    default:
      printf("Opcao invalida!\n");
      break;
    }
  } while (opcao != SAIR);

  return 0;
}
