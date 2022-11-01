typedef struct{
	char nome[100];
	char sobrenome[100];
	char email[150];
	char fone[15]
} contato;

typedef struct{
	contato dado;
  	struct no* proximo;
	struct no* anterior;
} no;

typedef struct {
	no* primeiro;
	no* ultimo;
	int tamanho;
} cabecalho;

int insert (cabecalho *cabeca, contato c); 
int deletar (cabecalho *cabeca, contato c);