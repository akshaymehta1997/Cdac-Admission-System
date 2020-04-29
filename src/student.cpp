/*
 * student.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: akshay
 */

#include "student.h"
student::student() {
	this->setAlloCourseName(" ");
	this->setAlloPref(0);
	this->setCenterId(" ");
	this->setDegree(" ");
	this->setDegreeMarks(0);
	this->setFormNo(0);
	this->setPayment(0);
	this->setPrn(" ");
	this->setRankA(0);
	this->setRankB(0);
	this->setRankC(0);
	this->setReported(0);
	this->setStudentName(" ");
}

const string& student::getAlloCourseName() const {
	return allo_course_name;
}

void student::setAlloCourseName(const string& alloCourseName) {
	allo_course_name = alloCourseName;
}

int student::getAlloPref() const {
	return allo_pref;
}

void student::setAlloPref(int alloPref) {
	allo_pref = alloPref;
}

const string& student::getCenterId() const {
	return center_id;
}

void student::setCenterId(const string& centerId) {
	center_id = centerId;
}

int student::getFormNo() const {
	return form_no;
}

void student::setFormNo(int formNo) {
	form_no = formNo;
}

vector<preference>& student::getLpref()  {
	return lpref;
}

void student::setLpref(const vector<preference>& lpref) {
	this->lpref = lpref;
}

const string& student::getPrn() const {
	return prn;
}

void student::setPrn(const string& prn) {
	this->prn = prn;
}

int student::getRankA() const {
	return rank_a;
}

void student::setRankA(int rankA) {
	rank_a = rankA;
}

int student::getRankB() const {
	return rank_b;
}

void student::setRankB(int rankB) {
	rank_b = rankB;
}

int student::getRankC() const {
	return rank_c;
}

void student::setRankC(int rankC) {
	rank_c = rankC;
}

int student::getReported() const {
	return reported;
}

void student::setReported(int reported) {
	this->reported = reported;
}

const string& student::getStudentName() const {
	return student_name;
}

void student::setStudentName(const string& studentName) {
	student_name = studentName;
}

student::~student() {
	// TODO Auto-generated destructor stub
}

student::student(int form_no,string s_name,int rank_a,int rank_b,int rank_c,string degree,float degree_marks,int allo_pref,string allo_course_name,string center_id,float payment,int reported,string prn) {
	this->setAlloCourseName(allo_course_name);
	this->setAlloPref(allo_pref);
	this->setCenterId(center_id);
	this->setDegree(degree);
	this->setDegreeMarks(degree_marks);
	this->setFormNo(form_no);
	this->setPayment(payment);
	this->setPrn(prn);
	this->setRankA(rank_a);
	this->setRankB(rank_b);
	this->setRankC(rank_c);
	this->setReported(reported);
	this->setStudentName(s_name);
}

void student::display() {
	cout<<"\n-----------------------------------------------------------"
			<<"\nForm Number : "<<form_no
			<<"\nName : "<<student_name
			<<"\nRank in Section A : "<<rank_a
			<<"\nRank in Section B : "<<rank_b
			<<"\nRank in Section C : "<<rank_c
			<<"\nDegree Achieved : "<<degree
			<<"\nPercentage in "<<degree<<" : "<<degree_marks
			<<"\nAllocated Preference : "<<allo_pref
			<<"\nAllocated Course Name : "<<allo_course_name
			<<"\nAllocated Center Id : "<<center_id
			<<"\nPaid : "<<payment<<" Rs"
			<<"\nReported : "<<reported
			<<"\nPrn : "<<prn
			<<"\n-----------------------------------------------------------"<<endl;
}


float student::getDegreeMarks() const {
	return degree_marks;
}

void student::setDegreeMarks(float degreeMarks) {
	degree_marks = degreeMarks;
}

float student::getPayment() const {
	return payment;
}

const string& student::getDegree() const {
	return degree;
}

void student::setDegree(const string& degree) {
	this->degree = degree;
}

void student::setPayment(float payment) {
	this->payment = payment;
}

