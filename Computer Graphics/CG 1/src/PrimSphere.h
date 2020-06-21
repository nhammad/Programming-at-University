// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Sphere Geaometrical Primitive class
 */
class CPrimSphere : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param center Position of the center of the sphere
	 * @param radius Radius of the sphere
	 */
	CPrimSphere(Vec3f center, float radius)
		: CPrim(), m_center(center), m_radius(radius)
	{
	}
	virtual ~CPrimSphere(void) = default;

	virtual bool Intersect(Ray &ray) override
	{
		// --- PUT YOUR CODE HERE ---

		//Code Reference: Scratchapixel.com & HW Problem 2.c

		//note: since we use quadratic formula, there are 2 possible values of t

		// we'll use the smallest value for further calculations

		float a = ray.dir.dot(ray.dir); //d dot d
		float b = 2*ray.dir.dot(ray.org - m_center);
		float c = (ray.org - m_center).dot(ray.org - m_center) - m_radius*m_radius;
		float trying = b*b - (4*a*c); //main eq

		if (trying < 0)
		{
			printf("Ivalid\n");
			return false;
		}

		float t;
		float t1 = ((-b) + sqrt(trying)) / (2*a);
		float t2 = ((-b) - sqrt(trying)) / (2*a);

		if (t1 > t2)
			{
				t = t2;
			}
		else
			{
				t = t1;
			}

		//checking ranges. 
		if ((t > Epsilon) && (t < ray.t))
		{
			ray.t = t;
			return true;
		}
		//if val is too close to epsilon, sol is invalid
		else
			{
				printf("Ivalid\n");
				return false;
			}
	}

private:
	Vec3f m_center; ///< Position of the center of the sphere
	float m_radius; ///< Radius of the sphere
};