#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Flight.h"
#include "Plane.h"
#include <vector>

class Admin : public User {
public:
    Admin(std::string uid = "", std::string pwd = "");
    void displayMenu() const override;
    void addFlight();
    void modifyFlight();
    void deleteFlight();
    void addPlane();
    void modifyPlane();
    void deletePlane();

    void saveFlightsToFile(const std::string& filename) const;
    void loadFlightsFromFile(const std::string& filename);
    void savePlanesToFile(const std::string& filename) const;
    void loadPlanesFromFile(const std::string& filename);

private:
    std::vector<Flight> flights;
    std::vector<Plane> planes;
};

#endif // ADMIN_H
