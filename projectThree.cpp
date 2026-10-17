/*
*
*
*
12/3/2024
*
*
*
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

string card(int);
void shuffle(int[], int);
void deal(int[], int[]);
void sort(int[]);
int analyzeHand(int[]);

int main()
{
	
	int seedValue, straightFlush = 0, fourOfAKind = 0, fullHouse = 0, flush = 0, straight = 0, threeOfAKind = 0, twoPair = 0, onePair = 0, highCard = 0;
	double numOfHands, straightFlushAmnt = 0, fourOfAKindAmnt = 0, fullHouseAmnt = 0, flushAmnt = 0, straightAmnt = 0, threeOfAKindAmnt = 0, twoPairAmnt = 0, onePairAmnt = 0, highCardAmnt = 0;
	int hand[5] = { };
	int deck[52] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 11, 12,
				     13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
				     26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
				     39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };

	cout << "Enter the seed value : ";
	cin >> seedValue;
	srand(seedValue);

	// Displays 5 sorted hands using the shuffle, deal, sort, and card functions
	for (int i = 0; i < 5; i++) {

		shuffle(deck, 676);
		deal(deck, hand);
		sort(hand);
		for (int i = 0; i < 5; i++) {
			cout << setw(4) << card(hand[i]);
		}
		cout << endl;
	}
	
	// Gets the number of hands from the user, and makes sure it's above 0. Making it 0 if it's not.
	cout << "Enter the number of hands : ";
	cin >> numOfHands;
	if (numOfHands < 0) { numOfHands = 0; }

	// Gets a shuffled hand the specified number of times. Then determines what type of poker hand it is and adds it to the counter.
	for (int i = 0; i < numOfHands; i++) {

		shuffle(deck, 676);
		deal(deck, hand);
		sort(hand);
		int handRanking = analyzeHand(hand);
		
		if (handRanking == 1) { straightFlush++; }
		else if (handRanking == 2) { fourOfAKind++; }
		else if (handRanking == 3) { fullHouse++; }
		else if (handRanking == 4) { flush++; }
		else if (handRanking == 5) { straight++; }
		else if (handRanking == 6) { threeOfAKind++; }
		else if (handRanking == 7) { twoPair++; }
		else if (handRanking == 8) { onePair++; }
		else if (handRanking == 9) { highCard++; }
	}

	// Runs calculations for percentages if number of hands is not negative or zero.

	if (numOfHands != 0) {

		straightFlushAmnt = straightFlush / numOfHands;
		fourOfAKindAmnt = fourOfAKind / numOfHands;
		fullHouseAmnt = fullHouse / numOfHands;
		flushAmnt = flush / numOfHands;
		straightAmnt = straight / numOfHands;
		threeOfAKindAmnt = threeOfAKind / numOfHands;
		twoPairAmnt = twoPair / numOfHands;
		onePairAmnt = onePair / numOfHands;
		highCardAmnt = highCard / numOfHands;
	}

	// Displays the results from the amount of requested hands in a chart.
	cout << fixed << setprecision(5);
	cout << "Straight Flush" << setw(11) << straightFlushAmnt * 100 << "%" << setw(10) << straightFlush << endl;
	cout << "Four of a Kind" << setw(11) << fourOfAKindAmnt * 100 << "%" << setw(10) << fourOfAKind << endl;
	cout << "Full House    " << setw(11) << fullHouseAmnt * 100 << "%" << setw(10) << fullHouse << endl;
	cout << "Flush         " << setw(11) << flushAmnt * 100 << "%" << setw(10) << flush << endl;
	cout << "Straight      " << setw(11) << straightAmnt * 100 << "%" << setw(10) << straight << endl;
	cout << "Three of a Kind" << setw(10) << threeOfAKindAmnt * 100 << "%" << setw(10) << threeOfAKind << endl;
	cout << "Two Pair      " << setw(11) << twoPairAmnt * 100 << "%" << setw(10) << twoPair << endl;
	cout << "One Pair      " << setw(11) << onePairAmnt * 100 << "%" << setw(10) << onePair << endl;
	cout << "High Card     " << setw(11) << highCardAmnt * 100 << "%" << setw(10) << highCard << endl;

	/**************DEBUG STUFF BELOW IGNORE****************

	int input;
	while (cin >> input) {
		cout << card(input) << endl;
	}

	
	for (int i = 0; i < 51; i++) {
		cout << deck[i] << "\t";
	}
	cout << endl << endl;

	shuffle(deck, 676);
	for (int i = 0; i < 51; i++) {
		cout << deck[i] << "\t";
	}
	cout << endl << endl;
	
	*****************************************************/
}

