#include <stdio.h>
#include <string.h>

#define MAX 200
#define NOM_ARXIU "magatzem.txt"

// Tipus de dades que defineix un producte de la nostra botiga
typedef struct {
  char nom[MAX];
  float preu;
  int quantitat;
} t_producte;

// Llistat de productes, de nombre (num) variable
typedef struct {
  int num;
  t_producte prods[MAX];
} t_llista_productes;

// Guarda al fitxer de disc "magatzem.txt" una llista de productes, en format:
// 4    <-- numero de productes
// Aspirador:100.00:7 <- cada linea es un producte en format nom:preu:quantitat
// iPod:250.00:6
// Play Station 4:350.00:60
// Xbox 360:400.00:50
void guardar(t_llista_productes lp);

// Llegeix la llista de productes del fitxer de disc "magatzem.txt", en el
// mateix format en que s'ha guardat a la funció "guardar". Guarda les dades
// a la llista de productes apuntada pel punter *lp.
// Retorna 0 si s'ha carregat. -1 en cas de que hi hagi hagut algun error
int carregar(t_llista_productes *lp);

// Mostra per pantalla un producte
void mostrar(t_producte p);

// Mostra per pantalla tots els productes d'una llista
void mostrar_llista(t_llista_productes lp);

// Llegeix un producte pel teclat i el retorna
t_producte llegir();

// Donat un producte i una llista de productes ja ordenada alfabèticament,
// retorna en quina posició hauria d'insertar-se el producte per que la llista
// continués estant alfabèticament ordenada.
int buscar_posicio(t_producte p, t_llista_productes lp);

// Inserta el producte p a la posició "pos" de la llista apuntada per *lp
void insertar(t_producte p, int pos, t_llista_productes *lp);

main() {
  t_llista_productes stock;
  
  if (carregar(&stock) != 0) {
    printf("Arxiu de dades no existeix. ");
    printf("Es creara un arxiu nou\n");
    stock.num = 0;
  }

  t_producte p = llegir();
  
  int pos = buscar_posicio(p, stock);
  insertar(p, pos, &stock);
  
  printf("La llista actualitzada es:\n");
  mostrar_llista(stock);
  
  guardar(stock);
}

void guardar(t_llista_productes lp) {
  FILE *fp = fopen(NOM_ARXIU, "w");
  if (fp == NULL) {
    printf("Error a l'obrir arxiu\n");
    return;
  }
  
  fprintf( fp, "%d\n", lp.num);
  int i;
  for( i = 0 ; i < lp.num ; i++) {
    fprintf( fp, "%s:%.2f:%d\n",
          lp.prods[i].nom,
          lp.prods[i].preu,
          lp.prods[i].quantitat);       
  }
  
  fclose(fp);
}

int carregar(t_llista_productes *lp) {
  FILE *fp = fopen(NOM_ARXIU, "r");
  if (fp == NULL) {
    // Si el fitxer no existeix, retorna -1 i no fa res mes
    return -1;
  }
  
  // primera línia: número d'elements
  fscanf(fp, "%d%*c", &lp->num);
  int i;
  for (i = 0 ; i < lp->num ; i++) {
    // A cadascuna de les següents línies es llegeix les dades d'un producte,
    // en format: nom:preu:quantitat
    fscanf(fp, "%[^:]:%f:%d%*c", lp->prods[i].nom, &lp->prods[i].preu,
                                 &lp->prods[i].quantitat);
  }
  // No oblidar mai! Tancar arxiu després d'usar
  fclose(fp);
  return 0;
}

void mostrar(t_producte p) {
  printf("- %s\n", p.nom);
  printf("  Preu: %.2f\tStock: %d\n", p.preu, p.quantitat);
}

void mostrar_llista(t_llista_productes lp) {
  int i;
  for (i = 0 ; i < lp.num ; i++) {
    mostrar(lp.prods[i]);
  }
}

t_producte llegir() {
  t_producte p;
  
  printf("Nom: ");
  scanf("%[^\n]%*c", p.nom);
  printf("Preu: ");
  scanf("%f%*c", &p.preu);
  printf("Quantitat: ");
  scanf("%d%*c", &p.quantitat);
  
  return p;  
}

int buscar_posicio(t_producte p, t_llista_productes lp) {
  int pos = 0;
  // Mentre no arribem al final de la llista o trobem un producte
  // alfabèticament posterior al que volem insertar, seguim buscant a la
  // següent posició
  while(pos < lp.num && strcasecmp(p.nom, lp.prods[pos].nom) > 0) {
    pos++;
  }
  return pos;
}

void insertar(t_producte p, int pos, t_llista_productes *lp) {
  // Primer fem espai pel nou element, començant pel darrere
  int i;
  for (i = lp->num ; i > pos ; i--) {
    lp->prods[i] = lp->prods[i-1];
  }          
  // Copiem el producte a la posició on es vol insertar
  lp->prods[pos] = p;
  // Incrementem el compte del número d'elements
  lp->num++;  
}
