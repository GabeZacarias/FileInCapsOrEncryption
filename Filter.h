#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Filter
{
    public:
        void doFilter(fstream& in, fstream& out);
        virtual char transform(char ch) = 0;
};

void Filter::doFilter(fstream& in, fstream& out)
{
    char ch;
    char transformChar;

    in.get(ch);

    while (!in.fail())
    {
        transformChar = transform(ch);
        out.put(transformChar);
        in.get(ch);
    }
};



class UpperCaseFilter : public Filter
{
    public:
        char transform(char ch)
        {
            char outputUpper = toupper(ch);
            cout << outputUpper;
            return toupper(ch);
        }
};

class EncryptionFilter: public Filter
{
    protected:
        char transform(char ch)
        {
            char encrypt123 = (char)ch+5;
            cout << encrypt123;
            return encrypt123;
        }
};


#endif // FILTER_H_INCLUDED
