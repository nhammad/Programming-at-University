#pragma once

#include "PrimTriangleSmooth.h"

/**
* @brief Smooth triangle primitive with support of textures class interface
*/
class CPrimTriangleSmoothTextured : public CPrimTriangleSmooth
{
public:
	CPrimTriangleSmoothTextured(Vec3f a, Vec3f b, Vec3f c, Vec3f na, Vec3f nb, Vec3f nc, Vec2f ta, Vec2f tb, Vec2f tc, std::shared_ptr<IShader> pShader)
		: CPrimTriangleSmooth(a, b, c, na, nb, nc, pShader)
		, m_ta(ta)
		, m_tb(tb)
		, m_tc(tc)
	{}
	virtual ~CPrimTriangleSmoothTextured(void) = default;
  
	virtual Vec2f getUV(const Ray& ray) const override
	{
		// assume u/v coordinates in ray correspond to beta(u) and gamma(v) barycentric coordinates of 
		// hitpoint on triangle (have to be stored like this in the intersection code !)
		// --- PUT YOUR CODE HERE ---
		return Vec2f(0, 0);
	}


private:
	Vec2f m_ta;	///< vertex a texture coordiante
	Vec2f m_tb;	///< vertex b texture coordiante
	Vec2f m_tc;	///< vertex c texture coordiante 
};	

