/*
 * ANALISADOR LEXICO
 
*/

#include <stdlib.h> // CONVERSÃO, MEMÓRIA,CONTROLE DE PROCESSO
#include <stdio.h> // ENTRADA E SAÍDA (PRINTF, SCANF, FPRINT,FSCANF)
#include <string.h> // CADEIAS DE CARACTERES E REGIÕES DE MEMÓRIA 
#include <windows.h> // ESPECÍFICO DO WINDOWS

int countLinha = 0; int countCaracter = 0; int countAspas = 0; int countChaves = 0; int countParenteses = 0; int countErroCaracter = 0; int errocod = 0;
char file[40]; char palavra[400];

typedef int LINHA;

typedef struct {   // CÓDIGO ID , DICIONÁRIO
	LINHA linha;  
	int nElemento;               
	char palavra[40];              
	} REGISTRO;

typedef struct aux { // AUXILIAR , REGISTRO
 REGISTRO regt;             
 struct aux* prx;
} ELEMENTO,* P;

typedef struct {  // LISTA , PONTEIRO INICIO , PONTEIRO FIM 
 P inicio;
 P fim;            
} LISTA;

LISTA LL;
void inicializarLISTA(LISTA* LL) { // INCIALIZANDO LISTA
LL->inicio = 0;
LL->fim = 0;
}

int tamanho(LISTA* LL) { // TAMANHO, ENDEREÇO
P ender = LL->inicio;
int tam = 0;
while (ender != 0) {
tam++;
ender = ender->prx;
}
return tam;
}

int exibirLISTA(LISTA* LL) { // EXIBIÇÃO DE LISTA VAZIA 
    P ender = LL->inicio;
    if(LL->inicio==0) {
            printf("\nLista Ligada vazia!!\n"); // LISTA VAZIA	
    return 0;
    }else{
        printf("\tPalavras analisadas:  ");                 //  PALAVRAS ANALISADAS 
        while (ender != 0) {
            printf("\nPalavra:          %s", ender->regt.palavra);
            //printf("\nN de Elementos:   %d\n", ender->regt.nElemento);
            ender = ender->prx;
        }
    printf("\n");
    }
}

int salvarCodigo(char *token, LISTA* LL,int elementos){  // SALVAR CÓDIGO , GERAR TOKEN 
    //printf("\n%s",token);
        P novo = (P) malloc(sizeof(ELEMENTO));
        novo->regt.linha = countLinha;
        strcpy(novo->regt.palavra, token);
        novo->regt.nElemento = elementos;
        novo->prx = 0;
        if (LL->inicio==0) LL->inicio = novo;
        else LL->fim->prx = novo;
        LL->fim = novo;
        return 1;
}

int verificaNumero(char *numero){  // VERIFICAR NÚMERO , COMPARAR NÚMERO COM CHAR 
int countNum = 0;
int valor = atoi(numero); 
if(strcmp(numero,"0")==0)
    countNum++;
if(valor==0)
    countNum++;
return countNum;
}

