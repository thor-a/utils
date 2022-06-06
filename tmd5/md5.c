/* Line-wise md5 hashing using the mhash library */

#include <mhash.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSZ 1024

int main(void)
{
  int i;
  MHASH td;

  unsigned char buffer[BUFSZ]; /* line length limit */
  unsigned char hash[16];      /* enough size for MD5 */
  unsigned char hex[] = "0123456789abcdef";

  while(fgets(buffer, BUFSZ, stdin) != NULL) {

    td = mhash_init(MHASH_MD5); if (td == MHASH_FAILED) exit(1);

    mhash(td, &buffer, strnlen(buffer)-1, BUFSZ);

    mhash_deinit(td, hash);
    
    for(i = 0; i <= 15; i++) {
      putchar(hex[ hash[i] >>   4 ]);
      putchar(hex[ hash[i] & 0x0f ]);
    }

    printf("\t%s", buffer);
  }

  exit(0);
}
