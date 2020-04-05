#include "Sommet.h"
#include "Graphe.h"
#include <fstream>
#include <unordered_map>


Graphe::Graphe(std::string cheminFichierGraphe) {
    std::ifstream ifs{cheminFichierGraphe};
    if (!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + cheminFichierGraphe);
    }
    ifs >> m_estOriente;
    if (ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'orientation du graphe.");
    }
    int ordre;
    ifs >> ordre;
    if (ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'ordre du graphe.");
    }
    int taille;
    ifs >> taille;
    if (ifs.fail()) {
        throw std::runtime_error("Problème de lecture de la taille du graphe.");
    }
    for (int i = 0; i < ordre; ++i) {
        m_sommets.push_back(new Sommet(i));
    }
    int num1, num2, poids;
    for (int i = 0; i < taille; ++i) {
        ifs >> num1 >> num2 >> poids;
        if (ifs.fail()) {
            throw std::runtime_error("Problème de lecture d'un.e arc/arête.");
        }
        std::pair<const Sommet *, const Sommet *> clee(m_sommets[num1], m_sommets[num2]);
        m_arete.insert({clee, poids});
        m_sommets[num1]->addSuccesseur(m_sommets[num2]);
        if (!m_estOriente && num1 < num2) {
            m_sommets[num2]->addSuccesseur(m_sommets[num1]);
        }
    }
}

Graphe::~Graphe() {
    for (auto addrSommet : m_sommets) {
        delete addrSommet;
    }
}

int Graphe::getNumCompo(int i) {
    return m_sommets[i]->getNumeroCompCon();
}

void Graphe::setNumCompo(int i, int nouvNum) {
    m_sommets[i]->changNumeroCompCon(nouvNum);
}

void Graphe::afficher() const {
    std::cout << std::endl << "Graphe ";
    std::cout << (m_estOriente ? "orienté" : "non orienté") << std::endl;
    std::cout << "Ordre : " << m_sommets.size() << std::endl;
    std::cout << "Liste d'adjacences : " << std::endl;
    for (auto addrSommet : m_sommets) {
        addrSommet->afficher();
        std::cout << std::endl;
    }
    std::cout << std::endl << "   Aretes "" : " << std::endl;
    for (auto it : m_arete) {
        std::cout << it.first.first->getNumero() << " " << it.first.second->getNumero() << " Poids : " << it.second
                  << std::endl;
    }
    std::cout << std::endl << "----Algorithme de Kruskal----" << std::endl;
    std::cout << std::endl << "   Aretes "" : " << std::endl;
    int somPoids = 0;
    for (auto it : m_areteResult) {
        somPoids = somPoids + it.second;
        std::cout << it.first.first->getNumero() << " " << it.first.second->getNumero() << " Poids : " << it.second
                  << std::endl;
    }
    std::cout << somPoids << std::endl;
}

void Graphe::krustal() {
    std::deque<int> queue;
    for (auto it : m_arete)
        queue.push_back(it.second);
    std::sort(queue.begin(), queue.end());
    int nb_aretes = 0;
    int i = 0;
    while (nb_aretes < m_sommets.size() - 1) {
        for (auto it : m_arete) {
            if (queue[i] == it.second) {
                if (getNumCompo(it.first.first->getNumero()) != getNumCompo(it.first.second->getNumero())) {
                    std::pair<const Sommet *, const Sommet *> clee(m_sommets[it.first.first->getNumero()],
                                                                   m_sommets[it.first.second->getNumero()]);
                    nb_aretes++;
                    int poids = it.second;
                    m_areteResult.insert({clee, poids});
                    int nb1 = getNumCompo(it.first.first->getNumero());
                    int nb2 = getNumCompo(it.first.second->getNumero());
                    for (int j = 0; j < m_sommets.size(); ++j) {
                        if (getNumCompo(j) == nb2) {
                            setNumCompo(j, nb1);
                        }
                    }
                }
            }
        }
        i++;
    }

}




