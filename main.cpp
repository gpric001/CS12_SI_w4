#include <vector>
#include "Card.h"

using namespace std;

void fight(Card&, Card&, vector<Card>&, int);
void runTournament(vector<Card>&);

int main(int argc, char* argv[]){
    Card punk("Rough street punk carrying a baseball bat", 1000, 300, 5);
    Card princess("Dainty princess with a rocket launcher", 550, 2500, 6);
    Card mmaChampion("UFC champion Jose Aldo", 2000, 280, 10);
    Card dragon("Massive pink dragon", 5000, 1000, 1);
    
    vector<Card> contestants {punk, princess, mmaChampion, dragon};
    runTournament(contestants);
    
    return 0;
}

void fight(Card& card1, Card& card2, vector<Card>& winners, int roundNum){
    bool running = true;
    cout << "Round " << roundNum << ": " << card1.getName() << " vs. " << card2.getName() << endl;
    while(running){
        if(card1.isDead() && card2.isDead()){
            cout << "It seems both contestants have fallen! How exciting!" << endl;
            return;
        }
        if(card1.isDead() ){
            cout << card1.getName() << " seems to not be moving..." << endl;
            cout << card2.getName() << " is the winner!" << endl;
            winners.push_back(card2);
            return;
        }
        if(card2.isDead()){
            cout << "Uh oh, " << card2.getName() << " looks to be incapacitated..." << endl;
            cout << "Give " << card1.getName() << " a round of applause!" << endl;
            winners.push_back(card1);
            return;
        }
        if(card1.canAct()){
            card1.attack(card2);
            card1.resetAT();
        }
        if(card2.canAct()){
            card2.attack(card1);
            card2.resetAT();
        }
        card1.progressAT();
        card2.progressAT();
    }
}

void runTournament(std::vector<Card>& contestants){
    vector<Card> winners;
    int roundNum = 1;
    while(contestants.size() > 1){
        int contFighting = contestants.size();
        if(contestants.size() % 2 != 0){
            contFighting -= 1; 
            winners.push_back(contestants.at(contFighting));
        }
        for(int i = 0; i < contFighting; i+=2){
            fight(contestants.at(i), contestants.at(i + 1), winners, roundNum);
            roundNum += 1; 
        }
        contestants = winners;
        winners.clear();
    }
    if(contestants.size() > 0){
        cout << "The champion is " << contestants.at(0).getName() << "!" << endl;
    }
    else{
        cout << "Hmm, there is no winner..." << endl;
    }
}
