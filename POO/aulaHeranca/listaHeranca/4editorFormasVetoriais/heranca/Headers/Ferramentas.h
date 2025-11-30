#pragma once
#include "Forma.h"
#include <iostream>

class Ferramenta {
public:
    virtual ~Ferramenta() = default;
    virtual void aplicar(Forma& forma) const = 0;
};

class FerramentaRedimensionar : public Ferramenta {
private:
    double fator;
public:
    explicit FerramentaRedimensionar(double f);
    void aplicar(Forma& forma) const override;
};

class FerramentaRotacionar : public Ferramenta {
private:
    double angulo;
public:
    explicit FerramentaRotacionar(double a);
    void aplicar(Forma& forma) const override;
};