#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class No{
	public:
		char nome;
		No *prox;
		No(char n){
			nome = n;
			prox = NULL;
		}
};

class Fila{
	public:
		No *inicio;
		No *fim;

	    Fila(){
	    	inicio = NULL;
	    	fim = NULL;

		}
		//inserir um elemento no topo da fila
		void InsereFila(char n){
			No *novo= new No(n);
			if (inicio==NULL){  //fila vazia
				inicio = novo;
				fim = novo;
			}
			else{ // insere o elemento e modifica o topo
				fim->prox = novo;
				fim = novo;
			}
		}
		//retirar o elemento do topo
		char RetiraFila(){
			No *el;
			char nome;
			if (inicio!=NULL){
				el = inicio;
				nome = el->nome;
				inicio = inicio->prox;
				free(el);
			}
			return nome;
		}

		int fila_vazia(){
			return (inicio == NULL);
		}

		void mostra(){
			No *atual;
			atual = inicio;

		    cout<<"\n\n-------- Mostra a Fila ---------------\n\n";
		    while (atual!=NULL){
		    	printf("\nNome %c\n",atual->nome);
				atual = atual->prox;
			}
		}

	};


main(){
   Fila *l1=new Fila();
   Fila *l2=new Fila();
   int resp;
   char letra;

   do {


   	  cout<<"\nDigite a letra:";
   	  cin>>letra;

   	  if(l1->inicio!=NULL){
            No *atual = l1->inicio;
            while(atual!=NULL){
                l2->InsereFila(atual->nome);
                atual=atual->prox;
            }
            l1->InsereFila(letra);

            atual=l1->inicio;
            while(atual->prox!=NULL){
                l1->RetiraFila();
                atual=l1->inicio;
            }

            atual=l2->inicio;
            while(atual!=NULL){
                l1->InsereFila(atual->nome);
                atual=atual->prox;
            }

            atual = l2->inicio;
            while(atual->prox!=NULL){
                l2->RetiraFila();
                atual=l2->inicio;
            }
            l2->RetiraFila();

       }else{
            l1->InsereFila(letra);
       }
   	  l1->mostra();

   	  cout<<"\nDeseja continuar (1-Sim 2-Nao)?";
   	  cin>>resp;
   }while(resp==1);

}
