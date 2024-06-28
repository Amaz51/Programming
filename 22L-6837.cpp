#include<iostream>
#include<string>
using namespace std;
const int maxparticipant = 100;


class Participant {
public:
	int studentid;
	string name;
	string email;
    Participant() { studentid = 0; }
	Participant(int student,string n,string mail) {
		studentid = student;
		name = n;
		email = mail;
	}
};

class Societies {
	Participant participant[maxparticipant];
	int participantcount=0;
    int participatedsocieties = 0;
public:
	Societies() {
        participantcount=0;
	}
    Societies(int ps) {
        participatedsocieties = ps;
    }
void addParticipant(int id, const string& name, const string& email) {
        if (participantcount < maxparticipant) {
            participant[participantcount].studentid = id;
            participant[participantcount].name = name;
            participant[participantcount].email = email;
            participantcount++;
        }
        else {
            cout << "The number of participants has been exceded.No more are allowed." << endl;
        }
    }

    void removeParticipant(int id) {
        for (int i = 0; i < participantcount; ++i) {
            if (participant[i].studentid == id) {
                
                participant[i] = participant[participantcount - 1];
                participantcount--;
                return;
            }
        }
        cout << "participant is not found.Error" << endl;
    }
 void displayParticipants() {
        for (int i = 0; i < participantcount; ++i) {
            cout << "Student ID: " << participant[i].studentid<<endl;
            cout << "Name: " << participant[i].name<<endl;
              cout  << "Email: " << participant[i].email <<endl;
        }
    }
 void commonstudents(const int societyid[],const int societycount) {
     for (int i = 0; i < societycount; i++) {
         for (int j = 0; j < participantcount; j++) {
             if (participant[j].studentid == societyid[i]) {
                 cout << "The student with ID " << participant[j].studentid << " is found in multiple societies ." << endl;
                 return;
             }

         }
     }cout << "Participant is only in a single society ." << endl;
 }
 void mergememberships() {
     
     for (int i = 0; i < participatedsocieties; i++) {
         for (int j = 0; j < participantcount; i++) {
             if (participatedsocieties == 1) {
                 cout << "\nThe student has participated in only 1 society.So we cant merge membership." << endl;
                 return;
             }
             else if (participatedsocieties == 0) {
                 cout << "\nThe student has not participated in any society.Error." << endl;
                 return;
             }
             else if(participant[j].studentid==participant[i].studentid) {

                 cout << "Membership merged" << endl;
             }
         }
     }
 }
 void deleteduplicates() {
     for (int i = 0; i < participatedsocieties; i++) {
         for (int j = 0; j < participantcount; i++) {
             if (participatedsocieties == 1) {
                 cout << "\nThe student has participated in only 1 society.So no duplicate found" << endl;
                 return;
             }
             else if (participatedsocieties == 0) {
                 cout << "\nThe student has not participated in any society. no duplicate found.Error." << endl;
                 return;
             }
             else if (participant[j].studentid == participant[i].studentid) {
                 cout << "Duplicates deleted" << endl;
             }
         }
     }
 }
};

int main() {
    Societies event;
    event.addParticipant(1, "Ali", "ali@gmail.com");//adding the participants
    event.addParticipant(2, "Ehan", "ehan@gmail.com");
    event.addParticipant(3, "mehdi", "mehdi@gmail.com");
    cout << "The participants are :\n";
    event.displayParticipants();
    event.removeParticipant(2);//removing participants
    cout << "\nThe participants after removal are :\n";
    event.displayParticipants();
    int societyIDs[] = { 1, 2 };  // Assuming society IDs
    event.commonstudents(societyIDs, 2);
    event.mergememberships();
    event.deleteduplicates();
}

