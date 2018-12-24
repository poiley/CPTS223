#include "Scheduler.h"

//Constructor
Scheduler::Scheduler(int processors) {
    this->id_tracker = 0;
    this->p = this->p_available = processors;
}

//Destructor
Scheduler::~Scheduler() { this->w_pq.empty(); this->pq.empty(); }

bool Scheduler::isDone() { return this->w_pq.empty(); }

bool Scheduler::InsertJob(Job j) { return this->InsertJob(j.job_descr, j.n_procs, j.n_ticks); }

bool Scheduler::InsertJob(string job_descr, int n_procs, int n_ticks) {
    Node n = Node(job_descr, n_procs, n_ticks, this->GenerateID()); //ASSIGN DATA AND GENERATE ID
    
    // Ensure node is valid and okay to insert into wait pq.
    if (!(0 < n_procs && n_procs <= this->p_available && n_ticks > 0)) {
        cout << "Job Submission Error!" << endl;
        return false;
    }

    this->w_pq.push(n);
    this->p_available -= n_procs;

    cout << "Job successfully pushed!" << endl;
    cout << "Available processors:\t" << this->p_available << "/" << this->p << endl;
    
    return true;
}

Node Scheduler::FindShortest(void) {
	int smallest = 10000;
	Node holdNode = Node("", -1, -1, -1);

    priority_queue<Node> temp = w_pq;

	while (!temp.empty()) {
        Node n = temp.top();
        if (n.getJob().n_ticks < smallest)
            holdNode = temp.top();

        temp.pop();
	}

	return holdNode;
}

bool Scheduler::CheckAvailability(int n_procs) {
    if (this->p_available < n_procs)
        return false;
    return true;
}

bool Scheduler::DeleteShortest() {
    if(this->w_pq.empty())
        return false;
    this->ReleaseProcs(this->FindShortest().getJob());
    this->w_pq.pop();
    return true;
}

void Scheduler::RunJob(Node task) {
    Node pCur = this->FindShortest();
    this->DeleteShortest();
    w_pq.push(pCur);
}

int Scheduler::GenerateID() { return ++this->id_tracker; }

void Scheduler::DecrementTimer() {
    priority_queue<Node> temp = pq;
    priority_queue<Node> editQ, incQ;

    /*  While processors are available for the shortest job
        //It will execute them until there are not enough
        Processors left or the wait queue is empty        */
    while (!w_pq.empty()) {
        if (!CheckAvailability(this->FindShortest().getJob().n_procs))
            continue;

        for (int i = 0; i < pq.size(); i++) {
            while(!pq.empty()) { //Subtract 1 from all the n_ticks
                Node n = this->pq.top();
                this->pq.pop();

                n.incrementTicks();

                editQ.push(n);
            }
            
            while ( !editQ.empty() ) {
                Node n = editQ.top();
                editQ.pop();

                this->pq.push(n);
                
                if(n.getJob().n_ticks == 0) { //When this runs out we release procs
                    ReleaseProcs(n.getJob()); //Release them
                    Node n = this->w_pq.top();
                    cout << "A\t"<<n.getJob().job_descr << endl;
                    this->w_pq.pop(); //Remove from list
                }
            }
        }

        usleep(1000);
        //Run job of next shortest one. And this inserts
        //Next job at the next available tick
        this->RunJob(this->FindShortest());

        //Remove the task ran from the wait queue
        w_pq.pop();
   }
}

bool Scheduler::ReleaseProcs(Job j) {
    cout << "Job '" << j.job_descr << "' is finished. Freeing " << j.n_procs << " processors." << endl;
    
    if(!j.n_procs)
        return false;
        
    this->p_available += j.n_procs;
    return true;
}

bool Scheduler::ReleaseProcs(int n_procs) {
    if(n_procs <= 0)
        return false;
        
    this->p_available += n_procs;
    return true;
}
