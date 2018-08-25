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
			nome=n;
			prox=NULL;
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
		void insereNaFila(char n){
			No *novo= new No(n);
			if (inicio==NULL){  //fila vazia
				inicio = novo;	
				fim = novo;			
			}
			else{ // insere o elemento e modifica o topo
				fim->prox=novo;
				fim=novo;
			}
		}
		//retirar o elemento do topo
		char retiraDaFila(){
			No *el;
			char nome;
			if (inicio!=NULL){
				el=inicio;
				nome=el->nome;
				inicio=inicio->prox;
				free(el);
			}
			return nome;
		}
		
		int fila_vazia(){
			return (inicio==NULL);
		}
		
		void mostra(){
			No *atual;
			atual=inicio;
			
		    cout<<"\n\n--------Mostra a Fila---------------\n\n";
		    while (atual!=NULL){
		    	printf("\nNome %c\n",atual->nome);			
				atual = atual->prox;
			}					
		}			
	};


int main(){
   Fila *l1=new Fila();
   Fila *l2=new Fila();
   int resp =1;
   char letra;
   	  
   while(resp==1){
       cout<<"\nDigite a letra:";
   	  cin>>letra;
   
         while(!l1->fila_vazia()){
          	l2->insereNaFila(l1->retiraDaFila());
          }
          l1->insereNaFila(letra);
          while(!l2->fila_vazia()){
          	l1->insereNaFila(l2->retiraDaFila());
         }
         l1->mostra();
   	  cout<<"\nDeseja continuar (1-Sim 2-Nao)?";
   	  cin>>resp;
   }

}