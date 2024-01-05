#ifndef DEF_ASCENSEUR
#define DEF_ASCENSEUR

#include<string>



enum Position{         // énumération qui définit la position de l'ascenseur(à quel étage il se trouve et à quel moment).
	                  //  mais aussi la destination d'un passager.
	ETA0, ETA1, ETA2
};

typedef enum Position Position;



enum Deplacement{ // énumération qui décrit le déplacement de l'ascenseur (monter ou descendre).

	MONTER, DESCENDRE
};

typedef enum Deplacement Deplacement;



class Ascenseur{
	
	public : 
		
		Ascenseur();
		Ascenseur(int nbrPlc, int nbrPass, Position position, Deplacement deplacement);
		std::string getPosition() const;
		std::string getDeplacement() const;
		int getNbrPass() const;
		int getNbrPlc() const;
		void setPosition(Position position);
		void setDeplacement(Deplacement deplacement);
		void setNbrPass(int nbrPass);
		
		
		
	private : 
		
		int m_nbrPlc;                    // Le nombre de place à bord de l'ascenseur.
		int m_nbrPass;                  // Le nombre de passagers à l'intérieur de l'ascenseur.
		Position m_position;           // La position de l'ascenseur.
		Deplacement m_deplacement;    // Le déplacement de l'ascenseur.
};



void getEtat(Ascenseur ascenseur);
void deplacement(Ascenseur ascenseur);



#endif



                                                                                                                                 // Made by Lula Jonathan UCAC-ICAM (X2026).