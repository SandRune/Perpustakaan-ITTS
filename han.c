#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char nama[100];
	char kode[10];
	char judul[100];
	char letak[100];
	int stok;
	int nim;
}data;

data perpus[100];
char kode, jd[100],user[10],pass[10],yt;
int pil,pil1,pil2,cuy,x,i,j,jml,hari,bayar;


void input(){
	system("cls");
	FILE*fp;
	fp=fopen("Data Buku.txt","a");
	x=x+1;
	printf("		Input Data Buku 		\n");
	printf("==============================\n\n");
	printf("Kode Buku\t:"); fflush(stdin); gets(perpus[x].kode);
	fprintf(fp,"Kode buku %s\n",perpus[x].kode);
	printf("Judul Buku\t:"); fflush(stdin); gets(perpus[x].judul);
	fprintf(fp,"Judul buku %s\n",perpus[x].judul);
	printf("Stok Buku\t:"); scanf("%d",&perpus[x].stok);
	fprintf(fp,"Stok buku %d\n",perpus[x].stok);
	printf("Letak Buku\t:"); scanf("%s",&perpus[x].letak);
	fprintf(fp,"Letak Buku %s\n",perpus[x].letak);
	fclose(fp);
}

void lihat(){
	system("cls");
	for(i=1;i<=x;i++){
		printf("		Data Buku 			\n");
		printf("==========================\n\n");
		printf("\tKode Buku\t: %s\n",perpus[i].kode);
		printf("\tJudul Buku\t: %s\n",perpus[i].judul);
		printf("\tStok Buku\t: %d\n",perpus[i].stok);
		printf("\tLetak Buku\t: %s\n",perpus[i].letak);
	}
}

void cari(){
	system("cls");
	printf("		Cari Data Buku 			\n");
	printf("==============================\n\n");
	printf("Masukan Judul : "); fflush(stdin); scanf("%[^\n]s",jd);
	for(i=1;i<=x;i++)
	{
		if(strcmp(jd,perpus[i].judul)==0)
		{
			cuy=i;
			printf("Kode Buku\t: %s\n",perpus[cuy].kode);
			printf("Judul Buku\t: %s\n",perpus[cuy].judul);
			printf("Letak BUku\t: %s\n",perpus[cuy].letak);
			if(perpus[i].stok<0){
				printf("\nStok Kosong !");
			}
			else if(perpus[i].stok>=0){
				printf("Stok Buku\t: %d\n",perpus[i].stok);
			}
		}
	}

}
void pinjam(){
	system("cls");
	printf("		Menu Pinjaman 			\n");
	printf("==============================\n\n");
	printf("Nama Peminjam\t\t\t: "); fflush(stdin); gets(perpus[j].nama);
	printf("NIM Peminjam\t\t\t: "); scanf("%d",&perpus[j].nim);
	printf("Masukkan Judul\t\t\t: "); fflush(stdin); scanf("%[^\n]s",jd);
	for(i=1;i<=x;i++){
		if(strcmp(jd,perpus[i].judul)==0)
		{
			printf("Judul Buku\t\t\t: %s\n",perpus[i].judul);
			printf("Stok Buku\t\t\t: %d\n",perpus[i].stok);
			printf("Letak Buku\t\t\t: %s\n",perpus[i].letak);
			printf("Jumlah dipinjam\t\t\t: "); scanf("%d",&jml);
			if(perpus[i].stok>=jml){
				perpus[i].stok-=jml;
			}
			else printf("Stok tidak mencukupi\n");
		}
	}
	printf("Lama Meminjam\t\t\t: "); scanf("%d",&hari);
	bayar=hari*500*jml;
	printf("Biaya yang dibayarkan\t\t: Rp %d\n",bayar);
}

