#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Midia.h"

class GerenciadorMidia {
private:
    std::vector<std::unique_ptr<Midia>> midias;

public:
    void add(std::unique_ptr<Midia> m);
    void list() const;
    void openAll() const;
    void filter(const std::string& filtro) const;
};

