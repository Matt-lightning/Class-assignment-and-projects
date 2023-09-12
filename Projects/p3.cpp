#include <iostream>
#include <string>

#include "p3.h"

using namespace std;

Person::Person()
{
    this->height = 0;
    this->weight = 0;
    this->nextHeight = nullptr;
    this->nextWeight = nullptr;
}

Person::Person(string first, string last, int height, int weight)
{
    this->first = first;
    this->last = last;
    this->height = height;
    this->weight = weight;
    this->nextHeight = nullptr;
    this->nextWeight = nullptr;
}

PersonList::PersonList()
{
    this->size = 0;
    this->headHeightList = nullptr;
    this->headWeightList = nullptr;
}

int PersonList::getSize()
{
    return size;
}

void PersonList::printByHeight(ostream &os)
{
    Person* cr = headHeightList;
    while(cr != nullptr){
        os << cr->first << " " << cr->last << ": height=" << cr->height << " " << "weight=" << cr->weight << endl;

        cr = cr->nextHeight; 
    }
}

void PersonList::printByWeight(ostream &os)
{
    Person* cr = headWeightList;
    while(cr != nullptr){
        os << cr->first << " " << cr->last << ": height=" << cr->height << " " << "weight=" << cr->weight << endl;

        cr = cr->nextWeight; 
    }

}

bool PersonList::exists(string first, string last)
{
    Person* cr = headWeightList;
    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
            return true;
        }

        cr = cr->nextWeight;
    }
    return false;
}

int PersonList::getHeight(string first, string last) {
    Person* cr = headHeightList;
    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
            return cr->height;
        }

        cr = cr->nextHeight;
    }

    return -1;
}

int PersonList::getWeight(string first, string last) {
    Person* cr = headWeightList;
    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
            return cr->weight;
        }

        cr = cr->nextWeight;
    }
    return -1;
}

bool PersonList::add(string first, string last, int height, int weight)
{
   if (this->exists(first, last))
    {
        return false;
    } 
    Person *p = new Person(first, last, height, weight);
    Person* cr = headHeightList;

    p->nextHeight = this->headHeightList;
	this->headHeightList = p; 

    if(p->height > headHeightList->height){
        p->nextHeight = headHeightList;
        headHeightList = p;
    }
    else{
        while(cr->nextHeight != nullptr && cr->nextHeight->height > p->height){
            
            cr = cr->nextHeight;
    }
        p->nextHeight = cr->nextHeight;
        cr->nextHeight = p;
    }

     //Person* cr = headWeightList;

    p->nextWeight = this->headWeightList;
	this->headWeightList = p; 

    if(p->weight > headWeightList->height){
        p->nextWeight = headWeightList;
        headWeightList = p;
    }
    else{
        while(cr->nextWeight != nullptr && cr->nextWeight->weight > p->weight){
            
            cr = cr->nextWeight;
    }
        p->nextWeight = cr->nextWeight;
        cr->nextWeight = p;
    }
   
    
    
    /*
    Person *p = new Person(first, last, height, weight);
    Person* cr = headHeightList;
    Person* prev = nullptr;

	// add it to "headHeightList"
    while(cr->height != nullptr){
	p->nextHeight = this->headHeightList;
	this->headHeightList = p; 
    }
	// add it to "headWeightList"
	p->nextWeight = this->headWeightList;
	this->headWeightList = p; 

	return true;*/
}

