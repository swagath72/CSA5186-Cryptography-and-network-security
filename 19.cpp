#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

void encrypt_3des_cbc(const char *input, const char *key, const char *iv, char *output, int input_len) {
    DES_cblock des_key1, des_key2, des_key3, des_iv;
    DES_key_schedule ks1, ks2, ks3;

    // Split the key into 3 parts
    memcpy(des_key1, key, 8);
    memcpy(des_key2, key + 8, 8);
    memcpy(des_key3, key + 16, 8);

    // Set up key schedules
    DES_set_key_unchecked(&des_key1, &ks1);
    DES_set_key_unchecked(&des_key2, &ks2);
    DES_set_key_unchecked(&des_key3, &ks3);

    // Set up the IV
    memcpy(des_iv, iv, 8);

    // Perform encryption
    DES_ede3_cbc_encrypt((const unsigned char *)input, (unsigned char *)output, input_len, &ks1, &ks2, &ks3, &des_iv, DES_ENCRYPT);
}

int main() {
    // Input plaintext
    const char *input = "This is a test.";  // Example plaintext
    int input_len = strlen(input);

    // Ensure input length is a multiple of 8 by padding with null bytes
    int padded_len = ((input_len + 7) / 8) * 8;
    char padded_input[100] = {0};
    memcpy(padded_input, input, input_len);

    // Key (24 bytes for 3DES)
    const char *key = "12345678abcdefghABCDEFGH";  // 24-byte key

    // IV (8 bytes)
    const char *iv = "12345678";  // 8-byte IV

    // Output buffer
    char output[100] = {0};

    // Encrypt
    encrypt_3des_cbc(padded_input, key, iv, output, padded_len);

    // Print encrypted text in hexadecimal format
    printf("Encrypted text (hex): ");
    for (int i = 0; i < padded_len; i++) {
        printf("%02x ", (unsigned char)output[i]);
    }
    printf("\n");

    return 0;
}
