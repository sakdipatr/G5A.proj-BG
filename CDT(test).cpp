#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
using namespace std::chrono;

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
int main(){
    
}
