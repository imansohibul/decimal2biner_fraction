/*======================================================================*/
/* File : stack.c 												 		*/
/* Deskripsi : Body ADT Stack yang hanya dikenali L->TOP 			    */		
/* Dibuat oleh : MOCHAMAD SOHIBUL IMAN 151511016						*/
/*				Kelas 1A - D3 Teknik Informatika						*/
/* MODIFIKASI DARI :													*/
/* Sumber Kode : Ade Chandra											*/
/* Tanggal Sumber DIbuat : 24-10-2001 									*/
/*======================================================================*/
#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

/********** BODY SUB PROGRAM ***********/

/**** Konstruktor/Kreator ListStack Kosong ****/

void CreateListStack (ListStack *L)
/* IS : L sembarang */
/* FS : Terbentuk ListStack Kosong */
{
  L->TOP= Nil;
}

/**** Manajemen Memory ****/
addressStack AlokasiStack (infotype X)
/* Mengirimkan addressStack hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressStack != Nil, */
/* dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
 /* Kamus Lokal */
 addressStack P;
 /* Algoritma */
			 P = (addressStack)malloc(sizeof(ElmtListStack));
			 if (P != Nil) /* Alokasi berhasil */
			 {
					 P->info = X;
					 P->next = Nil;
			 }
			 
 return (P);
}

void DeAlokasiStack (addressStack P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressStack P ke system */
{
		 if (P != Nil)
		 {
		 	free (P);
		 }
} 


/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void Push (ListStack * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
 /* Kamus Lokal */
 addressStack P;
 /* Aloritma */
 P = AlokasiStack (X);
 
 	if (P != Nil)
 	{ 			
	 		InsertTOP (&(*L), P); 
 	}
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertTOP (ListStack * L, addressStack P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-addressStack P sebagai elemen pertama */
{
 P->next= L->TOP;
 L->TOP = P;
}

/**** Penghapusan Elemen ****/
void Pop (ListStack *L, infotype *X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama ListStack dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
{
 /* Kamus Lokal */
 addressStack P;
 /* Algoritma */
 P = L->TOP;
 *X=L->TOP->info;
 L->TOP= L->TOP->next;
 DeAlokasiStack (P);
} 


/**** PROSES SEMUA ELEMEN ListStack ****/
void PrintInfoStack (ListStack L)
/* IS : L mungkin kosong */
/* FS : Jika ListStack tidak kosong, semua info yang disimpan pada elemen ListStack */
/* diprint. Jika ListStack kosong, hanya menuliskan "ListStack Kosong" */
{
 /* Kamus Lokal */
 addressStack P;
 /* Algoritma */
 if (L.TOP == Nil)
 {
 		printf ("ListStack Kosong .... \a\n");
 }
  else /* ListStack memiliki elemen */
	 {
	 		P = L.TOP;
			for (;;)
	 		{
				 if (P == Nil)
				 {
					 break;
				 }
				 else /* Belum berada di akhir ListStack */
					 {
						 printf ("%d", P->info);
						 P = P->next;
					 }
			}
	 }
}


void PopAll(ListStack *L,infotype *X)
{
		while(L->TOP != NULL)
		{
			Pop(&(*L),&(*X));
		}
}


void reverseStack(ListStack *L) 
{



}