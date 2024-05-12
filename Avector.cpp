//
// Created by navykid75 on 2024-04-11.
//

#include <iostream>
using namespace std;

class Kvector{
protected:
    int *m;
    int len;

public:
    Kvector(int sz = 0, int value = 0){
        len = sz;
        if(sz == 0) m = NULL;
        else{
            m = new int[len];
            for(int i = 0; i < len; i++) m[i] = value;
        }
    }
    Kvector(const Kvector& v) {
        len = v.len;
        if(len == 0) m = NULL;
        else{
            m = new int[len];
            for(int i = 0; i < len; i++){
                m[i] = v.m[i];
            }
        }

    }
    ~Kvector(){
        // cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    void print() const{
        for(int i = 0; i < len; i++) cout << m[i] << " ";
        cout << "\n";
    }
    void clear(){
        delete[] m;
        m = NULL;
        len = 0;
    }
    int size(){return len;}

    Kvector& operator = (const Kvector& other){
        if (this == &other){
            return *this;
        }

        this -> len = other.len;
        m = new int[other.len];

        for(int i = 0; i < other.len; i++){
            this -> m[i] = other.m[i];
        }
        return *this;
    }

    bool operator==(const Kvector& other){
        if (this -> len == other.len){
            for(int i = 0; i < other.len; i++){
                if (this -> m[i] != other.m[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool operator!=(const Kvector& other){
        if(this -> len != other.len) return true;
        for(int i = 0; i < other.len; i++){
            if(this -> m[i] != other.m[i]) return true;
        }
        return false;
    }

    int& operator[](int index){
        return this -> m[index];
    }

    friend ostream& operator<<(ostream& os, const Kvector& obj) {
        for(int i = 0; i < obj.len; i++){
            os << obj.m[i] << " ";
        }
        return os;
    }

};

class Avector : public Kvector{

    char table[3]; // 0, 1, 2

public:
    Avector(int size = 0, int value = 0, const char *s = "abc") : Kvector(size, value){
        setTable(s);
    }

    void setTable(const char *s){
        for(int i = 0; i < 3; i++) table[i] = s[i];
    }

    friend ostream& operator<<(ostream& os, const Avector& v){
        for(int j = 0; j < v.len; j++){
            os << v.table[v.m[j]%3] << " ";
        }
        return os;
    }
};

int main(){
    Avector v1(3); v1.print();
    Avector v2(2, 1, "xyz"); v2.print();
    Avector v3(v2); v3.print();

    cout << "v1 == v2 " << (v1 == v2) << endl;
    cout << "v3 == v2 " << (v3 == v2) << endl;

    v3 = v2 = v1;

    cout << "v1 : " << v1 << endl;
    v1.print();
    cout << "v2 : " << v2 << endl;
    v2.print();
    cout << "v3 : " << v3 << endl;
    v3.print();

    cout << "v3 != v2 " << (v3 != v2) << endl;

    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable("pqr");

    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}