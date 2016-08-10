// Epic1337734m
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int main() {
  int ok;
  int n, a;
 
  while (scanf("%d", &n)==1) {
    if (abs(n)<=10000) {
      ok=0;
      for (a=0; a<=sqrt(n); a++) {
        if (sqrt(n-pow(a,2))==(float) sqrt(n-pow(a,2))) ok=1;
        if (ok) break;
      }
      if (ok) printf("YES\n"); else printf("NO\n");
    }
  }
  return 0;
}