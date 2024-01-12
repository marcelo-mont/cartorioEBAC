#include <stdio.h>  //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsavel pelas string

int registro() // Função responsável por cadastrar os usuários no sistema
{
    // Início criação de variáveis/string
    setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação de variáveis/string

    printf("Você escolheu o registro de nomes! Por favor, digite o CPF a ser cadastrado:\n"); // Coletando informação do usuário
    scanf("%s", cpf);                                                                         // Armazena valor tipo string na variavel cpf

    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings

    FILE *file;                 // Cria o arquivo
    file = fopen(arquivo, "w"); // Abre e escreve no arquivo
    fprintf(file, cpf);         // Salva o valor na variavel cpf
    fclose(file);               // Fecha o arquivo

    file = fopen(arquivo, "a"); // Altera o arquivo acrescentando vírgula
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado:\n");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado:\n");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado:\n");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    printf("Obrigado, seu registro está completo!");
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
    char cpf[40];
    char conteudo[200];

    printf("Você escolheu consultar os nomes! Por favor, digite o CPF a ser consultado:\n");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r"); // Lê a variavel no arquivo

    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado!.\n");
    }

    while (fgets(conteudo, 200, file) != NULL) // Laço de repetiçao para realizar busca no banco de dados
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int apagar()
{
    char cpf[40];

    printf("Por favor, digite o CPF a ser apagado:");
    scanf("%s", cpf);

    remove(cpf); // Apaga o arquivo com a primary key cpf

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) // Condicional pro caso do cpf informado não constar no banco de dados
    {
        printf("O usuário não se encontra no sistema!.\n");
        system("pause");
    }
    else
    {
        printf("CPF apagado com sucesso!.\n");
        system("pause");
    }
}

int main()
{
    int opcao = 0; // Definindo variáveis
    int laco = 1;
    char senhadigitada[30] = "a";
    int comparacao;

    printf("### Cartório EBAC! ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    comparacao = strcmp(senhadigitada, "admin");

    if (comparacao == 0)
    {
        system("cls");
        for (laco = 1; laco = 1;)
        {
            system("cls"); // Responsável por limpar a tela

            setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem

            printf("### Olá Mundo! Boas Vindas ao Cartório EBAC! ###\n\n"); // Início do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar Nomes\n");
            printf("\t2 - Consultar Nomes\n");
            printf("\t3 - Apagar Nomes\n");
            printf("\t4 - Sair do sistema\n\n"); // Fim do menu

            scanf("%d", &opcao); // Armazenando a escolha do usuário

            system("cls");

            switch (opcao) // Início da seleção do menu
            {
            case 1:
                registro(); // Chamada de funções
                break;      // Encerra processos desse case

            case 2:
                consulta();
                break;

            case 3:
                apagar();
                break;

            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
                break;

            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
            } // Fim da seleção
        }
    }
    else
        printf("Senha incorreta!");
}