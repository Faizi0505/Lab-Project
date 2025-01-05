#include <iostream>
#include <string>
using namespace std;

int main() {
    string username, password, programs[] = {"CS", "SE", "IT"};
    int seats[] = {3, 4, 2}, studentMarks;
    float eligibility[] = {60.0, 55.0, 50.0};
    bool continueSystem = true;

    while (continueSystem) {
        cout << "--- Admin Login ---\n";
        cout << "Username: "; cin >> username;
        cout << "Password: "; cin >> password;

        if (username == "admin" && password == "admin123") {
            cout << "Login Successful!\n";
            for (int i = 0; i < 3; i++)
                cout << i + 1 << ". " << programs[i]
                     << " Seats: " << seats[i]
                     << " Eligibility: " << eligibility[i] << "%\n";

            cout << "\nEnter Student Marks (out of 1000): ";
            cin >> studentMarks;
            float percentage = (float)studentMarks / 1000 * 100;
            string status = "Rejected";

            for (int i = 0; i < 3; i++) {
                if (percentage >= eligibility[i] && seats[i] > 0) {
                    status = "Accepted in " + programs[i];
                    seats[i]--; break;
                }
            }

            cout << "Status: " << status << "\n\n";
        } else {
            cout << "Invalid Credentials.\n";
        }

        cout << "Continue? (1=Yes, 0=No): "; cin >> continueSystem;
    }
    return 0;
}
