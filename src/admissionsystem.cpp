/*
 * admissionsystem.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: akshay
 */
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "admissionsystem.h"
#include <iomanip>

admissionsystem* admissionsystem::ptr=NULL;

admissionsystem::admissionsystem() {
	// TODO Auto-generated constructor stub
}

const vector<center>& admissionsystem::getCenter() const {
	return l_center;
}

void admissionsystem::setCenter(const vector<center>& center) {
	l_center = center;
}

const vector<course>& admissionsystem::getCourse() const {
	return l_course;
}

void admissionsystem::setCourse(const vector<course>& course) {
	l_course = course;
}

const vector<student>& admissionsystem::getStudent() const {
	return l_student;
}

vector<capacity>& admissionsystem::getCapacity()  {
	return l_capacity;
}

void admissionsystem::setCapacity(const vector<capacity>& capacity) {
	l_capacity = capacity;
}

const vector<string>& admissionsystem::getDegree() const {
	return l_degree;
}

void admissionsystem::setDegree(const vector<string>& degree) {
	l_degree = degree;
}

void admissionsystem::setStudent(const vector<student>& student) {
	l_student = student;
}

admissionsystem::~admissionsystem() {
	// TODO Auto-generated destructor stub
}

admissionsystem* admissionsystem::get_instance() {
	if(ptr==NULL)
	{
		ptr=new admissionsystem;
	}
	return ptr;
}

void admissionsystem::load_degrees() {
	//open degrees.txt
	ifstream fp;
	fp.open("./data-files/degrees.txt");
	if(!fp)
	{
		perror("failed to open degrees file");
		return;
	}
	// read line by line
	string line;
	while(getline(fp,line))
		//add line in vector l_degree
		this->l_degree.push_back(line);
	fp.close();
}

void admissionsystem::load_capacities() {
	//open capacities.txt
	ifstream fp;
	fp.open("./data-files/capacities.csv");
	if(!fp)
	{
		perror("failed to open capacities file");
		return;
	}
	// read line by line
	string line;
	while(getline(fp,line))
	{
		// each line split tokens
		stringstream str(line);
		string tokens[4];
		for (int i = 0; i < 4; ++i) {
			getline(str,tokens[i],',');
		}
		// put tokens in capacity object
		capacity c(tokens[0],tokens[1],stoi(tokens[2]),stoi(tokens[3]));
		// add capacity c in vector
		l_capacity.push_back(c);
		course *co=find_course(c.getCourseName());
		co->getLcenter()[c.getCenterId()]=l_capacity.size()-1;
		center *ce=find_center((c.getCenterId()));
		ce->getLcourse()[c.getCourseName()]=l_capacity.size()-1;
	}
	fp.close();
}

void admissionsystem::load_student() {
	//open students.txt
	ifstream fp;
	fp.open("./data-files/students.csv");
	if(!fp)
	{
		perror("failed to open students file");
		return;
	}
	// read line by line
	string line;
	while(getline(fp,line))
	{
		// each line split tokens
		stringstream str(line);
		string tokens[13];
		for (int i = 0; i < 13; ++i) {
			getline(str,tokens[i],',');
		}
		// put tokens in capacity object
		student s(stoi(tokens[0]),tokens[1],stoi(tokens[2]),stoi(tokens[3]),stoi(tokens[4]),
				tokens[5],stof(tokens[6]),stoi(tokens[7]),tokens[8],tokens[9],
				stof(tokens[10]),stoi(tokens[11]),tokens[12]);
		// add student s in vector
		this->l_student.push_back(s);
	}
	fp.close();
}

void admissionsystem::load_center() {
	//open centers.txt
	ifstream fp;
	fp.open("./data-files/centers.csv");
	if(!fp)
	{
		perror("failed to open centers file");
		return;
	}
	// read line by line
	string line;
	while(getline(fp,line))
	{
		// each line split tokens
		stringstream str(line);
		string tokens[5];
		for (int i = 0; i < 5; ++i) {
			getline(str,tokens[i],',');
		}
		// put tokens in center object
		center c(tokens[0],tokens[1],tokens[2],tokens[3],tokens[4]);
		// add center c in vector
		this->l_center.push_back(c);
	}
	fp.close();
}

