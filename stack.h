/*======================================================================*/
/* File        : stack.h 												*/
/* Deskripsi   : ADT Stack berkait dengan representasi fisik pointer	*/
/*				 Representasi address dengan pointer					*/
/*		 	 	InfoType adalah integer 								*/
/* Dibuat oleh : MOCHAMAD SOHIBUL IMAN 151511016						*/
/*				Kelas 1A - D3 Teknik Informatika						*/
/* MODIFIKASI DARI :													*/
/* Sumber Kode : Ade Chandra											*/
/* Tanggal Sumber DIbuat : 24-10-2001 									*/
/*======================================================================*/

#ifndef stack_H
#define	stack_H
#include <stdbool.h>
#include <stdio.h>
#define Nil NULL


typedef int infotype;
typedef struct tElmtListStack *addressStack;
typedef struct tElmtListStack {
    infotype info;
    addressStack  next;
    } ElmtListStack;    

typedef struct {
     addressStack TOP;	
} ListStack;


/**** Konstruktor/Kreator ListStack Kosong ****/
void CreateListStack (ListStack * L);
/* IS : L sembarang */
/* FS : Terbentuk ListStack Kosong */

/**** Manajemen Memory ****/
addressStack AlokasiStack (infotype X);
/* Mengirimkan addressStack hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressStack != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DeAlokasiStack (addressStack P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian addressStack P ke system */

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void Push (ListStack * L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsertTOP (ListStack * L, addressStack P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-addressStack P sebagai elemen pertama */

/**** Penghapusan Elemen ****/
void Pop (ListStack * L, infotype *X);
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama ListStack dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

/**** PROSES SEMUA ELEMEN ListStack  ****/
void PrintInfoStack (ListStack L);
/* IS : L mungkin kosong */
/* FS : Jika ListStack tidak kosong, semua info yang disimpan pada elemen ListStack */
/*	diprint. Jika ListStack kosong, hanya menuliskan "ListStack Kosong" */

// void KonvDes(ListStack *L,int Desimal, int Basis);
//Modul Tambahan Untuk Mengonversi Bilangan Desimal 
//Ke Biner dengan Basis=2, Ke Oktal dengan Basis=8,
//Ke Hexadesimal dengan Basis 16.

void PopAll(ListStack *L,infotype *X);
//Modul Tambahan Untuk Menghapus Semua Node Yang Ada diList,
//Atau MemPop Semua Node.

#endif
