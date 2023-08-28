#pragma once

#include <iostream>
#include <vector>

class Collatz{
	public:
		uint32_t loop_len, branch_len;
		std::vector<int64_t> numbers;

		Collatz(int32_t first_num_);
		void calcCollatz(int32_t a_, int32_t b);
		int checkLoop(uint32_t start_branch_, uint32_t start_loop_);
};
