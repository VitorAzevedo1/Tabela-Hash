#ifndef NO_H
#define NO_H

#include <string>

class No {
public:
    int matricula;
    std::string nome;
    std::string area;
    std::string titulo;
    std::string regime;
    No* prox;

    No(int m, const std::string& n, const std::string& a, const std::string& t, const std::string& r);
};

#endif
