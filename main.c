#include <stdio.h>
#include "agenda.h"

#define TEXTO_DO_MENU "1- Buscar Contato \n2- Inserir Contato \n3- Remover Contato \n0- Sair \n"

#define BUSCAR_CONTATO 1
#define INSERIR_CONTATO 2
#define REMOVER_CONTATO 3
#define SAIR 0


int main()
{
    int opcao;
    Cabecalho cabecalho;

    do
    {
        printf(TEXTO_DO_MENU);
        scanf("%i", &opcao);

        switch (opcao)
        {
        case BUSCAR_CONTATO:
            // Chamar funcao de buscar contato
            break;

        case INSERIR_CONTATO:
            // Chamar funcao de inserir contato
            inserir(&cabecalho);
            break;

        case REMOVER_CONTATO:
            // Chamar funcao de remover contato
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
