#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iterator>

int main()
{
	auto count = 0;
	std::map<std::pair<int, int>, int> score_map;
	const auto min_power = 0;
	const auto max_power = 10;

	for (auto a = min_power; a <= max_power; ++a)
	for (auto b = min_power; b <= max_power; ++b)
	for (auto c = min_power; c <= max_power; ++c)
	for (auto d = min_power; d <= max_power; ++d)
	for (auto e = min_power; e <= max_power; ++e)
	for (auto f = min_power; f <= max_power; ++f)
	for (auto g = min_power; g <= max_power; ++g)
	{
		auto enemy_score = a + b + c + d;
		auto ally_score = e + f + g;
		auto score = ally_score - enemy_score;
		printf
		(
			"%02d %02d %02d %02d %02d %02d %02d : %c%02d\r",
			a, b, c, d, e, f, g,
			(score < 0 ? '-': ' '),
			abs(score)
		);
		++score_map[{enemy_score, ally_score}];
		++count;
	}
	
	printf("                                               \r");
	for (auto i = std::begin(score_map); i != std::end(score_map); ++i)
	{
		printf
		(
			"%c%02d\t%c%02d\t%d\t%f\r\n",
			(i->first.first < 0 ? '-' : ' '),
			abs(i->first.first),
			(i->first.second < 0 ? '-' : ' '),
			abs(i->first.second),
			i->second,
			((double)i->second) /((double)count)
		);
	}

	return EXIT_SUCCESS;
}

