#include "Admin.h"
#include <fstream>
#include <iostream>
#include <algorithm> // for std::remove_if

Admin::Admin(std::string uid, std::string pwd) : User(uid, pwd) {}

void Admin::displayMenu() const {
    std::cout << "Admin Menu:\n";
    std::cout << "1. Add Flight\n";
    std::cout << "2. Modify Flight\n";
    std::cout << "3. Delete Flight\n";
    std::cout << "4. Add Plane\n";
    std::cout << "5. Modify Plane\n";
    std::cout << "6. Delete Plane\n";
    std::cout << "7. Save Flights\n";
    std::cout << "8. Load Flights\n";
    std::cout << "9. Save Planes\n";
    std::cout << "10. Load Planes\n";
    std::cout << "11. Exit\n";
}

void Admin::addFlight() {
    std::string fid, pid, orig, dest, dTime, aTime;
    double price;
    std::cout << "Enter Flight ID: ";
    std::cin >> fid;
    std::cout << "Enter Plane ID: ";
    std::cin >> pid;
    std::cout << "Enter Origin: ";
    std::cin >> orig;
    std::cout << "Enter Destination: ";
    std::cin >> dest;
    std::cout << "Enter Departure Time: ";
    std::cin >> dTime;
    std::cout << "Enter Arrival Time: ";
    std::cin >> aTime;
    std::cout << "Enter Price: ";
    std::cin >> price;

    flights.emplace_back(fid, pid, orig, dest, dTime, aTime, price);
    std::cout << "Flight added successfully.\n";
    saveFlightsToFile("flights.txt"); // Save to file
}

void Admin::modifyFlight() {
    std::string fid;
    std::cout << "Enter Flight ID to modify: ";
    std::cin >> fid;
    for (auto& flight : flights) {
        if (flight.getFlightID() == fid) {
            std::string pid, orig, dest, dTime, aTime;
            double price;
            std::cout << "Enter new Plane ID: ";
            std::cin >> pid;
            std::cout << "Enter new Origin: ";
            std::cin >> orig;
            std::cout << "Enter new Destination: ";
            std::cin >> dest;
            std::cout << "Enter new Departure Time: ";
            std::cin >> dTime;
            std::cout << "Enter new Arrival Time: ";
            std::cin >> aTime;
            std::cout << "Enter new Price: ";
            std::cin >> price;

            flight.setPlaneID(pid);
            flight.setOrigin(orig);
            flight.setDestination(dest);
            flight.setDepartureTime(dTime);
            flight.setArrivalTime(aTime);
            flight.setPrice(price);

            std::cout << "Flight modified successfully.\n";
            saveFlightsToFile("flights.txt"); // Save to file
            return;
        }
    }
    std::cout << "Flight ID not found.\n";
}

void Admin::deleteFlight() {
    std::string fid;
    std::cout << "Enter Flight ID to delete: ";
    std::cin >> fid;
    auto it = std::remove_if(flights.begin(), flights.end(), [&fid](const Flight& flight) {
        return flight.getFlightID() == fid;
        });
    if (it != flights.end()) {
        flights.erase(it, flights.end());
        std::cout << "Flight deleted successfully.\n";
        saveFlightsToFile("flights.txt"); // Save to file
    }
    else {
        std::cout << "Flight ID not found.\n";
    }
}

void Admin::addPlane() {
    std::string id, type;
    int rows, seatsPerRow;
    std::cout << "Enter Plane ID: ";
    std::cin >> id;
    std::cout << "Enter Plane Type: ";
    std::cin >> type;
    std::cout << "Enter Number of Rows: ";
    std::cin >> rows;
    std::cout << "Enter Seats Per Row: ";
    std::cin >> seatsPerRow;

    planes.emplace_back(id, type, rows, seatsPerRow);
    std::cout << "Plane added successfully.\n";
    savePlanesToFile("planes.txt"); // Save to file
}

void Admin::modifyPlane() {
    std::string id;
    std::cout << "Enter Plane ID to modify: ";
    std::cin >> id;
    for (auto& plane : planes) {
        if (plane.getPlaneID() == id) {
            std::string type;
            int rows, seatsPerRow;
            std::cout << "Enter new Plane Type: ";
            std::cin >> type;
            std::cout << "Enter new Number of Rows: ";
            std::cin >> rows;
            std::cout << "Enter new Seats Per Row: ";
            std::cin >> seatsPerRow;

            plane.setPlaneType(type);
            plane.setRows(rows);
            plane.setSeatsPerRow(seatsPerRow);

            std::cout << "Plane modified successfully.\n";
            savePlanesToFile("planes.txt"); // Save to file
            return;
        }
    }
    std::cout << "Plane ID not found.\n";
}

void Admin::deletePlane() {
    std::string id;
    std::cout << "Enter Plane ID to delete: ";
    std::cin >> id;
    auto it = std::remove_if(planes.begin(), planes.end(), [&id](const Plane& plane) {
        return plane.getPlaneID() == id;
        });
    if (it != planes.end()) {
        planes.erase(it, planes.end());
        std::cout << "Plane deleted successfully.\n";
        savePlanesToFile("planes.txt"); // Save to file
    }
    else {
        std::cout << "Plane ID not found.\n";
    }
}

void Admin::saveFlightsToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& flight : flights) {
            flight.saveToFile(outFile);
        }
        outFile.close();
        std::cout << "Flights saved successfully to " << filename << "\n";
    }
    else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void Admin::loadFlightsFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        flights.clear();
        while (inFile.peek() != EOF) {
            Flight flight;
            flight.loadFromFile(inFile);
            flights.push_back(flight);
        }
        inFile.close();
        std::cout << "Flights loaded successfully from " << filename << "\n";
    }
    else {
        std::cerr << "Unable to open file for reading.\n";
    }
}

void Admin::savePlanesToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& plane : planes) {
            plane.saveToFile(outFile);
        }
        outFile.close();
        std::cout << "Planes saved successfully to " << filename << "\n";
    }
    else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void Admin::loadPlanesFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        planes.clear();
        while (inFile.peek() != EOF) {
            Plane plane;
            plane.loadFromFile(inFile);
            planes.push_back(plane);
        }
        inFile.close();
        std::cout << "Planes loaded successfully from " << filename << "\n";
    }
    else {
        std::cerr << "Unable to open file for reading.\n";
    }
}
