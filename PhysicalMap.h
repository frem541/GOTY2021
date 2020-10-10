#ifndef PHYSICALMAP_H
#define PHYSICALMAP_H

#include <GLFW/glfw3.h>
#include "fstream"

struct MapZone
{
    double leftX,rightX,topZ,bottomZ;
    char type;
};

class PhysicalMap
{
protected:
    MapZone* Zones;
    unsigned long long numofZones, sizeX, sizeZ;
public:
    void LoadMap(char* filename);
    void Show();
    void getSize(unsigned long long& sizex, unsigned long long& sizez);
    MapZone getZone(unsigned long long num);
    unsigned long long getnumofZones();
	~PhysicalMap();
};

#endif // PHYSICALMAP_H