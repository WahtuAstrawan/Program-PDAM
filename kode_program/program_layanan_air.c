#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ADMIN_RT 10000 // biaya admin rumah tangga
#define ADMIN_N 12500  // biaya admin usaha
#define DENDA 25000    // denda bila lewat jatuh tempo
#define BPM_RT 5000    // biaya pemeliharaan rumah tangga
#define BPM_U 7500     // biaya pemeliharaan usaha
#define JATUH_TEMPO 20 // jatuh tempo tgl 20

// deklarasi semua fungsi
void namaProgram(), namaKelompok(), menuUtama(), menuRT(), totalBiayaD11(), is(), cobaLagi(),
    Input(), Input_Float(), Input_Int(), range_Validasi_Int(), totalBiayaD12(),
    totalBiayaE34(), totalBiayaE33(), totalBiayaE32(), totalBiayaE31(), totalBiayaE24(),
    totalBiayaE23(), totalBiayaE22(), totalBiayaE21(), totalBiayaE14(), totalBiayaE13(),
    totalBiayaE12(), totalBiayaE11(), totalBiayaD54(), totalBiayaD53(), totalBiayaD52(),
    totalBiayaD51(), totalBiayaD44(), totalBiayaD43(), totalBiayaD34(), totalBiayaD33(),
    totalBiayaD24(), totalBiayaD23(), totalBiayaD14(), totalBiayaD13(), totalBiayaD42(),
    totalBiayaD41(), totalBiayaD32(), totalBiayaD31(), totalBiayaD22(), totalBiayaD21(),
    akhirProgram(), menuUsaha();

int validasi_Int(), pilihListrik();

float validasi_Float(), pemakaianAir();

// program utama
int main()
{
    namaProgram();
    return 0;
}

// validasi float
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
    }
}
void Input_Float(float *var, char *nama)
{
    while (1)
    {
        printf("%s", nama);
        fflush(stdin);
        if (validasi_Float(var))
            break;
        printf("\t\t\t Input salah! Silahkan coba lagi.\n");
    }
}
float validasi_Float(float *var)
{
    char buff[1024];
    char cek;
    fflush(stdin);
    if (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        if (sscanf(buff, "%f %c", var, &cek) == 1)
        {
            return 1;
        }
    }
    return 0;
}

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

// intro
void namaProgram()
{
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("||          Selamat Menikmati Layanan Kami :)         ||\n");
    printf("|| ================================================== ||\n");
    printf("||       Tekan Enter untuk melanjutkan program!       ||\n");
    printf("========================================================\n");
    getchar();
    namaKelompok();
}

// nama kelompok
void namaKelompok()
{
    system("clear");
    printf("========================================================\n");
    printf("||                  Anggota Kelompok                  ||\n");
    printf("|| ================================================== ||\n");
    printf("||                                                    ||\n");
    printf("|| - 2205551067 I Putu Liangga Ristiana Putra         ||\n");
    printf("||                                                    ||\n");
    printf("|| - 2205551071 I Gusti Ngurah Putu Astrawan          ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n\n");
    printf("        Tekan Enter untuk melanjutkan program !   ");
    getchar();
    menuUtama();
}

// menu utama
void menuUtama()
{
    system("clear");
    int menu;
    printf("==========================================================\n");
    printf("||                Menu Kelompok Pelanggan               ||\n");
    printf("|| ==================================================== ||\n");
    printf("|| 1. Rumah Tangga                                      ||\n");
    printf("|| 2. Usaha                                             ||\n");
    printf("==========================================================\n");
    printf("\n");
    range_Validasi_Int(&menu, 1, 2, "   Pilihan Anda : ");
    switch (menu)
    {
    case 1:
        menuRT();
        break;
    case 2:
        menuUsaha();
        break;
    default:
        is();
        menuUtama();
        break;
    }
}

