#include <stdio.h>
#include <string.h>

int main() {
    int i, j, keylen, msglen;
    char input[100], key[30], temp[30], quot[100], key1[30], rem[30];
    printf("Enter Data: ");
    scanf("%s", input);
    printf("Enter Key: ");
    scanf("%s", key);

    keylen = strlen(key);
    msglen = strlen(input);

    strcpy(key1, key);

    for (i = 0; i < keylen - 1; i++) {
        input[msglen + i] = '0';
    }
    input[msglen + keylen - 1] = '\0';
    strncpy(temp, input, keylen);
    temp[keylen] = '\0';
    for (i = 0; i < msglen; i++) {
        quot[i] = temp[0]; 

        if (quot[i] == '0') {
            for (j = 0; j < keylen; j++) {
                key[j] = '0'; 
            }
        } else {
            for (j = 0; j < keylen; j++) {
                key[j] = key1[j]; 
            }
        }
        for (j = 1; j < keylen; j++) {
            temp[j - 1] = (temp[j] == key[j]) ? '0' : '1';
        }
        if (i + keylen < msglen + keylen - 1) {
            temp[keylen - 1] = input[i + keylen];
        }
    }
    strncpy(rem, temp, keylen - 1);
    rem[keylen - 1] = '\0';

    quot[msglen] = '\0';
    printf("Quotient : %s\n", quot);
    printf("Remainder : %s\n", rem);

    return 0;
}