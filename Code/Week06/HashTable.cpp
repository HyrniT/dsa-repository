#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct Company
{
    string name;
    string profit_tax;
    string address;
};

vector<Company> ReadCompanyList(string file_name)
{
    vector<Company> companies;
    ifstream file(file_name);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            Company company;
            // int pos1 = line.find("|");
            // int pos2 = line.find("|", pos1 + 1);
            // company.name = line.substr(0, pos1);
            // company.profit_tax = line.substr(pos1 + 1, pos2 - pos1 - 1);
            // company.address = line.substr(pos2 + 1);
            // companies.push_back(company);

            string name, profit_tax, address;
            stringstream ss(line);
            getline(ss, name, '|');
            getline(ss, profit_tax, '|');
            getline(ss, address);

            company.name = name;
            company.profit_tax = profit_tax;
            company.address = address;
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

const long long M = 1e9 + 9;
const long long BASE = 31;

// Way 1: Ordinary
// long long power(long long base, int n)
// {
//     if (n == 0)
//         return 1;
//     if (n == 1)
//         return base;
//     return power(base, n - 1) * base;
// }

// long long HashString(string company_name)
// {
//     int n = company_name.length();
//     string s = (n > 20) ? company_name.substr(n - 20) : company_name;
//     long long sigma = 0;
//     long long pow_base = 1;
//     for (int i = 0; i < n; i++)
//     {

//         sigma += ((int)s[i] * pow_base) % M;
//         pow_base = (pow_base * BASE) % M;
//     }
//     return (sigma + M) % M;
// }

// Way 2: Optmize
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
        sigma = (sigma + (long long)s[i] * pow_base) % M;
        pow_base = (pow_base * BASE) % M;
    }
    return sigma;
}

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

const int TABLE_SIZE = 50;
Node *CreateHashTable(vector<Company> list_company)
{
    Node *hash_table = new Node[TABLE_SIZE];
    for (const auto &company : list_company)
    {
        long long index = HashString(company.name) % TABLE_SIZE;
        Node *new_node = new Node(company);
        new_node->next = hash_table[index].next;
        hash_table[index].next = new_node;
    }
    return hash_table;
}

void Insert(Node *hash_table, Company company)
{
    long long index = HashString(company.name) % TABLE_SIZE;
    Node *new_node = new Node(company);

    // Add head
    new_node->next = hash_table[index].next;
    hash_table[index].next = new_node;

    // Add tail
    // if (hash_table[index].next == nullptr)
    //     hash_table[index].next = new_node;
    // else
    // {
    //     Node *cur = hash_table[index].next;
    //     while (cur->next != nullptr)
    //         cur = cur->next;
    //     cur->next = new_node;
    // }
}

Company *Search(Node *hash_table, string company_name)
{
    long long index = HashString(company_name);
    Node *current_node = &hash_table[index];

    while (current_node->next != nullptr)
    {
        current_node = current_node->next;
        if (current_node->data.name == company_name)
            return &current_node->data;
    }
    return NULL;
}

int main()
{
    vector<Company> companies = ReadCompanyList("MST.txt");
    // Node* hash_table = CreateHashTable(companies);

    // Insert new companies to the hash table
    Node *hash_table = CreateHashTable(companies);   
    Company new_company;
    new_company.name = "New Company";
    new_company.profit_tax = "10%";
    new_company.address = "123 Main St";
    Insert(hash_table, new_company);

    Company *search_company = new Company();
    search_company = Search(hash_table, "New Company");
    if (search_company != NULL)
        cout << "Found: " << search_company->name << endl;
    else
        cout << "Not found!" << endl;
}