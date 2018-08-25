#include <stdio.h>
#include <iostream>

using namespace std;

void QuickSort (int vetor[], int inicio, int fim){

    int pivo, aux, i, j;

    i = inicio;
    j = fim;
    pivo = vetor[(int) ((i + j) / 2)];

    do{
        while (vetor[i] < pivo)
            i = i + 1;
        while (vetor[j] > pivo)
            j = j - 1;
        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    } while(j > i);

    if(inicio < j)
        QuickSort(vetor, inicio, j);
    if(i < fim)
        QuickSort(vetor, i, fim);
}

int main(){

    int vetor[] = {7, 9, 4, 3, 6, 1, 18, 2, 10, 5};

    cout <<"Vetor desordenado:" << endl;
    for(int i = 0; i < 10; i++){
        cout << vetor[i] << endl;
    }
    cout << endl;

    QuickSort(vetor, 0, 9);

    cout << "Vetor ordenado:\n" << endl;
    for(int i = 0; i < 10; i++){
        cout << vetor[i] << endl;
    }

}

