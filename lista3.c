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
#include <string.h>

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define MIN_FABRICANTES 2
#define MIN_PRODUTOS 2

struct Fabricante {
    char marca[50];
    char site[100];
    char telefone[15];
    char uf[3];
};

struct Produto {
    char descricao[100];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    struct Fabricante fabricante;
};

void leValidaFabricante(struct Fabricante *fabricante) {
    printf("Marca: ");
    scanf(" %[^\n]", fabricante->marca);

    printf("Site: ");
    scanf(" %[^\n]", fabricante->site);

    printf("Telefone: ");
    scanf(" %[^\n]", fabricante->telefone);

    printf("UF: ");
    scanf(" %[^\n]", fabricante->uf);
}

void leValidaProduto(struct Produto *produto) {
    printf("Descrição: ");
    scanf(" %[^\n]", produto->descricao);

    printf("Peso: ");
    scanf("%f", &produto->peso);

    printf("Valor de compra: ");
    scanf("%f", &produto->valorCompra);

    printf("Valor de venda: ");
    scanf("%f", &produto->valorVenda);

    // Calcula o lucro e percentual de lucro automaticamente
    produto->valorLucro = produto->valorVenda - produto->valorCompra;
    produto->percentualLucro = (produto->valorLucro / produto->valorCompra) * 100;

    leValidaFabricante(&(produto->fabricante));
}

void cadastrarFabricantes(struct Fabricante fabricantes[], int *numFabricantes) {
    for (int i = 0; i < *numFabricantes; i++) {
        printf("Fabricante %d\n", i + 1);
        leValidaFabricante(&(fabricantes[i]));
    }
}

void cadastrarProdutos(struct Produto produtos[], int *numProdutos) {
    for (int i = 0; i < *numProdutos; i++) {
        printf("Produto %d\n", i + 1);
        leValidaProduto(&(produtos[i]));
    }
}

void exibirRelatorioProdutos(const struct Produto produtos[], int numProdutos) {
    printf("RELATÓRIO DE PRODUTOS\n");
    for (int i = 0; i < numProdutos; i++) {
        const struct Produto *produto = &produtos[i];
        printf("Produto %d\n", i + 1);
        printf("Descrição: %s\n", produto->descricao);
        printf("Peso: %.2f\n", produto->peso);
        printf("Valor de compra: %.2f\n", produto->valorCompra);
        printf("Valor de venda: %.2f\n", produto->valorVenda);
        printf("Valor do lucro: %.2f\n", produto->valorLucro);
        printf("Percentual do lucro: %.2f%%\n", produto->percentualLucro);
        printf("Fabricante:\n");
        printf("  Marca: %s\n", produto->fabricante.marca);
        printf("  Site: %s\n", produto->fabricante.site);
        printf("  Telefone: %s\n", produto->fabricante.telefone);
        printf("  UF: %s\n\n", produto->fabricante.uf);
    }
}

void exibirRelatorioFabricantes(const struct Fabricante fabricantes[], int numFabricantes) {
    printf("RELATÓRIO DE FABRICANTES\n");
    for (int i = 0; i < numFabricantes; i++) {
        const struct Fabricante *fabricante = &fabricantes[i];
        printf("Fabricante %d\n", i + 1);
        printf("Marca: %s\n", fabricante->marca);
        printf("Site: %s\n", fabricante->site);
        printf("Telefone: %s\n", fabricante->telefone);
        printf("UF: %s\n\n", fabricante->uf);
    }
}

int main() {
    int numFabricantes, numProdutos;

    do {
        printf("Quantidade de fabricantes (entre %d e %d): ", MIN_FABRICANTES, MAX_FABRICANTES);
        scanf("%d", &numFabricantes);
        getchar(); // Limpa o buffer do teclado
    } while (numFabricantes < MIN_FABRICANTES || numFabricantes > MAX_FABRICANTES);

    struct Fabricante fabricantes[MAX_FABRICANTES];

    do {
        printf("Quantidade de produtos (entre %d e %d): ", MIN_PRODUTOS, MAX_PRODUTOS);
        scanf("%d", &numProdutos);
        getchar(); // Limpa o buffer do teclado
    } while (numProdutos < MIN_PRODUTOS || numProdutos > MAX_PRODUTOS);

    struct Produto produtos[MAX_PRODUTOS];

    int opcao;
    do {
        printf("MENU\n");
        printf("1. Cadastrar Fabricantes\n");
        printf("2. Cadastrar Produtos\n");
        printf("3. Exibir relatório de produtos\n");
        printf("4. Exibir relatório de fabricantes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                cadastrarFabricantes(fabricantes, &numFabricantes);
                break;
            case 2:
                cadastrarProdutos(produtos, &numProdutos);
                break;
            case 3:
                exibirRelatorioProdutos(produtos, numProdutos);
                break;
            case 4:
                exibirRelatorioFabricantes(fabricantes, numFabricantes);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}
