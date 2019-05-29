#import <stdio.h>
#import <string.h>

class String{

public:
    String(const char* str=NULL);
    String(const String &str);
    ~String();

    String  operator + (const String &str) const;
    String& operator = (const String &str);
    String& operator += (const String &str);
    bool    operator == (const String &str) const;
    char&   operator [] (int n) const;

    size_t size() const;
    const char* c_str() const;

private:
    char* data;
    size_t length;
};


String::String(const char* str) {
    if (str == NULL) {
        data = new char[1];
        *data = '\0';
    } else {
        length = strlen(str);
        data = new char[length+1];
        strcpy(data, str);
    }
}

String::String(const String &str) {
    length = str.size();
    data = new char[length+1];
    strcpy(data, str.c_str());
}

String::~String() {
    length = 0;
    delete []data;
}

String String::operator + (const String &str) const {
    String newString;
    newString.length = length + str.size();
    newString.data = new char[newString.length + 1];
    strcpy(newString.data, data);
    strcat(newString.data, str.c_str());
    return newString;
}

String& String::operator = (const String &str) {
    if (this == &str) {
        return *this;
    }

    length = str.size();
    delete []data;
    data = new char[length + 1];
    strcpy(data, str.c_str());
    return *this;
}

String& String::operator += (const String &str) {
    length += str.size();
    char* newData = new char[length+1];
    strcpy(newData, data);
    strcat(newData, str.c_str());
    delete []data;
    data = newData;
    return *this;
}

bool String::operator == (const String &str) const {
    if (length != str.size()) {
        return false;
    }
    return strcmp(data, str.c_str()) ? false : true;
}

char& String::operator [] (int n) const {
    if (n<0 || n>=length) {
        return data[length-1];
    } else {
        return data[n];
    }
}

inline const char* String::c_str() const {
    return data;
}

size_t String::size() const {
    return length;
}

int main() {
    char str[] = {'a', 'b', 'c'};
    String s1(str);
    String s2(s1);
    printf("%s\n", s1.c_str());
    printf("%s\n", s2.c_str());
    printf("%zu\n", s1.size());
    String s3 = s1 + s2;
    printf("%s\n", s3.c_str());
    printf("%zu\n", s3.size());
    String s4 = s3;
    printf("%s\n", s4.c_str());
    printf("%zu\n", s4.size());
    s4 += s3;
    printf("%s\n", s4.c_str());
    printf("%zu\n", s4.size());
    printf("%d\n", s1 == s2);
    printf("%d\n", s1 == s2 ? 0 : 1);
    printf("%c\n", s1[2]);
}