void inicio(LISTA* LL){  // INICIO DA LISTA , COMPARANDO AS PALAVRAS SE AS MESMAS ESTÃO PRESENTES NA LISTA 
    P ender = LL->inicio;
    char aux[400];
    printf("\nPalavras validas:\n");
    while (ender != 0) {
            if (strcmp (ender->regt.palavra, "num") == 0){              //NUM
                printf("\nPalavra valida: %s ",ender->regt.palavra);
                ender = ender->prx;
            } else if (strcmp (ender->regt.palavra, "string") == 0){    //STRING
                printf("\nPalavra valida: %s ",ender->regt.palavra);
                ender = ender->prx;
            } else if (strcmp (ender->regt.palavra, "print") == 0){     //PRINT
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "read") == 0){      //READ
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "return") == 0){    //RETURN
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "if") == 0){        //IF
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "else") == 0){      //ELSE
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "sqrt") == 0){      //SQRT
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "for") == 0){       //FOR
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "step") == 0){      //STEP
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "to") == 0){        //TO
                printf("\nPalavra valida: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "{") == 0){         //FECHAMENTO CHAVE {
                printf("\nFechamento(chaves): %s ",ender->regt.palavra);
                countChaves++;
            } else if (strcmp (ender->regt.palavra, "}") == 0){         //FECHAMENTO CHAVE }
                printf("\nFechamento(chaves): %s ",ender->regt.palavra);
                countChaves--;
            } else if (strcmp (ender->regt.palavra, "(") == 0){         //FECHAMENTO PARENTESES (
                printf("\nFechamento(parenteses): %s ",ender->regt.palavra);
                countParenteses++;
            } else if (strcmp (ender->regt.palavra, ")") == 0){         //FECHAMENTO PARENTESES )
                printf("\nFechamento(parenteses): %s ",ender->regt.palavra);
                countParenteses--;
            } else if (strcmp(ender->regt.palavra,"\"")==0){            // FECHAMENTO ASPAS 
                printf("\nFechamento (aspas): %s",ender->regt.palavra);
                countAspas++;
            } else if (strcmp (ender->regt.palavra, ">") == 0){         //OPERADOR RELACIONAL >
                printf("\nOperador Relacional: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "<") == 0){         //OPERADOR RELACIONAL <
                printf("\nOperador Relacional: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "=") == 0){         //OPERADOR RELACIONAL/ ATRIBUIÇÃO =
                printf("\nOperador Relacional: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "*") == 0){         //OPERADOR ARITIMETICO *
                printf("\nOperador Aritimetico: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "/") == 0){         //OPERADOR ARITIMETICO/
                printf("\nOperador Aritimetico: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "+") == 0){         //OPERADOR ARITIMETICO +
                printf("\nOperador Aritimetico: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "-") == 0){         //OPERADOR ARITIMETICO -
                printf("\nOperador Aritimetico: %s ",ender->regt.palavra);
            } else if (strcmp (ender->regt.palavra, "%") == 0){         //OPERADOR ARITIMETICO %
                printf("\nOperador Aritimetico: %s ",ender->regt.palavra);
            } else if(verificaNumero(ender->regt.palavra)==0 || verificaNumero(ender->regt.palavra)==2 ){
                printf("\nNUM: %s",ender->regt.palavra);
            }
            ender = ender->prx;
        }
}

int verificaFechamento(){ // VERIFICAÇÃO DE FECHAMENTO DO CÓDIGO 
    FILE *arquivo;
    arquivo = fopen("resultado.txt", "a"); // ABERTURA DO ARQUIVO
    //printf("\n CHAVES: %d - PARENTESES: %d - ASPAS: %d", countCHAVES, countPARENTESES,countASPAS);
    if(arquivo == 0){
        printf("Erro na abertura do arquivo!"); // ERRO NA ABERTURA DO CÓDIGO
        return 1;
    }
    if(countChaves!=0 || countParenteses!=0 || countAspas%2!=0 ){ 
        fprintf(arquivo, "\n%s", "Falta fechamento do codigo "); // FALTA FECHAMENTO DO CÓDIGO
        errocod++;
    }
    fclose(arquivo); // FECHAMENTO DO ARQUIVO 
}

int verificaErros(){ // VERIFICAÇÃO DE ERROS DO ARQUIVO 
    FILE *arquivo;
    arquivo = fopen("resultado.txt", "a"); // ABERTURA DO ARQUIVO 
    if(arquivo == 0){
        printf("Erro na abertura do arquivo!"); // ERRO NA ABERTURA DO ARQUIVO 
        return 1;
    }
    if(errocod==0){
        fprintf(arquivo, "\n%s", "Arquivo  "); 
        fprintf(arquivo, "%s", file);
        fprintf(arquivo, "%s", "  analisado corretamente");
    } else {
        fprintf(arquivo, "\n%s", " O arquivo  ");
        fprintf(arquivo, "%s", file);
        fprintf(arquivo, "%s", " contem erro(s) ");
    }
    fclose(arquivo);
}

int verificaLexema(char *caracter, LISTA* LL, int countCaracter){  // VERIFICAÇÃO DE LEXEMA , PALAVRA E CARACTER 
        int n;
        FILE *arquivo;
            if (strcmp (caracter, "a") == 0){
                  strcat(palavra,caracter);
                  printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "b") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "c") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "d") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "e") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "f") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "g") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "h") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "i") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "j") == 0){
               strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "k") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "l") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "m") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "n") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "o") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "p") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "q") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "r") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "s") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "t") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "u") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "v") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "w") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "y") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "x") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "z") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "0") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "1") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "2") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "3") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "4") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "5") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "6") == 0){
               strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "7") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "8") == 0){
               strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "9") == 0){
                strcat(palavra,caracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "{") == 0){         //Fechamento Chave {
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "}") == 0){         //Fechamento Chave }
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "(") == 0){         //Fechamento Parenteses (
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, ")") == 0){         //Fechamento Parenteses )
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "\"")==0){          // Fechamento aspas
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "<") == 0){         //Operador relacional <
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, ">") == 0){         //Operador relacional >
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "=") == 0){         //Operador relacional ou atribuição =
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                printf("\nletra: %s - palavra: %s",caracter,palavra);
                strcpy(caracter,"");
            } else if (strcmp (caracter, "*") == 0){         //OPERADOR ARITIMETICO *
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "/") == 0){         //OPERADOR ARITIMETICO /
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "+") == 0){         //OPERADOR ARITIMETICO +
               verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "-") == 0){         //OPERADOR ARITIMETICO -
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, "%") == 0){         //OPERADOR ARITIMETICO %
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                salvarCodigo(caracter,LL,countCaracter);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, ";") == 0){         // PONTO E VÍRGULA
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, ",") == 0){         // VIRGULA
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, ":") == 0){         //  DOIS PONTOS
                verificaCadeia(palavra,caracter,countCaracter,countErroCaracter,LL);
                strcpy(caracter,"");
                printf("\nletra: %s - palavra: %s",caracter,palavra);
            } else if (strcmp (caracter, " ") == 0 || strcmp (caracter, "\n") == 0 || strcmp (caracter, "\0") == 0){         //ESPAÇO
                countLinha++;
                if(strcmp (palavra, " ") == 0 || strcmp (palavra, "\n") == 0 || strcmp (palavra, "\0") == 0){
                    printf("\nEspaco vazio: %s",palavra); // COMPARAÇÃO ESPAÇO COM PALAVRA
                    printf("\nErro: %d",countErroCaracter);
                } else {
                    if (countErroCaracter==0){
                        salvarCodigo(palavra,LL,countCaracter);
                        printf("\nPalavra salva: %s",palavra);
                    }else {
                        errocod++;
                        arquivo = fopen("resultado.txt", "a");
                        if(arquivo == 0){
                        printf("Erro na abertura do arquivo!");
                        return 1;
                        }
                        fprintf(arquivo, "\n%s", "Palavra");
                        fprintf(arquivo, "\t%s\t", palavra);
                        printf("------>word**: %s", palavra);
                        fprintf(arquivo, "\t%s", "nao reconhecida");
                        fclose(arquivo);
                    }
                }
                countErroCaracter = 0;
                strcpy(palavra,"");
                strcpy(caracter,"");
            } else {
                strcat(palavra,caracter);
                countErroCaracter++;
                printf("\n erro: letra: %s - palavra: %s - erro: %d",caracter,palavra,countErroCaracter);
            }
}

