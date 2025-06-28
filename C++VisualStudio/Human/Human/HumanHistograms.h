#pragma once
class HumanHistograms
{
public:
	void CreateHistograms(Human** h1, unsigned int entries);
	void DisplayAgeHistograms();
	void DisplayGenderHistogram();
	void ClearHistograms();

	int ageHistogram[15] = { 0 }; //0-8, 9-16, 17-24, 25-32, 33-40, 41-48, 49-56, 57-64, 65-72, 73-80, 81-88, 89-96, 97-104, 105-112, 113-120
	int weightHistogram[15] = { 0 }; //0-10, 10-20, 20-30, 30-40, 40-50, 50-60, 60-70, 70-80, 80-90, 90-100, 100-110, 110-120, 120-130, 130-140, 140-150
	int heightHistogram[10] = { 0 }; //1,2,3,4,5,6,7,8,9,10
	int NetWorthHistogram[10] = { 0 }; //0-10,10-100,100-1000,1000-10000,10000-100000,100000-1000000,1000000-10000000,10000000-100000000,100000000-1000000000,1000000000-10000000000
	int genderHistogram[2] = { 0 }; //0,1

};