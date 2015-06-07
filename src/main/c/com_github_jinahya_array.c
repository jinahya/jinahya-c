#include <jni.h>
#include "com_github_jinahya_jni_util_JniNative.h"
#include "com_github_jinahya_jni_util_JniArrays.h"
#include <stdlib.h>
#include <string.h>

int reverse(void * array, const size_t offset, const size_t length, const size_t size) {
  void * temp = malloc(size);
  if (temp == NULL) {
    fprintf(stderr, "failed to allocate memory of size(%zu)\n", size);
    return EXIT_FAILURE;
  }
  size_t s = (offset + 0) * size; // start
  size_t e = (length - 1) * size; // end
  while (s < e) {
    memcpy(temp, (char *) array + s, size);
    memcpy((char *) array + s, (char *) array + e, size);
    memcpy((char *) array + e, temp, size);
    s += size;
    e -= size;
  }
  free(temp);
  return EXIT_SUCCESS;
}
