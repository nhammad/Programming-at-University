#pragma once

#include "ShaderFlat.h"

class CScene;

class CShaderPhong : public CShaderFlat
{
public:
	/**
	 * @brief Constructor
	 * @param scene Reference to the scene
	 * @param color The color of the object
	 * @param ka The ambient coefficient
	 * @param kd The diffuse reflection coefficients
	 * @param ks The specular refelection coefficients
	 * @param ke The shininess exponent
	 */
	CShaderPhong(CScene& scene, Vec3f color, float ka, float kd, float ks, float ke)
		: CShaderFlat(color)
		, m_scene(scene)
		, m_ka(ka)
		, m_kd(kd)
		, m_ks(ks)
		, m_ke(ke)
	{}
	virtual ~CShaderPhong(void) = default;


	//the parameter ray is the ray coming from the camera
	virtual Vec3f Shade(const Ray& ray) const override
	{
		// --- PUT YOUR CODE HERE ---
		/*Vec3f partA = m_ka * RGB(1,1,1);

		/*for(std::vector<auto>::iterator id; CScene::m_vpLights.begin(); id != CScene::m_vpLights.end(); id++)
		for(int i = 0; i < CScene::m_vpLights.size(); i++) {
 			auto light = CScene::m_vpLights[i];*/

		//Reference: 
		//https://www.scratchapixel.com/lessons/3d-basic-rendering/phong-shader-BRDF

		Vec3f white = RGB(1, 1, 1);

		// CShaderFlat::Shade(ray) is the product of Ca and La
		Vec3f partA = m_ka * CShaderFlat::Shade(ray);
		Vec3f cdTotal = 0;
		int i = 0;

		//let myRay be the ray coming from our light source
		Ray myRay;

		for (i ; i < m_scene.m_vpLights.size(); i++)
		{
			myRay.org = ray.org + ray.t*ray.dir;
			std::optional<Vec3f> LI = m_scene.m_vpLights[i] -> Illuminate(myRay);
			myRay.t = std::numeric_limits<float>::infinity();
			
			if (m_scene.Occluded(myRay) == false)
			{
				if(LI)
				{
					//checking all light sources for their LI value 
					//finding the products of Li and (I dot N)
					//summing all products
					//we use the max value because we only have to consider 
					//sources that illuminate the primitive from its front-side (i.e. Il·N > 0).
					float angle = max(0.0f, myRay.dir.dot(ray.hit->GetNormal(ray)));
					cdTotal += * LI * angle;
				}
			}
		}

		Vec3f partD = m_kd * cdTotal.mul(CShaderFlat::Shade(ray));
		int j = 0;
		Vec3f csTotal = 0;
		
		Ray secondRay;

		for(j ; j < m_scene.m_vpLights.size(); ++j)
		{
			secondRay.org = ray.org + ray.t*ray.dir;
			std::optional<Vec3f> LI = m_scene.m_vpLights[i]->Illuminate(secondRay);
			secondRay.t = std::numeric_limits<float>::infinity();

			//if not blocked:
			if (m_scene.Occluded(myRay) == false)
			{
				if (LI)
				{
					Vec3f distReflected = secondRay.dir - 2 * (secondRay.dir.dot(ray.hit->GetNormal(ray))) * ray.hit->GetNormal(ray);
					float cosAngle = max(0.0f, ray.dir.dot(distReflected));
					csTotal += * LI * pow(cosAngle, m_ke);
				}
			}
		}

		Vec3f partS = m_ks * white.mul(csTotal);

		return partA + partD + partS;
		//return RGB(0, 0, 0);
	}

	
private:
	CScene& m_scene;
	float 	m_ka;    ///< ambient coefficient
	float 	m_kd;    ///< diffuse reflection coefficients
	float 	m_ks;    ///< specular refelection coefficients
	float 	m_ke;    ///< shininess exponent
};
