#include "Booking.h"
#include <iostream>

Booking::Booking(std::string bid, std::string fid, std::string pname, std::string sNumber, std::string pDetails, std::string rExpiry)
    : bookingID(bid), flightID(fid), passengerName(pname), seatNumber(sNumber), paymentDetails(pDetails), reservationExpiryDate(rExpiry) {}

std::string Booking::getBookingID() const {
    return bookingID;
}

std::string Booking::getFlightID() const {
    return flightID;
}

std::string Booking::getPassengerName() const {
    return passengerName;
}

std::string Booking::getSeatNumber() const {
    return seatNumber;
}

std::string Booking::getPaymentDetails() const {
    return paymentDetails;
}

std::string Booking::getReservationExpiryDate() const {
    return reservationExpiryDate;
}

void Booking::setBookingID(const std::string& bid) {
    bookingID = bid;
}

void Booking::setFlightID(const std::string& fid) {
    flightID = fid;
}

void Booking::setPassengerName(const std::string& pname) {
    passengerName = pname;
}

void Booking::setSeatNumber(const std::string& sNumber) {
    seatNumber = sNumber;
}

void Booking::setPaymentDetails(const std::string& pDetails) {
    paymentDetails = pDetails;
}

void Booking::setReservationExpiryDate(const std::string& rExpiry) {
    reservationExpiryDate = rExpiry;
}

void Booking::saveToFile(std::ofstream& out) const {
    out << bookingID << std::endl;
    out << flightID << std::endl;
    out << passengerName << std::endl;
    out << seatNumber << std::endl;
    out << paymentDetails << std::endl;
    out << reservationExpiryDate << std::endl;
}

void Booking::loadFromFile(std::ifstream& in) {
    std::getline(in, bookingID);
    std::getline(in, flightID);
    std::getline(in, passengerName);
    std::getline(in, seatNumber);
    std::getline(in, paymentDetails);
    std::getline(in, reservationExpiryDate);
}
