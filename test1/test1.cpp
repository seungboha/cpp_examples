#include <iostream>
#include <cstdint>

using std::uint64_t;


static uint64_t Solution(uint64_t N);
static uint64_t Count369(uint64_t N);

int main()
{
	uint64_t N = 0;

	std::cin >> N;
	std::cout << Solution(N) << std::endl;

	return 0;
}
//========//========//========//========//=======#//========//========//========//========//=======#

uint64_t Count369(uint64_t N) {
	// N is natural number
	uint64_t count = 0;
	uint64_t last_digit;

	while (N != 0) {
		last_digit = N % 10;
		if (last_digit==3 || last_digit==6 || last_digit==9) {
			count++;
		}
		N /= 10;
	}
	return count;
}

uint64_t Solution(uint64_t N)
{
	uint64_t answer = 0;
	//answer = CountOccurrence(3333, 3);

	for (uint64_t num = 1; num <= N; num++) {
		answer += Count369(num);

	}

	return answer;
}