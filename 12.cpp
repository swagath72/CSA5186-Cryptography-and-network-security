#include <stdio.h>
#include <string.h>

#define MOD 26

int main() {
    char plaintext[] = "meetmeattheusualplaceattenratherthanoclock";
    char ciphertext[100], decrypted[100];
    int key[2][2] = {{9, 4}, {5, 7}};
    int invKey[2][2];
    int i, j, k, len;

    // Step 1: Pad plaintext if necessary
    len = strlen(plaintext);
    if (len % 2 != 0) {
        plaintext[len] = 'x'; // Add padding
        plaintext[len + 1] = '\0';
        len++;
    }

    // Step 2: Encrypt the plaintext
    for (i = 0; i < len; i += 2) {
        int block[2] = {plaintext[i] - 'a', plaintext[i + 1] - 'a'};
        ciphertext[i] = ((key[0][0] * block[0] + key[0][1] * block[1]) % MOD) + 'a';
        ciphertext[i + 1] = ((key[1][0] * block[0] + key[1][1] * block[1]) % MOD) + 'a';
    }
    ciphertext[len] = '\0';
    printf("Ciphertext: %s\n", ciphertext);

    // Step 3: Compute determinant of the key matrix
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD;
    if (det < 0) det += MOD;

    // Step 4: Compute modular inverse of determinant
    int invDet = -1;
    for (i = 1; i < MOD; i++) {
        if ((det * i) % MOD == 1) {
            invDet = i;
            break;
        }
    }
    if (invDet == -1) {
        printf("Inverse determinant does not exist.\n");
        return 1;
    }

    // Step 5: Compute inverse key matrix
    invKey[0][0] = (key[1][1] * invDet) % MOD;
    invKey[0][1] = (-key[0][1] * invDet) % MOD;
    invKey[1][0] = (-key[1][0] * invDet) % MOD;
    invKey[1][1] = (key[0][0] * invDet) % MOD;

    // Ensure all values are positive
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (invKey[i][j] < 0) invKey[i][j] += MOD;
        }
    }

    // Step 6: Decrypt the ciphertext
    for (i = 0; i < len; i += 2) {
        int block[2] = {ciphertext[i] - 'a', ciphertext[i + 1] - 'a'};
        decrypted[i] = ((invKey[0][0] * block[0] + invKey[0][1] * block[1]) % MOD) + 'a';
        decrypted[i + 1] = ((invKey[1][0] * block[0] + invKey[1][1] * block[1]) % MOD) + 'a';
    }
    decrypted[len] = '\0';
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
