#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SinhVien
{
    int id;
    char name[50];
    char birthday[50];
    char address[50];
    int status;
};
struct SinhVien studentList[100];
typedef struct SinhVien sv;
void output(sv studentList[], int i)
{
    printf("ID: %d, Name: %s, Birthday: %s, Address: %s, Status:%d \n",
           studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
}
void input(sv studentList[], int i)
{
    printf("Nhap id: ");
    scanf("%d", &studentList[i].id);
    printf("Nhap Name: ");
    getchar();
    gets(studentList[i].name);

    printf("Nhap Birthday: ");
    gets(studentList[i].birthday);

    printf("Nhap Address: ");
    gets(studentList[i].address);

    printf("Nhap status: ");
    scanf("%d", &studentList[i].status);
    printf("\n");
}

int main(){
	char find_name[50];
	int i,j,n;
	int currentIndex = 2;
    int count;
    struct SinhVien studentList[2] =
        {
            {1, "Tien", "6/12/2005", "23 Tu liem", 1},
            {2, "Hue", "15/4/2005", "13 Le Loi", 0}};
	do{
		printf("1. In toan bo danh sach sinh vien co trong mang StudentList tren cung mot hang\n");
		printf("2. Them sinh vien vao vi tri cuoi cung\n");
		printf("3. Cap nhat thong tin cua sinh vien\n");
		printf("4. Xoa sinh vien\n");
		printf("5. sap xep va in ra danh sach sau khi sap xep\n");
		printf("6. Tim kiem va in ra thong tin sinh vien\n");
		printf("7. Tim kiem va in ra thong tin sinh vien theo status\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban: ");
		
		int choice;
		scanf("%d",&choice);
		switch (choice){
			case 1:
			for ( i = 0; i < currentIndex; i++){
                output(studentList, i);
            }
				break;
			case 2:
            printf("Nhap so sinh vien can them ");
            scanf("%d", &n);
            for (i = 0; i < n; i++){
                input(studentList, currentIndex);
                currentIndex++;
            }
				break;
			case 3:
			printf("Nhap ten sinh vien muon thay doi thong tin: ");
            count = 0;
            char update_name[50];
            getchar();
            gets(update_name);
            for (i = 0; i < currentIndex; i++)
            {
                if (strcmp(update_name, studentList[i].name) == 0)
                {
                    input(studentList, i);
                    count = 1;
                }
            }
            if (count == 0)
            {
                printf("Khong tim thay");
            }
				break;
			case 4:
			printf("Nhap ten sinh vien muon xoa:");
            count = 0;
            char delete_name[50];
            getchar();
            gets(delete_name);
            for (i = 0; i < currentIndex; i++){
                if (strcmp(delete_name, studentList[i].name) == 0){
                    for (j = i; j < currentIndex -1; j++){
                        studentList[j] = studentList[j + 1];
                    }
                    count = 1;
                }
            }
            currentIndex --;
            if (count == 0)
            {
                printf("Khong tim thay\n");
            }
				break;
			case 5:
			for (i = 0; i < currentIndex - 1; i++){
                for (j = 0; j < currentIndex - i - 1; j++){
                    if (studentList[j].name[0] > studentList[j + 1].name[0]){
                        sv temp = studentList[j];
                        studentList[j] = studentList[j + 1];
                        studentList[j + 1] = temp;
                    }
                }
            }
            	for ( i = 0; i < currentIndex; i++){
                output(studentList, i);
            }
				break;
			case 6:
			
            printf("nhap ten can tim kiem:");
            getchar();
            gets(find_name);
            int start = 0;
            int end = currentIndex;
            int mid;
            while (start <= end){
                mid = (start + end) / 2;
                if (strcmp(studentList[mid].name, find_name) == 0){
                    break;
                }
                else if (studentList[mid].name < find_name){
                    start = mid + 1;
                }else{
                end = mid - 1;
                }
            }
            if (strcmp(studentList[mid].name, find_name) == 0){
                output(studentList, mid);
            }else{
                printf("Khong tim thay ");
            }
            break;
				break;
			case 7:
				printf("Nhap so status: ");
            	int find_status;
            	scanf("%d", &find_status);
            	for (i = 0; i < currentIndex; i++){
                	if (studentList[i].status == find_status){
                    output(studentList, i);
                }
            }
				break;
			case 8:
				exit(0);
			default:
				printf("Vui long chon lai ");
		}
	}while ( 1 == 1);
}
