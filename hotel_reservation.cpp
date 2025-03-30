#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Room {
public:
    int roomNumber;
    string customerName;
    bool isBooked;

    Room(int number, string name = "", bool booked = false)
        : roomNumber(number), customerName(name), isBooked(booked) {}

    void display() const {
        cout << setw(5) << roomNumber << " | "
             << setw(20) << (isBooked ? customerName : "Available") << " | "
             << (isBooked ? "Booked" : "Free") << endl;
    }

    string toString() const {
        return to_string(roomNumber) + "," + customerName + "," + (isBooked ? "1" : "0");
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "No existing data found. Starting with empty rooms.\n";
            for (int i = 1; i <= 10; ++i) {
                rooms.emplace_back(i);
            }
            return;
        }

        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            int roomNum = stoi(line.substr(0, pos1));
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            bool booked = (line.substr(pos2 + 1) == "1");

            rooms.emplace_back(roomNum, name, booked);
        }
        file.close();
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        for (const auto& room : rooms) {
            file << room.toString() << endl;
        }
        file.close();
    }

    void displayRooms() const {
        cout << "\n=== Hotel Room Status ===\n";
        cout << setw(5) << "Room" << " | " << setw(20) << "Customer" << " | Status\n";
        cout << "------------------------------------------\n";
        for (const auto& room : rooms) {
            room.display();
        }
    }

    void bookRoom(int roomNumber, const string& customerName) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number!\n";
            return;
        }

        Room& room = rooms[roomNumber - 1];

        if (room.isBooked) {
            cout << "Room already booked!\n";
        } else {
            room.isBooked = true;
            room.customerName = customerName;
            cout << "Room " << roomNumber << " booked successfully!\n";
        }
    }

    void cancelBooking(int roomNumber) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number!\n";
            return;
        }

        Room& room = rooms[roomNumber - 1];

        if (!room.isBooked) {
            cout << "Room is already free!\n";
        } else {
            room.isBooked = false;
            room.customerName = "";
            cout << "Booking for room " << roomNumber << " cancelled successfully!\n";
        }
    }
};

int main() {
    Hotel hotel;
    const string FILENAME = "hotel_data.txt";

    hotel.loadFromFile(FILENAME);

    int choice, roomNumber;
    string customerName;

    do {
        cout << "\n===== Hotel Reservation System =====\n";
        cout << "1. Display Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;

            case 2:
                cout << "Enter room number to book: ";
                cin >> roomNumber;
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, customerName);
                hotel.bookRoom(roomNumber, customerName);
                break;

            case 3:
                cout << "Enter room number to cancel booking: ";
                cin >> roomNumber;
                hotel.cancelBooking(roomNumber);
                break;

            case 4:
                cout << "Saving data and exiting...\n";
                hotel.saveToFile(FILENAME);
                break;

            default:
                cout << "Invalid option. Try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
