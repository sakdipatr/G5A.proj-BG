#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std::chrono;

std::string text[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
std::string ques[3] = {"1st_Q-list.txt","2nd_Q-list.txt","3rd_Q-list.txt"};
std::string aws1[10] = {"Capital cities.txt","Countries.txt","Land Animals.txt","Musical Instruments.txt","Flowers.txt","Perfume Brands.txt","Languages.txt","Ocean Animals.txt","Electronic Gadgets.txt","Cooking Utensils.txt"};
std::string aws2[10] = {"Body parts.txt","Colors.txt","Programming Languages.txt","Gemstones.txt","Disney Character Names.txt","Video Games.txt","Job titles.txt","Holidays.txt","Celebrities.txt","Indoors and Outdoor Hobbies.txt"};
std::string aws3[10] = {"Sports.txt","Vegetables.txt","Subjects.txt","Construction.txt","Thing in a museum.txt","Board Games.txt","Ice cream flavors.txt","Clothing Brands.txt","Fruits.txt","Car brands.txt"};

int main() {
    srand(time(0));

    std::ifstream qs,checkaws;
    std::ofstream dest;
    std::string tl,aws,name;
    std::vector<std::string> ans_arch;
    std::vector<std::string> q_ans;
    std::vector<std::string> name_ply;
    int st = 1;
    int bt = 0;
    int sec = 0;
    int score = 0;
    int n_name = 0;
    

    while(st == 1){

        std::cout << "pls Enter number 1 : ";
        std::cin >> bt;
        std::cout << "-----------------------------------"<< std::endl;

        if(bt == 1){
            std::cout << "player = ";
            std::cin >> n_name;
            for (int i = 0 ; i < n_name; i++){
                std::cout << "name player " << i+1 << " = ";
                std::cin >> name;
                name_ply.push_back(name);
            }
            int x = rand()%26;
            std::cout <<  "*-----------------------*" << std::endl;
            std::cout << std::endl << "your letter is "<< text[x] << std::endl;
            std::cout << std::endl << "*-----------------------*" << std::endl;
            std::cout << std::endl ;

            std::cout << "Enter time (sec) : ";
            std::cin >> sec;
            std::cout << std::endl << "*-----------------------*" << std::endl;

            // cd timer
            for(int n = 0 ; n < n_name ; n++){
                std::cout << "round "<< n+1 << " player : "<< name_ply[n] << std::endl;
                std::cout << std::endl;

                int q = rand()%3;
                if( q == 0 ){
                    for(int i = 0; i < 10; i++ ){
                        q_ans.push_back(aws1[i]);
                    }
                }else if( q == 1 ){
                    for(int i = 0; i < 10; i++ ){
                        q_ans.push_back(aws2[i]);
                    }
                }else if( q == 2 ){
                    for(int i = 0; i < 10; i++ ){
                        q_ans.push_back(aws3[i]);
                    }
                }

                qs.open("Question\\"+ques[q]);
                
                //พิมพ์คำตอบ
                while(getline(qs, tl)){
                    std::cout << tl << ' ';
                    std::cin >> aws;
                    ans_arch.push_back(aws);
                }

                qs.close();

                std::cout << std::endl <<"*-----------------------*" << std::endl;
                std::cout << std::endl ;

                //เช็คคะแนน
                for(int i = 0; i < 10; i++){
                    checkaws.open("Answer\\"+q_ans[i]);
                    std::cout << i+1 << ". ";
                    while(getline(checkaws,tl)){
                        if(tl == ans_arch[i]){
                            std::cout << ans_arch[i] << " +1score" << " ";
                            score++ ;
                        }
                    }
                    checkaws.close();
                }

                std::cout << std::endl << "*-----------------------*" << std::endl;
                std::cout << std::endl << name_ply[n]<<" score is : " << score << std::endl;
                std::cout << std::endl << "-----------------------------------"<< std::endl;

                st = 0;
            }
        }
    }
    return 0;
}