void admissionsystem::load_courses() {
	//open courses.txt
	ifstream fp;
	fp.open("./data-files/courses.csv");
	if(!fp)
	{
		perror("failed to open course file");
		return;
	}
	// read line by line
	string line;
	while(getline(fp,line))
	{
		// each line split tokens
		stringstream str(line);
		string tokens[4];
		for (int i = 0; i < 4; ++i) {
			getline(str,tokens[i],',');
		}
		// put tokens in courses object
		course c(stoi(tokens[0]),tokens[1],stoi(tokens[2]),tokens[3]);
		// add course c in vector
		this->l_course.push_back(c);
	}
	fp.close();
}

void admissionsystem::load_eligibility() {
	//open eligibility.txt
	ifstream fp;
	fp.open("./data-files/eligibilities.csv");
	if(!fp)
	{
		perror("failed to open eligibility file");
		return;
	}
	// read line by line
	string line;
	while(getline(fp,line))
	{
		// each line split tokens
		stringstream str(line);
		string tokens[3];
		for (int i = 0; i < 3; ++i) {
			getline(str,tokens[i],',');
		}
		// put tokens in eligibility object
		eligibility e(tokens[0],tokens[1],stof(tokens[2]));
		// add eligibility e in corresponding course's eligibility vector
		course *c=find_course(e.getCourseName());
		c->getvectorEligibility().push_back(e);
	}
	fp.close();
}

void admissionsystem::load_preference() {
	//open eligibility.txt
	ifstream fp;
	fp.open("./data-files/preferences.csv");
	if(!fp)
	{
		perror("failed to open preference file");
		return;
	}
	// read line by line
	string line;
	while(getline(fp,line))
	{
		// each line split tokens
		stringstream str(line);
		string tokens[4];
		for (int i = 0; i < 4; ++i) {
			getline(str,tokens[i],',');
		}
		// put tokens in preference object
		preference p(stoi(tokens[0]),stoi(tokens[1]),tokens[2],tokens[3]);
		// add preference p in corresponding student's preference vector
		student *s=find_student(p.getFormNo());
		s->getLpref().push_back(p);
	}
	fp.close();
}

student* admissionsystem::find_student(int form_no) {
	unsigned i;
	for(i=0; i<l_student.size(); i++) {
		if(l_student[i].getFormNo() == form_no)
			return &l_student[i];
	}
	return NULL;
}

course* admissionsystem::find_course(string course_name) {
	unsigned i;
	for(i=0; i<l_course.size(); i++) {
		if(0==course_name.compare(l_course[i].getName()))
			return &l_course[i];
	}
	return NULL;
}

center* admissionsystem::find_center(string center_id) {
	unsigned i;
	for(i=0; i<l_center.size(); i++) {
		if(0==center_id.compare(l_center[i].getId()))
			return &l_center[i];
	}
	return NULL;
}

void admissionsystem::displaystudent() {
	vector<student>::const_iterator itr=this->getStudent().cbegin();
	vector<preference>::iterator itr1;
	while(itr!=this->getStudent().cend())
	{
		student s=*itr;
		s.display();
		itr1=s.getLpref().begin();
		while(itr1!=s.getLpref().end())
		{
			itr1->display();
			itr1++;
		}
		cout<<endl;
		itr++;
	}
}

void admissionsystem::displaycourses() {
	for(unsigned i=0; i<l_course.size(); i++) {
		l_course[i].display();
		vector<eligibility>::iterator itr1=l_course[i].getvectorEligibility().begin();
		while(itr1!=l_course[i].getvectorEligibility().end())
		{
			itr1->display();
			itr1++;
		}
	}
	cout << endl;

}

void admissionsystem::displaycenter() {
	//sort(l_center.begin(),l_center.end(),sort_name);
	cout<<"\nList of Centers are as follows:"
			<<setw(70)<<setfill('-')<<endl;
	for(unsigned i=0; i<l_center.size(); i++) {
		cout<<"\n"<<i+1<<". ";
		l_center[i].display();
		l_center[i].display_courses();
	}
}

