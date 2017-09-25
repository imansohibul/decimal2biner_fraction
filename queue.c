/*======================================================================*/
/* File        : queque.h 												*/
/* Deskripsi   : ADT Queque berkait dengan representasi fisik pointer	*/
/*				 Representasi address dengan pointer					*/
/*		 	 	InfoType adalah integer 								*/
/* Dibuat oleh : MOCHAMAD SOHIBUL IMAN 151511016						*/
/*				Kelas 1A - D3 Teknik Informatika						*/
/* MODIFIKASI DARI :													*/
/* Sumber Kode : Ade Chandra											*/
/* Tanggal Sumber DIbuat : 24-10-2001 									*/
/*======================================================================*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void CreateListQue (ListQue * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
 	Front(*L) = Nil;
}

/**** Manajemen Memory ****/
addressQue AlokasiQue (infotype X)
/* Mengirimkan addressQue hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressQue != Nil, */
/* dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
 /* Kamus Lokal */
 addressQue P;
 /* Algoritma */
			 P = (addressQue) malloc (sizeof (ElmtListQue));
			 if (P != Nil) /* Alokasi berhasil */
			 {
					 P->Info = X;
					 P->Next = Nil;
			 }
			 
 return (P);
}

void DeAlokasiQue (addressQue P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressQue P ke system */
{
		 if (P != Nil)
		 {
		 	free (P);
		 }
} 

void Enque(ListQue * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen terakhir dengan nilai X jika alokasi berhasil */
{
 /* Kamus Lokal */
 addressQue P;
 /* Aloritma */
 P = AlokasiQue (X);
 if (P != Nil)
 { InsertLast (&(*L), P); }
}

void InsertLast (ListQue * L, addressQue P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
 /* Kamus Lokal */
 addressQue Last;
 /* Algoritma */
		 if (Front(*L) != Nil)
		 {
			Next(Rear(*L))= P;
			Rear(*L)=P;
		 }
		  else
			 { Front(*L) = P;
			   Rear(*L)  = Front(*L);
			 }
}

void Deque(ListQue *L, infotype *X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir ListQue dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
{
 /* Kamus Lokal */
 addressQue PDel;
 /* Algoritma */
 PDel = L->Front;
 *X=L->Front->Info;
 L->Front=L->Front->Next;
 
 DeAlokasiQue (PDel);
}

/**** PROSES SEMUA ELEMEN ListQue ****/
void PrintInfoQue (ListQue L)
/* IS : L mungkin kosong */
/* FS : Jika ListQue tidak kosong, semua info yang disimpan pada elemen ListQue */
/* diprint. Jika ListQue kosong, hanya menuliskan "ListQue Kosong" */
{
 /* Kamus Lokal */
 addressQue P;
 /* Algoritma */
 if (L.Front == Nil)
 {
 		printf ("ListQue Kosong .... \a\n");
 }
  else /* ListQue memiliki elemen */
	 {
	 		P = L.Front;
			for (;;)
	 		{
				 if (P == NULL)
				 {
					
					 break;
				 }
				 else /* Belum berada di akhir ListQue */
					 {
						 printf ("%d", P->Info);
						 P = P->Next;
					 }
			}
	 }
}

