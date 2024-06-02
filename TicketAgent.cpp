#include "TicketAgent.h"
#include <iostream>
#include <fstream>

TicketAgent::TicketAgent(std::string uid, std::string pwd) : User(uid, pwd) {}

void TicketAgent::displayMenu() const {
    std::cout << "Ticket Agent Menu:\n";
    std::cout << "1. Search Flight\n";
    std::cout << "2. Book Ticket\n";
    std::cout << "3. Save Bookings\n";
    std::cout << "4. Load Bookings\n";
    std::cout << "5. Exit\n";
}

void TicketAgent::searchFlight(const std::vector<Flight>& flights) const {
    std::string origin, destination;
    std::cout << "Enter Origin: ";
    std::cin >> origin;
    std::cout << "Enter Destination: ";
    std::cin >> destination;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getOrigin() == origin && flight.getDestination() == destination) {
            std::cout << "Flight ID: " << flight.getFlightID() << "\n";
            std::cout << "Plane ID: " << flight.getPlaneID() << "\n";
            std::cout << "Departure Time: " << flight.getDepartureTime() << "\n";
            std::cout << "Arrival Time: " << flight.getArrivalTime() << "\n";
            std::cout << "Price: " << flight.getPrice() << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No flights found from " << origin << " to " << destination << ".\n";
    }
}

void TicketAgent::bookTicket(std::vector<Booking>& bookings, const std::vector<Flight>& flights) {
    std::string bookingID, flightID, passengerName, seatNumber, paymentDetails, reservationExpiryDate;
    std::cout << "Enter Booking ID: ";
    std::cin >> bookingID;
    std::cout << "Enter Flight ID: ";
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

    Booking newBooking(bookingID, flightID, passengerName, seatNumber, paymentDetails, reservationExpiryDate);
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

void TicketAgent::saveBookingsToFile(const std::string& filename, const std::vector<Booking>& bookings) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& booking : bookings) {
            booking.saveToFile(outFile);
        }
        outFile.close();
        std::cout << "Bookings saved successfully to " << filename << "\n";
    }
    else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void TicketAgent::loadBookingsFromFile(const std::string& filename, std::vector<Booking>& bookings) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        bookings.clear();
        while (inFile.peek() != EOF) {
            Booking booking;
            booking.loadFromFile(inFile);
            bookings.push_back(booking);
        }
        inFile.close();
        std::cout << "Bookings loaded successfully from " << filename << "\n";
    }
    else {
        std::cerr << "Unable to open file for reading.\n";
    }
}
