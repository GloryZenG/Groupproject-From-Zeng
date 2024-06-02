#include "Plane.h"

// ���캯��
Plane::Plane(std::string id, std::string type, int r, int spr)
    : planeID(id), planeType(type), rows(r), seatsPerRow(spr) {}

// ��ȡ���Եķ���
std::string Plane::getPlaneID() const {
    return planeID;
}

std::string Plane::getPlaneType() const {
    return planeType;
}

int Plane::getRows() const {
    return rows;
}

int Plane::getSeatsPerRow() const {
    return seatsPerRow;
}

// �������Եķ���
void Plane::setPlaneID(const std::string &id) {
    planeID = id;
}

void Plane::setPlaneType(const std::string &type) {
    planeType = type;
}

void Plane::setRows(int r) {
    rows = r;
}

void Plane::setSeatsPerRow(int spr) {
    seatsPerRow = spr;
}

// ����Plane�����ļ�
void Plane::saveToFile(std::ofstream &out) const {
    out << planeID << std::endl;
    out << planeType << std::endl;
    out << rows << std::endl;
    out << seatsPerRow << std::endl;
}

// ���ļ���ȡPlane����
void Plane::loadFromFile(std::ifstream &in) {
    std::getline(in, planeID);
    std::getline(in, planeType);
    in >> rows;
    in >> seatsPerRow;
    in.ignore(); // ���Ի��з�
}
