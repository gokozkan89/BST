/**
* @author Gokhan OZKAN(gokozkan89@gmail.com)
*/
#include "islem.h"

//main fonksiyonu programın başlamasını sağlar, programın kendisidir.
int main()
{
	islem* basla = new islem();
	
	basla->basla();
	
	delete basla;

	return 0;
}