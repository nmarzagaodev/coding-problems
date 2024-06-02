// Implementation of a ArrayList
// Inspired by: https://www.w3schools.com/java/java_arraylist.asp

#include <iostream>
#include <string>

using namespace std;

template<typename T>

class ArrayList {
private:
    T* items;
    size_t capacity;
    size_t size;

public:
    ArrayList() : items(new T[5]), size(5), capacity(-1) {};

    void add(T item) {
        if (++this->capacity == this->size) {
            size_t newSize = this->size * 2;
            T* newItems    = new T[newSize];

            for (size_t i = 0; i < this->size; i++)
                newItems[i] = this->items[i];

            delete[] this->items;
            this->items = newItems;
            this->size = newSize;
        }

        this->items[this->capacity] = item;
    }

    T& get(size_t index) {
        if (index >= this->capacity) 
            throw out_of_range("ArrayList.get(): Index out of bounds");
        return this->items[index];
    }
    
    void set(size_t index, T item) {
        if (index >= this->capacity) 
            throw out_of_range("ArrayList.set(): Index out of bounds");
        this->items[index] = item;
    }

    void remove(size_t index) {
        if (index >= this->capacity) 
            throw out_of_range("ArrayList.remove(): Index out of bounds");
        this->items[index] = T();
    }

    void clear() {
        for (size_t i = 0; i < this->size; i++)
            this->items[i] = T();
        this->capacity = -1;
    }

    size_t getSize() {
        return this->capacity;
    }

    ~ArrayList() {
        delete[] this->items;
    }

    class Iterator {
    private:
        T* curr;

    public:
        Iterator(T* c) : curr(c) {};

        T& operator*() { return *curr; };
        
        Iterator& operator++() {
            ++curr;
            return *this;
        }

        Iterator& operator--() {
            --curr;
            return *this;
        }
        
        bool operator!=(const Iterator& other) const { return curr != other.curr; }
        bool operator==(const Iterator& other) const { return curr == other.curr; }

    };

    Iterator begin() { return Iterator(items); };
    Iterator end()   { return Iterator(items + size); };
};