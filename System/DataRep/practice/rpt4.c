// code to print byte representation of data
// casing pointer unsigned char * allows treatment as a byte array
typedef unsigned char *pointer;
void show_bytes(pointer start, size_t len) {
  size_t i;
  for (i=0; i<len; i++)
    pritnf("%p\t0x%.2x\n", start+i, start[i]);
  printf("\n");
}
