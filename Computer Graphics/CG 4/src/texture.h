#pragma once

#include "types.h"

class Texture : public Mat
{
public:
	Texture(int resX, int resY) : Mat(resY, resX, CV_32FC3) {}

	Texture(const std::string& fileName) : Mat(imread(fileName)) 
	{
		(*this).convertTo(*this, CV_32FC3, 1.0 / 255);
	}
  
	Vec3f GetTexel(float u, float v) const
	{
		// find texel indices
		int px = static_cast<int>(floor(cols * u));
		int py = static_cast<int>(floor(rows * v));

		// texture repeat wrap
		px = ((px % cols) + cols) % cols;
		py = ((py % rows) + rows) % rows;

		return (*this).at<Vec3f>(py, px);
	}

	void GetResolution(float &dx, float &dy) const 
	{
		dx = 1.0f / cols;
		dy = 1.0f / rows;
	}
};
