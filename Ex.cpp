#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

string text[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
string aws1[10] = {"Capital cities.txt","Countries.txt","Land Animals.txt","Musical Instruments.txt","Flowers.txt","Perfume Brands.txt","Languages.txt","Ocean Animals.txt","Electronic Gadgets.txt","Cooking Utensils.txt"};

void Countdown_Timer(int seconds){
    if(seconds <= 0){
        cout << "Time's up." << endl;
        return;
    }
    if(seconds==10){
        cout << seconds << "SECOND LEFT!!!!" << endl;
    }
    this_thread::sleep_for(std::chrono::seconds(1));
    Countdown_Timer(seconds-1);
}

int main() {
    srand(time(0));

    ifstream qs,checkaws,;
    ofstream dest;
    string tl,aws,;
    string ans_arch[];
    int st = 1;
    int bt = 0;
    int sec = 0;
    int score = 0;

    while(st == 1){
        qs.open("Question\\1st_Q-list.txt");
        dest.open("Answer_now.txt");

        cout << "pls Enter number 1 : ";
        cin >> bt;
        cout << "-----------------------------------"<< endl;

        if(bt == 1){
            int x = rand()%26;
            cout <<  "*-----------------------*" << endl;
            cout << endl << "your letter is "<< text[x] << endl;
            cout << endl << "*-----------------------*" << endl;
            cout << endl ;
        }

        cout << "Enter time (sec) : ";
        cin >> sec;
        Countdown_Timer(sec);

        while(getline(qs, tl)){
            cout << tl << ' ';
            cin >> aws;
            dest << aws << endl;
        }

        qs.close();
        dest.close();

        cout << endl <<"*-----------------------*" << endl;
        cout << endl ;

        qs.open("Answer_now.cpp");
        while(getline(qs,tl)){
            ans_arch = tl;
        }
        qs.close();

        for(int i = 0; i < 10 ; i++){
            checkaws.open("Answer\\"+aws1[i]);
            cout << i+1 << ". ";
            for(int j = 0; j < ans_arch.size();j++){
                while(getline(checkaws,tl)){
                    if(tl == ans_arch[j]){
                        cout << tl_now << " +1score" << " ";
                        score++ ;
                    }
                }
            }
            checkaws.close();
        }

        cout << endl << "*-----------------------*" << endl;
        cout << endl <<"your score is : " << score << endl;

        cout << endl << "-----------------------------------"<< endl;

        //-------------------------------------------------------------------
        st = 0;
    }
    return 0;
}
