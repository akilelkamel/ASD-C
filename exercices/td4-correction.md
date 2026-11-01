# Correction du TD 4 — La récursivité


------------------------------------------------------------------------

## Exercice 1 : Récursivité croisée ou mutuelle


```c
#include <stdio.h>
int u(int n);
int v(int n);

int u(int n)
{
    if (n == 0)
        return 3;
    else
        return 2 * v(n - 1) + 1;
}

int u_ternaire (int n)
{
    return (n == 0) ? 3 : 2 * v(n - 1) + 1;
}

int v(int n)
{
    if (n == 0)
        return 1;
    else
    {
        if (n == 1)
            return 2 * u (0) + 3;
        else
            return u(n - 1) + 3 * v(n - 2);
    }
}

void main ()
{
    int N;
    do
    {
        printf (" Donner N (0 <= N <= 25) : ");
        scanf ("%d", &N);
    }
    while (N < 0 || N > 25);

    printf ("u(%d) = %d\n", N, u(N));
    printf ("v(%d) = %d\n", N, v(N));
}

```

------------------------------------------------------------------------

## Exercice 2 : Suite récurrente arithmético-géométrique


```c
#include <stdio.h>
unsigned suite_non_term (unsigned n)
{
    if (n == 0)
        return 1;
    else
        return 3*suite_non_term(n-1) + 2*n - 1;
}

unsigned suite_non_term_ternaire (unsigned n)
{
    return (n == 0) ? 1 :
           3*suite_non_term_ternaire (n-1) + 2*n - 1;
}
unsigned suite_term (unsigned n, unsigned w, unsigned i)
{
    if (n == 0)
        return w;
    else
        return suite_term (n-1, 3*w + 2*i - 1, i+1);
}

unsigned suite_term_ternaire(unsigned n, unsigned w, 	unsigned i)
{
    return (n == 0) ? w : suite_term_ternaire (n-1,
            3*w + 2*i - 1, i+1);
}
void main ()
{
    unsigned n;
    printf (" Donner n (0 <= n <= 25) : ");
    scanf ("%u", &n);

    printf("Recursif non terminal : W_%u = %u\n", n, suite_non_term (n));
    printf("Recursif terminal : W_%u = %u\n", n, suite_term (n, 1,1));
}


```


### Version non terminale

- Pour `suite_non_term(3)`, les appels descendent jusqu’à `suite_non_term(0)`. 
- Ensuite, les calculs s’effectuent au retour : `S(0)=1`, `S(1)=4`, `S(2)=15`, `S(3)=50` 


### Version terminale

- L’appel initial est : `suite_term(3, 1, 1);`


| Appel   | n | w  | i |
|---------|---|----|---|
| Initial | 3 | 1  | 1 |
| Etape 1 | 2 | 4  | 2 |
| Etape 2 | 1 | 15 | 3 |
| Etape 3 | 0 | 50 | 4 |


Lorsque `n == 0`, la procédure renvoie directement `w`, soit `50`.


La transformation consiste à remplacer les calculs différés par une mise à jour de l’accumulateur `w`. Ainsi, l’appel récursif devient la dernière opération de la procédure: **c’est la récursivité terminale**.


![](imgs/recursivite_non_terminale_vers_terminale.gif)

------------------------------------------------------------------------

## Exercice 3: Approximation de π/4 par série alternée


