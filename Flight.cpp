#include "Flight.h"
#include <iostream>

// 
Flight::Flight(std::string fid, std::string pid, std::string orig, std::string dest, std::string dTime, std::string aTime, double p)
    : flightID(fid), planeID(pid), origin(orig), destination(dest), departureTime(dTime), arrivalTime(aTime), price(p) {}

// 
std::string Flight::getFlightID() const {
    return flightID;
}

std::string Flight::getPlaneID() const {
    return planeID;
}

std::string Flight::getOrigin() const {
    return origin;
}

std::string Flight::getDestination() const {
    return destination;
}

std::string Flight::getDepartureTime() const {
    return departureTime;
}

std::string Flight::getArrivalTime() const {
    return arrivalTime;
}

double Flight::getPrice() const {
    return price;
}

// 
void Flight::setFlightID(const std::string &fid) {
    flightID = fid;
}

void Flight::setPlaneID(const std::string &pid) {
    planeID = pid;
}

void Flight::setOrigin(const std::string &orig) {
    origin = orig;
}

void Flight::setDestination(const std::string &dest) {
    destination = dest;
}

void Flight::setDepartureTime(const std::string &dTime) {
    departureTime = dTime;
}

void Flight::setArrivalTime(const std::string &aTime) {
    arrivalTime = aTime;
}

void Flight::setPrice(double p) {
    price = p;
}

// 
void Flight::saveToFile(std::ofstream &out) const {
    out << flightID << std::endl;
    out << planeID << std::endl;
    out << origin << std::endl;
    out << destination << std::endl;
    out << departureTime << std::endl;
    out << arrivalTime << std::endl;
    out << price << std::endl;
}

// 
void Flight::loadFromFile(std::ifstream &in) {
    std::getline(in, flightID);
    std::getline(in, planeID);
    std::getline(in, origin);
    std::getline(in, destination);
    std::getline(in, departureTime);
    std::getline(in, arrivalTime);
    in >> price;
    in.ignore(); 
}
