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
		// --- PUT YOUR CODE HERE ---
		//Reference: www.scratchapixel.com/code.php?id=13&origin=/lessons/3d-basic-rendering/introduction-to-shading

		/*Vec3f lightDir = (ray.dir - m_position); 
        float r2 = normalize(lightDir);
        float distance = sqrt(r2); 
        lightDir[0] /= distance, lightDir[1] /= distance, lightDir[2] /= distance; 
        Vec3f lightIntensity = m_color * m_intensity / (4 * M_PI * r2); 
		return lightIntensity;*/

		/*Vec3f intensity; 
		int i = 0;
		for (i = 0; i < 3; i++)
		{
			intensity[i]= m_intensity[i]/pow(((ray.org[i] + ray.t*ray.dir[i]) - m_position[i]),2);
		}
		return intensity;*/

		Vec3f lightDir = m_position - ray.org;

		Vec3f intensity;
		Vec3f normalized;
		intensity = m_intensity / pow(cv :: norm(lightDir), 2);
		ray.dir = normalize(lightDir);
		normalized = normalize(intensity);
		
		return normalized;
	}


private:
	Vec3f m_intensity; ///< emission (red, green, blue)
	Vec3f m_position;  ///< The light source origin
};
