# Chapitre 3 — Les instructions de contrôle

## Exercices d’application

---

## Exercice 1 — Nombres palindromes

### Enoncé

Un nombre est dit **palindrome** s’il est écrit de la même manière de gauche à droite ou de droite à gauche.

**Exemples :** `101`, `22`, `3663`, `10801`, etc.

Ecrire un programme C permettant de déterminer et d'afficher tous les nombres palindromes compris dans l'intervalle `[100..9999]`.

### Correction

```c
#include <stdio.h>

void main()
{
    int n, temp, inverse, chiffre;

    printf("Nombres palindromes compris entre 100 et 9999 :\n");

    for (n = 100; n <= 9999; n++)
    {
        temp = n;
        inverse = 0;

        while (temp != 0)
        {
            chiffre = temp % 10;
            inverse = inverse * 10 + chiffre;
            temp = temp / 10;
        }

        if (n == inverse)
            printf("%d ", n);
    }

}
```

---

## Exercice 2 — Nombres parfaits

### Enoncé

Réaliser un programme en C qui affiche la suite de tous les nombres parfaits inférieurs ou égaux à un nombre naturel non nul donné, noté `n`.

Un nombre est dit **parfait** s'il est égal à la somme de ses diviseurs autres que lui-même.

**Exemple :**

`28 = 1 + 2 + 4 + 7 + 14`

Voici la liste des nombres parfaits inférieurs à `10000` :

`6, 28, 496, 8128`

### Correction

```c
#include <stdio.h>

void main()
{
    int n, i, j, somme;

    printf("Donner un entier naturel non nul : ");
    scanf("%d", &n);

    printf("Nombres parfaits inferieurs ou egaux a %d :\n", n);

    for (i = 2; i <= n; i++)
    {
        somme = 1;

        /* Calcul de la somme des diviseurs propres de i */
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
                somme = somme + j;
        }

        /* Test si i est parfait */
        if (somme == i)
            printf("%d ", i);
    }

}
```

---

## Exercice 3 — Nombres de Fibonacci

### Enoncé

Les nombres de Fibonacci sont donnés par la récurrence :

$F_n = F_{n-2} + F_{n-1}$

avec :

- $F_0 = 1$
- $F_1 = 1$

Ecrire un programme C qui affiche les **20 premiers nombres de Fibonacci**.

### Correction

```c
#include <stdio.h>

void main()
{
    int f0 = 1, f1 = 1, f2;
    int i;

    printf("Les 20 premiers nombres de Fibonacci :\n");

    printf("%d %d ", f0, f1);

    for (i = 3; i <= 20; i++)
    {
        f2 = f0 + f1;
        printf("%d ", f2);

        f0 = f1;
        f1 = f2;
    }

}
```

---

## Exercice 4 — Nombres frères

### Enoncé

Deux entiers `N1` et `N2` sont dits **frères** si chaque chiffre de `N1` apparaît au moins une fois dans `N2` et inversement.

### Exemples

Si :

```text
N1 = 1164
N2 = 614
```

le programme affichera :

```text
N1 et N2 sont frères
```

Si :

```text
N1 = 405
N2 = 554
```

le programme affichera :

```text
N1 et N2 ne sont pas frères
```

Ecrire un programme C qui saisit deux entiers `N1` et `N2`, vérifie et affiche s'ils sont frères ou non.

### Correction 1 — Vérification des chiffres 0 à 9

La première solution vérifie, pour chacun des dix chiffres, s'il apparaît dans `N1` et dans `N2`.

```c
#include <stdio.h>

void main()
{
    int N1, N2;
    int n1, n2;
    int chiffre;
    int present1, present2;
    int freres = 1;

    printf("Donner N1 : ");
    scanf("%d", &N1);

    printf("Donner N2 : ");
    scanf("%d", &N2);

    /* Vérification des 10 chiffres */
    for (chiffre = 0; chiffre <= 9; chiffre++)
    {
        n1 = N1;
        n2 = N2;
        present1 = 0;
        present2 = 0;

        /* Recherche du chiffre dans N1 */
        if (n1 == 0)
        {
            if (chiffre == 0)
                present1 = 1;
        }
        else
        {
            while (n1 != 0)
            {
                if (n1 % 10 == chiffre)
                {
                    present1 = 1;
                    break;
                }

                n1 = n1 / 10;
            }
        }

        /* Recherche du chiffre dans N2 */
        if (n2 == 0)
        {
            if (chiffre == 0)
                present2 = 1;
        }
        else
        {
            while (n2 != 0)
            {
                if (n2 % 10 == chiffre)
                {
                    present2 = 1;
                    break;
                }

                n2 = n2 / 10;
            }
        }

        /* Le chiffre doit être présent dans les deux
           ou absent des deux */
        if (present1 != present2)
        {
            freres = 0;
            break;
        }
    }

    if (freres)
        printf("N1 et N2 sont freres.\n");
    else
        printf("N1 et N2 ne sont pas freres.\n");

}
```

---

### Correction 2 — Vérification dans les deux sens

La deuxième solution effectue deux vérifications :

1. chaque chiffre de `N1` doit apparaître dans `N2` ;
2. chaque chiffre de `N2` doit apparaître dans `N1`.

```c
#include <stdio.h>

void main()
{
    int N1, N2, n1, n2;
    int frere1 = 1, frere2 = 1;
    int existe, chiffre;

    printf("Donner N1 : ");
    scanf("%d", &N1);

    printf("Donner N2 : ");
    scanf("%d", &N2);

    /* Vérification : chaque chiffre de N1 apparaît dans N2 */
    n1 = N1;

    if (n1 == 0)
    {
        frere1 = (N2 == 0);
    }
    else
    {
        while (n1 != 0)
        {
            chiffre = n1 % 10;
            existe = 0;
            n2 = N2;

            if (n2 == 0)
            {
                existe = (chiffre == 0);
            }
            else
            {
                while (n2 != 0 && existe == 0)
                {
                    if (chiffre == n2 % 10)
                        existe = 1;

                    n2 /= 10;
                }
            }

            if (existe == 0)
            {
                frere1 = 0;
                break;
            }

            n1 /= 10;
        }
    }

    /* Vérification : chaque chiffre de N2 apparaît dans N1 */
    n2 = N2;

    if (n2 == 0)
    {
        frere2 = (N1 == 0);
    }
    else
    {
        while (n2 != 0)
        {
            chiffre = n2 % 10;
            existe = 0;
            n1 = N1;

            if (n1 == 0)
            {
                existe = (chiffre == 0);
            }
            else
            {
                while (n1 != 0 && existe == 0)
                {
                    if (chiffre == n1 % 10)
                        existe = 1;

                    n1 /= 10;
                }
            }

            if (existe == 0)
            {
                frere2 = 0;
                break;
            }

            n2 /= 10;
        }
    }

    if (frere1 && frere2)
        printf("%d et %d sont deux nombres freres\n", N1, N2);
    else
        printf("%d et %d NE sont PAS deux nombres freres\n", N1, N2);


}
```

### Comparaison des deux solutions

- **Solution 1 :** parcourt les chiffres `0` à `9` et vérifie leur présence dans les deux nombres.
- **Solution 2 :** parcourt directement les chiffres de `N1`, puis ceux de `N2`, et recherche leur présence dans l'autre nombre.
