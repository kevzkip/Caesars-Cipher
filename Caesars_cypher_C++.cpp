#include <iostream>
#include <cctype>

using namespace std;

// Function to encrypt the text with a given shift value
string encrypt(const string& text, int shift) {
    string result = "";

    for (char ch : text) {
        if (isalnum(ch)) {
            if (isalpha(ch)) {
                if (isupper(ch)) {
                    result += static_cast<char>((ch + shift - 'A') % 26 + 'A');
                } else {
                    result += static_cast<char>((ch + shift - 'a') % 26 + 'a');
                }
            } else {
                result += static_cast<char>((ch + shift - '0') % 10 + '0');
            }
        } else {
            result += ch;
        }
    }

    return result;
}

// Function to decrypt the text with a given shift value
string decrypt(const string& text, int shift) {
    return encrypt(text, -shift);
}

int main() {
    // Ask the user to enter the text they want to encrypt.
    string text;
    cout << "Enter the text to encrypt: ";
    getline(cin, text);

    // Ask the user to enter the shift value (the secret key).
    int shift;
    cout << "Enter the shift value: ";
    cin >> shift;

    // Call the encrypt function to get the encrypted text.
    string encrypted_text = encrypt(text, shift);

    // Call the decrypt function to get the decrypted text.
    string decrypted_text = decrypt(encrypted_text, shift);

    // Display the encrypted and decrypted texts.
    cout << "\nEncrypted Text: " << encrypted_text << endl;
    cout << "Decrypted Text: " << decrypted_text << endl;

    return 0;
}
