// CS50の課題にあったマリオのブロックを作成するコード
#include <stdio.h>

void print_spaces(int height, int counter)
{
    for (int i = 0; i < height - counter; i++)
    {
        printf(" ");
    }
}

void print_left_hashes(int height, int counter)
{
    for (int i = 0; i < counter; i++)
    {
        printf("#");
    }
}

void print_gap(void)
{
    printf("  ");
}

void print_right_hashes(int height, int counter)
{
    for (int i = 0; i < counter; i++)
    {
        printf("#");
    }
}

int main(void)
{
    int height;

    do
    {
        scanf("%d", height);
    } while (!(0 < height && height <= 8));

    for (int counter = 1; counter <= height; counter++)
    {
        print_spaces(height, counter);
        print_left_hashes(height, counter);
        print_gap();
        print_right_hashes(height, counter);
        printf("\n");
    }
}