// menu rumah tangga
void menuRT()
{
    system("clear");
    int menu, listrik1, listrik2, listrik3, listrik4, listrik5;
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||   Ukuran jalan termasuk saluran got dan berm Anda  ||\n");
    printf("||              serta apabila memiliki kios           ||\n");
    printf("|| ================================================== ||\n");
    printf("||                                                    ||\n");
    printf("|| 1. 0 - 3,99 meter                                  ||\n");
    printf("|| 2. 4 - 6,99 meter                                  ||\n");
    printf("|| 3. 7 - 10   meter                                  ||\n");
    printf("|| 4.  > 10    meter                                  ||\n");
    printf("|| 5. Memiliki Rumah dengan kios                      ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("\n");
    range_Validasi_Int(&menu, 1, 5, "   Pilihan Anda : ");
    switch (menu)
    {
    case 1:
        listrik1 = pilihListrik();
        if (listrik1 == 1)
        {
            totalBiayaD11();
        }
        else if (listrik1 == 2)
        {
            totalBiayaD12();
        }
        else if (listrik1 == 3)
        {
            totalBiayaD13();
        }
        else if (listrik1 == 4)
        {
            totalBiayaD14();
        }
        break;
    case 2:
        listrik2 = pilihListrik();
        if (listrik2 == 1)
        {
            totalBiayaD21();
        }
        else if (listrik2 == 2)
        {
            totalBiayaD22();
        }
        else if (listrik2 == 3)
        {
            totalBiayaD23();
        }
        else if (listrik2 == 4)
        {
            totalBiayaD24();
        }
        break;
    case 3:
        listrik3 = pilihListrik();
        if (listrik3 == 1)
        {
            totalBiayaD31();
        }
        else if (listrik3 == 2)
        {
            totalBiayaD32();
        }
        else if (listrik3 == 3)
        {
            totalBiayaD33();
        }
        else if (listrik3 == 4)
        {
            totalBiayaD34();
        }
        break;
    case 4:
        listrik4 = pilihListrik();
        if (listrik4 == 1)
        {
            totalBiayaD41();
        }
        else if (listrik4 == 2)
        {
            totalBiayaD42();
        }
        else if (listrik4 == 3)
        {
            totalBiayaD43();
        }
        else if (listrik4 == 4)
        {
            totalBiayaD44();
        }
        break;
    case 5:
        listrik5 = pilihListrik();
        if (listrik5 == 1)
        {
            totalBiayaD51();
        }
        else if (listrik5 == 2)
        {
            totalBiayaD52();
        }
        else if (listrik5 == 3)
        {
            totalBiayaD53();
        }
        else if (listrik5 == 4)
        {
            totalBiayaD54();
        }
        break;
    default:
        is();
        menuRT();
    }
}

// menu usaha
void menuUsaha()
{
    system("clear");
    int menu, listrik1, listrik2, listrik3;
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||   Ukuran jalan termasuk saluran got dan berm Anda  ||\n");
    printf("||              serta apabila memiliki kios           ||\n");
    printf("|| ================================================== ||\n");
    printf("||                                                    ||\n");
    printf("|| 1. 0 - 6,99 meter                                  ||\n");
    printf("|| 2. 7 - 10   meter                                  ||\n");
    printf("|| 3.  > 10    meter                                  ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("\n");
    range_Validasi_Int(&menu, 1, 3, "   Pilihan Anda : ");
    switch (menu)
    {
    case 1:
        listrik1 = pilihListrik();
        if (listrik1 == 1)
        {
            totalBiayaE11();
        }
        else if (listrik1 == 2)
        {
            totalBiayaE12();
        }
        else if (listrik1 == 3)
        {
            totalBiayaE13();
        }
        else if (listrik1 == 4)
        {
            totalBiayaE14();
        }
        break;
    case 2:
        listrik2 = pilihListrik();
        if (listrik2 == 1)
        {
            totalBiayaE21();
        }
        else if (listrik2 == 2)
        {
            totalBiayaE22();
        }
        else if (listrik2 == 3)
        {
            totalBiayaE23();
        }
        else if (listrik2 == 4)
        {
            totalBiayaE24();
        }
        break;
    case 3:
        listrik3 = pilihListrik();
        if (listrik3 == 1)
        {
            totalBiayaE31();
        }
        else if (listrik3 == 2)
        {
            totalBiayaE32();
        }
        else if (listrik3 == 3)
        {
            totalBiayaE33();
        }
        else if (listrik3 == 4)
        {
            totalBiayaE34();
        }
        break;
    default:
        is();
        menuUsaha();
    }
}

// menu memilih listrik
int pilihListrik()
{
    system("clear");
    int listrik;
    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||     Masukkan Besar Listrik Yang Anda Gunakan !      ||\n");
    printf("|| =================================================== ||\n");
    printf("||                                                     ||\n");
    printf("|| 1.    450    Watt                                   ||\n");
    printf("|| 2.    900    Watt                                   ||\n");
    printf("|| 3.   1300    Watt                                   ||\n");
    printf("|| 4. > 1300    Watt                                   ||\n");
    printf("||                                                     ||\n");
    printf("=========================================================\n");
    printf("\n");
    range_Validasi_Int(&listrik, 1, 4, "   Pilihan Anda : ");
    return listrik;
}

// Rumus Golongan Rumah Tangga
void totalBiayaD11()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }

    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 17800;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 2060;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 5880;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D1-1                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("=========================================================\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD12()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 20600;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 2340;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 5940;
    }

    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D1-2                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD13()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 63400;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 9200;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 9600;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D1-3                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD14()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 64200;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 9350;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 9650;
    }
    total = biaya + bpm + denda + admin;
    system("clear");
    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D1-4                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD21()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 23400;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 2620;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 6000;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D2-1                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD22()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 26200;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 2900;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 6060;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D2-2                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD23()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 64900;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 9500;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 9800;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D2-3                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD24()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 65700;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 9650;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 9950;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D2-4                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD31()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 29000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 3180;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 6120;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D3-1                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD32()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 31800;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 3460;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 6180;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D3-2                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD33()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 66400;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 9800;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 10100;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D3-3                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD34()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 67200;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 9950;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 10250;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D3-4                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD41()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 34600;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 3740;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 6240;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D4-1                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD42()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 37400;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 4020;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 6300;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D4-2                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD43()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 67900;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10100;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 10400;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D4-3                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD44()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 68700;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10250;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 10550;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D4-4                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD51()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 69400;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10400;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 10700;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D5-1                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD52()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 70200;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10550;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 10850;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D5-2                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD53()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 70900;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10700;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 11000;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D5-3                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaD54()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_RT;
    admin = ADMIN_RT;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 71700;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10850;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 11150;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Rumah Tangga                   \n");
    printf("|| Golongan           : D5-4                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

// rumus golongan usaha
void totalBiayaE11()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 92000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 9850;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 10950;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E1-1                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE12()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 95000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10150;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 11250;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E1-2                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE13()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 98000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10450;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 11550;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E1-3                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE14()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 101000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 10750;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 11850;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E1-4                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE21()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 104000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 11050;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 12150;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E2-1                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE22()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 107000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 11350;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 12550;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E2-2                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE23()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 110000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 11650;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 13150;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E2-3                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE24()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 113000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 11950;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 13950;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E2-4                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE31()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 116000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 12250;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 14750;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E3-1                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE32()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 119000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 12550;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 15050;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E3-2                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE33()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 122000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 12850;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 15850;
    }
    total = biaya + bpm + denda + admin;
    system("clear");

    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E3-3                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

