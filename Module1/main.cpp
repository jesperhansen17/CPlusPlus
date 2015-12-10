//
//  main.cpp
//  Assignment1
//
//  Created by Jesper Hansen on 2015-11-12.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <string>
#include "DDList.h"
#include "DDList.cpp"

void floatTest() {
    std::cout << "#############FloatTest################" << std::endl;
    List<float> myList;
 
    // Test Create empty list
    assert(myList.Check(0));
    
    // Test Push/Pop-Back
    std::cout << "Start test of Push" << std::endl;
    Node<float> *temp;
    temp = myList.Push_Back(3.4f);
    myList.PrintList();
    assert(myList.Check(1));
    
    Node<float> *temp2;
    temp2 = myList.Push_Back(44.22f);
    myList.PrintList();
    assert(myList.Check(2));
    
    myList.Push_Back(12.444f);
    myList.PrintList();
    assert(myList.Check(3));

    myList.Push_Front(85.4f);
    myList.PrintList();
    assert(myList.Check(4));
    std::cout << "Test ended of Push" << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "Start test, retrive First and Last Node" << std::endl;
    Node<float> *pTempNode;
    pTempNode = myList.First();
    std::cout << "Value of first Node: " << pTempNode->data << std::endl;
    myList.PrintList();
    pTempNode = myList.Last();
    std::cout << "Value of last Node: " << pTempNode->data << std::endl;
    myList.PrintList();
    std::cout << "End test, retrive First and Last Node" << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "Start test of Pop" << std::endl;
    myList.Pop_Back();
    myList.PrintList();

    myList.Pop_Front();
    myList.PrintList();
    std::cout << "Test ended of Pop" << std::endl;
    
    std::cout << "" << std::endl;

    std::cout << "Start test of Insert" << std::endl;
    myList.InsertAfter(temp, 500);
    myList.PrintList();
    Node<float> *temp3;
    temp3 = myList.InsertAfter(temp2, 44);
    myList.PrintList();
   
    Node<float> *temp4;
    temp4 = myList.InsertBefore(temp3, 27.98f);
    myList.PrintList();
    myList.InsertBefore(temp4, 756);
    myList.PrintList();
    std::cout << "Stop test of Insert" << std::endl;
    
    try {
        myList.Pop_Front();
        myList.Pop_Front();
        myList.Pop_Front();
        myList.Pop_Front();
        myList.Pop_Front();
        myList.Pop_Front();
        myList.Pop_Front(); // Generates exception
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    }
}

void intTest()
{
    std::cout << "#############IntegerTest################" << std::endl;
    List<int> *myList = new List<int>();
    
    // Test Create empty list
    assert(myList->Check(0));
    
    // Test Push/Pop-Back
    std::cout << "Start test of Push" << std::endl;
    Node<int> *temporary;
    temporary = myList->Push_Back(3);
    myList->PrintList();
    assert(myList->Check(1));
    
    Node<int> *temp2;
    temp2 = myList->Push_Back(44);
    myList->PrintList();
    assert(myList->Check(2));
    
    myList->Push_Back(12);
    myList->PrintList();
    assert(myList->Check(3));
    
    myList->Push_Front(85);
    myList->PrintList();
    assert(myList->Check(4));
    std::cout << "Test ended of Push" << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "Start test, retrive First and Last Node" << std::endl;
    Node<int> *pTempNode;
    pTempNode = myList->First();
    std::cout << "Value of first Node: " << pTempNode->data << std::endl;
    myList->PrintList();
    pTempNode = myList->Last();
    std::cout << "Value of last Node: " << pTempNode->data << std::endl;
    myList->PrintList();
    std::cout << "End test, retrive First and Last Node" << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "Start test of Pop" << std::endl;
    myList->Pop_Back();
    myList->PrintList();
    
    myList->Pop_Front();
    myList->PrintList();
    std::cout << "Test ended of Pop" << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "Start test of Insert" << std::endl;
    myList->InsertAfter(temporary, 500);
    myList->PrintList();
    Node<int> *temp3;
    temp3 = myList->InsertAfter(temp2, 44);
    myList->PrintList();
    
    Node<int> *temp4;
    temp4 = myList->InsertBefore(temp3, 27);
    myList->PrintList();
    myList->InsertBefore(temp4, 756);
    myList->PrintList();
    std::cout << "Stop test of Insert" << std::endl;
    
    delete myList;
}

void stringTest()
{
    std::cout << "#############StringTest################" << std::endl;
    List<std::string> *myList = new List<std::string>();
    
    // Test Create empty list
    assert(myList->Check(0));
    
    // Test Push/Pop-Back
    std::cout << "Start test of Push" << std::endl;
    Node<std::string> *temporary;
    temporary = myList->Push_Back("Jesper");
    myList->PrintList();
    assert(myList->Check(1));
    
    Node<std::string> *temp2;
    temp2 = myList->Push_Back("Daniel");
    myList->PrintList();
    assert(myList->Check(2));
    
    myList->Push_Back("Peter");
    myList->PrintList();
    assert(myList->Check(3));
    
    myList->Push_Front("Andree");
    myList->PrintList();
    assert(myList->Check(4));
    std::cout << "Test ended of Push" << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "Start test, retrive First and Last Node" << std::endl;
    Node<std::string> *pTempNode;
    pTempNode = myList->First();
    std::cout << "Value of first Node: " << pTempNode->data << std::endl;
    myList->PrintList();
    pTempNode = myList->Last();
    std::cout << "Value of last Node: " << pTempNode->data << std::endl;
    myList->PrintList();
    std::cout << "End test, retrive First and Last Node" << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "Start test of Pop" << std::endl;
    myList->Pop_Back();
    myList->PrintList();
    
    myList->Pop_Front();
    myList->PrintList();
    std::cout << "Test ended of Pop" << std::endl;
    
    std::cout << "" << std::endl;
    
    std::cout << "Start test of Insert" << std::endl;
    myList->InsertAfter(temporary, "Karl");
    myList->PrintList();
    Node<std::string> *temp3;
    temp3 = myList->InsertAfter(temp2, "Sara");
    myList->PrintList();
    
    Node<std::string> *temp4;
    temp4 = myList->InsertBefore(temp3, "Emma");
    myList->PrintList();
    myList->InsertBefore(temp4, "Johanna");
    myList->PrintList();
    std::cout << "Stop test of Insert" << std::endl;
    
    delete myList;
}

int main() {
    floatTest();
    intTest();
    stringTest();
    while (true);
    return 0;
}
