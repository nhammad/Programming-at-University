// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */
	CPrimTriangle(Vec3f a, Vec3f b, Vec3f c)
		: CPrim(), m_a(a), m_b(b), m_c(c)
	{
	}
	virtual ~CPrimTriangle(void) = default;

	virtual bool Intersect(Ray &ray) override
	{
		// --- PUT YOUR CODE HERE ---

		// Reference: Course Slides/ Scratch Pixel

		Vec3f vecAB = (m_b-ray.org).cross(m_a-ray.org);
		Vec3f vecBC = (m_c-ray.org).cross(m_b-ray.org);
		Vec3f vecCA = (m_a-ray.org).cross(m_c-ray.org);

		float area = vecAB.dot(ray.dir)+vecBC.dot(ray.dir)+vecCA.dot(ray.dir);
		float lambdaOne = vecAB.dot(ray.dir)/area;
		float lambdaTwo = vecBC.dot(ray.dir)/area;
		float lambdaThree = vecCA.dot(ray.dir)/area;

		if (lambdaOne < 0 || lambdaTwo < 0 || lambdaThree < 0)
		{
			printf("Invalid Cases\n");
			return false;
		}

		Vec3f phit = lambdaOne*m_a + lambdaTwo*m_b + lambdaThree*m_c;
		float t = phit[0]/ray.dir[0];
		
		//if value is too close to epsilon, it's an ivalid case
		if (t < Epsilon || t > ray.t)
		{
			printf("Invalid Cases\n");
			return false;
		}

		ray.t = t;
		return true;
	}

private:
	Vec3f m_a; ///< Position of the first vertex
	Vec3f m_b; ///< Position of the second vertex
	Vec3f m_c; ///< Position of the third vertex
};