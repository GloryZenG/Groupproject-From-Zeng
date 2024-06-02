#include "Customer.h"
#include <iostream>
#include <fstream>

Customer::Customer(std::string uid, std::string pwd) : User(uid, pwd) {}

void Customer::displayMenu() const {
    std::cout << "Customer Menu:\n";
    std::cout << "1. Book Ticket\n";
    std::cout << "2. View Flight Details\n";
    std::cout << "3. Exit\n";
}

void Customer::bookTicket(const std::vector<Flight>& flights, std::vector<Booking>& bookings) {
    std::string flightID, passengerName, seatNumber, paymentDetails, reservationExpiryDate;
    std::cout << "Enter Flight ID (F00X) : ";
    std::cin >> flightID;

    bool flightExists = false;
    for (const auto& flight : flights) {
        if (flight.getFlightID() == flightID) {
            flightExists = true;
            break;
        }
    }

    if (!flightExists) {
        std::cout << "Flight ID not found.\n";
        return;
    }

    std::cout << "Enter Passenger Name: ";
    std::cin >> passengerName;
    std::cout << "Enter Seat Number: ";
    std::cin >> seatNumber;
    std::cout << "Enter Payment Details: ";
    std::cin >> paymentDetails;
    std::cout << "Enter Reservation Expiry Date: ";
    std::cin >> reservationExpiryDate;

    Booking newBooking("B" + std::to_string(bookings.size() + 1), flightID, passengerName, seatNumber, paymentDetails, reservationExpiryDate);
    bookings.push_back(newBooking);

    // Write the new booking to bookings.txt
    std::ofstream outFile("bookings.txt", std::ios::app); // Open file in append mode
    if (outFile.is_open()) {
        newBooking.saveToFile(outFile);
        outFile.close();
        std::cout << "Ticket booked and saved successfully.\n";
    }
    else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void Customer::viewFlightDetails(const std::vector<Flight>& flights) const {
    for (const auto& flight : flights) {
        std::cout << "Flight ID: " << flight.getFlightID() << "\n";
        std::cout << "Plane ID: " << flight.getPlaneID() << "\n";
        std::cout << "Origin: " << flight.getOrigin() << "\n";
        std::cout << "Destination: " << flight.getDestination() << "\n";
        std::cout << "Departure Time: " << flight.getDepartureTime() << "\n";
        std::cout << "Arrival Time: " << flight.getArrivalTime() << "\n";
        std::cout << "Price: " << flight.getPrice() << "\n";
        std::cout << "------------------------\n";
    }
}
