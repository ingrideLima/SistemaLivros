#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp{
	int id;
	char titulo[30];
	char autor[30];
	struct temp *prox;
}Livros;

Livros *lista, *atual, *antes;
Livros *inicio = NULL;

Livros inserirLivro(Livros **plivros, int idf, char *titulof, char *autorf){
	
	lista = (Livros *) malloc(sizeof(Livros));

    atual = *plivros;
    antes = NULL;

    strcpy(lista->titulo,titulof);
    strcpy(lista->autor,autorf);
    lista->id = idf;

    if(atual == NULL){
        lista->prox = NULL;
        *plivros = lista;
    }else{
        while(atual != NULL && atual->id < idf){
            antes = atual;
            atual = atual->prox;
        }
        lista->prox = atual;

        if(antes == NULL){
            *plivros = lista;
        } else{
            antes->prox = lista;
        }
    } 
    
    printf("\nLivro Cadastrado com Sucesso!\n\n");
}

void mostrarTitulo(Livros *plivros){
	Livros *aux;
	aux=plivros;
    
	if(aux == NULL){
	    printf("\nNenhum Livro\n\n");
	}else{    
        printf("---------Lista dos Livros------------\n");
        printf("Id-----Titulo\n");
        while(aux != NULL){
            printf("%d-----%s", aux->id, aux->titulo);
            aux = aux->prox;
        }
        printf("------------------------------------\n\n");
	}
}

//int listaVazia(Livros* l){
//	return (l == NULL);
//}
//
//Livros* lst_retira(Livros* l, char *tituloR){
//	Livros* ant = NULL;
//	Livros* p=l;
//	
//	while(p != NULL && strcmp(p->titulo, tituloR) != 0){
//		ant =p;
//		p=p->prox;
//	}
//	if(p==NULL){
//		return l;
//	}
//	if(ant == NULL){
//		lista = p->prox;
//	}else{
//		ant->prox = p->prox;
//	}
//	free(p);
//	setbuf(stdin,NULL);
//	return lista;
//}
//
//Livros* removerLivro(char *tituloR, Livros *plivros){
//	if(!listaVazia(lista)){
//		if(strcmp(plivros->titulo, tituloR) == 0){
//			Livros *t=plivros;
//			plivros = plivros->prox;
//			free(t);	
//		}else{
//			plivros->prox = lst_retira(lista->prox, tituloR);
//		}
//	}
//	printf("Livro Removido com sucesso!\n\n");
//	return lista;
//}

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
     
            inserirLivro(&inicio, id, titulo, autor);
    
            break;
        case 2:
        	system("cls");
        	mostrarTitulo(inicio);
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
