#ifndef listas_e
#include <vector>

struct Node{
    int chave;
    Node *prox;
    Node():chave(0), prox(nullptr){};
    Node(int a): chave(a), prox(nullptr){};
    Node(int a, Node* end): chave(a), prox(end){};

};

Node* busca(Node* hader, int valor);
Node *busca_ordenada(Node *header, int valor);
Node* inserir(Node *header, int valor);
Node *criaLista(const std::vector<int>& v);

#endif