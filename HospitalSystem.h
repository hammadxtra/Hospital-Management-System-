#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Files Name 
const string patientFile = "Patients_Record.txt";
const string doctorFile = "Doctors_Record.txt";
const string adminFile = "Admin_Record.txt";
const string apptFile = "Appointments_Record.txt";
const string roomFile = "Rooms_Record.txt";
const string recordFile = "Medical_Records.txt";
const string billFile = "Bills_Record.txt";
const string authFile = "Users_Credentials.txt";

//===========================================
//1.Person Classs
//Abstract Class and Pure Virtual Function
//===========================================
class Person {
	//Encapsulation : Data is Private
	string name;
	int age;
	string address;
	string phoneNumber;
public:
	//Default Constructor
	Person();
	//Perametrized Constructor
	Person(string n, int a, string addr, string phon);

	//Setters
	void setName(string n);
	void setAge(int a);
	void setAddress(string addr);
	void setPhoneNumber(string phon);

	//Getters
	string getName() const;
	int getAge() const;
	string getAddress() const;
	string getPhoneNumber() const;

	// Pure Virtual Function (Makes this class Abstract)
	virtual void display() = 0;
};

//===========================================
//2.Patient Classs
// Inheritance: Derived from Person
//===========================================
class Patient : public Person {
	// Encapsulation: Data is private
	string patientId;
	string bloodGroup;
	string dateOfAdmission;
	string username;
	string password;

	string medicalHistory[50];
	int historyCount;
public:
	//Default Constructor
	Patient();
	//Perametrized Constructor
	Patient(string n, int a, string addr, string phon,
		string pId, string bGroup, string doa, string user, string pass);

	//Setters
	void setPatientId(string pId);
	void setBloodGroup(string bGroup);
	void setDateOfAdmission(string doa);
	void setUsername(string user);
	void setpassword(string pass);

	//Getters
	string getPatientId() const;
	string getBloodGroup() const;
	string getDateOfAdmission() const;
	int getHistoryCount() const;
	string getUsername() const;
	string getPassword() const;

	void Register();
	void addMedicalHistory(string record);
	string getHistoryItem(int index) const;
	void getMedicalHistory();
	void saveData();
	bool loadFromFile(ifstream& inFile);

	// Overriding displayInfo() from Person
	void display();
};

//===========================================
//3.Employee Classs
// Inheritance: Derived from Person
//===========================================
class Employee : public Person {
	// Encapsulation: Data is private
	string employeeId;
	double salary;
	string dateOfJoining;
public:
	//Default Constructor
	Employee();
	//Perameterized Constructor
	Employee(string n, int ag, string addr, string pho,
		string eid, double sa, string doj);

	//Setters
	void setEmployeeId(string eid);
	void setSalary(double sa);
	void setDateOfJoining(string doj);

	//Getters
	string getEmployeeId() const;
	double getSalary() const;
	string getDateOfJoining() const;

	//Virtual Function
	virtual double calculateSalary();

	// Overriding displayInfo() from Person
	void display();
};

//===========================================
//4.Doctor Class
// Inheritance: Derived from Employee
//===========================================
class Doctor : public Employee {
	// Encapsulation: Data is private
	string username;
	string specialization;
	string licenseNumber;
	string scheduale;
	string password;
public:
	//Default Constructor
	Doctor();
	//Paramterized Constructor
	Doctor(string n, int ag, string addr, string pho,
		string eid, double sa, string doj,
		string spec, string ln, string sched, string user, string pass);

	//setters
	void setSpecialization(string spec);
	void setLicenseNumber(string ln);
	void setScheduale(string sched);
	void setUserName(string user);
	void setPassword(string pass);

	//Getters
	string getSpecialization() const;
	string getLicenseNumber() const;
	string getSchedual() const;
	string getUserName() const;
	string getPassword() const;

	void addDiagnosis(string patientName, string diagnose);
	void viewSchedual();
	double calculateSalary();
	void saveToFile();
	bool loadFile(ifstream& ifile);
	void display();
};

//===========================================
//5.Admin Staff Class
// Inheritance: Derived from Employee
//===========================================
class AdminStaff : public Employee {
	// Encapsulation: Data is private
	string departmentName;

public:
	//Default Constructor
	AdminStaff();
	//Paramterized Constructor 
	AdminStaff(string d, string e, double s, string doj, string n, int a, string addr, string p);

	//setter
	void setDepName(string depName);
	//Getter
	string getDepName() const;

	void manageStaff();
	void handleBilling();
	double calculateSalary();
	void saveToFile();
	bool loadFromFile(ifstream& ifile);
	void display();
};

//===========================================
//6.Appointment
// Composition: Links Patient and Doctor
//===========================================
class Appointment {
	// Encapsulation: Data is private
	string appointmentID;
	string date;
	string time;
	string status;
	Patient patient;
	Doctor doctor;

public:
	//Default Constructor
	Appointment();
	//Paramterized Constructor
	Appointment(string a, string d, string t, string s, Patient p, Doctor doc);