```c
#include <stdio.h>

int saisien ()
{
    int n;
    printf (" Donner n (1 <= n <= 100) : ");
    scanf ("%d", &n);
    if (n < 1 || n > 100)
    {
        printf("Valeur incorrecte. Recommencez .\n");
        return saisien ();
    }
    else
        return n;
}

double somme_recursive(int n)
{
    double terme, signe ;
    if (n == 1)
        return 1.0;
    else
    {
        if (n % 2 == 1)
            signe = 1.0;
        else
            signe = -1.0;
        terme = signe / (2.0 * n - 1.0) ;
        return somme_recursive (n - 1) + terme ;
    }
}

double somme_recursive_ternaire (int n)
{
    return (n == 1) ? 1.0 : somme_recursive_ternaire (n-1) + ((n % 2 == 1) ? 1.0 : -1.0) / (2.0 * n - 1.0);
}

double somme_recursive_terminale_aux (int n, int k, double acc)
{
    double terme, signe ;
    if (k > n)
        return acc;
    else
    {
        if (k % 2 == 1)
            signe = 1.0;
        else
            signe = -1.0;
        terme = signe / (2.0 * k - 1.0) ;
        return somme_recursive_terminale_aux (n, k+1, acc + terme);
    }
}

double somme_recursive_terminale (int n)
{
    return somme_recursive_terminale_aux (n, 1, 0.0) ;
}

void main ()
{
    int n = saisien ();
    double s_nt = somme_recursive (n);
    double s_t = somme_recursive_terminale (n);

    printf("S_%d (non terminale) = %lf (pi ~ %lf)\n", n, s_nt, 4.0 * s_nt);
    printf ("S_%d (terminale) = %lf (pi ~ %lf)\n", n, s_t, 4.0 * s_t);
}

```

------------------------------------------------------------------------


## Exercice 4 : Conversion binaire vers décimal


```c
#include <stdio.h>
#include <math.h>

int saisie ()
{
    int n;
    printf("Donner un entier binaire (> 0) : ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Erreur: le nombre doit etre strictement positif.\n");
        return saisie();
    }
    else
        return n;
}

int verif(int x)
{
    if (x == 0)
        return 1;
    else
    {
        if (x % 10 != 0 && x % 10 != 1)
            return 0;
        else
            return verif(x / 10);
    }
}

int binaire_non_term(int x, int poids)
{
    if (x == 0)
        return 0;
    else
        return (x%10)*(int)pow(2, poids) + binaire_non_term(x/10, poids+1);
}

int binaire_term (int x, int poids, int acc)
{
    if (x == 0)
        return acc;
    else
        return binaire_term (x/10, poids * 2, acc + (x % 10) * poids);
}

void main()
{
    int nb = saisie ();
    if( verif (nb))
    {
        printf ("%d (base 2) = %d (base 10) [Non terminale]\n", nb, binaire_non_term (nb, 0));

        printf ("%d (base 2) = %d (base 10) [Terminale]\n", nb, binaire_term(nb, 1, 0));
    }
    else
        printf ("Conversion impossible: %d n'est pas un nombre binaire valide.\n", nb);
}

```

------------------------------------------------------------------------


## Exercice 6 : Minimum et occurrences dans un tableau


```c
#include <stdio.h>

int minimum_NT(int T[], int N)
{
    int min;
    if (N == 1)
        return T [0];
    else
    {
        min = minimum_NT(T, N-1);
        if(T[N-1] < min)
            return T[N-1];
        else
            return min;
    }
}

int minimum_T (int T[], int N, int min_acc)
{
    if (N == 0)
        return min_acc;
    else
    {
        if (T[N-1] < min_acc)
            return minimum_T (T, N-1, T[N-1]);
        else
            return minimum_T (T, N-1, min_acc );
    }
}

int compter_occurrences_T(int T[], int N, int val, int acc)
{
    if (N == 0)
        return acc;
    else
    {
        if (T[N-1] == val)
            return compter_occurrences_T(T, N-1, val, acc+1);
        else
            return compter_occurrences_T(T, N-1, val, acc);
    }
}

void main ()
{
    int T[] = {14, 5, 23, 5, 89, 5, 42, 7};
    int N = 8;
    int min_val ;
    printf("Tableau: [14, 5, 23, 5, 89, 5, 42, 7]\n");
    min_val = minimum_T(T, N, T[0]) ;
    printf("Valeur minimale (NT): %d\n",
           minimum_NT (T, N));
    printf("Valeur minimale (T) : %d\n", min_val);
    printf("Nombre d'occurrences du minimum : %d\n",
           compter_occurrences_T (T, N, min_val, 0));
}


```

------------------------------------------------------------------------
