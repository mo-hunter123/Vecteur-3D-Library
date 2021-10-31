#pragma once

#include <iostream>
#include <cmath>

//utilisation des espaces de nommage est importantes 

namespace Geo {
	class Vecteur3D
	{
	private:
		float Vect[3];

	public:

		Vecteur3D(float x = 0.0, float y = 0.0, float z = 0.0);
		//interdir l'initialisation par le constructeur de recopie et l'operateur d'affectation 
		//on interdit totalement l'utilisation de passage par valeur
		Vecteur3D(const Vecteur3D&) = delete; //on a interdit l'utilisation le const de recopie 
		Vecteur3D& operator=(const Vecteur3D&) = delete;

		//si on veut copier des objets on peut definir une methode clonage en controllant comment il faut faire le clonage 

		void Print() const;
		float at(unsigned int index) const;
		float& operator[](unsigned int index); //on retourne la vrai case de vecteur pour qu'on puisse le modifier 
		bool operator==(const Vecteur3D& Vecteur) const; //on ne peut pas passer le vecteur par valeur car on aura une creation de recopie ;; teste !!
		bool operator!=(const Vecteur3D& Vec) const;

		~Vecteur3D();
	};
};
