#include <stdio.h>
#include <string.h>
void encrypt(const char *plaintext, const
int *key, char *ciphertext) {
 int plaintextLen = strlen(plaintext);
 int i;

 for (i = 0; i < plaintextLen; i++) {
 ciphertext[i] = (plaintext[i] - 'A' +
key[i]) % 26 + 'A';
 }
 ciphertext[plaintextLen] = '\0';
}
void decrypt(const char *ciphertext, const
int *key, char *plaintext) {
 int ciphertextLen = strlen(ciphertext),i;

 for (i = 0; i < ciphertextLen; i++) {
 plaintext[i] = (ciphertext[i] - 'A' - key[i]
+ 26) % 26 + 'A';
 }
 plaintext[ciphertextLen] = '\0';
}
int main() {
 const char *plaintext =
"SENDMOREMONEY";
 int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11,
11, 2, 8, 9};
 char ciphertext[strlen(plaintext) + 1];

 encrypt(plaintext, key, ciphertext);
 printf("Ciphertext: %s\n", ciphertext);
 char decryptedText[strlen(plaintext) +
1];
 decrypt(ciphertext, key, decryptedText);
 printf("Decrypted Text: %s\n",
decryptedText);

 return 0;
}