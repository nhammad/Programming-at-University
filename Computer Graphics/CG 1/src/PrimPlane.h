// Plane Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief The Plane Geaometrical Primitive class
 */
class CPrimPlane : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param origin Point on the plane
	 * @param normal Normal to the plane
	 */
	CPrimPlane(Vec3f origin, Vec3f normal)
		: CPrim(), m_normal(normal), m_origin(origin)
	{
		normalize(m_normal);
	}
	virtual ~CPrimPlane(void) = default;

	virtual bool Intersect(Ray &ray) override
	{
		// --- PUT YOUR CODE HERE ---

		//Refernece: course slides + what TA explained via email

		float val; //val = Current/maximum hit distance
		float num = m_normal.dot(m_origin - ray.org);
		float den = m_normal.dot(ray.dir);

		if (den != 0)
		{
			val = num/den;
		}
		else
		{
			printf("Inavlid\n");
			return 0;
		}
					 

		//checking ranges. 
		//if val is too close to epsilon, sol is invalid
		if (val < Epsilon || val > ray.t)
		{
			printf("Invalid Case\n");
			return false;
		}

		//assigning value to ray.t
		ray.t = val;
		return true;
	}

private:
	Vec3f m_normal; ///< Point on the plane
	Vec3f m_origin; ///< Normal to the plane
};