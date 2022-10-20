#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Input(float *var, char *nama);
float validasi_Float(float *var);
void Input_Float(float *var, char *nama);
void menuUtama();
float pemakaianAir();
void range_Validasi_Int(int *var, int range1, int range2, char *nama);
void Input_Int(int *var, char *nama);
int validasi_Int(int *var);
void registrasi(char *nama,float *jalan,float *listrik);


int main()
{   
    char nama[1024];
    menuUtama();
    float test = pemakaianAir();
    //printf("%s",nama);
    return 0;
}

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
void Input_Float(float *var, char *nama){
    while(1){
        printf("%s",nama);
        fflush(stdin);
        if(validasi_Float(var))
            break;
        printf("\t\t\t Input salah! Silahkan coba lagi.\n");
    }
}
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

float pemakaianAir()
{
    //system("cls");
    float pakaiAir, bulanIni, bulanLalu;
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("||====================================================||\n");
    printf("||                   Pemakaian Air                    ||\n");
    printf("========================================================\n");

    Input(&pakaiAir, "  Masukkan pemakaian bulan lalu (M^3) : ");
    Input(&bulanIni, "  Masukkan pemakaian bulan ini (M^3)  : ");

    pakaiAir = bulanIni - bulanLalu;

    return pakaiAir;
}
void menuUtama()
{
    int menu;
    printf("|| ==================================================== ||\n");
    printf("||                Menu Kelompok Pelanggan               ||\n");
    printf("|| ==================================================== ||\n");
    printf("|| 1. Non Niaga Bersubsidi                              ||\n");
    printf("|| 2. Non Niaga Tanpa Bersubsidi                        ||\n");
    printf("|| 3. Niaga                                             ||\n");
    printf("|| ==================================================== ||\n");
    printf("\n");
    range_Validasi_Int(&menu, 1, 3, "Pilihan Anda: ");
    // printf("Pilihan Anda: ");
    // scanf("%d", &menu);
    system("cls");

    switch (menu)
    {
    case 1:
        //nonNiagaBersubsidi();
        break;
    case 2:
        //nonNiagaTanpaBersubsidi();
        break;
    case 3:
        //niaga();
        break;
    default:
        printf("|| ================================================== ||\n");
        printf("||       Maaf Input anda salah, Silahkan ulangi !     ||\n");
        printf("|| ================================================== ||\n");
        menuUtama();
        break;
    }
}

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

void registrasi(char *nama,float *jalan,float *listrik){
    system("cls");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("   MASUKAN NAMA ANDA :");
    scanf("%[^\n]", nama);
    Input(jalan, " ");
}

int jalan_Subsidi(){
    system("cls");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||    ukuran jalan termasuk saluran got dan berm      ||\n");
    printf("||                                                    ||\n");
    printf("|| 1. 0 - 3,99 meter                                  ||\n");
    printf("|| 2. 4 - 6,99 meter                                  ||\n");
    printf("|| 3. 7 - 10   meter                                  ||\n");
    printf("|| 4.  >10     meter                                  ||\n");
    printf("========================================================\n");
}