#pragma once

#include "ShaderFlat.h"

/**
 * @brief Eye-light shader class
 */
class CShaderEyelight : public CShaderFlat
{
public:
	/**
	 * @brief Constructor
	 * @details This is a texture-free and light-source-free shader
	 * @param scene Reference to the scene
	 * @param color The color of the object
	 */
	CShaderEyelight(Vec3f color = RGB(0.5f, 0.5f, 0.5f))
		: CShaderFlat(color)
	{}
	virtual ~CShaderEyelight(void) = default;

	virtual Vec3f Shade(const Ray& ray) const override
	{
		float cos = ray.dir.dot(ray.hit->GetNormal(ray));
		//return (cos > 0) ? Vec3f(0, 0, 0) : m_color * cos;
		
		if (cos > 0) return RGB(0, 0, 0);
		return CShaderFlat::Shade() * fabs(cos);
		
		return CShaderFlat::Shade() * fabs(ray.dir.dot(ray.hit->GetNormal(ray)));
	}
};

