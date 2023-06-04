// Lista 3
// Elabore um programa onde o usuário armazenará por meio de Structs os dados de "Produtos" 
// e "Fabricantes", serão cadastrados no mínimo 2 fabricantes (máximo 5) e no mínimo 5 produtos 
// (máximo 50).
// Produto: Descrição, peso, valor de compra, valor de venda, valor do lucro (calculado 
// automaticamente), percentual do lucro (calculado automaticamente) e fabricante.
// Fabricante: Marca (nome), site, telefone, UF (todas as unidades da federação previamente 
// cadastradas AC, AM, AP,.., SP, TO).
// Por fim crie um menu para emitir os relatórios abaixo:
// - Utilizem o máximo de funções e procedimentos no estilo "le_valida" para minimizar os erros 
// de cadastros por parte dos usuários.
// Façam bom uso de "tabelas" para apresentação das telas como no exemplo abaixo:
// - O trabalho deverá ser desenvolvido em grupos de até 5 integrantes.
// - Obrigatoriamente os códigos da entrega 3 serão compartilhados pelo github.com . 
// - Somente 1 integrante do grupo deverá enviar a atividade pelo AVA (arquivo .txt contendo 
// os nomes dos integrantes e link do github).
// - Para cada envio de outros integrantes no AVA será descontado 1 ponto do grupo.
// - Entrega 3 – 05/06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 51
#define UF_SIZE 5

// Estrutura do Fabricante
typedef struct {
    char marca[50];
    char site[100];
    char telefone[20];
    char uf[UF_SIZE];
} Fabricante;

// Estrutura do Produto
typedef struct {
    char descricao[100];
    float peso, valorCompra, valorVenda, valorLucro, percentualLucro;
    int fabricanteIndex;
} Produto;

typedef struct {
    char estados[2];
} UFs;

// Função para ler e validar uma string
void lerString(char* string, int tamanho) {
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0'; // Remove a quebra de linha
}

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para ler e validar um número float
float lerFloat() {
    char buffer[20];
    lerString(buffer, sizeof(buffer));
    fflush(stdin);
    return strtof(buffer, NULL);
}

// Função para ler e validar um número inteiro
int lerInt() {
    char buffer[20];
    lerString(buffer, sizeof(buffer));
    fflush(stdin);
    return strtol(buffer, NULL, 20);
}

// Função para cadastrar um fabricante
void cadastrarFabricante(Fabricante* fabricante, int* numFabricantes) {
    printf("Cadastro de Fabricante\n");
    printf("Marca: ");
    lerString(fabricante->marca, sizeof(fabricante->marca));
    printf("Site: ");
    lerString(fabricante->site, sizeof(fabricante->site));
    printf("Telefone: ");
    lerString(fabricante->telefone, sizeof(fabricante->telefone));
    printf("UF: ");
    lerString(fabricante->uf, sizeof(fabricante->uf));
    (*numFabricantes)++;
    printf("Tecle enter para continuar...");
    getchar();
    
}

// Função para cadastrar um produto
void cadastrarProduto(Produto* produto, Fabricante* fabricante, int numFabricantes, int* numProdutos) {
    printf("Cadastro de Produto\n");
    printf("Descricao: ");
    lerString(produto->descricao, sizeof(produto->descricao));
    printf("Peso: ");
    produto->peso = lerFloat();
    printf("Valor de Compra: ");
    fflush(stdin);
    produto->valorCompra = lerFloat();
    printf("Valor de Venda: ");
    fflush(stdin);
    produto->valorVenda = lerFloat();
    fflush(stdin);
    produto->valorLucro = produto->valorVenda - produto->valorCompra;
    produto->percentualLucro = (produto->valorLucro / produto->valorCompra)*100;
    

    // Cadastrar fabricante
    printf("Fabricante (Digite o numero correspondente):\n");fflush(stdin);
    for (int i = 0; i < numFabricantes; i++) {
        fflush(stdin);
        printf("%d - %s\n", i + 1, fabricante[i].marca);
        fflush(stdin);
    }
    
    int opcao;
    do {
        opcao = lerInt();
        if (opcao > 0 && opcao <= numFabricantes) {
            produto->fabricanteIndex = opcao - 1;
        } else {
            printf("Opcao invalida! Digite novamente: ");
        }
    } while (opcao <= 0 || opcao > numFabricantes);
    (*numProdutos)++;
    printf("Tecle enter para continuar...");
    getchar();
}

