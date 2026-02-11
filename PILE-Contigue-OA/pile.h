#define N 100
struct pile
{
    int cle[N];
    int sommet;
};

void creerpile(void);
unsigned pile_vide(void);
int dernier(void);
void emplier(int);
void depiler(void);
