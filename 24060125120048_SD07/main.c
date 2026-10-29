/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060125120048 & Joshua Briliant Suryana */
/* Tanggal : 27 Oktober 2026 */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list1.h"

int main()
{
  /* Kamus */
  address A, B, P, foundAddr;
  List1 Senarai, L;
  infotype val;

  /* Algoritma */
  printf("========================================================\n");
  printf("        DRIVER ADT LIST BERKAIT (POINTER) - LIST1       \n");
  printf("========================================================\n\n");

  /* --- 1. APLIKASI TIPE ADDRESS & TIPE LIST1 DASAR --- */
  printf("--- 1. Aplikasi Tipe Address & Tipe List1 Dasar ---\n");
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );

  // aplikasi tipe List1
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

  // Pembersihan alokasi manual
  Dealokasi(A);
  Dealokasi(B);

  /* --- 2. PENGUJIAN ADT LIST1 (FUNGSI & PROSEDUR LENGKAP) --- */
  printf("--- 2. Pengujian CreateList & IsEmptyList ---\n");
  CreateList(&L);
  printf("Setelah CreateList(&L):\n");
  printf("  IsEmptyList(L) : %s\n", IsEmptyList(L) ? "TRUE" : "FALSE");
  printf("  NbElm(L)       : %d\n", NbElm(L));
  printf("  PrintList(L)   :");
  PrintList(L);
  printf("\n\n");

  printf("--- 3. Pengujian InsertVFirst & InsertVLast ---\n");
  printf("InsertVFirst 'C', 'B', 'A' ke L:\n");
  InsertVFirst(&L, 'C');
  InsertVFirst(&L, 'B');
  InsertVFirst(&L, 'A');
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n", NbElm(L));

  printf("\nInsertVLast 'D', 'B' (menambahkan 'B' lagi untuk tes duplikasi) ke L:\n");
  InsertVLast(&L, 'D');
  InsertVLast(&L, 'B');
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n\n", NbElm(L));

  printf("--- 4. Pengujian SearchX & UpdateX ---\n");
  printf("Pencarian elemen 'B':\n");
  SearchX(L, 'B', &foundAddr);
  if (foundAddr != NIL) {
    printf("  SearchX(L, 'B') ditemukan di address %p dengan info '%c'\n", (void*)foundAddr, info(foundAddr));
  } else {
    printf("  SearchX(L, 'B') TIDAK ditemukan\n");
  }

  printf("Pencarian elemen 'Z' (tidak ada di list):\n");
  SearchX(L, 'Z', &foundAddr);
  if (foundAddr != NIL) {
    printf("  SearchX(L, 'Z') ditemukan di address %p\n", (void*)foundAddr);
  } else {
    printf("  SearchX(L, 'Z') berhasil ditangani (TIDAK ditemukan / NIL)\n");
  }

  printf("\nUpdateX(&L, 'D', 'K') -> ubah 'D' pertama menjadi 'K':\n");
  UpdateX(&L, 'D', 'K');
  printf("  Isi L setelah UpdateX:");
  PrintList(L);
  printf("\n\n");

  printf("--- 5. Pengujian CountKonsonan, CountX, & FrekuensiX ---\n");
  printf("  Isi L saat ini:");
  PrintList(L);
  printf("\n  Jumlah huruf konsonan (CountKonsonan) : %d\n", CountKonsonan(L));
  printf("  Jumlah kemunculan 'B' (CountX)        : %d\n", CountX(L, 'B'));
  printf("  Frekuensi 'B' (FrekuensiX)            : %.2f\n", FrekuensiX(L, 'B'));
  printf("  Jumlah kemunculan 'Z' (CountX)        : %d\n", CountX(L, 'Z'));
  printf("  Frekuensi 'Z' (FrekuensiX)            : %.2f\n\n", FrekuensiX(L, 'Z'));

  printf("--- 6. Pengujian SearchAllX & UpdateAllX ---\n");
  printf("Posisi semua kemunculan 'B' (SearchAllX): ");
  SearchAllX(L, 'B');
  printf("\nPosisi semua kemunculan 'Z' (SearchAllX): ");
  SearchAllX(L, 'Z');

  printf("\n\nUpdateAllX(&L, 'B', 'M') -> ubah semua kemunculan 'B' menjadi 'M':\n");
  UpdateAllX(&L, 'B', 'M');
  printf("  Isi L setelah UpdateAllX:");
  PrintList(L);
  printf("\n  CountX(L, 'M'): %d | CountX(L, 'B'): %d\n\n", CountX(L, 'M'), CountX(L, 'B'));

  printf("--- 7. Pengujian DeleteVFirst & DeleteVLast ---\n");
  printf("Isi list sebelum delete:");
  PrintList(L);
  printf("\n");

  DeleteVFirst(&L, &val);
  printf("DeleteVFirst -> elemen terhapus: '%c'\n", val);
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n\n", NbElm(L));

  DeleteVLast(&L, &val);
  printf("DeleteVLast -> elemen terhapus: '%c'\n", val);
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n\n", NbElm(L));

  printf("--- 8. Pengujian Delete hingga List Kosong (Edge Case 1 Elemen) ---\n");
  while (!IsEmptyList(L)) {
    DeleteVLast(&L, &val);
    printf("DeleteVLast -> terhapus '%c', sisa NbElm: %d\n", val, NbElm(L));
  }
  printf("List sekarang kosong: IsEmptyList(L) = %s\n", IsEmptyList(L) ? "TRUE" : "FALSE");

  // Uji delete pada list yang sudah kosong
  DeleteVFirst(&L, &val);
  printf("DeleteVFirst pada list kosong -> val = '%c' (default '#')\n", val);
  DeleteVLast(&L, &val);
  printf("DeleteVLast pada list kosong  -> val = '%c' (default '#')\n\n", val);

  printf("========================================================\n");
  printf("                   PENGUJIAN SELESAI                    \n");
  printf("========================================================\n");

  return 0;
}
