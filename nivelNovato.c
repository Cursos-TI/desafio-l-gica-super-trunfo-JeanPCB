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

  printf("\n=== DADOS CARTA ===\n");
  printCard(cardCode1, state1, city1, pop1, area1, pib1);
  printCard(cardCode2, state2, city2, pop2, area2, pib2);

  // Declaracao variaveis novos valores
  double pibCapita1 = pibPerCapita(pib1, pop1);
  double pibCapita2 = pibPerCapita(pib2, pop2);

  // Poder total da carta - determina a vencedora
  float power1 = totalPower(pop1, area1, pib1);
  float power2 = totalPower(pop2, area2, pib2);

  float popDens1 = popDensityCalc(pop1, area1);
  float popDens2 = popDensityCalc(pop2, area2);

  // Comparaçao maior PIB per capita
  if (pibCapita1 > pibCapita2) {
    strcpy(winCardCode, cardCode1);
  } else {
    strcpy(winCardCode, cardCode2);
  }

  printf("Comparação de cartas (Atributo: PIB per capita):\n");
  printf("%s - %s (%s): %f\n", cardCode1, city1, state1, pibCapita1);
  printf("%s - %s (%s): %f\n", cardCode2, city2, state2, pibCapita2);

  // strcmp() -> compara valor das strings nao ref memoria
  if (strcmp(winCardCode, cardCode1) == 0) {
    printf("Carta 1 (%s) venceu!", city1);
  } else if (strcmp(winCardCode, cardCode2) == 0) {
    printf("Carta 2 (%s) venceu!", city2);
  }

  // Carta vencedora pelo poder (total atributos)
  printf("\n=== CARTA VENCEDORA (TOTAL) ===\n");
  if (power1 > power2) {
    printf("Carta 1 VENCEU!!!");
  } else {
    printf("Carta 2 VENCEU!!!");
  }

  return 0;
}
