#include <iostream>
#include <sstream>

/* The base conditon to stop */
void log(std::ostream& out, std::stringstream& ss);

template <typename First, typename... Rest>
void log(std::ostream& out, std::stringstream& ss, First&& first, Rest&&... rest)
{
	ss << std::forward<First>(first);
    log(out, ss, std::forward<Rest>(rest)...);
	return;
}

template <typename First, typename... Rest>
void log(std::ostream& out, First&& first, Rest&&... rest)
{
	std::stringstream ss;
	ss << std::forward<First>(first);
    log(out, ss, std::forward<Rest>(rest)...);
	return;
}
