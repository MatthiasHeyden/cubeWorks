#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/get.h"
#include "../include/grids.h"
#include "../include/matvec.h"
#include "../include/cubeWorks.h"

int main(int argc,char *argv[]) {
    char fnCUBE[100];
    char fnOut[100];
    FILE *io;
    t_grid gA,gB,gOut;
    int equal;
    int i,j,k,m;
    float esc;
    int flag=0;

    printName("cubeDiv");

    if(argc<4) {
        printf("usage: cubeDiv A.cube B.cube output.cube [escape]\n");
        printf(" output.cube = A.cube / B.cube\n");
        printf(" escape: result of division by zero\n\n");
        exit(1);
    }

    getString(argv[1],fnCUBE);
    printf("%-20s : %s\n","input file A",fnCUBE);
    readCUBE(fnCUBE,&gA,1.0,0);

    getString(argv[2],fnCUBE);
    printf("%-20s : %s\n","input file B",fnCUBE);
    readCUBE(fnCUBE,&gB,1.0,0);

    getString(argv[3],fnOut);
    printf("%-20s : %s\n","output file",fnOut);

    if(argc>4) {
        getFloat(argv[4],&esc);
        printf("%-20s : %f\n","escape",esc);
    } else esc=0.0;

    if(eqCUBEformat(gA,gB)!=1) {
        fprintf(stderr,"ERROR: incompatible grid formats:\n");
        fprintf(stderr," %s\n",argv[1]);
        fprintf(stderr," %s\n",argv[2]);
        exit(1);
    } else {
        cpyCUBEformat(gA,&gOut);
    }

    allocGrd(&gOut);
    for(i=0;i<gOut.dim[0];i++) {
        for(j=0;j<gOut.dim[1];j++) {
            for(k=0;k<gOut.dim[2];k++) {
                if(gB.grid[i][j][k]!=0.0) {
                    gOut.grid[i][j][k]=gA.grid[i][j][k]/gB.grid[i][j][k];
                } else {
                    gOut.grid[i][j][k]=esc;
                    if(flag==0) {
                        flag=1;
                        fprintf(stderr,"NOTE: division by zero encountered\n");
                        fprintf(stderr,"      result set to: %f\n,esc");
                    }
                }
            }
        }
    }
    writeCUBE(fnOut,gOut,1.0,0);

    return 0;
}
