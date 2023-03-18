#include <stdio.h>
#include "StereoEnhancement.h"

int main()
{
	char *input = "Stream8_Mono.wav";
	char *output = "Output.wav";

	FILE *fr, *fw;
	fr = fopen(input, "rb");
	fw = fopen(output, "wb");

	headerobj content = (headerobj)malloc(sizeof(Waveheader));

	fread(content, 1, sizeof(Waveheader), fr);
	const int ChannelCheck = (content->num_channels == 1) ? (content->num_channels = 2,content->block_align*=2,
                            content->byte_rate*=2,content->chunk_size*=2,content->subchunk2_size*=2) : 0;
	float gain = 2.5;
	fwrite(content, 1, sizeof(Waveheader), fw);


	float src[FRAME] = { 0 };

	short Inbuf[FRAME] = { 0 };
	short outbuf[FRAME] = { 0 };

	while (!feof(fr)) {
		
		if (ChannelCheck) {
			fread(Inbuf, sizeof(short int), 256, fr);
			for (int i = 0,k = 0; i < 256; i++) {
				src[k++] = (float)(Inbuf[i] / 32767.f);
				src[k++] = (float)(Inbuf[i] / 32767.f);
			}
		}
		else {
			fread(Inbuf, sizeof(short int), FRAME, fr);
			for (int i = 0; i < FRAME; i++)
				src[i] = (float)(Inbuf[i] / 32767.f);
		}

		StereoEnhance(src, gain);

		for (int i = 0; i < FRAME; i++)
			outbuf[i] = (short)(src[i] * 32767.f);

		fwrite(outbuf, sizeof(short int), FRAME, fw);
	}
	return 0;
}
