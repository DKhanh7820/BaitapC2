#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct TyperArr 
{
    int *ptr; //luu dia chi dau tien cua mang
    int size; //luu kich thuoc cua mang
}TyperArr;

 TyperArr *NhapThongTin(TyperArr *value){

    printf("\nNhap vao kich thuoc cua mang: ");
    scanf("%d", &value->size);

    value->ptr = (int*)malloc(value->size * sizeof(int));//tao mang cap phat dong va dia chi dau tien cua mang se duoc luu vao ptr 
    
    for(int i = 0; i < value->size; i++)
    {
      printf("Nhap gia tri tai arr[%d]: ",i);
      scanf("%d", &value->ptr[i]);
    };

}
// viet chuong trinh nhap vao cac so ngau nhien, roi luu vao trong mang arr[]
//nhan 1: sap xep theo thu tu tu be den lon
//nhan 2: sap xep theo thư tu tu lon den be
//nhan 3: tim so lon nhat
//nhan 4: thoat chuong trinh


void BedenLon(TyperArr *value){

int i , j, Min, temp;
  for(i = 0; i < (value->size-1); i++)
  {
     Min = i;
     for(j = i + 1; j < value->size; j++)
     {
       if(value->ptr[j] < value->ptr[Min])
       {
         Min = j;
       }
     }

 temp = value->ptr[i];
 value->ptr[i] = value->ptr[Min];
 value->ptr[Min] = temp;
  }

}
void LonDenBe( TyperArr *value){
int i , j, Max, temp;
  for( i = 0; i < (value->size-1); i++)
  {
     Max = i;
     for( j = i + 1; j < value->size; j++)
     {
       if(value->ptr[j] > value->ptr[Max])
       {
         Max = j;
       }
     }

 temp = value->ptr[i];
 value->ptr[i] = value->ptr[Max];
 value->ptr[Max] = temp;

}
}
void TimsoLonNhat( TyperArr value)
{

int i, max;
for( i = 0; i < value.size; i++)
{
    max = value.ptr[0];
}
for(i = 1; i < value.size; i++)
{
    if(value.ptr[i] > max)
    {
        max = value.ptr[i];
    }
}
printf("%d\n", max);
}

int main(int argc, char const *argv[]){

     TyperArr value;
     int choice;
    NhapThongTin(&value);

    for(int i = 0; i < value.size; i++){
        printf("arr[%d]: %d\n", i, value.ptr[i]);
    };
    do{      
    printf("1. Hien thi mang tu be den lon:\n");
    printf("2. Hien thi mang tu lon den be:\n");
    printf("3. Tim so lon nhat trong mang:\n");
    printf("4. Thoat chuong trinh:\n");
    printf("Nhap lua chon:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
            BedenLon(&value);
            printf("Mang da thay doi tu be den lon:\n");
             for(int i = 0; i < value.size; i++)
             {
               printf("arr[%d]: %d\n", i, value.ptr[i]);
             }
        break;
    case 2:
            LonDenBe(&value);
            printf("Mang da thay doi tu lon den be:\n");
             for(int i = 0; i < value.size; i++)
             {
               printf("arr[%d]: %d\n", i, value.ptr[i]);
             };
        break;
    case 3:
            printf("So lon nhat la: ");
            TimsoLonNhat(value);
        break;
    case 4:
        return 0;
        break;    
    default:
        printf("Lua chon khong hop le:\n");
        break;
    }
    }
    while (choice = 4);
    return 0;
}
