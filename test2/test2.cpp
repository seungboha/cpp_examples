#include <iostream>
#include <cstdint>

using std::uint64_t;


static uint64_t Solution(uint64_t A);


int main()
{
	uint64_t A = 0;

	std::cin >> A;
	std::cout << Solution(A) << std::endl;

	return 0;
}
//========//========//========//========//=======#//========//========//========//========//=======#



uint64_t Solution(uint64_t A)
{
	std::array<uint64_t, 8> perm = {1, 2, 4, 3, 7, 8, 6, 5};
	return 0;
}