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
					break;
				case 2://Sign IN
					student *s;
					s=a->student_login();
					if(s==NULL)
						break;
					while((choice=a->list_student_function())!=0)
						switch (choice) {
						case 1://list courses(as per eligibility)
							a->display_eligible_courses(s);
							break;
						case 2://list centers
							a->displaycenter();
							break;
						case 3://Give preferences
							a->give_preference(s);
							break;
						case 4://See allocated center/course
							a->display_allocated_course_center(s);
							break;
						case 5://Update payment details
							a->update_payment(s);
							break;
						default:
							cout<<"Enter appropriate index";
							break;
						}
					break;
						default:
							cout<<"Enter appropriate index";
							break;
				}
			}
			break;
		case 2://admin
			while((choice=a->list_admin_function())!=0)
			{
				bool login=a->admin_login();
				if(login==false)
					break;
				switch (choice) {
				case 1://List courses & eligibilities
					a->displaycourses();
					break;

				case 2://List centers & capacities
					a->displaycenter();
					break;

				case 3://List Students
					a->displaystudent();
					break;

				case 4://Update student ranks
					a->update_rank();
					break;

				case 5://Allocate centers(round 1)
					a->first_allocation();
					break;

				case 6://Allocate centers(round 2)
					a->second_allocation();
					break;

				case 7://List allocated students
					a->display_allocated_students();
					break;

				case 8://List paid students
					a->display_paid_students();
					break;

				case 9://list reported(at center)students
					a->display_reported_students();
					break;

				case 10://Generate PRN
					a->generate_pnr();
					break;

				case 11://List admitted students (with PRN) for given center
					a->display_admitted_students();
					break;
				default:
					cout<<"Enter appropriate index";
					break;
				}
			}
			break;
		case 3://Center coordinator
			center *c;
			c=a->center_coordinator_login();
			if(c==NULL)
				break;
			while((choice=a->list_center_coordinator_function())!=0)
			{
				switch (choice) {
				case 1://List courses
					a->display_center_courses(c);
					break;

				case 2://List Students
					a->disply_center_students(c);
					break;

				case 3://Update reported status

					break;

				case 4://List admitted students (with PRN)
					a->display_admitted_students(c);
					break;
				default:
					cout<<"Enter appropriate index";
					break;
				}
			}
		}
	}
	a->save_all_files();
	return 0;
}
