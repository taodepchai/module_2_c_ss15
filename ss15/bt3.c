#include<stdio.h>
struct student{
    char name[30];
    int age, phone_number;
    char email_adress[100];
};
typedef struct student std;
void input(std *temp){
    printf("nhap ten sinh vien:");
    getchar();
    gets(temp->name);
    printf("nhap tuoi:");
    scanf("%d",&temp->age);
    printf("nhap sdt:");
    scanf("%d",&temp->phone_number);
    printf("nhap email:");
    getchar();
    gets(temp->email_adress);
}
void output( std *temp){
    printf("ten:%s, tuoi:%d, sdt:%d, email:%s\n",temp->name, temp->age, temp->phone_number, temp->email_adress);
}
int main(){
    int n;
    std temp[100];
    int index;
    int choice;
    do {
        printf("\n1.nhap vao danh sach sinh vien\n");
        printf("2.them sinh vien vao danh sach\n");
        printf("3.sua sinh vien o vi tri chi dinh\n");
        printf("4.xoa sinh vien o vi tri chi dinh\n");
        printf("5.in ra danh sach sinh vien\n");
        printf("6.thoat\n");
        printf("nhap lua chon");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("nhap vao so luong sinh vien:");
                scanf("%d",&n);
                for (int i=0;i<n;i++)
                    input(&temp[i]);
                break;
            case 2:
                int add;
                printf("nhap so sinh vien can them vao: ");
                scanf("%d",&add);
                index = 0;
                index += n + add;
                for (int i=n;i<index;i++)
                    input(&temp[i]);
                break;
            case 3:
                int change_index;
                printf("nhap vao vi tri muon sua: ");
                scanf("%d",&change_index);
                input(&temp[change_index]);
                break;
            case 4:
                int delete_index;
                printf("nhap vi tri can xoa:");
                scanf("%d",&delete_index);
                for (int i=delete_index;i<index-1;i++)
                    temp[i] = temp[i+1];
                index--;
                break;
            case 5:
                for (int i=0;i<index;i++){
                    printf("sinh vien thu %d: ",i+1);
                    output(&temp[i]);   
                }
                break;
            case 6:
                printf("thoat\n");
                break;
            default:
                printf("khong hop le\n");
                break;
        }
    } while (choice != 8);
}
