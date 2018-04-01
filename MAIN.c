#include<stdio.h>
/*C file to add my Name & Roll no. on the top of every file provided.
temp.txt is a temporary file that will locally hold the data for each file.
fnames.txt is a files that has the names of all the files on which the operation
`is to be executed on each line.
*/
int main() {
char c, fname[20];
FILE *t = fopen("temp.txt", "r+"), *s, *files = fopen("fnames.txt", "r");
while(!feof(files)) {
fscanf(files, "%s", fname);
s = fopen(fname, "r+");
while((c=getc(s)) != EOF) putc(c, t);
rewind(s);
rewind(t);
fputs("/*\nName: Suraj Bhosle\nRoll no.: 27\n*/\n", s);
while((c=getc(t)) != EOF) putc(c, s);
fclose(s);
}
fclose(t);
return 0;
}
