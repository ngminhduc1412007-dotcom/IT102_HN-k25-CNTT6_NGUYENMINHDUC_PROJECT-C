#include<stdio.h>
#include<string.h>
#include<ctype.h>
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

struct Patient listPatient[MAX]={
	{"0001", "Nguyen Le Huy", "0987123456", 100, 10},
	{"0002", "Tran Hai Nam Hung", "0912345876", 500, 1},
	{"0003", "Do Duc Kien", "0987654123", 300, 30},
};

void toLowerString(char str[]){
	for (int i = 0; str[i]; i++){
		str[i]=tolower(str[i]);
	}
}//ham dung de chuyen chu hoa thanh chu thuong

int totalPatient = 3;
int totalRecord = 0;

void createNewPatient(struct Patient patient[]);
void updatePatientInfo(struct Patient patient[], struct Record record[]);
void dischargePatient(struct Patient patient[]);
void showCurrentPatient(struct Patient[]);
void searchPatient(struct Patient patient[]);
void softByDebt(struct Patient patient[]);

int main(){
	struct Patient patient[MAX];
	struct Record record[MAX];
	int choice;
	
	for(int i = 0; i < totalPatient; i++){// sao chep du lieu tu listpatient sang patient 
        patient[i] = listPatient[i];
    }

	while(1){
//		system ("cls");
		printf ("\n");
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
				dischargePatient(patient);
				break;
			}
			case 4:{
				showCurrentPatient(patient);
				break;
			}
			case 5:{
				searchPatient(patient);
				break;
			}
			case 6:{
				softByDebt(patient);
				break;
			}
			case 7:{
				break;
			}
			case 8:{
				break;
			}
			case 9:{
				printf ("Thoat phan mem...\n");
				printf ("Cam on ban da su dung phan mem cua chung toi!\n");
				break;
			}
			default:{
				printf ("Lua chon cua ban khong hop le! Vui long chon lai chuc nang\n");
				break;
			}
		}
	}
}
//chuc nang 1
void createNewPatient(struct Patient patient[]){

//	system ("cls");

	if (totalPatient >= MAX){
		printf ("Danh sach benh nhan da day!");
		return;
	}
	
	printf ("Ma ho so/CCCD: ");
	fgets (patient[totalPatient].cardId, sizeof(patient[totalPatient].cardId), stdin);
	patient[totalPatient].cardId[strcspn(patient[totalPatient].cardId, "\n")] = 0;
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
	patient[totalPatient].name[strcspn(patient[totalPatient].name, "\n")] = 0;
	if (strlen(patient[totalPatient].name) == 0){
		printf ("Ten benh nhan khong duoc de trong!\n");
		return;
	}
	
	printf ("So dien thoai: ");
	fgets (patient[totalPatient].phone, sizeof(patient[totalPatient].phone), stdin);
	patient[totalPatient].phone[strcspn(patient[totalPatient].phone, "\n")] = 0;
	if (strlen(patient[totalPatient].phone) == 0){
		printf ("So dien thoai khong duoc de trong!\n");
		return;
	}
	if (strlen(patient[totalPatient].phone) < 9){
		printf ("So dien thoai khong hop le!\n");
		return;
	}

	printf ("Cong no ban dau: ");
	scanf ("%lf", &patient[totalPatient].debt);
	if (patient[totalPatient].debt < 0){
		printf ("Cong no khong hop le!\n");
		return;
	}
	
	printf ("So ngay dieu tri: ");
	scanf ("%d", &patient[totalPatient].visitDays);
	if( patient[totalPatient].visitDays < 0){
		printf ("So ngay dieu tri khong hop le!\n");
		return;
	}
	getchar(); 
	
	totalPatient++;
	printf ("Tiep nhan benh nhan thanh cong\n");
}
//chuc nang 2
void updatePatientInfo(struct Patient patient[], struct Record record[]){

//	system ("cls"); 

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
//		system ("cls");
		printf ("Khong tim thay benh nhan!\n");
	}else{
//		system ("cls");
		printf ("+===============HIEN THI BENH NHAN===============+\n");
		printf ("| Ma ho so/CCCD: %s                              \n", patient[found].cardId);
		printf ("| Ten benh nhan: %s                              \n", patient[found].name);
		printf ("| So dien thoai: %s                              \n", patient[found].phone);
		printf ("| Cong no: %lf                                   \n", patient[found].debt);
		printf ("| So ngay dieu tri: %d                           \n", patient[found].visitDays);
		printf ("+===============================================+\n");
	}
	
	for (int i = totalRecord - 1; i >= 0; i--){
		if (strcmp(record[i].cardId, searchCardId) == 0){
            if (strcmp(record[i].status, "Benh nhan da xuat vien") == 0){
                printf("Khong the cap nhat thong tin vi benh nhan da xuat vien!\n");
                return;
            }
            break;
        }
	}
	
	char newPhone[15];
	printf ("Da tim thay benh nhan!\n");
	printf ("\n");
	
	printf ("Cap nhat so dien thoai moi: ");
	fgets (newPhone, sizeof(newPhone), stdin);
	newPhone[strcspn(newPhone, "\n")] = 0;
	
	if (strlen(newPhone) < 9){
		printf ("So dien thoai khong hop le!\n");
		return;
	}

	strcpy (patient[found].phone, newPhone);
	printf ("Cap nhat so dien thoai moi thanh cong!\n");
}
//chuc nang 3
void dischargePatient(struct Patient patient[]){

//	system ("cls");

	if (totalPatient == 0){
		printf ("Khong tim thay benh nhan!\n");
		return;
	}
	
	char searchCardId[10];
	printf ("Ma ho so/CCCD benh nhan can xuat vien: ");
	fgets(searchCardId, sizeof(searchCardId), stdin);
	searchCardId[strcspn(searchCardId, "\n")] = 0;
	
	int found = -1;
	for (int i = 0; i < totalPatient; i++){
		if (strcmp(patient[i].cardId, searchCardId)==0){
			found = i;
			break;
		}
	}
	
	if (found == -1){
		printf ("Khong co tim thay benh nhan trong danh sach!\n");
		return;
	}
	
	if (patient[found].debt > 0){
		printf ("Benh nhan con no cong can thanh toan!\n");
		printf ("So tien con no la: %fl\n", patient[found].debt);
		printf ("Ban co muon xuat vien khong(Y/N)?");
		char confirm;
		printf ("Xac nhan cua ban: \n");
		scanf ("%c", &confirm);
		getchar();
		
		if (confirm == 'N' || confirm == 'n'){
			printf ("Benh nhan khong xuat vien!\n");
			return;
		}
	}
	for (int i = found; i < totalPatient - 1; i++){
		patient[i] = patient[i + 1];
	}
	totalPatient--;
	printf ("Benh nhan da xuat vien!\n");
}
//chuc nang 4
void showCurrentPatient(struct Patient patient[]){

//	system ("cls");

	if (totalPatient == 0){
		printf ("Khong co benh nhan nao trong danh sach!\n");
		return;
	}
	int pageSize = 2;
	int totalPage = (totalPatient + pageSize - 1) / pageSize;
	int curentPage = 0;

	while(1){
		printf ("+===============HIEN THI BENH NHAN===============+\n");
		int start = curentPage * pageSize;
		int end = start + pageSize;
		if (end > totalPatient){
			end = totalPatient;
		}
		for (int i = start; i < end; i++){
			printf ("| Ma ho so/CCCD: %s                              \n", patient[i].cardId); 
			printf ("| Ten benh nhan: %s                              \n", patient[i].name);
			printf ("| So dien thoai: %s                              \n", patient[i].phone);
			printf ("| Cong no: %lf                                   \n", patient[i].debt);
			printf ("| So ngay dieu tri: %d                           \n", patient[i].visitDays);
		}
		printf ("+===================TRANG %d/%d====================+\n", curentPage + 1, totalPage);
		char choice;
		printf ("P: trang truoc | N: trang sau | Q: thoat\n");
		printf ("Hay nhap lua chon cua ban: ");
		scanf (" %c", &choice);
		getchar(); 
//		system("cls");
		if (totalPage > 1){
			if (choice == 'P' || choice == 'p'){
				if (curentPage > 0){
					curentPage--;
				}
			}else if (choice == 'N' || choice == 'n'){
				if (curentPage < totalPage - 1){
					curentPage++;
				}
			}else if (choice == 'Q' || choice == 'q'){
				break;
			}
		}else{
			if (choice == 'Q' || choice == 'q'){
				break;
			}
		}
	}
}
//chuc nang 5
void searchPatient(struct Patient patient[]){
	if (totalPatient == 0){
		printf ("Khong tim thay benh nhan!\n");
		return;
	}
	getchar();
	while(1){
		printf ("+===============TIM KIEM BENH NHAN===============+\n");
		printf ("|1. Tim kiem theo ma ho so/CCCD                  |\n");
		printf ("|2. Tim kiem theo ten benh nhan                  |\n");
		printf ("|3. Thoat tim kiem                               |\n");
		printf ("+================================================+\n");
		int choice;
		printf ("Vui long chon chuc nang tim kiem: ");
		scanf ("%d", &choice);
		getchar();

		if (choice == 1){
			char searchCardId[10];
			printf ("Ma ho so/CCCD benh nhan can tim kiem: ");
			fgets(searchCardId, sizeof(searchCardId), stdin);
			searchCardId[strcspn(searchCardId, "\n")] = 0;
			if (strlen(searchCardId) == 0){
				printf ("Ma ho so khong duoc de trong!\n");
				return;
			}
			int found = 0;
			for (int i = 0; i < totalPatient; i++){
				if(strcmp(patient[i].cardId, searchCardId)==0){
					found = 1;
//					system ("cls");
					printf ("+===============HIEN THI BENH NHAN===============+\n");
					printf ("| Ma ho so/CCCD: %s                               \n", patient[i].cardId);
					printf ("| Ten benh nhan: %s                               \n", patient[i].name);
					printf ("| So dien thoai: %s                               \n", patient[i].phone);
					printf ("| Cong no: %lf                                    \n", patient[i].debt);
					printf ("| So ngay dieu tri: %d                            \n", patient[i].visitDays);
					printf ("+================================================+\n");
					break;
				}
			}
			if (!found){
//				system ("cls");
				printf ("Khong tim thay benh nhan!\n");
			}
		}else if (choice == 2){
			char searchName[50];
			printf ("Ten benh nhan can tim kiem: ");
			fgets(searchName, sizeof(searchName), stdin);
			searchName[strcspn(searchName, "\n")] = 0;
			if (strlen(searchName) == 0){
				printf ("Ten benh nhan khong duoc de trong!\n");
				return;
			}
			toLowerString(searchName);//chuyen chuoi tim kiem tu chu hoa thanh chu thuong
			int found = 0;
			for (int i = 0; i < totalPatient; i++){
				//tao ban sao ten cua benh nhan va chuyen chu hoa thanh chu thuong
				char patientLowerName[50];
				strcpy(patientLowerName, patient[i].name);
				toLowerString(patientLowerName);
        		if(strstr(patient[i].name, searchName) != NULL){
//          		printPatient(patient[i]);
            		found = 1;
//					system ("cls");
					printf ("+===============HIEN THI BENH NHAN==============+\n");
					printf ("| Ma ho so/CCCD: %s                              \n", patient[i].cardId);
					printf ("| Ten benh nhan: %s                              \n", patient[i].name);
					printf ("| So dien thoai: %s                              \n", patient[i].phone);
					printf ("| Cong no: %lf                                   \n", patient[i].debt);
					printf ("| So ngay dieu tri: %d                           \n", patient[i].visitDays);
					printf ("+===============================================+\n");
					break;
        		}
    		}
			if(!found){
//				system ("cls");
				printf ("Khong tim thay benh nhan!\n");
			}
		}else if (choice == 3){
			printf ("Thoat chuc nang tim kiem benh nhan!\n");
			break;
		}else{
			printf ("Lua chon cua ban khong hop le! Vui long chon lai chuc nang\n");
		}
	}
}
//chuc nang 6
void softByDebt(struct Patient patient[]){
	if (totalPatient == 0){
		printf ("Khong co benh nhan nao trong danh sach!\n");
		return;
	}
	getchar();
	while(1){
		printf ("+===============SAP XEP BENH NHAN================+\n");
		printf ("|1. Sap xep theo cong no tang dan                |\n");
		printf ("|2. Sap xep theo cong no giam dan                |\n");
		printf ("|3. Thoat sap xep                                |\n");
		printf ("+================================================+\n");
		int choice;
		printf ("Vui long chon chuc nang sap xep: ");
		scanf ("%d", &choice);
		getchar();

		if (choice == 1){
			for (int i = 0; i < totalPatient - 1; i++){
				for (int j = i + 1; j < totalPatient; j++){
					if (patient[i].debt > patient[j].debt){
						struct Patient temp = patient[i];
						patient[i] = patient[j];
						patient[j] = temp;
					}
				}
			}
			printf ("Sap xep benh nhan theo cong no tang dan thanh cong!\n");
		}else if (choice == 2){
			for (int i = 0; i < totalPatient - 1; i++){
				for (int j = i + 1; j < totalPatient; j++){
					if (patient[i].debt < patient[j].debt){
						struct Patient temp = patient[i];
						patient[i] = patient[j];
						patient[j] = temp;
					}
				}
			}
			printf ("Sap xep benh nhan theo cong no giam dan thanh cong!\n");
		}else if (choice == 3){
			printf ("Thoat chuc nang sap xep benh nhan!\n");
			break;
		}else{
			printf ("Lua chon cua ban khong hop le! Vui long chon lai chuc nang\n");
			continue;
		}
		int pageSize = 2;
		int totalPage = (totalPatient + pageSize - 1) / pageSize;
		int curentPage = 0;
	
		while(1){
			printf ("+===============HIEN THI BENH NHAN===============+\n");
			int start = curentPage * pageSize;
			int end = start + pageSize;
			if (end > totalPatient){
				end = totalPatient;
			}
			for (int i = start; i < end; i++){
				printf ("| Ma ho so/CCCD: %s                              \n", patient[i].cardId); 
				printf ("| Ten benh nhan: %s                              \n", patient[i].name);
				printf ("| So dien thoai: %s                              \n", patient[i].phone);
				printf ("| Cong no: %lf                                   \n", patient[i].debt);
				printf ("| So ngay dieu tri: %d                           \n", patient[i].visitDays);
			}
			printf ("+===================TRANG %d/%d====================+\n", curentPage + 1, totalPage);
			char choice;
			printf ("P: trang truoc | N: trang sau | Q: thoat\n");
			printf ("Hay nhap lua chon cua ban: ");
			scanf (" %c", &choice);
			getchar(); 
//			system("cls");
			if (totalPage > 1){
				if (choice == 'P' || choice == 'p'){
					if (curentPage > 0){
						curentPage--;
					}
				}else if (choice == 'N' || choice == 'n'){
					if (curentPage < totalPage - 1){
						curentPage++;
					}
				}else if (choice == 'Q' || choice == 'q'){
					break;
				}
			}else{
				if (choice == 'Q' || choice == 'q'){
					break;
				}
			}
		}
	}
}
