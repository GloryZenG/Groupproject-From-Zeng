#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <fstream>

class Plane {
private:
    std::string planeID;
    std::string planeType;
    int rows;
    int seatsPerRow;

public:
    Plane(std::string id = "", std::string type = "", int r = 0, int spr = 0);
    std::string getPlaneID() const;
    std::string getPlaneType() const;
    int getRows() const;
    int getSeatsPerRow() const;

    void setPlaneID(const std::string &id);
    void setPlaneType(const std::string &type);
    void setRows(int r);
    void setSeatsPerRow(int spr);

    // 保存和读取的方法
    void saveToFile(std::ofstream &out) const;
    void loadFromFile(std::ifstream &in);
};

#endif // PLANE_H

