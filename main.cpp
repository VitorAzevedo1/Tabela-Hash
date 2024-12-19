#include "TabelaHash.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void menu()
{
    std::cout << "\n===== MENU DA TABELA HASH =====\n";
    std::cout << "1 - Inserir elemento\n";
    std::cout << "2 - Remover elemento\n";
    std::cout << "3 - Buscar elemento\n";
    std::cout << "4 - Listar todos os elementos\n";
    std::cout << "5 - Sair\n";
    std::cout << "Escolha uma opcao: ";
}

int main()
{
    TabelaHash tabela;
    std::ifstream arquivo("dados.txt");
    std::string linha;

    // Lê os dados do arquivo e insere na tabela hash
    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            std::stringstream ss(linha);
            int matricula;
            std::string nome, area, titulo, regime;

            ss >> matricula;
            ss.ignore();
            getline(ss, nome, '\t');
            ss >> area >> titulo >> regime;

            tabela.inserir(matricula, nome, area, titulo, regime);
        }
        arquivo.close();
        std::cout << "Dados carregados do arquivo com sucesso.\n";
    }
    else
    {
        std::cout << "Erro: Arquivo de dados nao encontrado.\n";
    }

    int opcao;
    do
    {
        menu();
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
        {
            int matricula;
            std::string nome, area, titulo, regime;

            std::cout << "Digite a matricula: ";
            std::cin >> matricula;
            std::cin.ignore();
            std::cout << "Digite o nome: ";
            getline(std::cin, nome);
            std::cout << "Digite a area: ";
            std::cin >> area;
            std::cout << "Digite o titulo: ";
            std::cin >> titulo;
            std::cout << "Digite o regime: ";
            std::cin >> regime;

            tabela.inserir(matricula, nome, area, titulo, regime);
            break;
        }
        case 2:
        {
            int matricula;
            std::cout << "Digite a matricula para remover: ";
            std::cin >> matricula;
            tabela.remover(matricula);
            break;
        }
        case 3:
        {
            int matricula;
            std::cout << "Digite a matricula para buscar: ";
            std::cin >> matricula;
            tabela.buscar(matricula);
            break;
        }
        case 4:
        {
            tabela.imprimir();
            break;
        }
        case 5:
            std::cout << "Saindo do programa...\n";
            break;
        default:
            std::cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}