void admissionsystem::first_allocation() {
	unsigned i,j;
	for (j = 0; j < 10; j++)
	{
		//Sort by RankA
		sort(l_student.begin(),l_student.end(),comp_student_rankA);
		//Allocation of ccat Section A
		for (i = 0; i < l_student.size(); i++)
		{
			if(l_student[i].getLpref().size()>j && l_student[i].getPayment()!=-1 && l_student[i].getAlloPref()==0)
			{
				course *c=find_course(l_student[i].getLpref()[j].getCourseName());
				//condition for Section B and if test has been given
				if(!c->getCcatSection().compare("A")&&l_student[i].getRankA()!=-1)
					allocation1(i,j);
			}
		}
		//Sort by RankB
		sort(l_student.begin(),l_student.end(),comp_student_rankB);
		//Allocation of ccat Section B
		for (i = 0; i < l_student.size(); i++)
		{
			if(l_student[i].getLpref().size()>j && l_student[i].getPayment()!=-1 && l_student[i].getAlloPref()==0)
			{
				course *c=find_course(l_student[i].getLpref()[j].getCourseName());
				//condition for Section B and if test has been given
				if(!c->getCcatSection().compare("B")&&(l_student[i].getRankB()!=-1))
					allocation1(i,j);
			}
		}
		//Sort by RankC
		sort(l_student.begin(),l_student.end(),comp_student_rankC );
		//Allocation of ccat Section C
		for (i = 0; i < l_student.size(); i++)
		{
			if(l_student[i].getLpref().size()>j && l_student[i].getPayment()!=-1 && l_student[i].getAlloPref()==0)
			{
				course *c=find_course(l_student[i].getLpref()[j].getCourseName());
				//condition for Section B and if test has been given
				if(!c->getCcatSection().compare("C")&& l_student[i].getRankC()!=-1)
					allocation1(i,j);
			}
		}
	}
}


void admissionsystem::allocation1(unsigned i,unsigned j) {
	center *c=find_center(l_student[i].getLpref()[j].getCenterId());
	int a=c->getLcourse()[l_student[i].getLpref()[j].getCourseName()];
	if(l_capacity[a].getFilledCapacity()<l_capacity[a].getMaxCapacity())
	{
		int filled=l_capacity[a].getFilledCapacity();
		l_capacity[a].setFilledCapacity(++filled);
		l_student[i].setAlloCourseName(l_student[i].getLpref()[j].getCourseName());
		l_student[i].setAlloPref(j+1);
		l_student[i].setCenterId(l_student[i].getLpref()[j].getCenterId());
		l_student[i].display();
		l_student[i].getLpref()[j].display();
	}
}

void admissionsystem::second_allocation() {
	unsigned i;
	for (i = 0; i < l_student.size(); i++)
	{
		if(l_student[i].getAlloPref()!=0)
		{
			center *c=find_center(l_student[i].getCenterId());
			int a=c->getLcourse()[l_student[i].getAlloCourseName()];
			int filled=l_capacity[a].getFilledCapacity();
			l_capacity[a].setFilledCapacity(--filled);
			l_student[i].setAlloCourseName("NA");
			l_student[i].setCenterId("NA");
			l_student[i].setAlloPref(0);
			if(l_student[i].getPayment()==0)
			{
				l_student[i].setPayment(-1);
			}
		}
	}
	first_allocation();
}

bool admissionsystem::comp_student_rankA(const student& s1, const student& s2) {
	return s1.getRankA()<s2.getRankA();
}

bool admissionsystem::comp_student_rankB(const student& s1, const student& s2) {
	return s1.getRankB()<s2.getRankB();
}

bool admissionsystem::comp_student_rankC(const student& s1, const student& s2) {
	return s1.getRankC()<s2.getRankC();
}

bool admissionsystem::comp_prefernces_prefno(const preference& p1,const preference& p2) {
	return p1.getPreferenceNo()<p2.getPreferenceNo();
}

void admissionsystem::sort_stutents_preference() {
	for(unsigned i = 0; i < l_student.size(); ++i)
		sort(l_student[i].getLpref().begin(),l_student[i].getLpref().end(),comp_prefernces_prefno);
}