void totalBiayaE34()
{
    float pakaiAir, biaya, total;
    int tanggal, denda, bpm, admin;
    char nama[100];
    system("clear");
    printf("========================================================\n");
    printf("||                    Program PDAM                    ||\n");
    printf("||               PT.Blangkon Sejahtera                ||\n");
    printf("|| ================================================== ||\n");
    printf("||                Registrasi Pelanggan                ||\n");
    printf("|| ================================================== ||\n");
    printf("   Nama Anda  : ");
    scanf("%[^\n]", nama);
    getchar();
    printf(" ====================  Bulan Ini   ==================== \n");
    range_Validasi_Int(&tanggal, 1, 31, "   Tanggal    : ");
    bpm = BPM_U;
    admin = ADMIN_N;
    if (tanggal > JATUH_TEMPO)
    {
        denda = DENDA;
    }
    else
    {
        denda = 0;
    }
    pakaiAir = pemakaianAir();
    if (pakaiAir <= 10)
    {
        biaya = 125000;
    }
    else if (pakaiAir > 10 && pakaiAir <= 20)
    {
        biaya = pakaiAir * 13150;
    }
    else if (pakaiAir > 20)
    {
        biaya = pakaiAir * 16650;
    }
    total = biaya + bpm + denda + admin;
    system("clear");
    printf("=========================================================\n");
    printf("||                    Program PDAM                     ||\n");
    printf("||               PT.Blangkon Sejahtera                 ||\n");
    printf("|| =================================================== ||\n");
    printf("||  Struk Pembayaran Air : %s                            \n", nama);
    printf("|| =================== Bulan Ini ===================== ||\n");
    printf("||                                                     \n");
    printf("|| Kelompok Pelanggan : Usaha                          \n");
    printf("|| Golongan           : E3-4                           \n");
    printf("|| Tanggal Bayar      : Tanggal %d                     \n", tanggal);
    printf("|| Jatuh Tempo Bayar  : Tanggal %d                     \n", JATUH_TEMPO);
    printf("|| Pemakaian Air      : %2.f      M^3                  \n", pakaiAir);
    printf("|| Biaya Air          : Rp. %2.f,-                       \n", biaya);
    printf("|| Denda              : Rp. %d,-                         \n", denda);
    printf("|| BPM                : Rp. %d,-                         \n", bpm);
    printf("|| Biaya Administrasi : Rp. %d,-                         \n", admin);
    printf("||                                                     \n");
    printf("|| =================================================== ||\n");
    printf("|| Total Bayar        : Rp. %2.f,-                       \n", total);
    printf("=========================================================\n");
    printf("             Tekan Enter Untuk Melanjutkan  !");
    getchar();
    cobaLagi();
}

