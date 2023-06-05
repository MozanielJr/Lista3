#include <stdio.h>

#define MAX_FABRICANTES 5
#define MIN_FABRICANTES 2



struct Fabricante {
    char marca[50];
    char site[100];
    char telefone[15];
    char uf[2];
};


void leValidaFabricante(struct Fabricante *fabricante) {
    printf("Marca: ");
    fgets(fabricante->marca, sizeof(fabricante->marca), stdin);
    fabricante->marca[strcspn(fabricante->marca, "\n")] = '\0';

    printf("Site: ");
    fgets(fabricante->site, sizeof(fabricante->site), stdin);
    fabricante->site[strcspn(fabricante->site, "\n")] = '\0';

    printf("Telefone: ");
    fgets(fabricante->telefone, sizeof(fabricante->telefone), stdin);
    fabricante->telefone[strcspn(fabricante->telefone, "\n")] = '\0';

    printf("UF: ");
    fgets(fabricante->uf, sizeof(fabricante->uf), stdin);
    fabricante->uf[strcspn(fabricante->uf, "\n")] = '\0';
}



int main (){




}


