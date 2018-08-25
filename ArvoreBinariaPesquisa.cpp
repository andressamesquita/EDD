#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

class No{
   public:
	int info;
	No *esq;
	No *dir;
	No(int n,No *e,No *d){
		info = n;
		esq = e;
		dir = d;
	}
};

class Arvore{
	public:
		No *raiz;
		Arvore(){
			raiz = NULL;
		}

		void imprime(No *n){
            if (raiz == NULL){
                cout << "\n VAZIO" << endl;
            } else {
                if (n!=NULL){
                    cout << "<" << n->info;
                    imprime(n->esq);
                    imprime(n->dir);
                    cout << ">";
                } else {
                    cout << "<>";
                }
            }
        }

		No *cria_Raiz(int n, No *e,No *d){
			No *novo = new No(n,e,d);
			raiz = novo;
			return raiz;
		}
        No *insere_Ordenado(No *raiz, No *novo){
            if(raiz == NULL){
                return novo;
            }
            if(novo->info < raiz->info){
                raiz->esq = insere_Ordenado(raiz->esq, novo);
            }else{
                raiz->dir = insere_Ordenado(raiz->dir, novo);
            }
            return raiz;
		}

		No *buscar_Elemento(int ch, No *raiz){
            if(raiz == NULL){
                return NULL;
            }
            if(raiz->info == ch){
                return raiz;
            }
            if(raiz->info > ch){
                return buscar_Elemento(ch, raiz->esq);
            }
            return buscar_Elemento(ch, raiz->dir);
		}

		int conta_Nos(No *raiz){
            return (1 + conta_Nos(raiz->esq) + conta_Nos(raiz->dir));
		}

};

int main() {
    Arvore *arv = new Arvore();

    arv->cria_Raiz(15,NULL,NULL);

    No *a = new No(10, NULL,NULL);
    No *b = new No(17, NULL,NULL);
    No *c = new No(9, NULL, NULL);


    arv->insere_Ordenado(arv->raiz, b);
    arv->insere_Ordenado(arv->raiz, a);
    arv->insere_Ordenado(arv->raiz, c);

    arv->imprime(arv->raiz);

    No *aux = arv->buscar_Elemento(7,arv->raiz);
    cout << endl << "Resultado da busca: " << aux->info;
    cout << endl << "Nos: " << arv->conta_Nos(arv->raiz);
}
