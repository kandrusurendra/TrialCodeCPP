// Human.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Human.h>
#include <Windows.h>

void Human::IntroduceSelf()
{
	cout << "I am " + name << " and am ";
	cout << age << " years old" << endl;
}

void  Human::GetName()
{
	cout << name << endl;
}

void  Human::SetName(string name)
{
	this->name = name;
}

void  Human::getAge()
{
	cout << age << endl;
}

void  Human::SetAge(int age)
{
	if (age > 120)
	{
		//cout << "Age is too high. Setting it to 120" << endl;
		age = 120;
	}

	this->age = age;
}

int  Human::GetWeight()
{
	return weight;
}

void  Human::SetWeight(int weight)
{
	this->weight = weight;
}

int  Human::GetHeight()
{
	return height;
}

void  Human::setHeight(int height)
{
	this->height = height;
}

int  Human::GetNetWorth()
{
	return NetWorth;
}

void  Human::SetNetWorth(int NetWorth)
{
	this->NetWorth = NetWorth;
}

int  Human::GetGender() {
	return this->gender;
}

void Human::SetGender(int gender) {
	this->gender = gender;
}

void Human::TimeMachine(int ThreadID)
{
	cout << " Thread ID: " << ThreadID << " is moving in time" << endl;
	while (age < 120) {
		Sleep(1000);
		age++;
	}

	cout << " Thread ID: " << ThreadID << " has reached the end of time" << endl;
}

void Human::startLife()
{

}