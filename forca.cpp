#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int drawForca(int erros){
    switch (erros)
    {
    case 0:
        printf("___________\n");
        printf("|          |\n");
        printf("|           \n");
        printf("|           \n");
        printf("|           \n");
        printf("------------\n");
        break;
    case 1:
        printf("___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|           \n");
        printf("|           \n");
        printf("------------\n");
        break;
    case 2:
        printf("___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|          |\n");
        printf("|           \n");
        printf("------------\n");
        break;
    case 3:
        printf("___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|         /|\n");
        printf("|           \n");
        printf("------------\n");
        break;
    case 4:
        printf("___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|         /|\\\n");
        printf("|           \n");
        printf("------------\n");
        break;
    case 5:
        printf("___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|         /|\\\n");
        printf("|           \\\n");
        printf("------------\n");
        break;
    case 6:
        printf("___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|         /|\\\n");
        printf("|         / \\\n");
        printf("------------\n");
        break;
    default:
        break;
    }
}
char letrasDigitas[26];
const int quantida = 10;
char palaD[30];
char bancoDePala[quantida][30] = {
    "uva",
    "cachorro",
    "pao",
    "sanduiche",
    "leite",
    "refrigerante",
    "tigre",
    "boi",
    "macaco",
    "girafa"
};
char * sortearPalavra(){
    char * pala = (char*) malloc( (100 + 1) * sizeof(char) ) ;
    srand(time(NULL));
    strcpy(pala, bancoDePala[rand() % 10]);
    return pala;
}
char pedirletra(){
    char letra;
    printf("digite uma letra ");
    scanf("%c%*c",&letra);
    return letra;
}
char printLetras(int quantLetras){
    int i;
    for (i = 0; i < quantLetras; i++)
    {
        printf(" _ "); 
    }
    printf("\n\n");
}
int verificar(char letra, char *uva, int erro, int qtdL){
    int i = 0, acertos = 0, erros = 0;
    for (i = 0; i < qtdL; i++)
    {
        if (letra != uva[i])
        {
            erros += 1;
        }
    }
    if (erros == qtdL)
    {
        erro +=1;
    }
    return erro;
}
void LJDigi(){
    printf("\n");
    printf("letras ja digitas ");
    printf("%s",letrasDigitas);
    printf("\n");   
}
int rtrnQtdL(char * palvraS){
    if (strcmp (palvraS, "uva") == 0)
    {
        return 3;
    }
    if (strcmp (palvraS, "cachorro") == 0)
    {
        return 8;
    }
    if (strcmp (palvraS, "pao") == 0)
    {
        return 3;
    }
    if (strcmp (palvraS, "sanduiche") == 0)
    {
        return 9;
    }
    if (strcmp (palvraS, "leite") == 0)
    {
        return 5;
    }
    if (strcmp (palvraS, "refrigerante") == 0)
    {
        return 13;
    }
    if (strcmp (palvraS, "tigre") == 0)
    {
        return 5;
    }
    if (strcmp (palvraS, "boi") == 0)
    {
        return 3;
    }
    if (strcmp (palvraS, "macaco") == 0)
    {
        return 6;
    }
    if (strcmp (palvraS, "girafa") == 0)
    {
        return 6;
    }   
}
bool verificar_Ld(char letra, char * letrasD, int qtd){
    for (int i = 0; i < qtd; i++)
    {
        if (letra == letrasD[i])
        {
            return true;
        }   
    }
    return false;
}
int acertos(char letra, char *uva,  int qtdl, char * ultimaLetra){
    int i = 0, acertos = 0;
    for (i = 0; i < qtdl; i++)
    {
        if(letra == uva[i]){
            acertos++;
        }
    }
    return acertos;
}
void vetorPala(char letra,int qtdL, char* pala){
    for (int i = 0; i < qtdL; i++)
    {
        if (letra == pala[i])
        {
            palaD[i] = letra;

        }
        
    }
}
int Perde(int limiteTent, int errAtuais, int acertosatuais, int quantidadeDeletras){
    if (limiteTent == errAtuais || acertosatuais == quantidadeDeletras)
    {
        return 1;
    }else 
    {
        return 0;
    } 
}
int main(){
    char * uva = sortearPalavra();
    int erro = 0,acerto = 0;
    int qtdL = rtrnQtdL(uva);
    int cont_let = 0;
    char letra;
    int fim = 0, Limitentativas = 6;
    drawForca(erro);
    palaD[qtdL];
    for (int i = 0; i < qtdL; i++)
    {
        palaD[i]= '_';
    }
    printf("%s", palaD);
    while (fim == 0)
    {   
        printf("\n");
        letra = pedirletra();
        if (verificar_Ld(letra, letrasDigitas, qtdL))
        {
            printf("\npor favor digite outra letra\n"); 
            system("pause");
        }else
        {
            letrasDigitas[cont_let] = letra;
            cont_let++;
            acerto += acertos(letra, uva, qtdL, letrasDigitas);  
            erro = verificar(letra, uva, erro, qtdL);
            vetorPala(letra,qtdL,uva);
        }
        system("cls");
        printf("\n====JOGO DA FORCA====\n");
        drawForca(erro);
        printf("\n");
        printf("%s", palaD);
        printf("\n");
        LJDigi();
        fim = Perde(Limitentativas, erro, acerto, qtdL);
    } 
    printf("\n GAME OVER \n");
}