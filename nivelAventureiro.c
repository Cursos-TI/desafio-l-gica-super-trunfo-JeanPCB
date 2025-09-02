#include <math.h>
#include <stdio.h>
#include <string.h>

float popDensityCalc(unsigned long pop, float area) { return pop / area; }

double pibPerCapita(double pib, unsigned long pop) { return pib / pop; }

float totalPower(unsigned long pop, float area, double pib) {
  float pibCapita = pibPerCapita(pib, pop);
  float popDens = 1 / popDensityCalc(pop, area);

  return pop + area + pib + pibCapita + popDens;
}

void printCard(char code[], char state[], char city[], unsigned long pop,
               float area, double pib) {
  printf("Codigo: %s\n", code);
  printf("Estado: %s\n", state);
  printf("Cidade: %s\n", city);
  printf("Populacao: %lu\n", pop);
  printf("Area: %.2f\n", area);
  printf("PIB: %.2f\n", pib);
  printf("Densidade Populacional: %.2f\n", popDensityCalc(pop, area));
  printf("PIB per Capita: %.2f\n\n", pibPerCapita(pib, pop));
}

int main() {
  char state1[3], state2[3];
  char cardCode1[4], cardCode2[4];
  char city1[30], city2[30];
  unsigned long pop1, pop2;
  int tourPlaces1, tourPlaces2;
  float area1, area2;
  double pib1, pib2;
  char buffer[100];

  // Carta com maior atributo
  char winCardCode[4];

  // Escolha menu interativo
  short int menuChoice;

  printf("=== CADASTRO CARTA 1 ===\n");

  printf("Estado: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%2s", state1);

  printf("Codigo da carta: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%3s", cardCode1);

  printf("Cidade: ");
  fgets(city1, sizeof(city1), stdin);
  city1[strcspn(city1, "\n")] = '\0';

  printf("Populacao: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%lu", &pop1);

  printf("Area: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%f", &area1);

  printf("PIB: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%lf", &pib1);

  printf("Numero pontos turisticos: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%d", &tourPlaces1);

  printf("=== CADASTRO CARTA 2 ===\n");

  printf("Estado: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%2s", state2);

  printf("Codigo da carta: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%3s", cardCode2);

  printf("Cidade: ");
  fgets(city2, sizeof(city2), stdin);
  city2[strcspn(city2, "\n")] = '\0';

  printf("Populacao: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%lu", &pop2);

  printf("Area: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%f", &area2);

  printf("PIB: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%lf", &pib2);

  printf("Numero pontos turisticos: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%d", &tourPlaces2);

  float popDens1 = popDensityCalc(pop1, area1);
  float popDens2 = popDensityCalc(pop2, area2);

  printf("\n=== COMPARACAO DE ATRIBUTO ===\n");
  printf("Escolha um atributo: \n");
  printf("1. Nome da cidade\n");
  printf("2. Populacao\n");
  printf("3. Area\n");
  printf("4. PIB\n");
  printf("5. Numero de pontos turisticos\n");
  printf("6. Densidade demografica\n");
  printf("0. Sair\n");
  scanf("%hd", &menuChoice);

  switch (menuChoice) {
    printf("%s VS %s", city1, city2);
  case 1:
    printf("Atributo: nome da cidade\n");
    printCard(cardCode1, state1, city1, pop1, area1, pib1);
    printCard(cardCode2, state2, city2, pop2, area2, pib2);
    break;

  case 2:
    printf("Atributo: populacao\n");
    printf("%lu - %lu", pop1, pop2);
    if (pop1 > pop2) {
      printf("Carta 1 venceu!");
    } else if (pop2 > pop1) {
      printf("Carta 2 venceu!");
    } else {
      printf("Empate!");
    }
    break;

  case 3:
    printf("Atributo: area\n");
    printf("%.2f - %.2f", area1, area2);
    if (area1 > area2) {
      printf("Carta 1 venceu!");
    } else if (area2 > area1) {
      printf("Carta 2 venceu!");
    } else {
      printf("Empate!");
    }
    break;

  case 4:
    printf("Atributo: PIB\n");
    printf("%.2f - %.2f", pib1, pib2);
    if (pib1 > pib2) {
      printf("Carta 1 venceu!");
    } else if (pib2 > pib1) {
      printf("Carta 2 venceu!");
    } else {
      printf("Empate!");
    }
    break;

  case 5:
    printf("Atributo: pontos turisticos\n");
    printf("%d - %d", tourPlaces1, tourPlaces2);
    if (tourPlaces1 > tourPlaces2) {
      printf("Carta 1 venceu!");
    } else if (tourPlaces2 > tourPlaces1) {
      printf("Carta 2 venceu!");
    } else {
      printf("Empate!");
    }
    break;

  case 6:
    printf("Atributo: densidade populacional\n");
    printf("%.2f - %.2f", popDens1, popDens2);
    if (popDens1 < popDens2) {
      printf("Carta 1 venceu!");
    } else if (popDens2 < popDens1) {
      printf("Carta 2 venceu!");
    } else {
      printf("Empate!");
    }
    break;

  default:
    printf("Encerrando...\n");
  }

  return 0;
}
