
#include <iostream>
#include "Vecteur3D.h"
#include <string>

using namespace std; 

int main()
{
	Vecteur3D<int> v1(2, 4, 5); 
	v1.Print(); 
	v1[2] = 6; 
	v1.Print(); 
}
