#pragma once
#include <stdlib.h>
#define FRAME 512
//Header For Audio File(Wav File)
typedef struct waveheader
{
	char chunk_id[4];
	int chunk_size;
	char format[4];
	char subchunk1_id[4];
	int subchunk1_size;
	short int audio_format;
	short int num_channels;
	int sample_rate;			// sample_rate denotes the sampling rate.
	int byte_rate;
	short int block_align;
	short int bits_per_sample;
	char subchunk2_id[4];
	int subchunk2_size;			// subchunk2_size denotes the number of samples.
} Waveheader;

typedef struct waveheader* headerobj;

typedef float float_32t;
typedef int int_32t;
void MonoEnhance(float *src,float gain);
void StereoEnhance(float *Src, float gain);
