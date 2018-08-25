#include <iostream>
#include <string>

using namespace std;

class Aluno{
    private:
        int mat;
        string nome;
    public:
        Aluno(int mat, string nome){
            this->mat = mat;
            this->nome = nome;
        }
        int getMat(){
            return this->mat;
        }
        string getNome(){
            return this->nome;
        }
        void setMat(int m){
            this->mat = m;
        }
        void setNome(string n){
            this->nome = n;
        }
};

class Lista{
    private:
        Aluno *registro[4];
        int tamanho;
    public:
        Lista(){
            tamanho = 0;
        }

        //EXIBIR ELEMENTOS
        void Imprime(){
            cout << "Alunos:" << endl;
            for(int i = 0; i < tamanho; i++){
                cout << "Matricula: " << registro[i]-> << " ---- ";

                cout << "Nome: ";
            }
        }

        //BUSCAR ELEMENTO
        int Busca(int n){
            int elemento = -1;
            for(int i = 0; i < tamanho; i++){
                if(n == alunos[i]->getMat()){
                    elemento = i;
                }
            }
            if(elemento < 0){
                cout << "Aluno nao cadastrado!";
                return elemento;
            }else{
                return elemento;
            }
        }

        //INSERIR NO FINAL
        bool InsereNoFinal(Lista *l, Aluno novo){

        }
        //INSERIR NA POSICAO
        bool InsereNaPosicao(Lista ){

        }

        //REINICIALIZAR
};
int main(){

}

