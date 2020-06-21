#include "Scene.h"
#include "PrimTriangle.h"
#include "ShaderEyelight.h"
#include "ShaderPhong.h"


void CScene::ParseOBJ(const std::string& fileName)
{
	std::cout << "Parsing OBJnewfile : " << fileName << std::endl;

	std::shared_ptr<IShader> pShader = std::make_shared<CShaderEyelight>(RGB(1, 1, 1));
	// --- PUT YOUR CODE HERE ---

	//this vector is for values of v
	//each v represents the x,y,z coordinates
	//of a point
	std::vector<Vec3f> vertices;
	Vec3f vertex;

	//this vector is for values of f
	//each f represents a set of 3 verticies
	//forming a triangle
	std::vector<unsigned int> fVertexIndices;
	
	std::ifstream newfile;

	newfile.open("cow.obj", std::ios::out | std::ios::app | std::ios::binary);
	//newfile.open(fileName);
	if (!newfile.is_open())
	{
		std::cout << " Unable to Open File For Parsing\n" << std::endl;
		return;
	}

	//if line starts from v, it is a vertex
	//we read the 3 x, y, z coordinates and store in it 
	//our Vector3f vertex
	//we multiply values with 99.99 because the original 
	//coordinate values are way too small
	//without this, we only get a plain black image

	std::string line;
			
    while (std::getline(newfile, line))
    {
		
		if (line[0] == 'v')
		{
			std::istringstream str(&line[1]);
   			str >> vertex[0] >> vertex[1] >> vertex[2];
			vertices.push_back(99.9f * vertex);
		}

		//if the line starts from f, it is representing a 
		//set of 3 verticies forming a triangle

		else if(line[0] == 'f')
		{

			//we store indexes of 3 vertices given after each f
			//in the following array
			unsigned int triVertices[3];
			std::istringstream str(&line[1]);
   			str >> triVertices[0] >> triVertices[1] >> triVertices[2];

			fVertexIndices.push_back(triVertices[0]);
			fVertexIndices.push_back(triVertices[1]);
			fVertexIndices.push_back(triVertices[2]);
		}
	}

	int i = 0;
	while(i < fVertexIndices.size())
	{
		//these will be the three vertices of each triangle
		Vec3f tri1, tri2, tri3;

		//we obtain the value by going to indexes mentioned in f
		//indexes in our cow.obj file start from 1
		//and not 0. Thus, we subtract 1
		tri1 = vertices[fVertexIndices[i]-1];
		i++;

		tri2 = vertices[fVertexIndices[i]-1];
		i++;
		
		tri3 = vertices[fVertexIndices[i]-1];
		i++;

		Add(std::make_shared<CPrimTriangle>(tri1, tri2, tri3, pShader));
	}
	newfile.close();

	std::cout << "Finished Parsing" << std::endl;
}

