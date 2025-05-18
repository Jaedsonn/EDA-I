#include "listas_s.h"
#include <iostream>

using namespace std;

int lista_sequencial::busca(int valor)
{
    int i, busca;
    i = 0;
    busca = -1;

    while (i < n && lista[i] != valor)
    {
        i = i + 1;
    }

    if (i >= n)
    {
        busca = -1;
    }
    else
    {
        busca = i;
    };
    return busca;
}
void lista_sequencial::excluir( int valor)
{
    int ind = busca(valor);
    if (n > 0)
    {
        if (ind != -1)
        {
            for (int i = ind; i < n; i++)
            {
                lista[i] = lista[i + 1];
            }
            n = n - 1;
        }
        else
        {
            cout << "Valor não existe" << endl;
        }
    } else{
        cout << "Underflow" << endl;
    }
};
void lista_sequencial::incluir( int valor){

    int ind = busca(valor);

    if(n < MAX){
        if(ind == -1){
            n = n+1;
            lista[n] = valor;
        } else{
            cout << "Valor existe" << endl;
        }
    } else{
        cout << "Overflow" << endl;
    };
};
int lista_sequencial::busca_ordenada(int valor){
 int i = 0;
 while(i < n && lista[i] < valor){
    i = i+1;
 };
 return i;
}
void lista_sequencial::inclusao_ordenada(int valor){
    int ind = busca_ordenada(valor);
    if(n < MAX){
        if(ind < n && lista[ind] != valor){
            for(int i = n; i >= ind; i = i - 1){
                lista[i+1] = lista[i];
            }
            lista[ind] = valor;
            n = n+1;
        } else{
            cout <<"Não dá" << endl;
        }
    }
};