bool PersonList::remove(string first, string last)
{
   /* Person* cr1 = headHeightList;
    Person* cr2 = headWeightList;

    while(cr1 != nullptr){
        if(cr1->first == first && cr1->last == last){
            remove(cr);
        }

        cr1 = cr1->nextHeight;
    }
    while(cr2 != nullptr){
        if(cr2->first == first && cr2->last == last){
            remove(cr);
        }

        cr2 = cr2->nextWeight;
    }*/

    Person* pv = nullptr;
    Person* cr = headHeightList;

    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
            if(pv == nullptr){
                headHeightList = cr->nextHeight;
            }
            else{
                pv->nextHeight = cr->nextHeight;
            }

            delete cr;
            size--;
            return true;
        }
        pv = cr;
        cr = cr->nextHeight;

    }

   // Person* pv = nullptr;
    //Person* cr = headWeightList;

    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
            if(pv == nullptr){
                headWeightList = cr->nextWeight;
            }
            else{
                pv->nextWeight = cr->nextWeight;
            }

            delete cr;
            size--;
            return true;
        }
        pv = cr;
        cr = cr->nextWeight;

    }
    return false;
}

bool PersonList::updateName(string first, string last, string newFirst, string newLast)
{
    Person* cr = headHeightList;
    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
            cr->first = newFirst;
            cr->last = newLast;
            return true;
        }

        cr = cr->nextHeight;
    }

    return false;
}

bool PersonList::updateHeight(string first, string last, int height)
{
    /* Person* cr = headHeightList;

    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
            break;
        }
        cr = cr->nextHeight;
    }

    if(cr != nullptr){
        remove(cr);

        cr->height = height;

        insert(cr);

        return true;

    }

    return false;*/

    Person* cr = headHeightList;
    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
           cr->height = height;
            return true;
        }

        cr = cr->nextHeight;
    }

    return false;

   
}

bool PersonList::updateWeight(string first, string last, int weight)
{
      /*Person* cr = headWeightList;

    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
            break;
        }
        cr = cr->nextWeight;
    }

    if(cr != nullptr){
        remove(cr);

        cr->weight = weight;

        insert(cr);

        return true;

    }

    return false;*/

    Person* cr = headWeightList;
    while(cr != nullptr){
        if(cr->first == first && cr->last == last){
           cr->weight = weight;
            return true;
        }

        cr = cr->nextWeight;
    }

    return false;

   
}


PersonList::~PersonList()
{
    
    Person* crH = headHeightList;
    //Person* crW = headWeightList;
    Person* pvH = nullptr;
   // Person* pvW = nullptr;

    while(crH != nullptr){
        pvH = crH;
        crH = crH->nextHeight;
        delete pvH;
    }
    headHeightList = nullptr;

    // while(crW != nullptr){
    //     pvW = crW;
    //     crW = crW->nextWeight;
    //     delete pvW;
    // }
    headWeightList = nullptr;

    size = 0;

}

void PersonList::deepCopy(const PersonList &src){
    if (src.headWeightList == nullptr) {
    return;
    }
    /*
    headWeightList = new WeightNode(src.headWeightList->weight, nullptr);

    
    WeightNode* srcNode = src.headWeightList->next;
    WeightNode* destNode = headWeightList;
    while (srcNode != nullptr) {
        destNode->next = new WeightNode(srcNode->weight, nullptr);
        destNode = destNode->next;
        srcNode = srcNode->next;
    }
    
    size = src.size;*/
    //Person* copy = new Person(src);


    


      


}

PersonList::PersonList(const PersonList &src)
{ //deepCopy
    

    headHeightList = nullptr;
    headWeightList = nullptr;
    size = 0;

    deepCopy(src);
}

const PersonList &PersonList::operator=(const PersonList &src)
{ //  clear then deepcpoy 
    if(this != &src){

        this->~PersonList();
        
        deepCopy(src);

    }
    return *this;
}

// size = src.size;
    // data = new Person[size];

    // for (int i = 0; i < size; i++) {
    //     data[i] = src.data[i];
    // }

/*
    for each node in src (either height or weight list, pick one)
        add(n->first, n->last, n->height, n->weight)
    */

        // for(int i = 0; i < src.size; i++){
        //     Person* nperson = new Person(src.data[i]);
        //     insert(nperson);

        // }

        /*
        for each node in src (either height or weight list, pick one)
            add(n->first, n->last, n->height, n->weight)
        */