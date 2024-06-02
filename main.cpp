#include <iostream>
#include <fstream>
#include <vector>
#include "Admin.h"
#include "TicketAgent.h"
#include "Manager.h"
#include "Customer.h"
#include "Plane.h"
#include "Flight.h"
#include "Booking.h"

void adminMenu(Admin& admin);
void agentMenu(TicketAgent& agent, std::vector<Flight>& flights, std::vector<Booking>& bookings);
void managerMenu(Manager& manager, const std::vector<Flight>& flights, const std::vector<Booking>& bookings);
void customerMenu(Customer& customer, std::vector<Flight>& flights, std::vector<Booking>& bookings);

void loadInitialData(Admin& admin, std::vector<Flight>& flights, std::vector<Plane>& planes, std::vector<Booking>& bookings) {
    admin.loadFlightsFromFile("flights.txt");
    admin.loadPlanesFromFile("planes.txt");

    std::ifstream inFile("flights.txt");
    if (inFile.is_open()) {
        while (inFile.peek() != EOF) {
            Flight flight;
            flight.loadFromFile(inFile);
            flights.push_back(flight);
        }
        inFile.close();
    }

    inFile.open("planes.txt");
    if (inFile.is_open()) {
        while (inFile.peek() != EOF) {
            Plane plane;
            plane.loadFromFile(inFile);
            planes.push_back(plane);
        }
        inFile.close();
    }

    std::ifstream bookingsFile("bookings.txt");
    if (bookingsFile.is_open()) {
        while (bookingsFile.peek() != EOF) {
            Booking booking;
            booking.loadFromFile(bookingsFile);
            bookings.push_back(booking);
        }
        bookingsFile.close();
    }
}

int main() {
    Admin admin("admin", "admin123");
    TicketAgent agent("agent", "agent123");
    Manager manager("manager", "manager123");
    Customer customer("customer", "customer123");

    std::vector<Flight> flights;
    std::vector<Plane> planes;
    std::vector<Booking> bookings;

    loadInitialData(admin, flights, planes, bookings);

    int choice;
    do {
        std::cout << "Select User Role:\n";
        std::cout << "1. Admin\n";
        std::cout << "2. Ticket Agent\n";
        std::cout << "3. Manager\n";
        std::cout << "4. Customer\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            adminMenu(admin);
            break;
        case 2:
            agentMenu(agent, flights, bookings);
            break;
        case 3:
            managerMenu(manager, flights, bookings);
            break;
        case 4:
            customerMenu(customer, flights, bookings);
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void adminMenu(Admin& admin) {
    int choice;
    do {
        admin.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            admin.addFlight();
            break;
        case 2:
            admin.modifyFlight();
            break;
        case 3:
            admin.deleteFlight();
            break;
        case 4:
            admin.addPlane();
            break;
        case 5:
            admin.modifyPlane();
            break;
        case 6:
            admin.deletePlane();
            break;
        case 7:
            admin.saveFlightsToFile("flights.txt");
            break;
        case 8:
            admin.loadFlightsFromFile("flights.txt");
            break;
        case 9:
            admin.savePlanesToFile("planes.txt");
            break;
        case 10:
            admin.loadPlanesFromFile("planes.txt");
            break;
        case 11:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);
}

void agentMenu(TicketAgent& agent, std::vector<Flight>& flights, std::vector<Booking>& bookings) {
    int choice;
    do {
        agent.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            agent.searchFlight(flights);
            break;
        case 2:
            agent.bookTicket(bookings, flights);
            break;
        case 3:
            agent.saveBookingsToFile("bookings.txt", bookings);
            break;
        case 4:
            agent.loadBookingsFromFile("bookings.txt", bookings);
            break;
        case 5:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void managerMenu(Manager& manager, const std::vector<Flight>& flights, const std::vector<Booking>& bookings) {
    int choice;
    do {
        manager.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.generateStatistics(flights, bookings);
            break;
        case 2:
            manager.viewTotalEarnings(flights, bookings);
            break;
        case 3:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

void customerMenu(Customer& customer, std::vector<Flight>& flights, std::vector<Booking>& bookings) {
    int choice;
    do {
        customer.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            customer.bookTicket(flights, bookings);
            break;
        case 2:
            customer.viewFlightDetails(flights);
            break;
        case 3:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}







