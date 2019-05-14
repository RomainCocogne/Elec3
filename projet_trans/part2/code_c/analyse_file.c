/*
	implementation du module analyse_file.h
*/

#include "analyse_file.h"

sf_count_t fx_mix_mono_read_double (SNDFILE *file, double *data, sf_count_t datalen){
	SF_INFO info;
	static double multi_data [2048];
	int k, ch, frames_read;
	sf_count_t  dataout = 0;

	sf_command(file, SFC_GET_CURRENT_SF_INFO, &info, sizeof(info));
	if(info.channels==1) {
		return sf_read_double (file, data, datalen);
		
	}

	while(dataout<datalen){
	    int this_read;
	    this_read = MIN(ARRAY_LEN (multi_data)/info.channels, datalen);
	    frames_read=sf_readf_double(file,multi_data,this_read);
	    if(frames_read==0)
	    	break;
	    for(k=0; k<frames_read; k++){
	        double mix =0.0;
	    	for(ch=0; ch<info.channels; ch++) mix+=multi_data[k*info.channels+ch];
	    	    data[dataout+k]= mix/info.channels;
	    }
	    dataout+=this_read;
	}	
	return dataout;
}


int process_data (double *res, double *data, int count, int channels, int mode)
{	
	double dft [BUFFER_LEN];
//choix de l'algo pour la fft (de 0 a 2, du plus lent au plus rapide)
	switch (mode) {
	    case 0: ;
	      	dft_directe(dft,data,BUFFER_LEN);
	      break;
	    case 1: ;
	    	double complex fftrec_crec [BUFFER_LEN];
			double complex data_complex[BUFFER_LEN];
			toComplex(data_complex,data, BUFFER_LEN);
			fftrec(data_complex,fftrec_crec,BUFFER_LEN);
			toReal(dft,fftrec_crec,BUFFER_LEN);
	      break;
	    case 2: ;
	    	double complex data_cbit[BUFFER_LEN];
			toComplex(data_cbit,data, BUFFER_LEN);
	    	complex TW[BUFFER_LEN];
			twiddle(TW,BUFFER_LEN);
			fftiterTW(data_cbit,BUFFER_LEN,10,TW);
			toReal(dft, data_cbit,BUFFER_LEN);
	      break;
	    default: return 0;
	}
	moyenne(dft,res,BUFFER_LEN/2,SIZE); //decimation et stockage du resultat
	return 1;
} 


void analyseTiming(double *data, int count, int channels){
	for(int mode=0; mode<3; mode++){
		clock_t begin =clock();
		double res[SIZE];
	    process_data(res,data,count,channels,mode);
		clock_t end =clock();
		double time_spend= (double)(end-begin)/CLOCKS_PER_SEC;
		printf("Mode: %d 	time of execution: %lf sec\n",mode,time_spend);
	}
}




