//***************************
//*                               SAKARYA ÜNİVERSİTESİ
//*                    BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
//*                        BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
//*                          ÖĞRENCİ NUMARASI => g181210552
//*                          ÖĞRENCİNİN ADI => wajeeh bacha
//*                          ÖDEV NUMARASI => 1.1
//*                          DERS GRUBU => C
//*
//*
//*
//*
//****************************
#include <iostream>

using namespace std;

int main()
{
	int space = 1; // space (boşluk) değişkeni tanımladık

	 // sağ ve sol üst üçgenlerin for döngüsü. satirsayisi  değişkeni tanımladık ve ilk değeri 0 belirledik 

	for (int satirsayisi = 0; satirsayisi < 5; satirsayisi++) 

	{//sol üst üçgenin yıldızları . i = basılan yıldız veya boşluk değişkeni
		for (int yildizsayısı = 0; yildizsayısı < 5 - satirsayisi; yildizsayısı++)
		{
			cout <<"*" ;
		}
		for (int yildizsayısı = 0; yildizsayısı < space; yildizsayısı++) //üst kısmın boşlukları
		{
			cout << " ";
		}
		for (int yildizsayısı = 0; yildizsayısı < 5 - satirsayisi; yildizsayısı++)// sağ üst üçgenin yildizlari
		{
			cout << "*";
		}
		  space += 2;// her satirdaki yildizlar basıldıktan sonra boşlukları arttırıyoruz
		  cout << endl; // satır boşluğu
	}
	
	int space1 = 11; // sol kısmın boşluk sayisi

	for (int satirsayisi = 0; satirsayisi < 6; satirsayisi++)// sağ ve sol alt kısmın döngüsü
	{
		for (int yildizsayısı = 0; yildizsayısı < satirsayisi; yildizsayısı++)// sol alt üçgenin yıldızları
		{
			cout << "*";
		}
		for (int yildizsayısı = 0; yildizsayısı < space1; yildizsayısı++)// alt kısmın boşlukları
		{
			cout << " ";
		}
		for (int yildizsayısı = 1; yildizsayısı < satirsayisi + 1; yildizsayısı++)// sağ alt üçgenin yıldızları
		{
			cout << "*";
		}
		space1 -= 2;//har satırdaki yıldızlar basıldıktan sonra boşlukları azaltıyoruz
		cout << endl;
	}
		system("pause");
		return 0;

}