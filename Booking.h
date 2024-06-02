#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <fstream>

class Booking {
private:
    std::string bookingID;
    std::string flightID;
    std::string passengerName;
    std::string seatNumber;
    std::string paymentDetails;
    std::string reservationExpiryDate;

public:
    Booking(std::string bid = "", std::string fid = "", std::string pname = "", std::string sNumber = "", std::string pDetails = "", std::string rExpiry = "");
    std::string getBookingID() const;
    std::string getFlightID() const;
    std::string getPassengerName() const;
    std::string getSeatNumber() const;
    std::string getPaymentDetails() const;
    std::string getReservationExpiryDate() const;

    void setBookingID(const std::string& bid);
    void setFlightID(const std::string& fid);
    void setPassengerName(const std::string& pname);
    void setSeatNumber(const std::string& sNumber);
    void setPaymentDetails(const std::string& pDetails);
    void setReservationExpiryDate(const std::string& rExpiry);

    void saveToFile(std::ofstream& out) const;
    void loadFromFile(std::ifstream& in);
};

#endif // BOOKING_H
