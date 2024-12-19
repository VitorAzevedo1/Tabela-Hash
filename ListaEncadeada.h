#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "No.h"

class ListaEncadeada {
private:
    No* head;
    int tamanho;

public:
    ListaEncadeada();
    ~ListaEncadeada();

    bool inserir(int matricula, const std::string& nome, const std::string& area, const std::string& titulo, const std::string& regime);
    bool buscar(int matricula);
    bool remover(int matricula);
    void imprimir();
    int getTamanho();
};

#endif
