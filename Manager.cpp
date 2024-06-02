#include "Manager.h"
#include <iostream>
#include <map>
#include <vector>
#include "Flight.h"
#include "Booking.h"

Manager::Manager(std::string uid, std::string pwd) : User(uid, pwd) {}

void Manager::displayMenu() const {
    std::cout << "Manager Menu:\n";
    std::cout << "1. Generate Statistics\n";
    std::cout << "2. View Total Earnings\n";
    std::cout << "3. Exit\n";
}

void Manager::generateStatistics(const std::vector<Flight>& flights, const std::vector<Booking>& bookings) {
    std::cout << "Generating statistics...\n";
    std::cout << "Total Flights: " << flights.size() << "\n";
    std::cout << "Total Bookings: " << bookings.size() << "\n";

    double totalRevenue = 0;
    for (const auto& booking : bookings) {
        for (const auto& flight : flights) {
            if (flight.getFlightID() == booking.getFlightID()) {
                totalRevenue += flight.getPrice();
                break;
            }
        }
    }
    std::cout << "Total Revenue: $" << totalRevenue << "\n";

    std::cout << "Total Planes: " << flights.size() << "\n";

    std::map<std::string, int> passengerCount; // Use std::map to count passengers
    for (const auto& booking : bookings) {
        passengerCount[booking.getFlightID()]++;
    }

    for (const auto& flight : flights) {
        std::cout << "Flight ID: " << flight.getFlightID() << ", Price: $" << flight.getPrice() << ", Passengers: " << passengerCount[flight.getFlightID()] << "\n";
    }
}

void Manager::viewTotalEarnings(const std::vector<Flight>& flights, const std::vector<Booking>& bookings) const {
    double totalEarnings = 0;
    for (const auto& booking : bookings) {
        for (const auto& flight : flights) {
            if (flight.getFlightID() == booking.getFlightID()) {
                totalEarnings += flight.getPrice();
                break;
            }
        }
    }
    std::cout << "Total Earnings: $" << totalEarnings << "\n";
}
