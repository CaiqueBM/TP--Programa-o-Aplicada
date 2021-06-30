#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

struct tCircuito {    //Estrutura que guarda os dados
    float resistencia1;
    float resistencia2;
    int tensao;
    tCircuito* proximo;
};

struct tComandos {
    int n = 0;
    
    tCircuito* criaNo(float r1, float r2, int v) {  //Função para criar um nó
        tCircuito* no = new tCircuito;

        no -> resistencia1 = r1;
        no -> resistencia2 = r2;
        no -> tensao = v;

        no -> proximo = NULL;

        return no;
    }

    struct tLista {
        tCircuito* primeiro;
        tCircuito* ultimo;
        tCircuito* marcador;
        int tamanho;
    };

    void inicializaLista(tLista* pLista) {
        pLista -> primeiro = NULL;
        pLista -> ultimo = NULL;
        pLista -> marcador = NULL;
        pLista -> tamanho = 0;
    }

    int obterTamanho (tLista* pLista) {
    return pLista -> tamanho;
}

    bool listaVazia (tLista* pLista) {
        return pLista -> tamanho == 0;
    }

    bool finalizaLista (tLista* pLista) {
    return pLista -> marcador == NULL;
}

    void incluirNoFim (tLista* pLista, float r1, float r2, int v) { //função que inclui um novo nó no fim
        tCircuito* no;
        no = criaNo(r1,r2,v);

        if(listaVazia(pLista)) {
            pLista -> primeiro = no;
        } else {
            pLista ->ultimo -> proximo = no;
        }

        pLista -> ultimo = no;
        pLista -> marcador = no;
        pLista -> tamanho++;
    }

        void operacao() {    //equivalente a main
            // Criando a lista encadeada
            tCircuito circuito;
            tLista* valores = new tLista;
            inicializaLista(valores);

       // struct tCircuito valor[comando.n];
        
        for (int i=0; i < n ; i++) {
            cout << "--------- Item " << i + 1 << "----------" << endl;
            cout << "Resistência 1: ";
            cin >> circuito.resistencia1;
            cout << "Resistência 2: ";
            cin >> circuito.resistencia2;
            cout << "Fonte de tensão: ";
            cin >> circuito.tensao;

            incluirNoFim(valores, circuito.resistencia1, circuito.resistencia2, circuito.tensao);
            cout << "O tamanho da lista é: " << obterTamanho(valores) << endl;
        }
        gravarNoArquivo();

        
        }
        void gravarNoArquivo () {
            tLista* pLista;
            ofstream enviar;

            enviar.open("dados.txt", ios::out);

            for (int i = 0; i < obterTamanho(pLista); i++) {
                pLista -> marcador = pLista -> primeiro;

                while (!finalizaLista(pLista)) {
                    float r1 = pLista -> marcador -> resistencia1;
                    float r2 = pLista -> marcador -> resistencia2;
                    int v = pLista -> marcador -> tensao;
                    enviar << r1 << endl;
                    enviar << r2 << endl;
                    enviar << v << endl;

                    pLista -> marcador = pLista -> marcador -> proximo;
                }
            }
            enviar.close();
        }
};
