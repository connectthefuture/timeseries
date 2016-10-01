#include <vector>
#include <cmath>
#include <algorithm>
#include "../include/TimeSeriesUtils.hpp"

namespace TimeSeriesUtils {

	double CalculateEuclideanDistance(double x, double y) {
		return std::sqrt(std::pow((x - y), 2));
	}	

	double CalculateDynamicTimeWarpedDistance(std::vector<double> t0, std::vector<double> t1) {
		
		size_t m = t0.size();
		size_t n = t1.size();

		// Allocate the Matrix to work on:
		std::vector<std::vector<double>> cost(m, std::vector<double>(n));

		cost[0][0] = CalculateEuclideanDistance(t0[0], t1[0]);

		// Calculate the first row:
		for (int i = 1; i < m; i++) {
			cost[i][0] = cost[i - 1][0] + CalculateEuclideanDistance(t0[i], t1[0]);
		}

		// Calculate the first column:
		for (int j = 1; j < n; j++) {
			cost[0][j] = cost[0][j - 1] + CalculateEuclideanDistance(t0[0], t1[j]);
		}

		// Fill the matrix:
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				cost[i][j] = std::min(cost[i - 1][j], std::min(cost[i][j - 1], cost[i - 1][j - 1])) 
					+ CalculateEuclideanDistance(t0[i], t1[j]);
			}
		}
	
		return cost[m-1][n-1];
	}

	int CalculateLongestCommonSubsequence(std::vector<double> t0, std::vector<double> t1) {
	
		size_t m = t0.size() + 1;
		size_t n = t1.size() + 1;

		// Allocate the Matrix to work on:
		std::vector<std::vector<int>> cost(m, std::vector<int>(n));

		cost[0][0] = 0;

		// Calculate the first row:
		for (int i = 1; i < m; i++) {
			cost[i][0] = 0;
		}

		// Calculate the first column:
		for (int j = 1; j < n; j++) {
			cost[0][j] = 0;
		}


		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				 if(std::abs(t0[i-1] - t1[j-1]) <= 1e-10) {
					cost[i][j] = 1 + cost[i-1][j-1];
				} else {
					cost[i][j] = std::max(cost[i][j-1], cost[i-1][j]);
				}
			}
		}
	
		return cost[m-1][n-1];
	}
	
	int CalculateTimeWarpedLongestCommonSubsequence(std::vector<double> t0, std::vector<double> t1) {
	
		size_t m = t0.size() + 1;
		size_t n = t1.size() + 1;

		// Allocate the Matrix to work on:
		std::vector<std::vector<int>> cost(m, std::vector<int>(n));

		cost[0][0] = 0;

		// Calculate the first row:
		for (int i = 1; i < m; i++) {
			cost[i][0] = 0;
		}

		// Calculate the first column:
		for (int j = 1; j < n; j++) {
			cost[0][j] = 0;
		}


		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				 if(std::abs(t0[i-1] - t1[j-1]) <= 1e-10) {
					cost[i][j] = 1 + std::max(cost[i][j-1], std::max(cost[i-1][j],  cost[i-1][j-1]));
				} else {
					cost[i][j] = std::max(cost[i][j-1], cost[i-1][j]);
				}
			}
		}
		
		return cost[m-1][n-1];
	}
}
