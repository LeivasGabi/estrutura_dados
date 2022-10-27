typedef struct{
    char nome[100];
    char sobrenome[100];
    char email[150];
    char fone[15]
} contato;

typedef struct{
    contato dado;
	  struct tipoNo* proximo;
	  struct tipoNo* anterior;
} tipoNo;

typedef struct {
    tipoNo* primeiro;
	  tipoNo* ultimo;
    int tamanho;
} cabecalho;
