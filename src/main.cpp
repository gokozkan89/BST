/**
* @author Gokhan OZKAN(gokozkan89@gmail.com)
*/
#include "islem.h"

//main fonksiyonu program�n ba�lamas�n� sa�lar, program�n kendisidir.
int main()
{
	islem* basla = new islem();
	
	basla->basla();
	
	delete basla;

	return 0;
}