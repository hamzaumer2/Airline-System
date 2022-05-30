#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
using namespace std;

class Time
{
protected:
    int year, month, day, hour, minute, second;
public:
    Time()
    {

        year = 0, month = 0, day = 0;
        hour = 0, minute = 0, second = 0;
    }
    void set_time()///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    {
        cout << "\t\t\t\tEnter Date: (YYYY MM DD): ....   ";
        cin >> this->year >> this->month >> this->day;
        cout << "\t\t\t\tEnter Time: (Hour Minute Second) 24hr format:....   ";
        cin >> this->hour >> this->minute >> this->second;
        bool date = true, time = true;

        while (date) {
            cout << "\t\t\t\t\tEnter Date: (YYYY MM DD) : ....  ";
            cin >> this->year >> this->month >> this->day;
            if (this->month > 12 || (this->month == 1 && this->day > 31) || (this->month == 2 && this->day > 29) || (this->month == 3 && this->day > 31) || (this->month == 4 && this->day > 30) || (this->month == 5 && this->day > 31) || (this->month == 6 && this->day > 30) || (this->month == 7 && this->day > 31) || (this->month == 8 && this->day > 31) || (this->month == 9 && this->day > 30) || (this->month == 10 && this->day > 31) || (this->month == 11 && this->day > 30) || (this->month == 12 && this->day > 31)) {
                cout << "\nPlease Enter Correct Date!!";
                cout << endl;
            }
            else date = false;
        }
        while (time) {
            cout << "\t\t\t\t\tEnter Time: (HH MM SS): 24hr Format: ....  ";
            cin >> this->hour >> this->minute >> this->second;
            if (this->hour > 24 || this->minute > 60 || this->second > 60) {
                cout << "Please Enter Correct Time!!";
            }
            else time = false;
        }
    }
    void set_year(int y)
    {
        year = y;
    }
    void set_month(int m)
    {
        month = m;
    }
    void set_day(int d)
    {
        day = d;
    }
    void set_hour(int h)
    {
        hour = h;
    }
    void set_minute(int m)
    {
        minute = m;
    }
    void set_second(int s)
    {
        second = s;
    }
    int get_year() const
    {
        return year;
    }
    int get_month() const
    {
        return month;
    }
    int get_day() const
    {
        return day;
    }
    int get_hour() const
    {
        return hour;
    }
    int get_minute() const
    {
        return minute;
    }
    int get_second() const
    {
        return second;
    }
    void print_time() const
    {
        cout << day << "/" << month << "/" << year << " :: " << hour << ":" << minute << ":" << second << endl;
    }
    friend ostream& operator<<(ostream& os, Time const& tme)
    {
        os << tme.year << " " << tme.month << " " << tme.day << " " << tme.hour << " " << tme.minute << " " << tme.second << " ";
        return os;
    }
    friend istream& operator>>(istream& is, Time& tme)
    {
        is >> tme.year;
        is >> tme.month >> tme.day >> tme.hour >> tme.minute >> tme.second;
        return is;
    }
};

template <class t>
class node
{
private:
    t data;
    node* nextnode;
public:
    node()
    {
        //t = nullptr;
        nextnode = nullptr;
    }
    void set_data(t a)
    {
        data = a;
    }
    void set_nextnode(node* gh)
    {
        nextnode = gh;
    }
    t get_data()
    {
        return data;
    }
    node* get_nextnode()
    {
        return nextnode;
    }

};

