#include<iostream>
#include<stdlib.h>
#include<stdio.h>

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

class Pilha{
    public:
        No *topo;

        Pilha(){
            topo = NULL;
        }

        void imprime(){
            cout << "PILHA: " << endl;
            No *aux = topo;
            while(aux != NULL){
                cout << aux->nome << endl;
                aux = aux->prox;
            }
        }

        bool vazia(){
            if(topo == NULL){
                return true;
            }else{
                return false;
            }
        }

        int tamanho(){
            int tam = 0;
            No *aux = topo;

            while(aux != NULL){
                tam++;
                aux = aux->prox;
            }
            return tam;
        }

        void inserir(char nome){
            No *novo = new No(nome);
            novo->prox = topo;
            topo = novo;
        }

        bool remover(){
            if(topo == NULL){
                cout << "Pilha vazia!";
                return false;
            }else{
                No *apagar = topo;
                topo = topo->prox;
                free(apagar);
                return true;
            }
        }

        void reinicializar(){
            No *apagar;
            No *posicao = topo;

            while(posicao != NULL){
                apagar = posicao;
                posicao = posicao->prox;
                free(apagar);
            }

            topo = NULL;
        }

};
int main(){
    Pilha *p = new Pilha();

    p->inserir('S');
    p->inserir('Y');
    p->inserir('W');
    p->inserir('R');
    p->inserir('A');
    p->inserir('H');

    p->imprime();
    p->remover();
    p->imprime();

    return 0;
}
