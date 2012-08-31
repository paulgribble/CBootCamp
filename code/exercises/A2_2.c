// gcc -Wall -o go A2_2.c

#include <stdio.h>

int main(int argc, char *argv[])
{  
  FILE *fid;
  int nr = 0;
  char buf[255];
  
  // open the file
  fid = fopen("A2_1_data.csv", "r");

  // count the number of lines
  while (!feof(fid)) {
    fgets(buf, 255, fid);
    nr++;
  }
  nr--;

  // go back to beginning of file
  fseek(fid, 0, SEEK_SET);

  // load in the data
  double c1[nr], c2[nr];
  int i;
  for (i=0; i<nr; i++) {
    fscanf(fid, "%lf,%lf\n", &c1[i], &c2[i]);
  }
  
  // close file
  fclose(fid);

  // print the data to the screen
  for (i=0; i<nr; i++) {
    printf("c1[%d]=%f, c2[%d]=%f\n", i, c1[i], i, c2[i]);
  }

  return 0;
}