void kembali(){
	system("cls");
	printf("		Menu Pengembalian 			\n");
	printf("==================================\n\n");
	printf("Nama Peminjam\t\t\t: "); fflush(stdin); gets(perpus[j].nama);
	printf("NIM Peminjam\t\t\t: "); scanf("%d",&perpus[j].nim);
	printf("Masukkan Judul\t\t\t: "); fflush(stdin); scanf("%[^\n]s",jd);
	for(i=1;i<=x;i++){
		if(strcmp(jd,perpus[i].judul)==0)
		{
			printf("Judul Buku\t\t\t: %s\n",perpus[i].judul);
			printf("Jumlah yang dipinjam\t\t: "); scanf("%d",&jml);
			printf("Lama Meminjam\t\t\t: "); scanf("%d",&hari);
			printf("Dengan Biaya : %d\n",bayar);
			if(perpus[i].stok>=0)
			perpus[i].stok+=jml;

		}
	}
}

void datapinjam(){
	for(i=1;i<=x;i++){
		if(strcmp(jd,perpus[i].judul)==0){
			system("cls");
			printf("		Data Pinjaman Buku 			\n");
			printf("==================================\n\n");
			printf("Nama Peminjam\t\t\t:%s\n",perpus[j].nama);
			printf("Data Pinjaman Buku\t\t:%s\n",perpus[i].judul);
			printf("Letak Buku\t: %s\n",perpus[i].letak);
			printf("Dengan Jumlah yang dipinjam\t:%d\n",jml);
			printf("Dengan Biaya %d\n",bayar);
		}
	}
}

void datakembali(){
	for(i=1;i<=x;i++){
		if(strcmp(jd,perpus[i].judul)==0){
			system("cls");
			printf("		Data Pengembalian Buku 			\n");
			printf("======================================\n\n");
			printf("Nama Peminjam\t\t\t:%s\n",perpus[j].nama);
			printf("Data Pengembalian Buku\t\t:%s\n",perpus[i].judul);
			printf("Dengan Jumlah yang dikembalikan\t:%d\n",jml);
		}
	}
}

int main()
{
	do
	{	system("cls");
		printf("=============== PROGRAM PERPUSTAKAAN ===============\n");
		printf("==================== IT TELKOM =====================\n");
		printf("===================== Surabaya =====================\n");
		printf("\n\n");
		printf("					Menu Pilihan					\n");
		printf("==================================================\n\n");
		printf("\t\t\tAnda Masuk Sebagai :");
		printf("\n\t\t\t1.Petugas Perpus\n\t\t\t2.Pengunjung Perpustakaan\n");
		printf("Pilihan : "); scanf("%d",&pil);
		if(pil==1){
			btt :
				system("cls");
				printf("Username\t: "); scanf("%s",&user);
				printf("Password\t: "); scanf("%s",&pass);
				if(strcmp(user,"ITTELKOM")==0&&strcmp(pass,"ITTELKOM")==0)
				{
					do{
						system("cls");
						printf("			Menu Pilihan 			\n");
						printf("==================================\n\n");
						printf("\t\t1.Input Data Buku\n\t\t2.Lihat Data Buku\n\t\t3.Data Pinjam\n\t\t4.Data Kembali\n\t\t5.Exit\n");
						printf("Pilihan : "); scanf("%d",&pil1);
						switch(pil1){
							case 1 :
								input();
								system("pause");
								break;
							case 2 :
								lihat();
								system("pause");
								break;
							case 3 :
								datapinjam();
								break;
							case 4 :
								datakembali();
								break;
							case 5 :
								break;
						}
					}while(pil1!=5);
				}
				else{
					system("cls");
					printf("Username dan Passwoord SALAH !\n\n");
					system("pause");
					goto btt;
				}
		}
		else if (pil==2){
			do{
				system("Pause");
				system("cls");
				printf("			Menu Pilihan 			\n");
				printf("==================================\n\n");
				printf("\t\t1.Cari buku\n\t\t2.Peminjaman Buku\n\t\t3.Pengembalian Buku\n\t\t4.Exit\n");
				printf("Pilihan : "); scanf("%d",&pil2);
				switch(pil2){
					case 1 :
						cari();
						break;
					case 2 :
						pinjam();
						break;
					case 3 :
						kembali();
						break;
					case 4 :
						break;
				}
			}while(pil2!=4);
			}else{
					system("cls");
					printf("BRO HIT THE GRIDDYDYY");
					system("pause");
					goto btt;
				}
	}
while(pil2!=5);

  printf("OOOOO MA GADDDDDDDD");

  return 0;}
