/* Implementa��o de uma pilha din�mica utilizando ponteiro topo para controlar a pila */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct no
{
	int valor;
	struct no* prox;
};
struct no *topo = NULL;
/* Fun��o insere elemento na pilha */
void push(int i)//adcionar elementos para o topo da pilha,fun��o para  as  pilhas
{
	struct no *novo = (struct no*) malloc(sizeof(struct no));
	//certo alocamos dinamicamente e  ambos os ponteiros est�o apontando para a estruct livro estou correto 
	novo -> valor = i;
	if(topo == NULL)
	novo ->prox = NULL;
	else
		novo ->prox = topo;
		topo = novo;
}
int pop()
{
	//No contexto de uma pilha, a fun��o pop � usada para remover o elemento do topo da pilha, 
	int valor;
	struct no *aux;
	if(topo != NULL)
	{
	aux = topo;
	valor = topo ->valor;
	topo = topo ->prox;
	free(aux);
	return valor;
	}
	else
	{
		printf("\nTentou remover de uma pilha vazia");
		return 0;
	}
	
	
}
void imprime()
{
	struct no *aux;
	if(topo != NULL)
	{
		for(aux=topo; aux != NULL; aux=aux ->prox)
		printf("valor = %d\n",aux ->valor);
	}
	else
	{
			printf("\Tentou imprimir de uma pilha vazia");

		
	}
			getche();

}

main()
{
	int op,valor,retorno;
	while(op!= 4)
	{
		system("cls");
		printf("Programa para manipula��o de pilha");
		printf("Digite 1 para inserir elemento na pilha\n");
		printf("Digite 2 para imprimir a pilha\n");
		printf("Digite 3 para remover elemento da pilha\n");
		printf("Digite 4 para sair \n");
		printf("Entre com a op��o desejada:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Entre com um elemento inteiro para a pilha: ");
				scanf("%d",&valor);
				push(valor);
				break;
			case 2:
				imprime();
				break;
			case 3:
				retorno = pop();
				if(retorno != 0)
					printf("\nO valor removido foi: %i",retorno);
					getche();
					break;
			case 4:
				exit(1);
				break;
				default:
					printf("opcao invalida");
					
					
		}
		
	}
}
