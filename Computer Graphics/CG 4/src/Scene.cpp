#include "Scene.h"

#include "ShaderEyelight.h"
#include "ShaderEyelightTextured.h"
#include "ShaderPhong.h"
#include "PrimTriangle.h"
#include "PrimTriangleSmooth.h"
#include "PrimTriangleSmoothTextured.h"

#include <fstream> 


void CScene::ParseOBJ(const std::string& fileName)
{
	std::ifstream file(fileName);

	if (file.is_open()) {
		std::cout << "Parsing OBJFile : " << fileName << std::endl;

		std::shared_ptr<IShader> pShader = std::make_shared<CShaderEyelight>(RGB(1, 0.5f, 0));
		std::vector<Vec3f> vVertexes;
		std::vector<Vec2f> tempuvs;
		std::vector<Vec3f> temp_normal;

		std::string line;

		//obj file contains f, vn, v & vt so we put cases for all of them

		for (;;) {
			if (!getline(file, line)) break;
			std::stringstream ss(line);
			getline(ss, line, ' ');
			if (line == "v") {
				Vec3f v;
				for (int i = 0; i < 3; i++) ss >> v.val[i];
				// std::cout << "Vertex: " << v << std::endl;
				vVertexes.emplace_back(100 * v);
			}

			else if (line == "f") {
				Vec3i f_a,f_b,f_c;
				char c;
				for (int i = 0; i < 3; i++){
					
					ss >> f_a.val[i] >> c >> f_b.val[i] >> c >> f_c.val[i];
				} 
				// std::cout << "Face: " << f << std::endl;
				// Add(std::make_shared<CPrimTriangle>(vVertexes[f.val[0] - 1], vVertexes[f.val[1] - 1], vVertexes[f.val[2] - 1], pShader));
				Add(std::make_shared<CPrimTriangleSmooth>(vVertexes[f_a.val[0]-1],vVertexes[f_a.val[1]-1],vVertexes[f_a.val[2]- 1],temp_normal[f_a.val[0]-1],temp_normal[f_c.val[1]-1],temp_normal[f_c.val[2]-1], pShader));
			}

			else if (line == "vt"){
				Vec2f vt;
				for (int i = 0; i < 2; ++i) ss >> vt.val[i];
				tempuvs.emplace_back(vt);
			}

			else if (line == "vn"){
				Vec3f vn;
				for (int i = 0; i < 2; ++i) ss >> vn.val[i];
				temp_normal.emplace_back(vn * 100);
			}
			else {
				std::cout << "Unknown key [" << line << "] met in the OBJ file" << std::endl;
			}
		}

		file.close();
		std::cout << "Finished Parsing" << std::endl;
	} else
		std::cout << "ERROR: Can't open OBJFile" << std::endl;
}
