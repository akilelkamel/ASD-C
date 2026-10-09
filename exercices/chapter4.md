# Chapitre 4 — Les sous programmes

## Exercices d’application

------------------------------------------------------------------------

## Exercice 1 — Triangle rectangle

### Enoncé

Ecrire en C une fonction **triangle** qui permet de vérifier si les 3 nombres `a`, `b` et `c` peuvent être les mesures des côtés d'un triangle rectangle.

**Remarque :** D'après le théorème de Pythagore,

Si `a`, `b` et `c` sont les mesures des côtés d'un triangle rectangle,

Alors `a² = b² + c²` ou `b² = a² + c²` ou `c² = a² + b²`.

### Correction

``` c
#include <stdio.h>

int triangle(int a, int b, int c)
{
    if (a * a == b * b + c * c ||
        b * b == a * a + c * c ||
        c * c == a * a + b * b)
        return 1;
    else
        return 0;
}

void main()
{
    int a, b, c;

    printf("Donner les trois côtés : ");
    scanf("%d%d%d", &a, &b, &c);

    if (triangle(a, b, c))
        printf("Les trois nombres peuvent etre les cotes d'un triangle rectangle.\n");
    else
        printf("Les trois nombres ne peuvent pas etre les cotes d'un triangle rectangle.\n");
}
```

------------------------------------------------------------------------

## Exercice 2 — Somme double

### Enoncé

Ecrire une fonction qui étant donné un entier **n**, renvoie la somme suivante :

$$\sum_{i=1}^{n}\sum_{j=1}^{i}(i+j)$$

### Correction

``` c
#include <stdio.h>

int somme(int n)
{
    int i, j;
    int s = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            s = s + i + j;
        }
    }

    return s;
}

void main()
{
    int n;

    printf("Donner n : ");
    scanf("%d", &n);

    printf("La somme est : %d\n", somme(n));
}
```

------------------------------------------------------------------------

## Exercice 3 — Nombres amis

### Enoncé

Ecrire un programme en C qui lit deux nombres naturels non nuls `n` et `m` et qui détermine s’ils sont amis.

Deux nombres entiers `n` et `m` sont qualifiés d'amis, si la somme des diviseurs de `n` est égale à `m` et la somme des diviseurs de `m` est égale à `n` (on ne compte pas comme diviseur le nombre lui-même et 1).

Proposer une solution modulaire.

### Correction

``` c
#include <stdio.h>

int sommeDiviseurs(int n)
{
    int i;
    int somme = 0;

    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            somme = somme + i;
    }

    return somme;
}

int sontAmis(int n, int m)
{
    return sommeDiviseurs(n) == m &&
           sommeDiviseurs(m) == n;
}

void main()
{
    int n, m;

    printf("Donner n et m : ");
    scanf("%d%d", &n, &m);

    if (sontAmis(n, m))
        printf("%d et %d sont amis.\n", n, m);
    else
        printf("%d et %d ne sont pas amis.\n", n, m);
}
```

------------------------------------------------------------------------

## Exercice 4 — Nombre dont le carré se termine par le même chiffre

### Enoncé

Réaliser en C une fonction qui cherche le premier nombre entier naturel dont le carré se termine par `n` fois le même chiffre.

**Exemple :** pour `n = 2`, le résultat est `10` car `100` se termine par 2 fois le même chiffre.

### Correction

``` c
#include <stdio.h>

int memeChiffre(int nombre, int n)
{
    int chiffre;
    int i;

    chiffre = nombre % 10;

    for (i = 1; i < n; i++)
    {
        nombre = nombre / 10;

        if (nombre % 10 != chiffre)
            return 0;
    }

    return 1;
}

int premierNombre(int n)
{
    int i = 1;

    while (!memeChiffre(i * i, n))
        i++;

    return i;
}

void main()
{
    int n;
    int resultat;

    printf("Donner n : ");
    scanf("%d", &n);

    resultat = premierNombre(n);

    printf("Le premier nombre est : %d\n", resultat);
    printf("Son carre est : %d\n", resultat * resultat);
}
```

------------------------------------------------------------------------

## Exercice 5 — Calculatrice générique

### Enoncé

Cet exercice a pour objectif de concevoir une calculatrice **générique** permettant la réalisation de diverses opérations mathématiques en fonction de l'opération sélectionnée par l'utilisateur.

Pour ce faire, on vous demande de :

1.  Implémenter les fonctions suivantes :

    - **addition** : accepte un entier comme premier opérande, tandis que le second opérande sera saisi dans la fonction, puis retourne leur somme.
    - **soustraction** : prend un entier comme premier opérande (le second opérande sera saisi dans la fonction) et retourne leur différence.
    - **multiplication** : requiert un entier comme premier opérande (le second opérande sera saisi dans la fonction) et renvoie leur produit.
    - **division** : nécessite un entier comme premier opérande (le second opérande sera saisi dans la fonction) et fournit le quotient.

2.  Introduire une fonction **calculatrice** prenant un entier et une fonction d'opération en tant que paramètres. Cette fonction doit appliquer la fonction d'opération spécifiée aux deux entiers et retourner le résultat.

3.  Tester la calculatrice avec différentes opérations :

    - Solliciter l'utilisateur pour qu'il fournisse un premier entier et un caractère représentant l'opération (`+`, `-`, `*`, `/`).
    - Employer une structure conditionnelle `switch` pour appeler la fonction **calculatrice** avec les paramètres appropriés en fonction du caractère saisi.

### Correction

**Remarque** :

La correction proposée est partielle. Seule la fonction addition a été implémentée et prise en compte dans la fonction calculatrice. Le même principe peut être appliqué aux autres opérations (soustraction, multiplication et division).

``` c
#include <stdio.h>

int somme(int a)
{
    int b;

    printf("Donner le deuxieme entier: ");
    scanf("%d", &b);

    return a + b;
}

int calculatrice(int x, int (*fonction)(int))
{
    return fonction(x);
}

void main()
{
    int a;
    char op;

    printf("Donner le premier entier: ");
    scanf("%d", &a);

    printf("Donner l'operation souhaitee (+, -, *, /): ");
    scanf(" %c", &op);

    switch (op)
    {
        case '+':
            printf("Le resultat = %d", calculatrice(a, somme));
            break;

        default:
            printf("Merci de verifier l'operation introduite.");
    }
}
```
