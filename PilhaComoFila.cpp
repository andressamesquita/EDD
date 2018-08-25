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

        char remover(){
            char valor;
            if(topo != NULL){
                valor = topo->nome;
                topo = topo->prox;
            }
            return valor;
        }
};

int main(){
    Pilha *p1 = new Pilha();
    Pilha *p2 = new Pilha();

    int opcao;
    char letra;

    do{
        cout << endl << "Digite a letra: ";
        cin >> letra;

        if(p2->topo != NULL){
            No *cont = p2->topo;
            while(cont != NULL){
                char aux = p2->remover();
                p1->inserir(aux);
                cont = cont->prox;
            }
            p1->inserir(letra);

            cont = p1->topo;
            while(cont != NULL){
                char aux = p1->remover();
                p2->inserir(aux);
                cont = cont->prox;
            }
        }else{
            p2->inserir(letra);
        }

        p2->imprime();

        cout << endl << "Deseja continuar (1-Sim 2-Nao)? ";
        cin >> opcao;

    }while(opcao == 1);

    return 0;
}
