#include <stdio.h>
#include <string.h>

char input[100];
int i, l;

int E();
int EP();
int T();
int TP();
int F();

int main() {
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");
    printf("\nEnter the string to be checked:");
    fgets(input, sizeof(input), stdin);

    l = strlen(input);
    i = 0;

    if (E() && i == l - 1) {
        printf("\nString is accepted\n");
    } else {
        printf("\nString is not accepted\n");
    }

    return 0;
}

int E() {
    if (T()) {
        if (EP()) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int EP() {
    if (input[i] == '+') {
        i++;
        if (T()) {
            if (EP()) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

int T() {
    if (F()) {
        if (TP()) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int TP() {
    if (input[i] == '*') {
        i++;
        if (F()) {
            if (TP()) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

int F() {
    if (input[i] == '(') {
        i++;
        if (E()) {
            if (input[i] == ')') {
                i++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
        i++;
        return 1;
    } else {
        return 0;
    }
}