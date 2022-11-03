#include <stdio.h>
#include <string.h>
#include "agenda.h"
#include <stdlib.h>

#define TEXTO_DO_MENU "1- Buscar Contato \n2- Inserir Contato \n3- Remover Contato \n0- Sair \n"

#define BUSCAR_CONTATO 1
#define INSERIR_CONTATO 2
#define REMOVER_CONTATO 3
#define SAIR 0


int main()
{
    int opcao;
    Cabecalho cabecalho;
    Contato contato;
    int retorno;
    
    inicializar(&cabecalho);

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
            strcpy(contato.nome, "Leonardo");
            strcpy(contato.sobrenome, "Marcos");
            strcpy(contato.email, "leonardo@gmail.com");
            strcpy(contato.fone, "519813123123");

            retorno = inserir(&cabecalho, contato);
            
            printf("retorno da insercao: %d \n", retorno);

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
