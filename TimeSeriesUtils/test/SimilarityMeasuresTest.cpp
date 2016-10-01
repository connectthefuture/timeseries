#include "../include/TimeSeriesUtils.hpp"
#include <vector>
#include <cstdint>
#include <catch.hpp>

namespace {

	typedef TimeSeriesUtils::Measurement<double> DoubleMeasurement;

	TEST_CASE("DynamicTimeWarpedDistanceTest")
	{
		std::vector<DoubleMeasurement> timeSeries0;
		std::vector<DoubleMeasurement> timeSeries1;

		timeSeries0.push_back(DoubleMeasurement(0, 4));
		timeSeries0.push_back(DoubleMeasurement(1, 4));
		timeSeries0.push_back(DoubleMeasurement(2, 5));
		timeSeries0.push_back(DoubleMeasurement(3, 5));
		timeSeries0.push_back(DoubleMeasurement(4, 6));
		timeSeries0.push_back(DoubleMeasurement(5, 6));
		timeSeries0.push_back(DoubleMeasurement(6, 7));
		timeSeries0.push_back(DoubleMeasurement(7, 7));

		timeSeries1.push_back(DoubleMeasurement(1, 23));
		timeSeries1.push_back(DoubleMeasurement(2, 4));
		timeSeries1.push_back(DoubleMeasurement(3, 5));
		timeSeries1.push_back(DoubleMeasurement(4, 6));
		timeSeries1.push_back(DoubleMeasurement(5, 7));

		double result = TimeSeriesUtils::CalculateDynamicTimeWarpedDistance(timeSeries0, timeSeries1);

		REQUIRE(result == Approx(19).epsilon(0.01));
	}

	TEST_CASE("LongestCommonSubsequenceTest")
	{
		std::vector<DoubleMeasurement> timeSeries0;
		std::vector<DoubleMeasurement> timeSeries1;

		timeSeries0.push_back(DoubleMeasurement(0, 4));
		timeSeries0.push_back(DoubleMeasurement(1, 4));
		timeSeries0.push_back(DoubleMeasurement(2, 5));
		timeSeries0.push_back(DoubleMeasurement(3, 5));
		timeSeries0.push_back(DoubleMeasurement(4, 6));
		timeSeries0.push_back(DoubleMeasurement(5, 6));
		timeSeries0.push_back(DoubleMeasurement(6, 7));
		timeSeries0.push_back(DoubleMeasurement(7, 7));

		timeSeries1.push_back(DoubleMeasurement(1, 4));
		timeSeries1.push_back(DoubleMeasurement(2, 5));
		timeSeries1.push_back(DoubleMeasurement(3, 6));
		timeSeries1.push_back(DoubleMeasurement(4, 7));

		int result = TimeSeriesUtils::CalculateLongestCommonSubsequence(timeSeries0, timeSeries1);

		REQUIRE(result == 4);
	}
}
