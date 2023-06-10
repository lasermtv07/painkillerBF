////////////////////////////////////////////
//   painkillerBf                         //
//   (C) lasermtv07, 2023                 //
//   Released under GNU GPL licence       //
////////////////////////////////////////////

#include "compiler.h"

void main( int argc, char *argv[] ){
    char*fc=malloc(10240); fc[0]='\0';
    if(argc==1) {
        printf("\nERROR: No file provided\n");
        return;
    }
    else {
    FILE*f=fopen(argv[1],"r");
    
        if(f!=NULL){
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), f) != NULL) {
                strcat(fc,buffer);
            }
        }
        else {
            printf("\nERROR: Could not load file\n");
            return;
        }
    }
    compile(fc);
}