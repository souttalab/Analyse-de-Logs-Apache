/*************************************************************************
                            Sats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-------- Interface de la classe <Stats> (fichier Stats.h) --------------
#if ! defined ( STATS_H )
#define STATS_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <unordered_map>
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Stats>
//  Permet de gérer une collections de logs sous forme de graphe, d'en 
//  afficher les statisitques et de l'exporter pour le logiciel Graphviz
//------------------------------------------------------------------------

class Stats
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterLien (const string &referant, const string &cible);
    // Mode d'emploi :
    //      Ajoute un log au graphe et au répertoire du nombre de consultations
    //      selon le référant et la cible de la requête
    // Contrat :
    //      Aucun

    void AfficherTop10() const;
    // Mode d'emploi :
    //      Affiche sur la sortie standard les 10 pages les plus consultées
    //      ou moins si le graphe est plus petit que 10. Les pages non 
    //      consultées sont ignorées.
    // Contrat :
    //      Aucun

    void CreerGraphe(const string &nomFichier) const;
    // Mode d'emploi :
    //      Créer ou remplace dans le fichier 'nomFichier' une représentation
    //      du graphe pour pouvoir le visualiser avec le logiciel Graphviz
    // Contrat :
    //      Aucun


//------------------------------------------------- Surcharge d'opérateurs
    // Xxx & operator = ( const Xxx & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Stats (const Stats &unStats);
    // Mode d'emploi (constructeur de copie) :
    //      Construit une instance de Stats à partir d'une autre
    // Contrat :
    //      Aucun

    Stats ();
    // Mode d'emploi :
    //      Construit une instance de Stats
    // Contrat :
    //      Aucun

    virtual ~Stats ();
    // Mode d'emploi :
    //      Détruit l'instance de Stats
    // Contrat :
    //      Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    typedef unordered_map<string, int> Tconsultations;
    typedef unordered_map<string, Tconsultations> Tgraphe;
    
    Tconsultations consultations;
    Tgraphe graphe;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // STATS_H

