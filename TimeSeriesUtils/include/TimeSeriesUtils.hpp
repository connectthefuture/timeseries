#ifndef TSUTIL_H
#define TSUTIL_H

#include <vector>
#include <cstdint>

namespace TimeSeriesUtils {
	
	double CalculateEuclideanDistance(double x, double y);

	double CalculateDynamicTimeWarpedDistance(std::vector<double> t0, std::vector<double> t1);
	
	int CalculateLongestCommonSubsequence(std::vector<double> t0, std::vector<double> t1);
	
	int CalculateTimeWarpedLongestCommonSubsequence(std::vector<double> t0, std::vector<double> t1);

}

#endif