// Função para exibir relatório de produtos
void exibirRelatorioProdutos(Produto* produtos, Fabricante* fabricante, int numProdutos) {
    printf("Relatorio de Produtos\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\a\n", i + 1);
        printf("Descricao: %s\a\n", produtos[i].descricao);
        printf("Peso: %.2f\a\n", produtos[i].peso);
        printf("Valor de Compra: %.2f\a\n", produtos[i].valorCompra);
        printf("Valor de Venda: %.2f\a\n", produtos[i].valorVenda);
        printf("Valor do Lucro: %.2f\a\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\a\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\a\n", fabricante[produtos[i].fabricanteIndex].marca);
        printf("\a\n");

    }

    
}


// Função para exibir relatório de produtos por Estado
void exibirRelatorioProdutosporEstado(Produto* produtos, Fabricante* fabricante, int numProdutos) {
    printf("Relatorio de Produtos por Estado\n");
    for (int i = 0; i < numProdutos; i++) {
        
        printf("%d - %s \n", i+1, fabricante[i].uf);
        
        printf("\a\n");

    }
}

void exibirRelatorioFabricantes(Fabricante* fabricante, int numFabricantes) {
    printf("Relatorio de Produtos\n");
    for (int i = 0; i < numFabricantes; i++) {
        printf("Fabricante %d:\n", i + 1);
        printf("Marca do fabricante: %s\n", fabricante[i].marca);
        printf("Site do fabricante: %s\n", fabricante[i].site);
        printf("Telefone do fabricante: %s\n", fabricante[i].telefone);
        printf("UF do fabricante %s\n\n", fabricante[i].uf);
    }
}

int main() {
    Fabricante fabricantes[MAX_FABRICANTES];
    Produto produtos[MAX_PRODUTOS];
    int numFabricantes = 0;
    int numProdutos = 0;

    int opcao;
    do {
        printf("MENU\n");
        printf("1 - Cadastrar Fabricante\n");
        printf("2 - Cadastrar Produto\n");
        printf("3 - Exibir Relatorio de Produtos\n");
        printf("4 - Exibir Fabricantes\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        opcao = lerInt();

        switch (opcao) {
            case 1:
                if (numFabricantes <= MAX_FABRICANTES) {
                    cadastrarFabricante(&fabricantes[numFabricantes], &numFabricantes);
                    printf("Fabricante cadastrado com sucesso!\n");
                } else {
                    printf("Numero maximo de fabricantes atingido!\n");
                }
                break;
            case 2:
                if (numProdutos <= MAX_PRODUTOS) {
                    cadastrarProduto(&produtos[numProdutos], fabricantes, numFabricantes, &numProdutos);
                    printf("Produto cadastrado com sucesso!\n");
                } else {
                    printf("Numero maximo de produtos atingido!\n");
                }
                break;
            case 3:
                if (numProdutos > 0) {
                    exibirRelatorioProdutos(produtos, fabricantes, numProdutos);
                } else {
                    printf("Nenhum produto cadastrado!\n");
                }
                break;
            
                case 4:
                if (numFabricantes > 0) {
                    exibirRelatorioFabricantes(fabricantes, numFabricantes);
                } else {
                    printf("Nenhum produto cadastrado!\n");
                }
                break;


            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        printf("\a\n");
    } while (opcao != 0);

    return 0;
}
