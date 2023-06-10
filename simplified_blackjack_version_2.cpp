#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937
#include <string>
using namespace std;
bool verification(int dealer_deck, int player_deck){
  bool player_flag = false;
  bool dealer_flag = false;
   if(player_deck > 21){
     cout << "Player got more than 21 and lost" << endl;
     player_deck = 0;
     return false;
   }
   if(dealer_deck > 21){
    cout << "Dealer got more than 21 and lost" << endl;
    dealer_deck = 0;
    return true;
    }
    if(player_deck > dealer_deck){
      return true;
    }else if (dealer_deck > player_deck || dealer_deck == player_deck){
      return false;
    }
}
void print_symbols(int simbol = rand()%4+1){
  switch(simbol){
    case 1:
      cout << " of clubs";
      break;
    case 2:
      cout << " of diamonds";
      break;
    case 3:
      cout << " of hearts";
      break;
    case 4:
      cout << " of spades";
      break;
  }    
}
int dealer(int dealer_deck){
    int dealer_sum;
    do{
      dealer_sum = rand()%10+1;
      cout << "The dealer took a "<< dealer_sum;
      print_symbols();
      cout << endl;
      dealer_deck += dealer_sum;
    }while(dealer_deck <= 16);
    cout << "Scorring a total of: "<< dealer_deck << endl; 
    return dealer_deck;
}
bool playblackjack(char stand_or_hits = 'E',int player_deck = 0,int dealer_deck = 0){
  int player_sum = rand()%10+1;
  bool who_won;
  player_deck += player_sum;
  cout << "You found a " << player_sum << " ";
  print_symbols();
  cout << " and a ";
  player_sum = rand()%10+1;
  cout << player_sum;
  print_symbols(); 
  cout << " with a total score of: ";
  player_deck += player_sum;
  cout << player_deck << endl;
  do{
    cout << "stand or hits?";
    cin >> stand_or_hits;
  }while(stand_or_hits != 'S' && stand_or_hits != 'H');
  if(stand_or_hits == 'S'){
    dealer_deck = dealer(dealer_deck);
    who_won = verification(dealer_deck, player_deck);
    return who_won;
  }
  else{
    do{
      player_sum = rand()%10+1;
      cout << "You found a " << player_sum;
      print_symbols(); 
      cout << " with a total of: ";
      player_deck += player_sum;
      cout << player_deck << endl;
      if(player_deck > 21){
        cout << "Player got more than 21" << endl;
        player_deck = 0;
        return false; // qua ci stava un break
      }else{
        cout << "stand or hits?";
        cin >> stand_or_hits;
      }
    }while(stand_or_hits != 'S');
    dealer_deck = dealer(dealer_deck);
    who_won = verification(dealer_deck, player_deck);
    return who_won;
  }
}
int main() {
  srand(time(NULL));
  char stand_or_hits;
  int player_deck = 0;
  int dealer_deck = 0;
  if(playblackjack(stand_or_hits, player_deck, dealer_deck)){
    cout << "Player won" << endl;
  }else{
    cout << "Dealer won" << endl;
  }
}