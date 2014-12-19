// cat - concatenate and print files

#include <stdio.h>

void copy_file(FILE *in, FILE *out);

int main(int argc, char **argv) {

  if (argc == 1) {
    // no arguments - use standard input
    copy_file(stdin, stdout);
  } else {
    FILE *read;
    while (--argc > 0) {
      read = fopen(*++argv, "r");
      if (read == NULL) {
        printf("*** cat: %s cannot be opened\n", *argv);
        return 1;
      } else {
        copy_file(read, stdout);
        fclose(read);
      }
    } // end while
  } // end else

  return 0;
}

void copy_file(FILE *in, FILE *out) {
  int chr;
  while ( (chr = getc(in)) != EOF ) {
    putc(chr, out);
  }
}