	// Setters
	void setAppointmentID(string a);
	void setDate(string d);
	void setTime(string t);
	void setStatus(string s);
	void setPatient(const Patient& p);
	void setDoctor(const Doctor& d);

	//Getters
	string getAppointmentID() const;
	string getDate() const;
	string getTime() const;
	string getStatus() const;
	Patient getPatient() const;
	Doctor getDoctor() const;

	void bookAppointment();
	void cancelAppointment();
	void saveToFile();
	bool loadFile(ifstream& ifile);
	void display();
};

//===========================================
//7.Room
// Standalone
//===========================================
class Room {
	// Encapsulation: Data is private
	string roomNumber;
	string roomType;
	bool isOccupied;

public:
	//default constructors
	Room();
	//Paramterized Constructor 
	Room(string n, string t, bool i);

	//setters
	void setRoomNumber(string n);
	void setRoomType(string t);
	void setIsOccupied(bool i);

	//Getters
	string getRoomNumber() const;
	string getRoomType() const;
	bool getIsOccupied() const;

	void checkAvailability();
	void assignPatient(string patientName);
	void saveFile();
	bool loadFile(ifstream& ifile);
	void display();
};

//===========================================
//8. MedicalRecord Class
// Association: Linked to Patient
//===========================================
class MedicalRecord {
	// Encapsulation: Data is private
	string recordID;
	string diagnosis;
	string prescription;
	string date;
	string patientName;
	string patientID;

public:
	//Default Constructor
	MedicalRecord();
	// Parameterized Constructor
	MedicalRecord(string r, string d, string p, string dat, string pName, string pID);

	//Setters
	void setRecordID(string r);
	void setDiagnosis(string d);
	void setPrescription(string p);
	void setDate(string d);
	void setPatientName(string pName);
	void setPatientId(string pID);

	//Getters
	string getRecordID() const;
	string getDiagnosis() const;
	string getPrescription() const;
	string getDate() const;

	void addEntry(string id, string diag, string rx, string d, Patient& p);
	void getRecordByDate(string d);
	void saveFile();
	bool loadFile(ifstream& ifile);
	void display();
};

//===========================================
//9.Bill Class
// Composition (links to Patient and Room)
//===========================================
class Bill {
	// Encapsulation: Data is private
	string billId;
	double amount;
	string paymentStatus;
	string itemList[50];
	int itemCount;
	double roomCharges;//not important just add roomCharges by roomType
	Patient patient;
	Room room;

public:
	//Default Constructor
	Bill();
	//Parametrized Constructor
	Bill(string bi, Patient p, Room r);

	void AddItems(string item);

	//setters 
	void setBillId(string bi);

	//Getters
	string getBillId() const;
	double getAmount() const;
	string getPaymentStatus() const;
	string getPatientID() const;

	void genrateBill();
	void makePayment();
	void display();
	void saveFile();
	bool loadFile(ifstream& ifile);
};

//===========================================
//10.Hospital Class
// Aggregation (holds lists of other objects)
//===========================================
class Hospital {
	// Encapsulation: Data is private
	Patient* patient[100];
	int pCount;
	Doctor* doctor[50];
	int dCount;
	Room* room[50];
	int rCount;
	AdminStaff* staff[100];
	int eCount;
public:
	//Default Constructor
	Hospital();
	~Hospital();

	void addDoctor(Doctor* d);
	void viewAllDoctors();
	void addPatient(Patient* p);
	void viewAllPatient();
	void viewAllAppointments();
	void addRoom(Room* r);
	void addEmployee(AdminStaff* a);
	void viewAllEmployes();
	void viewDetails();
	void checkRoomStatus();
	void bookNewAppointment();
	bool isPatientIdValid(string id);
	void updatePatient();
	void dischargePatient();
	void deleteDoctor();
	void viewMedicalRecords();
	void cancelAppointment();
	void viewMyDetails(string myID);
	void viewMyHistory(string myID);
	void viewMyAppointments(string myName);
	void viewMyBills(string myID);
};

//===========================================
//11.Authentication Class
//===========================================
class Authentication {
	// Encapsulation: Data is private
	string username;
	string password;
	string userrole;
public:
	//Default Constructor
	Authentication();
	//parameterized Constructor
	Authentication(string user, string pass, string role);

	//Setters
	void setUserName(string user);
	void setPassword(string pass);
	void setUserRoll(string role);

	//Getters
	string getUsername();
	string getPassword();
	string getUserRole();

	void registerUser(string user, string pass, string role);
	bool verifyRole(string requiredRole);
	bool login(string user, string pass);
	void logout();
};

// Standalone Function Prototypes
void Admin(Hospital& hospital);
void doctor(Authentication& auth, Hospital& hospital);
void Operator(Hospital& hospital);
void Patient_Menu(Authentication& auth, Hospital& hospital);
void all();

#endif // HOSPITAL_SYSTEM_H