#include <stdio.h>
int main(){

    //***** Desafio Super Trunfo - Estados *****
    
    int População1, População2;
    int Pontos1, Pontos2;
    float Área1, Área2;
    float PIB1, PIB2;
    char Estado1[30], Estado2[30];
    char Cidade1[30], Cidade2[30];
    char Carta1[5], Carta2[5];

    //***** Cadastro da Primeira Carta *****
    
    printf("Cadastre a primeira carta\n");
    
    printf("código da carta? \n");
    scanf("%s", Carta1);
    
    printf("nome do estado? \n");
    scanf("%s", Estado1);
    
    printf("nome da cidade? \n");
    scanf("%s", Cidade1);
    
    printf("área da cidade em km²? \n");
    scanf("%f", &Área1);
    
    printf("população da cidade? \n");
    scanf("%d", &População1);
    
    printf("PIB da cidade? \n");
    scanf("%f", &PIB1);
    
    printf("pontos turísticos? \n");
    scanf("%d", &Pontos1);
    

    //***** Saída Dados da Cidade *****
    
    printf("***** CARTA 01 ***** \n");
    printf("Estado: %s\n", Estado1);
    printf("Cidade: %s\n", Cidade1);
    printf("Área: %.3fkm²\n", Área1);
    printf("População: %d\n", População1);
    printf("PIB: R$%.3f\n", PIB1);
    printf("Pontos Turísticos: %d\n", Pontos1);
    printf("Código da carta %s\n", Carta1);

    //***** Cadasto da Segunda Carta *****
    
    printf("Cadastre a segunda carta\n");
    
    printf("código da carta? \n");
    scanf("%s", Carta2);
    
    printf("nome do estado? \n");
    scanf("%s", Estado2);
    
    printf("nome da cidade? \n");
    scanf("%s", Cidade2);
    
    printf("área da cidade em km²? \n");
    scanf("%f", &Área2);
    
    printf("população da cidade? \n");
    scanf("%d", &População2);
    
    printf("PIB da cidade? \n");
    scanf("%f", &PIB2);
    
    printf("pontos turísticos? \n");
    scanf("%d", &Pontos2);
    

    //***** Saída Dados da Cidade 2 *****
    
    printf("***** CARTA 02 ***** \n");
    printf("Estado: %s\n", Estado2);
    printf("Cidade: %s\n", Cidade2);
    printf("Área: %.3fkm²\n", Área2);
    printf("População: %d\n", População2);
    printf("PIB: R$%.3f\n", PIB2);
    printf("Pontos Turísticos: %d\n", Pontos2);
    printf("Código da carta %s\n", Carta2);
    

    return 0;
}
