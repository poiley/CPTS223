#include "Node.h"

//Constructor
Node::Node(Job j) { this->job = j; }

Node::Node(string job_descr, int n_procs, int n_ticks, int id) {
    this->job.job_descr = job_descr;
    this->job.n_procs   = n_procs;
    this->job.n_ticks   = n_ticks;
    this->job.id        = id;
}

// Destructor
Node::~Node() {}

// Getters
Job Node::getJob() { return this->job; }
Job Node::getConstJob() const { return this->job; }

// Setters
void Node::incrementTicks() { this->job.n_ticks -= 1; }

// Operators
bool Node::operator<(const Node &n) const { return this->job.n_ticks > n.getConstJob().n_ticks; }