#include <string>
#include "CipherInterface.h"
#include "Playfair.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Caesar.h"
#include "Vigenere.h"
#include "Monoalphabetic.h"
#include "Railfence.h"

//

//interface
void iterateFiles(const string& inputFile,const string&  outputFile,const string&  key,const string&  EorD, CipherInterface* cipher, const string& cipherName);

using namespace std;

int main(int argc, char** argv)
{

	if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL || argv[5] == NULL) {
		cout<<"ERROR: Invalid Input. Try './cipher <cipherName> <key> <ENC/DEC> <inputfile> <outputfile>'\n";
		return 0;
	}

	//initialize values from arguments
	string cipherName = argv[1];
	string key = argv[2];
	string EorD = argv[3];
	string inputFile = argv[4];
	string outputFile = argv[5];




	CipherInterface* cipher = NULL;

	//Choose correct cipher
	if (cipherName == "PLF" || cipherName == "Playfair"){
		cout<<"you chose Playfair"<<endl;
	//CipherInterface* cipher = new Playfair();

	}else if(cipherName == "RTS" || cipherName == "RowTransposition"){
		cout<<"You chose Row Transposition\n";
	}else if (cipherName == "RFC" || cipherName == "Railfence"){
		cout<<"You chose Railfence\n";
		CipherInterface* cipher = new Railfence();
		iterateFiles(inputFile, outputFile, key, EorD, cipher,cipherName);

	}else if (cipherName == "VIG" || cipherName == "Vigenre"){
		cout<<"You chose Vigenre\n";
		CipherInterface* cipher = new Vigenere();
		iterateFiles(inputFile, outputFile, key, EorD, cipher,cipherName);

	}else if (cipherName == "CES" || cipherName == "Caesar"){
		cout<<"You chose Caesar\n";
		CipherInterface* cipher = new Caesar();
		iterateFiles(inputFile, outputFile, key, EorD, cipher,cipherName);

	}else if (cipherName == "MAC" || cipherName == "MonoalphabeticCipher"){
		cout<<"You chose Monoalphabetic Cipher\n";
		CipherInterface* cipher = new Monoalphabetic();
		iterateFiles(inputFile, outputFile, key, EorD, cipher,cipherName);


	}else{

		cout<<"ERROR: Invalid Cipher name. Please try again\n";
	}



	cout<<"Operation Completed!\n";
	delete cipher;	//end of program
	return 0;
}

//implementation
void iterateFiles(const string& inputFile,const string&  outputFile,const string&  key,const string&  EorD, CipherInterface* cipher, const string& cipherName){
	bool isValid = cipher->setKey(key);
	if(isValid){

		//open appropiate files
		fstream inFile;
		fstream opFile;
		inFile.open(inputFile,ios::in);
		opFile.open(outputFile,ios::out);
		string tempString;

		string in;

		int i =0;
		while(!inFile.eof()){
			inFile >>in;
			if(EorD == "ENC"){
				tempString = cipher->encrypt(in);}
				else{
					tempString = cipher->decrypt(in);}

			opFile <<tempString;
			i++;
		}


		opFile.close();
		inFile.close();
	}
	else{
		cout<<"ERROR: Invalid Key for "<<cipherName<<" cipher. Please try again.\n";
		exit(0);
	}

}
