/**
* @author Gokhan OZKAN(gokozkan89@gmail.com)
*/
#include "ikiliAramaAgaci.h"

//dugum yapısı kurucu fonksiyonu.
dugum::dugum(const string& veri)
{
	this->veri = veri;
	pSag = NULL;
	pSol = NULL;
	sehir = new ikiliAramaAgaci();//ulkeler agacında şehirleri tutmamızı sağlar.
}
dugum::~dugum()
{
	delete sehir;
}

//ikiliAramaAgacı kurucu fonksiyonu.
ikiliAramaAgaci::ikiliAramaAgaci()
{
	kok = NULL;
}

//ulkeler agacına şehirleri eklememizi sağlar.
void ikiliAramaAgaci::sehirEkle(dugum* &gelen_Kok, const string &sehir)
{
	//gelen dugum bos ise dugum ekler
	if (gelen_Kok == NULL)
		gelen_Kok = new dugum(sehir);
	//sehir gelen dugumun verisinden kucukse sol tarafa dogru eklemeye calışır.Bunun için öz yinelemeli fonksiyon sitemi kullanılır.
	else if (sehir < gelen_Kok->veri)
		sehirEkle(gelen_Kok->pSol, sehir);
	//sehir gelen dugumun verisinden buyukse sağ tarafa dogru eklemeye calışır.Bunun için öz yinelemeli fonksiyon sitemi kullanılır.
	else if (sehir > gelen_Kok->veri)
		sehirEkle(gelen_Kok->pSag,sehir);
}
void ikiliAramaAgaci::ulkeEkle(dugum* &gelen_Kok, const string &ulke,const string& sehir)
{
	//gelen dugum boş ise ulke için dugum ekler ayrıca ulke dugumunun içindeki şehir agacına eleman eklemek için ilgili fonksiyonu çağırır. 
	if (gelen_Kok == NULL)
	{
		gelen_Kok = new dugum(ulke);
		gelen_Kok->sehir->sehirEkle(gelen_Kok->sehir->kok, sehir);
	}
	//ulke verisi eger agac içinde yer alıyorsa, yeni bir ulke eklemez ancak o ulkeye yeni bir şehir eklemek için ilgili fonksiyonu çağırır.
	else if (ulke == gelen_Kok->veri)
		gelen_Kok->sehir->sehirEkle(gelen_Kok->sehir->kok, sehir);
	//sol tarafa ekleme yapmak için öz yinelemeyi kullanır.
	else if (ulke < gelen_Kok->veri)
		ulkeEkle(gelen_Kok->pSol, ulke , sehir);
	//sağ tarafa ekleme yapmak için öz yinelemeyi kullanır.
	else if (ulke > gelen_Kok->veri)
		ulkeEkle(gelen_Kok->pSag, ulke , sehir);
}

//ulke agacını inorder şekilde yazdırmamızı sağlar.
void ikiliAramaAgaci::ulkeInorder(dugum* gelen_Kok)const
{
	if (gelen_Kok != NULL)
	{
		ulkeInorder(gelen_Kok->pSol);
		cout <<endl<<gelen_Kok->veri <<endl;
		sehirInorder(gelen_Kok->sehir->kok);
		ulkeInorder(gelen_Kok->pSag);
	}
}

//sehir agacındaki verileri inorder şekilde sıralamamızı sağlar.
void ikiliAramaAgaci::sehirInorder(dugum* gelen_Kok)const
{
	if (gelen_Kok != NULL)
	{
		sehirInorder(gelen_Kok->pSol);
		cout << gelen_Kok->veri << " ";
		sehirInorder(gelen_Kok->pSag);
	}	
}
//agacın bos olup olmadıgını kontrol eder.
bool ikiliAramaAgaci::bosmu()const 
{
	return kok == NULL;
}
//agaca eleman dışardan eleman eklememizi sağlar.
void ikiliAramaAgaci::ekle(const string &ulke,const string &sehir)
{
		ulkeEkle(kok,ulke,sehir);
}
//agacı dışardan yazdırmamızı sağlar.
void ikiliAramaAgaci::yazdirInorder() const
{
	cout << "INORDER OKUMA";
	ulkeInorder(kok);
}
//agactaki dugumleri silmemizi sağlar.
bool ikiliAramaAgaci::dugumSil(dugum* &gelen_Kok)
{
	//gelen dugum bos ise false doner.bişey yapmaz.
	if (gelen_Kok == NULL) 
		return false;		
	//silinecek adında bir dugum pointerı tanımlanır ve buna dışardan gelen dugum atılır.
	dugum *silinecek = gelen_Kok;
	//gelen dugumun sağ pointerında değer yoksa gelen dugume sol tarafında ki dugume eşitler.
	if (gelen_Kok->pSag == NULL) 
		gelen_Kok = gelen_Kok->pSol;
	//gelen dugumun sol pointerinda değer yoksa gelen dugume sağ tarafındaki dugume eşitlenir.
	else if (gelen_Kok->pSol == NULL)
		gelen_Kok = gelen_Kok->pSag;
	else
	{
		silinecek = gelen_Kok->pSol;
		dugum* tmp = gelen_Kok;
		while (silinecek->pSag != NULL)
		{
			tmp = silinecek;
			silinecek = silinecek->pSag;
		}
		gelen_Kok->veri = silinecek->veri;
		if (tmp == gelen_Kok) 
			gelen_Kok->pSol = silinecek->pSol;
		else 
			tmp->pSag = silinecek->pSol;
	}
	//her ulke ayrıca bir şehir agacı barındırdıgından şehir ağaçları içinde silme işlemi yapılır.
	silinecek->sehir->temizle();
	delete silinecek;
	return true;
}
void ikiliAramaAgaci::temizle()
{
	while (!bosmu())
		dugumSil(kok);
}
ikiliAramaAgaci::~ikiliAramaAgaci()
{
	temizle();
}