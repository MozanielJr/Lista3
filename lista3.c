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

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50

int main(){


struct Uf

{
    char estado[2];
};

struct Fabricante
{
    char marca[20];
    char site[20];
    char telefoneFixo[11];
    char telefoneCelular[12];
    struct Uf uf;

};


struct Produtos
{
    char descricao[100];
    float peso;
    float valorDeCompra;
    float valorDeVenda;
    float valorDoLucro;
    float percentualDoLucro;
    struct Fabricante fabricante[MAX_FABRICANTES];
};





}