// Gets the rank and suit of a specified card in the array and returns it.
string card(int cardNum) {

	string theCard;
	int rank = cardNum / 4 + 1;
	int suit = cardNum % 4;

	if (rank == 1) { theCard += "A"; }
	else if (rank == 2) { theCard += "2"; }
	else if (rank == 3) { theCard += "3"; }
	else if (rank == 4) { theCard += "4"; }
	else if (rank == 5) { theCard += "5"; }
	else if (rank == 6) { theCard += "6"; }
	else if (rank == 7) { theCard += "7"; }
	else if (rank == 8) { theCard += "8"; }
	else if (rank == 9) { theCard += "9"; }
	else if (rank == 10) { theCard += "10"; }
	else if (rank == 11) { theCard += "J"; }
	else if (rank == 12) { theCard += "Q"; }
	else if (rank == 13) { theCard += "K"; }

	if (suit == 0) { theCard += "S"; }
	else if (suit == 1) { theCard += "H"; }
	else if (suit == 2) { theCard += "D"; }
	else if (suit == 3) { theCard += "C"; }

	return theCard;

}

// Gets 2 random positions from the deck array and swaps the values of them. Doing it as many times as requested in the argument (676).
void shuffle(int deck[], int numOfShuffles) {

	for (int i = 0; i < numOfShuffles; i++) {

		int posOne, posTwo, temp;

		posOne = rand() % 52;
		posTwo = rand() % 52;
		temp = deck[posOne];
		deck[posOne] = deck[posTwo];
		deck[posTwo] = temp;
	}
}

// Takes the first 5 elements of the deck array and stores them in the hand array
void deal(int deck[], int hand[]) {

	for (int i = 0; i < 5; i++) {
		hand[i] = deck[i];
	}
}

// Sorts the hand array using bubble sort (using the example shown in class).
void sort(int hand[]) {

	bool swap = true;
	while (swap == true) {

		swap = false;
		for (int i = 1; i < 5; i++) {
			if (hand[i - 1] > hand[i]) {

				int temp = hand[i - 1];
				hand[i - 1] = hand[i];
				hand[i] = temp;
				swap = true;
			}
		}
	}
}

// Checks to see what type of poker hand the hand array currently has. Returning an int based on which one.
int analyzeHand(int hand[]) {

	// Default high card if everything else fails
	int handRank = 9;

	// Straight Flush
	if ((hand[0] + 4 == hand[1]) && (hand[1] + 4 == hand[2]) && (hand[2] + 4 == hand[3]) && (hand[3] + 4 == hand[4])) { handRank = 1; }
	// Four of a Kind
	else if ( ((hand[0] / 4 + 1 == hand[1] / 4 + 1) && (hand[1] / 4 + 1 == hand[2] / 4 + 1) && (hand[2] / 4 + 1 == hand[3] / 4 + 1)) ||
		      ((hand[1] / 4 + 1 == hand[2] / 4 + 1) && (hand[2] / 4 + 1 == hand[3] / 4 + 1) && (hand[3] / 4 + 1 == hand[4] / 4 + 1))    ) { handRank = 2; }
	// Full House
	else if ( (((hand[0] / 4 + 1 == hand[1] / 4 + 1) && (hand[1] / 4 + 1 == hand[2] / 4 + 1)) && (hand[3] / 4 + 1 == hand[4] / 4 + 1)) ||
			  (((hand[0] / 4 + 1 == hand[1] / 4 + 1) && ((hand[2] / 4 + 1 == hand[3] / 4 + 1) && (hand[3] / 4 + 1 == hand[4] / 4 + 1))))  ) { handRank = 3; }
	// Flush
	else if ((hand[0] % 4 == hand[1] % 4) && (hand[1] % 4 == hand[2] % 4) && (hand[2] % 4 == hand[3] % 4) && (hand[3] % 4 == hand[4] % 4)) { handRank = 4; }
	// Straight
	else if (((hand[0] / 4 == hand[1] / 4 - 1) && (hand[1] / 4 == hand[2] / 4 - 1)) && ((hand[2] / 4 == hand[3] / 4 - 1) && (hand[3] / 4 == hand[4] / 4 - 1))) { handRank = 5; }
	// Three of a Kind
	else if (((hand[0] / 4 == hand[1] / 4) && (hand[1] / 4 == hand[2] / 4)) || ((hand[1] / 4 == hand[2] / 4) && (hand[2] / 4 == hand[3] / 4)) ||
		     ((hand[2] / 4 == hand[3] / 4) && (hand[3] / 4 == hand[4] / 4)) ) { handRank = 6; }
	// Two Pair
	else if ( ((hand[0] / 4 == hand[1] / 4) && ((hand[2] / 4 == hand[3] / 4) || (hand[3] / 4 == hand[4] / 4))) || 
		      ((hand[4] / 4 == hand[3] / 4) && ((hand[2] / 4 == hand[1] / 4) || (hand[1] / 4 == hand[0] / 4)))    ) { handRank = 7; }
	// One Pair
	else if ((hand[0] / 4 == hand[1] / 4) || (hand[1] / 4 == hand[2] / 4) || (hand[2] / 4 == hand[3] / 4) || (hand[3] / 4 == hand[4] / 4)) { handRank = 8; }

	return handRank;

}
