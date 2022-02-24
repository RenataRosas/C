#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
/**
 *
 * Exemplo de utilizacao de pilha em C
 *
 * Angelito M. Goulart
 *
 * www.angelitomg.com
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definicao da estrutura da pilha
struct pilha{
        int dados;
        struct pilha *prox;
};

// Prototipo das funcoes
int empilha(struct pilha **p, int v);
struct pilha *desempilha(struct pilha **p);

/**
 * Funcao main
 */
int main()
{
        
        // Topo da pilha
        struct pilha *p = NULL;

        // Ponteiro para armazenar um elemento desempilhado
        struct pilha *desempilhado = NULL;
        
        // Variaveis auxiliares
        int i, n;

        // Semeia o gerador de numeros aleatorios
        srand(time(NULL));

        printf("Empilhando...\n");

        // Laco para sortear 15 valores aleatorios
        for (i = 1; i <= 15; i++){

                // Sorteio de um valor aleatorio Entre 1 e 50
                n = (rand() % 50) + 1;

                // Empilha o valor sorteado
                empilha(&p, n);
                printf("Empilhado: %d\n", n);
        }

        printf("Desempilhando...\n");   

        // Desempilha e imprime todos os valores da pilha
        while ((desempilhado = desempilha(&p)) != NULL){
                printf("Desempilhado: %d\n", desempilhado->dados);
        } 

}

/**
 * Funcao responsavel por empilhar um valor na pilha. Recebe como
 * parametros um ponteiro para um ponteiro para o primeiro elemento da pilha 
 * e o valor a ser empilhado.
 */
int empilha(struct pilha **p, int v)
{

        // Ponteiro para o novo elemento a ser alocado
        struct pilha *novo = NULL;

        // Aloca o novo elemento
        novo = (struct pilha *) malloc(sizeof(struct pilha));

        // Verifica se a alocacao teve exito
        if (novo != NULL){

                // Adiciona o valor ao novo elemento
                novo->dados = v;

                // Verifica se a pilha esta vazia, se estiver vazia, o ponteiro
                // para o proximo elemento sera NULL
                if (*p == NULL){
                        novo->prox = NULL;
                } else {

                        // Caso contrario, o novo elemento assume o topo, e o proximo
                        // elemento para a ser o antigo topo
                        novo->prox = *p;
                }

                // O topo passa a ser o novo elemento
                *p = novo;

        } else {
                printf("Erro ao alocar memoria!\n");
                return 1;
        }       

        return 0;

}

/**
 * Funcao responsavel por desempilhar um valor da pilha. Recebe como parametro
 * um ponteiro para um ponteiro para o primeiro elemento da pilha
 */
struct pilha *desempilha(struct pilha **p)
{

        // Variavel que armazenara o valor desempilhado temporariamente
        struct pilha tmp; 

        // Ponteiro auxiliar
        struct pilha *aux = NULL;

        // Ponteiro para o elemento que sera desempilhado
        struct pilha *del = NULL;

        // Se a pilha nao estiver vazia...
        if (*p != NULL){

                // Aloca o elemento que recebera o valor a ser desempilhado
                aux = (struct pilha *) malloc(sizeof(struct pilha));

                // Obtem o valor do elemento desempilhado
                tmp = **p;

                // Armazena um ponteiro para o valor do elemento desempilhado
                aux = &tmp;

                // Armazena o endereco do elemento a ser excluido
                del = *p;

                // Altera o topo para o proximo elemento da pilha
                *p = (*p)->prox;

                // Exclui o elemento desempilhado
                free(del);

                // Retorna o ponteiro para o valor desempilhado
                return aux;

        } else {
                return NULL;
        }}
