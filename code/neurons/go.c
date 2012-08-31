// gcc -std=c99 -o go go.c neuron.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "neuron.h"

int main(int argc, char *argv[]) {

  int ncells = 100;                     // # cells to process
  char fnum[4], fname[128];              // filename strings
  double celldirs[40], cellspks[40];    // data for each cell
  double PD[ncells], plate_out[9];      // store cell PDs

  // loop to process each cell
  int i;
  for (i=1; i<=ncells; i++) {

    // construct the numeric part of the filename
    if (i<10) sprintf(fnum, "00%d", i);
    else if (i<100) sprintf(fnum, "0%d", i);
    else sprintf(fnum, "%d", i);

    // read in a dirs data file
    sprintf(fname, "data/cell_dirs_%s.txt", fnum);
    readcell(fname, celldirs, 40, 0);

    // read in a spks data file
    sprintf(fname, "data/cell_spks_%s.txt", fnum);
    readcell(fname, cellspks, 40, 0);
		
    // compute PD
    PD[i-1] = compute_PD(celldirs, cellspks, 40);
  }

  // print vector of PDs to screen and write to a file
  show_double_vec(PD, ncells);
  write_double_vec(PD, ncells, "PDs.txt");
	
  return 0;
}