class plane;
template<class g>
class linked_list
{
private:
    string name;
    node <g>* head;
    int size;
    node <g>* current;
    node <g>* newnode;
    node <g>* previous;
    g* ptr1;
public:
    linked_list()
    {
        head = nullptr;
        size = 0;
        name = " ";
    }
    void set_name(string a)
    {
        name = a;
    }
    string get_name()
    {
        return name;
    }
    void insert_at_start(g an)
    {
        newnode = new node <g>();
        newnode->set_data(an);
        newnode->set_nextnode(nullptr);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode->set_nextnode(head);
            head = newnode;
        }
        size++;
    }

    void insert_at_end(g an)
    {
        newnode = new node <g>();
        newnode->set_data(an);
        newnode->set_nextnode(nullptr);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            current = head;
            while (current->get_nextnode() != nullptr)
            {
                current = current->get_nextnode();
            }
            current->set_nextnode(newnode);
        }
        size++;
    }
    void delete_at_start()
    {
        if (head == nullptr)
        {
            cout << "list is empty " << endl;
        }
        else
        {
            current = head;
            head = head->get_nextnode();
            delete current;
            size--;
        }
    }
    void delete_at_end()
    {
        if (head == nullptr)
        {
            cout << "list is empty " << endl;
        }
        else
        {
            current = head;
            previous = head;
            while (current->get_nextnode() != nullptr)
            {
                previous = current;
                current = current->get_nextnode();
            }
            previous->set_nextnode(nullptr);
            delete current;
            size--;
        }
    }
    void insert_at_specific_location(g d, int loc)
    {
        newnode = new node();
        newnode->set_data(d);
        if ((head == nullptr) && (loc == 1))
        {
            head = newnode;
            newnode->set_nextnode(nullptr);
            size++;
        }
        else if ((loc <= size) && (loc > 0))
        {
            if (loc == 1)
            {
                newnode->set_nextnode(head);
                head = newnode;
                size++;
            }
            else
            {
                current = head;
                previous = head;
                for (int i = 1; i < loc; i++)
                {
                    previous = current;
                    current = current->get_nextnode();
                }
                previous->set_nextnode(newnode);
                newnode->set_nextnode(current);
                size++;
            }
        }
    }
    void delete_at_specific_location(int loc)
    {
        if ((head == nullptr) && (loc == 1))
        {

            cout << "List is empty " << endl;
        }
        else if ((loc <= size) && (loc > 0))
        {
            if (loc == 1)
            {
                current = head;
                head = head->get_nextnode();
                delete current;
                size--;
            }
            else
            {
                current = head;
                previous = head;
                for (int i = 1; i < loc; i++)
                {
                    previous = current;
                    current = current->get_nextnode();
                }
                previous->set_nextnode(current->get_nextnode());
                delete current;
                size--;
            }
        }
    }
    void display()
    {
        if (head == nullptr)
            cout << "list is empty " << endl;
        else
        {
            current = head;
            while (current->get_nextnode() != nullptr)
            {
                cout << current->get_data();
                current = current->get_nextnode();

            }
            cout << current->get_data();
        }
    }
    int get_size()
    {
        return size;
    }
    g get_on_the_position(int v)
    {
        int j = 1;
        current = head;
        while (current->get_nextnode() != nullptr)
        {
            if (j == v)
            {
                return current->get_data();
            }
            j++;
            current = current->get_nextnode();
        }
        if (j == v)
            return current->get_data();


    }

};

template<class h>
class stack
{
    node <h>* head;
    int noe;
    node <h>* current;
    string name;
public:
    stack()
    {
        head = nullptr;
        noe = 0;
    }
    void set_name(string a)
    {
        name = a;
    }
    string get_name()
    {
        return name;
    }

    void push(h v)
    {
        node <h>* newnode = new node <h>();
        newnode->set_data(v);
        newnode->set_nextnode(head);
        head = newnode;
        noe++;
    }
    h pop()
    {
        h temp = head->get_data();
        node <h>* t = head;
        head = head->get_nextnode();
        delete t;
        noe--;
        return temp;
    }
    int isempty()
    {
        return head == nullptr;
    }
    h top()
    {
        return head->get_data();
    }
    int get_size()
    {
        return noe;
    }
    void display()
    {
        if (head == nullptr)
            cout << "stack is empty ";
        else
        {
            current = head;
            while (current->get_nextnode() != nullptr)
            {
                
                cout << current->get_data() << "  ";
                system("pause");
                current = current->get_nextnode();
            }
            cout << current->get_data() << "  ";
        }
    }
    void display_style()
    {
        cout << "\t\t\t\t\t*************** " << endl;
        cout << "\t\t\t\t\t  Stack    \t\t\t" << endl;
        cout << "\t\t\t\t\t *************** " << endl;
        cout << "\t\tList name :  " << name << "\t\t\t\t  Size:   " << noe << endl;
        cout << "\t\t\t\t\t";
        display();
        cout << "\n\n\n";
    }

};

template<class q>
class queue
{
private:
    node <q>* front;
    node <q>* rear;
    int size;
    node <q>* current;

public:

    queue()
    {
        size = 0;
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(q v)
    {
        node <q>* newnode = new node <q>();
        newnode->set_data(v);
        newnode->set_nextnode(nullptr);
        if (rear == nullptr)
        {

            front = newnode;
            rear = newnode;
            size++;
        }
        else
        {

            rear->set_nextnode(newnode);
            rear = newnode;
            size++;
        }
    }
    q dequeu()
    {
        q temp;

        if (rear == nullptr)
        {
            cout << "queue is empty ";
        }
        else
        {
            temp = front->get_data();
            node <q>* p = front;
            if (rear == front)
            {
                rear = nullptr;
                front = nullptr;
                size--;
            }
            else
            {
                front = front->get_nextnode();
                delete p;
                size--;

            }
            return temp;
        }
    }
    bool is_empty()
    {
        return  rear == nullptr;
    }
    int get_size()
    {
        return size;
    }
    void display_style()
    {
        cout << "\t\t\t\t\t*************** " << endl;
        cout << "\t\t\t\t\t  Queue   \t\t\t" << endl;
        cout << "\t\t\t\t\t *************** " << endl;
        cout << "\t\tQueue:  " << "Ahmed" << "\t\t\t\t  Number of Elements:   " << size << endl;
        cout << "\t\t\t\t\t";
        display();
        cout << "\n\n\n";
    }
    void display()
    {
        current = front;
        while (current->get_nextnode() != nullptr)
        {
            cout << current->get_data() << " ";
            current = current->get_nextnode();
        }
        cout << current->get_data() << " ";
    }
    q show()
    {
        return front->get_data();
    }

};

class user
{
protected:
    string name, gender, address, email;
    int age;
    int contact_number;

public:
    user()
    {
        name = " ";
        gender = " ";
        address = "";
        email = " ";
        age = 0;
        contact_number = 0;
    }
    void set_name(string input)
    {
        name = input;
    }
    void set_gender(string input)
    {
        gender = input;
    }
    void set_address(string input)
    {
        address = input;
    }
    void set_email(string input)
    {
        email = input;
    }
    void set_age(int input)
    {
        age = input;
    }
    void set_contactnumber(int input)
    {
        contact_number = input;
    }
    string get_name() const
    {
        return name;
    }
    string get_gender() const
    {
        return gender;
    }
    string get_address() const
    {
        return address;
    }
    string get_email() const
    {
        return email;
    }
    int get_age() const
    {
        return age;
    }
    int get_contactnumber() const
    {
        return contact_number;
    }
};

class passenger : public user
{
protected:
    int amount_charged;
    bool flight_confirmed;
    bool pay_bill;
    bool authorized;
    int seats;
    string seat_type;
    int t_cost;
    string fl_no;
    string srce, dest;
    string p_name;

public:
    passenger() : user()
    {
        amount_charged = 0;
        flight_confirmed = 0;
        t_cost = 0;
        authorized = 0;
    }
    void set_p_name(string g)
    {
        p_name = g;
    }
    string get_p_name()
    {
        return p_name;
    }

    void set_seats(int v)
    {
        seats = v;
    }
    void set_seat_type(string v)
    {
        seat_type = v;
    }
    string get_seat_type()
    {
        return seat_type;
    }

    int get_seats() const
    {
        return seats;
    }

    void set_flight_confirmed()
    {
        flight_confirmed = 1;
    }
    void set_flight_no(string input)
    {
        fl_no = input;
    }

    void set_source(string input)
    {
        srce = input;
    }
    void set_destination(string input)
    {
        dest = input;
    }

    void set_amount_charged(int input)
    {
        amount_charged = input;
    }



    bool get_flight_confirmed() const
    {
        return flight_confirmed;
    }
    int get_amountcharged() const
    {
        return amount_charged;
    }

    void cost_calculator()
    {
        t_cost = amount_charged * seats;
    }


