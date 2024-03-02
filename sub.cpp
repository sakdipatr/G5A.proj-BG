#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

char random_letter(){
    return 'A' + rand() % 26;
}

int main()
{
    int time_limit = 10; // set time limit to 10 seconds
    int remaining_time = time_limit;

    time_t start_time = time(NULL);

    while (remaining_time > 0)
    {
        //game logic

        time_t current_time = time(NULL);
        int elapsed_seconds = difftime(current_time, start_time);
        if (elapsed_seconds >= remaining_time)
        {
            cout << "Time's up!" << endl;
            break;
        }
        cout << "your letter is: " << random_letter() << endl;
        cout << "Remaining time: " << remaining_time << " seconds." << endl;
        cout << "Enter your answer: ";
        string ans;
        cin >> ans; // read answer as string
        

        remaining_time -= elapsed_seconds;
        start_time = current_time;
    }

    return 0;
}