#include "listas_e.h"
#include <iostream>

using namespace std;

Node *busca(Node *header, int valor)
{
    Node *ptr = header;
    Node *ant = nullptr;
    Node *pont = nullptr;

    while (ptr != nullptr && pont == nullptr)
    {
        if (ptr->chave == valor)
        {
            pont = ptr;
        }
        else
        {
            ant = ptr;
            ptr = ptr->prox;
        }
    }
    return pont;
};

Node *busca_ordenada(Node *header, int valor){
    Node* ant = nullptr;
    Node* pont = nullptr;
    Node* ptr = header;

    while(ptr != nullptr){
        if(ptr->chave < valor){
            ant = ptr;
            ptr = ptr->prox;
        } else{
            pont = ptr;
            ptr = nullptr;
        }
    };

    return pont;
};

Node* inserir(Node *header, int valor){

    Node  *ant = nullptr;
    Node *ptr = header;

    while(ptr != nullptr && ptr->chave < valor ){
        ant = ptr;
        ptr = ptr->prox;   
    }

    Node novo = Node(valor, ptr);

    if(ant == nullptr){
        header = nullptr;
    } else{
        ant->prox = &novo;
    }

    return header;
}

Node* merge(Node* ptlista1, Node* ptlista2){
    Node *l1 = ptlista1;
    Node *l2 = ptlista2;
    Node *header;
    header->prox = nullptr;
    Node *aux = header;
    while(l1 != nullptr && l2 != nullptr){
        if(l1->chave == l2->chave){
            aux->prox = l1;
            aux = aux->prox;
            aux->prox = l2;
            aux = aux->prox;
            l1 = l1->prox;
            l2 = l2->prox;
        } else if(l1->chave < l2->chave){
            aux->prox = l1;
            aux = aux->prox;
            l1 = l1->prox;
        } else{
            aux->prox = l2;
            aux = aux->prox;
            l2 = l2->prox;
        }
    }
    if(l1 != nullptr){
        while(l1 != nullptr){
            aux->prox = l1;
            aux = aux->prox;
            l1 = l1->prox;
        }
    }


    if(l2 != nullptr){
        while(l2 != nullptr){
            aux->prox = l2;
            aux = aux->prox;
            l2 = l2->prox;
        }
    }

    return header;
}

Node* criaLista(const std::vector<int>& v) {
    if (v.empty()) return nullptr;
    Node* head = new Node(v[0]);
    Node* cur = head;
    for (size_t i = 1; i < v.size(); ++i) {
        cur->prox = new Node(v[i]);
        cur = cur->prox;
    }
    return head;
}