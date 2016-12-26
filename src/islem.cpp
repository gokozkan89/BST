/**
* @author Gokhan OZKAN(gokozkan89@gmail.com)
*/
#include "islem.h"

//kurucu fonksiyon.
islem::islem()
{
	agac = new ikiliAramaAgaci();
}

//y�k�c� fonksiyon.
islem::~islem()
{
	delete agac;
}

//fonksiyon bilgi.txt dosyas�ndan verileri okumam�z� ve ilgili fonksiyonlar� �a��rmam�z� sa�lar.
void islem::dosyadanOku()
{
	string ulke,sehir; //dosyadan okudu�umuz veriyi atamak i�in string tipinde bir de�i�ken tan�mlad�k.
	ifstream dosya; //ifstream s�n�f�ndan bir nesne olu�turduk.Herhangi bir isim verebilirsiniz.
	
	dosya.open("bilgi.txt"); //deneme.txt isimli daha �nceden olu�turdu�umuz dosyay� a�t�k.
	
	while (!dosya.eof())
	{
		getline(dosya, ulke, '#');//getline fonksiyonu ile sat�r okuma yapt�k(# i�aretini gorunceye kadar) ve ulke de�i�kenine atad�k.
		getline(dosya, sehir, '\n');
		agac->ekle(ulke, sehir);//okudugumuz �lke ve �ehirleri agac�m�za eklemek i�in ekle fonksiyonu �a��rd�k.
	}
	agac->yazdirInorder();//a�ac�m�z� �norder bir �ekilde ekrana yazd�rmam�z i�in �a��rd�k
	dosya.close(); //dosyay� kapatt�k.
}

//public olarak tan�mlad�g�m�z basla fonksiyonu i�lemlerin ba�lamas�n� sa�lar.
void islem::basla()
{
	dosyadanOku();
}