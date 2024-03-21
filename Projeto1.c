#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de textos por região
#include <string.h> // Biblioteca responsável por cuidar das strings

int cadastrar() // Função responsável por cadastrar os usuários no sistema
{
    // Início criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação de variáveis/string

    printf("Digite o CPF a ser cadastrado:  "); // Coletando informação do usuário
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings

    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
    fprintf(file, "%s", cpf); // Salva o valor da variável
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o seu cargo para ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("Usuário cadastrado com sucesso!\n");

    system("read");
    system("clear");
}

int consultar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:  ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado!\n");
    }
    else
    {
        while (fgets(conteudo, 200, file) != NULL)
        {
            printf("\nEssas são as informações do usuário: ");
            printf("%s", conteudo);
            printf("\n\n");
        }
    }
    fclose(file); // Fechando o arquivo

    system("read");
    system("clear");
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    // Remover o arquivo
    if (remove(cpf) == 0)
    {
        printf("O usuário com CPF %s foi deletado com sucesso.\n", cpf);
    }
    else
    {
        FILE *file;
        file = fopen(cpf, "r");

        if (file == NULL)
        {
            printf("\n\nO usuário não se encontra no sistema!\n");
        }

        fclose(file);

        system("read");
        system("clear");
    }
}

int main()
{
    int opcao = 0; // Definindo variáveis

    char senhadigitada[10];

    printf("### Cartório da EBAC ###\n\n");
    printf("Login do administrador!!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    if (strcmp(senhadigitada, "admin") == 0) // Corrigindo a condição do if
    {
        system("clear");
        while (1)
        {
            setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem

            printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - incluir nomes\n");
            printf("\t2 - consultar nomes\n");
            printf("\t3 - deletar nomes\n");
            printf("\t4 - sair do sistema\n\n");
            printf("Opção: "); // Fim do menu

            scanf("%d", &opcao); // Armazenando a escolha do usuário

            system("clear"); // Limpar o sistema apos a seleção do usuário

            switch (opcao) // Inicio da seleção do menu
            {
            case 1:
                cadastrar(); // Chamada de funções
                break;

            case 2:
                consultar();
                break;

            case 3:
                deletar();
                break;

            case 4:
                printf("Obrigado por utilizar nosso aplicativo!\n");
                return 0; // Retornando 0 para encerrar o programa corretamente
                break;

            default:
                printf("Essa opção não está disponível!\n");
                system("read");
                break;
            }
        }
    }
    else
    {
        printf("Senha incorreta. Tente novamente.\n");
    }

    return 0;
}