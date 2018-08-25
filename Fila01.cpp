#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

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
		
		void inserir(char n){
			No *novo = new No(n);
			if(inicio == NULL){
				inicio = novo;
				fim = novo;
			}else{
				fim->prox = novo;
				fim = novo;
			}
		}
		
		char apagar(){
			No *temp;
			char nome;
			if(inicio != NULL){
				temp = inicio;
				nome = inicio->nome;
				inicio = inicio->prox;
				free(temp);
			}
			return nome;
		}
		
		int isEmpty(){
			return (inicio == NULL);
		}
	
	// Nao aconselhavel para PILHAS	
	//	void showAll(){
	//		No *atual = topo;
	//		while(atual != NULL){
	//			cout << "End: " << &atual << " // Valor: " << atual->nome << " // Prox: " << atual->prox << endl;
	//			atual = atual->prox;
	//		}
	//	}
};

int main(){
	/*Pilha *p=new Pilha();
	p->push('A');
	p->push('B');
	p->push('C');
//	p->showAll();*/
    Fila *f1=new Fila();
    Fila *f2=new Fila();
    f1->inserir('A');
	f1->inserir('B');
	f1->inserir('C');
	
    
	

	
}
