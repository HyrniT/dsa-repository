#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

const long long M = 1e9 + 9;
const long long BASE = 31;
const int TABLE_SIZE = 200;

struct Company
{
    string name;
    string profit_tax;
    string address;
    // Company()
    // {
    //     name = "";
    //     profit_tax = "";
    //     address = "";
    // }
    string toString() const
    {
        return name + "|" + profit_tax + "|" + address;
    }
};

struct Node
{
    Company data;
    Node *next;
    Node()
    {
        data = Company();
        next = nullptr;
    }
    Node(Company company)
    {
        data = company;
        next = nullptr;
    }
};


vector<Company> ReadCompanyList(const string& file_name)
{
    vector<Company> companies;
    ifstream file(file_name);
    if (file.is_open())
    {
        string line;
        getline(file, line); // Skip the first line (header)
        while (getline(file, line))
        {
            Company company;

            stringstream ss(line);
            getline(ss, company.name, '|');
            getline(ss, company.profit_tax, '|');
            getline(ss, company.address);

            companies.push_back(company);
        }
        file.close();
    }
    else
    {
        cout << "Cannot open file: " << file_name << endl;
    }
    return companies;
}

void WriteCompanyList(string file_name, const vector<Company> &companies)
{
    ofstream file(file_name);
    if (file.is_open())
    {
        for (const auto &company : companies)
        {
            file << company.name << "|" << company.profit_tax << "|" << company.address << endl;
        }
        file.close();
    }
}
long long power(long long base, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        long long half = power(base, n / 2);
        return (half * half) % M;
    }
    else
    {
        long long half = power(base, (n - 1) / 2);
        return (half * half * base) % M;
    }
}

long long HashString(string company_name)
{
    int n = company_name.length();
    string s = (n > 20) ? company_name.substr(n - 20) : company_name;
    long long sigma = 0;
    long long pow_base = 1;
    for (int i = 0; i < n; i++)
    {
        sigma = (sigma + (int)s[i] * pow_base) % M;
        pow_base = (pow_base * BASE) % M;
    }
    return sigma;
}

Node* CreateHashTable(const vector<Company>& list_company)
{
    Node* hash_table = new Node[TABLE_SIZE]();

    for (const auto& company : list_company)
    {
        long long index = HashString(company.name) % TABLE_SIZE;

        Node* new_node = new Node(company);

        if (hash_table[index].data.name != "")
        {
            Node* current_node = &hash_table[index];
            while (current_node->next != nullptr)
                current_node = current_node->next;
            current_node->next = new_node;
        }
        else
        {
            hash_table[index] = *new_node;
        }
    }

    return hash_table;
}

void Insert(Node* hash_table, const Company& company)
{
    long long index = HashString(company.name) % TABLE_SIZE;

    Node* new_node = new Node(company);

    if (hash_table[index].data.name != "")
    {
        Node* current_node = &hash_table[index];
        while (current_node->next != nullptr)
            current_node = current_node->next;
        current_node->next = new_node;
    }
    else
    {
        hash_table[index] = *new_node;
    }
}

const Company* Search(const Node* hash_table, const string& company_name)
{
    long long index = HashString(company_name) % TABLE_SIZE;

    const Node* current_node = &hash_table[index];
    while (current_node != nullptr)
    {
        if (current_node->data.name == company_name)
        {
            return &current_node->data;
        }
        current_node = current_node->next;
    }

    return nullptr;
}

int main()
{
    vector<Company> companies = ReadCompanyList("MST.txt");
    // for(const auto& company : companies) {
    //     cout << company.toString() << endl;
    // }

    Node* hash_table = CreateHashTable(companies);

    Company new_company;
    new_company.name = "New Company";
    new_company.profit_tax = "10%";
    new_company.address = "123 Main St";
    Insert(hash_table, new_company);

    const Company* search_company = Search(hash_table, "New Company");
    if (search_company != nullptr)
        cout << "Found: " << search_company->name << endl;
    else
        cout << "Not found!" << endl;

    delete[] hash_table;

    return 0;
}

