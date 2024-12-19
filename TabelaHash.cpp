#include "TabelaHash.h"
#include <iostream>

int TabelaHash::hashFunction(int matricula) {
    return matricula % TAMANHO;
}

void TabelaHash::inserir(int matricula, const std::string& nome, const std::string& area, const std::string& titulo, const std::string& regime) {
    int pos = hashFunction(matricula);
    if (!tabela[pos].inserir(matricula, nome, area, titulo, regime)) {
        std::cout << "Erro: Limite de colisões excedido na posição " << pos << std::endl;
    }
}

void TabelaHash::buscar(int matricula) {
    int pos = hashFunction(matricula);
    if (!tabela[pos].buscar(matricula)) {
        std::cout << "Chave " << matricula << " não encontrada." << std::endl;
    }
}

void TabelaHash::remover(int matricula) {
    int pos = hashFunction(matricula);
    if (!tabela[pos].remover(matricula)) {
        std::cout << "Erro: Chave " << matricula << " não encontrada para remoção." << std::endl;
    }
}

void TabelaHash::imprimir() {
    for (int i = 0; i < TAMANHO; i++) {
        std::cout << "Posição " << i << ": ";
        tabela[i].imprimir();
        std::cout << std::endl;
    }
}
