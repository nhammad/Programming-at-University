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
	 * @param pShader Pointer to the shader to be applied for the prim
	 */
	CPrimPlane(Vec3f origin, Vec3f normal, std::shared_ptr<IShader> pShader)
		: CPrim(pShader)
		, m_normal(normalize(normal))
		, m_origin(origin)
	{}
	virtual ~CPrimPlane(void) = default;

	virtual bool Intersect(Ray& ray) override
	{
		float t = (m_origin - ray.org).dot(m_normal) / ray.dir.dot(m_normal);
		if (t < Epsilon || t > ray.t) return false;
		ray.t = t;
		ray.hit = this;
		return true;
	}
	
	virtual Vec3f getNormal(const Ray& ray) const override { return m_normal; }
	
	virtual CBoundingBox calcBounds(void) const override
	{
		CBoundingBox bounds;
		float Infinity = std::numeric_limits<float>::infinity();

		if (m_normal.val[0] == 0) {
			bounds.extend(Vec3f(m_origin.val[0], -Infinity, -Infinity));
			bounds.extend(Vec3f(m_origin.val[0], Infinity, Infinity));
		}
		else if (m_normal.val[1] == 0) {
			bounds.extend(Vec3f(-Infinity, m_origin.val[1], -Infinity));
			bounds.extend(Vec3f(Infinity,  m_origin.val[1], Infinity));
		}
		else if (m_normal.val[2] == 0) {
			bounds.extend(Vec3f(-Infinity, -Infinity, m_origin.val[2]));
			bounds.extend(Vec3f(Infinity,   Infinity, m_origin.val[2]));
		}
		else {
			bounds.extend(Vec3f(-Infinity, -Infinity, -Infinity));
			bounds.extend(Vec3f(Infinity, Infinity, Infinity));
		}
		return bounds;
	}
	
private:
	Vec3f m_normal;	///< Point on the plane
	Vec3f m_origin;	///< Normal to the plane
};
