#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class No{
	public:
		char letra;
		No *prox;
		
		No(char l){
			letra = l;
			prox = NULL;
		}
};

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
			if(inicio == NULL){
				inicio = novo;
				final = novo;
			}else{
				final->prox = novo;
				final = novo;
			}
		}
		
		void percorrer(){
			if(inicio==NULL){
				cout<<"Fila vazia";
			}else{
				No *aux = inicio;
				cout<<"Consultando Fila\n";
				while(aux!=NULL){
					cout<<aux->letra<<" ";
					aux = aux->prox;
				}
				
			}
		}
		
		char apagar(){
			if(inicio == NULL){
				cout<<"Fila vazia";
			}else{
				No *aux = inicio;
				inicio = inicio->prox;
				free(aux);
				cout<<"Letra removida";
			}
		}	
};

int main(){
	Fila *f = new Fila();
	
	f->inserir('a');
	f->inserir('b');
	
	cout<<endl;
	f->percorrer();
	
	
}

