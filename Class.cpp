#include "Header.h"
using namespace std;

    void search(list<string> LIST) {
        stack<int> STACK;

        int count = 0;

        regex searchError("google");
        string replacement = "yandex";
        for (auto l : LIST) {

            l = regex_replace(l, searchError, replacement);
            cout << l << endl;
        }

        regex searchParagraf("<p[^>]*>(.*?)</p>");
        for (auto l : LIST) {
            for (sregex_iterator it(l.begin(), l.end(), searchParagraf), end; it != end; ++it) {
                cout << it->str(1) << endl;
                count++;
            }
        }
        cout << endl;
      
        
        STACK.push(count);
        count = 0;

       
        regex searchHead("<(h[1-6]|H[1-6])[^>]*>(.*?)</(h[1-6]|H[1-6])>");
        for (auto l : LIST) {
            for (sregex_iterator it(l.begin(), l.end(), searchHead), end; it != end; ++it) {
               
                cout << it->str(2) << endl;
                count++;
            }
        }
        
        STACK.push(count);
        count = 0;

        regex searchItalics("<I[^>]*>(.*?)</I>");
        for (auto l : LIST) {
            for (sregex_iterator it(l.begin(), l.end(), searchItalics), end; it != end; ++it) {
                cout << it->str(1) << endl;
                
                count++;
            }
        }
        STACK.push(count);
        cout << "Елементов с тегом <I> :" << STACK.top() << endl;
        STACK.pop();
        cout << "Елементов с тегом <h[1-6]> :" << STACK.top() << endl;
        STACK.pop();
        cout << "Елементов с тегом <p> :" << STACK.top() << endl;
        STACK.pop();
      
     

    }

   