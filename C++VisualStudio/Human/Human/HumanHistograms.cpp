#include <Human.h>
#include <HumanHistograms.h>


void HumanHistograms::CreateHistograms(Human** h1, unsigned int entries)
{
	for (int i = 0; i < 100; i++)
	{
		ageHistogram[(h1[i]->age-1) / 8 ]++; // Average life expectancy, median distribution
		weightHistogram[h1[i]->weight / 10]++;
		heightHistogram[h1[i]->height]++;
		NetWorthHistogram[h1[i]->NetWorth]++;//TODO: Fix this. Power law distribution
		genderHistogram[h1[i]->GetGender()]++;
	}
}

void HumanHistograms::DisplayAgeHistograms() 
{
	cout << "\n Age Histograms \n";
	for (int i = 0; i < 15; i++) {
		cout << " Age :" << i*8 << "to" << (i+1)*8 << "  =  " << ageHistogram[i] << endl;
	}
}


void HumanHistograms::DisplayGenderHistogram() {
	cout << "\n Gender Histograms \n";
	for (int i = 0; i < 2; i++) {
		cout << " Gender :" << (i == 0? "Female" : "Male") <<"   " << genderHistogram[i] << endl;
	}
}

void HumanHistograms::ClearHistograms()
{
	for (int i = 0; i < 15; i++) {
		ageHistogram[i] = 0;
	}

	for (int i = 0; i < 15; i++) {
		weightHistogram[i] = 0;
	}

	for (int i = 0; i < 10; i++) {
		heightHistogram[i] = 0;
	}

	for (int i = 0; i < 10; i++) {
		NetWorthHistogram[i] = 0;
	}

	genderHistogram[0] = 0;
	genderHistogram[1] = 0;
	
}

