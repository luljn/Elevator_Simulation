#include<iostream>
#include<string>
#include<list>
#include<unistd.h>
#include"ascenseur.hpp"
#include"passager.hpp"

using namespace std;
extern list<Passager> FilePassager;
extern int nbrPassEta0;   // Le nombre de passagers à l'étage 0.
extern int nbrPassEta1;  // Le nombre de passagers à l'étage 1.
extern int nbrPassEta2; // Le nombre de passagers à l'étage 2.



Ascenseur::Ascenseur() : m_nbrPlc(5), m_nbrPass(0), m_position(ETA0), m_deplacement(MONTER)
{
	
}



Ascenseur::Ascenseur(int nbrPlc, int nbrPass, Position position, Deplacement deplacement) : m_nbrPlc(nbrPlc), m_nbrPass(nbrPass), m_position(position), m_deplacement(deplacement)
{
	
}



string Ascenseur::getPosition() const{
	
	switch(m_position){
		
		case ETA0 : 
		
			return "Etage 0";
			break;
			
		case ETA1 : 
		
			return "Etage 1";
			break;
			
		case ETA2 : 
		
			return "Etage 2";
			break;
			
		default : 
		
			break;
	}
}



string Ascenseur::getDeplacement() const{
	
	switch(m_deplacement){
		
		case MONTER : 
		
			return "il monte";
			break;
			
		case DESCENDRE : 
		
			return "il descend";
			break;
			
		default : 
		
			break;
	}
}



int Ascenseur::getNbrPass() const{
	
	return m_nbrPass;
}



int Ascenseur::getNbrPlc() const{
	
	return m_nbrPlc;
}



void Ascenseur::setPosition(Position position){
	
	m_position = position;
}



void Ascenseur::setDeplacement(Deplacement deplacement){
	
	m_deplacement = deplacement;
}



void Ascenseur::setNbrPass(int nbrPass){
	
	m_nbrPass = nbrPass;
}



void getEtat(Ascenseur ascenseur){
	
	cout << "Etat de l'ascenseur" << endl;
	cout << "\tPosition de l'ascenseur : " << ascenseur.getPosition();
	cout << "\n\tDeplacement de l'ascenseur : " << ascenseur.getDeplacement();
	//cout << "\n\tNombres de passagers a l'interieur de l'ascenseur : " << ascenseur.getNbrPass();
	cout << "\n\tNombres de places maximale de l'ascenseur : " << ascenseur.getNbrPlc();
	//cout << "\n\tNombres de places disponibles a l'interieur de l'ascenseur : " << ascenseur.getNbrPlc() - ascenseur.getNbrPass();
	cout << "\n\tNombres de personnes sur l'etage 0 : " << nbrPassEta0;
	cout << "\n\tNombres de personnes sur l'etage 1 : " << nbrPassEta1;
	cout << "\n\tNombres de personnes sur l'etage 2 : " << nbrPassEta2 << endl << endl;
}



void deplacement(Ascenseur ascenseur){
	
	sleep(2);
	getEtat(ascenseur);
	ajouterPassager(ascenseur);
	deplacerPassager(ascenseur);
	
	// On monte.
	ascenseur.setPosition(ETA1);
	sleep(2);
	getEtat(ascenseur);
	ajouterPassager(ascenseur);
	deplacerPassager(ascenseur);
	
	ascenseur.setPosition(ETA2);
	sleep(2);
	getEtat(ascenseur);
	ajouterPassager(ascenseur);
	deplacerPassager(ascenseur);
	
	ascenseur.setDeplacement(DESCENDRE);
	
	// On descend.
	ascenseur.setPosition(ETA2);
	sleep(2);
	getEtat(ascenseur);
	ajouterPassager(ascenseur);
	deplacerPassager(ascenseur);
	
	ascenseur.setPosition(ETA1);
	sleep(2);
	getEtat(ascenseur);
	ajouterPassager(ascenseur);
	deplacerPassager(ascenseur);
	
	ascenseur.setPosition(ETA0);
	sleep(2);
	getEtat(ascenseur);
	ajouterPassager(ascenseur);
	deplacerPassager(ascenseur);
}
    
	
	
	                                                                                                                            // Made by Lula Jonathan UCAC-ICAM (X2026).