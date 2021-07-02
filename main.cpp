#include <iostream>
#include "circuito.cpp"

using namespace std;

int main() {
    int verificacao;
    tComandos comando;
    while (verificacao != 3) {
        cout << "--------------- Inicialização ---------------" << endl << "Digite 1 para gravar, 2 para ler e 3 para fechar o programa: ";
        cin >> verificacao; //1 = gravar / 2 = ler / 3 = Sair do programa

        if(verificacao == 1) {
            cout << "--------------- Gravar dados ---------------" << endl << "Quantos dados deseja armazenar? " << endl;
            cin >> comando.n; //Quantidade de dados a serem gravados
            comando.operacaoGravar();
            //comando.gravarNoArquivo();
        } else if (verificacao == 2) {
            comando.operacaoLer();
        }
    }
    if (verificacao == 3) {
        cout << "O programa foi encerrado!" << endl;
    }
}