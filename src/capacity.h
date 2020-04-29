/*
 * capacity.h
 *
 *  Created on: 17-Apr-2020
 *      Author: akshay
 */
#include <iostream>
using namespace std;
#ifndef CAPACITY_H_
#define CAPACITY_H_

class capacity {
private:
	string center_id,course_name;
	int max_capacity,filled_capacity;
public:
	capacity();
	capacity(string center_id,string course_name,int max_capacity,int filled_capacity);
	~capacity();

	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	int getFilledCapacity() const;
	void setFilledCapacity(int filledCapacity);
	int getMaxCapacity() const;
	void setMaxCapacity(int maxCapacity);
	void display();
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
};

#endif /* CAPACITY_H_ */
