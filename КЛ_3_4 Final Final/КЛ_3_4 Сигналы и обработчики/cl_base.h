#ifndef CL_BASE_H
#define CL_BASE_H

#define SIGNALING (cl_base* p_parent, int id, string nameSender, string nameReceiver)
#define HANDLING (cl_base* p_parent, string message, string nameSender)

#include <iostream>

#include <string>

#include <vector>



using namespace std;



class cl_base

{

public:

    cl_base(cl_base* p_parent = 0);

    //New 3.4

    cl_base(cl_base* p_parent, bool infoSender, bool strorageMess);


    //only add vector ID

    cl_base(cl_base* p_parent, bool id);


    //Например 
    cl_base(cl_base* p_parent, bool infoSender, bool strorageMess, bool id) {
    
            if (infoSender) {
                set_object_name("cl_base");
                if (p_parent) {
                    this->p_parent = p_parent;
                    p_parent->addChildInfoSender(this);
                }
                else {
                    this->p_parent = 0;
                }
            }
            if (strorageMess) {
                set_object_name("cl_base");
                if (p_parent) {
                    this->p_parent = p_parent;
                    p_parent->addChildstorageMess(this);
                }
                else {
                    this->p_parent = 0;
                }
            }
            if (id)
            {
                set_object_name("cl_base");
                if (p_parent) {
                    this->p_parent = p_parent;
                    p_parent->addChildInfoSender(this);
                }
                else {
                    this->p_parent = 0;
                }
            }
    };



    //End 3.4

    void set_object_name(string object_name);

  
    string get_object_name(cl_base* p_parent);
    void set_parent(cl_base* p_parent);

    void add_child(cl_base* p_child);

    cl_base* get_child(string object_name);

    void set_state(int c_state);

    int get_state(cl_base* p_parent);


    //New Start 3.4
    void setConnect SIGNALING;
    void deleteConnect();
    void signaling HANDLING;

    void setNameSender(string nameSender);
    string getNameSender(cl_base* p_parent);
    void setNameReceiver(string nameReceiver);
    string getNameReceiver(cl_base* p_parent);
    void setMessageText(string messageText);
    string getMessageText(cl_base* p_parent);
    void setID(int id);
    int getID(cl_base* p_parent);

    void addChildInfoSender(cl_base* p_child);
    void addChildstorageMess(cl_base* p_child);

    // -> Vector info Sender 
    vector <cl_base*> infoSender;
    vector <cl_base*> ::iterator it_iS;

    // -> Vector Message
    vector <cl_base*> storageMess;
    vector <cl_base*> ::iterator it_sM;

    //End Start 3.4




    vector < cl_base* > children;
    vector < cl_base* > ::iterator it_child;
    string text_finish = "endtree";


private:

    string  object_name;

    cl_base* p_parent;

    int    c_state;


    //New 3.4
    int id;
    string nameSender;
    string nameReceiver;
    string messageText;



};



#endif // CL_BASE_H