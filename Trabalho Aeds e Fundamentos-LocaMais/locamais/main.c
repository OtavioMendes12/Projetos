#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <time.h>
#include <math.h>


struct tCliente
{
    int cpfCliente;
    char nome[50];
    int pontosFidelidade;
    int diaDevolucao;
    int dia;
    float preco;
    float precoTotal;
    int locacoes;
    int resposta;
    int numtelefone;
    char endereco[50];
};


struct tVeiculos
{
    char cor[50];
    int codigo;
    char modelo[50];
    float preco;
    float precoTotalcarro;
    char status[50];
    int placanum;
    char placaletra[30];
    int ocupantes;
};

struct tLocacao
{
    int codigo_locacao;
    int data_retirada;
    int data_devolucao;
    int seguro;
    int quantDias;
    int cod_cliente;
    int cod_veiculo;
    float precoLoc;
    float precoLocTotal;
    int dataDevolucaocliente;
    char carro[40];

};





int menuprincipal();
void cadastCliente();
void cadastVeiculo();
void listar();
void consultar();
void fidelidade();
void alterar();
void baixa_locacao();
void cadastrarLoc();





int main(void)
{
    setlocale(LC_ALL,"Portuguese");
    int op;

    do
    {
        op = menuprincipal();
        switch (op)
        {

        case 1:
            printf("----Aba Clientes----\n");
            cadastCliente();
            break;

        case 2:
            printf("----Aba Veículos----\n");
            cadastVeiculo();
            break;
        case 3:
            printf("----Cadastro de Locação----\n");
            cadastrarLoc();
            break;

        case 4:
            printf("----Clientes cadastrados----\n");
            listClientes();
            break;

        case 5:
            printf("----Veículos cadastrados----\n");
            listVeiculos();
            break;

        case 6:
            printf("-----Listar Informações já cadastradas----\n");
            listInfos();
            break;

        case 7:
            printf("----Consultar Cliente----\n");
            consultCliente();
            break;

        case 8:
            printf("----Consultar Veículos----\n");
            consultVeiculos();
            break;

        case 9:
            printf("\n----Fidelidade----\n");
            fidelidade();

            break;
        case 10:
            printf("----Baixa em Locação----\n");
            baixa_locacao();
            break;

        case 11:
            printf("----Alterar----\n");
            alterar();
            break;



        }
    }
    while (op != 0);

    system("pause");
    return 0;
}


int menuprincipal (void)
{

    int opcao;
    do
    {
        printf("\n\n--------------------------!SEJA BEM-VINDO!----------------------------\n");
        printf("\n---------------------------Cadastro de cliente----------------(Digite 1)\n");
        printf("\n---------------------------Cadastro de veículo----------------(Digite 2)\n");
        printf("\n---------------------------Cadastro de Locação----------------(Digite 3)\n");
        printf("\n---------------------------Listar clientes--------------------(Digite 4)\n");
        printf("\n---------------------------Listar veículos--------------------(Digite 5)\n");
        printf("\n---------------------------Listar Informações já cadastradas--(Digite 6)\n");
        printf("\n---------------------------Consultar clientes-----------------(Digite 7)\n");
        printf("\n---------------------------Consultar veículos-----------------(Digite 8)\n");
        printf("\n---------------------------Pontos de Fidelidade---------------(Digite 9)\n");
        printf("\n---------------------------Baixa em Locação-------------------(Digite 10)\n");
        printf("\n---------------------------Alterar----------------------------(Digite 11)\n");
        printf("\n---------------------------Sair-------------------------------(Digite 0)\n");
        printf("\nDigite a sua escolha: ");
        scanf("%d", &opcao);
        if ((opcao < 0) || (opcao > 11))
            printf ("Não existe essa opção de escolha!\n");
    }
    while ((opcao < 0) || (opcao > 11));

    return opcao;
}


void cadastCliente()
{
    struct tCliente clientes;

    FILE *arq = fopen("clientes.txt", "ab");
    if (arq == NULL)
    {
        printf("Erro no arquivo");
        return;
    }
    printf("Digite o endereço: \n");
    scanf("%s",&clientes.endereco);
    printf("Digite o numero de telefone: \n");
    scanf("%i",&clientes.numtelefone);
    printf("Digite os primeiros 3 digitos do CPF que será o código do cliente: \n");
    scanf("%u", &clientes.cpfCliente);
    printf("Digite o nome do cliente: \n");
    fflush(stdin);
    gets(clientes.nome);
    fwrite (&clientes, sizeof(clientes), 1, arq);
    fclose(arq);
}


