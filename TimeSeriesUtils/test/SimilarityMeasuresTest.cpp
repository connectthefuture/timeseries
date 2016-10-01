#include "../include/TimeSeriesUtils.hpp"
#include <vector>
#include <cstdint>
#include <catch.hpp>

namespace {

	TEST_CASE("DynamicTimeWarpedDistanceTest")
	{
		std::vector<double> timeSeries0;
		std::vector<double> timeSeries1;

		timeSeries0.push_back(4);
		timeSeries0.push_back(4);
		timeSeries0.push_back(5);
		timeSeries0.push_back(5);
		timeSeries0.push_back(6);
		timeSeries0.push_back(6);
		timeSeries0.push_back(7);
		timeSeries0.push_back(7);

		timeSeries1.push_back(23);
		timeSeries1.push_back(4);
		timeSeries1.push_back(5);
		timeSeries1.push_back(6);
		timeSeries1.push_back(7);

		double result = TimeSeriesUtils::CalculateDynamicTimeWarpedDistance(timeSeries0, timeSeries1);

		REQUIRE(result == Approx(19).epsilon(0.01));
	}

	TEST_CASE("LongestCommonSubsequenceTest")
	{
		std::vector<double> timeSeries0;
		std::vector<double> timeSeries1;

		timeSeries0.push_back(4);
		timeSeries0.push_back(4);
		timeSeries0.push_back(5);
		timeSeries0.push_back(5);
		timeSeries0.push_back(6);
		timeSeries0.push_back(6);
		timeSeries0.push_back(7);
		timeSeries0.push_back(7);

		timeSeries1.push_back(4);
		timeSeries1.push_back(5);
		timeSeries1.push_back(6);
		timeSeries1.push_back(7);

		int result = TimeSeriesUtils::CalculateLongestCommonSubsequence(timeSeries0, timeSeries1);

		REQUIRE(result == 4);
	}
}
