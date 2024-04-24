#include<iostream>
#include<string>
using namespace std;
int key[30],c[30],n;
int i;

class CITY
{  
	public:
	int patient_id,age;
	string name,gen,plan,history;
	void declare();
	void display();
	void accept();
	void search();
	void deletE();
	void modify();
}h[30];

void CITY::declare()
{
	cout<<"\nEnter the Total No Of Patients: ";
	cin>>n;
	cout<<"\nEnter The Patient Id: ";
	for(i=0;i<n;i++)
	{
	cin>>key[i];
	}
	for(i=0;i<20;i++)
	{
	
		h[i].patient_id=-1;
		c[i]=0;
		
	}
}

void CITY::accept()
{
	int no,pos;
	for(i=0;i<n;i++)
	{
		no=key[i]%10;
		do
		{
            if(c[i]==0)
            {
                pos=no;
            }
            else
            {
                pos=c[i];
            }
            
			if(h[no].patient_id==-1)
			{
			    h[no].patient_id=key[i];
			    cout<<"\n********Enter Music Patient Details********";
			    
				cout<<"\nEnter Patient Name: ";
				cin>>h[no].name;
				cout<<"\nEnter Age: ";
				cin>>h[no].age;
				cout<<"\nEnter gender: ";
				cin>>h[no].gen;
				cout<<"\nEnter History: ";
				cin>>h[no].history;
				cout<<"\nEnter Treatment Plan: ";
				cin>>h[no].plan;
				break;
				
			}
			else
			{
				no++;
				c[pos]=no;
				if(no>10)
				{
					no=0;
				}
			}
		}while(no<10);
	}
}

void CITY::display()
{
	
	for(i=0;i<20;i++)
	{
		cout<<"\n";
		cout<<"\n"<<h[i].patient_id<<"\t"<<h[i].name<<"\t"<<h[i].age<<"\t"<<h[i].gen<<"\t"<<h[i].plan<<"\t"<<h[i].history<<"\t"<<c[i];
	}
}

void CITY::search()
{
    int patient_key;
    int no,f=0;
    cout<<"\nEnter Patient Id to SEARCH: ";
    cin>>patient_key;
    no=patient_key%10;
    for(i=0;i<n;i++)
    {
        
        if(c[no]==0)
        {
            if(h[no].patient_id==patient_key)
            {
                f=1;
                cout<<"\nRecord is Found";
                break;
            }
            else
            {
                f=0;
                cout<<"\nRecord is not Found";
                break;
            }
        }
        else
        {
            int cnum=c[no];
            if(h[cnum].patient_id==patient_key)
            {
                f=1;
                cout<<"\nRecord is Found\n";
                cout<<"\n";
			    cout<<"\n| PATIENT ID |\t NAME |\t AGE |\t GENDER |\t HISTORY |\t PLAN |\tCHain\n";
            
		            cout<<"\n"<<h[cnum].patient_id<<"\t"<<h[cnum].name<<"\t"<<h[cnum].age<<"\t"<<h[cnum].gen<<"\t"<<h[cnum].plan<<"\t"<<h[cnum].history<<"\t"<<c[cnum];

                break;
            }
             else
            {
               no=cnum;
            }
        }
    }
}

void CITY::deletE()
{
    int patient_key;
    int no,f=0,cno;
    cout<<"\nEnter Patient Id to DELETE: ";
    cin>>patient_key;
    for(i=0;i<n;i++)
    {
        no=patient_key%10;
        if(h[no].patient_id==patient_key)
        {
            f=1;
            h[no].patient_id = -1;
            h[no].name = "";
            h[no].age = 0;
            h[no].gen = "";
            h[no].history = "";
            h[no].plan = "";
            if(c[no] != 0)
            {
                cno=c[no];
                h[no].patient_id=h[cno].patient_id;
                h[no].name = h[cno].name;
                h[no].age = h[cno].age;
                h[no].gen = h[cno].gen;
                h[no].history =h[cno].history;
                h[no].plan =h[cno].plan;
                c[no]=c[cno];
                h[cno].patient_id = -1;
                h[cno].name = "";
                h[cno].age = 0;
                h[cno].gen = "";
                h[cno].history = "";
                h[cno].plan = "";
            }
            cout<<"\nRecord deleted successfully";
            break;
        }
        else
        {
            f=0;
            cout<<"\nRecord is not Found";
            break;
        }
    }
}

void CITY::modify()
{
    int patient_key;
    int no,f=0;
    cout<<"\nEnter Patient Id to MODIFY: ";
    cin>>patient_key;
    for(i=0;i<n;i++)
    {
        no=patient_key%10;
        if(h[no].patient_id==patient_key)
        {
            f=1;
            
            cout<<"\nEnter New NAME: ";
            cin>>h[no].name;
            cout<<"\nEnter AGE: ";
            cin>>h[no].age;
            cout<<"\nEnter GENDER: ";
            cin>>h[no].gen;
            cout<<"\nEnter HISTORY RECORD: ";
            cin>>h[no].history;
            cout<<"\nEnter New TREARMENT PLAN: ";
            cin>>h[no].plan;
            cout<<"\nRecord modified successfully";
            
            break;
        }
        else
        {
            f=0;
            cout<<"\nRecord is not Found";
            break;
        }
    }
}

int main()
{
	int ch;
	CITY c;

	do {
		cout << "\n1. INSERT Patient NO's";
		cout << "\n2. Insert Patient Record";
		cout << "\n3. Display Patient Record";
		cout << "\n4. Search Patient Record";
		cout << "\n5. Delete Patient Record";
		cout << "\n6. Modify Patient ";
        cout << "\n7. EXIT\n";
        cout << "\nEnter your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			c.declare();
			cout<<"\n| PATIENT ID |\t NAME |\t AGE |\t GENDER |\t HISTORY |\t PLAN |\tCHAIN\n";
			c.display();
			break;
		case 2:
			c.accept();
			break;
		case 3:
			cout<<"\n| PATIENT ID |\t NAME |\t AGE |\t GENDER |\t HISTORY |\t PLAN |\tCHain\n";
			c.display();
			break;
		case 4:
			c.search();
			break;
		case 5:
			c.deletE();
			break;
		case 6:
			c.modify();
			break;
		case 7:
			exit(0);
			break;
		default:
			cout << "Invalid Choice!!";
			break;
		}
	} while (ch != 8);

	return 0;
}
