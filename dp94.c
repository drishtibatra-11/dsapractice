#include <stdio.h>
#include <string.h>

#define SIZE 100
#define EMPTY -1

int table[SIZE];

void insert(int key, int m)
{
    int index = key % m;

    int i = 0;

    while(i < m)
    {
        int newIndex = (index + i * i) % m;

        if(table[newIndex] == EMPTY)
        {
            table[newIndex] = key;
            return;
        }

        i++;
    }
}

void search(int key, int m)
{
    int index = key % m;

    int i = 0;

    while(i < m)
    {
        int newIndex = (index + i * i) % m;

        if(table[newIndex] == key)
        {
            printf("FOUND\n");
            return;
        }

        if(table[newIndex] == EMPTY)
        {
            break;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main()
{
    int m, q;

    scanf("%d", &m);
    scanf("%d", &q);

    // initialize table
    for(int i = 0; i < m; i++)
    {
        table[i] = EMPTY;
    }

    while(q--)
    {
        char operation[10];
        int key;

        scanf("%s %d", operation, &key);

        if(strcmp(operation, "INSERT") == 0)
        {
            insert(key, m);
        }

        else if(strcmp(operation, "SEARCH") == 0)
        {
            search(key, m);
        }
    }

    return 0;
}