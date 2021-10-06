#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include<string.h>

#pragma warning(disable : 4996) //Visual studio fica dando este erro, desabilitei. nao achei solucao

#define MAX 100

struct PlayList { // struc criada apartir da aula 2
    char* nome;
    int duracao;
    char* artista;
}Head[MAX];

void exibirMenu() { // MENU 
    setlocale(LC_ALL, "Portuguese");
    printf("\n\tSelecione umas das opções a seguir:\n");
    printf("\t01 - Inserir nova Musica\n"
        "\t02 - Listar Musicas\n"
        "\t03 - Tocar musica\n" //Opcao nao implementada
        "\t99 - Sair\n\n");
}

char* alocarMemoria(int tamanho) {
    char* info = NULL;
    info = (char*)malloc(sizeof(tamanho) * sizeof(char));

    if (info == NULL) {
        printf("ERRO: impossível alocar a quantidade de memória requisitada!");
        exit(1);
    }
    return info;
}

void cadastrarMusica(int registro) {
    char dados[MAX];
    printf("\n\t\tNome: ");
    scanf_s("%[^\n]s", dados, _countof(dados));
    setbuf(stdin, NULL);
    Head[registro].nome = alocarMemoria(strlen(dados)); // alocacao e copia de dados
    strcpy(Head[registro].nome, dados);

    printf("\t\tDuracao: ");
    scanf_s("%d", &Head[registro].duracao);
    setbuf(stdin, NULL);

    printf("\t\tBanda: ");
    scanf_s("%[^\n]s", dados, _countof(dados));
    setbuf(stdin, NULL);
    Head[registro].artista = alocarMemoria(strlen(dados)); // alocacao e copia de dados
    strcpy(Head[registro].artista, dados);

}
// funcao para listar musicas alocadas na struct
void listarMusica(int qtdeMusica) {
    int i;
    int contagem = 1;
    for (i = 0; i < qtdeMusica; i++) {
        printf("\n\tMusica nº: %d\n", contagem++);
        printf("\tNome: %s\n", Head[i].nome);
        printf("\tDuracao: %d\n", Head[i].duracao);
        printf("\tBanda: %s\n", Head[i].artista);
    }
    printf("\n\n");
}

void exibirMusica(int indice) {
    printf("\n\tNome: %s\n", Head[indice].nome);
    printf("\tDuracao: %d\n", Head[indice].duracao);
    printf("\tBanda: %s\n", Head[indice].artista);
}

int pesquisarMusica(int qtdeMusica, char* nomeBuscado) {
    int i;

    for (i = 0; i < qtdeMusica; i++) {
        if (strcmp(nomeBuscado, Head[i].nome) == 0)
            return i;
    }
    return -1;
}


int leitor() {
    int opcao;

    printf("\n\tOpção escolhida: ");
    scanf_s("%d", &opcao);
    setbuf(stdin, NULL);

    return opcao;
}

int main() { // funcao do menu com switch
    char nome[MAX];
    int numeroRegistro = 0;
    int opcaoEscolhida;
    int indice;

    do {
        exibirMenu();
        opcaoEscolhida = leitor();

        switch (opcaoEscolhida) {
        case 1:
            cadastrarMusica(numeroRegistro++);
            break;
        case 2:
            listarMusica(numeroRegistro);
            break;
        case 99:
            printf("\n\tSaindo...");
            break;
        default:
            printf("Tocando musica..."); // Nao foi implementadado esta funcao
            exibirMenu();
            opcaoEscolhida = leitor();
        }

    } while (opcaoEscolhida != 99);
}
