#include <collatz.hpp>

#include <iostream>
#include <vector>

Collatz::Collatz(int32_t first_number_){
	loop_len = branch_len = 0u;
	numbers.push_back(first_number_);
}

void Collatz::calcCollatz(int32_t a_, int32_t b_){
	if((numbers.back() & 0x01) == 0){
		numbers.push_back(numbers.back() / 2);
	}else{
		numbers.push_back(numbers.back() * a_ + b_);
	}
}

int Collatz::checkLoop(uint32_t start_branch_, uint32_t start_loop_){
	bool loop_flag = false;

	for(loop_len=start_loop_; loop_len<((numbers.size()-start_branch_)>>2); loop_len++){
		if(std::equal(numbers.end()-loop_len, numbers.end(), numbers.end()-(loop_len<<1))){
			if(std::equal(numbers.end()-loop_len, numbers.end(), numbers.end()-loop_len*3)){
				if(std::equal(numbers.end()-loop_len, numbers.end(), numbers.end()-(loop_len<<2))){
					if(std::equal(numbers.end()-loop_len, numbers.end(), numbers.end()-loop_len*5)){
						loop_flag = true;
						break;
					}
				}
			}
		}
	}

	if(!loop_flag){
		std::cout << "No loop found." << std::endl;

		return 1;
	}

	for(branch_len=start_branch_; branch_len<numbers.size()-(loop_len<<2); branch_len++){
		if(std::equal(numbers.begin()+branch_len, numbers.begin()+branch_len+loop_len, numbers.begin()+branch_len+loop_len)){
			if(std::equal(numbers.begin()+branch_len, numbers.begin()+branch_len+loop_len, numbers.begin()+branch_len+(loop_len<<1))){
				if(std::equal(numbers.begin()+branch_len, numbers.begin()+branch_len+loop_len, numbers.begin()+branch_len+loop_len*3)){
					if(std::equal(numbers.begin()+branch_len, numbers.begin()+branch_len+loop_len, numbers.begin()+branch_len+(loop_len<<2))){
						break;
					}
				}
			}
		}
	}

	return 0;
}
