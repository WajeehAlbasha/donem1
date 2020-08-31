//***************************
//*                               SAKARYA ÜNİVERSİTESİ
//*                    BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
//*                        BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
//*                          ÖĞRENCİ NUMARASI => g181210552
//*                          ÖĞRENCİNİN ADI => wajeeh bacha
//*                          ÖDEV NUMARASI => 3
//*                          DERS GRUBU => C
//*
//*
//*
//*
//****************************
#include<iostream>
#include<iomanip>
#include<locale.h>

using namespace std;
struct Islem
{
	int giris[5][5] = { 3,2,5,1,4,
					 6,2,1,0,7,
					 3,0,0,2,0,
					 1,1,3,2,2,
					 0,3,1,0,0 };
};
Islem değer;
int girismatrisi = (sizeof(değer.giris) / sizeof(*değer.giris));


int boyut, kayma, i, j;
int n = 0, m = 0;
int toplam = 0;
const int satir = 5;
const int sutun = 5;
int cekirdek[satir][sutun];
int sonuc[5][5];//matris tanımlama
int giris[5][5];
int topla ;

void matrisyaz(int[5][5], int);//fonksyon tanımlama
void matrisCarp(int, int);



int main()
{
	setlocale(LC_ALL, "turkish");

	cout << "cekirdek boyutunu griniz: ";
	cin >> boyut;
	cout << "kayma miktarini giriniz:";
	cin >> kayma;
	if (kayma >= boyut)
	{
		cout << "bu islem yapilmaz" << endl;
	}
	else
	{
		for (int satir = 0; satir < boyut; satir++)//çekirdek fonksyonu kullancıdan almak 
		{
			for (int sutun = 0; sutun < boyut; sutun++)
			{
				cout << "cekirdek[" << satir << "]" << "[" << sutun << "]:";
				cin >> cekirdek[satir][sutun];
			}

		}
		cout << "giris matris" << endl;
		matrisyaz(giris, 5);//matrisyazan fonksyon
		cout << "cekirdek matris" << endl;
		for (int satir = 0; satir < boyut; satir++) //cekirdek matrisi yazdırmal
		{
			for (int sutun = 0; sutun < boyut; sutun++)
				cout << cekirdek[satir][sutun] << " ";
			cout << endl;
		}
		cout << "Carpim Sonucu : " << endl;
		
		

		//matriscarp2(giris, cekirdek, boyut,kayma);
		//matrisyaz(sonuc, boyut);
		int çıkış_sütun = 0, giriş_sütun = 0, çekirdek_sütun = 0;
		çıkış_sütun = ((giriş_sütun - boyut) / kayma) + 1;//son matrisin boyutunu hesaplama
		int sonuc = çıkış_sütun, i, j;
		if (çıkış_sütun - sonuc)
		{
			for (i=n ; i < çıkış_sütun; i++)//kaydırma fonksyonu
			{
				for (int j=m ; j < çıkış_sütun; j++)
				{
					 matrisCarp(i, j);
					  int matris[5][5];
					 for (int i = 0; i < boyut; i++)
					 {
						 for (int j = 0; j < boyut; j++)
						 {
							 cout << matris[i][j] << " ";
						 }
						 cout << endl;
					 }
				}
			}
		}


	}
	system("pause");
	return 0;
}

void matrisyaz(int matris[5][5], int boyut)//matris yazma fonksyonu
{
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			cout << matris[i][j] << " ";
		}
		cout << endl;
	}
}

void matrisCarp(int j, int i)//matris çarpma fonksyonu
{
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			toplam = giris[i][j] * cekirdek[i][j];
			sonuc[i][j] = toplam;
			toplam = 0;
		}

	}
}


