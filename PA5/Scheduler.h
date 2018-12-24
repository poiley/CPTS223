#include "Node.h"

#include <queue>
#include <iterator>
#include <unistd.h>

using namespace std;

class Scheduler {
	public: 
		// Constructor:
		Scheduler(int processors);

		// Destructor
		~Scheduler();

		bool InsertJob(string job_descr, int n_procs, int n_ticks);
		bool InsertJob(Job j);

		void DecrementTimer();

		bool isDone();
	private:
		Node FindShortest();

		bool CheckAvailability(int n_procs);
		int GenerateID();

		void RunJob(Node task);

		bool DeleteShortest();

		bool ReleaseProcs(int n_procs);
		bool ReleaseProcs(Job j);

		int id_tracker;		// Counter for ID's; ensures no duplicate ID's.
		int p;				// Procs total
		int p_available; 	// Procs not in use

		priority_queue<Node> pq; //Queue for inserting jobs
		priority_queue<Node> w_pq; //Wait Queue - Take jobs from here
};
