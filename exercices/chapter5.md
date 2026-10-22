# Chapitre 5 — La récursivité

## Exercices d’application

------------------------------------------------------------------------

## Exercice 1 — Récursivité simple

### Enoncé

Soit la suite numérique \(U_n\) définie par :

\[
U_0 = 4
\]

et, pour \(n > 0\) :

\[
U_n = 2 \times U_{n-1} + 9
\]

Ecrire une fonction C qui calcule le terme \(U_n\), pour tout entier `n` passé en argument.

### Correction

```c
#include <stdio.h>

int terme(int n)
{
    if (n == 0)
        return 4;

    return 2 * terme(n - 1) + 9;
}

void main()
{
    int n;

    printf("Donner n : ");
    scanf("%d", &n);

    if (n < 0)
        printf("n doit etre positif ou nul.\n");
    else
        printf("U(%d) = %d\n", n, terme(n));
}
```

**Explication :** le cas de base est `n == 0`, pour lequel la fonction retourne `4`. Pour `n > 0`, elle calcule \(U_n\) à partir du terme précédent, \(U_{n-1}\).

------------------------------------------------------------------------

## Exercice 2 — Récursivité croisée

### Enoncé

Ecrire deux fonctions C qui calculent les termes d’indice `n` des suites entières \(U_n\) et \(V_n\), définies par :

\[
U_0 = 1 \qquad V_0 = 0
\]

Pour \(n > 0\) :

\[
U_n = V_{n-1} + 1
\qquad
V_n = 2 \times U_{n-1}
\]

### Correction

```c
#include <stdio.h>

int U(int n);
int V(int n);

int U(int n)
{
    if (n == 0)
        return 1;

    return V(n - 1) + 1;
}

int V(int n)
{
    if (n == 0)
        return 0;

    return 2 * U(n - 1);
}

void main()
{
    int n;

    printf("Donner n : ");
    scanf("%d", &n);

    if (n < 0)
        printf("n doit etre positif ou nul.\n");
    else
    {
        printf("U(%d) = %d\n", n, U(n));
        printf("V(%d) = %d\n", n, V(n));
    }
}
```

**Explication :** il s’agit d’une récursivité croisée : la fonction `U` appelle `V`, tandis que la fonction `V` appelle `U`. Les deux fonctions s’arrêtent lorsque `n == 0`.

------------------------------------------------------------------------

## Exercice 3 — Somme des carrés

### Enoncé

Ecrire une fonction récursive qui retourne la somme des carrés des `x` premiers entiers positifs si `x >= 0`, et `-1` sinon.

**Exemple :** pour `x = 4`, le résultat est :

\[
1^2 + 2^2 + 3^2 + 4^2 = 30
\]

### Correction

```c
#include <stdio.h>

int sommeCarres(int x)
{
    if (x < 0)
        return -1;

    if (x == 0)
        return 0;

    return x * x + sommeCarres(x - 1);
}

void main()
{
    int x;
    int resultat;

    printf("Donner x : ");
    scanf("%d", &x);

    resultat = sommeCarres(x);

    if (resultat == -1)
        printf("x doit etre positif ou nul.\n");
    else
        printf("La somme des carres est : %d\n", resultat);
}
```

**Explication :** si `x == 0`, aucun entier positif n’est à additionner : la somme vaut `0`. Sinon, on ajoute \(x^2\) à la somme des carrés des entiers de `1` à `x - 1`. Si `x` est négatif, la fonction retourne `-1`.

------------------------------------------------------------------------

## Exercice 4 — Récursivité terminale : vérifier une divisibilité

### Enoncé

Ecrire une fonction récursive terminale, basée sur des soustractions successives comme dans l’algorithme d’Euclide, qui vérifie si `a` est un diviseur de `b`.

On suppose que `a` est strictement positif et `b` est positif ou nul.

### Correction

```c
#include <stdio.h>

int estDiviseur(int a, int b)
{
    if (b == 0)
        return 1;

    if (b < a)
        return 0;

    return estDiviseur(a, b - a);
}

void main()
{
    int a, b;

    printf("Donner a (strictement positif) et b (positif ou nul) : ");
    scanf("%d%d", &a, &b);

    if (a <= 0 || b < 0)
        printf("Valeurs invalides.\n");
    else if (estDiviseur(a, b))
        printf("%d est un diviseur de %d.\n", a, b);
    else
        printf("%d n'est pas un diviseur de %d.\n", a, b);
}
```

