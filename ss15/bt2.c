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
void output( std temp){
    printf("ten:%s \ntuoi:%d \nsdt:%d \nemail:%s \n",temp.name, temp.age, temp.phone_number, temp.email_adress);
}
int main(){
    std temp;
    input(&temp);
    output(temp);   
}
