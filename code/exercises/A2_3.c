// gcc -Wall -o go A2_3.c -lm

#include <stdio.h>
#include <math.h>

double mean(int n, double v[n]);
double sd(int n, double v[n]);
double ttest(int n1, int n2, double v1[n1], double v2[n2]);

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

  // compute a t statistic for the difference between means
  double tobs = ttest(nr, nr, c1, c2);
  printf("tobs = %f\n", tobs);

  return 0;
}


// helper functions

double mean(int n, double v[n])
{
  double sum = 0.0;
  int i;
  for (i=0; i<n; i++)
    {
      sum+= v[i];
    }
  return sum / n;
}

double sd(int n, double v[n])
{
  double smean = mean(n, v);
  double sum = 0.0;
  int i;
  for (i=0; i<n; i++) {
    sum += (v[i]-smean)*(v[i]-smean);
  }
  return sqrt(sum / (n-1));
}

double ttest(int n1, int n2, double v1[n1], double v2[n2])
{
  double sd1 = sd(n1, v1);
  double sd2 = sd(n2, v2);
  double m1 = mean(n1, v1);
  double m2 = mean(n2, v2);
  return (m2-m1) / sqrt(((sd1*sd1)/n1) + ((sd2*sd2)/n2));
}
