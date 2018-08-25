#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct{
    char info;
    No *esq;
    No *dir;
}No;

typedef struct{
    No *raiz;
}Arvore;

void imprime(No *n){
    if(raiz == NULL){
        cout << "\nVAZIA!!";
    }else{
        if(n != NULL){
            cout << "<" << n->info;
            imprime(n->esq);
            imrpime(n->dir);
            cout << ">";
        }else{
            cout << "<>";
        }
    }
}

int main(){

}
