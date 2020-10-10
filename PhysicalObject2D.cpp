#include "PhysicalObject2D.h"

void PhysicalObject2D::RefreshVertexArray()
{
    VertexArray[0][0] = CoordX;
    VertexArray[0][1] = CoordY;
    VertexArray[0][2] = CoordZ;

    VertexArray[1][0] = CoordX+SizeX;
    VertexArray[1][1] = CoordY;
    VertexArray[1][2] = CoordZ;

    VertexArray[2][0] = CoordX+SizeX;
    VertexArray[2][1] = CoordY;
    VertexArray[2][2] = CoordZ+SizeZ;

    VertexArray[3][0] = CoordX;
    VertexArray[3][1] = CoordY;
    VertexArray[3][2] = CoordZ+SizeZ;
}

PhysicalObject2D::PhysicalObject2D(float coordX, float coordY, float coordZ, float sizeX, float SizeZ)
{
    SetCoordinates(coordX, coordY, coordZ);
    SetSize(sizeX, SizeZ);
}

void PhysicalObject2D::SetCoordinates(float coordX, float coordY, float coordZ)
{
    CoordX = coordX;
    CoordY = coordY;
    CoordZ = coordZ;

    RefreshVertexArray();
}

void PhysicalObject2D::SetSize(float sizeX, float sizeZ)
{
    SizeX = sizeX;
    SizeZ = sizeZ;

    RefreshVertexArray();
}

void PhysicalObject2D::Draw(float R, float G, float B)
{
    glBegin(GL_POLYGON);
    glColor3f(R,G,B);
    for (int i = 0; i < 4; i++)
        glVertex3f(VertexArray[i][0],VertexArray[i][1],VertexArray[i][2]);
    glEnd();
}

void PhysicalObject2D::Draw()
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; i++)
        glVertex3f(VertexArray[i][0],VertexArray[i][1],VertexArray[i][2]);
    glEnd();
}

void PhysicalObject2D::MoveTo(float moveX, float moveY, float moveZ)
{
    CoordX+=moveX;
    CoordY+=moveY;
    CoordZ+=moveZ;

    RefreshVertexArray();
}

inline float PhysicalObject2D::getVertexCoord(int i, int j) const
{
    return VertexArray[i][j];
}
