#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

class No{
	public:
		int numero;
		No *prox;
	No(int n){
		numero = n;
		prox = NULL;
	}	 
};

class Lista{
	public:
		No *inicio;
		No *fim;
	Lista(){
		inicio = NULL;
		fim = NULL;
	}
	
	bool isEmpty(){
		if (fim == NULL){
			return true;
		}
		return false;
	}
	
	void inserirInicio(int n){
		No *novoNo = new No(n);
		if (isEmpty()){
			inicio = novoNo;
			fim = novoNo;
			fim->prox = inicio;
		}else{
			novoNo->prox = inicio;
	   	   	inicio = novoNo;		
		}

		
	}
	
	void inserirFim(int n){
		No *novoNo = new No(n);
		if (isEmpty()){
			inicio = novoNo;
			fim = novoNo;
			fim->prox = inicio;
		}else{
			fim->prox = novoNo;
			fim = novoNo;
			fim->prox = inicio;
		}

	}
	
	void removerInicio(){
		
		No *aux = inicio; 
		inicio = inicio->prox;
		fim->prox = inicio;
		free(aux);
	}
	
	void removerFim(){
		No *aux = inicio;
		No *aux2;
		while (aux != fim){
			aux2 = aux;
			aux = aux->prox;
		}
		aux2-> prox = inicio;
		fim = aux2;
		free(aux);
		
			
	}
	
	void mostrar(){
		No *atual = inicio;
		int X = 0;
		cout<<"Lista: "<<endl;
		while(atual != NULL && X < 5){
			cout<<atual->numero<<endl;
			atual = atual->prox;
			X++;
		}
		cout<<endl;
	}
	
	
};

int main(){
	Lista *lista = new Lista();
	lista->inserirFim(4);

	lista->inserirInicio(1);
	lista->inserirInicio(5);

	lista->inserirFim(7);
	lista->mostrar();
	
	lista->removerInicio();
	lista->mostrar();
	
	lista->removerFim();
	lista->mostrar();
}