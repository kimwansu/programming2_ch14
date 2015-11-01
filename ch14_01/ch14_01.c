#include <stdio.h>

void set_proverb(char** q, int n);

int main()
{
    char* s = NULL;
    set_proverb(&s, 2);
    printf("selected proverb = %s\n", s);

    return 0;
}

void set_proverb(char** q, int n)
{
    // 영어 속담 출처
    // http://blog.koreadaily.com/view/myhome.html?fod_style=B&med_usrid=koyou08&cid=536764&fod_no=9
    static char *array[10] = {
        "Happiness is good for body, but it is pain that develops the powers of the mind",
        "The more, the better",
        "A friend in need is a friend indeed",
        "Theres no place like home",
        "Easy come, easy go",
        "Do as you would be done by",
        "Every dog has his day",
        "Cut your coat according to your cloth",
        "A good medicine tastes bitter",
        "Tastes differ",
    };

    if (n >= 10 || n < 0)
        return;

    *q = array[n];
}