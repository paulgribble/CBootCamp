// gcc -std=c99 -o goboot goboot.c neuron.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "neuron.h"

int main(int argc, char *argv[]) {

  // initialize new seed for random number generator
  srand((unsigned) time(NULL));

  // allocate memory to store data loaded for each neuron
  double celldirs[40], cellspks[40];

  // number of cell files to read
  int ncells = 100;
  if (argc > 1) ncells = atoi(argv[1]);

  // number of bootstrap iterations
  int nboot = 100000;

  // allocate strings to construct filenames
  char fnum[4];
  char fname[128];

  // allocate memory to store various things
  double PD[ncells], PDboot[ncells], PDr[ncells], PDr_boot,
    boot_spks[40], plate_out[9];
	
  // allocate and initialize vector of indices
  int boot_ind[40];
  for (int i=0; i<40; i++) boot_ind[i]=i;

  // loop through each cell
  int i, j, k, bootcount;
  for (i=1; i<=ncells; i++) {

    // construct the filename
    if (i<10) sprintf(fnum, "00%d", i);
    else if (i<100) sprintf(fnum, "0%d", i);
    else sprintf(fnum, "%d", i);
		
    // read in the dirs file
    sprintf(fname, "data/cell_dirs_%s.txt", fnum);
    readcell(fname, celldirs, 40, 0);

    // read in the spks file
    sprintf(fname, "data/cell_spks_%s.txt", fnum);
    readcell(fname, cellspks, 40, 1);
		
    // compute overall PD and PDr
    platemethod(celldirs, cellspks, 40, plate_out);
    PD[i-1] = plate_out[0];
    PDr[i-1] = compute_PDr(celldirs, cellspks, 5, 8);
		
    // bootstrap to compute prob(PDr_boot >= PDr) given shuffled data
    bootcount = 0;
    for (j=0; j<nboot; j++) {
      // randomly sample from cellspks into boot_spks with replacement
      for (k=0; k<40; k++) boot_spks[k]=cellspks[rand()%40];
			
      // compute PDr_boot for shuffled spike data
      PDr_boot = compute_PDr(celldirs, boot_spks, 5, 8);
			
      // if PDr_boot is greater than observed PDr then increment counter
      if (PDr_boot >= PDr[i-1]) bootcount = bootcount + 1;
    }
    // compute proportion of times we simulated PDr_boot >= PDr observed
    PDboot[i-1] = (double) bootcount / nboot;
  }
	
  // show vector of PDs and PDboot values
  show_double_vec(PD, ncells);
  show_double_vec(PDboot, ncells);
  write_double_vec(PD, ncells, "PD.txt");
  write_double_vec(PDboot, ncells, "PDboot.txt");
	
  return 0;
}
