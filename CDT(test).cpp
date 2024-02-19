#include<iostream>
#include<chrono>//ตัวจัดการเวลา
#include<thread>//ตัวจัดการเธรด
using namespace std;
using namespace std::chrono;

void Countdown_Timer(int seconds){
    if(seconds <= 0){
        cout << "Time's up." << endl;
        return;
    }
    if(seconds==0){
        cout << seconds << "SECOND LEFT!!!!" << endl;
    }
    this_thread::sleep_for(std::chrono::seconds(1));//หยุดการทำงานเธรด 1 วิ
    Countdown_Timer(seconds-1);//recursion
}