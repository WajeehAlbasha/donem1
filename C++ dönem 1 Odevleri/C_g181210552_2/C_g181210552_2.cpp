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
#include<string.h>

using namespace std;
//değişkenler tanımlama
int i, j, a, b, random, random1, random2;
bool benzersiz = true;
const int satir = 5;
const int sutun = 10;
//matris tanımlama
int litters[satir][sutun];

int main()
{
	
	srand(time(NULL));//bastırdığımız random harflerin kapatıp açtığımızda yenilenmesi için

	cout << "random harfler:" << endl << endl;
	//matrisi dödüren döngü
	for (i = 0; i < satir; i++)
	{
		for (j = 0; j < sutun; j++)
		{//sutunları bir büyük bir küçük harflı olacak şekilde random harf basamak için if döngü
			if (j % 2 == 0)//eğer sutun sayısının ikiye bölmesi 0 ise 
			{
				do
				{
					random1 = rand() % 26 + 65;//random büyük harfları üreten fonksyon
					for (a = 0; a < satir; a++)//satırları arttırarak devam eden for döngü
					{
						for (b = 0; b < sutun; b++)//sutunları arttırarak devam eden for döngü
						{
							//basılan harfın benzeri yoksa random harfı matrise ata
							benzersiz = true;
							if (litters[a][b] == random1)
							{//basılan harfın benzeri varsa dönen a ve b yi satir ve sutun 
							 //sayısına eşitleyerek döngüden çıkmasını sağlayan fonksyon
								benzersiz = false;
								b = sutun;
								a = satir;
							}
						}
					}

				} while (!benzersiz);//bastırdığımız random harfları random 1'e atıyoruz
				litters[i][j] = random1;
			}
			else
			{
				do
				{
					random2 = rand() % 26 + 97;//random küçük harfları üreten fonksyon
					for (a = 0; a < satir; a++)//satırları arttırarak devam eden for döngü
					{
						for (b = 0; b < sutun; b++)//sutunları arttırarak devam eden for döngü
						{//basılan harfın benzeri yoksa random harfı matrise ata
							benzersiz = true;
							if (litters[a][b] == random2)
							{
							 //basılan harfın benzeri varsa dönen a ve b yi satir ve sutun 
							 //sayısına eşitleyerek döngüden çıkmasını sağlayan fonksyon
								benzersiz = false;
								b = sutun;
								a = satir;
							}
						}
					}

				} while (!benzersiz);//bastırdığımız random harfları random 2'e atıyoruz
				litters[i][j] = random2;
			}
		}
	}

	for (i = 0; i < satir; i++)//matrisi basan for döngüsü
	{
		for (j = 0; j < sutun; j++)
		{
			cout << setw(2) << (char)litters[i][j] ;//matrisi chara dünüştürerek harf olarak yazar
		}
		cout << endl;
	}

	cout << endl << "A'dan z'ye harfler:" << endl << endl;
	for (int i = 0; i < satir; i++) //harfları A'dan z'ye sıralayan döngü 
	{
		for (int j = 0; j < sutun; j++) 
		{
			int m = i;
			int n = j + 1;
			while (true) 
			{ //10. sutundeki harfı sıraladıktan sonra bir sonraki satıra geçmeyi sağlayan döngü
				if (n == 10) 
				{
					n = 0;
					m++;
					if (m == 5) break;//5. satıra geldiğinde dur
				}
				//n'i arttırarak harfları birbirine karşılaştırır ve farfları sıralar
				//yukardaki if döngü sayesinde 10. sutunden sonra bir sonraki satıra gelir 
				//ve karşılaştırmaya devam eder
				if (litters[i][j] > litters[m][n]) std::swap(litters[i][j], litters[m][n]);

				n++;
			}
		}
	}
	
	for (i = 0; i < satir; i++)//random atılan harfların sıralandıktan sonra ekrana basar
	{
		for (j = 0; j < sutun; j++)
		{
			cout << setw(2) << (char)litters[i][j] ;//matrisi chara dünüştürerek harf olarak yazar
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}
