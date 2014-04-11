/*
Problem Statement
    	
Class Name: Dice
Method Name: getScores
Parameters: int, int[]
Returns: int[]

Implement a class Dice, which contains a method getScores. getScores takes an
int representing the number of players playing the game and an int[]
representing the rolls of the die.  getScores returns the final scores of all
the players, as an int[].  The 0th element of the int[] is the score of the
first player, 1st element is the score of second player ...

Here is the method signature:
int[] getScores(int iNumberOfPlayers, int[] dieRolls);
Be sure your method is public.
* iNumberOfPlayers will be a number from 3 to 10 (inclusive)
* dieRolls will be of length 10 to 50 (inclusive), and will contain Integers
from 1 to 6 (inclusive)

The game always starts with player 1.  The players sit in a circle with player
2 to the right of player 1 and player 1 to the right of the last player.  When
it is a player's turn, the player rolls the die. The player earns points and
the next player is determined based on the following rules:
* If the die is a 1 or 2, one point is earned.
* If the die is a 3 or 4, two points are earned.
* If the die is a 5 or 6, three points are earned.
* If the number on the die is even, control passes to the player on the left.
* If the number on the die is odd, control passes to the player on the right.
* The above rules do not apply when the number rolled is exactly the same as
the previously rolled number. Instead, control is kept by the current player,
and points are earned according to the following:
* If it is the first time the number has been rerolled(second time in a row
a number has been rolled), points are given as above, plus bonus points are
given equal to the amount shown on the die.
* Otherwise, points are earned equal to the amount shown on the die
multiplied by the number of times the player has rerolled the number.

Walkthrough example:
With 5 players, and the rolls [3,4,4,4,4,6,6,2,1,5,5], the game is played as
below:
player 1 rolls a 3, earning 2   points. Control passes to the right (player
2) [2,0,0,0,0]
player 2 rolls a 4, earning 2   points. Control passes to the left  (player
1) [2,2,0,0,0]
player 1 rolls a 4, earning 2+4 points. Control stays with          (player
1) [8,2,0,0,0]
player 1 rolls a 4, earning 2*4 points. Control stays with          (player
1) [16,2,0,0,0]
player 1 rolls a 4, earning 3*4 points. Control stays with          (player
1) [28,2,0,0,0]
player 1 rolls a 6, earning 3   points. Control passes to the left  (player
5) [31,2,0,0,0]
player 5 rolls a 6, earning 3+6 points. Control stays with          (player
5) [31,2,0,0,9]
player 5 rolls a 2, earning 1   point.  Control passes to the left  (player
4) [31,2,0,0,10]
player 4 rolls a 1, earning 1   point.  Control passes to the right (player
5) [31,2,0,1,10]
player 5 rolls a 5, earning 3   points. Control passes to the right (player
1) [31,2,0,1,13]
player 1 rolls a 5, earning 3+5 points. Control stays with          (player
1) [39,2,0,1,13]
  *** GAME OVER ***
  The int[] returned is [39,2,0,1,13].

Examples:
* With 5 players, and the rolls [3,4,4,4,6,6,2,1,5,5], the scores are
[27,2,0,1,13].
* With 3 players, and the rolls [2,5,6,3,1,3,2,5,5,6], the scores are [5,5,17].
* With 5 players, and the rolls [1,1,2,1,3,5,3,3,1,2,2,1,1], the scores are
[5,5,3,2,10].
* With 10 players, and the rolls [5,3,5,6,5,2,2,1,6,3,6], the scores are
[3,2,12,10,0,0,0,0,0,0].
 
Definition
    	
Class:	Dice
Method:	getScores
Parameters:	int, int[]
Returns:	int[]
Method signature:	int[] getScores(int param0, int[] param1)
(be sure your method is public)
*/

#include <iostream>
#include <vector>

using namespace std;

class Dice
{
	public:
		vector<int> getScores(int iNumberOfPlayers, vector<int> dieRolls)
		{
			vector<int> finalScore(iNumberOfPlayers,0);

			int player = 0;

			int repeated = 1;

			for (int i = 0; i < dieRolls.size() ; ++i)
			{
				if(i > 0 && dieRolls[i] == dieRolls[i-1])
					++repeated;
				else
					repeated = 1;

				if(repeated == 1)
				{
					finalScore[player] += (dieRolls[i]&1 ? (dieRolls[i]+1)/2 : dieRolls[i]/2);
					dieRolls[i]&1 ? ++player%=iNumberOfPlayers : --player%=iNumberOfPlayers;
					player<0?player+=iNumberOfPlayers:0;
				}
				else if(repeated == 2)
				{
					finalScore[player] += (dieRolls[i]&1 ? (dieRolls[i]+1)/2 : dieRolls[i]/2);
					finalScore[player] += dieRolls[i];
				}
				else if(repeated > 2)
				{
					finalScore[player] += (repeated-1)*dieRolls[i];
				}	
			}

			return finalScore;
		}
};

int main()
{
	Dice *D = new Dice;

	vector<int> dieRolls;
	//int players=10;int drolls[] =  {5,3,5,6,5,2,2,1,6,3,6};dieRolls.insert(dieRolls.begin(),drolls,&drolls[sizeof(drolls)/sizeof(*drolls)]);
	//int players=3;int drolls[] =  {1, 2, 3, 4, 5, 6, 1, 2, 3, 4};dieRolls.insert(dieRolls.begin(),drolls,&drolls[sizeof(drolls)/sizeof(*drolls)]);
	//int players=4;int drolls[] =  {5, 2, 6, 6, 6, 6, 5, 5, 4, 5};dieRolls.insert(dieRolls.begin(),drolls,&drolls[sizeof(drolls)/sizeof(*drolls)]);
	//int players=4;int drolls[] =  {2, 4, 6, 2, 4, 6, 2, 4, 6, 2, 4};dieRolls.insert(dieRolls.begin(),drolls,&drolls[sizeof(drolls)/sizeof(*drolls)]);
	//int players=8;int drolls[] =  {5, 5, 3, 2, 2, 4, 1, 1, 1, 1, 1};dieRolls.insert(dieRolls.begin(),drolls,&drolls[sizeof(drolls)/sizeof(*drolls)]);
	int players=3;int drolls[] =  {2, 2, 3, 4, 5, 6, 5, 4, 2, 1, 2};dieRolls.insert(dieRolls.begin(),drolls,&drolls[sizeof(drolls)/sizeof(*drolls)]);

	vector<int> finalScore = D->getScores(players,dieRolls);

	for (int i = 0; i < finalScore.size(); ++i)
	{
		cout<<finalScore[i]<<" ";
	}
	cout<<"\n";

	return 0;
}