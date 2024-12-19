#include "No.h"

No::No(int m, const std::string& n, const std::string& a, const std::string& t, const std::string& r)
    : matricula(m), nome(n), area(a), titulo(t), regime(r), prox(nullptr) {}
