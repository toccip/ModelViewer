#pragma once
#include <vector>
#include "../linearalgebra.h"

namespace quetzal {

	static bool read_obj(const char* filename, std::vector<vec3>& vertices, std::vector<vec2>& uvs, 
		std::vector<vec3>& normals, std::vector<unsigned int>& indices) {

		FILE* fp = fopen(filename, "r");
		if (fp == NULL) {
			std::cout << "OBJ load failure: " << filename << " - failed to open" << std::endl;
			return false;
		}

		char readIN[128];

		std::vector<vec2> a_uvs;
		std::vector<vec3> a_normals;

		bool shouldBreak = false;

		while (!shouldBreak)
		{
			if (fscanf(fp, "%s", readIN) == EOF) {
				std::cout << "OBJ load failure: " << filename << " - unexpected EOF" << std::endl;
				fclose(fp);
				return false;
			}
			if (!strcmp(readIN, "v")) {
				vec3 temp;
				fscanf(fp, "%f %f %f\n", &temp.x, &temp.y, &temp.z);
				vertices.push_back(temp);
			}
			else if (!strcmp(readIN, "vt")) {
				vec2 temp;
				fscanf(fp, "%f %f\n", &temp.x, &temp.y);
				a_uvs.push_back(temp);
			}
			else if (!strcmp(readIN, "vn")) {
				vec3 temp;
				fscanf(fp, "%f %f %f\n", &temp.x, &temp.y, &temp.z);
				a_normals.push_back(temp);
			}
			else if (!strcmp(readIN, "f")) {
				shouldBreak = true;
			}
		}

		unsigned int vertexIndex[3];
		unsigned int uvIndex[3];
		unsigned int normalIndex[3];
		for (int i = 0; i < vertices.size(); i++) {
			uvs.push_back(vec2());
			normals.push_back(vec3());
		}

		do {
			if (!strcmp(readIN, "f")) {
				fscanf(fp, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
					&vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
				indices.push_back(vertexIndex[0] - 1);
				indices.push_back(vertexIndex[1] - 1);
				indices.push_back(vertexIndex[2] - 1);

				uvs[vertexIndex[0] - 1] = a_uvs[uvIndex[0] - 1];
				uvs[vertexIndex[1] - 1] = a_uvs[uvIndex[1] - 1];
				uvs[vertexIndex[2] - 1] = a_uvs[uvIndex[2] - 1];

				normals[vertexIndex[0] - 1] = a_normals[normalIndex[0] - 1];
				normals[vertexIndex[1] - 1] = a_normals[normalIndex[1] - 1];
				normals[vertexIndex[2] - 1] = a_normals[normalIndex[2] - 1];

			}
		} while (fscanf(fp, "%s", readIN) != EOF);

		fclose(fp);
		return true;
	}

	static bool read_bmp(const char* filename, unsigned char*& data, unsigned int& width, unsigned int& height) {
		unsigned char header[54]; // Each BMP file begins by a 54-bytes header
		unsigned int dataPos;     // Position in the file where the actual data begins
		unsigned int imageSize;   // = width*height*3
								  // Actual RGB data

								  // Open the file
		FILE * file = fopen(filename, "rb");
		if (!file) { printf("Image could not be opened\n"); return 0; }

		if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
			printf("Not a correct BMP file\n");
			return false;
		}

		if (header[0] != 'B' || header[1] != 'M') {
			printf("Not a correct BMP file\n");
			return false;
		}

		// Read ints from the byte array
		dataPos = *(int*)&(header[0x0A]);
		imageSize = *(int*)&(header[0x22]);
		width = *(int*)&(header[0x12]);
		height = *(int*)&(header[0x16]);

		// Some BMP files are misformatted, guess missing information
		if (imageSize == 0)    imageSize = width * height * 3; // 3 : one byte for each Red, Green and Blue component
		if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

											 // Create a buffer
		data = new unsigned char[imageSize];

		// Read the actual data from the file into the buffer
		fread(data, 1, imageSize, file);

		//Everything is in memory now, the file can be closed
		fclose(file);
		return true;
	}
}