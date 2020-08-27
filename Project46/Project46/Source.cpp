/****************************************************************************
**
**				ÖĞRENCİ ADI...........................:Hajer Gafsi
**				ÖĞRENCİ NUMARASI.............:B181210562
**				DERS GRUBU…………………:1B
****************************************************************************/

#include <iostream>
#include<fstream>
#include<stdio.h> 
#include<ctime>
#include<sstream> 
#include<stdlib.h>
#include<iomanip> 
#include<Windows.h>
using namespace std;
//menuGoster adli fonksyonu 6 secenekli menuyu gosteriyor ,kullanicidan secmesini istiyor ve kullanicinin sectigi rakamini donduruyor 
int menuGoster() {
	int sec = 0;
	cout << endl << "1. Ogrenci ekle " << endl << "2. sinif ekle " << endl << "3. ogrenci degistir " << endl << "4. ogrenci sil" << endl << "5. sinif sil " << endl << "6. cikis " << endl;
	cin >> sec;
	return sec;
}
void koordinatAta(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//ustYazdirSinif adli fonksyonu icinde sinifin adi yazilan seklinin ust kismini cizer 
void ustYazdirSinif(int elemanSayisi, int yatay, int dusey)
{
	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;

	koordinatAta(yatay, 0);
	cout << solUstKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;

	}
	cout << sagUstKose << endl;
	koordinatAta(yatay, dusey);
	cout << dikey << setw(elemanSayisi + 1) << dikey << endl;

}
//ustYazdirOgr adli fonksyonu icinde ogrencinin bilgileri yazilan seklinin ust kismini cizer
void ustYazdirOgr(int elemanSayisi, int yatay, int dusey)
{
	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;

	koordinatAta(yatay, dusey += 2);
	cout << solUstKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;

	}
	cout << sagUstKose << endl;
	koordinatAta(yatay, dusey + 2);
	for (int i = 0; i < 3; i++) {
		int z = dusey;
		koordinatAta(yatay, ++dusey);
		cout << dikey << setw(elemanSayisi + 1) << dikey << endl;
	}
}
//altYazdirSinif adli fonksyonu icinde sinifin adi yazilan seklinin alt kismini cizer
void altYazdirSinif(int elemanSayisi, int yatay)
{
	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;
	koordinatAta(yatay, 2);
	cout << solAltKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagAltKose << endl;
}
//altYazdirOgr adli fonksyonu icinde ogrencinin bilgileri yazilan seklinin alt kismini cizer
void altYazdirOgr(int elemanSayisi, int yatay, int dusey)
{
	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;
	koordinatAta(yatay, dusey);
	cout << solAltKose;
	for (int i = 0; i < elemanSayisi; i++)
	{
		cout << duz;
	}
	cout << sagAltKose << endl;
}
//3 uye degiskenlerden olusturan ogrYapi adli bir yapi
struct ogrYapi {
	string isim;
	string soyisim;
	int numara;
};
//4 uye degiskenlerden olusturan sinifYapi adli bir yapi
struct sinifYapi {
	string sinifAdi;
	int ogrSayisi;
	ogrYapi* ogrPtr;
	long konum;
};
//dosyaYonetim adli bir sinif dosylama islemleri yapilmasini sagliyor 
class dosyaYonetim {
private:

public:
	//dosyaYonetim nesnesinin kurucu fonksyonu kayitlar dosyasini olusturur 
	dosyaYonetim() {
		ofstream dosya;
		dosya.open("kayitlar.txt", ios::app);
		dosya.close();
	}
	// dosyadanIsimSec isimli fonksyonu isimler.txt dosyasindan rastgele bir isim  secer ve dondurur
	string dosyadanIsimSec() {
		int i = 0, n = 0;
		string isim, isim1;
		string isimler[5000];
		ifstream dosya("isimler.txt");
		//asagidaki dongu dosyadan soyisimleri okur ve soyisimler dizisine ekler
		while (dosya >> isim) {
			isimler[i] = isim;
			i++;
			n++;
		}
		dosya.close();
		return isimler[rand() % n];
	}
	//dosyadanSoyisimSec isimli fonksyonu isimler.txt dosyasindan rastgele bir soyisim  secer ve dondurur
	string dosyadanSoyisimSec() {
		int i = 0, n = 0;
		string soyisim, soyisim1;
		string soyisimler[300];
		ifstream dosya("soyisimler.txt");
		//asagidaki dongu dosyadan soyisimleri okur ve soyisimler dizisine ekler
		while (dosya >> soyisim) {
			soyisimler[i] = soyisim;
			i++;
			n++;
		}
		dosya.close();
		return soyisimler[rand() % n];
	}
	//ogrBilgilerikaydet isimli fonksyonu ogrenci bilgileri parametre olarak alir ve bu bilgileri "kayitlar.txt" dosyasina kaydeder
	void ogrBilgilerikaydet(string isim, string soyisim, int numara) {
		ofstream kayitDosyasi("kayitlar.txt", ios::app);
		kayitDosyasi << isim << " " << soyisim << " " << numara << endl;
		kayitDosyasi.close();
	}
	//kayitlar.txt dosyasini temizlenir 
	void dosyayiSil() {
		ofstream kayitDosyasi("kayitlar.txt", ios::trunc);
		kayitDosyasi.close();
	}
	//kayitlar.txt dosyasina sinifin adini ve ogrenci sayisini kaydeder 
	void sinifBilgilerikaydet(string isim, int sayisi) {
		ofstream kayitDosyasi("kayitlar.txt", ios::app);
		kayitDosyasi << isim << endl << sayisi << endl;
		kayitDosyasi.close();
	}
	//kayitlar.txt dosyasindan siniftaki  ogrencilerin bilgileri okur ve sinifYapi tipinden bir yapiya aktar
	sinifYapi kayitDosyasindanOku(long konum) {
		sinifYapi sinif1;
		ifstream kayitdosyasi1("kayitlar.txt", ios::in);

		kayitdosyasi1.seekg(konum);
		kayitdosyasi1 >> sinif1.sinifAdi >> sinif1.ogrSayisi;
		ogrYapi* ogrler;
		ogrler = new ogrYapi[100];
		for (int i = 0; i < sinif1.ogrSayisi; i++) {
			kayitdosyasi1 >> ogrler[i].isim >> ogrler[i].soyisim >> ogrler[i].numara;
		}
		sinif1.ogrPtr = &ogrler[0];
		konum = kayitdosyasi1.tellg();
		sinif1.konum = konum;
		return sinif1;
		kayitdosyasi1.close();
	}
	//okuldaki siniflarin sayisini kayit.txt dosyasindan bilgi okuyarak hesaplanir 
	int sinifSayisiniHesapla() {
		int sayisi = 0;
		string isim;
		ifstream dosya("kayitlar.txt", ios::in);
		while (dosya >> isim) {
			if ((isdigit(isim[0])) && (isalpha(isim[1]))) {
				sayisi++;
			}
		}
		dosya.close();
		return sayisi;
	}

};
//Ogrenci isimli isim soyisim ve numara degiskenlerinden olusturan bir nesne 
class Ogrenci 
{
private:
	string isim;
	string soyisim;
	int numara;
public:
	//ogrencinin ismini dondurur
	string ismiyaz() {
		return isim;
	}
	//ogrencinin soyismini dondurur 
	string soyIsmiyaz() {
		return soyisim;
	}
	//ogrencinin numarasini dondurur 
	int ogrNumarasi() {
		return numara;
	}
	//ogrenciye parametre olarak aldigi ismini aktarir 
	void isimAktar(string name) {
		isim = name;
	}
	//ogrenciye parametre olarak aldigi soyismini aktarir 
	void soyisimAktar(string surname) {
		soyisim = surname;
	}
	//ogrenciye parametre olarak aldigi numarayi aktarir 
	void numaraAktar(int num) {
		numara = num;
	}
	//ogrencinin adini soyadini ve numarasini ekrana yazdirir 
	void ogrBilgileriGoster() {
		cout << "Ogrenci Adi : " << isim << endl << "ogrenci Soyadi : " << soyisim << endl << "ogrenci numara : " << numara << endl;
	}
	//Ogrenci tipinden yeni bir nesneyi olusturur ve ona rastgele bir isim soyisim ve numara verir
	void ogrenciOlustur() {
		dosyaYonetim dosya1;
		
		isim = dosya1.dosyadanIsimSec();
		soyisim = dosya1.dosyadanSoyisimSec();
		numara = rand() % 100 + 100;
	}
};
//sinif nesnesi sinifismi ve ogrSayisi uye degiskenleri 
class sinif {
private:

public:
	string sinifIsmi;
	int ogrSayisi;
	//sinif nesnesinin kurucu fonkysonu yeni bir sinifinin olusturuldugunda sinifinin ogrenci sayisina 0 degerini aktarilir
	sinif() {
		ogrSayisi = 0;
	}
	//sinif nesnesine parametre olarak aldigi ismini sinifin ismine aktariyor 
	void sinifIsimAktar(string name) {
		sinifIsmi = name;
	}
	//sinif nesnesine parametre olarak aldigi sayiyi sinifin sayisina aktariyor 
	void ogrSayisiAktar(int num) {
		ogrSayisi = num;
	}
	Ogrenci ogrenciler[100];
	//sinifa kurallara gore bir isim verir
	string sinifaAdVer(int* ptr) {
		int n = *ptr + 1;
		ostringstream strg;
		strg << n;
		string sayi = strg.str();
		sinifIsmi = sayi + char((rand() % 26) + 65);
		return sinifIsmi;
	}
	//sinifa bir ogrenci ekler
	void ogrenciEkle(Ogrenci ogr, int* i) {
		ogr.ogrenciOlustur();
		ogr.ogrBilgileriGoster();
		ogrenciler[(*i)] = ogr;
		(*i)++;
	}
	//siniftan numarasini parametre olarak aldigi ogrenciyi siler 
	void ogrenciSil(int num, int* boyut) {
		Ogrenci* ptr2 = ogrenciler;
		for (int i = 0; i < (*boyut) + 1; i++) {
			if (num == ((*ptr2).ogrNumarasi())) {
				for (int j = i; j <= (*boyut); j++) {
					ogrenciler[j] = ogrenciler[j + 1];
				}
				(*boyut)--;
			}
			ptr2++;
		}
	}
	//siniftan numarasini parametre olarak aldigi ogrenciyi degistirir 
	void ogrenciDegistir(int num, int boyut) {
		
		for (int i = 0; i < /*(**/boyut; i++) {
			if (num == ((ogrenciler[i]).ogrNumarasi())) {
				Ogrenci ogr;
				 ogr.ogrenciOlustur();
				ogr.ogrBilgileriGoster();
				ogrenciler[i] = ogr;
			}
		}
	}
};
//okul nesnesinin 2 uye degiskenleri var okulun sinif sayisi ve sinif tipinden siniflar dizisi siniflardaki ogrencilerinin bilgileri kapsar
class okul {
private:
public:
	int sinifSayisi;
	sinif siniflar[100];
	//okul nesnesinin kurucu fonksyonu kayitlar.txt dosyansindaki bulunan siniflar ve o siniflara ait ogrencilerin bilgileri okuyup siniflar dizisine aktarir
	okul() {
		dosyaYonetim dosya1;

		sinifYapi sinif0 = { " ",0,0 };
		sinifSayisi = dosya1.sinifSayisiniHesapla();
		//asagidaki for dongusu okuldaki bulunan siniflarin bilgilerini okuyarak ve siniflar dizisine aktararak siniflarin sayisina kadar gider 
		for (int j = 0; j < sinifSayisi; j++) {
			sinif0 = dosya1.kayitDosyasindanOku(sinif0.konum);
			siniflar[j].sinifIsimAktar(sinif0.sinifAdi);
			siniflar[j].ogrSayisiAktar(sinif0.ogrSayisi);
			//asagidaki for dongusu siniftaki bulunan ogrencilerin bilgilerini okuyarak ve ogrenciler dizisine aktararak ogrencilerin sayisina kadar gider 
			for (int i = 0; i < sinif0.ogrSayisi; i++) {
				siniflar[j].ogrenciler[i].isimAktar((sinif0.ogrPtr)->isim);
				siniflar[j].ogrenciler[i].soyisimAktar((sinif0.ogrPtr)->soyisim);
				siniflar[j].ogrenciler[i].numaraAktar((sinif0.ogrPtr)->numara);
				(sinif0.ogrPtr)++;
			}

		}
	}
	    //okuldaki siniflarinin ogrenci sayisini en yuksek olan bulur ve bu sayiyi dondurur  
		int enYuksekOgrSayisi() {
			int max = siniflar[0].ogrSayisi;
			for (int i = 1; i < sinifSayisi; i++) {
				if (siniflar[i].ogrSayisi > max)
					max = siniflar[i].ogrSayisi;
				}
			return max;
			}
		
