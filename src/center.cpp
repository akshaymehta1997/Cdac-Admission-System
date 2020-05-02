/*
 * center.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: akshay
 */

#include "center.h"
#include "admissionsystem.h"

center::center() {
	this->setAddress(" ");
	this->setCoordinator(" ");
	this->setId(" ");
	this->setName(" ");
	this->setPassword(" ");

}

const string& center::getAddress() const {
	return address;
}

void center::setAddress(const string& address) {
	this->address = address;
}

const string& center::getCoordinator() const {
	return coordinator;
}

void center::setCoordinator(const string& coordinator) {
	this->coordinator = coordinator;
}


const string& center::getId() const {
	return id;
}

void center::setId(const string& id) {
	this->id = id;
}

const string& center::getName() const {
	return name;
}

void center::setName(const string& name) {
	this->name = name;
}

const string& center::getPassword() const {
	return password;
}

void center::setPassword(const string& password) {
	this->password = password;
}

center::~center() {
	// TODO Auto-generated destructor stub
}

center::center(string id, string name, string address, string coordinator,
		string password) {
	this->setAddress(address);
	this->setCoordinator(coordinator);
	this->setId(id);
	this->setName(name);
	this->setPassword(password);
}

map<string, int>& center::getLcourse()  {
	return lcourse;
}

void center::setLcourse(const map<string, int>& lcourse) {
	this->lcourse = lcourse;
}

void center::display() {
	cout<<"Name : "<<name<<"\n   Address : "<<address<<endl;
}

void center::display_courses() {
	map<string,int>::iterator itr=lcourse.begin();
	while(itr!=lcourse.end())
	{	admissionsystem *a=admissionsystem::get_instance();
	cout<<"\tCourse Name : "<<itr->first<<"\tCapacity : ";
	a->getCapacity()[itr->second].display();
	itr++;
	}
}