void admissionsystem::save_prefernce() {
	ofstream fp;
	unsigned i,j;
	fp.open("./alloc1/prefernces.csv");
	if(!fp) {
		perror("failed to open preference file");
		return;
	}

	for(i=0; i<l_student.size(); i++) {
		for(j=0;j<l_student[i].getLpref().size();j++)
		{
			fp <<l_student[i].getLpref()[j].getFormNo() << ","
					<< l_student[i].getLpref()[j].getFormNo() << ","
					<< l_student[i].getLpref()[j].getCourseName() << ","
					<< l_student[i].getLpref()[j].getCenterId() <<endl;
		}
	}
	fp.close();
	cout << "Preferences saved." << endl;
}

void admissionsystem::save_student() {
	ofstream fp;
	unsigned i;
	fp.open("./alloc1/students.csv");
	if(!fp) {
		perror("failed to open students file");
		return;
	}

	for(i=0; i<l_student.size(); i++) {
		fp <<l_student[i].getFormNo() << ","
				<< l_student[i].getStudentName() << ","
				<< l_student[i].getRankA() << ","
				<< l_student[i].getRankB() << ","
				<< l_student[i].getRankC()<< ","
				<< l_student[i].getDegree()<< ","
				<< l_student[i].getDegreeMarks() << ","
				<< l_student[i].getAlloPref()<< ","
				<< l_student[i].getAlloCourseName()<< ","
				<< l_student[i].getCenterId() << ","
				<< l_student[i].getPayment()<< ","
				<< l_student[i].getReported()<< ","
				<< l_student[i].getPrn()<<endl;
	}
	fp.close();
	cout << "Students saved." << endl;
}

void admissionsystem::save_capacity() {
	ofstream fp;
	unsigned i;
	fp.open("./alloc1/capacity.csv");
	if(!fp) {
		perror("failed to open capacity file");
		return;
	}
	for(i=0; i<l_capacity.size(); i++) {
		fp <<l_capacity[i].getCenterId()<< ","
				<< l_capacity[i].getCourseName() << ","
				<< l_capacity[i].getMaxCapacity() << ","
				<< l_capacity[i].getFilledCapacity()<<endl;
	}
	fp.close();
	cout << "capacities saved." << endl;
}

int admissionsystem::list_role() {
	int choice;
	cout<<"List of roles:\n "
			"1.Student\n "
			"2.Admin\n "
			"3.Center Coordinator\n "
			"0.Exit\n"
			"Enter index of your role: ";
	cin>>choice;
	cout<<endl;
	return choice;
}

int admissionsystem::list_student_loginReg() {
	int choice;
	cout<<"Login OR Register:\n "
			"1.Register(If new user)\n "
			"2.Sign in\n "
			"0.Exit\n"
			"Enter index: ";
	cin>>choice;
	cout<<endl;
	return choice;
}

int admissionsystem::list_student_function() {
	int choice;
	cout<<"Enter index of function to be used:\n "
			"1.List Courses\n "
			"2.List Centers\n "
			"3.Give Preferences\n "
			"4.See allocated center/course\n "
			"5.Update payment details\n "
			"0.Exit\n"
			"Enter index of function to be used: ";
	cin>>choice;
	cout<<endl;
	return choice;
}

int admissionsystem::list_admin_function() {
	int choice;
	cout<<"List of function:\n"
			"1.List Courses & eligibilities\n "
			"2.List Centers & capacities\n "
			"3.List Students\n "
			"4.Update Student Rank\n "
			"5.Allocate centers (Round 1)\n "
			"6.Allocate centers (Round 2)\n "
			"7List allocated students\n "
			"8.List paid students\n "
			"9.List reported (at center) students/n "
			"10.Generate PRN\n "
			"11.List admitted students (with PRN) for given center\n "
			"0.Exit\n"
			"Enter index of function to be used:\n ";
	cin>>choice;
	cout<<endl;
	return choice;
}

int admissionsystem::list_center_coordinator_function() {
	int choice;
	cout<<"List of function:\n"
			"1.List Courses\n "
			"2.List Centers & capacities\n "
			"3.List Students\n "
			"4.Update Student Rank\n "
			"0.Exit\n"
			"Enter index of function to be used:\n ";
	cin>>choice;
	cout<<endl;
	return choice;
}

