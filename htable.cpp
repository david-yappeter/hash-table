#include <stdio.h>
#include <string.h>

const int MAX_ELEMENT = 6;
char HASHTABLES[MAX_ELEMENT][255];

void view() {
  for(int i = 0; i < MAX_ELEMENT; i++) {
    printf("%d -> %s\n", i, HASHTABLES[i]);
  }
}

int hash(char *str) {
  return (str[0] - 'a') % MAX_ELEMENT;
}

int linearProbing(int index) {
  // loop dari index+1 sampai akhir, 
  // ketika di akhir jadi 0 karena modulo.
  // lanjut dari 0 hingga dia sama dengan index baru berhenti.
  for(int i = index+1; i != index; i = (i+1) % MAX_ELEMENT) {
    if(HASHTABLES[i][0] == '\0') { // jika table di index i kosong
      return i; // return indexnya
    }
  }

  return -1; // table sudah penuh
}

void insert(char *str) {
  int index = hash(str); // nampung indexny

  if(HASHTABLES[index][0] != '\0') { // jika index sudah terisi
    index = linearProbing(index); // cari slot yang kosong
  }

  if(index != -1) { // jika tidak penuh
    strcpy(HASHTABLES[index], str); // masukin nilai
  } else {
    puts("Table is full!");
  }
}

int main() {
  insert((char*)"budi");
  insert((char*)"cecep");
  insert((char*)"bobo");
  insert((char*)"elsa");
  insert((char*)"dodi");
  insert((char*)"dede");
  insert((char*)"anang");
  view();
  return 0;
}
