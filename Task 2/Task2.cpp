#include <iostream>

int main(){
	double number1;
	double number2;
	char operation;
	double answer;
	
	
	std::cout<<"Enter First Number :";
	std::cin>>number1;
	
	std::cout<<"Enter Second Number :";
	std::cin>>number2;
	
	std::cout<<"Enter Operation (+,-,*,/) :";
	std::cin>>operation;
	
	switch(operation){
		case '+':
			answer = number1+number2;
			break;
		case '-':
			answer=number1-number2;
			break;
		case '*':
			answer=number1*number2;
			break;
		case '/':
			answer= number1/number2;
			break;
		default:
			std::cout<<"Invalid operation!";
	}
	std::cout<<"Answer is : "<<answer;
	return 0;
	
}