    bool receipt()
    {
        cout << "\t\t\tFlight No.. " << fl_no << "        "
            << "Date" << endl;
        cout << "\n";
        cout << "\t\t\t------------------------------------------------------------" << endl;
        cout << "\n\n";
        cout << "\t\t\tName        :" << name << "         "
            << " Gender     : " << gender << endl;
        cout << "\t\t\tDeparture   :" << srce << "         "
            << " Arrival    : " << dest << endl;
        cout << "\t\t\tEmail       :" << email << "         "
            << " Address    : " << address << endl;
        cout << "\t\t\tAge         :" << age << "          "
            << " Contact No : " << contact_number << endl;
        cout << "\t\t\t--------------------------------------------------------------" << endl;
        cout << "\t\t\tTotal Charges " << t_cost << endl;
        cout << "\n";

        do
        {
            cout << "\t\t\t\t\t Do you want to pay the bill and confirmed your flight 1(yes) 0(no) ..... ";
            cin >> pay_bill;

            if (pay_bill == 1)
                return 1;
            else if (pay_bill == 0)
                return 0;
            else
            {
                cout << "\t\t\t\t\tyou entered invalid choice " << endl;
            }
        } while (pay_bill == 0 || pay_bill == 1);
    }
    void show_data()
    {
        cout << setw(4) << name << setw(12) << gender << setw(14) << age << setw(24) << address << setw(24) << email << setw(16) << contact_number << setw(16) << srce << setw(16) << dest << setw(8) << seat_type << setw(8) << fl_no << endl;
    }
    friend ostream& operator<<(ostream& os, passenger const& d)
    {
        cout << setw(4) << d.name << setw(12) << d.gender << setw(14) << d.age << setw(24) << d.address << setw(24) << d.email << setw(16) << d.contact_number << setw(16) << d.srce << setw(16) << d.dest << setw(8) << d.seat_type << setw(8) << d.fl_no << endl;
        return os;
    }
};

class admin
{
private:
    int id[4]{};
    string pwd[4];
public:
    admin()
    {

        id[0] = 200903;
        pwd[0] = "ahmed";

        id[1] = 201947;
        pwd[1] = "sarib";

        id[2] = 200789;
        pwd[2] = "hamza";

        id[3] = 200915;
        pwd[3] = "imran";

    }
    bool check_member(int c, const string& nm)
    {
        for (int i = 0; i < 4; i++)
        {
            if ((id[i] == c) && (pwd[i] == nm))
                return 1;
        }
        return 0;
    }

};

class seat
{
public:
    int t_seats, b_seats;
    int s_counter;
    int c_p_seat;
    int r_seats{};
public:
    seat()
    {
        t_seats = 0;
        s_counter = 0;
        c_p_seat = 0;
        b_seats = 0;
    }
    void set_seatchrg(int j)
    {
        c_p_seat = j;
    }
    int get_seatchrg() const
    {
        return c_p_seat;
    }
    void set_t_seats(int r)
    {
        t_seats = r;
    }
    int get_t_seats() const
    {
        return  t_seats;
    }
    bool book_seats(int oo)
    {
        if ((t_seats - s_counter) >= oo)
        {
            s_counter = s_counter + oo;
            return 1;
        }
        else
        {
            cout << "Desired No of Seats are NOT Available ";
            return 0;
        }
    }
    void display() const
    {

        cout << "Total Number of Seats : " << t_seats << "            Seats Available : " << t_seats - s_counter << endl;
    }


};



class plane
{
private:
    string p_name;
    int capacity;

public:
    seat First_Class;
    seat economy;
    seat bussiness;
    plane()
    {
        p_name = " ";
        capacity = 0;
    }
    void set_capacity(int h)
    {
        capacity = h;
    }
    int get_capacity() const
    {
        return capacity;
    }
    void set_p_name(string a)
    {
        p_name = a;
    }
    string get_p_name()
    {
        return p_name;
    }
    void decide()
    {
        int e, p, d;
        e = capacity * 0.50;
        p = capacity * 0.30;
        d = capacity * 0.20;

        First_Class.set_t_seats(p);
        economy.set_t_seats(e);
        bussiness.set_t_seats(d);
    }
    friend ostream& operator<<(ostream& output, const plane& d)
    {
        cout << "\t\t\t " << setw(10) << d.p_name << setw(10) << d.capacity << setw(10) << d.economy.t_seats;
        cout << setw(10) << d.First_Class.t_seats << setw(10) << d.bussiness.t_seats << endl;
        return output;
    }

};


class Airport
{
private:
    string  name;
public:
    Airport()
    {
        name = " ";
    }
    void set_name(string a)
    {
        name = a;
    }
    string get_name()
    {
        return name;
    }

    friend ostream& operator<<(ostream& output, const Airport& d)
    {
        cout << d.name << endl;
        return output;
    }

    void operator=(const Airport& d)
    {
        name = d.name;
    }
};


class flight
{

private:
    string flight_name;
    int flight_charges{};
    plane* abc{};
    Airport* source{};
    Airport* destination{};
    Time flight_time;
public:
    flight()
    {

    }
    void set_plane(plane& pr)
    {
        abc = &pr;
    }
    plane* get_plane()
    {
        return abc;
    }

