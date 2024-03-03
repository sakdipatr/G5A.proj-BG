#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std::chrono;
using namespace std;

ifstream qs,checkaws;
char ltt;
string ques[3] = {"1st_Q-list.txt","2nd_Q-list.txt","3rd_Q-list.txt"};
string aws1[10] = {"Capital cities.txt","Countries.txt","Land Animals.txt","Musical Instruments.txt","Flowers.txt","Perfume Brands.txt","Languages.txt","Ocean Animals.txt","Electronic Gadgets.txt","Cooking Utensils.txt"};
string aws2[10] = {"Body parts.txt","Colors.txt","Programming Languages.txt","Gemstones.txt","Disney Character Names.txt","Video Games.txt","Job titles.txt","Holidays.txt","Celebrities.txt","Indoors and Outdoor Hobbies.txt"};
string aws3[10] = {"Sports.txt","Vegetables.txt","Subjects.txt","Construction.txt","Thing in a museum.txt","Board Games.txt","Ice cream flavors.txt","Clothing Brands.txt","Fruits.txt","Car brands.txt"};
vector<string> ans_arch;
vector<string> q_ans;
vector<string> name_ply;
int r = 0;
int ch_n = 0;
int score = 0;
int n_name = 0;
int q = 0;
string tl,aws,name;

char random_letter(){
    return 'A' + rand()%26;
}

void players(){
    cout << "Number of players = ";
    cin >> ::n_name;
    for (int i = 0 ; i < n_name; i++){
        cout << "Name player " << i+1 << " = ";
        cin >> name;
        ::name_ply.push_back(name);
    }

}

void random_question(){
    ::q = rand()%3;
    for(int i = 0;i < 3;i++){
        if(i == q){
            for(int j = 0; j < 10; j++){
                ::q_ans.push_back(aws1[j]);
            }
        }
    }
}

void answer_ply(){
    qs.open("Question\\"+ques[q]);
    while(getline(qs, tl)){
        cout << tl << ' ';
        cin >> aws;
        if(r == 0) {
            ::ch_n = 0;
            break;
        }
        ::ans_arch.push_back(aws);
    }
    qs.close();
}

void check_answer(){
    for(int i = 0; i < ans_arch.size(); i++){
        checkaws.open("Answer\\"+q_ans[i]);
        cout << i+1 << ". ";
        while(getline(checkaws,tl)){
            if(tl == ans_arch[i]){
                cout << ans_arch[i] << " +1score" << " ";
                ::score++ ;
            }
        }
        checkaws.close();
    }
}

void Countdown_Timer(int seconds){
    if(ch_n == 1){
        if(seconds <= 0){
            cout << endl << endl << "Time's up !!!  T_T" << endl;
            ::r = 0;
            ::ch_n = 0;
            return;
        }
        this_thread::sleep_for(std::chrono::seconds(1));
        Countdown_Timer(seconds -1);
    }
}

int main() {
    srand(time(0));

    int st = 1;
    int bt = 0;
    int sec = 0;

    while(st == 1){

        cout << "Enter number 1 for strat : ";
        cin >> bt;
        cout << endl;

        if(bt == 1){
            players();
            cout <<  "*-----------------------*" << endl;
            ltt = random_letter();
            cout << endl << "Your letter is "<< ltt << endl;
            cout << endl << "*-----------------------*" << endl;
            cout << endl ;


            cout << "Enter time (sec) : ";
            cin >> sec;
            ::r = sec;
            cout << endl;

            for(int n = 0 ; n < n_name ; n++){
                cout << "Round "<< n+1 << " player : "<< name_ply[n] << endl;
                cout << endl;
                ::ch_n = 1;
                thread taskCD(Countdown_Timer, sec);
                cout << r << " " << "SECOND LEFT!!!!" << endl << endl;

                random_question();
                answer_ply();

                cout << endl <<"*-----------------------*" << endl;
                cout << endl ;

                check_answer();

                cout << endl << "*-----------------------*" << endl;
                cout << endl << name_ply[n]<<" score is : " << score << endl;
                cout << endl << "-----------------------------------"<< endl;

                ::ans_arch.clear();
                ::ch_n = 0;
                ::r = sec;
                score = 0;
            }
        }
    st = 0;
    }
    return 0;
}