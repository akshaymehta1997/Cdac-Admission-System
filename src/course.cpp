/*
 * course.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: akshay
 */

#include "course.h"

course::course() {
	setId(0);
	setName(" ");
	setFees(0);
	setCcatSection(" ");

}

const string& course::getCcatSection() const {
	return ccat_section;
}

void course::setCcatSection(const string& ccatSection) {
	ccat_section = ccatSection;
}

float course::getFees() const {
	return fees;
}

void course::setFees(float fees) {
	this->fees = fees;
}

int course::getId() const {
	return id;
}

void course::setId(int id) {
	this->id = id;
}

const string& course::getName() const {
	return name;
}

void course::setName(const string& name) {
	this->name = name;
}

course::~course() {
	// TODO Auto-generated destructor stub
}

vector<eligibility>& course::getvectorEligibility()  {
	return vector_eligibility;
}

void course::setvectorEligibility(const vector<eligibility>& vectorEligibility) {
	vector_eligibility = vectorEligibility;
}

course::course(int id, string name, int fees, string section) {
	setId(id);
	setName(name);
	setFees(fees);
	setCcatSection(section);
}

void course::display() {
	cout<<"Course name : "<<name
			<<"\nFees : "<<fees
			<<"\nCcat Section : "<<ccat_section<<endl;
}

map<string, int>& course::getLcenter() {
	return lcenter;
}

void course::setLcenter(const map<string, int>& lcenter) {
	this->lcenter = lcenter;
}

void course::display_centers() {
	map<string,int>::iterator itr=lcenter.begin();
	while(itr!=lcenter.end())
	{
		cout<<itr->first<<" "<<itr->second<<endl;
		itr++;
	}
}
