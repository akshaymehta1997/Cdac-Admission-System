/*
 * preference.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: akshay
 */

#include "preference.h"

preference::preference() {
	this->setCenterId(" ");
	this->setCourseName(" ");
	this->setFormNo(0);
	this->setPreferenceNo(0);
}

const string& preference::getCenterId() const {
	return center_id;
}

void preference::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& preference::getCourseName() const {
	return course_name;
}

void preference::setCourseName(const string& courseName) {
	course_name = courseName;
}

int preference::getFormNo() const {
	return form_no;
}

void preference::setFormNo(int formNo) {
	form_no = formNo;
}

int preference::getPreferenceNo() const {
	return preference_no;
}

void preference::setPreferenceNo(int preferenceNo) {
	preference_no = preferenceNo;
}

preference::~preference() {
	// TODO Auto-generated destructor stub
}

preference::preference(int form_no, int preference, string course_name,
		string center_id) {
	this->setCenterId(center_id);
	this->setCourseName(course_name);
	this->setFormNo(form_no);
		this->setPreferenceNo(preference);
}

void preference::display() {
	cout<<"---->"<<this->form_no<<" "<<this->preference_no<<" "<<this->center_id<<" "<<this->course_name<<endl;
}
