#include <iostream>
#include "Graphe.h"

void afficherParcours(size_t s0, const std::vector<int>& precesseur) {
    for(size_t i = 0; i < precesseur.size(); ++i) {
        if (i != s0) {
            if(precesseur[i] != -1) {
                std::cout << i << " <--- ";
                size_t j = precesseur[i];
                while(j != s0) {
                    std::cout << j << " <--- ";
                    j = precesseur[j];
                }
                std::cout << j << std::endl;
            }
        }
    }
}

void afficherConnexite(std::vector<std::vector<int>> somConnex) {
    for(size_t i = 0; i < somConnex.size(); ++i) {
        std::cout << "Groupe connexe "<< i << " :" << std::endl;
        for (int j = 0; j < somConnex[i].size();++j){
            std::cout << somConnex[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
}


int main() {
    size_t s0 = 0, s1=0;
    Graphe g{"/Users/lowansteinmetz/Documents/Informatique/TP5/graphe-no-1"};
    std::vector<int> arborescence;
    std::vector<std::vector<int>> somConnex;
    std::vector<std::vector<int>> somDeg;
    std::vector<int> cEurlerien;
    g.krustal();
    g.afficher();

    return 0;
}