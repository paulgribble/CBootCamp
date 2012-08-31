#include "neuron.h"

double getangle(double x, double y) {
  double ang;
  ang = atan2(y,x);
  if (ang < 0) ang = ang + (2*M_PI);
  return ang;
}

void show_int_vec(int vec[], int n) {
  printf("\n");
  printf("[");
  for (int i=0; i<n-1; i++) {
    printf("%3d,", vec[i]);
  }
  printf("%3d ]\n", vec[n-1]);
}

void show_double_vec(double vec[], int n) {
  printf("\n");
  printf("[");
  for (int i=0; i<n-1; i++) {
    printf("%6.3f,", vec[i]);
  }
  printf("%6.3f ]\n", vec[n-1]);
}

void write_double_vec(double vec[], int n, char fname[]) {
  FILE *fid = fopen(fname, "w");
  if (fid==NULL) {
    printf("ERROR: write_double_vec(%s)\n", fname);
    exit(EXIT_FAILURE);
  }
  else {

    printf("writing to %s\n", fname);
    for (int i=0; i<n; i++) {
      fprintf(fid, "%.7f\n", vec[i]);
    }
    fclose(fid);
  }
}

void showmat(double mat[], int nrows, int ncols) {
  int ci = 0;
  printf("\n");
  for (int i=0; i<nrows; i++) {
    for (int j=0; j<ncols; j++) {
      printf("%7.4f", mat[ci]);
      ci = ci + 1;
    }
    printf("\n");
  }
  printf("\n");
}

void readcell(char fname[], double data[], int n, int msg) {
  FILE *fid;
  char tmpstring[255];
  if (msg) printf("reading %s\n", fname);
  fid = fopen(fname, "r");
  if (fid==NULL) {
    printf("ERROR: readcell(%s)\n", fname);
    exit(EXIT_FAILURE);
  }
  else {
    int fout;
    for (int ic=0; ic<n; ic++) {
      fout = fscanf(fid, "    %s", tmpstring);
      data[ic] = atof(tmpstring);
    }
    fclose(fid);
  }
}

