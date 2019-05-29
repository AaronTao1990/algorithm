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

int main() {
    char str[] = {"a", "b", "c"};
    String* s = new String(str);
}
