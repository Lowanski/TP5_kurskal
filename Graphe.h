#ifndef TP5_TG_GRAPHE_H
#define TP5_TG_GRAPHE_H

#include <iostream>
#include <vector>
#include <string>
#include "Sommet.h"

class Graphe {
private:
    bool m_estOriente;
    std::vector<Sommet*> m_sommets;
    std::map<std::pair<const Sommet*, const Sommet*>,int> m_arete;
    std::map<std::pair<const Sommet*, const Sommet*>,int> m_areteResult;
public:
    Graphe(std::string cheminFichierGraphe);
    ~Graphe();
    void afficher() const;
    void krustal();
    int getNumCompo(int i);
    void setNumCompo(int i, int nouvNum);
};


#endif