void cadastrarLoc()
{
    int i=0;
    struct tLocacao locacao;
    FILE *arq = fopen("locacao.txt", "ab");
    if (arq == NULL)
    {
        printf("Erro no arquivo");
        return;
    }
    printf("Digite a escolha do seu carro:\n");
    scanf("%s",&locacao.carro);
    printf("Digite a data de retirada:\n");
    scanf("%i",&locacao.data_retirada);
    printf("Por quantos dias será a locação:\n");
    scanf("%i",&locacao.quantDias);
    srand(time(NULL));
    for(i=0; i<1; i++)
    {
        locacao.data_devolucao = rand()%30;
        printf("Data de devolução gerada: %d do mês seguinte\n", locacao.data_devolucao);
    }
        printf("Deseja seguro?(Digite 1 para SIM e 2 para NÃO)\n");
        scanf("%i",&locacao.seguro);
        printf("!!!!LOCAÇÃO CONCLUÍDA COM SUCESSO!!!!");

        fwrite(&locacao,sizeof(locacao),1,arq);
        fclose(arq);

}



    void cadastVeiculo()
    {
        struct tVeiculos veiculos;


        FILE *arq = fopen("veiculos.txt", "ab");
        if (arq == NULL)
        {
            printf("Erro no arquivo");
            return;
        }
        printf("Digite a quantidade de ocupantes do veículo:\n");
        scanf("%i",&veiculos.ocupantes);
        printf("Digite a cor do veículo: \n");
        scanf("%s",&veiculos.cor);
        printf("Digite o status do veículo:(Alugado, Disponível ou Manutenção)\n");
        scanf("%s",veiculos.status);
        printf("Digite o valor da diária:\n");
        fflush(stdin);
        scanf("%f",&veiculos.preco);
        printf("Digite o modelo do veículo: \n");
        fflush(stdin);
        gets(veiculos.modelo);
        printf("Digite as letras da placa:\n");
        scanf("%s",&veiculos.placaletra);
        printf("Digite os números da placa:\n");
        scanf("%i",&veiculos.placanum);




        veiculos.codigo = randomCode(rand() % 10);
        fwrite (&veiculos, sizeof(veiculos), 1, arq);
        fclose(arq);
    }


    void listClientes()
    {

        struct tCliente clientes;
        FILE *arq = fopen("clientes.txt", "rb");
        if (arq == NULL)
        {
            printf("Arquivo inexistente!");
            return;
        }

        while (fread (&clientes, sizeof(clientes), 1, arq))
        {
            printf("\nEndereço: %s",clientes.endereco);
            printf("\nNúmero de Telefone: %i",clientes.numtelefone);
            printf("\nCódigo: %i",clientes.cpfCliente);
            printf("\nDescrição:%s",clientes.nome);
        }



        fclose(arq);
    }


    void listVeiculos ()
    {

        struct tVeiculos veiculos;
        FILE *arq = fopen("veiculos.txt", "rb");
        if (arq == NULL)
        {
            printf("Arquivo inexistente!");
            return;
        }

        while (fread (&veiculos, sizeof(veiculos), 1, arq))
        {
            printf("Valor diária: %4.f",veiculos.preco);
            printf("\nQuatidade de ocupantes: %i",veiculos.ocupantes);
            printf("\nCod: %i",veiculos.codigo);
            printf("\nModelo:%s",veiculos.modelo);
            printf("\nCor: %s",veiculos.cor);
            printf("\nStatus:%s",veiculos.status);
            printf("\n PLACA: %s%i",veiculos.placaletra,veiculos.placanum);
        }
        fclose(arq);
    }

    void listInfos()
    {
        printf("\n----Lista de clientes----\n");
        listClientes();

        printf("\n----Lista de veículos----\n");
        listVeiculos();
    }


    int randomCode(unsigned int aleatorio)
    {

        unsigned short cod;
        cod = ((aleatorio * (time(NULL)))%1000000);
        return cod;
    }



    void consultVeiculos()
    {

        FILE *arq = fopen("veiculos.txt", "rb");
        if (arq == NULL)
        {
            printf("Arquivo inexistente!");
            return;
        }

        struct tVeiculos veiculos;
        int cod, achei = 0;
        printf ("Digite o código de veículo que procura: \n");
        scanf ("%d", &cod);

        while (fread (&veiculos, sizeof(veiculos), 1, arq))
        {
            if ((cod == veiculos.codigo))
            {
                printf("Valor diária: %4.f",veiculos.preco);
                printf("\nQuatidade de ocupantes: %i",veiculos.ocupantes);
                printf("Código: %i\n",veiculos.codigo);
                printf("Modelo: %s\n",veiculos.modelo);
                printf("Cor:%s\n",veiculos.cor);
                printf("Status: %s\n",veiculos.status);
                printf("\n PLACA: %s%i\n",veiculos.placaletra,veiculos.placanum);
                achei = 1;
            }
        }

        if (!achei)
            printf ("\\nCódigo não cadastrado!!\n");

        fclose(arq);

    }


    void baixa_locacao()
    {
        FILE *arq = fopen("locacao.txt", "r+b");
        if (arq == NULL)
        {
            printf("O arquivo não existe!");
            return;
        }
        struct tLocacao locacao;

        int cod,resposta,achei=0;

        while (fread (&locacao, sizeof(locacao), 1, arq))
        {
            printf("\nDia que o veículo foi retirado: %i \n",locacao.data_retirada);
            printf("Digite o preço da locação:\n");
            scanf("%f",&locacao.precoLoc);
            printf("Dia marcado para a devolução do veículo:%i\n",locacao.data_devolucao);
            printf("Digite o dia que foi devolvido o veículo:\n");
            scanf("%i",&locacao.dataDevolucaocliente);
            printf("Seguro ativado?( Caso 1( ativado) Caso 2 (Desativado): %i\n",locacao.seguro);
            if(locacao.seguro==1 && locacao.dataDevolucaocliente>locacao.data_devolucao)
            {
                printf("Será adicionado 50 reais no preço total mais 30 de multa!\n");
                locacao.precoLocTotal=locacao.precoLoc+80;
                printf("Valor total a ser pago: %4.f",locacao.precoLocTotal);
            }
            if (locacao.seguro==2 && locacao.dataDevolucaocliente<=locacao.data_devolucao)
            {

                locacao.precoLocTotal= locacao.precoLocTotal;
            }


        }
        fclose(arq);
    }








    void consultCliente()
    {

        FILE *arq = fopen("clientes.txt", "rb");
        if (arq == NULL)
        {
            printf("Arquivo inexistente!");
            return;
        }

        struct tCliente clientes;
        int cod, achei = 0;
        printf ("Digite os primeiros 3 números do CPF que procura: \n");
        scanf ("%d", &cod);

        while (fread (&clientes, sizeof(clientes), 1, arq))
        {

            if ((cod == clientes.cpfCliente))
            {
                printf("\nCódigo: %i",clientes.cpfCliente);
                printf("\nDescrição:%s",clientes.nome);
                printf("\nEndereço: %s",clientes.endereco);
                printf("\nTelefone: %i",clientes.numtelefone);
                achei = 1;
            }
        }


        if (!achei)
            printf ("\\nCódigo não cadastrado!!\n");


        fclose(arq);


    }


    void fidelidade()
    {
        FILE *arq = fopen("clientes.txt", "r+b");
        if (arq == NULL)
        {
            printf("O arquivo não existe!");
            return;
        }
        struct tCliente clientes;
        int locacoes,pontos,cod = 0, achei= 0;
        printf("Digite os 3 digitos do seu código:");
        scanf("%i",&cod);
        while(fread (&clientes, sizeof(clientes), 1, arq))
        {
            if((cod == clientes.cpfCliente))
            {
                printf("\nDigite quantas locações você tem:\n");
                scanf("%i",&clientes.locacoes);
                clientes.pontosFidelidade=(clientes.locacoes*10);
                printf("\nVocê tem %i pontos de locação!\n",clientes.pontosFidelidade);
                if(clientes.pontosFidelidade>=500)
                {
                    printf("\n!!!PARABÉNS VOCÊ GANHOU O KITLOCAMAIS!!!\n");
                }
                else
                {
                    printf("Você  não tem direito ao KITLOCAMAIS!");
                }
            }

        }
        fclose(arq);
    }





    void alterar()
    {
        FILE *arq = fopen("clientes.txt", "r+b");
        if (arq == NULL)
        {
            printf("Arquivo inexistente!");
            return;
        }

        struct tCliente clientes;
        int cod, achei = 0;
        printf ("Digite os primeiros 3 digítos do CPF do cliente que deseja alterar: \n");
        scanf ("%d", &cod);

        while (fread (&clientes, sizeof(clientes), 1, arq))
        {
            if (cod == clientes.cpfCliente)
            {
                printf("\nCódigo: %i",clientes.cpfCliente);
                printf("\nDescrição:%s",clientes.nome);
                printf("\nEndereço: %s",clientes.endereco);
                printf("\nTelefone: %i",clientes.numtelefone);
                achei = 1;

                fseek(arq,sizeof(struct tCliente)*-1, SEEK_CUR);
                printf("\nDigite o novo nome desejado:\n");
                fflush(stdin);
                gets(clientes.nome);
                printf("\nDigite o novo número de telefone: \n");
                scanf("%i", &clientes.numtelefone);

                fwrite(&clientes, sizeof(clientes), 1, arq);
                fseek(arq, sizeof(clientes)* 0, SEEK_END);
                return;
            }
        }

        if (!achei)
            printf ("\nCódigo não cadastrado!!\n");

        fclose(arq);
    }