void oneplate(double r1, double r2, double a1, double a2, double output[6]) {
	
  // output is [area,cx,cy,Ix,Iy,Ixy]
  //from Gribble PL, Scott SH (2002) J. Neurosci. Methods 113(2):185-195

  double c1=(r2-r1)/(a2-a1);
  double c2=a1*c1;
  double c3=r1-c2;
	
  double c1p2 = c1*c1;
  double a2p3 = a2*a2*a2;
  double a1p3 = a1*a1*a1;
  double a2p2 = a2*a2;
  double a1p2 = a1*a1;
  double c3p2 = c3*c3;
  double c3p3 = c3*c3*c3;
  double c3p4 = c3*c3*c3*c3;
  double a2p4 = a2*a2*a2*a2;
  double a1p5 = a1*a1*a1*a1*a1;
  double c1p3 = c1*c1*c1;
  double c1p4 = c1*c1*c1*c1;
  double a1p4 = a1*a1*a1*a1;
  double a2p5 = a2*a2*a2*a2*a2;
  double f12 = 1.0/2.0;
  double f13 = 1.0/3.0;
  double f16 = 1.0/6.0;
  double f19 = 1.0/9.0;
  double f29 = 2.0/9.0;
  double f112 = 1.0/12.0;
  double f118 = 1.0/18.0;
  double f145 = 1.0/45.0;
  double sin_a1 = sin(a1);
  double sin_a2 = sin(a2);
  double cos_a1 = cos(a1);
  double cos_a2 = cos(a2);
  double cos_2_a1 = cos(2.0*a1);
  double sin_2_a1 = sin(2.0*a1);
  double cos_2_a2 = cos(2.0*a2);
  double sin_2_a2 = sin(2.0*a2);

  double area = f16*(c1p2)*((a2p3)-(a1p3)) + f12*c3*c1*((a2p2)-(a1p2)) + f12*(c3p2)*(a2-a1);
   
  double cx = ((f13*sin_a2 - f13*sin_a1)*(c3p3) + (cos_a2 - cos_a1 - a1*sin_a1 + a2*sin_a2)*c1*(c3p2) + 
	       (((a2p2)-2.0)*sin_a2 + (-(a1p2) + 2.0)*sin_a1 + 2.0*a2*cos_a2 - 2.0*a1*cos_a1) * 
	       (c1p2)*c3 + (((a2p2)-2.0)*cos_a2 + (-(a1p2)+2.0)*cos_a1 + (f13*(a2p3) - 2.0*a2)*sin_a2 + 
			    (-f13*(a1p3) + 2.0*a1)*sin_a1)*(c1p3)) / 
    ((f12*a2 - f12*a1)*(c3p2) + f12*c3*c1*((a2p2)-(a1p2)) + (f16*(a2p3) - f16*(a1p3))*(c1p2));
   
  double cy = ((-f13*cos_a2 + f13*cos_a1)*(c3p3) + (sin_a2 - sin_a1 + a1*cos_a1 - a2*cos_a2)*c1*(c3p2) + 
	       ((-(a2p2)+2.0)*cos_a2 + ((a1p2) - 2.0)*cos_a1 + 2.0*a2*sin_a2 - 2.0*a1*sin_a1) * 
	       (c1p2)*c3 + ((2.0*a2 - f13*(a2p3))*cos_a2 + (f13*(a1p3) - 2.0*a1)*cos_a1 + ((a2p2) - 2.0)*sin_a2 + 
			    (-(a1p2) + 2.0)*sin_a1)*(c1p3)) / 
    ((f12*a2 - f12*a1)*(c3p2) + f12*c3*c1*((a2p2)-(a1p2)) + (f16*(a2p3) - f16*(a1p3))*(c1p2));
   
  double Ix = (f118*sin_2_a1 - f19*a1 + f19*a2 - f118*sin_2_a2)*(c3p4) + (-f29*(a1p2) + f19*cos_2_a1 - 
									  f19*cos_2_a2 - f29*a2*sin_2_a2 + f29*a1*sin_2_a1 + f29*(a2p2))*c1*(c3p3) + 
    ((-f16 + f13*(a1p2))*sin_2_a1 + (f16 - f13*(a2p2))*sin_2_a2 - f13*a2*cos_2_a2 + 
     f13*a1*cos_2_a1 + 
     f29*(a2p3) - f29*(a1p3))*(c1p2)*(c3p2) + ((f13*a2 - f29*(a2p3))*sin_2_a2 + 
					       (f29*(a1p3) - f13*a1)*sin_2_a1 + (f16 - f13*(a2p2))*cos_2_a2 + (-f16 + 
													       f13*(a1p2))*cos_2_a1 - f19*(a1p4) + f19*(a2p4))*(c1p3)*c3 + ((f16*a2 - 
																					     f19*(a2p3))*cos_2_a2 + (f19*(a1p3) - f16*a1)*cos_2_a1 + 
																					    (f16*(a2p2) - f118*(a2p4) - f112)*sin_2_a2 + (-f16*(a1p2) + f112 + f118*(a1p4))*sin_2_a1 + 
																					    f145*(a2p5) - f145*(a1p5))*(c1p4);
   
  double Iy = (-f19*a1 + f118*sin_2_a2 + f19*a2 - f118*sin_2_a1)*(c3p4) + (-f19*cos_2_a1 - 
									   f29*(a1p2) + f29*a2*sin_2_a2 + f29*(a2p2) + f19*cos_2_a2 - 
									   f29*a1*sin_2_a1)*c1*(c3p3) + ((-f16 + f13*(a2p2))*sin_2_a2 + 
													 (f16 - f13*(a1p2))*sin_2_a1 - f13*a1*cos_2_a1 + f29*(a2p3) + 
													 f13*a2*cos_2_a2 - f29*(a1p3))*(c1p2)*(c3p2) + ((-f16 + f13*(a2p2))*cos_2_a2 + 
																			(f16 - f13*(a1p2))*cos_2_a1 + (-f13*a2 + f29*(a2p3))*sin_2_a2 + 
																			(f13*a1 - f29*(a1p3))*sin_2_a1 - f19*(a1p4) + f19*(a2p4))*(c1p3)*c3 + 
    ((-f16*a2 + f19*(a2p3))*cos_2_a2 + (-f19*(a1p3) + f16*a1)*cos_2_a1 + 
     (-f16*(a2p2) + f118*(a2p4) + f112)*sin_2_a2 + 
     (f16*(a1p2) - f118*(a1p4) - f112)*sin_2_a1 + f145*(a2p5) - f145*(a1p5))*(c1p4);
   
  double Ixy = (-f118*cos_2_a2 + f118*cos_2_a1)*(c3p4) + 
    (f29*a1*cos_2_a1 + f19*sin_2_a2 - f19*sin_2_a1 - f29*a2*cos_2_a2)*c1*(c3p3) + 
    ((f16 - f13*(a2p2))*cos_2_a2 + (f13*(a1p2) - f16)*cos_2_a1 - 
     f13*a1*sin_2_a1 + f13*a2*sin_2_a2)*(c1p2)*(c3p2) +  
    ((f13*a2 - f29*(a2p3))*cos_2_a2 + (-f13*a1 + f29*(a1p3))*cos_2_a1 + 
     (f13*(a2p2) - f16)*sin_2_a2 + (-f13*(a1p2) + f16)*sin_2_a1)*(c1p3)*c3 + 
    ((-f118*(a2p4) - f112 + f16*(a2p2))*cos_2_a2 + 
     (-f16*(a1p2) + f112 + f118*(a1p4))*cos_2_a1 + 
     (-f16*a2 + f19*(a2p3))*sin_2_a2 + (f16*a1 - f19*(a1p3))*sin_2_a1)*(c1p4);

  output[0] = area;
  output[1] = cx;
  output[2] = cy;
  output[3] = Ix;
  output[4] = Iy;
  output[5] = Ixy;
} 

