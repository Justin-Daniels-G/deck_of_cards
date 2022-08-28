//#include <stdafx.h>
#include <iostream> 
#include <ctime> 
#include <cstdlib> 
#include <stdlib.h> 
#include <random>

using namespace std;

class playing_card {
private:

public: 
	int number;
	int suit;
	playing_card() { number = 0; suit = 0; }
	playing_card(int n, int s) { set(n, s); }
	bool set(int n, int s) {
	 if (n > 14 || n < 2) return false; if (s > 4 || s < 1) return false; //Check for card to be valued between 2 and 14 (ace) and it is one of our 4 suits.
		  number = n; suit = s;
		  return true;
	  }
	  void show() {
		  if (number == 11) cout << "J"; else if (number == 12) cout << "Q"; else if (number == 13) cout << "K"; else if (number == 14) cout << "A"; else cout << number;
		  if (suit == 1) cout << static_cast<char>(5);
		  else if (suit == 2) cout << static_cast<char>(4); else if (suit == 3) cout << static_cast<char>(3); else if (suit == 4) cout << static_cast<char>(6);
	  }
	  bool equals(playing_card pc) { if (pc.number == number && pc.suit == suit) return true; else return false; }
};
class cardDeck {
private:

public:
	playing_card deck[52];
	  //void setCard(int ind, int num, int su); //{ // deck[ind].set(num, su); //}
	  void display() {
		  for (int i = 0; i < 52; i++) {
			  if (i % 13 == 0) cout << endl; deck[i].show(); cout << " ";
		  }
	  }
	  void setNew() { int i; for (i = 0; i < 52; i++) { int num, su; num = (i % 13) + 2; su = int(i / 13) + 1; deck[i].set(num, su); } }
	  //basic shuffle function to apply for cardDeck
	  void shuffle() {
		  for (int j = 0; j < 52; j++) {
			  playing_card temp;
			  int ind = (rand() % 52); temp = deck[ind]; deck[ind] = deck[j]; deck[j] = temp;
		  }
	  }
	  int rangeAlg(int min, int max) //This is the method java uses to return an unbiased integer in a specified range. 
	  { int n = max - min + 1; int remainder = RAND_MAX % n; int x; do { x = rand(); } while (x >= RAND_MAX - remainder); return min + x % n; }
		  void FYS() { playing_card temp; int n = 52; for (int a = n - 1; a > 0; a--) { int j = rangeAlg(1, 52); temp = deck[a]; deck[a] = deck[j]; deck[j] = temp; } }
};
int main() {
	srand(time(NULL)); //Seed random
	int royal_flush = 0; int straight_flush = 0; int pair = 0; int two_pair = 0; int high_card = 0; int three_o_kind = 0; int full_house = 0; int flush = 0; int straight = 0; int four_o_kind = 0;
	cout << "Modulo Random Shuffle - 1,000,000 iterations." << endl << endl << endl;
	for (int k = 0; k < 1000000; k++) { //We run 1,000,000 iterations for law of large numbers
		cardDeck deck1; deck1.setNew(); // deck1.display(); //cout << endl << endl;
		deck1.shuffle(); //shuffle the deck after initalizing 
		//deck1.display(); //cout << endl << endl;
		playing_card c1 = deck1.deck[0]; playing_card c2 = deck1.deck[1]; playing_card c3 = deck1.deck[2]; playing_card c4 = deck1.deck[3]; playing_card c5 = deck1.deck[4];
		bool swapped = false; do { swapped = false; for (int i = 0; i < 4; i++) { if (deck1.deck[i].number > deck1.deck[i + 1].number) { int temp_num = deck1.deck[i].number; int temp_suit = deck1.deck[i].suit; deck1.deck[i].number = deck1.deck[i + 1].number; deck1.deck[i].suit = deck1.deck[i + 1].suit; deck1.deck[i + 1].number = temp_num; deck1.deck[i + 1].suit = temp_suit; swapped = true; } } } while (swapped == true);
		c1 = deck1.deck[0]; c2 = deck1.deck[1]; c3 = deck1.deck[2]; c4 = deck1.deck[3]; c5 = deck1.deck[4];
		int hand_rank = -1; if ((c1.number == 10) && (c2.number == 11) && (c3.number == 12) && (c4.number == 13) && (c5.number == 14) && ((c1.suit == c2.suit) && (c1.suit == c3.suit) && (c1.suit == c4.suit) && (c1.suit == c5.suit))) { //royal flush
			hand_rank = 1;
		}

		else if ((c1.number == (c2.number - 1)) && (c1.number == (c3.number - 2)) && (c1.number == (c4.number - 3)) && (c1.number == (c5.number - 4)) && ((c1.suit == c2.suit) && (c1.suit == c3.suit) && (c1.suit == c4.suit) && (c1.suit == c5.suit))) { //straight flush
			hand_rank = 2; } else if ((c1.number == c2.number) && (c1.number == c3.number) && (c1.number == c4.number) || ((c2.number == c3.number) && (c2.number == c4.number) && (c2.number == c5.number))){ //four of a kind
			hand_rank = 3; } else if (((c1.number == c2.number) && (c3.number == c4.number && (c3.number == c5.number)) || ((c1.number == c2.number) && (c1.number == c3.number) && (c4.number == c5.number)))) { //full house 
			hand_rank = 4; } else if ((c1.suit == c2.suit) && (c1.suit == c3.suit) && (c1.suit == c4.suit) && (c1.suit == c5.suit)) { //flush 
			hand_rank = 5; } else if ((c1.number == (c2.number - 1)) && (c1.number == (c3.number - 2)) && (c1.number == (c4.number - 3)) && (c1.number == (c5.number - 4))) { //striaght
			hand_rank = 6; } else if (((c1.number == c2.number) && (c1.number == c3.number)) || ((c2.number == c3.number) && (c2.number == c4.number)) || ((c3.number == c4.number) && (c3.number == c5.number))) { //three of a kind 
			hand_rank = 7; } else if ((c1.number == c2.number && c3.number == c4.number) || (c1.number == c2.number && c4.number == c5.number) || (c2.number == c3.number && c4.number == c5.number)) { //two pair 
			hand_rank = 8; } else if ((c1.number == c2.number) || (c2.number == c3.number) || (c3.number == c4.number) || (c4.number == c5.number)) { //pair 
			hand_rank = 9; } else { //high card 
			hand_rank = 10; }
			//tally the hands below
				if (hand_rank == 1) { royal_flush = royal_flush + 1; }
				else if (hand_rank == 2) { straight_flush = straight_flush + 1; }
				else if (hand_rank == 3) { four_o_kind = four_o_kind + 1; }
				else if (hand_rank == 4) { full_house = full_house + 1; }
				else if (hand_rank == 5) { flush = flush + 1; }
				else if (hand_rank == 6) { straight = straight + 1; }
				else if (hand_rank == 7) { three_o_kind = three_o_kind + 1; }
				else if (hand_rank == 8) { two_pair = two_pair + 1; }
				else if (hand_rank == 9) { pair = pair + 1; }
				else if (hand_rank == 10) { high_card = high_card + 1; } }
			cout << "Royal Flushes: " << royal_flush << " ----- Probability: " << (double)(royal_flush / 1000000.0) << endl; cout << "Straight Flushes: " << straight_flush << " ----- Probability: " << (double)(straight_flush / 1000000.0) << endl; cout << "Four of a Kinds: " << four_o_kind << " ----- Probability: " << (double)(four_o_kind / 1000000.0) << endl; cout << "Full Houses: " << full_house << " ----- Probability: " << (double)(full_house / 1000000.0) << endl; cout << "Flushes: " << flush << " ----- Probability: " << (double)(flush / 1000000.0) << endl; cout << "Straights: " << straight << " ----- Probability: " << (double)(straight / 1000000.0) << endl; cout << "Three of a Kinds: " << three_o_kind << " ----- Probability: " << (double)(three_o_kind / 1000000.0) << endl; cout << "Two Pairs: " << two_pair << " ----- Probability: " << (double)(two_pair) / 1000000.0 << endl; cout << "Pairs: " << pair << " ----- Probability: " << (double)(pair / 1000000.0) << endl;
			cout << "High Cards: " << high_card << " ----- Probability: " << (double)(high_card / 1000000.0) << endl;
		}