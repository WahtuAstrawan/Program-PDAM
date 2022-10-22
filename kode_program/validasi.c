#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// validasi integer
int validasi_Int(int *var)
{
    char buff[1024];
    char cek;
    fflush(stdin);
    if (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        if (sscanf(buff, "%d %c", var, &cek) == 1)
        {
            return 1;
        }
    }
    return 0;
}
// menerima data dan intruksi, sekaligus looping jika data salah
void Input_Int(int *var, char *nama)
{
    while (1)
    {
        printf("%s", nama);
        fflush(stdin);
        if (validasi_Int(var))
            break;
        printf("========================================================\n");
        printf("||               Maaf Input anda salah !              ||\n");
        printf("||                 Mohon Masukan Angka                ||\n");
        printf("========================================================\n");
        // printf("\t\t\t Input salah! Mohon Masukan Angka\n");
    }
}
// range input integer untuk  ( digunakan pada menu )
void range_Validasi_Int(int *var, int range1, int range2, char *nama)
{
    while (1)
    {
        Input_Int(var, nama);
        fflush(stdin);
        if (*var >= range1 && *var <= range2)
            break;
        printf("\t\t\t Input salah! Pilih Nomer Yang tersedia\n");
    }
}

// menerima data dan intruksi sekaligus memeriksa bahwa bilangan sudah positif
void Input(float *var, char *nama)
{
    while (1)
    {
        Input_Float(var, nama);
        fflush(stdin);
        if (*var >= 0)
            break;
        printf("========================================================\n");
        printf("||               Maaf Input anda salah !              ||\n");
        printf("||              Masukan Bilangan Positif              ||\n");
        printf("========================================================\n");
        // printf("\t\t\t Input salah! Masukan Bilangan Positif\n");
    }
}

//validasi menerima input float
float validasi_Float(float *var){
    char buff[1024];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%f %c", var, &cek) == 1) {
            return 1;
        }
    }
    return 0;
}
//menerima data float dan intruksi, sekaligus looping jika data salah
void Input_Float(float *var, char *nama){
    while(1){
        printf("%s",nama);
        fflush(stdin);
        if(validasi_Float(var))
            break;
        printf("\t\t\t Input salah! Silahkan coba lagi.\n");
    }
}


int main()
{

    return 0;
}
