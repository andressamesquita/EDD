#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

class No{
   public:
	char info;
	No *esq;
	No *dir;
	No(char n,No *e,No *d){
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

		No *cria_Raiz(char n, No *e,No *d){
			No *novo = new No(n,e,d);
			raiz = novo;
			return raiz;
		}

		int arv_vazia(No *n){
			return (n == NULL);
		}

		void arv_cheia(No *n){
		    int altura = altura_Arvore(n);
            if(numero_Nos(n) == (pow(2,altura +1) - 1)){
                cout << endl << "ARVORE CHEIA: SIM!";
            }
            cout << endl << "ARVORE CHEIA: NAO!";
		}

		No *arv_libera(No *n){
            if(!arv_vazia(n)){
                arv_libera(n->esq);
                arv_libera(n->dir);
                free(n);
            }
            return NULL;
		}

		No *buscar_Elemento(char ch, No *raiz){
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

        No *cria_vazia(){
			return NULL;
		}
		No *cria_No(char n, No *e,No *d){
			No *novo = new No(n,e,d);
			return novo;
		}

        bool inserir(No *arv, No *novo, int lado, char pai){
            if(arv != NULL){
                if(arv->info == pai){
                    if(lado == 1){
                        if(arv->esq == NULL){
                            arv->esq = novo;
                        }else{
                            cout << "\n ERRO - JA EXISTE UM NO NESSA POSICAO!";
                        }
                    }
                    if(lado == 2){
                        if(arv->dir == NULL){
                            arv->dir = novo;
                        }else{
                            cout << "\n ERRO - JA EXISTE UM NO NESSA POSICAO!";
                        }
                    }
                }else{
                    inserir(arv->dir, novo, lado, pai);
                    inserir(arv->esq, novo, lado, pai);
                }
            }
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

        int numero_Nos(No *raiz){
            if(raiz == NULL){
                return 0;
            }else{
                return (1 + numero_Nos(raiz->esq) + numero_Nos(raiz->dir));
            }
        }

        int altura_Minima(No *n){
            return (log2(numero_Nos(n)) + 1);
        }

        int altura_Arvore(No *raiz){
            int esquerda, direita;
            if(raiz == NULL){
                return -1;
            }else{
                esquerda = altura_Arvore(raiz->esq);
                direita = altura_Arvore(raiz->dir);
            }
            if(esquerda < direita){
                return direita + 1;
            }else{
                return esquerda + 1;
            }
        }

        void completa(No* raiz){
            if((altura_Arvore(raiz) + 1) == altura_Minima(raiz)){
                cout << endl << "ARVORE COMPLETA!!";
            }else{
                cout << endl << "ARVORE INCOMPLETA!";
            }
        }

};

int main() {
    Arvore *arv = new Arvore();

	No *h = arv->cria_No('H',NULL,NULL);
	No *i = arv->cria_No('I',h,NULL);
	No *g = arv->cria_No('G',NULL,i);
	No *e = arv->cria_No('E',NULL,NULL);
	No *c = arv->cria_No('C',NULL,NULL);
	No *d = arv->cria_No('D',c,e);
	No *a = arv->cria_No('A',NULL,NULL);
	No *b = arv->cria_No('B',a,d);

	arv->raiz = arv->cria_Raiz('F',b,g);


    arv->imprime(arv->raiz);
    arv->completa(arv->raiz);
    arv->arv_cheia(arv->raiz);

    cout << endl << "Busca: " << arv->buscar_Elemento('X', arv->raiz);

    cout << endl << "N nos: " << arv->numero_Nos(arv->raiz);
    cout << endl << "Altura: " << arv->altura_Arvore(arv->raiz);
    return 0;
}

