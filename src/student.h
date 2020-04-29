
/*
 * student.h
 *
 *  Created on: 16-Apr-2020
 *      Author: akshay
 */
#include "preference.h"
#include <vector>
#ifndef STUDENT_H_
#define STUDENT_H_

class student {
private:
	int form_no,rank_a,rank_b,rank_c,reported,allo_pref;
	string student_name,degree,allo_course_name,center_id,prn;
	float degree_marks,payment;
	vector<preference>lpref;
public:
	student();
	student(int form_no,string s_name,int rank_a,int rank_b,int rank_c,string degree,float degree_marks,int allo_pref,string allo_course_name,string center_id,float payment,int reported,string prn);
	~student();
	const string& getAlloCourseName() const;
	void setAlloCourseName(const string& alloCourseName);
	int getAlloPref() const;
	void setAlloPref(int alloPref);
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	int getFormNo() const;
	void setFormNo(int formNo);
	vector<preference>& getLpref() ;
	void setLpref(const vector<preference>& lpref);
	const string& getPrn() const;
	void setPrn(const string& prn);
	int getRankA() const;
	void setRankA(int rankA);
	int getRankB() const;
	void setRankB(int rankB);
	int getRankC() const;
	void setRankC(int rankC);
	int getReported() const;
	void setReported(int reported);
	const string& getStudentName() const;
	void setStudentName(const string& studentName);
	float getDegreeMarks() const;
	void setDegreeMarks(float degreeMarks);
	float getPayment() const;
	void setPayment(float payment);
	const string& getDegree() const;
	void setDegree(const string& degree);
	void display();
};

#endif /* STUDENT_H_ */