void admissionsystem::load_all_files() {
	load_student();
	load_preference();
	load_center();
	load_courses();
	load_eligibility();
	load_capacities();
	load_degrees();
}

void admissionsystem::save_all_files() {
	save_prefernce();
	save_student();
	save_capacity();
}

void admissionsystem::student_registration() {
	cout<<"Enter Your Name:";
	string name;
	cin>>name;
	cout<<"\nList of Degrees are as follows:"<<endl;
	for(unsigned i=4;i<l_degree.size();i++)
		cout<<i-3<<". "<<l_degree[i]<<endl;
	cout<<"Enter Sr. No. of degree you earned from above:";
	int index,rankA=-1,rankB=-1,rankC=-1;
	cin>>index;
	cout<<"Enter Percentage you achieved in "<<l_degree[index+3]<<":";
	float percent;
	cin>>percent;
	if(percent<50)
	{
		cout<<"\nYou are not eligible for CCAT exam as you have percentage less than 50%"<<endl;
		return;
	}
	cout<<"Which section exam you are applying for [A/B/C]: ";
	string section;
	if(!section.compare("C"))
		rankC=rankB=rankA=0;
	else if(!section.compare("B"))
		rankB=rankA=0;
	else rankA=0;
	student s(l_student.size()+1,name,rankA,rankB,rankC,l_degree[index+3],percent,0,"NA","NA",0,0,"NA");
	cout<<"Your data is"<<endl;
	s.display();
	cout<<"Want to save data press y or if u don't want to save data press n [y/n]:";
	string save;
	cin>>save;
	if(!save.compare("y")){
		l_student.push_back(s);
		cout<<name<<"'s data has been saved\n\n"
				"PLEASE REMEBER YOUR CREDENTIALS GIVEN BELOW\n"
				"User ID : "<<l_student.size()<<
				"\nPassword : "<<name<<endl;
	}
}

student* admissionsystem::student_login() {
	cout<<"Enter User ID";
	int u_id;
	label:
	cin>>u_id;
	student *s=find_student(u_id);
	if(s==NULL)
	{
		cout<<"are u a new user?y for yes n for no[y/n]";
		string flag;
		cin>>flag;
		if(!flag.compare("y"))
			return NULL;
		cout<<"User ID entered was not found \n\nEnter appropriate id again:";
		goto label;
	}
	cout<<"Enter Password";
	string pass;
	cin>>pass;
	if(s->getStudentName().compare(pass))
	{
		cout<<"Password entered was wrong"<<endl;
		return NULL;
	}
	return s;
}

void admissionsystem::display_eligible_courses(student* s,vector<string>*c) {
	cout<<"\nList of Courses in which you are eligible are as follows:"
			<<setw(70)<<setfill('-')<<endl;
	int SrNo=1;
	for(unsigned i=0;i<l_course.size();i++)
	{
		for(unsigned j=0;j<l_course[i].getvectorEligibility().size();j++)
		{
			if(!l_course[i].getvectorEligibility()[j].getDegree().compare(s->getDegree()) && l_course[i].getvectorEligibility()[j].getMinPercent()<=s->getDegreeMarks())
			{
				cout<<"\n"<<SrNo++<<". ";
				l_course[i].display();
				if(c!=NULL)
					c->push_back(l_course[i].getName());
			}
		}
	}
}

