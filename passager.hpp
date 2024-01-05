#ifndef DEF_PASSAGER
#define DEF_PASSAGER

#include<iostream>
#include<string>
#include"ascenseur.hpp"



class Passager{
	
	public : 
	
		Passager();
		Passager(std::string nom, Position position, Position destination);
		std::string getNom() const;
		std::string getPosition() const;
		std::string getDestination() const;
		void setNom(std::string nom);
		void setPosition(Position position);
		void setDestination(Position destination);
		
		
		
	private : 
	
		std::string m_nom;         // Le nom du passager.
		Position m_position;      // La position actuelle du passager(étage0 ou étage1 ou étage2).
		Position m_destination;  // La destination du passager(étage0 ou étage1 ou étage2).
};



void ajouterPassager(Ascenseur ascenseur);
void deplacerPassager(Ascenseur ascenseur);



#endif



                                                                                                                                // Made by Lula Jonathan UCAC-ICAM (X2026).