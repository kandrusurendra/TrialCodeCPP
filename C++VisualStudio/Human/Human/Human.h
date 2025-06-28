#pragma once
#include <iostream>
using namespace std;

enum Work
{ 
	UNEMPLOYED, 
	EMPLOYED, 
	BUSINESS,
	STUDENT, 
	RETIRED 
};

class Human
{
public:
	string name;
	int age;
	int weight;
	int height;
	int NetWorth;
	int gender;
	//Country, Work, Financial State, Family Dependency, Married/Unmarried, Kids, Intelligence

	Human()
	{
		name = "NoName";
		age = 0;
		weight = 0;
		height = 0;
		NetWorth = 0;
		gender = 0; //female
	}

	~Human()
	{
		// Destructor for Human Object
		//cout << name << "Destroyed \n";
	}

	void IntroduceSelf();

	void GetName();
	void SetName(string name);

	void getAge();
	void SetAge(int age);

	int GetWeight();
	void SetWeight(int weight);

	int GetHeight();
	void setHeight(int height);

	int GetNetWorth();
	void SetNetWorth(int NetWorth);

	int GetGender();
	void SetGender(int gender);
	//What is the input?
	//	Areas that impact Financial Behavior
	//		Hope/Fear (Future), Prosperity, Current/Past Financial State, Family, Age, Mental State (Ambitious, Risk taking), Health, Financial Education
	void FinancialBehaviour();

	//What are the inputs?
	//	Love, Marriage, Kids, Health, 
	void EmotionalBehaviour();

	//Time Movement
	void TimeMachine(int ThreadID);

	//Start life time: basically updates the age every second
	void startLife();

};


