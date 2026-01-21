/*************************************************************************
                           ReadLog  -  description
*************************************************************************/                      
                           

//---------- Interface de la classe <> (fichier ReadLog.h) ----------------
#if ! defined ( READLOG_H )
#define READLOG_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
using namespace std;
//------------------------------------------------------------------ Types
struct Log
{
    string ip;
    string date;
    string heure;
    string action;
    string cible;
    string status;
    string data_quantity;
    string referenceur; 
    string identification_nav;
    Log(string Ip = "", string Date = "", string Heure = "", string Action = "", string Cible = "", string Status = "", string Data_quantity = "", string Referenceur= "", string Identification_nav = ""): ip(Ip), date(Date), heure(Heure), action(Action), cible(Cible), status(Status), referenceur(Referenceur), data_quantity(Data_quantity){};

};

//------------------------------------------------------------------------
// Rôle de la classe <ReadLog> 
// Lit une requête 
//
//------------------------------------------------------------------------

class ReadLog : public ifstream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    Log prochainLog();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //Crée un prochain log
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    ReadLog & operator = ( const ReadLog & unReadLog ); //à voir
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ReadLog ( const ReadLog & unReadLog ); // à voir
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ReadLog (ifstream& MyFile, string option = "");
    // Mode d'emploi :
    // Le constructeur par défaut de la classe ReadLog, dans le cas où aucune option est activée
    // Contrat :
    //

    virtual ~ReadLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ReadLog>

#endif // ReadLog_H

