// CS223 - PA6
// Benjamin Poile, Brevin Simon
// Monday, December 3rd, 2018

#include "header.h"

int main() {
    vector<string> DataArray = readFile(ifstream("OHenry.txt"));
    vector<string> QueryArray = readFile(ifstream("queries.txt"));

    Chaining::HashTable<string> ChainingHT;
    Linear::HashTable<string> LinearProbingHT;
    Quadratic::HashTable<string> QuadraticProbingHT;

    cout << endl << "==INSERTION==" << endl;
    Data insert_chaining    = insertIntoHT(DataArray, ChainingHT);
    Data insert_linear      = insertIntoHT(DataArray, LinearProbingHT);
    Data insert_quadratic   = insertIntoHT(DataArray, QuadraticProbingHT);
    cout << "Chaining:" << endl;
    reportInsertionData(insert_chaining);
    cout << "Linear:" << endl;
    reportInsertionData(insert_linear);
    cout << "Quadratic:" << endl;
    reportInsertionData(insert_quadratic);

    cout << endl << "==SEARCHING==" << endl;
    Data search_chaining    = searchHT(QueryArray, ChainingHT);
    Data search_linear      = searchHT(QueryArray, LinearProbingHT);
    Data search_quadratic   = searchHT(QueryArray, QuadraticProbingHT);
    cout << "Chaining:" << endl;
    reportSearchData(search_chaining);
    cout << "Linear:" << endl;
    reportSearchData(search_linear);
    cout << "Quadratic:" << endl;
    reportSearchData(search_quadratic);

    cout << endl << "==INSERTION==" << endl;
    Data insert_quadratic_simple    = insertIntoHT_simple(DataArray, QuadraticProbingHT);
    Data insert_quadratic_prefix    = insertIntoHT_prefix(DataArray, QuadraticProbingHT);
    Data insert_quadratic_full      = insertIntoHT_full(DataArray, QuadraticProbingHT);
    cout << "Quadratic - Simple:" << endl;
    reportInsertionData(insert_quadratic_simple);
    cout << "Quadratic - Prefix:" << endl;
    reportInsertionData(insert_quadratic_prefix);
    cout << "Quadratic - Full:" << endl;
    reportInsertionData(insert_quadratic_full);

    cout << endl << "==SEARCHING==" << endl;
    Data search_quadratic_simple    = searchHT_simple(DataArray, QuadraticProbingHT);
    Data search_quadratic_prefix    = searchHT_prefix(DataArray, QuadraticProbingHT);
    Data search_quadratic_full      = searchHT_full(DataArray, QuadraticProbingHT);
    cout << "Quadratic - Simple:" << endl;
    reportInsertionData(search_quadratic_simple);
    cout << "Quadratic - Prefix:" << endl;
    reportInsertionData(search_quadratic_prefix);
    cout << "Quadratic - Full:" << endl;
    reportInsertionData(search_quadratic_full);
}

Data insertIntoHT(vector<string> DataArray, Chaining::HashTable<string> HT) {
    Data d;
    clock_t begin;
    
    for (auto ir = DataArray.crbegin(); ir != DataArray.crend(); ++ir) {
        if(!HT.contains(*ir)) {
            begin = clock();
            
            HT.insert(*ir);

            d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
            d.f++;
        }
    }

    return d;
}

Data insertIntoHT(vector<string> DataArray, Linear::HashTable<string> HT) {
    Data d;
    clock_t begin;
    
    for (auto ir = DataArray.crbegin(); ir != DataArray.crend(); ++ir) {
        if(!HT.contains(*ir)) {
            begin = clock();
            
            HT.insert(*ir);

            d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
            d.f++;
        }
    }

    return d;
}

Data insertIntoHT(vector<string> DataArray, Quadratic::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto ir = DataArray.crbegin(); ir != DataArray.crend(); ++ir)
    {
        if (!HT.contains(*ir))
        {
            begin = clock();

            HT.insert(*ir);

            d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
            d.f++;
        }
    }

    return d;
}

Data insertIntoHT_simple(vector<string> DataArray, Quadratic::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto ir = DataArray.crbegin(); ir != DataArray.crend(); ++ir)
    {
        if (!HT.contains(*ir))
        {
            begin = clock();

            HT.insert(*ir, 1);

            d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
            d.f++;
        }
    }

    return d;
}

Data insertIntoHT_prefix(vector<string> DataArray, Quadratic::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto ir = DataArray.crbegin(); ir != DataArray.crend(); ++ir)
    {
        if (!HT.contains(*ir))
        {
            begin = clock();

            HT.insert(*ir, 2);

            d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
            d.f++;
        }
    }

    return d;
}

Data insertIntoHT_full(vector<string> DataArray, Quadratic::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto ir = DataArray.crbegin(); ir != DataArray.crend(); ++ir) {
        if (!HT.contains(*ir)) {
            begin = clock();

            HT.insert(*ir, 3);

            d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
            d.f++;
        }
    }

    return d;
}

Data searchHT(vector<string> QueryArray, Chaining::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto i = QueryArray.crbegin(); i != QueryArray.crend(); ++i) {
        begin = clock();

        HT.contains(*i);

        d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
        d.f++;
    }

    return d;
}

Data searchHT(vector<string> QueryArray, Linear::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto i = QueryArray.crbegin(); i != QueryArray.crend(); ++i)
    {
        begin = clock();

        HT.contains(*i);

        d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
        d.f++;
    }

    return d;
}

Data searchHT(vector<string> QueryArray, Quadratic::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto i = QueryArray.crbegin(); i != QueryArray.crend(); ++i)
    {
        begin = clock();

        HT.contains(*i);

        d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
        d.f++;
    }

    return d;
}

Data searchHT_simple(vector<string> QueryArray, Quadratic::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto i = QueryArray.crbegin(); i != QueryArray.crend(); ++i)
    {
        begin = clock();

        HT.contains(*i, 1);

        d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
        d.f++;
    }

    return d;
}

Data searchHT_prefix(vector<string> QueryArray, Quadratic::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto i = QueryArray.crbegin(); i != QueryArray.crend(); ++i)
    {
        begin = clock();

        HT.contains(*i, 2);

        d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
        d.f++;
    }

    return d;
}

Data searchHT_full(vector<string> QueryArray, Quadratic::HashTable<string> HT) {
    Data d;
    clock_t begin;

    for (auto i = QueryArray.crbegin(); i != QueryArray.crend(); ++i)
    {
        begin = clock();

        HT.contains(*i, 3);

        d.f_time += double(clock() - begin) / CLOCKS_PER_SEC;
        d.f++;
    }

    return d;
}

vector<string> readFile(ifstream infile) {
    vector<string> in;
    string l;

    while(getline(infile, l))
        in.push_back(l);
    
    return in;
}

void reportInsertionData(Data d) {
    cout << "Insertion Time:\t"     << d.f_time
         << "\nInsertions:\t"       << d.f
         << "\nTime/Insertion:\t"   << (d.f_time / d.f) << endl << endl;
}

void reportSearchData(Data d) {
    cout << "Search Time:\t"    << d.f_time
         << "\nSearches:\t"     << d.f
         << "\nTime/Search:\t"  << (d.f_time / d.f) << endl << endl;
}
