#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Livros{
	int id;
	char titulo[30];
	char autor[30];
	Livros* prox;
}livros;

livros *lista;
livros *inicio = NULL;

livros* inserirLivro(livros* plivros, int idf, char *titulof, char *autorf){
	
	livros* novo = (livros *) malloc(sizeof(livros));
		
	novo->id = idf;
  	strcpy(novo->titulo,titulof);
  	strcpy(novo->autor,autorf);
  	novo->prox = plivros;
  	
  	return novo; 
}

void mostrarTitulo(livros* plivros){
	livros* aux=plivros;
	
	if(aux == NULL){
		printf("nemhum livro\n");
	}else{
		printf("------ Titulos dos Livros ------\n\n");
		while (aux!=NULL){
			printf("ID: %d--%s", aux->id,aux->titulo);
			aux = aux->prox;
		}
		printf("\n");
	}
}

livros* removerLivro(char *tituloR, livros* plivros){
	livros* ant = NULL;
	livros* p=plivros;
	
	while(p != NULL && strcmp(p->titulo, tituloR) != 0){
		ant=p;
		p=p->prox;
	}
	if(p == NULL){
		return plivros;
	}
	if(ant == NULL){
		inicio = p->prox;
	}else{
		ant->prox = p->prox;
	}
	free (p);
	printf("Livro Removido com sucesso!\n\n");
	return inicio;
}

int main(){
    int id=0, i=0;
    float soma=0;
    int opcao;
    char titulo[50];
    char autor[50];
   
    while(1){
    printf("-----------Bem Vindo-------------\n");
    printf("---------------------------------\n");
    printf("1 adcionar livro\n");
    printf("2 Mostra todos os Titulos\n");
    printf("3 Excluir Livro\n");
    printf("0 Sair\n");
    printf("-----------------------------------\n");
    printf("opcao: ");
    scanf("%d",&opcao);
    setbuf(stdin,NULL);
    
    switch(opcao){
	    case 0:
	      printf("\nSistema Finalizado!\n\n");
            exit(0);
        break;
        case 1:
            system("cls");
           
			 printf("Titulo: ");
		     setbuf(stdin,NULL);
		     fgets(titulo,50,stdin);
		     printf("Autor: ");
		     setbuf(stdin,NULL);
		     fgets(autor,50,stdin);
		     id++;
     
            inserirLivro(inicio,id,titulo,autor);
            printf("\nLivro Cadastrado!\n\n");
            break;
        case 2:
        	system("cls");
        	mostrarTitulo(lista);
        break;
        case 3:
        	system("cls");
        	
        	printf("Titulo: ");
		    setbuf(stdin,NULL);
		    fgets(titulo,50,stdin);
		     
        	removerLivro(titulo, lista);
 
        break;
        default:
            printf("\n\nOpcao invalida!\n\n");
       }
    }
    return 0;
}

