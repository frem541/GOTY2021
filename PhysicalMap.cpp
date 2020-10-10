#include "PhysicalMap.h"

void PhysicalMap::LoadMap(char* filename)
{
    sizeX = 0;
    sizeZ = 0;
    std::ifstream fin;
    fin.open(filename, std::ios::in);
    long long cntr = 0;
    char *str = new char [1024];
    while(fin)
    {
        fin.getline(str, 1024, '\n');
        cntr++;
    }
    cntr--;
    delete str;
    fin.close();
    fin.open(filename, std::ios::in);
    Zones = new MapZone[cntr];
    numofZones = cntr;
    cntr--;
    for (cntr; cntr >= 0; cntr--)
    {
        fin >> Zones[cntr].type;
        fin >> Zones[cntr].leftX;
        fin >> Zones[cntr].topZ;
        fin >> Zones[cntr].rightX;
        fin >> Zones[cntr].bottomZ;
        if (Zones[cntr].rightX > sizeX)
            sizeX = Zones[cntr].rightX;
        if (Zones[cntr].bottomZ > sizeZ)
            sizeZ = Zones[cntr].bottomZ;
    }
    fin.close();
}
void PhysicalMap::Show()
{
    double ratioX, ratioZ;
    ratioX = 1/double(sizeX);
    ratioZ = 1/double(sizeZ);
    for (unsigned long long i = 0; i < numofZones; i++)
    {
        glBegin(GL_POLYGON);
        if (Zones[i].type == 'C')
            glColor3f(0,0,1);
        else
            glColor3f(1,0,0);
        glVertex3f(Zones[i].leftX*ratioX-0.5f,0,Zones[i].topZ*ratioZ-0.5f);
        glVertex3f(Zones[i].rightX*ratioX-0.5f,0,Zones[i].topZ*ratioZ-0.5f);
        glVertex3f(Zones[i].rightX*ratioX-0.5f,0,Zones[i].bottomZ*ratioZ-0.5f);
        glVertex3f(Zones[i].leftX*ratioX-0.5f,0,Zones[i].bottomZ*ratioZ-0.5f);
        glEnd();
        glLineWidth(1);
        glBegin(GL_LINE_STRIP);
        glColor3f(0,1,1);
        glVertex3f(Zones[i].leftX*ratioX-0.5f,0,Zones[i].topZ*ratioZ-0.5f);
        glVertex3f(Zones[i].rightX*ratioX-0.5f,0,Zones[i].topZ*ratioZ-0.5f);
        glVertex3f(Zones[i].rightX*ratioX-0.5f,0,Zones[i].bottomZ*ratioZ-0.5f);
        glVertex3f(Zones[i].leftX*ratioX-0.5f,0,Zones[i].bottomZ*ratioZ-0.5f);
        glEnd();
    }
}
void PhysicalMap::getSize(unsigned long long& sizex, unsigned long long& sizez)
{
    sizex = sizeX;
    sizez = sizeZ;
}

MapZone PhysicalMap::getZone(unsigned long long num)
{
    return Zones[num];
}

unsigned long long PhysicalMap::getnumofZones()
{
    return numofZones;
}

PhysicalMap::~PhysicalMap()
{
    delete[] Zones;
}
