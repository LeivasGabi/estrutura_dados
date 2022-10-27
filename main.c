#include <stdio.h>

#define TEXTO_DO_MENU "1- Buscar Contato \n2- Inserir Contato \n3- Remover Contato 0- Sair"

#define BUSCAR_CONTATO 1
#define INSERIR_CONTATO 2
#define REMOVER_CONTATO 3
#define SAIR 0


int main()
{
    int opcao;

    do
    {
        printf(MENU_TEXT);
        scanf("%i", &opcao);

        switch (option)
        {
        case BUSCAR_CONTATO:
            // Chamar funcao de buscar contato
            break;

        case INSERIR_CONTATO:
            // Chamar funcao de inserir contato
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
    } while (option != SAIR);

    return false;
}

