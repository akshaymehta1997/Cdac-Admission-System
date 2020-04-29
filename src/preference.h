/*
 * preference.h
 *
 *  Created on: 17-Apr-2020
 *      Author: akshay
 */
#include <iostream>
using namespace std;
#ifndef PREFERENCE_H_
#define PREFERENCE_H_

class preference {

private:
	int form_no,preference_no;
	string center_id,course_name;

public:
	preference();
	preference(int form_no,int preference,string course_name,string center_id);
	~preference();
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	int getFormNo() const;
	void setFormNo(int formNo);
	int getPreferenceNo() const;
	void setPreferenceNo(int preferenceNo);
	void display();
};

#endif /* PREFERENCE_H_ */
