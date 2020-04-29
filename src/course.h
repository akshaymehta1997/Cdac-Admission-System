/*
 * course.h
 *
 *  Created on: 16-Apr-2020
 *      Author: akshay
 */

#include <vector>
#include <iostream>
#include <map>
#include "eligibility.h"

using namespace std;

#ifndef COURSE_H_
#define COURSE_H_

class course {

private:
	int id;
	float fees;
	string name,ccat_section;
	vector<eligibility>vector_eligibility;
	map<string,int>lcenter;

public:
	course();
	course(int id,string name,int fees,string section);
	~course();
	const string& getCcatSection() const;
	void setCcatSection(const string& ccatSection);
	float getFees() const;
	void setFees(float fees);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);
	void display_centers();
	vector<eligibility>& getvectorEligibility() ;
	void setvectorEligibility(const vector<eligibility>& vectorEligibility);
	void display();
	 map<string, int>& getLcenter();
	void setLcenter(const map<string, int>& lcenter);
};

#endif /* COURSE_H_ */
