#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class No{
	public:
	   char letra;
	   No *prox;
	   
	   //construtor
	   No(char l){
		   letra = l;
		   prox = NULL;
	   }	
};//não esquecer de colocar o ";"

class Fila{
	public:
		No *inicio;
		No *final;
		
		Fila(){
			inicio = NULL;
			final = NULL;
		}
		
		void inserir(char l){
			No *novo = new No(l);
			if(inicio==NULL){
 				inicio = novo;
				final = novo;
			}else{
				final->prox = novo;
				final = novo;
			}
		}
		
		void percorrer(){
			if(isEmpty()){
				cout<<"Fila vazia!";
			}else{
				No *aux = inicio;
				cout<<"Consultando a Fila!";
				while(aux!=NULL){
					cout<<inicio->letra<<" ";
					aux = aux->prox;
				}
			}
		}
		
		void apagar(){ //apaga sempre no inicio
			
			if (inicio == NULL){
				cout<<"Fila vazia!";
			}else{
				No *aux = inicio;
				inicio = inicio->prox;
				free(aux);
				cout<<inicio->letra<<"removida";
			}
		}
		
		int isEmpty(){
			return (inicio==NULL);
		}
};
int main(){
	
	Fila *f1 = new Fila();
	int op;
	do{
		cout<<"\nMENU";
		cout<<"\n1 - Inserir na fila";
		cout<<"\n2 - Percorrer a fila";
		cout<<"\n3 - Retirar da fila";
		cout<<"\n4 - Esvaziar a fila";
		cout<<"\n5 - Sair";
		cout<<"\nEscolha uma opcao: ";
		cin>>op;
		
		if(op ==1){
			f1->inserir('A');
		}
		if(op==2){
			f1->percorrer();
		}
		if(op==3){
			f1->apagar();
		}
		if(op==4){
			f1->isEmpty();
		}
		
	}while(op!=5);
}