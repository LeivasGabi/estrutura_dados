#include <stdio.h>
#include <string.h>
#include "agenda.h"
#include <stdlib.h>

void inicializar (Cabecalho *cabecalho) {
    cabecalho -> primeiro = NULL;
    cabecalho -> ultimo = NULL;
    cabecalho -> tamanho = 0;
}

int inserir (Cabecalho *cabecalho, Contato contato) {
	No *novoNo = (No*)malloc(sizeof(No));
	int retorno, continua;
	
	
	if(novoNo == NULL){
		return 0;
	}

	strcpy(novoNo -> dado.nome, contato.nome);
	strcpy(novoNo -> dado.sobrenome, contato.sobrenome);
	strcpy(novoNo -> dado.email, contato.email);
	strcpy(novoNo -> dado.fone, contato.fone);
	
	
	
	if (cabecalho -> primeiro == NULL) {
	    cabecalho -> primeiro = novoNo;
	    
	    return 1;
	}

	return 1;
}

int deletar (Cabecalho *cabecalho, Contato contato) {
	
}