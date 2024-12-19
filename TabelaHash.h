#ifndef TABELAHASH_H
#define TABELAHASH_H

#include "ListaEncadeada.h"

class TabelaHash {
private:
    static const int TAMANHO = 337;
    ListaEncadeada tabela[TAMANHO];
    int hashFunction(int matricula);

public:
    void inserir(int matricula, const std::string& nome, const std::string& area, const std::string& titulo, const std::string& regime);
    void buscar(int matricula);
    void remover(int matricula);
    void imprimir();
};

#endif
