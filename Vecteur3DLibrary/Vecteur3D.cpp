#include "Vecteur3D.h"
#include <assert.h>
#include "pch.h"
using namespace Geo;
using namespace std; 

Geo::Vecteur3D::Vecteur3D(float x, float y, float z)
{
	this->Vect[0] = x;
	this->Vect[1] = y;
	this->Vect[2] = z;
}

void Vecteur3D::Print() const
{
	
	for (int i = 0; i < 3; i++)
	{
		cout << "vect[" << i << "] = " << this->at(i) << endl; 
	}

}

float Vecteur3D::at(unsigned int index) const
{
	assert(0 <= index && index < 3); //debug
	
	try // release
	{
		if (index < 0 || index >= 3) throw "Range Error"; 
		return this->Vect[index]; 
	}
	catch (char *e)
	{
		cout << e << endl; 
	}
	
}

//meme traitement que la fonction at mais le retour par reference 
//nous donne la possibilite de modifier les cases 
float& Vecteur3D::operator[](unsigned int index)
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

bool Vecteur3D::operator==(const Vecteur3D& Vecteur) const
{
	bool res = true;
	for (int i = 0; i < 3; i++)
	{
		res = res && (this->at(i) == Vecteur.at(i)); 
	}
	return res;
}

bool Vecteur3D::operator!=(const Vecteur3D& Vec) const
{
	return !(this->operator==(Vec));
}
