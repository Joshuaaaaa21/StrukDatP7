/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060125120048 & Joshua Briliant Suryana */
/* Tanggal : 27 Oktober 2026 */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list1.h"

int main()
{ //kamus
  address A; 
  address B;
  address P;
  List1 Senarai;

  //algoritma
  printf("===================================================\n");
  printf("       DRIVER ADT LIST BERKAIT (POINTER) - LIST1   \n");
  printf("===================================================\n\n");

  //aplikasi tipe address
  printf("--- 1. Aplikasi Tipe Address & Tipe List1 Dasar ---\n");
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );

  //aplikasi tipe List1
  Senarai.First = B; //First(Senarai) = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL) {
	  printf("\t%c", info(P));
	  P = next(P);
  }
  printf("\nPrintList(Senarai) :");
  PrintList(Senarai);
  printf("\nNbElm(Senarai)     : %d\n\n", NbElm(Senarai));

  //pengujian dealokasi
  printf("--- 2. Pengujian Dealokasi ---\n");
  Dealokasi(A);
  Dealokasi(B);
  printf("Dealokasi A dan B selesai.\n\n");

  //aplikasi fungsi-fungsi List1 pada Senarai
  printf("--- 3. Pengujian Fungsi-Fungsi ADT List1 ---\n");
  CreateList(&Senarai);
  printf("CreateList(&Senarai) -> IsEmptyList: %s | NbElm: %d\n", 
          IsEmptyList(Senarai) ? "TRUE" : "FALSE", NbElm(Senarai));

  //uji InsertVFirst
  printf("\n>> InsertVFirst berturut-turut 'C', 'B', 'A':");
  InsertVFirst(&Senarai, 'C');
  InsertVFirst(&Senarai, 'B');
  InsertVFirst(&Senarai, 'A');
  PrintList(Senarai);
  printf("\nNbElm: %d | IsEmptyList: %s\n", 
          NbElm(Senarai), IsEmptyList(Senarai) ? "TRUE" : "FALSE");

  //uji InsertVLast
  printf("\n>> InsertVLast berturut-turut 'D', 'E':");
  InsertVLast(&Senarai, 'D');
  InsertVLast(&Senarai, 'E');
  PrintList(Senarai);
  printf("\nNbElm: %d\n", NbElm(Senarai));

  //penelusuran akhir elemen Senarai
  printf("\n>> Penelusuran akhir Senarai:\nSenarai : ");
  P = First(Senarai);
  while (P != NIL) {
    printf("[%c] -> ", info(P));
    P = next(P);
  }
  printf("NIL\n\n");

  printf("===================================================\n");
  printf("               PENGUJIAN SELESAI                   \n");
  printf("===================================================\n");

  return 0;
}
