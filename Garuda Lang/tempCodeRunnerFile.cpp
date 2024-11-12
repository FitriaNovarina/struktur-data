#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk memeriksa validitas penggunaan bracket
bool is_valid_bracket_sequence(const char *code)
{
    char stack[1000];
    int top = -1;

    // Iterasi melalui setiap karakter dalam kode
    for (int i = 0; i < strlen(code); i++)
    {
        char current = code[i];

        // Jika karakter adalah bracket pembuka, tambahkan ke stack
        if (current == '(' || current == '[' || current == '<' || current == '{')
        {
            stack[++top] = current;
        }
        // Jika karakter adalah bracket penutup
        else if (current == ')' || current == ']' || current == '>' || current == '}')
        {
            // Jika stack kosong atau pasangan bracket tidak cocok
            if (top == -1 ||
                (current == ')' && stack[top] != '(') ||
                (current == ']' && stack[top] != '[') ||
                (current == '>' && stack[top] != '<') ||
                (current == '}' && stack[top] != '{'))
            {
                return false;
            }
            top--; // Pop stack karena bracket pasangan sudah ditemukan
        }
    }

    // Jika stack kosong, semua bracket sudah berpasangan
    return top == -1;
}

int main()
{
    char line[1000], allCode[10000];
    char pilih;

    do
    {
        // Inisialisasi ulang allCode untuk input berikutnya
        allCode[0] = '\0';

        system("cls");
        printf("Masukkan Kode:");

        // Membaca input sampai pengguna menekan Enter satu kali
        while (fgets(line, sizeof(line), stdin))
        {
            // Jika input hanya berisi newline (Enter), berhenti
            if (strcmp(line, "\n") == 0)
            {
                break;
            }

            // Tambahkan baris input ke semua kode
            strcat(allCode, line);
        }

        // Cek apakah kode valid atau tidak
        if (is_valid_bracket_sequence(allCode))
        {
            printf("Kode valid!\n");
        }
        else
        {
            printf("Kode tidak valid!\n");
        }

        // Tanyakan apakah pengguna ingin melanjutkan atau keluar
        printf("Tekan k untuk keluar, atau periksa kode lain: ");
        scanf(" %c", &pilih);
        getchar(); // Membersihkan buffer

    } while (pilih != 'k');

    return 0;
}
