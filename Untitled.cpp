#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <conio.h>

using namespace std::chrono;
using namespace std;

ifstream qs,checkaws;
char ltt;
string ques[3] = {"1st_Q-list.txt","2nd_Q-list.txt","3rd_Q-list.txt"};
string aws1[10] = {"Capital cities.txt","Countries.txt","Land Animals.txt","Musical Instruments.txt","Flowers.txt","Perfume Brands.txt","Languages.txt","Ocean Animals.txt","Electronic Gadgets.txt","Cooking Utensils.txt"};
string aws2[10] = {"Body parts.txt","Colors.txt","Programming Languages.txt","Gemstones.txt","Disney Character Names.txt","Video Games.txt","Job titles.txt","Holidays.txt","Celebrities.txt","Indoors and Outdoor Hobbies.txt"};
string aws3[10] = {"Sports.txt","Vegetables.txt","Subjects.txt","Construction.txt","Thing in a museum.txt","Board Games.txt","Ice cream flavors.txt","Clothing Brands.txt","Fruits.txt","Car brands.txt"};
string tl,aws,name;
vector<string> ans_arch;
vector<string> q_ans;
vector<string> name_ply;
int r = 0;
int score = 0;
int n_name = 0;
int q = 0;

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
    cout << endl;
}

void answer_ply(){
    qs.open("Question\\"+ques[q]);
    while(getline(qs, tl)){
        cout << tl << ' ';
        cin >> aws;
        if(r == 0) {
            break;
        }
        ::ans_arch.push_back(aws);
    }
    qs.close();
    cout << endl;
    check_answer();
}

void Countdown_Timer(int seconds){
    if(r == 1){
        if(seconds <= 0){
            cout << endl << endl << "Time's up !!!  T_T" << endl;
            ::r = 0;
            return;
        }
        this_thread::sleep_for(std::chrono::seconds(1));
        Countdown_Timer(seconds -1);
    }
}

/*void Countdown_Timer(int seconds){
    int remaining_time = seconds;
    time_t start_time = time(NULL);
    while (remaining_time > 0){
        if(r == 1){
            time_t current_time = time(NULL);
            int elapsed_seconds = difftime(current_time, start_time);
            if (elapsed_seconds >= remaining_time)
            {
                cout << endl << "TIME'S UP!!!" << endl;
                ::r = 0;
                break;
            }
            remaining_time -= elapsed_seconds;
            start_time = current_time;
        }
    }
}*/

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
            cout << endl;

            for(int n = 0 ; n < n_name ; n++){
                ::r = 1;
                cout << "Round "<< n+1 << " player : "<< name_ply[n] << endl;
                cout << endl;

                thread task_cd(Countdown_Timer,sec);

                cout << sec << " " << "SECOND LEFT!!!!" << endl << endl;

                random_question();
                answer_ply();

                task_cd.join();

                cout << endl << "*-----------------------*" << endl;
                cout << endl << name_ply[n]<<" score is : " << score << endl;
                cout << endl << "-----------------------------------"<< endl;

                ::ans_arch.clear();
                ::r = 0;
                score = 0;
            }
        }
    st = 0;
    }
    return 0;
}
