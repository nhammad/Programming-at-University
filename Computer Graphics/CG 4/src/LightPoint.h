#pragma once

#include "ILight.h"

/**
 * @brief Point light source class
 */
class CLightPoint : public ILight
{
public:
	/**
	 * @brief Constructor
	 * @param position The position (origin) of the light source
	 * @param intensity The emission color and strength of the light source
	 */
	CLightPoint(Vec3f intensity, Vec3f position)
		: m_intensity(intensity)
		, m_position(position)
	{} 
	virtual ~CLightPoint(void) = default;

	virtual std::optional<Vec3f> Illuminate(Ray& ray) override
	{
		// ray towards point light position
		ray.dir = m_position - ray.org;
		ray.hit = NULL;
		ray.t   = norm(ray.dir) - Epsilon; // maximal ray length
		ray.dir = normalize(ray.dir);
	
		// return attenuated intensity
		float attenuation = 1.0f / ray.t;
		//float attenuation = 1.0f / (ray.t * ray.t);
		//float attenuation = 1.0f / (0.5f * ray.t + 1.0f); // linear attenuation
		return attenuation * m_intensity;
	}


private:
	Vec3f m_intensity; ///< emission (red, green, blue)
	Vec3f m_position;  ///< The light source origin
};
