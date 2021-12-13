#pragma once

#include <iostream>
#include <cmath>
#include <assert.h>

//utilisation des espaces de nommage est importantes 

using namespace std; 

template <class T> 
class Vecteur3D
{
private:
	T Vect[3];

public:

	Vecteur3D(T x, T y, T z) {
		this->Vect[0] = x;
		this->Vect[1] = y;
		this->Vect[2] = z;
	}
	//interdir l'initialisation par le constructeur de recopie et l'operateur d'affectation 
	//on interdit totalement l'utilisation de passage par valeur
	Vecteur3D(const Vecteur3D&) = delete; //on a interdit l'utilisation le const de recopie 
	Vecteur3D& operator=(const Vecteur3D&) = delete;

	//si on veut copier des objets on peut definir une methode clonage en controllant comment il faut faire le clonage 

	void Print() const{

	for (int i = 0; i < 3; i++)
	{
		cout << "vect[" << i << "] = " << this->at(i) << endl;
	}

}
	T at(unsigned int index) const;
	T& operator[](unsigned int index); //on retourne la vrai case de vecteur pour qu'on puisse le modifier 
	bool operator==(const Vecteur3D& Vecteur) const; //on ne peut pas passer le vecteur par valeur car on aura une creation de recopie ;; teste !!
	bool operator!=(const Vecteur3D& Vec) const;

	~Vecteur3D(){}
};

template<class T>
T Vecteur3D<T>::at(unsigned int index) const
{
	assert(0 <= index && index < 3); //debug

	try // release
	{
		if (index < 0 || index >= 3) throw "Range Error";
		return this->Vect[index];
	}
	catch (char* e)
	{
		cout << e << endl;
	}

}
//meme traitement que la fonction at mais le retour par reference 
//nous donne la possibilite de modifier les cases 


template<class T>
T& Vecteur3D<T>::operator[](unsigned int index)
{
	assert(0 <= index && index < 3); //debug

	try // release
	{
		if (index < 0 || index >= 3) throw "Range Error";
		return this->Vect[index];
	}
	catch (char* e)
	{
		cout << e << endl;
	}

}

template <class T>
bool Vecteur3D<T>::operator==(const Vecteur3D& Vecteur) const
{
	bool res = true;
	for (int i = 0; i < 3; i++)
	{
		res = res && (this->at(i) == Vecteur.at(i));
	}
	return res;
}

template <class T>
bool Vecteur3D<T>::operator!=(const Vecteur3D& Vec) const
{
	return !(this->operator==(Vec));
}