**Explication :** on soustrait `a` à `b` tant que le résultat est supérieur ou égal à `a`. Si on atteint `0`, `b` est un multiple de `a` : `a` est donc un diviseur de `b`. Si le résultat devient strictement inférieur à `a` sans être nul, `a` n’est pas un diviseur de `b`.

**Exemple :** pour `a = 3` et `b = 12`, les appels successifs utilisent `12`, `9`, `6`, `3`, puis `0`. La fonction retourne `1` : `3` est un diviseur de `12`.

------------------------------------------------------------------------

## Exercice 5 — Calcul du PGCD

### Enoncé

On souhaite calculer le PGCD de deux nombres naturels non nuls `a` et `b` en utilisant l’algorithme d’Euclide.

1. Proposer une version itérative.
2. Proposer une version récursive.

La définition utilisée est :

\[
PGCD(a,b)=
\begin{cases}
a & \text{si } a=b\\
PGCD(a-b,b) & \text{si } a>b\\
PGCD(a,b-a) & \text{si } b>a
\end{cases}
\]

### Correction

#### 1. Version itérative

```c
#include <stdio.h>

int pgcdIteratif(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a;
}

void main()
{
    int a, b;

    printf("Donner deux entiers naturels non nuls : ");
    scanf("%d%d", &a, &b);

    if (a <= 0 || b <= 0)
        printf("Les deux nombres doivent etre strictement positifs.\n");
    else
        printf("PGCD = %d\n", pgcdIteratif(a, b));
}
```

#### 2. Version récursive

```c
#include <stdio.h>

int pgcdRecursif(int a, int b)
{
    if (a == b)
        return a;

    if (a > b)
        return pgcdRecursif(a - b, b);

    return pgcdRecursif(a, b - a);
}

void main()
{
    int a, b;

    printf("Donner deux entiers naturels non nuls : ");
    scanf("%d%d", &a, &b);

    if (a <= 0 || b <= 0)
        printf("Les deux nombres doivent etre strictement positifs.\n");
    else
        printf("PGCD = %d\n", pgcdRecursif(a, b));
}
```

**Explication :** dans les deux versions, on soustrait le plus petit nombre du plus grand jusqu’à obtenir deux valeurs égales. Cette valeur commune est le PGCD. La version itérative utilise une boucle, tandis que la version récursive s’appelle elle-même avec des arguments réduits.

------------------------------------------------------------------------

## Exercice 6 — Les tours de Hanoï

### Enoncé

On dispose de trois tours appelées `A`, `B` et `C`. La tour `A` contient `n` disques empilés par ordre de taille décroissante. Le but est de déplacer tous les disques de `A` vers `B`, dans le même ordre, en respectant les contraintes suivantes :

- On ne peut déplacer qu’un seul disque à la fois.
- On ne peut placer un disque que sur un disque plus grand ou sur une tour vide.

La procédure `deplacer(n, A, B, C)` doit déplacer `n` disques de la tour `A` vers la tour `B`, en utilisant éventuellement la tour `C`.

### Correction

```c
#include <stdio.h>

void deplacer(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("Deplacer un disque de %c vers %c\n", A, B);
    }
    else
    {
        /* 1. Deplacer n-1 disques de A vers C, en utilisant B. */
        deplacer(n - 1, A, C, B);

        /* 2. Deplacer le plus grand disque de A vers B. */
        printf("Deplacer un disque de %c vers %c\n", A, B);

        /* 3. Deplacer n-1 disques de C vers B, en utilisant A. */
        deplacer(n - 1, C, B, A);
    }
}

void main()
{
    int n;

    printf("Donner le nombre de disques : ");
    scanf("%d", &n);

    if (n <= 0)
        printf("Le nombre de disques doit etre strictement positif.\n");
    else
        deplacer(n, 'A', 'B', 'C');
}
```

**Explication :**

- **Cas de base :** lorsqu’il ne reste qu’un disque (`n == 1`), il suffit de le déplacer directement de `A` vers `B`.
- **Cas récursif :** pour déplacer `n` disques de `A` vers `B` :
  1. Déplacer les `n - 1` disques du sommet de `A` vers `C`, en utilisant `B`.
  2. Déplacer le disque restant de `A` vers `B`.
  3. Déplacer les `n - 1` disques de `C` vers `B`, en utilisant `A`.

La fonction affiche les déplacements à effectuer.

------------------------------------------------------------------------
