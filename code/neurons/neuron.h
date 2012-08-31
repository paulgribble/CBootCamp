#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

void show_int_vec(int vec[], int n);

void show_double_vec(double vec[], int n);

void write_double_vec(double vec[], int n, char fname[]);

void showmat(double mat[], int nrows, int ncols);

void readcell(char fname[], double data[], int n, int msg);

void oneplate(double r1, double r2, double a1, double a2, double output[6]);

void platemethod(double a[], double r[], int n, double output[9]);

int mycomp(const void *a, const void *b);

double getangle(double x, double y);

int mycomp_struct(const void *a, const void *b);

double compute_PDr(double celldirs[], double cellspks[], int ntrials, int ndirs);

double compute_PD(double celldirs[], double cellspks[], int ntrials);
