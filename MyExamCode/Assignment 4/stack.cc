#include <iostream>
#include <vector>

class Stack
{
protected:
    std::vector<int> stack{};
public:
    unsigned int size() const {
        return stack.size();
    }

    std::string to_string() const {
        std::string tmp{""};
        for (int i = stack.size()-1; i >= 0; i--) {
            tmp.append(std::to_string(stack.at(i)));
            tmp.append(" ");
        }
        return tmp;
    }

    friend Stack& operator<<(Stack& st, const int& val) {
        st.stack.push_back(val);
        return st;
    }

    friend Stack& operator>>(Stack& st, int& val) {
        val = st.stack.at(st.size()-1);
        st.stack.pop_back();
        return st;
    }
};

int main()
{
    Stack st{};

    st << 3 << 2 << 1;
    std::cout << st.to_string()<< std::endl;

    while (st.size() > 0)
    {
        int value;
        st >> value;
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}
