//============================================================================
// Name        : Cdac.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "admissionsystem.h"
int main() {

	admissionsystem *a=admissionsystem::get_instance();
	a->load_all_files();
	int choice;
	while((choice=a->list_role())!=0)
	{
		switch (choice) {
		case 1://student
			while((choice=a->list_student_loginReg())!=0)
			{
				switch (choice) {
				case 1://Register
					a->student_registration();
					cout<<endl;
					break;
				case 2://Sign IN
					student *s;
					s=a->student_login();
					cout<<endl;
					if(s==NULL)
						break;
					while((choice=a->list_student_function())!=0)
						switch (choice) {
						case 1://list courses(as per eligibility)
							a->display_eligible_courses(s);
							cout<<endl;
							break;
						case 2://list centers
							a->displaycenter();
							cout<<endl;
							break;
						case 3://Give preferences
							a->give_preference(s);
							cout<<endl;
							break;
						case 4://See allocated center/course
							a->display_allocated_course_center(s);
							cout<<endl;
							break;
						case 5://Update payment details
							a->update_payment(s);
							cout<<endl;
							break;
						default:
							cout<<"Enter appropriate index";
							cout<<endl;
							break;
						}
					break;
						default:
							cout<<"Enter appropriate index";
							cout<<endl;
							break;
				}
			}
			break;
		case 2://admin
			if(a->admin_login()==false)
				break;
			cout<<endl;
			while((choice=a->list_admin_function())!=0)
			{
				switch (choice) {
				case 1://List courses & eligibilities
					a->displaycourses();
					cout<<endl;
					break;

				case 2://List centers & capacities
					a->displaycentercourses();
					cout<<endl;
					break;

				case 3://List Students
					a->displaystudent();
					cout<<endl;
					break;

				case 4://Update student ranks
					a->update_rank();
					cout<<endl;
					break;

				case 5://Allocate centers(round 1)
					a->first_allocation();
					cout<<endl;
					break;

				case 6://Allocate centers(round 2)
					a->second_allocation();
					cout<<endl;
					break;

				case 7://List allocated students
					a->display_allocated_students();
					cout<<endl;
					break;

				case 8://List paid students
					a->display_paid_students();
					cout<<endl;
					break;

				case 9://list reported(at center)students
					a->display_reported_students();
					cout<<endl;
					break;

				case 10://Generate PRN
					a->generate_pnr();
					cout<<endl;
					break;

				case 11://List admitted students (with PRN) for given center
					a->display_admitted_students();
					cout<<endl;
					break;
				default:
					cout<<"Enter appropriate index";
					cout<<endl;
					break;
				}
			}
			break;
		case 3://Center coordinator
			center *c;
			c=a->center_coordinator_login();
			if(c==NULL)
				break;
			cout<<endl;
			while((choice=a->list_center_coordinator_function())!=0)
			{
				switch (choice) {
				case 1://List courses
					a->display_center_courses(c);
					cout<<endl;
					break;

				case 2://List Students
					a->disply_center_students(c);
					cout<<endl;
					break;

				case 3://Update reported status
					a->update_reported_status(c);
					cout<<endl;
					break;

				case 4://List admitted students (with PRN)
					a->display_admitted_students(c);
					cout<<endl;
					break;
				default:
					cout<<"Enter appropriate index";
					cout<<endl;
					break;
				}
			}
		}
	}
	a->save_all_files();
	return 0;
}
