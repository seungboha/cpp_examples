#include <iostream>
#include <cstdint>
//#include <chrono>

using std::uint64_t;


static uint64_t Solution(uint64_t N);
static bool is_condition(uint64_t num);

int main()
{
	uint64_t N = 0;

	std::cin >> N;
	//auto start = std::chrono::high_resolution_clock::now();

	std::cout << Solution(N) << std::endl;
	//auto end = std::chrono::high_resolution_clock::now();
	//auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	//std::cout << "Elasped time: " << elapsed.count() << "ms" << std::endl;


	return 0;
}
//========//========//========//========//=======#//========//========//========//========//=======#


bool is_condition(uint64_t num) {
	if (num == 3 || num == 6 || num == 9) {
		return true;
	}
	else {
		return false;
	}
}


uint64_t Solution(uint64_t N)
{
	uint64_t num_digits = 1;
	uint64_t curr_digit;
	uint64_t max_claps = 0;
	uint64_t prev_num_claps = 0;
	uint64_t curr_num_claps = 0;
	uint64_t tail_number = 0;


	while (N != 0) {
		curr_num_claps = 0;
		curr_digit = N % 10;

		for (uint64_t n = 0; n < curr_digit; n++) {
			if (is_condition(n)) {
				curr_num_claps += num_digits + max_claps;
			}
			else {
				curr_num_claps += max_claps;
			}
		}

		if (is_condition(curr_digit)) {
			if (num_digits > 1) {
				curr_num_claps += tail_number + 1 + prev_num_claps;
			}
		}
		else {
			curr_num_claps += prev_num_claps;
		}

		// Calculate the max number of claps upto num_digits
		if (N/10 != 0){
			max_claps = 10 * max_claps + 3 * num_digits;
		}

		tail_number += curr_digit * num_digits;
		N = N / 10;
		num_digits *= 10;
		prev_num_claps = curr_num_claps;
	} // while


	return curr_num_claps;
}