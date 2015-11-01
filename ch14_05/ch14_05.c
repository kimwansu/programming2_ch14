#include <stdio.h>
#include <string.h>

void sort_strings(char *s[], int size);

int main()
{
    int i;
    char *s[3] = {
        "mycopy",
        "src",
        "dst",
    };

    sort_strings(s, 3);
    for (i = 0; i < 3; i++)
    {
        puts(s[i]);
    }
    
    return 0;
}

void sort_strings(char *s[], int size)
{
    int i;
    int j;
    int minIdx = 0;
    char* tmp;

    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (strcmp(s[j], s[minIdx]) < 0)
            {
                minIdx = j;
            }
        }

        tmp = s[i];
        s[i] = s[minIdx];
        s[minIdx] = tmp;
    }
}