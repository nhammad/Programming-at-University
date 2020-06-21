#pragma once

#include "types.h"
#include "ray.h"


namespace {
	inline Vec3f Min3f(const Vec3f a, const Vec3f b)
	{
		return Vec3f(MIN(a.val[0], b.val[0]), MIN(a.val[1], b.val[1]), MIN(a.val[2], b.val[2]));
	}

	inline Vec3f Max3f(const Vec3f a, const Vec3f b)
	{
		return Vec3f(MAX(a.val[0], b.val[0]), MAX(a.val[1], b.val[1]), MAX(a.val[2], b.val[2]));
	}
}

/**
 * @brief Bounding Box class
 */
class CBoundingBox
{
public:
	CBoundingBox(void) = default;
	~CBoundingBox(void)= default;
	
	/**
	 * @brief Resets the bounding box
	 * @details This function resets the member variables \b m_min and \b m_max
	 */
	void clear(void)
	{
		m_min = Vec3f::all(std::numeric_limits<float>::infinity());
		m_max = Vec3f::all(-std::numeric_limits<float>::infinity());
	}
	
	/**
	 * @brief Extends the bounding box to contain point \b a
	 * @param a A point
	 */
	void extend(Vec3f a)
	{
		m_min = Min3f(a, m_min);
		m_max = Max3f(a, m_max);
	}
	
	/**
	 * @brief Extends the bounding box to contain bounding box \b box
	 * @param box The second bounding box
	 */
	void extend(const CBoundingBox& box)
	{
		extend(box.m_min);
		extend(box.m_max);
	}
	
	/**
	 * @brief Checks if the current bounding box overlaps with the argument bounding box \b box
	 * @param box The secind bounding box to be checked with
	 */
	bool overlaps(const CBoundingBox& box)
	{
		for (int i = 0; i < 3; i++) {
			if (box.m_min[i] - Epsilon > m_max[i]) return false;
			if (box.m_max[i] + Epsilon < m_min[i]) return false;
		}
		return true;
	}
	
	/**
	 * @brief Clips the ray with the bounding box
	 * @param[in] ray The ray
	 * @param[in,out] t0 The distance from ray origin at which the ray enters the bounding box
	 * @param[in,out] t1 The distance from ray origin at which the ray leaves the bounding box
	 */
	void clip(const Ray& ray, float& t0, float& t1)
	{
		float d, den;
		den = 1.0f / ray.dir.val[0];
		if (ray.dir.val[0] > 0) {
			if ((d = (m_min.val[0] - ray.org.val[0]) * den) > t0) t0 = d;
			if ((d = (m_max.val[0] - ray.org.val[0]) * den) < t1) t1 = d;
		}
		else {
			if ((d = (m_max.val[0] - ray.org.val[0]) * den) > t0) t0 = d;
			if ((d = (m_min.val[0] - ray.org.val[0]) * den) < t1) t1 = d;
		}
		if (t0 > t1) return;

		den = 1.0f / ray.dir.val[1];
		if (ray.dir.val[1] > 0) {
			if ((d = (m_min.val[1] - ray.org.val[1]) * den) > t0) t0 = d;
			if ((d = (m_max.val[1] - ray.org.val[1]) * den) < t1) t1 = d;
		}
		else {
			if ((d = (m_max.val[1] - ray.org.val[1]) * den) > t0) t0 = d;
			if ((d = (m_min.val[1] - ray.org.val[1]) * den) < t1) t1 = d;
		}
		if (t0 > t1) return;

		den = 1.0f / ray.dir.val[2];
		if (ray.dir.val[2] > 0) {
			if ((d = (m_min.val[2] - ray.org.val[2]) * den) > t0) t0 = d;
			if ((d = (m_max.val[2] - ray.org.val[2]) * den) < t1) t1 = d;
		}
		else {
			if ((d = (m_max.val[2] - ray.org.val[2]) * den) > t0) t0 = d;
			if ((d = (m_min.val[2] - ray.org.val[2]) * den) < t1) t1 = d;
		}
		return;
	}
	
	
public:
	Vec3f m_min = Vec3f::all(std::numeric_limits<float>::infinity());	///< The minimal point defying the size of the bounding box
	Vec3f m_max = Vec3f::all(-std::numeric_limits<float>::infinity());	///< The maximal point defying the size of the bounding box
};
