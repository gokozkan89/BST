/**
* @author Gokhan OZKAN(gokozkan89@gmail.com)
*/
#ifndef islem_h
#define islem_h

#include "ikiliAramaAgaci.h"
#include <fstream>

class islem
{
private:
	ikiliAramaAgaci* agac;
	void dosyadanOku();
public:
	void basla();
	islem();
	~islem();
};
#endif