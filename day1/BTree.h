//
//  BTree.h
//  OpenCV
//
//  Created by Daniil Vinogradov on 31.01.17.
//  Copyright © 2017 noname. All rights reserved.
//

#ifndef BTree_h
#define BTree_h

#include <iostream>

using namespace std;


template < typename T >
class BTree{
    
    struct Node{
        int key;
        T data;
        Node *left;
        Node *right;
    };
    
private:
    Node *root;
    
public:
    
    BTree(){
        root = NULL;
    }
    
    BTree(const BTree &tree){
        //*root = tree.getRoot();
    }
    
    ~BTree(){
        //cout << "Я тутачки" << endl;
        delete root;
    }
    
    const Node getRoot() const {
        return *root;
    }
    
    void put(int key, T value){
        Node **n = &root;
        while (*n != NULL){
            if (key < (*n)->key){
                n = &(*n)->left;
            }
            else if (key > (*n)->key){
                n = &(*n)->right;
            }
            else
                break;
        }
        
        *n = new Node;
        (*n)->key = key;
        (*n)->data = value;
        (*n)->left = NULL;
        (*n)->right = NULL;
    }
    
    T get(int key){
        Node **n = &root;
        while(true){
            if (key ==(*n)->key){
                return (*n)->data;
            }
            else if (key < (*n)->key){
                if ((*n)->left == NULL){
                    throw std::out_of_range ("Unknown object");
                }
                n = &(*n)->left;
            }
            else if (key > (*n)->key){
                if ((*n)->right == NULL){
                    throw std::out_of_range ("Unknown object");
                }
                n = &(*n)->right;
            }
        }
    }
    
    void remove(int key){
        Node **n = &root;
        while(true){
            if (key ==(*n)->key){
                break;
            }
            else if (key < (*n)->key){
                if ((*n)->left == NULL){
                    throw std::out_of_range ("Unknown object");
                }
                n = &(*n)->left;
            }
            else if (key > (*n)->key){
                if ((*n)->right == NULL){
                    throw std::out_of_range ("Unknown object");
                }
                n = &(*n)->right;
            }
        }
        if ((*n)->right == NULL){
            *n = (*n)->left;
        }
        else {
            Node **temp = &(*n)->right;
            Node **parent = NULL;
            while((*temp)->left != NULL){
                parent = temp;
                temp = &(*temp)->left;
            }
            
            Node *right = (*temp)->right;
            
            (*temp)->left = (*n)->left;
            (*temp)->right = (*n)->right;
            *n = *temp;
            (*parent)->left = right;
        }
    }
    
};

#endif /* BTree_h */
