#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
const long long LIMIT = 1e9;
using task = pair<string, long long>;

void run_program(vector<task> &program, long long pram) {
    vector<long long> st = {pram};
    bool error_flag = false;
    for (auto[name, pram] : program) {
        // st size : 0
        if (name == "NUM") {
            st.push_back(pram);
        }
        else {
            // st size : 1
            if (st.empty()) {
                error_flag = true;
                break;
            }
            if (name == "POP") {
                st.pop_back();
            }
            else if (name == "INV") {
                st.back() *= -1;
            }
            else if (name == "DUP") {
                st.push_back(st.back());
            }
            else {
                // st size : 2
                if ((int)st.size() < 2) {
                    error_flag = true;
                    break;
                }
                long long a, b;
                a = st.back(); st.pop_back();
                b = st.back(); st.pop_back();
                if (name == "SWP") {
                    st.push_back(a);
                    st.push_back(b);
                } else if (name == "ADD") {
                    if (abs(b + a) > LIMIT) {
                        error_flag = true;
                        break;
                    }
                    st.push_back(b + a);
                } else if (name == "SUB") {
                    if (abs(b - a) > LIMIT) {
                        error_flag = true;
                        break;
                    }
                    st.push_back(b - a);
                } else if (name == "MUL") {
                    if (abs(b * a) > LIMIT) {
                        error_flag = true;
                        break;
                    }
                    st.push_back(b * a);
                } else if (name == "DIV") {
                    if (a == 0) {
                        error_flag = true;
                        break;
                    }
                    st.push_back(b / a);
                } else if (name == "MOD") {
                    if (a == 0) {
                        error_flag = true;
                        break;
                    }
                    st.push_back(b % a);
                }
            }
        }
    }
    if ((int)st.size() != 1 || error_flag) {
        cout << "ERROR" << '\n';
    } else {
        cout << st.back() << '\n';
    }
}

bool test_case() {
    vector<task> program;
    while (true) {
        string name;
        cin >> name;
        if (name == "QUIT") {
            return false;
        }
        if (name == "END") {
            break;
        } else if (name == "NUM") {
            long long pram;
            cin >> pram;
            program.emplace_back(name, pram);
        } else {
            program.emplace_back(name, -1);
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long pram;
        cin >> pram;
        run_program(program, pram);
    }
    return true;
}

int main() {
    fastio;
    while (test_case()) {
        cout << '\n';
    }
}