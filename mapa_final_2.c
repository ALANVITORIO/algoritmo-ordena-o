#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Constantes
#define E 0
#define D 1
#define R -1

//Tipo no
typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;

//Tipo arvore
typedef struct ARVORE{
	NO *raiz;
}ARVORE;

//Declaracao da arvore
ARVORE a;

//Protipos das funcoes
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);


//Funcao que sempre deve ser chamada ao se criar uma nova arvore
void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

//Funcao utilizada para inicializar um novo no na arvore
void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}

//Fun??o que realiza a inser??o de maneira ordenada
//Valores menores ou iguais v?o ? esquerda
//Valores maiores v?o ? direita
void insereNoArvoreOrdenada(int valor)
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("Inserindo no %d. \n", novoNo->dado);
	
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		printf("No inserido na raiz. \n");
		return;
	}
	
	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				printf("No inserido na esquerda do no %d. \n", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf("No inserido na direita do no %d. \n", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}
            
//Executa o caminhamento pr?-ordem a partir do n? indicado por "raiz"
void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}



int main()
{
	setlocale(LC_ALL, "Portuguese");
	inicializaArvore(a);
	
	insereNoArvoreOrdenada(2);
	insereNoArvoreOrdenada(1);
	insereNoArvoreOrdenada(0);

	insereNoArvoreOrdenada(9);
	insereNoArvoreOrdenada(6);
	insereNoArvoreOrdenada(6);
	insereNoArvoreOrdenada(8);
	insereNoArvoreOrdenada(0);
	insereNoArvoreOrdenada (5);
	
 
	printf("\nBusca pre ordem: \n");
	printf("\n R.A Aluno Alan Gustavo Vitorio : 210966805 \n");
	preOrdem(a.raiz);
	

}

