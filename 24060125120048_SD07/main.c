/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : November 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  List1 Senarai;
  //algoritma
  
  //aplikasi tipe address
  
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
	  printf("\t%c",info(P));
	  P = next(P);
  }
  //PrintList( Senarai );
  
  return 0;
}
