#include <iostream>
#include <string>
#include <vector>
#include "cl_base.h"
#include "cl_root.h"
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"


using namespace std;

cl_base::cl_base(cl_base* p_parent)
{
    this->p_parent = p_parent;
    if (p_parent != 0)
    {
        this->p_parent->children.push_back(this);
    }
}

cl_base::cl_base(cl_base* p_parent, string name, int number, int readiness)
{
    this->name = name;
    this->p_parent = p_parent;
    if (p_parent != 0)
    {
        this->p_parent->children.push_back(this);
    }
    this->number = number;
    this->readiness = readiness;
}

string cl_base::get_object_name()
{
    return this->name;
}

cl_base::~cl_base()
{
    for (int i = 0; i < this->children.size(); i++)
        delete this->children[i];
}

cl_base* cl_base::search(string name)
{
    if (this->name == name)
    {
        return this;
    }
    for (int i = 0; i < this->children.size(); i++)
    {
        if (this->children[i]->name == name)
        {
            return this->children[i];
        }
    }
    for (int i = 0; i < this->children.size(); i++)
    {
        if (this->children[i]->children.size() != 0)
        {
            cl_base* pointer = children[i]->search(name);
            if (pointer != nullptr)
                return pointer;
        }
    }
    return nullptr;
}

bool cl_base::test_for_uniqueness()
{
    for (int i = 0; i < this->children.size(); i++)
    {
        if (this->children[i]->name == this->name)
            return false;
        if (this->children[i]->children.size() != 0)
            children[i]->test_for_uniqueness();
    }
    return true;
}

void cl_base::readiness_check()
{
    if (this->number == 1)
        cout << "Test result";
    if ((this->search(this->name) != nullptr) && (this->readiness > 0) && (this->test_for_uniqueness() == true))
    {
        cout << endl << "The object " << this->name << " is ready";
    }
    else
    {
        cout << endl << "The object " << this->name << " is not ready";
    }
    for (int i = 0; i < this->children.size(); i++)
    {
        children[i]->readiness_check();
    }
}

void cl_base::showtree(int counter)
{
    if (this->number == 1)
        cout << "Object tree";
    cout << endl;
    for (int i = 0; i < counter; i++)
        cout << "    ";
    counter++;
    cout << this->name;
    for (int i = 0; i < this->children.size(); i++)
    {
        this->children[i]->showtree(counter);
    }
}

cl_base* cl_base::search_coordinates(string coordinates)
{
    string m_coordinates;
    coordinates.erase(0, 1);
    int number = coordinates.find('/');
    if (number == -1)
    {
        m_coordinates = coordinates;
        coordinates.erase(0, coordinates.size());
    }
    else
    {
        for (int i = 0; i < number; i++)
            m_coordinates.push_back(coordinates[i]);
        coordinates.erase(0, number);
    }
    if (this->name == m_coordinates)
    {
        if (coordinates.size() == 0)
            return this;
        for (int i = 0; i < this->children.size(); i++)
        {
            cl_base* pointer = this->children[i]->search_coordinates(coordinates);
            if (pointer != nullptr)
                return pointer;
        }
    }
    return nullptr;
}

void cl_base::set_connect(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER p_ob_hendler)
{
    o_sh* p_value;
    for (unsigned int i = 0; i < connects.size(); i++)
    {
        if (connects[i]->p_signal == p_signal && connects[i]->p_cl_base == p_object && connects[i]->p_hendler == p_ob_hendler)
            return;
    }
    p_value = new o_sh();
    p_value->p_signal = p_signal;
    p_value->p_cl_base = p_object;
    p_value->p_hendler = p_ob_hendler;
    connects.push_back(p_value);
}

void cl_base::delete_connect(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER p_ob_hendler)
{
    if (connects.empty())
        return;
    for (unsigned int i = 0; i < connects.size(); i++)
    {
        if (connects[i]->p_signal == p_signal && connects[i]->p_cl_base == p_object && connects[i]->p_hendler == p_ob_hendler)
            connects.erase(connects.begin() + i);
    }
}

void cl_base::emit_signal(TYPE_SIGNAL p_signal, string& s_command)
{
    if (connects.empty())
        return;
    string forename = this->get_object_name();
    it = connects.begin();
    for (it; it != connects.end(); it++)
    {
        if ((*(it))->p_signal == p_signal)
        {
            cout << endl;
            (this->*((*(it))->p_signal))(s_command);
            (((*(it))->p_cl_base)->*((*(it))->p_hendler))(s_command);
            cout << forename << " -> " << s_command;
        }
    }
}