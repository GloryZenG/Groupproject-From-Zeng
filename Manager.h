#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"
#include <iostream>
#include <vector>
#include "Flight.h"
#include "Booking.h"

class Manager : public User {
public:
    Manager(std::string uid = "", std::string pwd = "");
    void displayMenu() const override;
    void generateStatistics(const std::vector<Flight>& flights, const std::vector<Booking>& bookings);
    void viewTotalEarnings(const std::vector<Flight>& flights, const std::vector<Booking>& bookings) const;
};

#endif // MANAGER_H
