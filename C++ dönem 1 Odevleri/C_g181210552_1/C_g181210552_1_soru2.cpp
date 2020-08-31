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
#include <iomanip>
#include <conio.h>
#include <locale.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");//türkçe karakter

	char harfler = 'j';//char tanımlamak

	int sayacA = 0, sayacE = 0, sayacO = 0, sayacU = 0, sayacI = 0; //değişken tanımlama

	cout << "yaziyi giriniz :  ";//ekrana göster


	while (harfler != '\r')//enter tuşuna basana kadar çalışan döngü
	{
		harfler = _getwche();//klaviyeden teker harf alan fonksyon


		if (harfler == 'A' || harfler == 'a')//a harfları sayan if döngüsü
			sayacA++;

		if (harfler == 'E' || harfler == 'e')//e harfları sayan if döngüsü
			sayacE++;

		if (harfler == 'O' || harfler == 'o')//o harfları sayan if döngüsü
			sayacO++;

		if (harfler == 'U' || harfler == 'u')//u harfları sayan if döngüsü
			sayacU++;

		if (harfler == 'I' || harfler == 'i')//i harfları sayan if döngüsü
			sayacI++;

	}
	cout << endl << endl;

	int maxkarakter = 0;
	//en çok girilen karakterin sayısına göre birden maxkarakter sayısına kadar sayı basan fonksyon
	//sayacA değeri maxkarakterden büyükse sayacA nın değeri maxkaraktere at
	if (sayacA > maxkarakter)
	{
		maxkarakter = sayacA;
	}
	else if (sayacE > maxkarakter)
	{
		maxkarakter = sayacE;
	}
	else if (sayacO > maxkarakter)
	{
		maxkarakter = sayacO;
	}
	else if (sayacU > maxkarakter)
	{
		maxkarakter = sayacU;
	}
	else if (sayacI > maxkarakter)
	{
		maxkarakter = sayacI;
	}
	//maaxkarakterin değeri bütün karakterlerin değerleri ile karşılaştırarak en çok girilen karakteri belirtiyoruz


	cout << "HARF" << setw(15) << "TS";
	cout << setw(4);

	for (int i = 1; i <= maxkarakter; i++)//maxkarakter değerine göre sayı basan fonksyon
	{
		cout << i << setw(5);
	}



	cout << endl;

	//ekrana A karakteri ve A karakterinin kaç kere gerildiğine göre a basan fonksyon
	cout << endl << "A                " << sayacA;
	for (int a = 0; a < sayacA; a++)
		cout << setw(5) << "a";

	//ekrana E karakteri ve A karakterinin kaç kere gerildiğine göre e basan fonksyon
	cout << endl << "E                " << sayacE;
	for (int e = 0; e < sayacE; e++)
		cout << setw(5) << "e";

	//ekrana O karakteri ve O karakterinin kaç kere gerildiğine göre o basan fonksyon
	cout << endl << "O                " << sayacO;
	for (int o = 0; o < sayacO; o++)
		cout << setw(5) << "o";

	//ekrana U karakteri ve U karakterinin kaç kere gerildiğine göre u basan fonksyon
	cout << endl << "U                " << sayacU;
	for (int u = 0; u < sayacU; u++)
		cout << setw(5) << "u";

	//ekrana I karakteri ve I karakterinin kaç kere gerildiğine göre i basan fonksyon
	cout << endl << "I                " << sayacI;
	for (int i = 0; i < sayacI; i++)
		cout << setw(5) << "i";

	cout << endl;


	system("pause");
	return 0;
}


