/*
 * center.h
 *
 *  Created on: 16-Apr-2020
 *      Author: akshay
 */
#include <vector>
#include <iostream>
#include <map>
using namespace std;
#ifndef CENTER_H_
#define CENTER_H_

class center {
private:
	string id,name,address,coordinator,password;
	map<string,int>lcourse;
public:
	center();
	center(string id,string name,string address,string coordinator,string password);
	~center();
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getCoordinator() const;
	void setCoordinator(const string& coordinator);
	const string& getId() const;
	void setId(const string& id);
	const string& getName() const;
	void setName(const string& name);
	const string& getPassword() const;
	void setPassword(const string& password);
	 map<string, int>& getLcourse() ;
	void setLcourse(const map<string, int>& lcourse);
	void display();
	void display_courses();
};

#endif /* CENTER_H_ */
