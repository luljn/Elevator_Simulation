#include<iostream>
#include<unistd.h>
#include<list>
#include"ascenseur.hpp"
#include"passager.hpp"

using namespace std;
list<Passager> FilePassager;
int nbrPassEta0(0);   // Le nombre de passagers à l'étage 0.
int nbrPassEta1(0);  // Le nombre de passagers à l'étage 1.
int nbrPassEta2(0); // Le nombre de passagers à l'étage 2.

// Le fonctionnement de l'ascenseur se fera sur un rez-de-chaussée + 2 étages (3 étages au total).

int main(){
	
	system("title Simulation_Ascenseur");
	system("color 09");
	
	Ascenseur ascenseur(5, 0, ETA0, MONTER);  // Un ascenseur avec 5 places maximum, et 0 passager à l'intérieur initialement.
	
	while(true){
		
		deplacement(ascenseur);
	}
	/*
	ascenseur.setNbrPass(ascenseur.getNbrPass() + 1);
	printf("%d", ascenseur.getNbrPass());
	*/
	//ajouterPassager();
	
	return 0;
}



                                                                                                                                 // Made by Lula Jonathan UCAC-ICAM (X2026).