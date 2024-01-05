#include<iostream>
#include<string>
#include<list>
#include"passager.hpp"
#include"ascenseur.hpp"

using namespace std;
extern main();
extern list<Passager> FilePassager;
extern int nbrPassEta0;   // Le nombre de passagers à l'étage 0.
extern int nbrPassEta1;  // Le nombre de passagers à l'étage 1.
extern int nbrPassEta2; // Le nombre de passagers à l'étage 2.



Passager::Passager() : m_nom("Passager_Lambda"), m_position(ETA0), m_destination(ETA2)
{
	
}



Passager::Passager(std::string nom, Position position, Position destination) : m_nom(nom), m_position(position), m_destination(destination)
{
	
}



string Passager::getNom() const{
	
	return m_nom;
}



string Passager::getPosition() const{
	
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



string Passager::getDestination() const{
	
	switch(m_destination){
		
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



void Passager::setNom(string nom){
	
	m_nom = nom;
}



void Passager::setPosition(Position position){
	
	m_position = position;
}



void Passager::setDestination(Position destination){
	
	m_destination = destination;
}



void ajouterPassager(Ascenseur ascenseur){
	
	char choix('o');   // Le choix de l'utisateur(si oui ou non il veut ajouter un nouveau passager sur un palier(étage)).
	string nom;
	int position;
	int destination;
	
	cout << "\n\tVoulez vous ajouter un nouveau passager ? o(oui)/n(non) : ";
	cin >> choix;
	
	switch(choix){
		
		case 'o' :
			
			cout << "\n\tLe nom du passager : ";
			cin >> nom;
			
			cout << "\n\tSur quel etage ? (utilisez 0, 1 ou 2) : ";
			cin >> position;
			
			cout << "\n\tQuelle est sa destination ? (utilisez 0, 1 ou 2) : ";
			cin >> destination;
			cout << endl << endl;
			
			if(position == 0 and destination == 1){
				
				Passager passager(nom, ETA0, ETA1);
				FilePassager.push_back(passager);
				nbrPassEta0 += 1;
			}
			
			else if(position == 0 and destination == 2){
				
				Passager passager(nom, ETA0, ETA2);
				FilePassager.push_back(passager);
				nbrPassEta0 += 1;
			}
			
			else if(position == 1 and destination == 0){
				
				Passager passager(nom, ETA1, ETA0);
				FilePassager.push_back(passager);
				nbrPassEta1 += 1;
			}
			
			else if(position == 1 and destination == 2){
				
				Passager passager(nom, ETA1, ETA2);
				FilePassager.push_back(passager);
				nbrPassEta1 += 1;
			}
			
			else if(position == 2 and destination == 0){
				
				Passager passager(nom, ETA2, ETA0);
				FilePassager.push_back(passager);
				nbrPassEta2 += 1;
			}
			
			else if(position == 2 and destination == 1){
				
				Passager passager(nom, ETA2, ETA1);
				FilePassager.push_back(passager);
				nbrPassEta2 += 1;
			}
		
		case 'n' :
			
			cout << endl << endl;
			break; 
		
		default : 
			
			system("cls");
			cout << "\n\tNon disponible :( !\n\n\t";
			system("pause");
			system("cls");
			main();
			break;
	}
}



void deplacerPassager(Ascenseur ascenseur){
	
	// Le départ des passagers.
	for(auto const& it : FilePassager){
		
		// Etage 0 : point de destination.
		if(it.getDestination() == "Etage 0" and it.getPosition() == "Etage 2" ){             // On teste la destination et la position du passager.
			
			if(ascenseur.getPosition() == "Etage 2" and nbrPassEta2 != 0){                 // On teste la position de l'ascenseur. 
				
				
				nbrPassEta2 -= 1;
				ascenseur.setNbrPass(ascenseur.getNbrPass() + 1);
			}
		}
				
		else if(it.getDestination() == "Etage 0" and it.getPosition() == "Etage 1" ){
					
			if(ascenseur.getPosition() == "Etage 1" and nbrPassEta1 != 0){
		
				nbrPassEta1 -= 1;
				ascenseur.setNbrPass(ascenseur.getNbrPass() + 1);
			}
		}
		
		// Etage 1 : point de destination.
		else if(it.getDestination() == "Etage 1" and it.getPosition() == "Etage 0" ){
					
			if(ascenseur.getPosition() == "Etage 0" and nbrPassEta0 != 0){
		
				nbrPassEta0 -= 1;
				ascenseur.setNbrPass(ascenseur.getNbrPass() + 1);
			}
		}
		
		else if(it.getDestination() == "Etage 1" and it.getPosition() == "Etage 2" ){
					
			if(ascenseur.getPosition() == "Etage 2" and nbrPassEta2 != 0){
		
				nbrPassEta2 -= 1;
				ascenseur.setNbrPass(ascenseur.getNbrPass() + 1);
			}
		}
		
		// Etage 2 : point de destination.
		else if(it.getDestination() == "Etage 2" and it.getPosition() == "Etage 0" ){
					
			if(ascenseur.getPosition() == "Etage 0" and nbrPassEta0 != 0){
		
				nbrPassEta0 -= 1;
				ascenseur.setNbrPass(ascenseur.getNbrPass() + 1);
			}
		}
		
		else if(it.getDestination() == "Etage 2" and it.getPosition() == "Etage 1" ){
					
			if(ascenseur.getPosition() == "Etage 1" and nbrPassEta1 != 0){
		
				nbrPassEta1 -= 1;
				ascenseur.setNbrPass(ascenseur.getNbrPass() + 1);
			}
		}
	}
	
	// L'arrivée des passagers.
	for(auto const& it : FilePassager){
		
		// Etage 0 : point d'arrivée.
		if(it.getDestination() == "Etage 0" and it.getPosition() == "Etage 2"){   // On teste la destination du passager.
		
			if(ascenseur.getPosition() == "Etage 0" and ascenseur.getDeplacement() == "il descend"){
				
				nbrPassEta0 += 1;
			}	
		}	
		
		if(it.getDestination() == "Etage 0" and it.getPosition() == "Etage 1"){   // On teste la destination du passager.
		
			if(ascenseur.getPosition() == "Etage 0" and ascenseur.getDeplacement() == "il descend"){
				
				nbrPassEta0 += 1;
			}	
		}	
		
		// Etage 1 : point d'arrivée.
		if(it.getDestination() == "Etage 1" and it.getPosition() == "Etage 0"){   // On teste la destination du passager.
		
			if(ascenseur.getPosition() == "Etage 1" and ascenseur.getDeplacement() == "il monte"){
				
				nbrPassEta1 += 1;
			}	
		}	
		
		if(it.getDestination() == "Etage 1" and it.getPosition() == "Etage 2"){   // On teste la destination du passager.
		
			if(ascenseur.getPosition() == "Etage 1" and ascenseur.getDeplacement() == "il descend"){
				
				nbrPassEta1 += 1;
			}	
		}
		
		// Etage 2 point d'arrivée.	
		if(it.getDestination() == "Etage 2" and it.getPosition() == "Etage 0"){   // On teste la destination du passager.
		
			if(ascenseur.getPosition() == "Etage 1" and ascenseur.getDeplacement() == "il monte"){
				
				nbrPassEta2 += 1;
			}	
		}	
		
		if(it.getDestination() == "Etage 2" and it.getPosition() == "Etage 1"){   // On teste la destination du passager.
		
			if(ascenseur.getPosition() == "Etage 1" and ascenseur.getDeplacement() == "il monte"){
				
				nbrPassEta2 += 1;
			}	
		}
	}
}



                                                                                                                                // Made by Lula Jonathan UCAC-ICAM (X2026).