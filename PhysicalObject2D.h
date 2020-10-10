#ifndef PHYSICALOBJECT2D_H
#define PHYSICALOBJECT2D_H

#include <GLFW/glfw3.h>

class PhysicalObject2D
{
protected:
    float VertexArray[4][3];
    float CoordX, CoordY, CoordZ, SizeX, SizeZ;
    void RefreshVertexArray();
public:
    PhysicalObject2D(float coordX, float coordY, float coordZ, float sizeX, float SizeZ);
    void SetCoordinates(float coordX, float coordY, float coordZ);
    void SetSize(float sizeX, float sizeZ);
    void Draw(float R, float G, float B);
    void Draw();
    void MoveTo(float moveX, float moveY, float moveZ);
    inline float getVertexCoord(int i, int j) const;
};

#endif // PHYSICALOBJECT2D_H