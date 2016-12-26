/**
* @author Gokhan OZKAN(gokozkan89@gmail.com)
*/
#include "islem.h"

//kurucu fonksiyon.
islem::islem()
{
	agac = new ikiliAramaAgaci();
}

//yýkýcý fonksiyon.
islem::~islem()
{
	delete agac;
}

//fonksiyon bilgi.txt dosyasýndan verileri okumamýzý ve ilgili fonksiyonlarý çaðýrmamýzý saðlar.
void islem::dosyadanOku()
{
	string ulke,sehir; //dosyadan okuduðumuz veriyi atamak için string tipinde bir deðiþken tanýmladýk.
	ifstream dosya; //ifstream sýnýfýndan bir nesne oluþturduk.Herhangi bir isim verebilirsiniz.
	
	dosya.open("bilgi.txt"); //deneme.txt isimli daha önceden oluþturduðumuz dosyayý açtýk.
	
	while (!dosya.eof())
	{
		getline(dosya, ulke, '#');//getline fonksiyonu ile satýr okuma yaptýk(# iþaretini gorunceye kadar) ve ulke deðiþkenine atadýk.
		getline(dosya, sehir, '\n');
		agac->ekle(ulke, sehir);//okudugumuz ülke ve þehirleri agacýmýza eklemek için ekle fonksiyonu çaðýrdýk.
	}
	agac->yazdirInorder();//aðacýmýzý ýnorder bir þekilde ekrana yazdýrmamýz için çaðýrdýk
	dosya.close(); //dosyayý kapattýk.
}

//public olarak tanýmladýgýmýz basla fonksiyonu iþlemlerin baþlamasýný saðlar.
void islem::basla()
{
	dosyadanOku();
}