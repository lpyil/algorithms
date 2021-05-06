#include <iostream>


// ==========================================================================================

// define struct
struct Node{
    int data;
    struct Node* next;
};

// initialize first & last
Node *first = nullptr;
Node *last = nullptr;


// push func
void push(int data);

// pop func
void pop();

// insert
void insert();

// remove (by place)
void remove(int place);

// display
void display();

// option
void option(int opt);


// main code
int main() {
    int num;
    int opt;

    while (true){
        display();
        std::cout << "\n\n1-Push\n2-Insert\n3-Pop\n4-Remove\n\nOpt: ";
        std::cin >> opt;

        option(opt);
    }


    display();

    return 0;
}


// --------------
void insert(int data, int place){
    Node* temp = new Node;
    temp->data = data;

    // if placing at first place
    if (place == 0){

        temp->next = first;
        first = temp;
    }

    // else go to the node before destination
    else{
        Node* walk = first;

        for(int i=0; i<place - 1; i++)
            walk = walk->next;

        temp->next = walk->next;
        walk->next = temp;
    }
}


// --------------
void push(int data){
    // create the node and insert the data
    Node *temp = nullptr;
    temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    // insert the node to the list
    if (first == nullptr){
        first = temp;
        last = first;
    }

    else {
        last->next = temp;
        last = temp;
    }
}


// --------------
void pop(){
    // do nothing if empty
    if (first == nullptr)
        std::cout << "\nList is empty" << std::endl;

    // delete first if there is only one node
    else if (first == last){
        delete first;
        first = nullptr;
    }

    // go to second-to-last node and delete the next node
    else{
        Node* walk = first;

        while (walk->next->next != nullptr)
            walk = walk->next;

        delete walk->next;
        walk->next = nullptr;
        last = walk;
    }
}


// --------------
void remove(int place) {
    // if first, delete
    if (place == 0) {
        if (first->next)
        delete first;
        first = nullptr;
    }

    // go to second-to-last node and delete the next node
    else{
        Node* walk = first;
        Node* temp;

        for(int i=0; i<place - 1; i++)
            walk = walk->next;

        temp = walk->next->next;
        delete walk->next;
        walk->next = temp;

    }
}

// --------------
void display(){
    // walk till the end
    Node *walk = first;

    int i = 0;
    while (walk != nullptr){
        std::cout << i << "-(" << walk->data << ")   ";
        walk = walk->next;
        i++;
    }
}


//---------------
void option(int opt){
    int data;
    int place;

    if (opt == 1){
        std::cout << "\nData: ";
        std::cin >> data;

        push(data);
    }

    else if (opt == 2){
        std::cout << "\nData: ";
        std::cin >> data;

        std::cout << "\nPlace: ";
        std::cin >> place;

        insert(data, place);
    }

    else if (opt == 3){
         pop();
    }

    else if (opt == 4){
        std::cout << "\nPlace: ";
        std::cin >> place;

        remove(place);
    }
}



// ==========================================================================================










