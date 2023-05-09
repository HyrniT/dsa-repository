#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

const int TABLE_SIZE = 200;

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
            int pos1 = line.find("|");
            int pos2 = line.find("|", pos1 + 1);
            company.name = line.substr(0, pos1);
            company.profit_tax = line.substr(pos1 + 1, pos2 - pos1 - 1);
            company.address = line.substr(pos2 + 1);
            companies.push_back(company);
        }
        file.close();
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

long long HashString(string company_name)
{
    string s = (company_name.length() < 20) ? company_name : company_name.substr(company_name.length() - 20);
    int n = s.length();
    long long sigma = 0;
    long long pow_base = 1;
    for (int i = 0; i < n; i++)
    {
        sigma = (sigma + (s[i] - 'a' + 1) * pow_base) % M;
        pow_base = (pow_base * BASE) % M;
    }
    return (sigma + M) % M; // add M to avoid negative values
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


Node *CreateHashTable(vector<Company> list_company)
{
    Node *hashTable = new Node[TABLE_SIZE];
    for (const auto &company : list_company)
    {
        long long index = HashString(company.name);
        Node new_node = Node(company);
        new_node.next = hashTable[index].next;
        hashTable[index].next = &new_node;
        // hashTable[index] = new_node;
    }
    return hashTable;
}

void Insert(Node *hash_table, Company company)
{
    long long index = HashString(company.name);
    Node *new_node = new Node(company);

    if (hash_table[index].next == nullptr)
        hash_table[index].next = new_node;
    else
    {
        Node *cur = hash_table[index].next;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new_node;
    }
}

int main()
{
    vector<Company> companies = ReadCompanyList("MST.txt");
    // Node* hash_table = CreateHashTable(companies);
    
    // // Insert new companies to the hash table
    // Company new_company;
    // new_company.name = "New Company";
    // new_company.profit_tax = "10%";
    // new_company.address = "123 Main St";
    // Insert(hash_table, new_company);

    // WriteCompanyList("output.txt", companies);
    string s= "A";
    cout<<HashString(s)<<endl;
}