#include<stdio.h>
#include<string.h>
struct Books {
    int book_id;
    char book_name[100];
    char author[100];
    long price;
    char category[100]; 
};
typedef struct Books book;
void input(book *temp){
    printf("nhap ma sach:");
    scanf("%d",&temp->book_id);
    printf("nhap ten sach:");
    getchar();
    gets(temp->book_name);
    printf("nhap tac gia:");
    getchar();
    gets(temp->author);
    printf("nhap gia:");
    scanf("%d",&temp->price);
    printf("nhap the loai:");
    getchar();
    gets(temp->category);
}
void output( book *temp){
    printf("ma sach:%d, ten sach:%s, tac gia:%s, gia tien:%d, the loai:%s\n",temp->book_id, temp->book_name, temp->author, temp->price, temp->category);
}
void price_sort_increase(book temp[], int index){
    for (int i=0;i<index-1;i++){
        for (int j=i+1;j<index;j++) {
            if (temp[i].price > temp[j].price){
                book t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
}
void price_sort_decrease(book temp[], int index){
    for (int i=0;i<index-1;i++){
        for (int j=i+1;j<index;j++) {
            if (temp[i].price < temp[j].price){
                book t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
}
int main(){
    book temp[100];
    int n,i;
    int choice;
    int index;
    do {
        printf("\n1.nhap vao danh sach sach\n");
        printf("2.hien thi tong tin sach\n");
        printf("3.them sach vao vi tri\n");
        printf("4.xoa sach theo id\n");
        printf("5.cap nhat thong tin sach theo ma sach\n");
        printf("6.sap xep theo gia\n");
        printf("7.tim kiem theo ten sach\n");
        printf("8.tim kiem theo khoang gia\n");
        printf("9.thoat\n");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("nhap vao so luong sach:");
                scanf("%d",&n);
                for (int i=0;i<n;i++)
                    input(&temp[i]);
                index = n;
                break;
            case 2:
                for (i=0;i<index;i++) {
                    printf("%d:",i+1);
                    output(&temp[i]);
                }
                break;
            case 3:
                int add_index;
                printf("nhap vi tri can chen thong tin:");
                scanf("%d",&add_index);
                for (i=index;i>=add_index;i--){
                    temp[i] = temp[i-1];
                    if (i == add_index)
                        input(&temp[i]);
                }
                index++;
                break;
            case 4:
                int delete_id;
                printf("nhap vao id can xoa:");
                scanf("%d",&delete_id);
                for (i=0;i<index;i++) {
                    if (temp[i].book_id == delete_id)
                    for (int j=i;j<index-1;j++)
                    temp[i] = temp [i+1];
                }
                index--;
                break;
            case 5:
                int find_id;
                printf("nhap vao id can cap nhat:");
                scanf("%d",&find_id);
                for (i=0;i<index;i++) {
                    if (temp[i].book_id == find_id)
                        input(&temp[i]);
                }
                break;
            case 6:
                int sort_choice;
                printf("lua chon cach sap xep:\n");
                printf("1.tang dan\n");
                printf("2.giam dan\n");
                scanf("%d",&sort_choice);
                switch(sort_choice){
                    case 1:
                        price_sort_increase(temp,index);
                        break;
                    case 2:
                        price_sort_decrease(temp,index);
                        break;
                    default:
                        printf("khong hop le");
                        break;                   
                }
                break;
            case 7:
                char find_name[10];
                printf("nhap vao ten can tim:");
                fgets(find_name,10,stdin);
                for (i=0;i<index;i++) {
                    if ( strcmp(temp[i].book_name,find_name) )  
                        output(&temp[i]);
                }
                break;
            case 8:
                int first_price,last_price;
                printf("nhap vao gia tri dau tien:");
                scanf("%d",&first_price);
                printf("nhap vao gia tri dau cuoi:");
                scanf("%d",&last_price);
                for (i=0;i<index;i++) {
                    if ( (temp[i].price > first_price) && (temp[i].price < last_price))
                        output(&temp[i]);
                }
                break;
            case 9:
                printf("thoat\n");
                break;
            default:
                printf("khong hop le\n");
                break;
        }
    } while (choice != 9);
}
