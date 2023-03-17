#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct giohang_st
{
    char tenkhachhang[30];
    char diachi[50];
    int sosanpham;
    typedef struct sanpham_st
    {
        char tensp[30];
        int gia;
        int soluong;
    } sanpham;
    sanpham dssp[30];
} giohang;
void menu(giohang *&giocuatoi);
void taogiohang(giohang *&giocuatoi);
void chonhang(giohang *&giocuatoi);
void xemgiohang(giohang *giohangcuatoi);
int demchucai(char str[]);
int demchuso(int n);
void xoamotmathang(giohang *&giohangcuatoi);
int main(void)
{
    giohang *giocuatoi = (giohang *)malloc(30 * sizeof(giohang));

    menu(giocuatoi);
    return 0;
    free(giocuatoi);
}

/*
--------------------2. Tạo ra Menu dưới đây:[ 1 ]--------------------------------
1. Tạo giỏ hàng
2. Chọn hàng.
3. Xem chi tiết giỏ hàng.
4. Loại bỏ một mặt hàng.
5. Ghi toàn bộ nội dung giỏ hàng vào tệp nhị phân cart.dat.
6. Thoát.
*/

void menu(giohang *&giocuatoi)
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
            taogiohang(giocuatoi);
            break;
        case 2:
            chonhang(giocuatoi);
            break;
        case 3:
            xemgiohang(giocuatoi);
            break;
        case 4:
            xoamotmathang(giocuatoi);
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
void taogiohang(giohang *&giocuatoi)
{

    printf("Nhap ten khack hang: ");
    fflush(stdin);
    gets(giocuatoi->tenkhachhang);
    printf("Nhap dia chi cua %s: ", giocuatoi->tenkhachhang);
    fflush(stdin);
    gets(giocuatoi->diachi);
    giocuatoi->sosanpham = 0;
}
void chonhang(giohang *&giocuatoi)
{
    int n = giocuatoi->sosanpham;
    /*
Khi chọn 2 từ Menu, thực hiện các yêu cầu dưới đây:
     Hiển thị “Nhap ten san pham:”
     Sau đó hiển thị “Nhap so luong:”
     Sau đó hiển thị “Nhap gia:”
Viết hàm “chonhang” để thực hiện chức năng này theo yêu cầu dưới đây:
     Sử dụng tham biến là con trỏ cấu trúc giohang_st
     Tăng số lượng sản phẩm lên 1 sau mỗi lần chọn hàng
    */

    printf("Nhap ten san pham: ");
    fflush(stdin);
    gets(giocuatoi->dssp[n].tensp);
    printf("Nhap so luong %s: ", giocuatoi->dssp[n].tensp);
    /*Bug*/
    scanf("%d", &giocuatoi->dssp[n].soluong);
    printf("Nhap gia cua %s: ", giocuatoi->dssp[n].tensp);
    scanf("%d", &giocuatoi->dssp[n].gia);
    giocuatoi->sosanpham++;
}
void xemgiohang(giohang *giohangcuatoi)
{
    // Khi chọn 3 từ Menu, sắp xếp các sản phẩm theo tên từ A🡪Z sau đó hiển thị thông tin chi tiết như dưới đây
    /*
    STT  Ten san pham   Gia     So luong
    1    Ca chua        3000    3
    2    Kem Socola     5500    10
    3    Vo hoc sinh    4000    20

    */

    printf("STT  ||Ten san pham                  ||Gia       ||So luong  \n");
    for (int i = 0; i < giohangcuatoi->sosanpham; i++)
    {
        printf("%d", i + 1);
        printf("%s", giohangcuatoi->dssp[i].tensp);
        printf("%d", giohangcuatoi->dssp[i].gia);
        printf("%d", giohangcuatoi->dssp[i].soluong);
        printf("\n");
    }
}
int demchucai(char str[])
{
    int d = 0;
    for (int i = 0; i < strlen(str); i++)
        if ((str[i] >= '65' && str[i] <= '90') || (str[i] >= '97' && str[i] <= '122'))
            d++;
    return d;
}
int demchuso(int n)
{
    int d = 0;
    while (n != 0)
    {
        n /= 10;
        d++;
    }
    return d;
}
void xoamotmathang(giohang *&giohangcuatoi)
{
    int n;
    // do
    // {
    //     printf("Can loai bo san pham thu may? ");
    //     scanf("%d", &n);
    // } while (n <= 0);
    printf("Can loai bo san pham thu may? ");
    scanf("%d", &n);
    while (n < 1 || n > giohangcuatoi->sosanpham)
        printf("“Ban phai nhap thu tu dung voi danh sach!!”");
    for (int i = n; i < giohangcuatoi->sosanpham; i++)
    {
        giohangcuatoi->dssp[i - 1] = giohangcuatoi->dssp[i];
    }
    giohangcuatoi->sosanpham--;
    printf("Ban da xoa mat hang thu %d", n);
}
/*5. Loại bỏ một mặt hàng[4]
Khi chọn 4 từ Menu, thực hiện các yêu cầu dưới đây:
Hiển thị  “Can loai bo san pham thu may:”
Tìm và loại bỏ sản phẩm tương ứng với thứ tự được chọn. Trong trường hợp người dung nhập con số không đúng với số lượng sản phẩm đang có thì hiển thị thong báo “Ban phai nhap thu tu dung voi danh sach”
Sử dụng hàm để thực hiện chức năng này theo yêu cầu dưới đây:
Sử dụng tham biến là con trỏ cấu trúc giohang_st tham chiếu đến biến giocuatoi trong hàm main().
*/
