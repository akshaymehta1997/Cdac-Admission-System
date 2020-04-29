/*
 * admissionsystem.h
 *
 *  Created on: 16-Apr-2020
 *      Author: akshay
 */

#include <vector>
#include "capacity.h"
#include "center.h"
#include "course.h"
#include "student.h"

#ifndef ADMISSIONSYSTEM_H_
#define ADMISSIONSYSTEM_H_

class admissionsystem {
private:
	vector<student>l_student;
	vector<course>l_course;
	vector<center>l_center;
	vector<string>l_degree;
	vector<capacity>l_capacity;
	static admissionsystem *ptr;
	admissionsystem();

public:
	~admissionsystem();
	static admissionsystem* get_instance();
	const vector<center>& getCenter() const;
	void setCenter(const vector<center>& center);
	const vector<course>& getCourse() const;
	void setCourse(const vector<course>& course);
	const vector<student>& getStudent() const;
	void setStudent(const vector<student>& student);
	 vector<capacity>& getCapacity() ;
	void setCapacity(const vector<capacity>& capacity);
	const vector<string>& getDegree() const;
	void setDegree(const vector<string>& degree);
	void load_degrees();
	void load_capacities();
	void load_student();
	void load_center();
	void load_eligibility();
	void load_preference();
	void load_courses();
	void load_all_files();
	int list_role();
	int list_student_loginReg();
	int list_student_function();
	int list_admin_function();
	int list_center_coordinator_function();
	void student_registration();
	void display_eligible_courses(student *s,vector<string>*c=NULL);
	void give_preference(student *s);
	void display_allocated_course_center(student *s);
	void update_payment(student *s);
	student* student_login();
	student* find_student(int form_no);
	void displaystudent();
	course* find_course(string course_name);
	void displaycourses();
	center* find_center(string center_id);
	void first_allocation();
	void allocation1(unsigned i,unsigned j);
	void second_allocation();
	static bool comp_student_rankA(const student& s1, const student& s2);
	static bool comp_student_rankB(const student& s1, const student& s2);
	static bool comp_student_rankC(const student& s1, const student& s2);
	static bool comp_prefernces_prefno(const preference& p1,const preference& p2);
	void sort_stutents_preference();
	void displaycenter();
	void save_prefernce();
	void save_student();
	void save_capacity();
	void save_all_files();
	bool admin_login();
	void display_allocated_students();
	void display_paid_students();
	void display_reported_students();
	void update_rank();
	center* center_coordinator_login();
	void display_center_courses(center *c);
	void disply_center_students(center *c);
	static bool compare_student_admin(const student& s1, const student& s2);
	void generate_pnr();
	void display_admitted_students(center*c=NULL);
	void update_reported_status(center *c);

};


#endif /* ADMISSIONSYSTEM_H_ */
