#include <iostream>
#include <cstring>

using namespace std;

struct NODE
{
    int key;
    NODE *pNext;
};

struct Stack
{
    NODE *p_top;
};

struct Queue
{
    NODE *p_head;
    NODE *p_tail;
};

// Viết hàm đọc theo một chuỗi ký tự và in chúng theo thứ tự ngược lại
void ReverseString(char *s)
{
    Stack st;
    st.p_top = NULL;
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        NODE *p = new NODE();
        p->key = s[i];
        p->pNext = st.p_top;
        st.p_top = p;
    }

    while (st.p_top != NULL)
    {
        cout << (char)st.p_top->key;
        NODE *p = st.p_top;
        st.p_top = st.p_top->pNext;
        delete p;
    }
}

// Viết chương trình đọc trong một chuỗi ký tự và xác định xem dấu ngoặc đơn (), dấu ngoặc nhọn {} và dấu ngoặc
// vuông [ ] của nó có "cân bằng" hay không
bool isOpeningBracket(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool isClosingBracket(char c)
{
    return (c == ')' || c == '}' || c == ']');
}

char getMatchingOpeningBracket(char c)
{
    if (c == ')')
        return '(';
    if (c == '}')
        return '{';
    if (c == ']')
        return '[';
    return '\0'; // invalid character
}

void CheckBalance(char *s)
{
    Stack st;
    st.p_top = NULL;
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (isOpeningBracket(s[i]))
        {
            NODE *p = new NODE;
            p->key = s[i];
            p->pNext = st.p_top;
            st.p_top = p;
        }
        else if (isClosingBracket(s[i]))
        {
            if (st.p_top == NULL || st.p_top->key != getMatchingOpeningBracket(s[i]))
            {
                cout << "false";
                return;
            }
            else
            {
                NODE *p = st.p_top;
                st.p_top = st.p_top->pNext;
                delete p;
            }
        }
    }

    if (st.p_top == NULL)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

// Viết chương trình đọc một số nguyên dương và in ra biểu diễn nhị phân của số nguyên đó
void DecToBin(int dec)
{
    Stack st;
    st.p_top = NULL;

    while (dec > 0)
    {
        int remainder = dec % 2;
        NODE *p = new NODE;
        p->key = remainder + '0';
        p->pNext = st.p_top;
        st.p_top = p;
        dec = dec / 2;
    }

    if (st.p_top == NULL)
    {
        cout << "0";
    }
    else
    {
        while (st.p_top != NULL)
        {
            cout << (char)st.p_top->key;
            NODE *p = st.p_top;
            st.p_top = st.p_top->pNext;
            delete p;
        }
    }
}

int main()
{
    // Test ReverseString
    char s1[] = "Hello world!";
    ReverseString(s1);
    cout << endl;

    // Test CheckBalance
    char s2[] = "(a+b)*(c+d)}";
    CheckBalance(s2);
    cout << endl;

    // Test DecToBin
    int n = 7;
    DecToBin(n);
    cout << endl;
}
