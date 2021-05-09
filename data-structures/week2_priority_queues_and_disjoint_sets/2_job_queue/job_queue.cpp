#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;
using std::priority_queue;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  priority_queue<pair<long long, int>> time_heap;
  priority_queue<int> heap;


  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }


  void BuildHeap() {

    for(int i = 0; i<num_workers_; i++) {

      heap.push(-i);
    }
    
  }


  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    // Build Heap
    BuildHeap();

    long long time = 0;

    for(int i=0; i<jobs_.size(); i++) {

      /*cout << "outer" << std::endl;

      for(int j=0; j<heap.size(); j++) {

        cout << heap[j] << " ";
      }
      cout << std::endl;

      for(int j=0; j<time_heap.size(); j++) {
          cout << time_heap[j].first << "," << time_heap[j].second << " ";
        }
      
      cout << std::endl;*/

      int idx = heap.top();

      assigned_workers_[i] = -idx;
      start_times_[i] = -time;

      if (jobs_[i] > 0) {
        heap.pop();
        time_heap.push(make_pair(-(-time + jobs_[i]), idx));
      }
      
      if (heap.size() == 0) {

        /*cout << "inner" << std::endl;

        for(int j=0; j<time_heap.size(); j++) {
          cout << time_heap[j].first << "," << time_heap[j].second << " ";
        }

        cout << std::endl;*/

        pair<long long, int> out = time_heap.top();
        time_heap.pop();

        //cout << out.first << " " << out.second << std::endl;

        //cout << time_heap.size() << std::endl;
        heap.push(out.second);

        while ((time_heap.size() > 0) && (time_heap.top().first == out.first)) {
          //cout << "inner while" << std::endl;
          
          pair<long long, int> tmp = time_heap.top();
          time_heap.pop();
          //cout << tmp.first << " " << tmp.second << std::endl;
          //cout << time_heap.size() << std::endl;
          heap.push(tmp.second);
        }

        time = out.first;
      }
    }
  }

  void AssignJobs_Naive() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
