#include <iostream>
#include <cstdlib>

int main(){
	int randomNumber = rand() % 100 + 1;
	int guess;
	std::cout<<"Guess The Number :";
	
	do {
		std::cin>>guess;
		if(guess>randomNumber){
			std::cout<<"High, Try again"<<std::endl;
		}
		else if(guess<randomNumber){
			std::cout<<"Low, Try again"<<std::endl;
		}
	}
	while (guess != randomNumber);
		std::cout<<"You guessed the Number " << randomNumber;
		return 0;
	
}
