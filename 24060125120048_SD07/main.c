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
  List1 Senarai, L, Lcopy, Lsplit1, Lsplit2, Lconcat;
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

  /* --- 2. PENGUJIAN CREATELIST & ISEMPTYLIST --- */
  printf("--- 2. Pengujian CreateList & IsEmptyList ---\n");
  CreateList(&L);
  printf("Setelah CreateList(&L):\n");
  printf("  IsEmptyList(L) : %s\n", IsEmptyList(L) ? "TRUE" : "FALSE");
  printf("  NbElm(L)       : %d\n", NbElm(L));
  printf("  PrintList(L)   :");
  PrintList(L);
  printf("\n\n");

  /* --- 3. PENGUJIAN INSERT (VFirst, VLast, VAfter) --- */
  printf("--- 3. Pengujian Insert (VFirst, VLast, VAfter) ---\n");
  printf("InsertVFirst 'C', 'B', 'A' ke L:\n");
  InsertVFirst(&L, 'C');
  InsertVFirst(&L, 'B');
  InsertVFirst(&L, 'A');
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n", NbElm(L));

  printf("\nInsertVLast 'E' ke L:\n");
  InsertVLast(&L, 'E');
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n", NbElm(L));

  printf("\nInsertVAfter(&L, 'C', 'D') (menyisipkan 'D' setelah 'C'):\n");
  InsertVAfter(&L, 'C', 'D');
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n\n", NbElm(L));

  /* --- 4. PENGUJIAN SEARCHX & UPDATEX --- */
  printf("--- 4. Pengujian SearchX & UpdateX ---\n");
  SearchX(L, 'C', &foundAddr);
  if (foundAddr != NIL) {
    printf("  SearchX(L, 'C') ditemukan pada address %p dengan info '%c'\n", (void*)foundAddr, info(foundAddr));
  } else {
    printf("  SearchX(L, 'C') TIDAK ditemukan\n");
  }

  SearchX(L, 'Z', &foundAddr);
  if (foundAddr != NIL) {
    printf("  SearchX(L, 'Z') ditemukan pada address %p\n", (void*)foundAddr);
  } else {
    printf("  SearchX(L, 'Z') berhasil ditangani (TIDAK ditemukan / NIL)\n");
  }

  printf("\nUpdateX(&L, 'D', 'K') -> ubah 'D' pertama menjadi 'K':\n");
  UpdateX(&L, 'D', 'K');
  printf("  Isi L setelah UpdateX:");
  PrintList(L);
  printf("\n\n");

  /* --- 5. PENGUJIAN SOAL TAMBAHAN (Konsonan, CountX, FrekuensiX, Modus, NbModus) --- */
  printf("--- 5. Pengujian Analisis Elemen (Konsonan, CountX, Frekuensi, Modus) ---\n");
  // Tambahkan elemen 'K' dan 'E' lagi untuk variasi pengujian modus dan duplikasi
  InsertVLast(&L, 'K');
  InsertVLast(&L, 'E');
  printf("  Isi L saat ini:");
  PrintList(L);
  printf("\n  Jumlah huruf konsonan (CountKonsonan) : %d\n", CountKonsonan(L));
  printf("  Jumlah kemunculan 'K' (CountX)        : %d\n", CountX(L, 'K'));
  printf("  Frekuensi 'K' (FrekuensiX)            : %.2f\n", FrekuensiX(L, 'K'));
  printf("  Modus (huruf paling sering muncul)   : %c\n", Modus(L));
  printf("  NbModus (frekuensi modus)            : %d\n\n", NbModus(L));

  /* --- 6. PENGUJIAN SEARCHALLX & UPDATEALLX --- */
  printf("--- 6. Pengujian SearchAllX & UpdateAllX ---\n");
  printf("Posisi semua kemunculan 'K' (SearchAllX): ");
  SearchAllX(L, 'K');
  printf("\nPosisi semua kemunculan 'Z' (SearchAllX): ");
  SearchAllX(L, 'Z');

  printf("\n\nUpdateAllX(&L, 'K', 'X') -> ubah semua kemunculan 'K' menjadi 'X':\n");
  UpdateAllX(&L, 'K', 'X');
  printf("  Isi L setelah UpdateAllX:");
  PrintList(L);
  printf("\n\n");

  /* --- 7. PENGUJIAN INVERS --- */
  printf("--- 7. Pengujian Invers (Membalik List) ---\n");
  printf("Isi list L sebelum di-invers:");
  PrintList(L);
  Invers(&L);
  printf("\nIsi list L setelah di-invers :");
  PrintList(L);
  printf("\n\n");

  /* --- 8. PENGUJIAN COPYLIST --- */
  printf("--- 8. Pengujian CopyList ---\n");
  CopyList(L, &Lcopy);
  printf("Isi Lcopy (salinan dari L):");
  PrintList(Lcopy);
  printf("\nVerifikasi independensi alamat (first berbeda alamat):\n");
  printf("  Address First(L)     : %p\n", (void*)First(L));
  printf("  Address First(Lcopy) : %p\n", (void*)First(Lcopy));
  if (First(L) != First(Lcopy)) {
    printf("  -> Benar, L dan Lcopy mandiri dengan alamat memori berbeda!\n\n");
  } else {
    printf("  -> Alamat masih sama!\n\n");
  }

  /* --- 9. PENGUJIAN SPLITLIST --- */
  printf("--- 9. Pengujian SplitList ---\n");
  // Lcopy berisi 7 elemen: n=7, k=(7+1)/2 = 4 (Lsplit1 mendapat 4 elemen, Lsplit2 mendapat 3 elemen)
  printf("Memecah Lcopy (NbElm = %d) menjadi Lsplit1 dan Lsplit2:\n", NbElm(Lcopy));
  SplitList(Lcopy, &Lsplit1, &Lsplit2);
  printf("  Lsplit1 (NbElm = %d) :", NbElm(Lsplit1));
  PrintList(Lsplit1);
  printf("\n  Lsplit2 (NbElm = %d) :", NbElm(Lsplit2));
  PrintList(Lsplit2);
  printf("\n\n");

  /* --- 10. PENGUJIAN CONCATLIST --- */
  printf("--- 10. Pengujian ConcatList ---\n");
  printf("Menggabungkan kembali Lsplit1 dan Lsplit2 menjadi Lconcat:\n");
  ConcatList(Lsplit1, Lsplit2, &Lconcat);
  printf("  Lconcat (gabungan):");
  PrintList(Lconcat);
  printf("\n  NbElm(Lconcat)   : %d\n\n", NbElm(Lconcat));

  /* --- 11. PENGUJIAN DELETE (VFirst & VLast) --- */
  printf("--- 11. Pengujian Delete (VFirst & VLast) ---\n");
  printf("Isi list L sebelum delete:");
  PrintList(L);
  printf("\n");

  DeleteVFirst(&L, &val);
  printf("DeleteVFirst -> elemen terhapus: '%c'\n", val);
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n", NbElm(L));

  DeleteVLast(&L, &val);
  printf("\nDeleteVLast -> elemen terhapus: '%c'\n", val);
  printf("  Isi L:");
  PrintList(L);
  printf("\n  NbElm(L): %d\n", NbElm(L));

  printf("\nMenghapus sisa elemen hingga list L kosong:\n");
  while (!IsEmptyList(L)) {
    DeleteVLast(&L, &val);
    printf("  DeleteVLast -> terhapus '%c', sisa NbElm: %d\n", val, NbElm(L));
  }
  printf("List L sekarang kosong: IsEmptyList(L) = %s\n", IsEmptyList(L) ? "TRUE" : "FALSE");

  // Uji delete pada list kosong
  DeleteVFirst(&L, &val);
  printf("DeleteVFirst pada list kosong -> val = '%c' (default '#')\n", val);
  DeleteVLast(&L, &val);
  printf("DeleteVLast pada list kosong  -> val = '%c' (default '#')\n\n", val);

  printf("========================================================\n");
  printf("                   PENGUJIAN SELESAI                    \n");
  printf("========================================================\n");

  return 0;
}
