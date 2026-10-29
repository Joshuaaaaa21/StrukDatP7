/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : 24060125120048 & Joshua Briliant Suryana */
/* Tanggal : 27 Oktober 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	} else {
		// Alokasi memori gagal, P bernilai NIL
	} /* end if */
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
	if ( P != NIL ) {
		next(P) = NIL;
		free(P);
	} else {
		// P sudah bernilai NIL, tidak ada yang dibebaskan
	} /* end if */
	P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L){
	//kamus lokal

	//algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L){
	//kamus lokal

	//algoritma
	return (First(L) == NIL);
}

/*********** OPERATORS ***********/

/**************** PENELUSURAN ****************/

/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List1 L) {
	//kamus lokal 
	address P;
	//algoritma
	P = First(L);
	if (P != NIL) {
		printf("\nElemen = ");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != NIL ); /* end do-while */
	} else {
		printf("\nList kosong\n");
	} /* end if */
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L){
	//kamus lokal
	address P;
	int tot;
	//algoritma
	P = First(L);
	tot = 0;
	if(!IsEmptyList(L)){
		while ( P != NIL ) {
			tot = tot + 1;
			P = next(P);
		} /* end while */
	} else {
		// List kosong, jumlah elemen tetap 0
	} /* end if */
	return tot;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ){
	//kamus lokal
	address P;
	//algoritma
	P = Alokasi(V);
	if( P != NIL ){
		next(P) = First(*L);
		First(*L) = P;
	} else {
		// Alokasi gagal, elemen baru tidak dapat ditambahkan
	} /* end if */
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ){
	//kamus lokal
	address P, T;
	//algoritma
	P = First(*L);
	T = Alokasi(V);
	if( T != NIL ){
		if( P != NIL ){
			while ( next(P) != NIL ) {
				P = next(P);
			} /* end while */
			next(P) = T;
		} else {
			First(*L) = T;
		} /* end if */
	} else {
		// Alokasi gagal, elemen baru tidak dapat ditambahkan
	} /* end if */
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
	//kamus lokal
	address P;
	//algoritma
	*V = '#';
	P = First(*L);
	if( P != NIL ) {
		*V = info(P);
		First(*L) = next(P);
		next(P) = NIL;
		Dealokasi(P);
	} else {
		// List kosong, tidak ada elemen yang dihapus (*V tetap '#')
	} /* end if */
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
	//kamus lokal
	address P, Pos; // Pos untuk menyimpan alamat elemen sebelum elemen terakhir
	//algoritma
	*V = '#';
	P = First(*L);
	Pos = NIL;
	if( P != NIL ){
		while ( next(P) != NIL ) {
			Pos = P;
			P = next(P);
		} /* end while */
		*V = info(P);
		if (Pos == NIL) {
			First(*L) = NIL; // list hanya memiliki 1 elemen
		} else {
			next(Pos) = NIL; // list memiliki lebih dari 1 elemen
		} /* end if */
		next(P) = NIL;
		Dealokasi(P);
	} else {
		// List kosong, tidak ada elemen yang dihapus (*V tetap '#')
	} /* end if */
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A){
	//kamus lokal
	address P;
	//algoritma
	P = First(L);
	*A = NIL;
	while( (P != NIL) && (*A == NIL) ){
		if( info(P) == X ){
			*A = P;
		} else {
			// Belum cocok dengan X, lanjut penelusuran
		} /* end if */
		P = next(P);
	} /* end while */
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y){
	//kamus lokal
	address A;
	//algoritma
	if(!IsEmptyList(*L)){
		SearchX(*L, X, &A);
		if( A != NIL ){
			info(A) = Y;
		} else {
			// Elemen bernilai X tidak ditemukan dalam list
		} /* end if */
	} else {
		// List kosong, tidak ada elemen yang dapat di-update
	} /* end if */
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountKonsonan(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam list L}*/
int CountKonsonan(List1 L){
	//kamus lokal
	int count;
	address P;
	char c;
	//algoritma
	count = 0;
	P = First(L);
	while( P != NIL ){
		c = info(P);
		// Memeriksa apakah karakter alfabet dan bukan huruf vokal
		if( ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) &&
		    (c != 'A' && c != 'a' && c != 'I' && c != 'i' &&
		     c != 'U' && c != 'u' && c != 'E' && c != 'e' &&
		     c != 'O' && c != 'o') ){
			count = count + 1;
		} else {
			// Karakter adalah huruf vokal atau bukan huruf alfabet
		} /* end if */
		P = next(P);
	} /* end while */
	return count; // banyaknya huruf konsonan
}

/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X){
	//kamus lokal
	address P;
	int count;
	//algoritma
	P = First(L);
	count = 0;
	while( P != NIL ){
		if( info(P) == X ){
			count = count + 1;
		} else {
			// info(P) tidak sama dengan X, tidak dihitung
		} /* end if */
		P = next(P);
	} /* end while */
	return count; // banyaknya karakter X
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X){
	//kamus lokal
	int count;
	int total;
	//algoritma
	total = NbElm(L);
	if (total > 0) {
		count = CountX(L, X);
		return ((float)count / (float)total);
	} else {
		// List kosong, frekuensi bernilai 0.0
		return 0.0f;
	} /* end if */
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X){
	//kamus lokal
	address P;
	int pos;
	boolean found;
	//algoritma
	pos = 1;
	found = false;
	P = First(L);
	if(!IsEmptyList(L)){
		while( P != NIL ){
			if( info(P) == X ){
				printf("%d ", pos);
				found = true;
			} else {
				// info(P) != X, tidak dicetak
			} /* end if */
			pos = pos + 1;
			P = next(P);
		} /* end while */
		if (!found) {
			printf("(tidak ditemukan)");
		} else {
			// Elemen ditemukan pada minimal satu posisi
		} /* end if */
	} else {
		printf("(list kosong)");
	} /* end if */
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y){
	//kamus lokal
	address P;
	//algoritma
	P = First(*L);
	if(!IsEmptyList(*L)){
		while( P != NIL ){
			if( info(P) == X ){
				info(P) = Y;
			} else {
				// info(P) != X, tidak diubah
			} /* end if */
			P = next(P);
		} /* end while */
	} else {
		// List kosong, tidak ada elemen yang dapat diubah
	} /* end if */
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA );

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','b','u'} menjadi {'u','b','i'} }*/
void Invers(List1 *L);

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L);

/*function NbModus(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int NbModus(List1 L);

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L); 

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L bagi dua, kelebihan 1 elemen ke L1}*/
void SplitList(List1 L, List1 *L1, List1 *L2);

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1, dengan first berbeda alamat}*/
void CopyList(List1 L1, List1 *L2);