    void set_time()
    {
        bool time = true, date = true;
        cout << "\t\t\t\t\tEnter the Time of Flight " << endl;
        cout << "\t\t\t\t\t-----------------------------------------" << endl;
        int y, m, d, h, m1, s;
        while (date) {
            cout << "\t\t\t\t\tEnter Date: (YYYY MM DD) : ....  ";
            cin >> y >> m >> d;
            if (m > 12 || (m == 1 && d > 31) || (m == 2 && d > 29) || (m == 3 && d > 31) || (m == 4 && d > 30) || (m == 5 && d > 31) || (m == 6 && d > 30) || (m == 7 && d > 31) || (m == 8 && d > 31) || (m == 9 && d > 30) || (m == 10 && d > 31) || (m == 11 && d > 30) || (m == 12 && d > 31)) {
                cout << "\nPlease Enter Correct Date!!";
                cout << endl;
            }
            else date = false;
        }
        while (time) {
            cout << "\t\t\t\t\tEnter Time: (HH MM SS): 24hr Format: ....  ";
            cin >> h >> m1 >> s;
            if (h > 24 || m1 > 60 || s > 60) {
                cout << "Please Enter Correct Time!!";
            }
            else time = false;
        }
        flight_time.set_year(y);
        flight_time.set_month(m);
        flight_time.set_day(d);
        flight_time.set_hour(h);
        flight_time.set_minute(m1);
        flight_time.set_second(s);

    }
    void set_flight_charges(int input)
    {
        flight_charges = input;
    }
    void set_source(Airport& input)
    {
        source = &input;
    }
    void set_destination(Airport& input)
    {
        destination = &input;
    }
    void set_flightname(string input)
    {
        flight_name = input;
    }

    Airport* get_source() const
    {
        return source;
    }
    Airport* get_destination() const
    {
        return destination;
    }
    string get_flightname() const
    {
        return flight_name;
    }
    int get_flight_charges() const
    {
        return flight_charges;
    }




    friend ostream& operator<<(ostream& os, flight const& ft)
    {

        cout << "\t\t\t\t\t\t ";
        cout << setw(10) << ft.flight_name << setw(10) << ft.source->get_name() << setw(10) << ft.destination->get_name() << setw(10) << ft.abc->get_p_name() << endl;
        return os;
    }

    void set_credentials()
    {
        int g;

        cout << "Enter Charges of Economy Seats : ";
        cin >> g;
        abc->economy.set_seatchrg(g);
        cout << "Enter Charges for Businness Seats  :";
        cin >> g;
        abc->bussiness.set_seatchrg(g);
        cout << "Enter Charges for First Class Seats : ";
        cin >> g;
        abc->First_Class.set_seatchrg(g);

    }
    void display_style()
    {
        cout << " \t\t\t\t " << flight_name << endl;
        cout << "\t\t\t\t  Source" << source << "\t\t\t\t  Destination  " << destination << endl;
        cout << "\t\t\t\t  Time : " << flight_time.get_month() << "-" << flight_time.get_year() << "::" << flight_time.get_hour() << ":" << flight_time.get_minute() << ":" << flight_time.get_second() << endl;
    }
};

template <typename t>
void abc(stack <t>& obj, linked_list <t>& obj1)
{
    for (int i = 1; i <= obj1.get_size(); i++)
    {
        obj.push(obj1.get_on_the_position(i));

    }

}




int main()
{

    int var = 0, var1 = 0, var2 = 0, cp, var4 = 0, var5 = 0;
    admin obj;
    int ds;
    string a;
    bool afp = 1, gh = 1, cd = 1, ll = 1, ath, ip = 1;
    int idi;
    string pwd, nm, pwd2;
    bool p, y = 0, u;
    stack <Airport> tcp;
    stack <plane> ocp;
    flight* ptr;
    flight ioi;
    plane* obj1;
    Airport* obj2;
    linked_list <plane> plaene;
    linked_list <Airport> port;
    linked_list<flight> flt;
    linked_list<passenger> psg;
    Airport nkl;
    string lkl;
    plane kll;
    bool r;
    string name, gender, address, email;
    int age, contact_no, seats;;
    passenger* tyi;
    queue<passenger> q1;
    queue<flight> q2;

    system("blue");
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "\n\t\t\t          ###     #### ########  ##       #### ##    ## ########      ######  ##    ##  ######  ######## ######## ##     ##";
    cout << "\n\t\t\t         ## ##     ##  ##     ## ##        ##  ###   ## ##           ##    ##  ##  ##  ##    ##    ##    ##       ###   ###";
    cout << "\n\t\t\t        ##   ##    ##  ##     ## ##        ##  ####  ## ##           ##         ####   ##          ##    ##       #### ####";
    cout << "\n\t\t\t       ##     ##   ##  ########  ##        ##  ## ## ## ######        ######     ##     ######     ##    ######   ## ### ##";
    cout << "\n\t\t\t       #########   ##  ##   ##   ##        ##  ##  #### ##                 ##    ##          ##    ##    ##       ##     ##";
    cout << "\n\t\t\t       ##     ##   ##  ##    ##  ##        ##  ##   ### ##           ##    ##    ##    ##    ##    ##    ##       ##     ##";
    cout << "\n\t\t\t       ##     ##  #### ##     ## ######## #### ##    ## ########      ######     ##     ######     ##    ######## ##     ##\n\n";
    system("PAUSE");
    system("cls");
    while (afp)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        cout << "\n\t\t\t           ##     ##    ###    #### ##    ##       ##     ## ######## ##    ## ##     ##";
        cout << "\n\t\t\t           ###   ###   ## ##    ##  ###   ##       ###   ### ##       ###   ## ##     ##";
        cout << "\n\t\t\t           #### ####  ##   ##   ##  ####  ##       #### #### ##       ####  ## ##     ##";
        cout << "\n\t\t\t           ## ### ## ##     ##  ##  ## ## ##       ## ### ## ######   ## ## ## ##     ##";
        cout << "\n\t\t\t           ##     ## #########  ##  ##  ####       ##     ## ##       ##  #### ##     ##";
        cout << "\n\t\t\t           ##     ## ##     ##  ##  ##   ###       ##     ## ##       ##   ### ##     ##";
        cout << "\n\t\t\t           ##     ## ##     ## #### ##    ##       ##     ## ######## ##    ##  #######\n\n";

        cout << "\n\n\n\n";

        if (GetAsyncKeyState(VK_UP) & 1)
        {
            var--;
            if (var < 1)
            {
                var = 4;

            }

        }
        else if (GetAsyncKeyState(VK_DOWN) & 1)
        {


            var++;
            if (var > 4)
            {
                var = 1;
            }
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

        if (var == 1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "\t\t\t\t\t          1. Admin" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        if (var == 2)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "\t\t\t\t\t          2. Passenger" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        if (var == 3)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "\t\t\t\t\t          3. About Group memebers " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        if (var == 4)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "\t\t\t\t\t          4. Exit " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

        if (GetAsyncKeyState(VK_RETURN) & 1)
        {
            switch (var)
            {
            case 1:
                system("cls");

                cout << "\n\n\n\n";
                cout << "\t\t\t\t  Enter your id       : ";
                cin >> idi;
                cout << "\t\t\t\t  Enter your passowrd : ";
                cin >> pwd;


                p = obj.check_member(idi, pwd);
                while (gh && p)
                {
                    system("cls");
                    cout << "\n\n\n\n";
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        var1--;
                        if (var1 < 1)
                        {
                            var1 = 9;

                        }

                    }
                    else if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        var1++;
                        if (var1 > 9)
                        {
                            var1 = 1;
                        }
                    }

                    if (var1 == 1)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          1. Add Flight" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var1 == 2)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          2. Add Airport" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var1 == 3)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          3. Add Plane  " << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var1 == 4)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          4. check Flight Schedules " << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var1 == 5)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          5. Check Passengers " << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var1 == 6)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          6. Check Planes " << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var1 == 7)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          7. Check Airports " << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var1 == 8)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          8. Back to Main Menu " << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);



