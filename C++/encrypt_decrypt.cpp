/*
	filename: encrypt_decrypt.cpp
*/
#include<bits/stdc++.h>
using namespace std;

// Key for Columnar Transposition
string const key = "HACK";
map<int,int> keyMap;

//function name: void setPermutationOrder()
//description: adds the permutation order into map
void setPermutationOrder()
{			
	for(int i=0; i < key.length(); i++)
	{
		keyMap[key[i]] = i;
	}
}
//end of void setPermutationOrder()

//function name: string encryptMessage(string msg)
//description: encrypts the message
string encryptMessage(string msg)
{
	int row,col,j;
	string cipher = "";
	
	col = key.length();
	
	row = msg.length()/col;
	
	if (msg.length() % col)
		row += 1;

	char matrix[row][col];

	for (int i=0,k=0; i < row; i++)
	{
		for (int j=0; j<col; )
		{
			if(msg[k] == '\0')
			{
				matrix[i][j] = '_';	
				j++;
			}
			
			if( isalpha(msg[k]) || msg[k]==' ')
			{
				matrix[i][j] = msg[k];
				j++;
			}
			k++;
		}
	}

	for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
	{
		j=ii->second;

		for (int i=0; i<row; i++)
		{
			if( isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]=='_')
				cipher += matrix[i][j];
		}
	}

	return cipher;
}
//end of string encryptMessage(string msg)

//function name: string decryptMessage(string cipher)
//description: decrypts the message
string decryptMessage(string cipher)
{
	int col = key.length();

	int row = cipher.length()/col;
	char cipherMat[row][col];

	for (int j=0,k=0; j<col; j++)
		for (int i=0; i<row; i++)
			cipherMat[i][j] = cipher[k++];

	int index = 0;
	for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
		ii->second = index++;

	char decCipher[row][col];
	map<int,int>::iterator ii=keyMap.begin();
	int k = 0;
	for (int l=0,j; key[l]!='\0'; k++)
	{
		j = keyMap[key[l++]];
		for (int i=0; i<row; i++)
		{
			decCipher[i][k]=cipherMat[i][j];
		}
	}

	string msg = "";
	for (int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(decCipher[i][j] != '_')
				msg += decCipher[i][j];
		}
	}
	return msg;
}
//end of string decryptMessage(string cipher)

//start of main
int main(void)
{
	string msg = "Amaan Shaikh";
	setPermutationOrder();
	string cipher = encryptMessage(msg);
	cout << "Encrypted Message: " << cipher << endl;
	cout << "Decrypted Message: " << decryptMessage(cipher) << endl;
	return 0;
}
//end of main