void admissionsystem::give_preference(student* s) {
	for (int i = s->getLpref().size()+1; i <= 10; ++i) {
		vector<string>course;
		display_eligible_courses(s,&course);
		cout<<"Enter Sr. No. of course you want to choose";
		int course_index;
		cin>>course_index;
		vector<center>center;
		int SrNo=1;
		cout<<"\nList of Courses in which you are eligible are as follows:"
				<<setw(70)<<setfill('-')<<endl;
		for(unsigned i=0;i<l_center.size();i++)
		{
			map<string,int>::iterator itr=l_center[i].getLcourse().begin();
			while(itr!=l_center[i].getLcourse().end())
			{
				if(!itr->first.compare(course[course_index-1]))
				{
					cout<<"\n"<<SrNo++<<". "<<l_center[i].getName();
					center.push_back(l_center[i]);
				}
				itr++;
			}
		}
		cout<<"\nEnter Sr. No. of center you want to choose";
		int center_index;
		cin>>center_index;
		preference p(s->getFormNo(),i,course[course_index-1],center[center_index-1].getId());
		cout<<endl;
		p.display();
		cout<<"Want to save data press y or if u don't want to save data press n [y/n]:";
		string save;
		cin>>save;
		if(!save.compare("y")){
			s->getLpref().push_back(p);
			cout<<s->getStudentName()<<"'s preference has been saved\n\n";
		}
		if(s->getLpref().size()<10)
		{
			cout<<"Want to add more preferences[y/n]";
			string status;
			cin>>status;
			if(status.compare("y"))
				return;
		}
	}
}

void admissionsystem::display_allocated_course_center(student* s) {
	if(s->getAlloPref()==0)
		cout<<"Your have not been allocated still"<<endl;
	else{
		course *c=find_course(s->getAlloCourseName());
		cout<<"Allocated center : "<<c->getName()<<endl;
		cout<<"Allocated course : "<<s->getAlloCourseName()<<endl;
	}
}

void admissionsystem::update_payment(student* s) {
	string status;
	float payment=s->getPayment();
	cout<<"Payment Done till now : "<<payment<<endl;
	if(payment==0)
	{

		cout<<"Pay your first installment 11800 Rs"<<endl;
		cout<<"y for yes n for no";
		cin>>status;
		if(status.compare("y"))
		{
			s->setPayment(11800);
		}
	}
	else if(payment==11800)
	{
		course *c=find_course(s->getAlloCourseName());
		cout<<"Pay your remaining fee "<<c->getFees()-11800<<" Rs."<<endl;
		cout<<"y for yes n for no";
		cin>>status;
		if(status.compare("y"))
		{
			s->setPayment(11800);
		}
	}
}

bool admissionsystem::admin_login() {
	cout<<"Enter UserID : ";
	string u_id,pass;
	label:
	cin>>u_id;
	if(u_id.compare("admin"))
	{
		cout<<"User ID entered was not found \n\nEnter appropriate id again:";
		goto label;
	}
	cout<<"Enter Password : ";
	cin>>pass;
	if(!pass.compare("admin"))
	{
		cout<<"Password entered was wrong"<<endl;
		return false;
	}
	return true;
}

void admissionsystem::display_allocated_students() {
	sort(l_student.begin(),l_student.end(),compare_student_admin);
	vector<student>::const_iterator itr=this->getStudent().cbegin();
	while(itr!=this->getStudent().cend())
	{
		student s=*itr;
		if(s.getAlloPref()!=0)
		{	s.display();
		cout<<endl;
		}
		itr++;
	}
}

void admissionsystem::display_paid_students() {
	sort(l_student.begin(),l_student.end(),compare_student_admin);
	vector<student>::const_iterator itr=this->getStudent().cbegin();
	while(itr!=this->getStudent().cend())
	{
		student s=*itr;
		if(s.getPayment()!=0)
			s.display();
		cout<<endl;
		itr++;
	}
}


void admissionsystem::display_reported_students() {
	sort(l_student.begin(),l_student.end(),compare_student_admin);
	vector<student>::const_iterator itr=this->getStudent().cbegin();
	while(itr!=this->getStudent().cend())
	{
		student s=*itr;
		if(s.getReported()!=0)
			s.display();
		cout<<endl;
		itr++;
	}
}

void admissionsystem::generate_pnr() {
	sort(l_student.begin(),l_student.end(),compare_student_admin);
	int SrNo=1;
	for(unsigned i=0;i<l_student.size();i++)
	{
		if(i!=0 && l_student[i-1].getCenterId().compare(l_student[i].getCenterId()))
			SrNo=1;
		course *c=find_course(l_student[i].getAlloCourseName());
		if(l_student[i].getReported()!=0 && c->getFees()==l_student[i].getPayment())
		{
			string prn=l_student[i].getAlloCourseName()+l_student[i].getCenterId()+to_string(SrNo++);
			l_student[i].setPrn(prn);
			l_student[i].display();
		}
	}
}

