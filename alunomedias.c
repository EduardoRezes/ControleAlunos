#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 40

typedef struct Cadastro{
    int matricula, idade, registro, faltas;
    char nome[40], sexo[10];
    float notas[max][2];
}Cadastro;

Cadastro alunos[max];

int adicionar();
int analisar(int m);
float verificar_media(float n1, float n2, int faltas);
void pesquisar();
void exibir();
void aprovados();
void reprovados();
void salvar_carregar();
void salvar();
void carregar();
int space();

int main(){

    int op;
    do{
        system("cls");
        printf("*******************************************\n");
        printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
        printf("* [1] Adicionar                           *\n");
        printf("* [2] Pesquisar                           *\n");
        printf("* [3] Exibir                              *\n");
        printf("* [4] Salvar/Carregar                     *\n");
        printf("* [0] Sair                                *\n");
        printf("*******************************************\n");
        printf("Operação: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch(op){
            case 1:
                adicionar();
            break;
            case 2:
                pesquisar();
            break;
            case 3:
                exibir();
            break;
            case 4:
                salvar_carregar();
            break;
        }
    }while(op != 0);

    return 0;
}

int adicionar(){
    int matricula, idade, faltas;
    char nome[40], sexo[10];
    float notas[2];
    if (space() == 0){
        printf("\nDesculpe, o sistema esta lotado\n\n");
        system("pause");
        return 1;
    }
    setbuf(stdin, NULL);
    system("cls");
    printf("*******************************************\n");
    printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
    printf("*            ADICIONAR ALUNO              *\n");
    printf("*                                         *\n");
    printf("* Matricula: ");
    scanf("%d", &matricula);
    if(analisar(matricula)){
        printf("* Esta matricula já esta cadastrada       *\n");
        printf("*******************************************\n");
    }
    else{
        setbuf(stdin, NULL);
        printf("\n* Nome: ");
        gets(nome);
        setbuf(stdin, NULL);
        printf("\n* Idade: ");
        scanf("%d", &idade);
        printf("\n* Sexo: ");
        scanf("%s", sexo);
        printf("\n* Avaliação 1: ");
        scanf("%f", &notas[0]);
        printf("\n* Avaliação 2: ");
        scanf("%f", &notas[1]);
        printf("\n* Numero de faltas: ");
        scanf("%d", &faltas);
        notas[2] = verificar_media(notas[0], notas[1], faltas);
        printf("\n* Média Final: %.1f\n", notas[2]);
        setbuf(stdin, NULL);
        printf("*******************************************\n");
        for (int i = 0; i < max; i++)
        {
            if (alunos[i].registro == 0){
                alunos[i].matricula = matricula;
                strcpy(alunos[i].nome, nome);
                alunos[i].idade = idade;
                strcpy(alunos[i].sexo, sexo);
                alunos[i].faltas = faltas;
                for (int j = 0; j < 2; j++){
                    alunos[i].notas[i][j] = notas [j];
                }
                alunos[i].registro = 1;
                break;
            }
        }
    }
    system("pause");
    return 0;
}

void pesquisar(){
    int j=0, matricula;
    char op;
    system("cls");
    setbuf(stdin, NULL);
    printf("*******************************************\n");
    printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
    printf("*             PESQUISAR ALUNO             *\n");
    printf("*                                         *\n");
    printf("* Matrícula para Pesquisa: ");
    scanf("%d", &matricula);
    setbuf(stdin, NULL);
    if (analisar(matricula)){
        for (int i = 0; i < max; ++i)
        {
            if (matricula == alunos[i].matricula)
            {
                printf("\n* Matrícula: %d\n", alunos[i].matricula);
                printf("* Nome: %s\n", alunos[i].nome);
                printf("* Idade: %d\n", alunos[i].idade);
                printf("* Sexo: %s\n", alunos[i].sexo);
                printf("* Avaliação 1: %.1f\n", alunos[i].notas[i][j]);
                printf("* Avaliação 2: %.1f\n", alunos[i].notas[i][j+1]);
                printf("* Numero de Faltas: %d\n",alunos[i].faltas);
                printf("* Média Final: %.1f\n", alunos[i].notas[i][j+2]);
                printf("*******************************************\n");
            }
        }
        system("pause");
    }
    else{
	    setbuf(stdin, NULL);
	    printf("\nEsta matrícula não esta cadastrada\nVocê deseja adicionar esta matrícula no sistema? [S/N] >> ");
	    scanf("%c", &op);
	    setbuf(stdin, NULL);
	    if (toupper(op) == 'S'){
	        adicionar();
	    }
	}
}

int analisar(int m){
    for (int i = 0; i < max; i++){
        if (m == alunos[i].matricula){
            return 1;
        }
    }
    return 0;
}

