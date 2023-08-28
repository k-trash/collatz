#include <collatz.hpp>

#include <iostream>

int main(int argc_, char* argv_[]){
	int32_t first_num;

	std::cout << "First number: ";
	std::cin >> first_num;

	Collatz collatz(first_num);

	for(uint32_t i=0; i<1000000; i++){
		collatz.calcCollatz(3, 1);
	}

	if(collatz.checkLoop(1, 1) == 0){
		for(uint32_t i=0; i<=collatz.loop_len; i++){
			std::cout << collatz.numbers[collatz.branch_len+i] << ' ';
		}

		std::cout << std::endl << collatz.branch_len + 1 << '\t' << collatz.loop_len << std::endl;
	}

	return 0;
}
