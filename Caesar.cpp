#include "Caesar.h"

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{ 
	//need to make sure that key is a valid integer
	int check;
	istringstream iss(key);
	iss >> check;

	if(iss.eof() == false){
		//not an int
		return false;
	}

	//otherwise key is an int and may be used
	cKey = stoi(key)%26;	//set cKey used for encryption or decryption
	return true;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Caesar::encrypt(const string& plaintext)
{ 
	int totalNumberOfLetters = 26;
	int lowerASCIIEnd = 122;
	string tempString = plaintext;
    tempString.erase(remove(tempString.begin(),tempString.end(),' '),tempString.end());
	
	int counter = 0;
	int c;
	char tempArray[tempString.length()];
	for (int i =0; i<tempString.length(); ++i){
		
			c = int(tempString[i]) + cKey;
			if (c >lowerASCIIEnd)
				c = c -26;
	
		
		
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
string Caesar::decrypt(const string& cipherText) 
{ 
	int totalNumberOfLetters = 26;
	int lowerAscIIStart = 97;
	
	string tempString = cipherText;
    tempString.erase(remove(tempString.begin(),tempString.end(),' '),tempString.end());
	
	int c;
	int counter = 0;
	char tempArray[tempString.length()];
	for (int i =0; i<tempString.length(); ++i){
		
			c = int(tempString[i]) - cKey;
			if (c <lowerAscIIStart)
				c = c +26;
	
		
		
		tempArray[i] = char(c);
		counter++;
		
	}
	string str(tempArray,counter);
	
	return str; 
	
}

