#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
class No{
	public:
		int mat;
		char nome[23];
		No *prox;
		No(int m,char n[23]){
			mat=m;
			strcpy(nome,n);
			prox=NULL;
		}
};

class Lista{

	No *inicio,*fim;
	public:
	Lista(){
		inicio=NULL;
		fim=NULL;
	}
	void add_fim(int m, char n[23]){

	}

	void add_inicio(int m, char n[23]){

}
	void addord(int m,char n[23]){
		}



	}

	void mostrar(){
		No *atual = inicio;
		while (atual!=NULL){
			cout<<"\nMat:"<<atual->mat<<" Nome:"<<atual->nome;
			atual=atual->prox;

		}
   }

	void remover(int cod){
	}



};

main(){
	Lista *turma = new Lista();

	//turma->inv_lista2();

}
