#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "zlib.h"

#define CHUNK (1024 * 16)

int deflateFile(FILE* source, FILE* dest, int level)
{
  int ret, flush;
  unsigned have;
  z_stream strm;
  unsigned char in[CHUNK];
  unsigned char out[CHUNK];

  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;
  ret = deflateInit(&strm, level);
  if (Z_OK != ret) {
    return ret;
  }

  do {
    strm.avail_in = fread(in, 1, CHUNK, source);
    if (ferror(source)) {
      (void)deflateEnd(&strm);
      return Z_ERRNO;
    }
    flush = feof(source) ? Z_FINISH : Z_NO_FLUSH;
    strm.next_in = in;

    do {
      strm.avail_out = CHUNK;
      strm.next_out = out;
      
    }
  }
}

int main(int argc, char *argv[])
{
  
  return 0;
}
