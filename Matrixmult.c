#include<stdio.h>
/*[9-3-18]
To find the product of two arrays.
*/
#include <string.h>
# define MAXA 10
void prodmtrx(const int[][MAXA], const int[][MAXA], size_t, size_t, size_t, int[][MAXA]);
static inline void putspc(unsigned i) {while(i--) putchar(32);}
void printMtrx(int[][MAXA], size_t, size_t, char*);

int main() {
int A[MAXA][MAXA], B[MAXA][MAXA], a_b[MAXA][MAXA] = {{0}, {0}};
puts("Two matrices, A and B will be constructed of size m*n, and n*p.\n"
"Enter the value of m, n and p:");
size_t m, n, p;
scanf("%d %d %d", &m, &n, &p);
unsigned i, j;
puts("-----Array A:");
for(i = 0; i < m; ++i) {
printf("Enter Row-%u elements:\n", i+1);
for(j = 0; j < n; ++j) scanf("%d", &A[i][j]);
}
puts("-----Array B:");
for(i = 0; i < n; ++i) {
printf("Enter Row-%u elements:\n", i+1);
for(j = 0; j < p; ++j) scanf("%d", &B[i][j]);
}
prodmtrx(A, B, m, n, p, a_b);
printMtrx(a_b, m, p, "A . B = ");
return 0;
}

void prodmtrx(const int a[][MAXA], const int b[][MAXA], size_t t, size_t u, size_t v, int ab[][MAXA]) {
size_t i, j, k;
// k is used for that chain multiplication.
for(j = 0; j < v; ++j) for(i = 0; i < t; ++i) for(k = 0; k < u; ++k) ab[i][j] += a[i][k] * b[k][j];
}
void printMtrx(int ab[][MAXA], size_t r, size_t c, char* str) {
unsigned stpos = (r+1)/2, sps = strlen(str);
size_t i, j;
putspc(sps);
putchar(218);
putspc(3*(2*c - 1));
printf("%c\n", 191);
for(i = 0; i < r; ++i) {
if(i != stpos) putspc(sps);
else printf("%s", str);
putchar(179);
for(j = 0; j < c; ++j) printf("%4d ", ab[i][j]);
printf("\b%c\n", 179);
}
putspc(sps);
putchar(192);
putspc(3*(2*c - 1));
putchar(217);
}