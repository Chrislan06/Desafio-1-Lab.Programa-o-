#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void listar(unsigned char armarios) {
  unsigned char posicao;
  for (int i = 0; i < 8; i++) {
    posicao = (unsigned char)pow(2, i);
    printf((armarios & posicao) ? " x " : " %d ", i + 1);
  }
  puts("");
}

unsigned char ocupar(unsigned char armarios) {
  unsigned char ocupacao;
  do {
    ocupacao = rand() % 8;
    ocupacao = (unsigned char)pow(2, ocupacao);
  } while ((ocupacao | armarios) == armarios);
  armarios = ocupacao | armarios;
  return armarios;
}

unsigned char desocupar(unsigned char armarios, unsigned char retirar) {
  armarios &= ~(unsigned char)pow(2, retirar - 1);
  return armarios;
}

int main(void) {
  unsigned char armario = 0, escolha, tirar;
  do {
    listar(armario);
    srand(time(NULL));
    printf("Valor do Bit: %hhu\n\n", armario);
    puts("1. ocupar Armário.");
    puts("2. Desocupar Armário.");
    puts("3. Sair.");
    printf("Escolha: ");
    scanf("%hhu", &escolha);
    switch (escolha) {
    case 1:
      if (armario == 255) {
        puts("todos os armarios estão ocupados");
      } else {
        armario = ocupar(armario);
      }
      break;
    case 2:
      puts("\nQual armario que quer desocupar");
      printf("escolha: ");
      scanf("%hhu", &tirar);
      if ((armario | (unsigned char)pow(2, tirar - 1)) == armario) {
        armario = desocupar(armario, tirar);
      } else {
        printf("armário %d já está desocupado\n", tirar);
      }
      puts("");
      break;
    case 3:
      puts("\n\nMuito Obrigado por usar Nosso Gerenciador de armários");
      break;
    default:
      puts("\noperação inválida!");
      puts("");
    }
  } while (escolha != 3);
  return 0;
}