<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

// Funcao para limpar tela
void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Interface de controle
void mainMenu()
{
    int option;

    do
    {
        printf("------------------------------------\n"
               "|       INTERFACE DE CONTROLE      |\n"
               "------------------------------------\n"
               "| 1 - Criar novo processo          |\n"
               "| 2 - Ver processos em andamento   |\n"
               "| 3 - Ver uso de memoria           |\n"
               "| 0 - Encerrar programa            |\n"
               "------------------------------------\n");
        printf("\nEscolha uma opcao: \n");
        scanf("%d", &option);

        clearScreen();
        switch (option)
        {
        case 0:
            printf("\nOPCAO 0 ESCOLHIDA.\nENCERRANDO PROGRAMA...\n\n");
            exit(0);
            break;
        case 1:
            printf("\nOPCAO 1 ESCOLHIDA.\n\n");
            // createProcess();
            break;
        case 2:
            printf("\nOPCAO 2 ESCOLHIDA.\n\n");
            // runningProcesses();
            break;
        case 3:
            printf("\nOPCAO 3 ESCOLHIDA.\n\n");
            // memoryUsage();
            break;
        default:
            printf("\nERRO: OPCAO INVALIDA!\n\n");
            break;
        }
    } while (option != 0);
=======
#include <stdio.h>
#include <stdlib.h>
// #include "process.h"

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mainMenu()
{
    int option;

    do
    {
        printf("-------------------------------\n"
               "|          MAIN MENU          |\n"
               "-------------------------------\n"
               "| 1 - Create new process      |\n"
               "| 2 - View running processes  |\n"
               "| 3 - View memory usage       |\n"
               "| 0 - Finish program          |\n"
               "-------------------------------\n");
        printf("\nChoose an option: \n");
        scanf("%d", &option);

        clearScreen();
        switch (option)
        {
        case 0:
            printf("\nOPTION 0 WAS CHOSEN.\nFINISHING PROGRAM...\n\n");
            exit(0);
            break;
        case 1:
            printf("\nOPTION 1 WAS CHOSEN.\n\n");
            // createProcess();
            break;
        case 2:
            printf("\nOPTION 2 WAS CHOSEN.\n\n");
            // runningProcess();
            break;
        case 3:
            printf("\nOPTION 3 WAS CHOSEN.\n\n");
            // memoryUsage();
            break;
        default:
            printf("\nERROR: INVALID OPTION!\n\n");
            break;
        }
    } while (option != 0);
>>>>>>> 2c0af9f5d5ab43bb3d9eeab5078a603ab9476c57
}