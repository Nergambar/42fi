#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
    int i;
    int ri;
    int swap;

    i = 0;
    ri = size - 1;
    while (i < ri)
    {
        swap = tab[i];
        tab[i] = tab[ri];
        tab[ri] = swap;
        i++;
        ri--;
    }
}

/*int main(void)
{
    int size = 5;
    int tab[] = {1, 2, 3, 4, 5};
    ft_rev_int_tab(tab, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}*/
