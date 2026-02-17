#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 1000

void reverse(char *str, int len) {
    int i = 0, j = len - 1;
    while (i < j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");

    FILE *fout = fopen(argv[2], "w");

    char word[MAX_WORD];
    while (fscanf(fin, "%s", word) != EOF) {
        int len = strlen(word);
        int split = len;

        for (int i = 0; i < len; i++) {
            if (!isalnum(word[i])) {
                split = i;
                break;
            }
        }

        char reversed[MAX_WORD];
        strncpy(reversed, word, split);
        reversed[split] = '\0';
        reverse(reversed, strlen(reversed));

        fprintf(fout, "%s%s ", reversed, word + split);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
