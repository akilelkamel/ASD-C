#include <stdio.h>

void main()
{
    int i,n,x;
    creerpile();
    printf("Donner le nombre d'éléments de la pile (n) :");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Donner un entier : ");
        scanf("%d", &x);
        empiler(x);
    }
    printf("Contenu de P: \n");
    while(!pile_vide())
    {
        printf("%d\t", dernier());
        depiler();
    }
}
