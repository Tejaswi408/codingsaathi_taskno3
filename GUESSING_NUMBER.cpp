#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int rdm_fun() {
    mt19937 num(time(0));
    int min = 1;
    int max = 3;
    uniform_int_distribution<int> distribution(min, max);
    int random_number = distribution(num);
    return random_number;
}

int main() {
    int attempts = 0, attempt = 0;
    int input, points = 0;
    string opt;
    cout << "Guess a number between 1 to 100: ";

    do {
        cin >> input;
        //cin.ignore();
        if (rdm_fun() == input) {
            attempt++;
            points++;
            cout << "Yes, you won..!" << endl;
            cout << "You have earned " << points << " points, for " << attempt << " attempts" << endl;
            attempts = 0;
            if (points % 5 == 0) {
                cout << "Keep going. That's great to score " << points << " points" << endl;
                continue;
            }
            cout << "Do you want to try again? (Y/N) ";
            cin >> opt;
            if (opt == "no" || opt == "N" || opt == "NO" || opt == "n") {
                cout << "Your score: " << points << endl;
                cout << "THANKYOU. Have a great day ahead..!" << endl;
                break;
            } else {
                continue;
            }
        } else {
            attempt++;
            attempts++;
            cout << "Try again" << endl;

            if (attempts % 5 == 0) {
                cout << "Do you want to quit the game? (Q/N)";
                cin >> opt;
                if (opt == "Q" || opt == "q") {
                    cout << "Your score: " << points << endl;
                    cout << "THANKYOU. Have a great day ahead..!" << endl;
                    break;
                }
            }
        }
    } while (0 < input && input < 101);

    return 0;
}

