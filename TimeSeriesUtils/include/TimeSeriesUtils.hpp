#include <chrono>
#include <vector>
#include <cstdint>

#ifndef TSUTIL_H
#define TSUTIL_H

namespace TimeSeriesUtils {
	
	template<typename TMeasurementType>
	class Measurement {
	
	public:

		Measurement(std::uint64_t timestamp, TMeasurementType measurement)
			: timestamp(timestamp), measurement(measurement) { }

		std::uint64_t getTimestamp() {
			return timestamp;
		}

		TMeasurementType getMeasurement() {
			return measurement;
		}
		
	private:

		std::uint64_t timestamp;
		TMeasurementType measurement;
	};

	double CalculateEuclideanDistance(double x, double y);

	double CalculateDynamicTimeWarpedDistance(std::vector<Measurement<double>> t0, std::vector<Measurement<double>> t1);
	
	int CalculateLongestCommonSubsequence(std::vector<Measurement<double>> t0, std::vector<Measurement<double>> t1);
	
	int CalculateTimeWarpedLongestCommonSubsequence(std::vector<Measurement<double>> t0, std::vector<Measurement<double>> t1);

}

#endif
