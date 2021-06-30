#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

struct tCircuito {    //Estrutura que guarda os dados
    int resistencia1;
    int resistencia2;
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

    void inicializaLista(tLista* pLista) { //Função que inicializa uma lista
        pLista -> primeiro = NULL;
        pLista -> ultimo = NULL;
        pLista -> marcador = NULL;
        pLista -> tamanho = 0;
    }

    int obterTamanho (tLista* pLista) { //Função que mostra o tamanho da lista
    return pLista -> tamanho;
    }

    bool listaVazia (tLista* pLista) { //Função que mostra se a lista está vazia
        return pLista -> tamanho == 0;
    }

    bool finalizaLista (tLista* pLista) { //Função que mostra se a lista chegou ao fim
    return pLista -> marcador == NULL;
    }

    void incluirNoFim (tLista* pLista, int r1, int r2, int v) { //função que inclui um novo nó no fim
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

    

    void gravarNoArquivo(tLista* pLista) { //Função para gravar os dados no arquivo txt
        ofstream enviar;
        int cont = 1;
    
        pLista -> marcador = pLista -> primeiro;
        
        enviar.open("dados.txt", ios::out);
        
        while (!finalizaLista(pLista)) {
            int r1 = pLista ->marcador ->resistencia1;
            int r2 = pLista ->marcador ->resistencia2;
            int v = pLista ->marcador ->tensao;
            
            if(cont <= 3) {
                if (cont == 3) {
                    enviar << r1 << endl;
                    enviar << r2 << endl;
                    enviar << v;
                    cont = 1;
                } else {
                    enviar << r1 << endl;
                    enviar << r2 << endl;
                    enviar << v << endl;
                    cont ++;
                }
            }
            pLista -> marcador = pLista -> marcador -> proximo;
        }
        enviar.close();
    }


        void operacaoGravar() {    //equivalente a main
            // Criando a lista encadeada
            tCircuito circuito;
            tLista* valores = new tLista;
            inicializaLista(valores);
        
            for (int i=0; i < n ; i++) {
                cout << "--------- Item " << i + 1 << "----------" << endl;
                cout << "Resistência 1: ";
                cin >> circuito.resistencia1;
                cout << "Resistência 2: ";
                cin >> circuito.resistencia2;
                cout << "Fonte de tensão: ";
                cin >> circuito.tensao;

                incluirNoFim(valores, circuito.resistencia1, circuito.resistencia2,     circuito.tensao);
                //cout << "O tamanho da lista é: " << obterTamanho(valores) << endl;
            }
        gravarNoArquivo(valores);
        }

        void operacaoLer() {
            ifstream receber;
            tCircuito circuito;
            tLista* valores = new tLista;
            inicializaLista(valores);
            int dado;
            int cont = 1;

            receber.open("dados.txt", ios::in);

            while(!receber.eof()) {

                    if (cont == 1) {
                        receber >> dado;
                        circuito.resistencia1 = dado;
                        cont++;
                    } else if ( cont == 2) {
                        receber >> dado;
                        circuito.resistencia2 = dado;
                        cont++;
                    } else if (cont == 3) {
                        receber >> dado;
                        circuito.tensao = dado;
                        incluirNoFim(valores, circuito.resistencia1, circuito.resistencia2, circuito.tensao);
                        cout << "O tamanho da lista é: " << obterTamanho(valores) << endl;
                        cont = 1;
                    }
            }
            receber.close();
        }  
};
