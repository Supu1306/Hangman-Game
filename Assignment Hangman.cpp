//Name-Supreet Singh Dhillon       // Student id- DHISD1903
// ASSIGNMENT 2 , HANGMAN GAME

#include <iostream>
using namespace std;
int letter_counter (char cstring[] )                   // counts the number of letters in the secret_word.
{
	int i=0;
	while(cstring[i] != 0)
		i++;
	return i;
}

int num_of_guesses (int size)                          // calculates the number of guesses.
{
	int num = size+5;
	if(num < 10)
		num = 10;
	if(num > 20)
		num = 20;

	return num;
}

bool compare ( char arr[], char arr1[], int size)     // compares the duplicate secret_secret and the original secret_word
{
	for(int i=0; i< size; i++)
	{
		if(arr[i] != arr1[i])
		return false;
	}
	return true;
}

bool continue_playing_or_not ( char var )            // tells the computer if the user wants to continue playing or not.
{
	if(var == 'y')
		return true;
	if(var == 'n')
		return false;
	else
		return 0;
}

void print_word ( char arr[], int size)                // prints the word.
{
	int i = 0; 
	while(i<size)
	{
		cout << arr[i];
		i++;
	}
}

void modify_word ( char arr[], int size)          // replaces every character in the word with '*'.
{
	for(int i = 0; i < size; i++)
	{
		arr[i]='*';
	}
}

int main()
{
	char answer;
	do
	{
		char *secret_word;
		const int size = 20;
		secret_word = new char[size];
		cout << "Enter the secret word (all in lowercase): " ;
		cin >> secret_word;
		cout << "==========================================" << endl;
		cout << endl;

		int number_of_words = letter_counter(secret_word);
		int guesses_given = num_of_guesses(number_of_words);

		char*duplicate_secret_word;
		duplicate_secret_word = new char[number_of_words];
		for(int j=0; j<number_of_words; j++)
			duplicate_secret_word[j] = secret_word[j];
		modify_word(duplicate_secret_word, number_of_words);

		bool check = true;
		char guess;
		for(int i=1; (i<=guesses_given)&&(compare(secret_word,duplicate_secret_word,number_of_words)==0); i++)
		{
			cout << "Word so far: " ;
			print_word(duplicate_secret_word, number_of_words);
			cout << endl;
			cout << "Take guess number " << i << " " <<":" << " " ;
			cin >> guess;
			int count=0;
			for(int j=0; j<number_of_words; j++)
			{
				if(secret_word[j] == guess)
				{
					count++;
					duplicate_secret_word[j] = guess;
					check = false;
					if(count<=1)
					{
						cout << "Got it! " << endl;
						cout << endl;
					}
				}
			}
			if(check == true)
			{
				cout << "Sorry. " << endl;
				cout << endl;
			}
			check = true;
		}

		if( compare(secret_word,duplicate_secret_word,number_of_words) == true)
		{
			cout << "Good. You correctly guessed the word: " ;
			for(int i=0; i< number_of_words; i++)
				cout << secret_word[i];
			cout << endl << endl;
		}
		else
		{
			cout << "Sorry no more lives. The word is: ";
			for(int i=0; i< number_of_words; i++)
				cout << secret_word[i];
			cout << endl << endl;
		}

		cout << "Do you want to play one more time? y/n? " ;
		cin >> answer;
		cout << endl;
	} while(continue_playing_or_not(answer));
	
	cout << "Bye! " << endl;

	system("pause");
	return 0;
}
