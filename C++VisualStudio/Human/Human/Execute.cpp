#include <Human.h>
#include <HumanHistograms.h>
#include <FinancialBehaviourAlgo.h>
#include <iostream>
#include <ctime>
#include <thread>
#include <vector>
#include <Windows.h>

using namespace std;

int main()
{
    cout << "Human Program \n";

	int ageStart = 1;
	int ageEnd = 100;
	srand(time(0));

	CreateHumans();

	Human* h1[100] = {0};
	vector<thread> threads;

	for (int i = 0; i < 100; i++) {
		//Create Human Objects
		h1[i] = new Human();
		char tmpName[20];

		_itoa_s(i, tmpName, 20, 10);
		//Set Name
		h1[i]->SetName(string(tmpName));
		//Set Age
		h1[i]->SetAge(ageStart + rand() % (ageEnd - ageStart + 1));
		//Set Gender
		h1[i]->SetGender(rand() % 2);
		//Printout Name and Age
		h1[i]->IntroduceSelf();

		threads.emplace_back(&Human::TimeMachine, h1[i], i);
	}


	HumanHistograms iHist;
	iHist.CreateHistograms(h1, 100);
	iHist.DisplayAgeHistograms();
	iHist.DisplayGenderHistogram();

	////Start Time Machine
	//thread* t1[100] = {0};
	//for (int i = 0; i < 100; i++) {
	//	*t1[i] = thread(h1[i]->TimeMachine());
	//}
	// Ages of the humans need to be updated for 50 years
	//for (int i = 0; i < 100; i++)
	//{
	//	//Update Age
	//	h1[i]->SetAge(h1[i]->age + 50);
	//}
	for (int i = 0; i < 5; i++) {
		//Sleep 5 seconds
		Sleep(5000);
		iHist.ClearHistograms();
		iHist.CreateHistograms(h1, 100);
		iHist.DisplayAgeHistograms();
	}
	
	// Join all threads
	for (auto& t : threads) {
		t.join();
	}

	//Delete Human Objects
	for (int i = 0; i < 100; i++) {
		delete h1[i];
		h1[i] = 0;
	}

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file