int verificaCadeia(char *palavra, char *caracter, int countCaracter, int countErroCaracter, LISTA *LL){ // VERIFICAÇÃO DE CADEIA
    FILE *arquivo;
    if(strcmp (palavra, " ") == 0 || strcmp (palavra, "\n") == 0 || strcmp (palavra, "\0") == 0){
            printf("\nEspaco vazio: %s",palavra);
            printf("\nErro: %d",countErroCaracter);
    } else {
        if(countErroCaracter==0){
            salvarCodigo(palavra,LL,countCaracter);
            printf("\nPalavra salva: %s",palavra);
        } else {
            errocod++;
            arquivo = fopen("resultado.txt", "a");
            if(arquivo == 0){
                printf("Erro na abertura do arquivo!");
                return 1;
            }
            fprintf(arquivo, "\n%s", "Palavra");
            fprintf(arquivo, "\t%s\t", palavra);
            printf("\n------>word: %s", palavra);
            fprintf(arquivo, "\t%s", "nao reconhecida");
            fclose(arquivo);
        }
    }
    strcpy(palavra,"");
    countErroCaracter = 0;
}

void output(){ // ARQUIVO DE SAÍDA 
       printf("# ARQUIVO DE SAIDA : resultado.txt #\n");
       Sleep(5000);
}

void loading(){ // CARREGANDO ARQUIVO 
      printf("# CARREGANDO, LENDO E COMPILANDO O ARQUIVO:-> %s \n",file);
    Sleep(5000);
}

void lerArquivo(LISTA *LL){ // LER ARQUIVO 
	FILE *arq;
	char caracter[400];
	gets(file);
	loading();
	arq = fopen(file, "r");
	strcpy(palavra,"");
	while (!feof(arq)){
       fread(&caracter,1,1,arq);
        countCaracter++;
        //printf("\n[%s]",caracter);
        //Sleep(10);
        verificaLexema(caracter,LL,countCaracter);
	}
    printf("\nArquivo lido com sucesso!\n");
}

int main() { // FUNCAO MAIN
    char arquivo[300]; 
    inicializarLISTA(&LL); // INCIALIZAR LISTA 
    printf("|=========== ANALISADOR LEXICO ==========|\n");
    printf("|== INFORME O NOME DO ARQUIVO A SER ANALISADO: ==|\n");
    printf("|=>");
    lerArquivo(&LL); // LER ARQUIVO
    exibirLISTA(&LL); // EXIBIR ARQUIVO 
    Sleep(5000);
    system("cls");
    inicio(&LL); // INICIO 
    verificaFechamento(); // VERIFICACAO FECHAMENTO DO ARQUIVO 
    verificaErros(); // VERIFICACAO DE ERROS DO ARQUIVO 
    output(); // SAÍDA DO ARQUIVO 
    return (0); 
}
