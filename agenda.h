typedef struct{
	char nome[100];
	char sobrenome[100];
	char email[150];
	char fone[15];
} Contato;

typedef struct{
	Contato dado;
  	struct No* proximo;
	struct No* anterior;
} No;

typedef struct {
	No* primeiro;
	No* ultimo;
	int tamanho;
} Cabecalho;

int inserir (Cabecalho *cabecalho, Contato contato); 
int deletar (Cabecalho *cabecalho, Contato contato);
void inicializar (Cabecalho *cabecalho);