                    if (GetAsyncKeyState(VK_RETURN) & 1)
                    {

                        switch (var1)
                        {
                        case 1:
                            system("cls");
                            ptr = new flight();

                            cout << "\t\t\t\t\t          Flight Name : ";
                            cin >> nm;
                            ptr->set_flightname(nm);
                            abc <Airport>(tcp, port);


                            while (1)
                            {
                                system("cls");

                                cout << "\n\n\n\t\t\t\t\t          Enter the Source : ";
                                if (tcp.get_size() != 0)
                                {

                                    nkl = tcp.top();
                                    cout << "\n\n\t\t\t\t\t  ";
                                    cout << tcp.pop();
                                    system("pause");

                                    if (GetAsyncKeyState(VK_UP) & 1)
                                    {
                                        obj2 = new Airport();
                                        *obj2 = nkl;
                                        ptr->set_source(*obj2);
                                        lkl = nkl.get_name();
                                        cout << "\t\t\t\t\t          Your Source is Successfully Confirmed" << endl;
                                        break;
                                    }
                                    if (GetAsyncKeyState(VK_RETURN) & 1)
                                    {

                                    }
                                    if (tcp.get_size() == 0)
                                        abc <Airport>(tcp, port);
                                }
                                else
                                    break;
                                system("pause");
                            }
                            abc <Airport>(tcp, port);
                            while (1)
                            {
                                system("cls");

                                cout << "\n\n\n\t\t\t\t\t          Enter the Destination : ";
                                if (tcp.get_size() != 0)
                                {

                                    nkl = tcp.top();
                                    if (nkl.get_name() == lkl)
                                    {
                                        tcp.pop();
                                        continue;
                                    }
                                    cout << "\n\n\t\t\t\t\t  ";
                                    cout << tcp.pop();
                                    system("pause");

                                    if (GetAsyncKeyState(VK_UP) & 1)
                                    {
                                        obj2 = new Airport();
                                        *obj2 = nkl;
                                        ptr->set_destination(*obj2);
                                        cout << "\t\t\t\t\t          Your Destination is Successfully Confirmed" << endl;
                                        break;
                                    }
                                    if (GetAsyncKeyState(VK_RETURN) & 1)
                                    {

                                    }
                                    if (tcp.get_size() == 0)
                                        abc <Airport>(tcp, port);
                                }
                                else
                                    break;
                                system("pause");
                            }
                            abc <plane>(ocp, plaene);
                            while (1)
                            {
                                system("cls");
                                cout << ocp.get_size();
                                cout << "\n\n\n\t\t\t\t\t          Enter the Plane : ";
                                if (ocp.get_size() != 0)
                                {

                                    kll = ocp.top();
                                    cout << "\n\n\t\t\t\t\t  ";
                                    cout << ocp.pop();
                                    system("pause");

                                    if (GetAsyncKeyState(VK_UP) & 1)
                                    {
                                        obj1 = new plane();
                                        *obj1 = kll;
                                        ptr->set_plane(*obj1);
                                        cout << "\t\t\t\t\t          your Plane is Successfully Confirmed" << endl;
                                        break;
                                    }
                                    if (GetAsyncKeyState(VK_RETURN) & 1)
                                    {

                                    }
                                    if (ocp.get_size() == 0)
                                        abc <plane>(ocp, plaene);

                                }
                                else
                                    break;
                                system("pause");

                            }
                            system("cls");
                            ptr->set_time();
                            ptr->set_credentials();

                            cout << "\t\t\t\t\t          Your Flight is Confirmed ";
                            flt.insert_at_end(*ptr);

                            break;
                        case 2:
                            system("cls");
                            obj2 = new Airport();
                            cout << "\n\n\n\n";
                            cout << "\t\t\t\t\t          Enter the Name of Airpot  : ";
                            cin >> nm;
                            obj2->set_name(nm);
                            port.insert_at_end(*obj2);

                            break;
                        case 3:
                            system("cls");
                            obj1 = new plane();
                            cout << "\n\n\n\n";
                            cout << "\t\t\t\t\t          Enter the Name of Plane   : ";
                            cin >> nm;
                            cout << "\t\t\t\t\t          Enter the Capacity of Plane : ";
                            cin >> cp;
                            obj1->set_capacity(cp);
                            obj1->set_p_name(nm);
                            obj1->decide();
                            plaene.insert_at_end(*obj1);
                            break;
                        case 4:
                            system("cls");
                            flt.display();
                            break;
                        case 5:
                            psg.display();
                            break;
                        case 6:
                            system("cls");
                            plaene.display();
                            break;
                        case 7:
                            system("cls");
                            port.display();
                            break;

                        case 8:
                            gh = 0;
                            break;
                        };
                        var1 = 0;
                    }

