#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class No{
	public:
		int mat;
		char nome[23];
		No *prox;
		No(int m,char n[23]){
			mat = m;
			strcpy(nome,n);
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


		void addToFinal(int m, char n[23]){
            No *novo = new No(m,n);
            novo->prox = NULL;
            if (inicio == NULL){
                inicio = novo;
                fim = novo;
            } else {
                fim->prox = novo;
                fim = novo;
            }

		}

		void addToInicio(int m,char n[23]){
            No *novo = new No(m,n);
            novo->prox = NULL;
            if (inicio == NULL){
                inicio = novo;
                fim = novo;
            } else {
                novo->prox = inicio;
                inicio = novo;
            }


		}

		void addOrd(int m,char n[23]){

		}
		void mostra(){
            No *atual = inicio;
            while (atual != NULL){
                cout << "\nMatricula: " << atual->mat;
                cout << "\nNome: " << atual->nome << endl;
                atual = atual->prox;
            }
		}

		int remove(int mat){
            No *anterior, *atual;
            atual = inicio;
            if(inicio->mat == mat){
                inicio = inicio->prox;
            }
            if(fim->mat == mat){
                fim = anterior;
                fim->prox = NULL;
            }else{
                while(atual != NULL){
                    if(atual->mat == mat){
                       anterior->prox = atual->prox;
                    }else{
                        atual = atual->prox;
                    }
                }
            }

		 }




		No *busca(int mat){
            No *atual;
            atual = inicio;
            while(atual != NULL){
                if(atual->mat == mat){
                    return atual;
                }else{
                    atual = atual->prox;
                }
            }
        }


		int lst_vazia(){
            if( inicio == NULL){
                return 1;
            }else{
                return 0;
            }
		}

		void removeTodos(){
            inicio = NULL;
            fim = NULL;
		}

};
main(){
    Lista *l=new Lista();

    l->addToFinal(1,"azul");
    l->addToFinal(2,"verde");
    l->mostra();

    cout << endl << "INSERINDO NO INICIO";
    l->addToInicio(3,"Breno");
    l->addToInicio(4,"Sywrah");
    l->mostra();

    cout << endl << "INSERINDO NO FINAL";
    l->addToFinal(0,"Mario");
    l->mostra();

    cout << "LISTA VAZIA: " << l->lst_vazia() << endl;

    cout << endl << "------ BUSCA ------" << endl;
    cout << endl << l->busca(2);
    //l->mostra();



}
