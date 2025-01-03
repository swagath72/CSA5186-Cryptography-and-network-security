#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BLOCK_SIZE 8 
void encrypt_ecb(const char *plaintext, char *ciphertext, const char *key, int num_blocks);
void decrypt_ecb(const char *ciphertext, char *plaintext, const char *key, int num_blocks);

void encrypt_cbc(const char *plaintext, char *ciphertext, const char *key, const char *iv, int num_blocks);
void decrypt_cbc(const char *ciphertext, char *plaintext, const char *key, const char *iv, int num_blocks);

void encrypt_cfb(const char *plaintext, char *ciphertext, const char *key, const char *iv, int num_blocks);
void decrypt_cfb(const char *ciphertext, char *plaintext, const char *key, const char *iv, int num_blocks);

int main() {
    const char key[] = "SECRET_K";
    const char iv[] = "INITIAL_";
    const char plaintext[] = "HELLO WO";
    char ciphertext[100];
    char decrypted[100];

    int num_blocks = strlen(plaintext) / BLOCK_SIZE;
    int padding_bits = BLOCK_SIZE - (strlen(plaintext) % BLOCK_SIZE);

    char padded_plaintext[100];
    strcpy(padded_plaintext, plaintext);
    for (int i = 0; i < padding_bits; i++) {
        padded_plaintext[strlen(plaintext) + i] = (i == 0) ? 0x80 : 0x00;
    }

    printf("Original Plaintext: %s\n", plaintext);

    encrypt_ecb(padded_plaintext, ciphertext, key, num_blocks);
    decrypt_ecb(ciphertext, decrypted, key, num_blocks);

    printf("ECB Mode:\n");
    printf("Encrypted Ciphertext: %s\n", ciphertext);
    printf("Decrypted Plaintext: %s\n", decrypted);

    encrypt_cbc(padded_plaintext, ciphertext, key, iv, num_blocks);
    decrypt_cbc(ciphertext, decrypted, key, iv, num_blocks);

    printf("CBC Mode:\n");
    printf("Encrypted Ciphertext: %s\n", ciphertext);
    printf("Decrypted Plaintext: %s\n", decrypted);

    encrypt_cfb(padded_plaintext, ciphertext, key, iv, num_blocks);
    decrypt_cfb(ciphertext, decrypted, key, iv, num_blocks);

    printf("CFB Mode:\n");
    printf("Encrypted Ciphertext: %s\n", ciphertext);
    printf("Decrypted Plaintext: %s\n", decrypted);

    return 0;
}