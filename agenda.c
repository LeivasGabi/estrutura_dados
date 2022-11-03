#include <stdio.h>
#include <string.h>
#include "agenda.h"
#include <stdlib.h>

int inserir (Cabecalho *cabeca, Contato contato) {
	No *novoNo = (No*)malloc(sizeof(No));
	int retorno, continua;
	
	
	if(novoNo == NULL){
		return 0;
	}

	strcpy(novoNo -> dado.nome, contato.nome);
	strcpy(novoNo -> dado.sobrenome, contato.sobrenome);
	strcpy(novoNo -> dado.email, contato.email);
	strcpy(novoNo -> dado.fone, contato.fone);
	
	do {
		
	} while (continua != 0);
	
	return 1;
}

int deletar (Cabecalho *cabecalho, Contato contato) {
	
}