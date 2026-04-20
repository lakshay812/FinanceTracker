#include <bits/stdc++.h>
void saveT();
void saveB();
using namespace std;
struct T {
    string t, c, d;
    double a;
};

struct B {
    string c;
    double l, s; // limit, spent
};

struct G {
    string n;
    double t, s;
};

vector<G> g;

vector<B> b;

vector<T> v;

void loadG() {
    ifstream f("data/goals.txt");
    if (!f) return;

    G x;
    while (f >> x.n >> x.t >> x.s) {
        g.push_back(x);
    }
}

void saveG() {
    ofstream f("data/goals.txt");
    for (auto &x : g) {
        f << x.n << " " << x.t << " " << x.s << "\n";
    }
}

void loadT() {
    ifstream f("data/transactions.txt");
    if (!f) return;

    T x;
    while (f >> x.t >> x.a >> x.c >> x.d) {
        v.push_back(x);
    }
}

void loadB() {
    ifstream f("data/budgets.txt");
    if (!f) return;

    B x;
    while (f >> x.c >> x.l >> x.s) {
        b.push_back(x);
    }
}

void saveB() {
    ofstream f("data/budgets.txt");
    for (auto &x : b) {
        f << x.c << " " << x.l << " " << x.s << "\n";
    }
}

void saveT() {
    ofstream f("data/transactions.txt");
    for (auto &x : v) {
        f << x.t << " " << x.a << " " << x.c << " " << x.d << "\n";
    }
}
void addT() {
    T x;

    cout << "Type (income/expense): ";
    cin >> x.t;

    cout << "Amount: ";
    cin >> x.a;

    cout << "Category: ";
    cin >> x.c;

    cout << "Date: ";
    cin >> x.d;

    v.push_back(x);

    if (x.t == "expense") {
        bool found = false;

        for (auto &y : b) {
            if (y.c == x.c) {
                y.s += x.a;
                found = true;
            }
        }

        // ⚠ warn if no budget exists
        if (!found) {
            cout << "⚠ No budget set for this category!\n";
        }
    }

    // ✅ save data
    saveT();
    saveB();

    cout << "✅ Transaction added successfully!\n";
}
void viewT() {
    cout << "\n--- Transactions ---\n";
    for (int i = 0; i < v.size(); i++) {
        cout << i + 1 << ". "
             << v[i].t << " | "
             << v[i].a << " | "
             << v[i].c << " | "
             << v[i].d << "\n";
    }
}

void dash() {
    double inc = 0, exp = 0;

    for (auto &x : v) {
        if (x.t == "income") inc += x.a;
        else if (x.t == "expense") exp += x.a;
    }

    cout << "\n--- Dashboard ---\n";
    cout << "Total Income: " << inc << "\n";
    cout << "Total Expense: " << exp << "\n";
    cout << "Balance: " << inc - exp << "\n";
}


void setB() {
    string c;
    double l;

    cout << "Category: ";
    cin >> c;
    cout << "Limit: ";
    cin >> l;

    for (auto &x : b) {
        if (x.c == c) {
            x.l = l;
            cout << "Budget updated!\n";
            saveB();
            return;
        }
    }

    B x;
    x.c = c;
    x.l = l;
    x.s = 0;

    b.push_back(x);
    saveB();
}


void viewB() {
    cout << "\n--- Budgets ---\n";

    for (auto &x : b) {
        double p = 0;
        if (x.l > 0) p = (x.s / x.l) * 100;

        cout << x.c << " | " << x.s << "/" << x.l
             << " (" << p << "%)\n";

        if (p > 100)
            cout << "🚨 Over Budget!\n";
        else if (p >= 80)
            cout << "⚠ Near Limit!\n";
    }
}

void goals() {
    int ch;
    cout << "\n1. Add Goal\n2. Add Savings\n3. View Goals\nChoice: ";
    cin >> ch;

    if (ch == 1) {
        G x;
        cout << "Name: ";
        cin >> x.n;
        cout << "Target: ";
        cin >> x.t;
        x.s = 0;

        g.push_back(x);
        saveG();
    }
    else if (ch == 2) {
        int i;
        double amt;

        cout << "Goal index: ";
        cin >> i;
        cout << "Amount: ";
        cin >> amt;

        if (i >= 1 && i <= g.size()) {
            g[i - 1].s += amt;
            saveG();
        }
    }
    else {
        for (int i = 0; i < g.size(); i++) {
            auto &x = g[i];
            double p = (x.s / x.t) * 100;

            cout << i + 1 << ". "
                 << x.n << " | "
                 << x.s << "/" << x.t
                 << " (" << p << "%)\n";
        }
    }
}

void tips() {
    cout << "\n--- Financial Tips ---\n";
    cout << "1. 50/30/20 Rule\n";
    cout << "   - 50% Needs, 30% Wants, 20% Savings\n\n";

    cout << "2. Emergency Fund\n";
    cout << "   - Save 3-6 months of expenses\n\n";

    cout << "3. Track Every Expense\n";
    cout << "   - Helps identify wasteful spending\n\n";

    cout << "4. Avoid Impulse Buying\n";
    cout << "   - Wait before making big purchases\n\n";

    cout << "5. Save Before Spending\n";
    cout << "   - Pay yourself first\n\n";

    cout << "6. Use Budget Categories\n";
    cout << "   - Control spending better\n\n";

    cout << "7. Invest Early\n";
    cout << "   - Benefit from compounding\n\n";
}


int main() {

    loadT();
    loadB();
    loadG();

    while (1) {
    cout << "\n==============================\n";
    cout << "   PERSONAL FINANCE TRACKER\n";
    cout << "==============================\n";
    cout << "1. Dashboard\n";
    cout << "2. Add Transaction\n";
    cout << "3. View Transactions\n";
    cout << "4. Set Budget\n";
    cout << "5. View Budget\n";
    cout << "6. Goals\n";
    cout << "7. Tips\n";
    cout << "8. Exit\n";
    cout << "\n------------------------------\n";

    int ch;
    cin >> ch;

    if (ch == 1) dash();
    else if (ch == 2) addT();
    else if (ch == 3) viewT();
    else if (ch == 4) setB();
    else if (ch == 5) viewB();
    else if (ch == 6) goals();
    else if (ch == 7) tips();
    else if (ch == 8) break;
    else cout << "Invalid choice\n";
    }
}