center* admissionsystem::center_coordinator_login() {
	cout<<"Enter User ID";
	string u_id;
	label:
	cin>>u_id;
	center *c=find_center(u_id);
	if(c==NULL)
	{
		cout<<"are u a new user?y for yes n for no[y/n]";
		string flag;
		cin>>flag;
		if(!flag.compare("y"))
			return NULL;
		cout<<"User ID entered was not found \n\nEnter appropriate id again:";
		goto label;
	}
	cout<<"Enter Password";
	string pass;
	cin>>pass;
	if(c->getPassword().compare(pass))
	{
		cout<<"Password entered was wrong"<<endl;
		return NULL;
	}
	return c;
}

void admissionsystem::display_center_courses(center *c) {
	int SrNo=1;
	map<string,int>::iterator itr=c->getLcourse().begin();
	while(itr!=c->getLcourse().end())
	{
		course *co=find_course(itr->first);
		cout<<"\n"<<SrNo++<<". "<<co->getName();
		itr++;
	}
}

void admissionsystem::disply_center_students(center* c) {
	vector<student>::const_iterator itr=this->getStudent().cbegin();
	while(itr!=this->getStudent().cend())
	{
		student s=*itr;
		if(!s.getCenterId().compare(c->getId()))
			s.display();
		cout<<endl;
		itr++;
	}
}

void admissionsystem::update_rank() {
	cout<<"Enter form number : ";
	int form_no,rankA,rankB,rankC;
	cin>>form_no;
	student *s=find_student(form_no);
	cout<<"Student details of that form number is : ";
	s->display();
	if(s->getRankC()==0)
	{
		cout<<"Enter Rank in Section A : ";
		cin>>rankA;
		s->setRankA(rankA);
		cout<<"Enter Rank in Section A & B : ";
		cin>>rankB;
		s->setRankB(rankB);
		cout<<"Enter Rank in Section A & B &C : ";
		cin>>rankC;
		s->setRankB(rankC);
	}
	else if(s->getRankB()==0)
	{
		cout<<"Enter Rank in Section A : ";
		cin>>rankA;
		s->setRankA(rankA);
		cout<<"Enter Rank in Section A & B : ";
		cin>>rankB;
		s->setRankB(rankB);
	}
	else if(s->getRankA()==0)
	{
		cout<<"Enter Rank in Section A : ";
		cin>>rankA;
		s->setRankA(rankA);
	}
	else
	{
		cout<<"Rank already present"<<endl;
	}
}

bool admissionsystem::compare_student_admin(const student& s1, const student& s2) {
	if(s1.getAlloCourseName().compare(s2.getAlloCourseName()))
		return s1.getAlloCourseName().compare(s2.getAlloCourseName())<0;

	if(s1.getCenterId().compare(s2.getCenterId()))
		return s1.getCenterId().compare(s2.getCenterId())<0;

	return s1.getStudentName().compare(s2.getStudentName())<0;
}

void admissionsystem::display_admitted_students(center* c) {
	string c_id,c_name;
	if(c==NULL)
	{
		cout<<"Center Id : ";
		cin>>c_id;
	}
	else {
		c_id=c->getId();
	}
	cout<<"Enter course name : ";
	cin>>c_name;
	for(unsigned i=0;i<l_student.size();i++)
	{
		if(!l_student[i].getAlloCourseName().compare(c_name) && !l_student[i].getCenterId().compare(c_id))
		{
			l_student[i].display();
		}
	}
}

void admissionsystem::update_reported_status(center* c) {
	sort(l_student.begin(),l_student.end(),compare_student_admin);
	int form_no;
	cout<<"Enter Form_no: ";
	cin>>form_no;
	for(unsigned i=0; i<l_student.size(); i++){
		if(l_student[i].getFormNo()==form_no && !c->getId().compare(l_student[i].getCenterId())){
			l_student[i].display();
			l_student[i].setReported(1);
			return;
		}
	}
	cout<<"Indicating Student is not allocated to this center.";
}
