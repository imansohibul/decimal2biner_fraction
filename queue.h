/*======================================================================*/
/* File        : queque.c 												*/
/* Deskripsi   : ADT Queque berkait dengan representasi fisik pointer	*/
/*				 Representasi address dengan pointer					*/
/*		 	 	InfoType adalah integer 								*/
/* Dibuat oleh : MOCHAMAD SOHIBUL IMAN 151511016						*/
/*				Kelas 1A - D3 Teknik Informatika						*/
/* MODIFIKASI DARI :													*/
/* Sumber Kode : Ade Chandra											*/
/* Tanggal Sumber DIbuat : 24-10-2001 									*/
/*======================================================================*/

#ifndef queque_H
#define	queqeu_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define Nil NULL
#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define Front(L) (L).Front
#define Rear(L) (L).Rear


typedef int infotype;
typedef struct tElmtListQue *addressQue;
typedef struct tElmtListQue {
    infotype Info;
    addressQue Next;
    }ElmtListQue;    

typedef struct {
     addressQue Front;
	 addressQue Rear;	
} ListQue;


void CreateListQue (ListQue * L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

addressQue AlokasiQue (infotype X);
/* Mengirimkan addressQue hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressQue != Nil, */
/* dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */


void DeAlokasiQue (addressQue P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressQue P ke system */

void Enque(ListQue * L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen terakhir dengan nilai X jika alokasi berhasil */

void InsertLast (ListQue * L, addressQue P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

void Deque(ListQue * L, infotype *X);
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir ListQue dihapus : nilai info disimpan pada X */
/* dan alamat elemen pertama di dealokasi */

void PrintInfoQue (ListQue L);
/* IS : L mungkin kosong */
/* FS : Jika ListQue tidak kosong, semua info yang disimpan pada elemen ListQue */
/* diprint. Jika ListQue kosong, hanya menuliskan "ListQue Kosong" */

#endif
