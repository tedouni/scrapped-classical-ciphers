#include "Monoalphabetic.h"

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Monoalphabetic::setKey(const string& key)
{ 
	//MAKE SURE NO REPEATING LETTERS
	int lowerASCIIEnd = 122;
	int lowerAscIIStart = 97;
	for (int i = 0; i < key.length();++i){
			if(key[i]<=122 && key[i] >=97 ){
				
				for(int j = 0; j<2;++j){
					
					if (j==0)
						mKey[i][j]= char(i+lowerAscIIStart);
					else
						mKey[i][j] = key[i];
						
						
				}
				
				}else{
					//has space or special character or even a numerical value
					return false;
				
				}
			}
				
	//key must be valid
			
	return true;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Monoalphabetic::encrypt(const string& plaintext){
	
	string tempString = plaintext;
    tempString.erase(remove(tempString.begin(),tempString.end(),' '),tempString.end());
	int counter = 0;
	
	char tempArray[tempString.length()];
	char c;
	
	for (int i = 0; i<tempString.length(); i++){
		
		c = tempString[i];
		
		switch (c){
			case 'a':
			tempArray[i] = mKey[0][1];
			counter++;
			break;
			case 'b':
			tempArray[i] = mKey[1][1];
			counter++;		
			break;
			case 'c':
			tempArray[i] = mKey[2][1];
			counter++;		
			break;
			case 'd':
			tempArray[i] = mKey[3][1]; 			
			counter++;
			break;
			case 'e':
			tempArray[i] = mKey[4][1];
			counter++;
			break;
			case 'f':
			tempArray[i] = mKey[5][1];			
			counter++;
			break;
			case 'g':
			tempArray[i] = mKey[6][1];			
			counter++;
			break;
			case 'h':
			tempArray[i] = mKey[7][1];			
			counter++;
			break;
			case 'i':
			tempArray[i] = mKey[8][1];			
			counter++;
			break;
			case 'j':
			tempArray[i] = mKey[9][1];			
			counter++;
			break;
			case 'k':
			tempArray[i] = mKey[10][1];			
			counter++;
			break;
			case 'l':
			tempArray[i] = mKey[11][1];			
			counter++;
			break;
			case 'm':
			tempArray[i] = mKey[12][1];			
			counter++;
			break;
			case 'n':
			tempArray[i] = mKey[13][1];			
			counter++;
			break;
			case 'o':
			tempArray[i] = mKey[14][1];			
			counter++;
			break;
			case 'p':
			tempArray[i] = mKey[15][1];			
			counter++;
			break;
			case 'q':
			tempArray[i] = mKey[16][1];			
			counter++;
			break;
			case 'r':
			tempArray[i] = mKey[17][1];			
			counter++;
			break;
			case 's':
			tempArray[i] = mKey[18][1];			
			counter++;
			break;
			case 't':
			tempArray[i] = mKey[19][1];			
			counter++;
			break;
			case 'u':
			tempArray[i] = mKey[20][1];		
			counter++;
			break;
			case 'v':
			tempArray[i] = mKey[21][1];			
			counter++;
			break;
			case 'w':
			tempArray[i] = mKey[22][1];			
			counter++;
			break;
			case 'x':
			tempArray[i] = mKey[23][1];			
			counter++;
			break;
			case 'y':
			tempArray[i] = mKey[24][1];	
			counter++;
			break;
			case 'z':
			tempArray[i] = mKey[25][1];
			counter++;
			break;
			
			default:
			break;
		}
		
		
	}
	

	string str(tempArray,counter);	
	return str; 
	
}
	
/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Monoalphabetic::decrypt(const string& cipherText) { 
	
	string tempString = cipherText;
    tempString.erase(remove(tempString.begin(),tempString.end(),' '),tempString.end());
	int counter = 0;
	
	char tempArray[tempString.length()];
	char c;
	
	
	for (int i = 0; i<tempString.length(); i++){
		
		c = tempString[i];
		
		//iterate key array[j][]
		for (int j = 0; j<26; ++j){
			
			if (mKey[j][1] == c){
				tempArray[i] = mKey[j][0];
				counter++;
				break;
			}
		}
		
		
	}
	

	string str(tempArray,counter);	
	return str; 
	
	
}