void exibir(){
    int op;
    do{
        system("cls");
        setbuf(stdin, NULL);
        printf("*******************************************\n");
        printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
        printf("*             EXIBIR ALUNOS               *\n");
        printf("*                                         *\n");
        printf("* [1] Aprovados                           *\n");
        printf("* [2] Reprovados                          *\n");
        printf("* [3] Todos                               *\n");
        printf("* [0] Voltar                              *\n");
        printf("Operação: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op){
            case 1:
                aprovados();
            break;
            case 2:
                reprovados();
            break;
            case 3:
                system("cls");
                printf("*******************************************\n");
                printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
                printf("*            TODOS OS ALUNOS              *\n");
                printf("*                                         *\n");
                for (int i = 0; i < max; i++){
                    int j=0;
                    if (alunos[i].registro == 1){
                        printf("* Matrícula: %d\n", alunos[i].matricula);
                        printf("* Nome: %s\n", alunos[i].nome);
                        printf("* Idade: %d\n", alunos[i].idade);
                        printf("* Sexo: %s\n", alunos[i].sexo);
                        printf("* Avaliação 1: %.1f\n", alunos[i].notas[i][j]);
                        printf("* Avaliação 2: %.1f\n", alunos[i].notas[i][j+1]);
                        printf("* Numero de Faltas: %d\n",alunos[i].faltas);
                        printf("* Média Final: %.1f\n", alunos[i].notas[i][j+2]);
                        printf("*******************************************\n");
                    }
                }
                system("pause");
            break;
        }
    }while(op != 0);
    system("pause");
}

void aprovados(){
    int op;
    do{
        system("cls");
        setbuf(stdin, NULL);
        printf("*******************************************\n");
        printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
        printf("*             ALUNOS APROVADOS            *\n");
        printf("*                                         *\n");
        printf("* [1] Média >=6 E faltas <= 20 \n");
        printf("* [0] Voltar\n");
        printf("Opçãoo: ");
        printf("*******************************************\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op){
            case 1:
            system("cls");
            printf("*******************************************\n");
            printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
            printf("*  ALUNOS COM MÉDIA >= 6 e FALTAS <= 20   *\n");
            printf("*-----------------------------------------*\n");
            for (int i = 0; i < max; i++){
                if (alunos[i].registro == 1){
                    float media;
                    int j=0;
                    media = alunos[i].notas[i][2];
                    if (media >= 6){
                        printf("* Matrícula: %d\n", alunos[i].matricula);
                        printf("* Nome: %s\n", alunos[i].nome);
                        printf("* Idade: %d\n", alunos[i].idade);
                        printf("* Sexo: %s\n", alunos[i].sexo);
                        printf("* Avaliação 1: %.1f\n", alunos[i].notas[i][j]);
                        printf("* Avaliação 2: %.1f\n", alunos[i].notas[i][j+1]);
                        printf("* Numero de Faltas: %d\n",alunos[i].faltas);
                        printf("* Média Final: %.1f\n", alunos[i].notas[i][j+2]);
                        printf("*                                         *\n");
                        printf("*******************************************\n");
                    }
                }
            }
        }
    }while(op != 0);
    system("pause");
}

void reprovados(){
    int j=0, op;
    do{
        system("cls");
        setbuf(stdin, NULL);
        printf("*******************************************\n");
        printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
        printf("*             ALUNOS REPROVADOS           *\n");
        printf("*                                         *\n");
        printf("* [1] Média <6 ou Faltas > 20\n");
        printf("* [0] Voltar\n\n");
        printf("* Opção: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op){
            case 1:
            system("cls");
            printf("*******************************************\n");
            printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
            printf("*   ALUNOS COM MÉDIA 6 ou FALTAS >  20    *\n");
            printf("*-----------------------------------------*\n");
            for (int i = 0; i < max; i++){
                if (alunos[i].registro == 1){
                    int j=0;
                    float media;
                    int faltas = alunos[i].faltas;
                    media = alunos[i].notas[i][2];
                    if (media < 6 || faltas > 20){
                        printf("* Matrícula: %d\n", alunos[i].matricula);
                        printf("* Nome: %s\n", alunos[i].nome);
                        printf("* Idade: %d\n", alunos[i].idade);
                        printf("* Sexo: %s\n", alunos[i].sexo);
                        printf("* Avaliação 1: %.1f\n", alunos[i].notas[i][j]);
                        printf("* Avaliação 2: %.1f\n", alunos[i].notas[i][j+1]);
                        printf("* Numero de Faltas: %d\n",alunos[i].faltas);
                        printf("* Média Final: %.1f\n", alunos[i].notas[i][j+2]);
                        printf("*******************************************\n");
                    }
                }
            }
            system("pause");
            break;
        }
    }while(op != 0);
    system("pause");
}

