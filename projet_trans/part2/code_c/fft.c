/*
	implementation des fonctions de fft.h
*/

#include "fft.h"

void twiddle(complex *TW, unsigned int size){
	complex phi = cexp(2*I*M_PI/ size );
	TW[0]=1;
	for(int i =1; i<size ; i++)
		TW[i]=TW[i-1]*phi;
}


void dft_directe(double *result, double *data, unsigned int size){
	double complex r [size];
	for (int k = 0; k < size; ++k)
	{
		r[k]=0;
		for (int n = 0; n < size; ++n)
		{
			r[k] += *(data + n)*cexp(-2*I*M_PI*k*n/size);
		}
		result[k]=cabs(r[k]);
	}
}


void fftrec(complex *data, complex *result, unsigned int size){
	complex ypair[size], yimpair[size],Fimpair[size], Fpair[size];
	int n,N2;
	if (size >1){
		N2 = size/2;
		for (n=0;n<N2;n++){
			ypair[n] = data[n] + data[n+N2];
			yimpair[n] = (data[n] - data[n+N2])*cexp(-2*I*M_PI*n/size);
		}
		fftrec(ypair,Fpair,N2);
		fftrec(yimpair,Fimpair,N2);
		for (n=0; n<N2; n++){
			result[2*n]=Fpair[n];
			result[2*n+1]=Fimpair[n];
		}
	}
	else{
		result[0] = data[0];
	}
}


int bitrev(int inp, int numbits)
{
    int i, rev = 0;
    for (i = 0; i < numbits; i++) {
        rev = (rev << 1) | (inp & 1);
        inp >>= 1;
    }
    return rev;
}


void fftiterTW(complex *data, unsigned int size, int log2n, complex *TW){
	int j,N2,Bpair,Bimpair,Bp=1,N=size;
	complex impair, pair, ctmp;

	for (int k=0; k<log2n; k++){
		N2 = N/2;
		Bpair=0;
		for (int b=0;b<Bp; b++){
			Bimpair=Bpair+N2;
			for (int n=0;n<N2;n++){
				impair=data[Bpair+n]+data[Bimpair+n];
				pair=(data[Bpair+n]-data[Bimpair+n])*TW[n*size/N];
				data[Bpair+n]=pair;
				data [Bimpair+n]=impair;
			}
			Bpair = Bpair+N;
		}
		Bp=Bp*2;
		N=N/2;
	}
	for (int i = 0; i < size; i++)
	{
		j = bitrev(i,log2n);
		if (j>i){
			// SWAP
			complex ctmp = data[j];
			data[j]=data[i];
			data[i]=ctmp;
		}
	}
	ctmp = data[size-1];
	for (int i = size-1; i > 0; i--)
		data[i]=data[i-1];
	data[0]=ctmp;
}

void print_fft(complex *data, int n){
	for (int i=0; i<n; i++){
		printf("%f+%f i\t",creal(*(data+i)),cimag(*(data+i)));
	}
	printf("\n");
}
