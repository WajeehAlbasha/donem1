//***************************
//*                               SAKARYA ÜNİVERSİTESİ
//*                    BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
//*                        BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
//*                          ÖĞRENCİ NUMARASI => g181210552
//*                          ÖĞRENCİNİN ADI => wajeeh bacha
//*                          ÖDEV NUMARASI => proje1
//*                          DERS GRUBU => C
//*
//*
//*
//*
//****************************
#include<iostream>
#include<windows.h>

using namespace std;
enum YON
{
	YON_SOL = 1,
	YON_SAG = 2,
	YON_YUKARI = 3,
	YON_ASAGI = 4,
	YON_DURAGAN = 5,
};
struct KoordinatBilgi
{
	int x;
	int y;
	YON yon;
	char karakter;
};

const int genislik = 80;
const int yukseklik = 20;
char sahne[genislik][yukseklik];
char tuslar[256];
int mermisayac = 0;
int dusmansayac = 0;
const int maxmermi =500;
const int maxdusman = 500;
int rastgeledusmanx = 80;
int a = 0;

KoordinatBilgi mermi[maxmermi];
KoordinatBilgi ucak[genislik];
KoordinatBilgi dusman[maxdusman];

void kursorugizle();
void gotoxy(int, int);
void sahneyiciz();
void sahnetemizle();
void sinirlariolustur();
void klavyeOku(char tuslar[])
{
	for (int x = 0; x < 256; x++)
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
}
void ucakOlustur()
{
	ucak[0].x = 1;
	ucak[0].y = 1;


	ucak[1].x = 2;
	ucak[1].y = 2;


	ucak[2].x = 3;
	ucak[2].y = 3;


	ucak[3].x = 2;
	ucak[3].y = 4;


	ucak[4].x = 1;
	ucak[4].y = 5;

}
void ucakCiz()
{
	for (int i = 0; i < 5; i++)
	{
		int x = ucak[i].x;
		int y = ucak[i].y;
		sahne[x][y] = 219;
	}
}
void mermiOlustur()
{
	mermi[mermisayac].x = ucak[2].x + 1;
	mermi[mermisayac].y = ucak[2].y;

}
void mermiCiz()
{
	for (int b = 0; b <maxmermi; b++)
	{
	
		int x = mermi[b].x;
		int y = mermi[b].y;
		sahne[x][y] =219;
		if (mermi[b].x != genislik)
		{
			mermi[b].x++;
		}
	}
}
void dusmanOlustur()
{
	
	
			int rastgeledusmany = rand() % 16+1;
			dusman[dusmansayac].x = rastgeledusmanx;
			dusman[dusmansayac].y = rastgeledusmany;

	
}
void dusmanCiz()
{
	
    {
		int x = dusman[dusmansayac].x;
		int y = dusman[dusmansayac].y;
		sahne[x][y] = 177;
		sahne[x+1][y] = 177;
		sahne[x+2][y] = 177;
		sahne[x][y+1] = 177;
		sahne[x][y+2] = 177;
		sahne[x+2][y+1] = 177;
		sahne[x+1][y+2] = 177;
		sahne[x+2][y+2] = 177;
	}
}
void dusmanhareketettir()
{
	for (int a = 0; a < genislik; a++)
	{

		dusman[a].x--;
	}
}
void carpisma()
{
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < mermisayac; j++)
		{
			if (dusman[i].x == mermi[j].x && (dusman[i].y == mermi[j].y || dusman[i].y + 1 == mermi[j].y || dusman[i].y + 2 == mermi[j].y))
			{
				mermi[j].x = NULL;
				mermi[j].y = NULL;
				dusman[i].x = NULL;
				dusman[i].y = NULL;
			}
			else if (mermi[j].x == genislik - 1)
			{
				mermi[j].x = NULL;
				mermi[j].y = NULL;
			}
		}
	}
}
void klavyeKontrol()
{
	int a = 0;
	klavyeOku(tuslar);
	for (int i = 0; i < 5; i++)
	{
		if (tuslar['W'] != 0)
		{
			ucak[i].yon = YON_YUKARI;
		}
		if (tuslar['S'] != 0)
		{
			ucak[i].yon = YON_ASAGI;
		}

		if (tuslar['A'] != 0)
		{
			mermiOlustur();
			mermisayac++;
		}
		

	}

}
void ucakHareketEttir()
{
	for (int i = 0; i < 5; i++)
	{
		switch (ucak[i].yon)
		{
		case YON_ASAGI:
			ucak[i].y++;
			ucak[i].yon = YON_DURAGAN;
			break;
		case YON_YUKARI:
			ucak[i].y--;
			ucak[i].yon = YON_DURAGAN;
			break;
		}
	}
}
int main()
{
	kursorugizle();
	ucakOlustur();

	while (true)
	{
		sahnetemizle();
		sinirlariolustur();
		klavyeKontrol();
		ucakHareketEttir();
		
		ucakCiz();
		mermiCiz();

		if (dusman[dusmansayac].x == 0)
		{
			dusmansayac++;
			dusmanOlustur();
		}
	    dusmanCiz();
		dusmanhareketettir();
		carpisma();

		gotoxy(0, 0);
		sahneyiciz();
		Sleep(2);
	}
	system("pause");
}
void gotoxy(int x, int y)//koordinat değiştirme fonksyonu
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void kursorugizle()//kursor gizleme fonksyonu
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO  cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void sahnetemizle()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			sahne[x][y] = ' ';
		}

	}
}
void sahneyiciz()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			cout << sahne[x][y];
		}
		cout << endl;
	}
}
void sinirlariolustur()
{
	for (int x = 0; x < genislik; x++)
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}
	for (int y = 0; y < yukseklik; y++)
	{
		sahne[0][y] = 219;
		sahne[genislik - 1][y] = 219;
	}
}
