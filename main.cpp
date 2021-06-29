#include <iostream>
#include "circuito.cpp"

using namespace std;

int main() {
    int verificacao; //0 = gravar / 1 = ler
    //tCircuito valor2; //somente para gravar a quantidade de 
    tComandos comando;

    cout << "Digite 0 para gravar e 1 para ler um arquivo: " << endl;
    cin >> verificacao;

    if(verificacao == 0) {
        cout << "Quantos dados deseja armazenar? " << endl;
        cin >> comando.n;

        struct tCircuito valor[comando.n];

        for (int i=0; i < comando.n ; i++) {
            cout << "--------- Item " << i + 1 << "----------" << endl;
            cout << "Resistência 1: ";
            cin >> valor[i].resistencia1;
            cout << "Resistência 2: ";
            cin >> valor[i].resistencia2;
            cout << "Fonte de tensão: ";
            cin >> valor[i].tensao;
        }
        
    } else if (verificacao == 1) {

        
    } 
}