#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <fstream>

class Flight {
private:
    std::string flightID;
    std::string planeID;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    double price;

public:
    Flight(std::string fid = "", std::string pid = "", std::string orig = "", std::string dest = "", std::string dTime = "", std::string aTime = "", double p = 0.0);
    std::string getFlightID() const;
    std::string getPlaneID() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    double getPrice() const;

    void setFlightID(const std::string &fid);
    void setPlaneID(const std::string &pid);
    void setOrigin(const std::string &orig);
    void setDestination(const std::string &dest);
    void setDepartureTime(const std::string &dTime);
    void setArrivalTime(const std::string &aTime);
    void setPrice(double p);

    // 保存和读取的方法
    void saveToFile(std::ofstream &out) const;
    void loadFromFile(std::ifstream &in);
};

#endif // FLIGHT_H

