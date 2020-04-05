#include "Sommet.h"

Sommet::Sommet(int num) : m_numero{num}, m_numCompCon{num}{}


void Sommet::addSuccesseur(const Sommet* succ) {
    m_successeurs.push_back(succ);
}


const std::vector<const Sommet*>& Sommet::getSuccesseurs() const {
    return m_successeurs;
}

int Sommet::getNumero() const {
    return m_numero;
}

int Sommet::getNumeroCompCon() const {
    return m_numCompCon;
}

void Sommet::afficher() const {
    std::cout << "   Sommet " << m_numero << " : ";
    for(auto addrSommet : m_successeurs) {
        std::cout << addrSommet->getNumero() << " ";
    }
}

void Sommet::changNumeroCompCon(int nouvNum) {
    m_numCompCon = nouvNum;
}


