#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD 20

void reverse_and_write(FILE *out, char *word, int len) {
    int i;
    if (len > 0 && !isalnum(word[len - 1])) {
        for (i = len - 2; i >= 0; i--) {
            fputc(word[i], out);
        }
        fputc(word[len - 1], out);
    } else {
        for (i = len - 1; i >= 0; i--) {
            fputc(word[i], out);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        perror("Error opening input file");
        return 1;
    }

    FILE *out = fopen(argv[2], "w");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return 1;
    }

    char word[MAX_WORD];
    int ch, index = 0;

    while ((ch = fgetc(in)) != EOF) {
        if (!isspace(ch)) {
            if (index < MAX_WORD - 1) {
                word[index++] = ch;
            }
        } else {
            if (index > 0) {
                reverse_and_write(out, word, index);
                index = 0;
            }
            fputc(ch, out);
        }
    }

    if (index > 0) {
        reverse_and_write(out, word, index);
    }

    fclose(in);
    fclose(out);

    return 0;
}
