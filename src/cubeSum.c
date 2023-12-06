#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/grids.h"
#include "../include/matvec.h"

int main(int argc,char *argv[]) {
    char fnCUBE[100];
    char fnOut[100];
    char tmp[100];
    FILE *io;
    t_grid gA,gOut;
    int equal;
    int i,j,k,m,n;

    if(argc<4) {
        printf("usage: ./cubeSum.exe A.cube B.cube ... output.cube\n");
        printf(" output.cube = A.cube + B.cube + ...\n");
        exit(1);
    }

    sscanf(argv[1],"%s",fnCUBE);
    readCUBE(fnCUBE,&gA,1.0,0);
    cpyCUBEformat(gA,&gOut);
    allocGrd(&gOut);
    for(i=0;i<gOut.dim[0];i++) {
        for(j=0;j<gOut.dim[1];j++) {
            for(k=0;k<gOut.dim[2];k++) {
                gOut.grid[i][j][k]=gA.grid[i][j][k];
            }
        }
    }

    for(n=2;n<argc-1;n++) {
        sscanf(argv[n],"%s",fnCUBE);
        readCUBE(fnCUBE,&gA,1.0,0);
        if(eqCUBEformat(gA,gOut)!=1) {
            printf("ERROR: incompatible grid formats:\n");
            printf(" %s\n",argv[1]);
            printf(" %s\n",argv[n]);
            exit(1);
        }
        for(i=0;i<gOut.dim[0];i++) {
            for(j=0;j<gOut.dim[1];j++) {
                for(k=0;k<gOut.dim[2];k++) {
                    gOut.grid[i][j][k]+=gA.grid[i][j][k];
                }
            }
        }
    }

    sscanf(argv[argc-1],"%s",fnOut);
    writeCUBE(fnOut,gOut,1.0,0);

    return 0;
}
