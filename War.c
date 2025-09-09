#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define Max_Nome 30
#define Max_Cor 10



// Definindo a estrutura do tipo Território
typedef struct {
    char Nom_Territorio[Max_Nome];
    char Nom_Cor[Max_Cor];
    int  Num_Tropas;
} Territorio;
int Num_Tamanho = 5;
int Num_Opcao_Atacante = -1;
int Num_Opcao_Defensor = -1;
int Num_Dado_Atacante = 0;
int Num_Dado_Defensor =0;

void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Atacar(Territorio* Atacante, Territorio* Defensor)
{
    printf("--- RESULTADO DA BATALHA ---\n");    
    printf("O atacante %s rolou o dado e tirou: %i\n",Atacante[Num_Opcao_Atacante-1].Nom_Territorio,Num_Dado_Atacante);
    printf("O defensor %s rolou o dado e tirou: %i\n",Defensor[Num_Opcao_Defensor-1].Nom_Territorio,Num_Dado_Defensor);
    if (Num_Dado_Atacante > Num_Dado_Defensor)
    {
        printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");
        Defensor[Num_Opcao_Defensor-1].Num_Tropas -= 1;

    }
    else if (Num_Dado_Atacante < Num_Dado_Defensor)
    {
        printf("VITORIA DO DEFENSOR! O atacante perdeu 1 tropa.\n");
        Atacante[Num_Opcao_Atacante-1].Num_Tropas -= 1;
    }
}

int main() {
    Territorio* territorios = (Territorio*)malloc(Num_Tamanho * sizeof(Territorio));

    srand(time(NULL));
    printf("--- Jogo War 5 Territórios ---\n");
    printf("\n");
    for (int i = 0; i < Num_Tamanho; i++)
    {
        /*printf("--- Cadastro Território %i\n",i+1);
        printf("Nome Território: ");
        fgets(territorios[i].nome,Max_Nome,stdin);
        printf("Cor Exército: ");
        fgets(territorios[i].cor,Max_Cor,stdin);
        printf("Número Tropa: ");
        scanf("%i",&territorios[i].tropas); 
        limparBufferEntrada();*/
        switch (i)
        {
        case 0:
            strcpy(territorios[i].Nom_Territorio, "America");
            strcpy(territorios[i].Nom_Cor, "Azul");
            territorios[i].Num_Tropas = 3;
            break;
        case 1:
            strcpy(territorios[i].Nom_Territorio, "Europa");
            strcpy(territorios[i].Nom_Cor, "Verde");
            territorios[i].Num_Tropas = 2;
            break;
        case 2:
            strcpy(territorios[i].Nom_Territorio, "Asia");
            strcpy(territorios[i].Nom_Cor, "Vermelho");
            territorios[i].Num_Tropas = 4;
            break;
        case 3:
            strcpy(territorios[i].Nom_Territorio, "Africa");
            strcpy(territorios[i].Nom_Cor, "Amarelo");
            territorios[i].Num_Tropas = 2;
            break;
        case 4:
            strcpy(territorios[i].Nom_Territorio, "Oceania");
            strcpy(territorios[i].Nom_Cor, "Branco");
            territorios[i].Num_Tropas = 2;
            break;
        default:
            break;
        };

    }
    printf("\n");
    printf("\n");
    printf("========================================\n");
    printf("MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("========================================\n");
    printf("\n");
    for (int i = 0; i < Num_Tamanho; i++)
    {
        printf("TERRITÓRIO %i\n",i+1);
        printf("  - Nome: %s",territorios[i].Nom_Territorio);
        printf("  - Domidado por: Exército %s",territorios[i].Nom_Cor);
        printf("  - Tropas: %i",territorios[i].Num_Tropas);
        printf("\n");        

    }
    printf("FASE DE ATAQUE \n");
    
    while (Num_Opcao_Atacante != 0)
    {
        printf("Escolha o territorio atacante (1 a 5,  ou 0 para sair): ");
        scanf("%i",&Num_Opcao_Atacante); 
        limparBufferEntrada();

        if (Num_Opcao_Atacante != 0)
        {
            printf("Escolha o territorio defensor (1 a 5): ");
            scanf("%i",&Num_Opcao_Defensor); 1
            limparBufferEntrada();
            if (Num_Opcao_Atacante == Num_Opcao_Defensor)
            {
                printf("Território repetido!\n\n");
            }
            else
            {
            
                if (Num_Opcao_Atacante >= 1 && Num_Opcao_Atacante <= 5)
                {
                    Num_Dado_Atacante = (rand() % 6) + 1;
                }
                
                if (Num_Opcao_Defensor >= 1 && Num_Opcao_Defensor <= 5)
                {
                    Num_Dado_Defensor = (rand() % 6) + 1;
                }

                Atacar(&territorios[Num_Opcao_Atacante-1],&territorios[Num_Opcao_Defensor-1]);
                printf("\n");
                printf("\n");
                printf("========================================\n");
                printf("MAPA DO MUNDO - ESTADO ATUAL\n");
                printf("========================================\n");
                printf("\n");
                for (int i = 0; i < Num_Tamanho; i++)
                {
                    printf("TERRITÓRIO %i\n",i+1);
                    printf("  - Nome: %s",territorios[i].Nom_Territorio);
                    printf("  - Domidado por: Exército %s",territorios[i].Nom_Cor);
                    printf("  - Tropas: %i",territorios[i].Num_Tropas);
                    printf("\n");        

                }
            }
        
        }
    }

    free(territorios);
    return 0;
}