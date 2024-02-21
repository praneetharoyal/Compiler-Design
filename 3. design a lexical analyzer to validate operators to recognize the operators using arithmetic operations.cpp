#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]) {
    char keywords[32][10] = {"main", "auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef",
                             "unsigned", "void", "printf", "while"};
    int i, flag = 0;

    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }

    return flag;
}

int main() {
    char ch, buffer[15];
    const char operators[] = "+-*/%=";

    int j = 0;

    printf("Enter your input:\n");

    while ((ch = getchar()) != EOF && ch != '\n') {
        for (int i = 0; i < 6; ++i) {
            if (ch == operators[i]) {
                printf("%c is an operator\n", ch);
            }
        }

        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer)) {
                printf("%s is a keyword\n", buffer);
            } else {
                printf("%s is an identifier\n", buffer);
            }
        }
    }

    return 0;
}