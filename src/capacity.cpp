/*
 * capacity.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: akshay
 */

#include "capacity.h"

capacity::capacity() {
	this->center_id=" ";
	this->course_name="";
	this->filled_capacity=0;
	this->max_capacity=0;
}


const string& capacity::getCenterId() const {
	return center_id;
}

void capacity::setCenterId(const string& centerId) {
	center_id = centerId;
}

int capacity::getFilledCapacity() const {
	return filled_capacity;
}

int capacity::getMaxCapacity() const {
	return max_capacity;
}

capacity::capacity(string center_id, string course_name, int max_capacity,int filled_capacity) {
	this->setCenterId(center_id);
	this->setCourseName(course_name);
	this->setMaxCapacity(max_capacity);
	this->setFilledCapacity(filled_capacity);
}

void capacity::setMaxCapacity(int maxCapacity) {
	max_capacity = maxCapacity;
}

void capacity::setFilledCapacity(int filledCapacity) {
	filled_capacity = filledCapacity;
}

capacity::~capacity() {
	// TODO Auto-generated destructor stub
}

void capacity::display() {
	cout<<this->getCenterId()<<" "<<this->getCourseName()<<" "<<this->getMaxCapacity()<<" "<<this->getFilledCapacity()<<endl;
}

const string& capacity::getCourseName() const {
	return course_name;
}

void capacity::setCourseName(const string& courseName) {
	course_name = courseName;
}