	//okula bir sinif ekler
	void sinifEkle() {
		sinif sinif1;
		int* ptr = &sinifSayisi;
		sinif1.sinifaAdVer(ptr);
		sinif1.ogrSayisi = 0;

		siniflar[sinifSayisi] = sinif1;
		(*ptr)++;

	}
	//okuldan adini parametre olarak aldigi sinifi siler
	void sinifSil(string adi) {
		for (int i = 0; i < sinifSayisi; i++) {
			if (siniflar[i].sinifIsmi == adi) {
				for (int j = i; j < sinifSayisi; j++) {
					siniflar[j] = siniflar[j + 1];
				}
				int* ptr = &sinifSayisi;
				(*ptr)--;
			}
		}
	}
	//okuldaki bulunan butun siniflarin bilgileri ve bu siniflara ait olan ogrencilerin bilgileri ekrana yazdirir
	void sinifListesiGoster() {
		int d;
		int y;
		y = -1;
		d = 1;
		int s = 5;
		//asagidaki for dongusu okuldaki bulunan siniflarin sayisina kadar gider her bir sinifin adini cizgide koyarak ekrana yazdiriyor
		for (int i = 0; i < sinifSayisi; i++) {
			ustYazdirSinif(14, ++y, d);
			koordinatAta(++s, 1);
			cout << siniflar[i].sinifIsmi;
			altYazdirSinif(14, y);
			int n = d + 2;
			int x = y + 2;
			//asagidaki for dongusu siniftaki bulunan ogrencilerin sayisina kadar her bir ogrencinin bilgileri cizgide koyarak ekrana yazdiriyor
			for (int j = 0; j < siniflar[i].ogrSayisi; j++) {
				ustYazdirOgr(12, y, n - 2);
				koordinatAta(x, ++n);
				cout << siniflar[i].ogrenciler[j].ismiyaz();
				koordinatAta(x, ++n);
				cout << siniflar[i].ogrenciler[j].soyIsmiyaz();
				koordinatAta(x, ++n);
				cout << siniflar[i].ogrenciler[j].ogrNumarasi() << endl;
				altYazdirOgr(12, y, ++n);
				n += 2;
			}
			y += 16;
			s += 16;
			koordinatAta(0, n+=10);
		}
	
	}
	//okuldaki bulunan butun siniflarin bilgileri ve bu siniflara ait olan ogrencilerin bilgileri kayitlar.txt dosyasina kaydeder 
	void okulBilgileriKaydet() {
		dosyaYonetim dosya0;
		//asagidaki for dongusu okuldaki bulunan siniflarin sayisina kadar siniflarin bilgilerini kayit.txt dosyasina kaydediyor
		for (int i = 0; i < sinifSayisi; i++) {
			dosya0.sinifBilgilerikaydet(siniflar[i].sinifIsmi, siniflar[i].ogrSayisi);
			//asagidaki for dongusu siniftaki bulunan ogrencilerin sayisina kadar ogrencilerin bilgileri kayit.txt dosyasina kaydediyor
			for (int j = 0; j < siniflar[i].ogrSayisi; j++) {
				dosya0.ogrBilgilerikaydet(siniflar[i].ogrenciler[j].ismiyaz(), siniflar[i].ogrenciler[j].soyIsmiyaz(), siniflar[i].ogrenciler[j].ogrNumarasi());
			}
		}
	}



};
class Program {

public:
	//calistir fonksyonu kullanicinin 6 tusuna basana kadar ona menuyu gosterir ,ona menuden yapmak istedigi islemi secmeyi imkani verir ve sectigi seceneginin islemlerini yapar 
	void calistir() {
		int num;
		srand(time(0));
		okul okul1;
		okul1.sinifListesiGoster();
		num = 0;
		//kullanicinin 6 tusuna basana kadar islemler
		while (num != 6) {
			koordinatAta(0, okul1.enYuksekOgrSayisi()*6 + 3);
			num = menuGoster();
			//kullanici 1 tusuna bastigi anda islem
			if (num == 1) {
				string sinAdi;
				cout << "sinif adi : ";
				cin >> sinAdi;
				int i = 0;
				//bir ogrenci eklemek istedigi sinifini bulana kadar siniflari isimlerini kontrol ediyor
				while (okul1.siniflar[i].sinifIsmi != sinAdi) {
					i++;
				}
				Ogrenci ogr;
				okul1.siniflar[i].ogrenciEkle(ogr, &(okul1.siniflar[i].ogrSayisi));
				system("pause");
				system("cls");
				okul1.sinifListesiGoster();

			}
			//kullanici 2 tusuna bastigi anda okula bir sinif ekler
			else if (num == 2) {
				okul1.sinifEkle();
				system("cls");
				okul1.sinifListesiGoster();
			}
			//kullanici 3 tusuna bastigi anda islem
			else if (num == 3) {
				int ogrNum;
				cout << "ogrenci numarasi : ";
				cin >> ogrNum;
				for (int i = 0; i <= okul1.sinifSayisi; i++) {
					//siniftaki bulunan ogrencilerinin sayisina kadar sayiyor ve kullanicinin degistirmek istedigi ogrenciyi siniftan degistiriyor
					for (int j = 0; j <= okul1.siniflar[i].ogrSayisi; j++) {
						if (okul1.siniflar[i].ogrenciler[j].ogrNumarasi() == ogrNum) {
							okul1.siniflar[i].ogrenciDegistir(ogrNum, okul1.siniflar[i].ogrSayisi);
						}
					}
				}
				system("pause");
				system("cls");
				okul1.sinifListesiGoster();
			}
			//kullanici 4 tusuna bastigi anda islem
			else if (num == 4) {
				int ogrNum;
				cout << "ogrenci numarasi : ";
				cin >> ogrNum;
				//okuldaki bulunan siniflarin sayisina kadar sayiyor
				for (int i = 0; i <= okul1.sinifSayisi; i++) {
					//siniftaki bulunan ogrencilerinin sayisina kadar sayiyor ve kullanicinin silmek istedigi ogrenciyi siniftan siliyor
					for (int j = 0; j <= okul1.siniflar[i].ogrSayisi; j++) {
						if (okul1.siniflar[i].ogrenciler[j].ogrNumarasi() == ogrNum) {
							okul1.siniflar[i].ogrenciSil(ogrNum, &(okul1.siniflar[i].ogrSayisi));
						}
					}
				}
				system("cls");
				okul1.sinifListesiGoster();
			}
			//kullanici 5 tusuna bastigi anda islem
			else if (num == 5) {

				string sinAdi;
				cout << "sinif adi ";
				cin >> sinAdi;
				okul1.sinifSil(sinAdi);
				system("cls");
				okul1.sinifListesiGoster();
			}
			system("cls");
			okul1.sinifListesiGoster();			
		}
		dosyaYonetim dosya1;
		dosya1.dosyayiSil();
		okul1.okulBilgileriKaydet();
		koordinatAta(0, okul1.enYuksekOgrSayisi() * 6 + 3);
		system("pause");
	}

};
int main() {
	Program prg;
	prg.calistir();
}