void salvar_carregar(){
    int op;
    do{
        system("cls");
        setbuf(stdin, NULL);
        printf("*******************************************\n");
        printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
        printf("*        SALVAR/CARREGAR ARQUIVO          *\n");
        printf("*                                         *\n");
        printf("* [1] Salvar\n\n");
        printf("* [2] Carregar\n\n");
        printf("* [0] Voltar\n\n");
        printf("Opçãoo: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch (op){
            case 1:
                salvar();
            break;
            case 2:
                carregar();
            break;
        }
    }while(op != 0);
    system("pause");
}

void salvar(){
    FILE *arq;
    char nome_arq[50];
    int j;
    system("cls");
    setbuf(stdin, NULL);
    printf("*******************************************\n");
    printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
    printf("*              SALVAR ARQUIVO             *\n");
    printf("*                                         *\n");
    setbuf(stdin, NULL);
    printf("* Nome do arquivo: ");
    gets(nome_arq);
    setbuf(stdin, NULL);
    strcat(nome_arq,".txt");
    arq = fopen(nome_arq,"w");
        for (int i = 0; i < max; ++i){
            if (alunos[i].registro == 1){
                j=0;
                fprintf(arq, "Matrícula: %d\n", alunos[i].matricula);
                fprintf(arq, "Nome: %s\n", alunos[i].nome);
                fprintf(arq, "Idade: %d\n", alunos[i].idade);
                fprintf(arq, "Sexo: %s\n", alunos[i].sexo);
                fprintf(arq, "Avaliação 1: %.1f\n", alunos[i].notas[i][j]);
                fprintf(arq, "Avaliação 2: %.1f\n", alunos[i].notas[i][j+1]);
                fprintf(arq, "Numero de Faltas: %d\n",alunos[i].faltas);
                fprintf(arq, "Média Final: %.1f\n\n", alunos[i].notas[i][j+2]);
                fprintf(arq, "*******************************************\n\n");
            }
        }
    fclose(arq);
    system("cls");
    printf("*******************************************\n");
    printf("*       Arquivo salvo com sucesso!        *\n");
    printf("*******************************************\n");
    system("pause");
}

void carregar(){
    FILE *arq;
    char nome_arq[50], n1[50];
    int j;
    for (int i = 0; i < max; ++i){
        alunos[i].registro = 0;}

    system("cls");
    setbuf(stdin, NULL);
    printf("*******************************************\n");
    printf("* CONTROLE DE ALUNOS - ESTRUTURA DE DADOS *\n");
    printf("*              CARREGAR ARQUIVO           *\n");
    printf("*                                         *\n");
    printf("* Nome do arquivo: ");
    gets(nome_arq);
    setbuf(stdin, NULL);
    strcat(nome_arq,".txt");
    arq = fopen(nome_arq,"r");
    if(arq == NULL){
        system("cls");
        printf("*******************************************\n");
        printf("*         Arquivo não encontrado          *\n");
        printf("*******************************************\n");
    }
    else{
        for (int i = 0; i < max; i++){
            j=0;
            while(!feof(arq)){
                fseek(arq,11,1); fscanf(arq,"%d\n", &alunos[i].matricula);
                fseek(arq,6,1); fgets(alunos[i].nome, 40, arq); alunos[i].nome[strlen(alunos[i].nome) - 1] = '\0';
                fseek(arq,7,1); fscanf(arq,"%d\n", &alunos[i].idade);
                fseek(arq,6,1); fscanf(arq,"%s\n", alunos[i].sexo);
                fseek(arq,5,1); fscanf(arq,"%f\n", &alunos[i].notas[i][j]);
                fseek(arq,5,1); fscanf(arq,"%f\n", &alunos[i].notas[i][j+1]);
                fseek(arq,5,1); fscanf(arq," %d\n",&alunos[i].faltas);
                fseek(arq,13,1); fscanf(arq,"%f\n\n", &alunos[i].notas[i][j+2]);
                fseek(arq,0,1); fscanf(arq,"%s\n\n", n1);
                alunos[i].registro = 1;
                break;
            }
        }
        system("cls");
        printf("*******************************************\n");
        printf("*      Arquivo carregado com sucesso!     *\n");
        printf("*******************************************\n");
    }
    fclose(arq);
    system("pause");
}

float verificar_media(float n1, float n2, int faltas){
    float somaDasNotas = n1 + n2;
    float media = somaDasNotas / 2;
    if (media >= 6 && faltas <= 20){
        return 1;
    }else
    {
        return 2;
    }  
    return 0;
}

int space(){
    for (int i = 0; i < max; ++i){
        if (alunos[i].registro == 0){
            return 1;
        }
    }
    return 0;
}
