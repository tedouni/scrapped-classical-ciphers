#include "Railfence.h"

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */

//TODO:Need to get vectors working as a vector except dynamic vec[i].size()
//    Basically not all rKey rows will have the same number of elements
// 	
// 		
// 			


bool Railfence::setKey(const string& key)
{ 
	int check;
	istringstream iss(key);
	iss >> check;

	if(iss.eof() == false){
		//not an int
		return false;
	}

	//otherwise key is an int and may be used
	rKey = stoi(key);	
	return true;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Railfence::encrypt(const string& plaintext){
	// string tempString = plaintext;
	//     tempString.erase(remove(tempString.begin(),tempString.end(),' '),tempString.end());
	// int length = tempString.length();
	//
	// for (int i = 0; i != rKey; ++i){
	//
	// 	bool isBottom = false;
	// 	int bottomSkip = 2 * (rKey - i -1);
	// 	int topSkip = 2*row;
	//
	// 	for (int j  = i; j < )
	// }
	//
	// string str(tempArray,counter);
	return "str"; 	
}
	
/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Railfence::decrypt(const string& cipherText) { 
	

	return "str"; 
	
}

