/*
 * eligibility.h
 *
 *  Created on: 17-Apr-2020
 *      Author: akshay
 */
#include <iostream>
using namespace std;
#ifndef ELIGIBILITY_H_
#define ELIGIBILITY_H_

class eligibility {
private:
	float min_percent;
	string course_name,degree;
public:
	eligibility();
	eligibility(string course_name,string degree,float min_percent);
	~eligibility();
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	const string& getDegree() const;
	void setDegree(const string& degree);
	float getMinPercent() const;
	void setMinPercent(float minPercent);
	void display();
};

#endif /* ELIGIBILITY_H_ */