// fungsi pemakaian air
float pemakaianAir()
{
    system("clear");
    float pakaiAir, bulanIni, bulanLalu;
    printf("========================================================\n");
    printf("||                   Pemakaian Air                    ||\n");
    printf("========================================================\n");
    Input(&bulanLalu, "   Masukkan pemakaian bulan lalu (M^3)  : ");
ulang:
    Input(&bulanIni, "   Masukkan pemakaian bulan ini (M^3)  : ");
    if (bulanIni < bulanLalu)
    {
        printf("Pemakaian Bulan ini tidak boleh lebih kecil dari bulan lalu ! \n");
        goto ulang;
    }
    pakaiAir = bulanIni - bulanLalu;

    return pakaiAir;
}

// fungsi print input salah
void is()
{
    printf("========================================================\n");
    printf("||       Maaf Input anda salah, Silahkan ulangi !     ||\n");
    printf("========================================================\n");
}

// fungsi untuk mengulang program
void cobaLagi()
{
    system("clear");
    int pilih;
    printf("====================================================\n");
    printf("|| Apakah Anda ingin menjalankan program kembali? ||\n");
    printf("||================================================||\n");
    printf("|| 1. Iya                                         ||\n");
    printf("|| 2. Tidak                                       ||\n");
    printf("====================================================\n");
    range_Validasi_Int(&pilih, 1, 2, "\n   Pilihan Anda : ");
    switch (pilih)
    {
    case 1:
        system("clear");
        menuUtama();
    case 2:
        system("clear");
        akhirProgram();
        break;
    default:
        is();
        cobaLagi();
    }
}

// fungsi akhir program
void akhirProgram()
{
    system("clear");
    printf("====================================================\n");
    printf("||  Terimakasih Telah Menggunakan Layanan Kami :) ||\n");
    printf("====================================================\n");
    getchar();
}
