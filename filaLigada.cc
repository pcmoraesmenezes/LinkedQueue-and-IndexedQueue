#include <iostream> // incluindo a biblioteca basica de c++
using namespace std; // habilita o uso das funções cout e cin sem precisar do std ::
typedef struct no{ // criando uma struct
    int valor; // variavel que irá receber o valor da fila
    no * proximo_no; // variavel que será responsavel para ir para o proximo elemento
}no; // nome da struct
typedef struct fila{ // criando uma struct
    no * primeiro_elemento; // variavel do tipo no que recebe o primeiro elemento
    no * ultimo_elemento; // variavel do tipo no que recebe o ultimo elemento
} fila;//nome da strucy
fila * cria_fila() // função que irá alocar na memoria a fila, ou seja criará a fila!
{
    fila * p = new fila; // aqui estamos criando uma variavel p do tipo fila e estamos fazendo ela receber o tamanho da fila
    p->primeiro_elemento = NULL; // aqui estamos fazendo com que o primeiro elemento aponte para nulo pois estamos inicializando a fila, ou seja não há nenhum elemento
    p->ultimo_elemento = NULL;// o mesmo para essa variavel, não há nenhum elemento
    return p; // retornamos a variavel p criada
}  
void enqueue(fila * p, int valor) // função que será responsavel por inserir os elementos na fila! recebe dois parametros uma variavel do tipo fila e uma variavel valor
{
    no * novo_no = new no; // criando uma variavel do novo_no do tipo no e atribuindo o tamanho do no a ela
    novo_no->valor = valor; // aqui estamos fazendo o novo_no apontado para valor receber valor ou seja essa variavel armazenará o valor inserido pelo ususario
    novo_no->proximo_no = NULL; // o proximo elemento é null pois não há nada depois do valor inserido
    if(p->ultimo_elemento == NULL) // condição que verifica se o ultimo elemento é null
        p->primeiro_elemento = p->ultimo_elemento = novo_no; // se o ultimo elemento e null então ele receberá o valor inserido pelo usuario
    p->ultimo_elemento->proximo_no = novo_no; // aqui estamos fazendo o ultimo elemento apontado para o proximo no receber novo no
    p->ultimo_elemento = novo_no; // a struct ultimo elemento recebe novo no
}
no * dequeue(fila * p) // função que irá remover o primeiro elemento inserido na fila, recebe uma variavel do tipo fila
{
    if(p->primeiro_elemento == NULL)// verifica se a fila esta vazia
    {   printf("Fila vazia! \n"); // retorna uma mensagem na tela
        return 0; // retorna 0
    }
    no * remove_no = p->primeiro_elemento; // se a fila não estiver vazia entao criaremos uma variavel que armazenara o valor removido na fila
    printf("O elemento removido foi: %d \n", remove_no->valor); // estamos informando qual valor foi removido
    p->primeiro_elemento = p->primeiro_elemento->proximo_no; // estamos fazendo o primeiro elemento, ou seja o elemento que foi removido receber o proximo elemento
    if(p->primeiro_elemento == NULL) // aqui estamos verificando se há elementos na variavel pois fazemos ela deslocar para o proximo elemento na parte de cima
    {
        p->ultimo_elemento = NULL; // se a condição for verdadeira então não há elementos então devemos fazer o ultimo elemento ser null
    }
    delete remove_no; // removendo o lixo de memoria
}
void imprime(fila * p) // função para imprimir a fila recebe como parametro uma variavel do tipo fila
{
  if (p->primeiro_elemento == NULL)  // condição que verifica se há elementos na fila
  {
    cout << "Fila vazia!" << endl; // mensagem na tela caso verdade
    return; // encerra a função
  }
  no * atual = p->primeiro_elemento; // aqui estamos criando uma variavel atual do tipo no e estamos fazendo ela receber o primeiro elemento
  while (atual != p->ultimo_elemento) // essa estrutura de repetição está comparando o atual com o ultimo elemento, se o ultimo elemento for igual ao atual ele encerra o laço
   {
    cout << atual->valor << " "; // mensagem na tela 
    atual = atual->proximo_no; // estamos andando com o atual para o proximo elemento
  }
  cout << atual->valor << endl; // estamos exibindo o ultimo elemento
}


int main() // corpo principal
{
   fila * p = cria_fila(); // estamos inicializando nossa fila
   int navegador = 0; // essa variavel será responsavel por guiar o usuario na interface
    int adicionar = 0; // variavel responsavel por receber o numero que o usuario gostaria de inserir na fila
    while (true) // essa condição faz com que o laço de repetição seja sempre verdade
   { 
        printf("Bem vindo a sua fila! Para visualizar a sua fila digite '1', para inserir um valor em sua fila digite '2', para remover o primeiro elemento adicionado da sua fila digite '3' e para sair digite '4'\n"); // mensagem para o usuario
        scanf("%d", &navegador); // está recebendo do usuario um numero para ação
        while (navegador != 1 && navegador != 2 && navegador != 3 && navegador != 4) // verifica se o usuario digitou algo além do que esperado
        {
            printf("Você não informou uma opção válida! Tente novamente \n"); // informa que ele não digitou uma opção válida das que foram ofertadas
            scanf("%d", &navegador);// recebe do usuario outra opção
        }
        if (navegador == 1) // verifica se ele escolheu a opção 1
        {
            if(p->primeiro_elemento == NULL) // verifica se a fila está vazia
            {
                printf("Fila vazia ! \n"); // retorna uma mensagem
            }
            else{ // senao
            printf("Você optou por visualizar a fila!\n "); // retorna uma mensagem
            imprime(p); // imprime a fila na tela
            }
        }
        if (navegador == 2) // verifica se ele optou pela opção 2
        {
            printf("Você optou por inserir! Por favor insira o numero abaixo: \n"); // retorna uma mensagem
            scanf("%d", &adicionar); // recebe do usuario um numero a ser adicionado
            enqueue(p, adicionar); // chamando a função que adiciona elementos na fila
        }
        if (navegador == 3) // verifica se o usuario optou pela opção 3
        {
            if(p->primeiro_elemento == NULL) // verifica se a fila está vazia
            {
                printf("Fila vazia! \n"); // retorna uma mensagem
            }
            else // senao
            {
              printf("Você optou por remover o primeiro elemento!\n "); // imprime uma mensagem na tela
              dequeue(p); // chama a função que remove o primeiro elemento inserido na fila
              imprime(p);  // imprime a fila na tela
            }
        }
        if (navegador == 4) // verifica se o usuario optou pela opção 4
        {   printf("Você optou por sair da fila! \n"); // retorna uma mensagem
            break; // quebra o laço de repetição
        }
    }
}