#ifndef TICKETAGENT_H
#define TICKETAGENT_H

#include "User.h"
#include "Flight.h"
#include "Booking.h"
#include <vector>

class TicketAgent : public User {
public:
    TicketAgent(std::string uid = "", std::string pwd = "");
    void displayMenu() const override;
    void searchFlight(const std::vector<Flight>& flights) const;
    void bookTicket(std::vector<Booking>& bookings, const std::vector<Flight>& flights);

    void saveBookingsToFile(const std::string& filename, const std::vector<Booking>& bookings) const;
    void loadBookingsFromFile(const std::string& filename, std::vector<Booking>& bookings);
};

#endif // TICKETAGENT_H
