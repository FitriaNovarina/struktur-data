#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_valid_bracket_sequence(const char *code)
{
    char stack[1000];
    int top = -1;

    for (int i = 0; i < strlen(code); i++)
    {
        char current = code[i];

        if (current == '(' || current == '[' || current == '<' || current == '{')
        {
            stack[++top] = current;
        }
        // Jika karakter adalah bracket penutup
        else if (current == ')' || current == ']' || current == '>' || current == '}')
        {

            if (top == -1 ||
                (current == ')' && stack[top] != '(') ||
                (current == ']' && stack[top] != '[') ||
                (current == '>' && stack[top] != '<') ||
                (current == '}' && stack[top] != '{'))
            {
                return false;
            }
            top--;
        }
    }

    return top == -1;
}

int main()
{
    char line[1000], allCode[1000];
    char pilih;

    do
    {
        allCode[0] = '\0';

        system("cls");
        printf("Masukkan Kode:");

        while (fgets(line, sizeof(line), stdin))
        {

            if (strcmp(line, "\n") == 0)
            {
                break;
            }

            strcat(allCode, line);
        }

        if (is_valid_bracket_sequence(allCode))
        {
            printf("Kode valid!\n");
        }
        else
        {
            printf("Kode tidak valid!\n");
        }

        printf("Tekan k untuk keluar, atau periksa kode lain: ");
        scanf(" %c", &pilih);
        getchar();

    } while (pilih != 'k');

    return 0;
}
