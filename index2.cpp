#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef struct StarBook_store
{
    struct KhachHang
    {

        int sttKH = -1;
        struct ThongTin
        {
            char ten[30];
            char diachi[50];
            int sosanpham;
            struct GioHang
            {
                char ten[30];
                int gia;
                int soluong;
            } dsGH[30];
        } dsTTKH[30];

    } kh;

    // struct SanPham
    // {
    //     /* data */
    //     struct DoUong
    //     {
    //     };
    //     struct DoAn
    //     {
    //     };
    //     /* data */
    // };

    // struct QuanLyThuChi
    // {
    //     int tienNgay;
    //     int tienThang;
    //     /* data */
    // };

    // struct NhanVien
    // {
    //     /* data */
    //     char ten[30];
    //     char diachi[40];
    //     int namsinh;
    // };

} cuahang;
void taogiohang(cuahang *&star);
void chonhang(cuahang *&star);
void xemgiohang(cuahang *star);
void xoamotmathang(cuahang *&star);
void menu_KH(cuahang *&star);
int demso(int a);
/*Ham main*/
int main(void)
{
    cuahang *star = (cuahang *)malloc(30 * sizeof(cuahang));
    menu_KH(star);
    free(star);
    return 0;
}

void menu_KH(cuahang *&star)
{
    int control = 0;
    printf("1. Tao gio hang\n2. Chon hang\n3. Xem chi tiet gio hang\n4. Loai bo mot mat hang\n5. Ghi toan bo noi dung gio hang vao tep nhi phan cart.dat.\n6. Thoat \n");

    while (control != 6)
    {
        printf("\n|-> Nhap lua chon cua ban: ");
        scanf("%d", &control);
        while (control < 1 || control > 6)
        {
            printf("- Nhap SAI!!. Vui long chon lai! -");
            scanf("%d", &control);
        }
        switch (control)
        {
        case 1:
            taogiohang(star);
            break;
        case 2:
            chonhang(star);
            break;
        case 3:
            xemgiohang(star);
            break;
        case 4:
            xoamotmathang(star);
            break;
        case 5:
            // Tep Nhi Phan
            break;
        case 6:
            printf("\n- Ban da thoat khoi chuong trinh. Xin cam on! -");
            break;
        }
    }
}

void taogiohang(cuahang *&star)
{
    star->kh.sttKH++;
    int n = star->kh.sttKH;
    printf("Nhap ten khach hang: ");
    fflush(stdin);
    gets(star->kh.dsTTKH[n].ten);
    printf("Nhap dia chi cua %s: ", star->kh.dsTTKH[n].ten);
    gets(star->kh.dsTTKH[n].diachi);
    star->kh.dsTTKH[n].sosanpham = 0;
}

void chonhang(cuahang *&star)
{
    int n = star->kh.sttKH;
    int x;
    printf("* Nhap so san pham ban can mua: ");
    scanf("%d", &x);
    star->kh.dsTTKH[n].sosanpham += x;
    int m = star->kh.dsTTKH[n].sosanpham;
    for (int i = 0; i < m; i++)
    {
        printf("\n-Nhap ten san pham thu %d: ", i + 1);
        fflush(stdin);
        gets(star->kh.dsTTKH[n].dsGH[i].ten);
        printf("-Nhap so luong %s: ", star->kh.dsTTKH[n].dsGH[i].ten);
        scanf("%d", &star->kh.dsTTKH[n].dsGH[i].soluong);
        printf("-Nhap gia cua %s: ", star->kh.dsTTKH[n].dsGH[i].ten);
        scanf("%d", &star->kh.dsTTKH[n].dsGH[i].gia);
        printf("\n");
    }
}
void canhgiuachu(int a, int b, char c[])
{

    for (int i = 0; i < ((a - b) / 2); i++)
        printf(" ");
    printf("%s", c);
    if (b / 2 != 0)
    {

        for (int i = 0; i < ((a - b + 1) / 2); i++)
            printf(" ");
    }
    else
    {
        for (int i = 0; i < ((a - b) / 2); i++)
            printf(" ");
    }
    printf("||");
}
void canhgiuaso(int a, int b, int c)
{

    for (int i = 0; i < ((a - b) / 2); i++)
        printf(" ");
    printf("%d", c);
    if (b / 2 != 0)
    {

        for (int i = 0; i < ((a - b + 1) / 2); i++)
            printf(" ");
    }
    else
    {
        for (int i = 0; i < ((a - b) / 2); i++)
            printf(" ");
    }
    printf("||");
}
void xemgiohang(cuahang *star)
{
    int n = star->kh.sttKH;
    int m = star->kh.dsTTKH[n].sosanpham;
    printf("\n-Gio Hang cua %s-\n", star->kh.dsTTKH[n].ten);
    printf("    STT    ||         Ten San Pham          ||    Gia    || So Luong  ||\n");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < m; i++)
    {
        // iN stt
        canhgiuaso(11, demso(i + 1), i + 1);

        // iN Ten San Pham --   Khoai :)
        canhgiuachu(31, strlen(star->kh.dsTTKH[n].dsGH[i].ten), star->kh.dsTTKH[n].dsGH[i].ten);

        // iN Gia
        canhgiuaso(11, demso(star->kh.dsTTKH[n].dsGH[m].gia), star->kh.dsTTKH[n].dsGH[m].gia);

        // iN So Luong
        canhgiuaso(10, demso(star->kh.dsTTKH[n].dsGH[m].soluong), star->kh.dsTTKH[n].dsGH[m].soluong);
        printf("\n");
    }
}
void xoamotmathang(cuahang *&star)
{
    int n = star->kh.sttKH;
    int m = star->kh.dsTTKH[n].sosanpham;
    int y;
    printf("Ban can loai bo san pham thu may? ");
    scanf("%d", &y);
    // while (n < 1 || n > star->kh.dsTTKH[n].sosanpham)
    while (y < 1 || y > m)
    {
        printf("Loi!\nVui long chon lai thu tu san pham: ");
        scanf("%d", &y);
    }
    for (int i = y; i < m; i++)
        star->kh.dsTTKH[n].dsGH[i - 1] = star->kh.dsTTKH[n].dsGH[i];
    star->kh.dsTTKH[n].sosanpham--;
    printf("Ban da xoa mat hang thu %d!", y);
}

int demso(int a)
{
    int dem = 0;
    while (a != 0)
    {
        a /= 10;
        dem++;
    }
    return dem;
}
