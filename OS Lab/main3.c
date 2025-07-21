#include <stdio.h>

int main(int argc,char **argv){
   FILE *fin = fopen(argv[1],"r");
   FILE *fout = fopen(argv[2],"w");
   
   char ch;
   ch = fgetc(fin);
   while(ch!=EOF){
        if(ch>='0'&&ch<='9'){
            fputc(ch,fout);
        }
        ch = fgetc(fin);
   }
   fclose(fin);
   fclose(fout);
    
    return 0;
}
