#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Extends the keyword to match the length of the text,
// aligning only with alphabetic characters.
// Passes the string by contant reference improves memory management 
// and ensures that the function cannot modify the original text. 
string generateFullKey(const string& text, const string& key) {
    string fullKey = ""; 
    int keyIndex = 0;
    
	//Uses range based for loops (C++ 11), eliminating the need for 
	//manual index tracking used previously. Checks whether the 
	//character is a letter and uses the modulo operator to repeat
	//the key in sequence regardless of how large keyIndex grows.
    for (char c : text) {
        if (isalpha(c)) {
            fullKey += toupper(key[keyIndex % key.length()]);
            keyIndex++;
        } else {
            fullKey += c; // Preserve non-alphabetic characters
        }
    }
    return fullKey;
}

// Encrypts plaintext using the Vigenère cipher formula:
// C_i = (P_i + K_i) mod 26
// Uses size_t, the unsigned int type returned by .length(). 
// char base uses a ternary operator to perform ASCII
// manipulation previously done manually.
// line 45 converts the numeric position back to its proper ASCII char
string encryptVigenere(const string& text, const string& key) {
    string cipherText = "";
    string extendedKey = generateFullKey(text, key);

    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int p = text[i] - base;
            int k = extendedKey[i] - 'A';
            char encryptedChar = base + (p + k) % 26;
            cipherText += encryptedChar;
        } else {
            cipherText += text[i];
        }
    }
    return cipherText;
}

// Decrypts ciphertext using the Vigenère cipher formula:
// P_i = (C_i - K_i + 26) mod 26
string decryptVigenere(const string& cipherText, const string& key) {
    string plainText = "";
    string extendedKey = generateFullKey(cipherText, key);

    for (size_t i = 0; i < cipherText.length(); ++i) {
        if (isalpha(cipherText[i])) {
            char base = isupper(cipherText[i]) ? 'A' : 'a';
            int c = cipherText[i] - base;
            int k = extendedKey[i] - 'A';
            char decryptedChar = base + (c - k + 26) % 26;
            plainText += decryptedChar;
        } else {
            plainText += cipherText[i];
        }
    }
    return plainText;
}


//Continues allowing the user to encrypt, decrypt until the user indicates the desire to stop
int main() {
    string message;
    string key;
    int choice;
        while (true){
            cout << "===== Vigenère Cipher Utility =====\n";
            cout << "1. Encrypt Message\n";
            cout << "2. Decrypt Message\n";
            cout << "Z. Exit\n";
            cout << "Select an option (1, 2, or Z): ";
            
            if (!(cin >> choice) || (choice != 1 && choice != 2)) {
                cerr << "Thank you for playing. Exiting.\n";
                break;
                return 1;
            }
            else{
                cin.ignore(); // Clear newline buffer
                cout << "Enter the key (alphabetic characters only): ";
                getline(cin, key);

                cout << "Enter the message: ";
                getline(cin, message);

                    if (choice == 1) {
                        string encrypted = encryptVigenere(message, key);
                        cout << "\nEncrypted Message: " << encrypted << "\n";
                    } 
                    else {
                        string decrypted = decryptVigenere(message, key);
                        cout << "\nDecrypted Message: " << decrypted << "\n";
                    }
                     
            }
        }

            return 0;
}