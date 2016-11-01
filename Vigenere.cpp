#include "Vigenere.h"

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Vigenere::setKey(const string& key)
{ 
	//need to make sure that key is a valid integer
	for (int i = 0; i < key.length();++i){
			if(key[i]<=122 && key[i] >=97 ){
				
				//do nothing
				}else{
					//has space or special character or even a numerical value
					return false;
				
				}
			}
				
	//key must be valid
	vKey = key;
			
	return true;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Vigenere::encrypt(const string& plaintext){
	
	//useful variables
	int totalNumberOfLetters = 26;
	int lowerASCIIEnd = 122;
	int lowerAscIIStart = 97;
	string tempString = plaintext;
    tempString.erase(remove(tempString.begin(),tempString.end(),' '),tempString.end());
	int c;
	int counter = 0;
	char tempArray[tempString.length()];
	int keyLength = vKey.length();
	
	for (int i = 0; i<tempString.length(); ++i){
		
		c = (int(tempString[i]) - lowerAscIIStart + int(vKey[i%keyLength])- lowerAscIIStart)%totalNumberOfLetters;
		c += lowerAscIIStart;
		tempArray[i] = char(c);
		counter++;
	}
	

	string str(tempArray,counter);	
	return str; 
	
}
	
/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Vigenere::decrypt(const string& cipherText) { 
	
	int totalNumberOfLetters = 26;
	int lowerASCIIEnd = 122;
	int lowerAscIIStart = 97;
	string tempString = cipherText;
    tempString.erase(remove(tempString.begin(),tempString.end(),' '),tempString.end());
	int p;
	char tempArray[tempString.length()];
	int keyLength = vKey.length();
	int counter = 0;
	
	for (int i = 0; i<tempString.length(); ++i){
		
		p = (int(tempString[i]) - lowerAscIIStart) - (int(vKey[i%keyLength])- lowerAscIIStart);
		
		if(p<0){
			p+=26;
		}
		if(p>26){
			p-=26;
		}
		p%=totalNumberOfLetters;
		
		p += lowerAscIIStart;
		tempArray[i] = char(p);
		counter++;
	}
	

	string str(tempArray,counter);	
	return str; 
	
}

