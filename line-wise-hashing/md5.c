/* Line-wise md5 hashing using the mhash library */

#include <mhash.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

int main(void) {
  int i;
  MHASH td;

  static       unsigned char hash[16];      /* enough size for MD5 */
  static       unsigned char outb[33];
  static const unsigned char hex[] = "0123456789abcdef";

  outb[32] = '\0';

  while(fgets(sbuf, BUFSZ, stdin) != NULL) {

    td = mhash_init(MHASH_MD5); if (td == MHASH_FAILED) exit(1);
    mhash(td, &sbuf, strlen(sbuf)-1);
    mhash_deinit(td, hash);
    
    for(i = 0; i < 16; i++) {
      outb[2*i  ] = hex[ hash[i] >>   4 ]; 
      outb[2*i+1] = hex[ hash[i] & 0x0f ];
    }

    printf("%s\t%s", outb, sbuf);
  }

  exit(0);
}
