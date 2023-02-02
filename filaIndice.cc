#include <iostream> // incluindo a biblioteca basica do c++
using namespace std; // permite que usemos o cin e cout sem ter que usar o std::
const int MAX_SIZE = 100; // estamos definindo um limite maximo para nossa fila pois estaremos usando indices 
typedef struct fila // criando uma struct
{
    int indice = 0; // variavel que recebera o valor 
    int front = -1; // o indice do primeiro  elemento da fila
    int fila[MAX_SIZE]; // array com tamanho maximo pre definido
}fila; // nome da struct
int enqueue(fila * p, int valor) // função que ira inserir elementos na fila, recebe como parametro uma variavel do tipo fila e o valor inserido
{
    if(p->indice == MAX_SIZE) // condição que verifica se a fila tem tamanho maximo
    {
        printf("Fila cheia! \n"); // se tiver retonar uma mensagem ao usuario
        return -1; // encerra o codigo
    }
    else if(p->front == -1) // fila vazia
    {
      p->front = 0; //estamos fazendo o primeiro elemento da fila receber 0
      p->fila[p->indice] = valor; // estamos fazendo o array armazenar o valor recebido na posição do indice, ou seja no tamanho
      p->indice = p->indice + 1; // incrementando o indice
      return valor; // retornando o valor inserido
    }
    else{ // se nao
        p->fila[p->indice] = valor; // o array esta armazenando o valor recebido na posição do indice
        p->indice = p->indice + 1; // incrementando o indice
        return valor; // retornando o valor inserido
    }
}
int dequeue(fila * p) // função que ira remover o primeiro elemento da fila , recebe como parametro uma variavel do tipo fila
{
    if (p->indice == 0) // condição que verifica se a fila esta vazia
    {
        printf("Fila vazia! \n"); // imprime uma mensagem na tela para o usuario
        return -1; // encerra o codigo
    }
    else // se nao
    {
       int valor_removido = p->fila[p->front]; // estamos armazenando o valor removido nessa variavel 
       for(int i = p->front;i <  p->indice - 1; i++) // uma repetição para movermos os valores
       {
            p->fila[i] = p->fila[i+1]; // estamos fazendo o primeiro elemento ir para o segundo e o segundo para o terceiro até o fim da fila
       }
       printf("O numero removido foi [%d] \n", valor_removido); // exibindo uma mensagem na tela
       p->indice--; // decrementando o indice
       return valor_removido; // encerrando a fila
    }
}
void imprimeFila(fila * p) // função para imprimir a fila, recebe como parametro uma variavel do tipo fila
{
    for(int i = 0; i < p->indice; i++) // repetição que ira imprimir os valores até o tamanho atual da fila
    {
        printf("[%d]-> ", p->fila[i]); // mensagem na tela
    }
    printf("\n"); // quebra de linha
}
int main() // corpo principal do codigo
{
    fila minha_fila; // criando uma variavel do tipo fila
    int navegador = 0; // variavel para movermos na main
    int numero_adicionado = 0; // variavel que recebera o valor que o usuario quer inserir
    while(true) // estrutura de repetição que sempre será verdadeira
    {
        printf("Bem vindo a sua fila! Para adicionar um elemento digite '1', para remover o primeiro elemento digite '2', para visualizar a sua fila digite '3' e para sair digite '4'\n");// mensagem na tela
        scanf("%d", &navegador); // recebendo do usuario o que ele deseja fazer
        while(navegador != 1 && navegador != 2 && navegador != 3 && navegador != 4) // verificando se o usuario digitou as opções corretamente
        {
            printf("\n Você não informou uma opção valida tente novamente! \n"); // exibindo uma mensagem de erro
            scanf("%d", &navegador); // pedindo para ele digitar novamente a opção
        }
        if(navegador == 1) // verifica se o usuario optou pela opção 1
        {
            printf("Você optou por inserir! Insira um numero abaixo! \n"); // mensagem na tela
            scanf("%d", &numero_adicionado ); // recebe do usuario o numero a ser inserido
            enqueue(&minha_fila, numero_adicionado); // chamando a função para inserir na fila o elemento a ser inserido
        }
        if(navegador == 2) // verifica se o usuario optou pela opção 2 
        {
            printf("Você optou por remover o primeiro elemento! \n"); // mensagem na tela
            if(minha_fila.front == -1) // verifica se a fila esta vazia
            {
                printf("Fila vazia! \n"); // mensagem na tela
            }
            else{ // se nao estiver vazia
                dequeue(&minha_fila); // remove o primeiro elemento inserido
            }
        }
        if(navegador == 3) // verifica se o usuario optou pela opção 3
        {
            printf("Você optou por visualizar a fila! \n"); // mensagem na tela
            if(minha_fila.front == -1) // verifica se a fila esta vazia
            {
                printf("Fila vazia! \n"); // retorna uma mensagem
            }
            else{ // se nao 
            imprimeFila(&minha_fila);// chama a função imprime fila para imprimir os valores da fila
            }
        }
        if(navegador == 4) // verifica se o usuario optou pela opção 4
        {
            printf("Você optou por sair!\n"); // mensagem na tela
            break; // encerra a repetição e o codigo
        }
    }
}