                    system("pause");
                    system("cls");
                }
                var = 0;
                var1 = 0;
                gh = 1;
                break;

            case 2:

                tyi = new passenger();
                while (cd)
                {
                    system("cls");
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        var2--;
                        if (var2 < 1)
                        {
                            var2 = 4;

                        }

                    }
                    else if (GetAsyncKeyState(VK_DOWN) & 1)
                    {


                        var2++;
                        if (var2 > 4)
                        {
                            var2 = 1;
                        }
                    }

                    if (var2 == 1)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          1. Check Flight" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var2 == 2)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          2. Book Flight" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var2 == 3)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          3. Transcript  " << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    if (var2 == 4)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t\t\t\t\t          4. Exit " << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);





                    if (GetAsyncKeyState(VK_RETURN) & 1)
                    {
                        switch (var2)
                        {
                        case 1:
                            system("cls");
                            flt.display();
                            break;
                        case 2:
                            system("cls");
                            cout << "\t\t\t\t\tEnter Name                 : ";
                            cin >> name;
                            cout << "\t\t\t\t\tEnter Gender               : ";
                            cin >> gender;
                            cout << "\t\t\t\t\tEnter Address              : ";
                            cin >> address;
                            cout << "\t\t\t\t\tEnter Email                : ";
                            cin >> email;
                            cout << "\t\t\t\t\tEnter Contact Number       : ";
                            cin >> contact_no;
                            cout << "\t\t\t\t\tEnter Age                  : ";
                            cin >> age;

                            if (flt.get_size() != 0)
                            {
                                tyi->set_name(name);
                                tyi->set_gender(gender);
                                tyi->set_email(email);
                                tyi->set_contactnumber(contact_no);
                                tyi->set_age(age);
                                tyi->set_address(address);


                                cout << "\t\t\t\t\tFlights Available    : ";
                                flt.display();//????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
                                cout << "Deisred Flight Number you want to Book  :  ";
                                cin >> nm;
                                for (int i = 1; i <= flt.get_size(); i++)
                                {
                                    ioi = flt.get_on_the_position(i);
                                    if ((ioi.get_flightname()) == nm)
                                    {
                                        break;
                                    }
                                }
                                tyi->set_destination(ioi.get_destination()->get_name());
                                tyi->set_source(ioi.get_source()->get_name());
                                tyi->set_p_name(ioi.get_plane()->get_p_name());
                                tyi->set_flight_no(ioi.get_flightname());
                                system("cls");
                                while (ll)
                                {
                                    system("cls");
                                    if (GetAsyncKeyState(VK_UP) & 1)
                                    {
                                        var4--;
                                        if (var4 < 1)
                                        {
                                            var4 = 4;

                                        }

                                    }
                                    else if (GetAsyncKeyState(VK_DOWN) & 1)
                                    {


                                        var4++;
                                        if (var4 > 4)
                                        {
                                            var4 = 1;
                                        }
                                    }

                                    if (var4 == 1)
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                                    cout << "\t\t\t\t\t          1. Economy " << endl;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                                    if (var4 == 2)
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                                    cout << "\t\t\t\t\t          2. First_Class  " << endl;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                                    if (var4 == 3)
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                                    cout << "\t\t\t\t\t          3. Bussiness " << endl;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                                    if (var4 == 4)
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                                    cout << "\t\t\t\t\t          4. Exit      " << endl;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

                                    if (GetAsyncKeyState(VK_RETURN) & 1)
                                    {
                                        switch (var4)
                                        {
                                        case 1:
                                            ioi.get_plane()->economy.display();
                                            cout << "\t\t\t\t\tEnter Number of Seats      :  ";
                                            cin >> seats;
                                            if (ioi.get_plane()->economy.book_seats(seats))
                                            {
                                                tyi->set_seats(seats);
                                                tyi->set_seat_type("Economy");
                                                tyi->set_amount_charged(ioi.get_plane()->economy.c_p_seat);
                                                tyi->cost_calculator();
                                                ll = 0;
                                            }

                                            break;
                                        case 2:
                                            ioi.get_plane()->First_Class.display();
                                            cout << "\t\t\t\t\tEnter Number of Seats      : ";
                                            cin >> seats;
                                            if (ioi.get_plane()->First_Class.book_seats(seats));
                                            {
                                                tyi->set_seats(seats);
                                                tyi->set_seat_type("First_Class");
                                                tyi->set_amount_charged(ioi.get_plane()->First_Class.c_p_seat);
                                                tyi->cost_calculator();
                                                ll = 0;
                                            }
                                            break;
                                        case 3:
                                            ioi.get_plane()->bussiness.display();
                                            cout << "\t\t\t\t\tEnter number of seats      : ";
                                            cin >> seats;
                                            if (ioi.get_plane()->First_Class.book_seats(seats));
                                            {
                                                tyi->set_seats(seats);
                                                tyi->set_seat_type("bussiness");
                                                tyi->set_amount_charged(ioi.get_plane()->bussiness.c_p_seat);
                                                tyi->cost_calculator();
                                                ll = 0;
                                            }
                                            break;
                                        case 4:
                                            ll = 0;
                                            break;
                                        };
                                    }

                                    system("pause");
                                }
                                ll = 1;
                            }
                            else
                                cout << "No flight availabe" << endl;
                            var2 = 0;
                            var4 = 0;
                            break;


                        case 3:
                            r = tyi->receipt();
                            if (r == 1)
                            {
                                tyi->get_flight_confirmed();
                                psg.insert_at_end(*tyi);
                            }
                            else

                                break;
                        case 4:
                            cd = 0;
                            break;

                        }
                    }
                    system("pause");
                    system("cls");
                }
                cd = 1;
                var = 0;
                var2 = 0;
                break;

            case 3:
                system("cls");
                cout << "About Group Members\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << "\nGroup Members: ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "\n1. Ahmed Imran - 200924";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << "\n2. Ahmed Siddique - 200903";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cout << "\n3. Hamza Umer Farooq - 200789";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                cout << "\n4. Sarib Hanif - 201947\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                system("PAUSE");

                break;
            case 4:
                afp = 0;
                break;
            };
        }
        system("pause");
        system("cls");
    }

    system("pause");
    return 0;
}