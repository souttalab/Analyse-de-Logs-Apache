/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-------- Réalisation de la classe <Stats> (fichier Stats.cpp) ----------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <algorithm>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Stats.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Stats::AjouterLien (const string &referant, const string &cible)
// Algorithme :
//
{
    ++graphe[referant][cible];

    if (consultations.find(referant) == consultations.end())
    {
        consultations[referant] = 0;
    }

    ++consultations[cible];
} //----- Fin de AjouterLien


void Stats::AfficherTop10() const
// Algorithme :
//
{
    if (consultations.empty())
    {
        cout << "Aucun log" << endl;
        return;
    }

    vector<pair<string, int>> pages(consultations.begin(), consultations.end());

    sort(pages.begin(), pages.end(),
        [] (const pair<string, int>& a, const pair<string, int>& b)
        {
            return a.second > b.second;
        });

    size_t limite = min<size_t>(10, pages.size());
    for (size_t i = 0; i < limite && pages[i].second > 0; i++)
    {
        cout << pages[i].first
             << " (" << pages[i].second << " consultations)" << endl;
    }
} //----- Fin de AfficherTop10


void Stats::CreerGraphe(const string &nomFichier) const
// Algorithme :
//
{
    ofstream fichier (nomFichier);
    if (!fichier)
    {
        cerr << "Erreur d'ouverture de <" << nomFichier << ">" << endl;
    }

    Tconsultations nodes;

    fichier << "digraph {" << endl;

    int compteur = 0;
    for (const auto& page : consultations)
    {
        fichier << "\tnode" << compteur
                << " [label=\"" << page.first << "\"];" 
                << endl;
        nodes[page.first] = compteur;
        compteur++;
    }

    for (const auto& noeud : graphe)
    {
        for (const auto& arrete : noeud.second)
        {
            fichier << "\tnode" << nodes[noeud.first] 
                    << " -> "
                    << "node" << nodes[arrete.first]
                    << " [label=\"" << arrete.second << "\"];"
                    << endl;
        }
    }

    fichier << "}";
} //----- Fin de Creergraphe


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Stats::Stats (const Stats &unStats)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stats>" << endl;
#endif

    graphe = unStats.graphe;
    consultations = unStats.consultations;
} //----- Fin de Stats (constructeur de copie)

Stats::Stats ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stats>" << endl;
#endif
} //----- Fin de Stats


Stats::~Stats ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Stats>" << endl;
#endif
} //----- Fin de ~Stats


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

