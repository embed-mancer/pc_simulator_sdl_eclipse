#include "tool.h"

void ReplaceSubstr(char *str, char *oldStr, char *newStr) {
  char *p = str;
  char *q = newStr;
  while (*str) {
    if (strncmp(str, oldStr, strlen(oldStr)) == 0) {
      while (*q) {
        *str++ = *q++;
      }
      q = newStr;
    } else {
      *str++ = *p++;
    }
  }
}