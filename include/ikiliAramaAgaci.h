/**
* @author Gokhan OZKAN(gokozkan89@gmail.com)
*/
#ifndef ikiliAramaAgaci_h
#define ikiliAramaAgaci_h

#include <iostream>
#include <string>

using namespace std;
//dugum yap�s�nda ikiliAramaAgaci nesnesi olu�turabilmek i�in tan�mland�.
class ikiliAramaAgaci;
//dugum yap�s�
struct dugum
{
	string veri;
	dugum* pSol;
	dugum* pSag;
	ikiliAramaAgaci* sehir;
	dugum(const string& veri);
	~dugum();
};

//s�n�f taslag� olusturulur.

class ikiliAramaAgaci
{
	private:
		dugum* kok;
		void ulkeEkle(dugum* &gelen_Kok, const string &ulke, const string &sehir);
		void ulkeInorder(dugum *gelen_Kok)const;
		void sehirInorder(dugum* gelen_Kok)const;
		void sehirEkle(dugum* &gelen_Kok, const string &sehir);
		bool dugumSil(dugum* &gelen_Kok);
		bool bosmu() const;
		void temizle();
	public:
		ikiliAramaAgaci();
		~ikiliAramaAgaci();
		void ekle(const string &ulke,const string &sehir);
		void yazdirInorder() const;			
};
#endif