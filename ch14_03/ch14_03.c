#include <stdio.h>

void pr_str_array(char** dp, int n);

int main()
{
    char *str_array[] = {
        "Lorem ipsum dolor sit amet, ",
        "consectetur adipiscing elit. ",
        "Donec a diam lectus.Sed sit amet ipsum mauris.",
        "Maecenas congue ligula ac quam viverra nec consectetur ante hendrerit.",
        "Donec et mollis dolor.",
        "Praesent et diam eget libero egestas mattis sit amet vitae augue.",
    };

    pr_str_array(str_array, 6);

    return 0;
}

void pr_str_array(char** dp, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        puts(dp[i]);
    }
}