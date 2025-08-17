#include <stdio.h>
#include <string.h>
#define Max_Nome 30
#define Max_Cor 30



// Definindo a estrutura do tipo Território
typedef struct {
    char nome[Max_Nome];
    char cor[Max_Cor];
    int tropas;
} Territorio;

void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Territorio territorios[5] = {} ;

int main() {
    printf("--- Jogo War 5 Territórios ---\n");
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("--- Cadastro Território %i\n",i+1);
        printf("Nome Território: ");
        fgets(territorios[i].nome,Max_Nome,stdin);
        printf("Cor Exército: ");
        fgets(territorios[i].cor,Max_Cor,stdin);
        printf("Número Tropa: ");
        scanf("%i",&territorios[i].tropas); 
        limparBufferEntrada();
    }
    printf("\n");
    printf("\n");
    printf("========================================\n");
    printf("MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("========================================\n");
    printf("\n");
for (int i = 0; i < 5; i++)
    {
        printf("TERRITÓRIO %i\n",i+1);
        printf("  - Nome: %s",territorios[i].nome);
        printf("  - Domidado por: Exército %s",territorios[i].cor);
        printf("  - Tropas: %i",territorios[i].tropas);
        printf("\n");
    }
    return 0;
}