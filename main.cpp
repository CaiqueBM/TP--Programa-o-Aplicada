#include <iostream>
#include "circuito.cpp"

using namespace std;

int main() {
    int verificacao;
    tComandos comando;
    
    cout << "--------------- Inicialização ---------------" << endl << "Digite 1 para gravar e 2 para ler um arquivo: ";
    cin >> verificacao; //1 = gravar / 2 = ler

    if(verificacao == 1) {
        cout << "--------------- Gravar dados ---------------" << endl << "Quantos dados deseja armazenar? " << endl;
        cin >> comando.n; //Quantidade de dados a serem gravados
        comando.operacao();
        comando.gravarNoArquivo();
    } else if (verificacao == 2) {
        cout << endl;
    }
}