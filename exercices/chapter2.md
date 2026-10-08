# Chapitre 2 — Les opérateurs de base & Fonctions E/S

## Exercices d’application

---

## Exercice 1 — Permutation de trois entiers

### Enoncé

Ecrire un programme qui demande à l’utilisateur de saisir trois valeurs entières pour les trois variables `a`, `b`, `c` de type entier. Le programme va par la suite permuter et afficher leurs valeurs.

**Permutation :**

- `a → b`
- `b → c`
- `c → a`

### Correction

```c
#include <stdio.h>

void main()
{
    int a, b, c, aide;

    printf("Introduisez trois nombres (a, b, c):\n");
    scanf("%d %d %d", &a, &b, &c);

    /* Affichage à l'aide de tabulations */
    printf("a = %d\tb = %d\tc = %d\n", a, b, c);

    aide = a;
    a = c;
    c = b;
    b = aide;

    printf("a = %d\tb = %d\tc = %d\n", a, b, c);
}
```

---

## Exercice 2 — Résistance équivalente

### Enoncé

Ecrire un programme qui affiche la résistance équivalente à trois résistances `r1`, `r2`, `r3` de type `double`.

- **Si les résistances sont branchées en série :**

  `rser = r1 + r2 + r3`

- **Si les résistances sont branchées en parallèle :**

  `rpar = (r1 × r2 × r3) / (r1 × r2 + r1 × r3 + r2 × r3)`

### Correction

```c
#include <stdio.h>

void main()
{
    double r1, r2, r3;
    double rser, rpar;

    printf("Donner les valeurs des trois resistance:\n");
    scanf("%lf %lf %lf", &r1, &r2, &r3);

    rser = r1 + r2 + r3;
    rpar = (r1 * r2 * r3) / (r1 * r2 + r1 * r3 + r2 * r3);

    printf("Resistance equivalente en serie: %.2f\n", rser);
    printf("Resistance equivalente en parallele : %.2f", rpar);
}
```

---

## Exercice 3 — Opérateurs arithmétiques et bit à bit

### Enoncé

Définir deux entiers `i` et `j` initialisés avec les valeurs `10` et `3` respectivement.

Faire écrire les résultats de :

- `i + j`
- `i - j`
- `i * j`
- `i / j`
- `i % j`

Affecter les valeurs `0x0FF` et `0xF0F` respectivement à `i` et `j`.

Faire écrire en hexadécimal les résultats de :

- `i & j`
- `i | j`
- `i ^ j`
- `i << 2`
- `j >> 2`

### Correction

```c
#include <stdio.h>

void main()
{
    int i = 10, j = 3;

    printf("%d + %d = %d\n", i, j, i + j);
    printf("%d - %d = %d\n", i, j, i - j);
    printf("%d * %d = %d\n", i, j, i * j);
    printf("%d / %d = %d\n", i, j, i / j);
    printf("%d %% %d = %d\n", i, j, i % j);

    i = 0x0FF;
    j = 0xF0F;

    printf("%X & %X = %X\n", i, j, i & j);
    printf("%X | %X = %X\n", i, j, i | j);
    printf("%X ^ %X = %X\n", i, j, i ^ j);
    printf("%X << %d = %X\n", i, 2, i << 2);
    printf("%X >> %d = %X\n", j, 2, j >> 2);
}
```

---

## Exercice 4 — Opérateur conditionnel

### Enoncé

En utilisant 4 entiers `i`, `j`, `k` et `l`, avec `k` initialisé à `12` et `l` à `8`, écrire le programme qui :

- lit les valeurs de `i` et `j` ;
- écrit la valeur de `k` si `i` est nul ;
- écrit la valeur de `i + l` si `i` est non nul et `j` est nul ;
- écrit la valeur de `i + j` dans les autres cas.

### Correction

```c
#include <stdio.h>

void main()
{
    /* Declaration des 4 entiers, initialisation de k et l */
    int i, j, k = 12, l = 8;

    /* Lecture des valeurs de i et de j */
    printf("\nEntrer la valeur de i : ");
    scanf("%d", &i);

    printf("\nEntrer la valeur de j : ");
    scanf("%d", &j);

    /* Ecriture du resultat selon les valeurs de i et de j */
    printf("\n resultat : %d\n", (!i ? k : (!j ? i + l : i + j)));
}
```
