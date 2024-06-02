#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <iostream>
#include <vector>
#include "Flight.h"
#include "Booking.h"

class Customer : public User {
public:
    Customer(std::string uid = "", std::string pwd = "");
    void displayMenu() const override;
    void bookTicket(const std::vector<Flight>& flights, std::vector<Booking>& bookings);
    void viewFlightDetails(const std::vector<Flight>& flights) const;
};

#endif // CUSTOMER_H
