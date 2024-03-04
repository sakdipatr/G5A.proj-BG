#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <cstdlib>
using namespace std;

char random_letter(){
    return 'A' + rand()%26;
}

vector<string> setup_player(){//player setup for number of players
    int player_num;
    vector<string> player_names;
    cout << "Enter number of players: ";
    cin >> player_num;
    for (int i = 0; i < player_num; ++i) {
        string name;
        cout << "Enter name for player: " << i + 1 << ": ";
        cin >> name;
        player_names.push_back(name);
    }
    return player_names;
}

string open_question(){// only question1
    string question1;
    ifstream list1("D:\\G5A.Project\\G5A.proj-BG\\mingw-std-threads\\questions\\list1.txt");
    if(!list1){
        cerr << "Unable to open." << endl;
        return ""; // Return an empty string (failed)
    }
    if(list1.is_open()){
        while (getline(list1, question1)) {// read the question from the file
            cout << question1 << endl;
        }
    }
    return ""; // Return an empty string
}

int main(){
    int time_limit = 10; // set time to 10 seconds
    int remaining_time = time_limit;
    time_t start_time = time(NULL);

    vector<string> player_names = setup_player();

    cout << "Players: ";
    for (const auto& name : player_names) {
    cout << name << " ";
    }
    cout << endl;
    cout << "your letter is: " << random_letter() << endl;
	cout << open_question() << endl;

    while (remaining_time > 0)
    {
        time_t current_time = time(NULL);
        int elapsed_seconds = difftime(current_time, start_time);
        if (elapsed_seconds >= remaining_time)
        {
            cout << "TIME'S UP!!!" << endl;
            break;
        }
        cout << "Remaining time: " << remaining_time << " seconds." << endl;
        cout << "Enter your answer: ";
        string ans;
        cin >> ans; 
    
        remaining_time -= elapsed_seconds;
        start_time = current_time;
    }

    return 0;
}
