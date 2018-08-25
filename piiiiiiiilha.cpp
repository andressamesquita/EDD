#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
class No{
	public:
		char letra;
		No *prox;
		
		No(char a){
			letra = a;
			prox = NULL;		
		}			
};

class Pilha{
	public: 
		No *topo;
		
		Pilha(){
			topo = NULL;
		} 
		
		void inserir(char a){
			No *novo = new No(a);
			if(topo == NULL){
				topo = novo;	   	   
			}else{
				novo->prox = topo;
				topo = novo;			
			}
			
		}
		
		void percorrer(){
			if(topo==NULL){
				cout<<"\nPilha vazia!";
			}else{
				No *aux = topo;
				while(aux!=NULL){
					cout<<aux->letra<<" ";
					aux = aux->prox;			
				}
			}
		}
		
		char pop(){
			if (topo==NULL){
				cout<<"\nPilha vazia";
			}else{
				No *aux = topo;
				topo = topo->prox;
				free(aux);
				cout<<"\nElemento apagado\n";
			}
		}
		
		void limparPilha(){
			if(topo==NULL){
				cout<<"Pilha vazia";
			}else{
				No *aux = topo;
				while(aux!=NULL){
					topo = topo->prox;
					free(aux);
					aux = topo;
				}
				cout<<"Pilha vazia";
			}
		}
};

int main(){
	
	Pilha *pilha = new Pilha();
	
	pilha->inserir('i');

	pilha->inserir('f');
	pilha->inserir('v');
	
	pilha->inserir('L');
	
	cout<<endl;
	
	pilha->percorrer();
	
	pilha->pop();
	
	pilha->percorrer();
	
	pilha->limparPilha();
	
	pilha->percorrer();
	
	
}