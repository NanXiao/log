# log
A simple log function implemented in C++.

## Example

`main.cpp`:  

	#include "log.h"
	
	int main()
	{
		log(std::cout, "A", '\n');
		log(std::cout, "A is ", 65, 'a', '\n');
		return 0;
	}  
Compile it: 

	g++ -std=c++11 -o test main.cpp log.cpp
For `std::ostream` who is thread-safe, like `std::cout`, `std::cerr`, the `log` won't cause traces interleaved; if it is not thread-safe, it is easy to add mutex in `log`.
