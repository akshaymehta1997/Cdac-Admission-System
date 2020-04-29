/*
 * eligibility.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: akshay
 */

#include "eligibility.h"

eligibility::eligibility() {
	setCourseName(" ");
	setDegree(" ");
	setMinPercent(0);
}

const string& eligibility::getCourseName() const {
	return course_name;
}

void eligibility::setCourseName(const string& courseName) {
	course_name = courseName;
}

const string& eligibility::getDegree() const {
	return degree;
}

void eligibility::setDegree(const string& degree) {
	this->degree = degree;
}

float eligibility::getMinPercent() const {
	return min_percent;
}

eligibility::eligibility(string course_name, string degree, float min_percent) {
	setCourseName(course_name);
	setDegree(degree);
	setMinPercent(min_percent);
}

void eligibility::setMinPercent(float minPercent) {
	min_percent = minPercent;
}

eligibility::~eligibility() {
	// TODO Auto-generated destructor stub
}

void eligibility::display() {
	cout<<"---->"<<course_name<<" "<<degree<<" "<<min_percent<<endl;
}
