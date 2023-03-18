#include "StereoEnhancement.h"
void StereoEnhance(float *src, float gain)
{
	for (int i = 0; i < FRAME; i += 2)
	{
		float left = src[i];
		float right = src[i + 1];
		float pos = (left + right) / 2;
		float neg = (left - right) / 2;
		src[i] = pos + neg * gain;
		src[i + 1] = pos - neg * gain;
		src[i] = (src[i] > 1.0f) ? 1.0f : ((src[i] < -1.0f) ? -1.0f : src[i]);
		src[i + 1] = (src[i + 1] > 1.0f) ? 1.0f : ((src[i + 1] < -1.0f) ? -1.0f : src[i + 1]);
	}
}

void MonoEnhance(float *src,float gain)
{
    for (int i = 0; i < FRAME; i += 2)
	{
		float mid = src[i];
		src[i] = (mid * gain)/2;
		src[i + 1] = (mid * gain)/2;
		src[i] = (src[i] > 1.0f) ? 1.0f : ((src[i] < -1.0f) ? -1.0f : src[i]);
		src[i + 1] = (src[i + 1] > 1.0f) ? 1.0f : ((src[i + 1] < -1.0f) ? -1.0f : src[i + 1]);
	}
}
