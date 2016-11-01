#ifndef MONOALPHABETIC_H
#define MONOALPHABETIC_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include "CipherInterface.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * This class implements the playfair cipher.
 * The class extends the abstract class 
 * CipherInterface.
 */

class Monoalphabetic: public CipherInterface
{
	/** The public members **/
	public:

		/**
		 * Sets the key to use
		 * @param key - the key to use
		 * @return - True if the key is valid and False otherwise
		 */
		bool setKey(const string& key);

		/**	
		 * Encrypts a plaintext string
		 * @param plaintext - the plaintext string
		 * @return - the encrypted ciphertext string
		 */
		string encrypt(const string& plaintext);

		/**
		 * Decrypts a string of ciphertext
		 * @param ciphertext - the ciphertext
		 * @return - the plaintext
		 */
		string decrypt(const string& ciphertext);
			
	
		
		/* The protected members */
	protected:
		char mKey[26][2];
	

};

#endif
