//
// Created by Lucas Orlikoski on 09/08/2021.
//

#ifndef GAME_NEW_LISTA_HPP
#define GAME_NEW_LISTA_HPP

#include "lib.hpp"

template <class L>
class Lista{
    template <class N>
    class Node{
        Node* nxt;
        Node* prv;
        N* info;
    public:
        Node(){
            nxt = NULL;
            prv = NULL;
            info = NULL;
        }
        ~Node(){
            nxt = NULL;
            prv = NULL;
            info = NULL;
        }
        void setNext(Node<N>* pNext) { nxt = pNext; }
        
        Node<N>* getNext() { return nxt; }

        void setPrevious(Node<N>* pPrevious) { prv = pPrevious; }

        Node<N>* getPrevious() { return prv; }

        void setInfo(N* pInfo) { info = pInfo; }
        
        N* getInfo() { return info; }

    };

    Node<L>* first;
    Node<L>* last;
    int size;
public:
    Lista(){
        first = NULL;
        last = NULL;
        size = 0;
    }
    ~Lista(){
        first = NULL;
        last = NULL;
    }
    void add(L* info);
    void remove(L* info);
    int length() {return size;};
    void clear();
};

template <class L>
void Lista<L>::add(L* info){
    Node<L>* novo = new Node<L>;
    novo->setInfo(info);
    if(last == NULL){
        last = novo;
        first = novo;
    }
    else{
        last->setNext(novo);
        novo->setPrevious(last);
        last = novo;
    }
    size++;
}
template <class L>
void Lista<L>::remove(L* info) {
    Node<L>* aux = first;
    Node<L>* aux2;
    while(aux->getInfo() != info)
        aux = aux->getNext();
    aux2 = aux->getPrevious();
    aux2->setNext(aux->getNext());
    aux2 = aux->getNext();
    aux2->setPrevious(aux->getPrevious());
    delete aux;
}
template <class L>
void Lista<L>::clear() {
    Node<L>* aux;
    while (first != NULL){
        aux = last;
        last = last->getPrevious();
        delete aux;
        size--;
    }
}
#endif