#include "ListaEncadeada.h"
#include <iostream>

ListaEncadeada::ListaEncadeada() : head(nullptr), tamanho(0) {}

ListaEncadeada::~ListaEncadeada() {
    while (head) {
        No* temp = head;
        head = head->prox;
        delete temp;
    }
}

bool ListaEncadeada::inserir(int matricula, const std::string& nome, const std::string& area, const std::string& titulo, const std::string& regime) {
    if (tamanho >= 3) return false; // Limite de colisões atingido

    No* novo = new No(matricula, nome, area, titulo, regime);
    novo->prox = head;
    head = novo;
    tamanho++;
    return true;
}

bool ListaEncadeada::buscar(int matricula) {
    No* atual = head;
    while (atual) {
        if (atual->matricula == matricula) {
            std::cout << "Encontrado: " << atual->nome << std::endl;
            return true;
        }
        atual = atual->prox;
    }
    return false;
}

bool ListaEncadeada::remover(int matricula) {
    No* atual = head;
    No* anterior = nullptr;

    while (atual) {
        if (atual->matricula == matricula) {
            if (anterior) anterior->prox = atual->prox;
            else head = atual->prox;

            delete atual;
            tamanho--;
            return true;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return false;
}

void ListaEncadeada::imprimir() {
    No* atual = head;
    while (atual) {
        std::cout << "(" << atual->matricula << ", " << atual->nome << ") -> ";
        atual = atual->prox;
    }
    std::cout << "NULL";
}

int ListaEncadeada::getTamanho() {
    return tamanho;
}
