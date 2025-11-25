#include<stdio.h>
#include<string.h>
#define MAX 1000

struct Patient{
	char cardId[10];
	char name[50];
	char phone[15];
	double debt;
	int visitDays;
};

struct Record{
	char recId[20];
	char cardId[10];
	char date[20];
	char status[20];
};

int totalPatient = 0;
int totalRecord = 0;

void createNewPatient(struct Patient patient[]);
void updatePatientInfo(struct Patient patient[], struct Record record[]);

int main(){
	struct Patient patient[MAX];
	struct Record record[MAX];
	int choice;

	while(1){
		printf ("Chao mung ban den voi phan mem quan ly benh nhan!\n");
		printf ("\n");
		printf ("+===============QUAN LY BENH NHAN===============+\n");
		printf ("|1. Tiep nhan thong tin benh nhan               |\n");
		printf ("|2. Cap nhat thong tin benh nhan                |\n");
		printf ("|3. Xuat vien                                   |\n");
		printf ("|4. Hien thi danh sach benh nhan                |\n");
		printf ("|5. Tim kiem benh nhan                          |\n");
		printf ("|6. Sap xep danh sach benh nhan                 |\n");
		printf ("|7. Ghi nhan kham benh                          |\n");
		printf ("|8. Xem lich su kham benh                       |\n");
		printf ("|9. Thoat phan mem                              |\n");
		printf ("+===============================================+\n");
		printf ("\n");
		printf ("Vui long chon chuc nang: ");
		scanf ("%d", &choice);
		getchar();
	
		switch(choice){
			case 1:{
				createNewPatient(patient);
				break;
			}
			case 2:{
				updatePatientInfo(patient, record);
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				break;
			}
			case 5:{
				break;
			}
			case 6:{
				break;
			}
			case 7:{
				break;
			}
			case 8:{
				break;
			}
			case 9:{
				printf ("Thoat phan mem. Cam on ban da su dung phan mem cua chung toi!\n");
				break;
			}
			default:{
				printf ("Lua chon cua ban khong hop le! Vui long chon lai chuc nang\n");
				break;
			}
		}
	}
}

void createNewPatient(struct Patient patient[]){
	if (totalPatient >= MAX){
		printf ("Danh sach benh nhan da day!");
		return;
	}
	
	printf ("Ma ho so/CCCD: ");
	fgets (patient[totalPatient].cardId, sizeof(patient[totalPatient].cardId), stdin);
	if (strlen(patient[totalPatient].cardId) == 0){
		printf ("Ma ho so khong duoc de trong!\n");
		return;
	}
	for (int i = 0; i < totalPatient; i++){
		if (strcmp(patient[i].cardId, patient[totalPatient].cardId) == 0){
			printf("Ma ho so bi trung!\n");
			return;
		}
	}
	
	printf ("Ten benh nhan: ");
	fgets (patient[totalPatient].name, sizeof(patient[totalPatient].name), stdin);
	if (strlen(patient[totalPatient].name) == 0){
		printf ("Ten benh nhan khong duoc de trong!\n");
		return;
	}
	
	printf ("So dien thoai: ");
	fgets (patient[totalPatient].phone, sizeof(patient[totalPatient].phone), stdin);
	if (strlen(patient[totalPatient].phone) == 0){
		printf ("So dien thoai khong duoc de trong!\n");
		return;
	}
	
	printf ("Cong no ban dau: ");
	scanf ("%.3lf", &patient[totalPatient].debt);
	
	printf ("So ngay dieu tri: ");
	scanf ("%d", &patient[totalPatient].visitDays);
	
	totalPatient++;
	printf ("Tiep nhan benh nhan thanh cong\n");
};

void updatePatientInfo(struct Patient patient[], struct Record record[]){
	if (totalPatient == 0){
		printf ("Khong tim thay benh nhan!\n");
		return;
	}
	char searchCardId[10];

	printf ("Nhap ma ho so/CCCD cua benh nhan muon cap nhat thong tin: \n");
	fgets (searchCardId, sizeof(searchCardId), stdin);
	searchCardId[strcspn(searchCardId, "\n")] = 0;
	
	int found = -1;
	for (int i = 0; i < totalPatient; i++){
		if (strcmp(patient[i].cardId, searchCardId) == 0){
			found = i;
			break;
		}
	}
	if (found == -1){
		printf ("Khong tim thay benh nhan!\n");
		return;
	}
	
	for (int i = totalRecord - 1; i >= 0; i--){
		if (strcmp(record[i].cardId, searchCardId) == 0) {
            if (strcmp(record[i].status, "Benh nhan da xuat vien") == 0){
                printf("Khong the cap nhat thong tin vi benh nhan da xuat vien!\n");
                return;
            }
            break;
        }
	}
	
	char newPhone[15];
	printf ("Da tim thay benh nhan!\n");
	printf ("Cap nhat so dien thoai moi: ");
	fgets (newPhone, sizeof(newPhone), stdin);
	newPhone[strcspn(newPhone, "\n")] = 0;
	
	if (strlen(newPhone) < 9){
		printf ("So dien thoai khong hop le!\n");
		return;
	}

	strcpy (patient[found].phone, newPhone);
	printf ("Cap nhat so dien thoai moi thanh cong!\n");
};
