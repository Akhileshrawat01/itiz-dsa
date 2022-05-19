#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    string value;
    node *next;

    node(string value)
    {
        this->value = value;
        this->next = NULL;
    }
    
};

class hasht
{
    node **table;
    int size;
    int cap;

    int getId(string value)
    {
        int id = 0;
        int cp = 17;
        for (int i = 0; i < 3; ++i)
        {
            id += value[i] * cp;
            id = id % cap;
        }
        return id % cap;
    }

public:
    hasht()
    {
        cap = 20;
        table = new node *[20];
        size = 0;
        for (int i = 0; i < cap; ++i)
            table[i] = NULL;
    }

    

    

    void insert(string value)
    {
        int id = getId(value);
        node *head = table[id];
        while (head != NULL)
        {
            if (head->value == value)
            {
                cout << value << " already exist" << endl;
                return;
            }
        }
        head = table[id];
        node *newnode = new node(value);
        newnode->next = head;
        table[id] = newnode;
    
    }

    void findVal(string value)
    {
        int id = getId(value);
        node *head = table[id];
        while (head != NULL)
        {
            if (head->value == value)
            {
                cout << "Found" << endl;
                cout << head->value << endl;
                return;
            }
        }
        cout << value << "Don't exist" << endl;
        return;
    }

    void del(string value)
    {
        if (size == 0)
        {
            cout << "Table empty" << endl;
        }
        int id = getId(value);
        node *head = table[id];
        node *prev = NULL;
        while (head != NULL)
        {
            if (head->value == value)
            {
                if (prev == NULL)
                {
                    table[id] = head->next;
                    head->next = NULL;
                    delete head;
                    return;
                }
                prev->next = head->next;
                cout << head->value << " is deleted " << endl;
                head->next = NULL;
                delete head;
                return;
            }
            prev = head;
            head = head->next;
        }
        cout << value << " don't exist" << endl;
        return;
    }

    void display()
    {
        for (int i = 0; i < cap; ++i)
        {
            cout << i << ": ";
            node *head = table[i];
            while (head != NULL)
            {
                cout << head->value << "  ";
                head = head->next;
            }
            cout << endl;
        }
    }
};

int main()
{

    hasht hm;
    string s;
    bool flag = true;
    while (flag)
    {
        cout << "1. Insert\n2. Find a value\n3. Delete \n4. Display\n5. Exit\nEnter your choice : " << endl;
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter the string:";
            cin >> s;
            hm.insert(s);
            break;
        }
        case 2:
        {
            cout << "Enter the string:";
            cin >> s;
            hm.findVal(s);
            break;
        }
        case 3:
        {
            cout << "Enter the string:";
            cin >> s;
            hm.del(s);
            break;
        }
        case 4:
        {
            hm.display();
            break;
        }
        case 5:
        {
            flag = false;
            break;
        }
        default:
            cout << "Incorrect value entered" << endl;
            break;
        }
    }

    return 0;
}