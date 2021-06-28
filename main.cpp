#include <iostream>
#include "circuito.cpp"

using namespace std;

int main() {
    int verificacao; //0 = gravar / 1 = ler
    int N;
    int valor;

    cout << "Digite 0 para gravar e 1 para ler um arquivo: " << endl;
    cin >> verificacao;

    if(verificacao == 0) {
        cout << "Quantos dados deseja armazenar? " << endl;
        cin >> N;

        for (int i=0; i < N; i++) {
            cout << "Item " << i + 1 << ":" << endl;
            cin >> valor;
        }
        
    } else if (verificacao == 1) {

    }
}