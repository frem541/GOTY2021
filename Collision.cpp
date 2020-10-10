#include "Collision.h"

bool ComputeMapCollision(PhysicalMap& physmap, PhysicalObject2D& object)
{
    unsigned long long numofZones = physmap.getnumofZones();
    float objectLeftX, objectRightX, objectTopZ, objectBottomZ;
    objectLeftX = object.getVertexCoord(0,0);
    objectRightX = object.getVertexCoord(1,0);
    objectTopZ = object.getVertexCoord(1,2);
    objectBottomZ = object.getVertexCoord(2,2);
    double ratioX, ratioZ;
    unsigned long long sizeX, sizeZ;
    physmap.getSize(sizeX, sizeZ);
    ratioX = 1/double(sizeX);
    ratioZ = 1/double(sizeZ);

    for (unsigned long long i = 0; i < numofZones; i++)
    {
        if (physmap.getZone(i).type == 'C')
        {
            if ((physmap.getZone(i).topZ*ratioZ-0.5f < objectTopZ) && (physmap.getZone(i).bottomZ*ratioZ-0.5f > objectTopZ) && (physmap.getZone(i).leftX*ratioX-0.5f < objectLeftX) && (physmap.getZone(i).rightX*ratioX-0.5f > objectLeftX))
                return false;
            if ((physmap.getZone(i).topZ*ratioZ-0.5f < objectTopZ) && (physmap.getZone(i).bottomZ*ratioZ-0.5f > objectTopZ) && (physmap.getZone(i).leftX*ratioX-0.5f < objectRightX) && (physmap.getZone(i).rightX*ratioX-0.5f > objectRightX))
                return false;
            if ((physmap.getZone(i).topZ*ratioZ-0.5f < objectBottomZ) && (physmap.getZone(i).bottomZ*ratioZ-0.5f > objectBottomZ) && (physmap.getZone(i).leftX*ratioX-0.5f < objectLeftX) && (physmap.getZone(i).rightX*ratioX-0.5f > objectLeftX))
                return false;
            if ((physmap.getZone(i).topZ*ratioZ-0.5f < objectBottomZ) && (physmap.getZone(i).bottomZ*ratioZ-0.5f > objectBottomZ) && (physmap.getZone(i).leftX*ratioX-0.5f < objectRightX) && (physmap.getZone(i).rightX*ratioX-0.5f > objectRightX))
                return false;
        }
    }
    return true;
}
