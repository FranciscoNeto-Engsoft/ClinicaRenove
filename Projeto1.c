#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória 
#include <locale.h> //Biblioteca de alocação de textos por região 
#include <string.h> //Biblioteca responsável por cuidar das strings

int cadastrar() //Função responsável por cadastrar os usuários no sistema
{
    //inicio criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string

    printf("Digite o CPF a ser cadastrado:  "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); //Responsável por copiar os valores das string 

    FILE *file; //cria o arquivo 
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variável
    fclose(file); //fecho o arquivo

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o seu cargo para ser cadastrado: ");
    scanf("%s",cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("read");
    system("clear");
     
}


  
int consultar()
{
   
    setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
   
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:  ");
    scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");

    if(file == NULL)
{
    printf("Não foi possível abrir o arquivo, não localizado!.\n");
}   else {
    while(fgets(conteudo, 200, file) != NULL)
    
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    
    }
    fclose(file); // fechando o arquivo

    system("read");
    system("clear");



   



}
int deletar()
{
  char cpf[40];
  
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    // Remover o arquivo
    if (remove(cpf) == 0) {
        printf("O usuário com CPF %s foi deletado com sucesso.\n", cpf);
    } 
        else {
        FILE *file;
        file = fopen(cpf, "r");

        if (file == NULL) {
            printf("\n\nO usuário não se encontra no sistema!\n");
        }

        fclose(file);

        system("read");
        system("clear");
    }
    
}

int main()
   {
   int opcao=0; //Definindo variáveis
   int x=1;

    for(x=1;x=1;)
   { 

        setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
    
        printf("### Cartório da EBAC ###\n\n"); //Inicio do menu 
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - incluir nomes\n");  
        printf("\t2 - consultar nomes\n");
        printf("\t3 - deletar nomes\n\n");
        printf("Opção: "); //Fim do menu
    
        scanf("%d", &opcao); //Armazenando a escolha do usuário
    
        system("clear"); //Limpar o sistema apos a seleção do usuário

        switch(opcao) //inicio da seleção do menu
        {
        case 1:
        cadastrar(); //chamada de funções
        break;
    
        case 2:
        consultar();
        break;

        case 3:
        deletar();
        break;

        default:
        printf("Essa opção não está disponível!\n");
        system("read");
        break;
        }
     }
    }
