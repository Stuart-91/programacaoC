#include <stdio.h>
int main(){

    // ***** Desafio Super Trunfo - Estados *****
    
    int População1, População2;
    int Pontos1, Pontos2;
    float Área1, Área2;
    float PIB1, PIB2;
    char Estado1[30], Estado2[30];
    char Cidade1[30], Cidade2[30];
    char Carta1[5], Carta2[5];

    
    // ***** Cadastro da Primeira Carta *****
    
    printf("Cadastre a primeira carta\n");
    
    printf("Código da Carta? \n");
    scanf("%s", Carta1);
    
    printf("Nome do Estado? \n");
    scanf("%s", Estado1);
    
    printf("Nome da Cidade? \n");
    scanf("%s", Cidade1);
    
    printf("Área da Cidade em km²? \n");
    scanf("%f", &Área1);
    
    printf("População da Cidade? \n");
    scanf("%d", &População1);
    
    printf("PIB da Cidade? \n");
    scanf("%f", &PIB1);
    
    printf("Pontos Turísticos? \n");
    scanf("%d", &Pontos1);
    

    // ***** Saída Dados da Cidade *****
    
    printf("***** CARTA 01 ***** \n");
    printf("Estado: %s\n", Estado1);
    printf("Cidade: %s\n", Cidade1);
    printf("Área: %.3fkm²\n", Área1);
    printf("População: %d\n", População1);
    printf("PIB: R$%.3f\n", PIB1);
    printf("Pontos Turísticos: %d\n", Pontos1);
    printf("Código da carta %s\n", Carta1);

    // ***** Cadasto da Segunda Carta *****
    
    printf("Cadastre a segunda carta\n");
    
    printf("Código da Carta? \n");
    scanf("%s", Carta2);
    
    printf("Nome do Estado? \n");
    scanf("%s", Estado2);
    
    printf("Nome da Cidade? \n");
    scanf("%s", Cidade2);
    
    printf("Área da Cidade em km²? \n");
    scanf("%f", &Área2);
    
    printf("População da Cidade? \n");
    scanf("%d", &População2);
    
    printf("PIB da Cidade? \n");
    scanf("%f", &PIB2);
    
    printf("Pontos Turísticos? \n");
    scanf("%d", &Pontos2);
    

    // ***** Saída Dados da Cidade 2 *****
    
    printf("***** CARTA 02 ***** \n");
    printf("Estado: %s\n", Estado2);
    printf("Cidade: %s\n", Cidade2);
    printf("Área: %.3fkm²\n", Área2);
    printf("População: %d\n", População2);
    printf("PIB: R$%.3f\n", PIB2);
    printf("Pontos Turísticos: %d\n", Pontos2);
    printf("Código da carta %s\n", Carta2);
    
    // *****Comparação entre cartas para ver quem venceu *****

    printf ("!!!Resultado Final Super Trunfo!!!\n\n");
    
    printf ("Atributo entre População:\n");
    if (População1 < População2)
    {
        printf("População A venceu! \n\n");
    }else {
        printf("População B venceu! \n\n");
    }

    printf ("Atributo entre Pontos Turísticos:\n");
    if (Pontos1 > Pontos2)
    {
       printf("Pontos Turísticos A venceu! \n\n");
    }else{
       printf("Pontos Turísticos B venceu! \n\n");
    }

    printf ("Atributo entre Área da cidade:\n");
    if (Área1 > Área2)
    {
       printf("Área da cidade A venceu! \n\n");
     }else{
        printf("Àrea da cidade B venceu! \n\n");
     }
    
    printf ("Atributo entre PIB:\n");
    if (PIB1 > PIB2)
    {
        printf("PIB A venceu! \n\n");
     }else{
        printf("PIB B venceu! \n\n");
     }
    
    
    
       return 0;
}
