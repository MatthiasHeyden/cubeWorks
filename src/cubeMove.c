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
	t_grid gA,gB,gOut;
	int i,j,k,m;
	t_vec trans;

	if(argc<6) {
		printf("usage: ./cubeMove.exe A.cube dX dY dZ output.cube\n");
		printf(" output.cube = A.cube + (dX dY dZ)\n");
		exit(1);
	}

	sscanf(argv[1],"%s",fnCUBE);
	readCUBE(fnCUBE,&gA,1.0,0);
	printf("read %d voxels\n",gA.nVoxel);
	sscanf(argv[2],"%f",&trans[0]);
	sscanf(argv[3],"%f",&trans[1]);
	sscanf(argv[4],"%f",&trans[2]);
	sscanf(argv[5],"%s",fnOut);

	gOut.nVoxel=gA.nVoxel;
	gOut.dg=gA.dg;
	for(m=0;m<3;m++) {
		gOut.dim[m]=gA.dim[m];
		gOut.oriUHBD[m]=gA.oriUHBD[m]+trans[m];
		gOut.oriMH[m]=gA.oriMH[m]+trans[m];
		gOut.oriCUBE[m]=gA.oriCUBE[m]+trans[m];
	}
	strcpy(gOut.title,gA.title);
	allocGrd(&gOut);
	for(i=0;i<gOut.dim[0];i++) {
		for(j=0;j<gOut.dim[1];j++) {
			for(k=0;k<gOut.dim[2];k++) {
				gOut.grid[i][j][k]=gA.grid[i][j][k];
			}
		}
	}
	writeCUBE(fnOut,gOut,1.0,0);

	return 0;
}
