#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

struct symtab
{
    char label[20];
    int addr;
} sy[50];

void insert();
int search(char *);
void display();
void modify();

int main()
{
    int ch;
    char lab[10];
    do
    {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Modify\n5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the label: ");
            scanf("%s", lab);
            if (search(lab))
                printf("Label found.\n");
            else
                printf("Label not found.\n");
            break;
        case 4:
            modify();
            break;
        case 5:
            exit(0);
            break;
        }
    } while (ch < 5);

    return 0;
}

void insert()
{
    int val;
    char lab[10];

    printf("Enter the label: ");
    scanf("%s", lab);

    val = search(lab);

    if (val == 1)
    {
        printf("Duplicate symbol.\n");
    }
    else
    {
        strcpy(sy[cnt].label, lab);
        printf("Enter the address: ");
        scanf("%d", &sy[cnt].addr);
        cnt++;
    }
}

int search(char *s)
{
    for (int i = 0; i < cnt; i++)
    {
        if (strcmp(sy[i].label, s) == 0)
        {
            return 1; // Found
        }
    }
    return 0; // Not found
}

void modify()
{
    int val, ad;
    char lab[10];

    printf("Enter the label: ");
    scanf("%s", lab);

    val = search(lab);

    if (val == 0)
    {
        printf("No such symbol.\n");
    }
    else
    {
        printf("Label found.\n");
        printf("Enter the new address: ");
        scanf("%d", &ad);

        for (int i = 0; i < cnt; i++)
        {
            if (strcmp(sy[i].label, lab) == 0)
            {
                sy[i].addr = ad;
            }
        }
    }
}

void display()
{
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\t%d\n", sy[i].label, sy[i].addr);
    }
}