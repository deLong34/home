#include <stdio.h>
#include <stdlib.h>
//кодируем символ
char simbolCrypt(char letter, int key) {
    letter += key;
    return letter;
}
//декодируем символ
char simbolDecrypt(char letter, int key) {
    letter -= key;
    return letter;
}
//функция фифрования Цезаря
char* cesarCrypt(char* str, int key) {
    int i = 0;
    while (str[i] != NULL) {
        char letter = str[i];
        str[i] = simbolCrypt(letter, key);
        i++;
    }
    return str;
}
//функция дешифровки Цезаря
char* cesarDeCrypt(char* str, int key) {
    int i = 0;
    while (str[i] != NULL) {
        char letter = str[i];
        str[i] = simbolDecrypt(letter, key);
        i++;
    }
    return str;
}

////////////////////////2
//функция шифровки перестановкой
char* pernCrypt(char* str, int col) {
    int len = strlen(str);
    int row;
    if (len % col == 0)
        row = len / col;
    else row = len / col + 1;
    char* cod = str;
    char arr[row][col];
    int k = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = str[k];
                k++;
            }
        }
    k = 0;
    for (int j = 0; j < col; j++) {
        for ( int i = 0; i < row; i++) {
            cod[k] = arr[i][j];
            k++;
        }
    }
    return cod;
}

//функция дешифровки перестановкой
char* pernDeCrypt(char* str, int col) {
    int len = strlen(str);
    int row;
    if (len % col == 0)
        row = len / col;
    else row = len / col + 1;
    char* cod = str;
    char arr[row][col];
    int k = 0;
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                arr[i][j] = str[k];
                k++;
            }
        }
    k = 0;
    for (int i = 0; i < row; i++) {
        for ( int j = 0; j < col; j++) {
            cod[k] = arr[i][j];
            k++;
        }
    }
    return cod;
}

int main() {

    char str[25] = "Very Secret String !";
    printf("%s", str);
    char* txt = str;
    printf("\n%s", cesarCrypt(txt, 3));
    printf("\n%s", cesarDeCrypt(txt, 3));
///////////////////2
    printf("\n%s", pernCrypt(txt, 4));
    printf("\n%s", pernDeCrypt(txt, 4));
    return 0;
}
