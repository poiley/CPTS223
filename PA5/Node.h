#include <iostream>

using namespace std;

typedef struct job {
    string job_descr;
    int n_procs;
    int n_ticks;
    int id;
} Job;

class Node {
	public: 
		// Constructor:
		Node(Job j);
        Node(string job_descr, int n_procs, int n_ticks, int id);

        ~Node(); // Destructor

        Job getJob(); // Getter
        void incrementTicks(); // Setter 

        bool operator<(const Node &n) const; // Operator
	private: 
		Job job;

        Job getConstJob() const; // for reference in operator
};
