#include <iostream>
#include <cstdint>

using std::uint64_t;


static uint64_t Solution(uint64_t A);
static uint64_t log2(uint64_t A);

int main()
{
	uint64_t A = 0;
	std::cin >> A;
	std::cout << Solution(A) << std::endl;

	return 0;
}
//========//========//========//========//=======#//========//========//========//========//=======#

uint64_t log2(uint64_t A){
	uint64_t k = 0;

	A = A - 1;
	while(A != 0){
		k++;
		A = A / 2;
	}
	return k;
}


uint64_t Solution(uint64_t A)
{
	uint64_t val_log2 = log2(A);
	uint64_t min_idx = 1;
	// Possible maximum idx
	uint64_t max_idx = 1;
	for(uint64_t k=0; k<=val_log2; k++){
		max_idx *= 2;
	}
	
	// Search the idx of A
	uint64_t search_N = 1;
	uint64_t quotient, remainder;

	quotient = A / 2;
	remainder = A % 2;

	while(search_N < A){
		if(quotient == 0){
			max_idx = max_idx / 2;
			if(remainder == 0){
				max_idx = max_idx / 2;
			}
			else{
				search_N *= 2;
				min_idx = min_idx * 2 + 1;
			}
		}
		else{
			search_N++;
			max_idx = max_idx / 2;
			min_idx = min_idx * 2 + 1;
			// A /= 2;
		}

		std::cout << "max_idx:" << max_idx << std::endl;
		std::cout << "min_idx:" << min_idx << std::endl;
	}

	return search_N;
}