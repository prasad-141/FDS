#include<iostream>
using namespace std;

typedef struct Member
{
    string PRN;
    string Name;
    string Memtype;
    struct Member *next;
}STUD;

class Club
{
    public:
    STUD *head1, *head2;
    Club()
    {
        head1=NULL;
        head2=NULL;
    }

    STUD *addMem(STUD *head, string prn, string nm, string mem)
    {
        STUD *p;
        p = new STUD;
        p->PRN=prn;
        p->Name=nm;
        p->Memtype=mem;
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
            cout<<"\n"<<head->PRN<<" "<<head->Name<<" "<<head->Memtype;
        }
        else
        {
            STUD *cur;
            cur = head;
            while(cur->next!=NULL)
            {
                cur=cur->next;
            }
            cur->next=p;
            cout<<"\n"<<cur->PRN<<" "<<cur->Name<<" "<<cur->Memtype;
        }
        return head;
    }

    void show(STUD *head)
    {
        STUD *cur;
        cur=head;
        if (head == NULL)
        {
            cout << "\n List is empty.";
            return;
        }
        while(cur != NULL)
        {
            cout<<"\n [ "<<cur->PRN<<" | "<<cur->Name<<" | "<<cur->Memtype<<" ]";
            cur=cur->next;
        }
        cout<<" NULL ";
    }

    STUD *deletemem(STUD *head, string key)
    {
        STUD *cur, *f=NULL;
        cur=head;
        while(cur != NULL)
        {
            if(cur->Name == key)
            {
                break;
            }
            f=cur;
            cur=cur->next;
        }
        if(cur)
        {
            if(cur==head && cur->next == NULL)
                head=NULL;
            else if(cur==head && cur->next != NULL)
                head=cur->next;
            else if(cur != head && cur->next != NULL)
                f->next = cur->next;
            else if(cur != head && cur->next == NULL)
                f->next = cur->next;
            delete cur;
        }
        else
        {
            cout<<"\n No Data Found ";
        }
        return head;
    }

    void concatenate()
    {
			STUD *cur;
			cur=head1;
            if(head1 == NULL)
            {
                head1 = head2;
                head2 = NULL;
                return;
            }

			while(cur->next != NULL)
            {
				cur=cur->next;
            }
			cur->next=head2;
			head2=NULL;
	}
};

int main()
{
    string prn, nm, mem;
    Club c;
    int ch = 0;
    while(ch != 5)
    {
        cout<<"\n 1. Add ";
        cout<<"\n 2. Show ";
        cout<<"\n 3. Delete ";
        cout<<"\n 4. Concatenate ";
        cout<<"\n 5. Exit \n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\n Enter PRN : ";
            cin>>prn;
            cout<<"\n Enter Name : ";
            cin>>nm;
            cout<<"\n Enter Member : ";
            cin>>mem;
            cout<<"\n Which List? \n 1. A-Div \n 2. B-Div \n";
            int ch1;
            cin>>ch1;
            if(ch1==1)
            {
                c.head1=c.addMem(c.head1,prn,nm,mem);
            }
            if(ch1==2)
            {
                c.head2=c.addMem(c.head2,prn,nm,mem);
            }      
            break;

            case 2:
            cout<<"\n A Division : ";
            c.show(c.head1);
            cout<<"\n B Division : ";
            c.show(c.head2);
            break;   

            case 3:
            cout<<"\n Which List? \n 1. A Div \n 2. B Div ";
            cin>>ch1;
            cout<<"\n Which Name? ";
            cin>>nm;
            if(ch1==1)
            {
                c.head1=c.deletemem(c.head1,nm);
            }
            if(ch1==2)
            {
                c.head2=c.deletemem(c.head2,nm);
            }
            break;

            case 4:
            c.concatenate();
            break;

            case 5:
            cout<<"\n Successfully Exited ";
            break;

            default:
            cout<<"\n Invalid ";
            break;

        }
    }

    return 0;
}