#include<iostream>
#include<string>

using namespace std;

string alphabet;
void getAlphabet()
{
	cout << "Enter alphabet: ";
	cin >> alphabet;
	
	for (int i = 0; i < alphabet.length(); i++)
	{
		alphabet[i] = toupper(alphabet[i]);
	}
}

int tableArr[26][26];

void vigenereTable()
{
	int counter = 0;
	int counter2 = 0;
	int sayac1 = 0;
	getAlphabet();
	
	for (int i = 0; i < alphabet.length(); i++)
	{
		int starter = 0;
		for (int j = 0; j < alphabet.length(); j++)
		{
		if (i + counter <= alphabet.length())
		{
			tableArr[i][j] = alphabet[i + counter];
			counter++;
		}
		if (i + counter > alphabet.length())
		{
			tableArr[i][j] = alphabet[counter2];
			counter2++;
		}
	}
	counter = 0;
	counter2 = 0;
	}
	int counter3 = 0;
	int counter4 = 0;
	
	
	for (int i = 0; i < alphabet.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			tableArr[i][j + alphabet.length()] = tableArr[counter4][counter3];
			counter3++;
			if (j <= alphabet.length())
			{
				counter3 = 0;
			}
			
		}
		counter4++;
		counter3 = counter4;
	}
	
	for (int i = 0; i < alphabet.length(); i++)
	{
		
		for (int j = 0; j < 26; j++)
		{
			cout << (char)tableArr[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	vigenereTable();
	system("pause");
}