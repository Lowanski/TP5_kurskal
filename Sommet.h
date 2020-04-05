#ifndef TP5_TG_SOMMET_H
#define TP5_TG_SOMMET_H

#include <iostream>
#include <vector>
#include <map>

class Sommet {
private:
    int m_numero;
    std::vector<const Sommet*> m_successeurs;
    int m_numCompCon;


public:
    Sommet(int num);
    int getNumero() const;
    int getNumeroCompCon() const;
    void changNumeroCompCon(int changNum);
    void addSuccesseur(const Sommet* succ);
    const std::vector<const Sommet*>& getSuccesseurs() const;
    void afficher() const;
};


#endif