struct myvec{
  double val;
  int ind;
};

int mycomp_struct(const void *a, const void *b) 
{
  struct myvec das = *(struct myvec *)a;
  struct myvec dbs = *(struct myvec *)b;
  double da = das.val;
  double db = dbs.val;
  if (da==db) return 0;
  else if (da < db) return -1;
  else return 1;
}

void platemethod(double ain[], double rin[], int n, double output[9]) {
	
  // output = [PD,IR,M,IX,IY,IXY,CX,CY,CR]
  // from Gribble PL, Scott SH (2002) J. Neurosci. Methods 113(2):185-195
  // INPUTS:
  // a: list of angles (in radians)
  // r: list of magnitudes
  // n: the length of the list
  //
  // OUTPUTS:
  // PD          :preferred direction (radians)
  // IR          :sharpness of tuning
  // M           :mass
  // IX, IY, IXY :moments of inertia 
  // CX, CY, CR  :centroid (x,y) and radius of centroid

  double a[n], r[n];
  double Av[n], CXv[n], CYv[n], IXv[n], IYv[n], IXYv[n];
  double PD, IR, M, IX, IY, IXY, CX, CY, CR; // outputs

  struct myvec ai[n];
  for (int i=0; i<n; i++) {
    ai[i].val = ain[i];
    ai[i].ind = i;
  }
  qsort(ai, n, sizeof(struct myvec), mycomp_struct);
  int a_ind[n];
  for (int i=0; i<n; i++) {
    a[i] = ai[i].val;
    a_ind[i] = ai[i].ind;
    r[i] = rin[a_ind[i]];
  }

  int i1, i2;
  double r1, r2, a1, a2;
  double plate_out[6];
  for (int i=0; i<n; i++) {
    i1=i; if (i==n-1) i2=0; else i2=i1+1;
    r1=r[i1]; r2=r[i2]; a1=a[i1]; a2=a[i2];
    if (a2<a1) a2=a2+(2*M_PI);
    oneplate(r1, r2, a1, a2, plate_out);
    Av[i] = plate_out[0];
    CXv[i] = plate_out[1];
    CYv[i] = plate_out[2];
    IXv[i] = plate_out[3];
    IYv[i] = plate_out[4];
    IXYv[i] = plate_out[5];
  }
	
  double gcx = 0.0;
  double gcy = 0.0;
  double a_sum = 0.0;
  IX = 0.0;
  IY = 0.0;
  IXY = 0.0;
  M = 0.0;
  for (int i=0; i<n; i++) {
    gcx = gcx + (CXv[i]*Av[i]);
    gcy = gcy + (CYv[i]*Av[i]);
    a_sum = a_sum + Av[i];
    IX = IX + IXv[i];
    IY = IY + IYv[i];
    IXY = IXY + IXYv[i];
  }
  gcx = gcx / a_sum;
  gcy = gcy / a_sum;
  M = sqrt(a_sum / M_PI);

  PD = getangle(gcx, gcy);
  CR = sqrt((gcx*gcx)+(gcy*gcy));
  CX = gcx;
  CY = gcy;

  double I1 = (IX+IY)/2 + ((IX-IY)/2)*cos(2*PD) - IXY*sin(2*PD);
  double I2 = (IX+IY)/2 - ((IX-IY)/2)*cos(2*PD) + IXY*sin(2*PD);
  if (I1>I2) {
    double tmp = I1;
    I1 = I2;
    I2 = tmp;
  }
  IR = I1 / I2;

  output[0] = PD;
  output[1] = IR;
  output[2] = M;
  output[3] = IX;
  output[4] = IY;
  output[5] = IXY;
  output[6] = CX;
  output[7] = CY;
  output[8] = CR;
}

double compute_PDr(double celldirs[], double cellspks[], int ntrials, int ndirs) {
  double plate_out[9];
  double celldirst[ndirs], cellspkst[ndirs];
  double PDx, PDy, PDr;
  int i1;
  PDx = 0.0;
  PDy = 0.0;
  for (int i=0; i<ntrials; i++) {
    i1 = i*ndirs;
    for (int j=0; j<ndirs; j++) {
      celldirst[j] = celldirs[i1+j];
      cellspkst[j] = cellspks[i1+j];
    }
    platemethod(celldirst, cellspkst, ndirs, plate_out);
    PDx = PDx + cos(plate_out[0]);
    PDy = PDy + sin(plate_out[0]);
  }
  PDx = PDx / ntrials;
  PDy = PDy / ntrials;
  PDr = sqrt((PDx*PDx)+(PDy*PDy));
  return PDr;
}

double compute_PD(double celldirs[], double cellspks[], int ntrials)
{
  double the_PD;
  double plate_out[9];
  platemethod(celldirs, cellspks, 40, plate_out);
  the_PD = plate_out[0];
  return the_PD;
}

