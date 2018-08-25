#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//fazendo pilha de caracteres

class No{
	public:
		char letra;
		No *prox;
		
		No(char l){
			letra = l;
			prox = NULL;
		}		
};

class Pilha{
	public:
		No *topo;
		
		Pilha(){
			topo = NULL;
		}
		
		void push(char l){
			No *novo = new No(l);
			if(topo == NULL){
				topo = novo;
			}else{
				novo->prox = topo;
				topo = novo;
			}
		}
		
		char pop(){
			if (topo == NULL){
				cout<<"Pilha vazia";
			}else{
				No *aux = topo;
				topo = topo->prox;
				free(aux);
				cout<<"caractere apagado";
			}
		}
		
		int esvaziar(){
			if(topo==NULL){
				cout<<"Pilha vazia";
			}else{
				No *aux = topo;
				while(aux != NULL){
					topo = topo->prox;
					free(aux);
					aux = topo;
				}
				cout<<"\nPilha esvaziada";
			}
		}
		
		void percorrerPilha(){
			if(topo == NULL){
				cout<<"Pilha vazia";
			}else{
				No *aux = topo;
				while(aux != NULL){
					cout<<aux->letra<<" ";
					aux = aux -> prox;
				}
			}
		}		
};

int main(){
	Pilha *p = new Pilha();
	
	p->push('a');
	p->push('k');
	p->push('d');
	
	p->percorrerPilha();
	
	
	p->push('g');
	p->push('L');
	
	cout<<endl;
	
	p->percorrerPilha();
	
	cout<<endl;
	p->pop();
	cout<<endl;
	p->pop();
	
	cout<<endl;
	
	p->percorrerPilha();
	p->esvaziar();
	
	cout<<endl;
	p->percorrerPilha();
}