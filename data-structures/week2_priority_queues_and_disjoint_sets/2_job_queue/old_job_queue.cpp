#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  vector<pair<long long, int>> time_heap;
  vector<int> heap;


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

      heap[i] = i;
    }

    int n = heap.size();

    if (n % 2 != 0) {
      n = n/2 + 1;
    }

    else {
      n = n/2;
    }

    for(int i=n; i>=0; i--) {

      SiftDown(i);
    }
    
  }

  void SiftDown(int i) {
    // We are now sifting down higher values since
    // this is a min-heap

    int n = heap.size();

    int l = 2*i + 1;
    int r = 2*i + 2;

    int index = i;

    if ((l < n) && (heap[index] > heap[l])) {
      // 
      index = l;
    }

    if ((r < n) && (heap[index] > heap[r])) {
      // 
      index = r;
    }

    if (index != i) {

      int tmp = heap[i];

      heap[i] = heap[index];

      heap[index] = tmp;

      SiftDown(index);
    }

  }


  int ExtractMin() {

    int tmp = heap[0];

    heap[0] = heap[heap.size()-1];
    
    heap.pop_back();

    SiftDown(0);

    return tmp;
  }

  void SiftUp(int i) {

    int parent = (i-1)/2;

    while ((i > 0) && (heap[parent] > heap[i])) {

      int tmp = heap[parent];

      heap[parent] = heap[i];

      heap[i] = tmp;

      i = parent;

      parent = (i-1)/2;
    }
  }

  void InsertHeap(int i) {

    heap.push_back(i);
    SiftUp(heap.size()-1);

  }

  void SiftDownM(int i) {

    int n = time_heap.size();

    int l = 2*i + 1;
    int r = 2*i + 2;

    int index = i;

    if ((l < n) && (time_heap[index].first > time_heap[l].first)) {
      // 
      index = l;
    }

    if ((r < n) && (time_heap[index].first > time_heap[r].first)) {
      // 
      index = r;
    }

    if (index != i) {

      pair<long long, int> tmp = time_heap[i];

      time_heap[i] = time_heap[index];

      time_heap[index] = tmp;

      SiftDownM(index);
    }
  }

  pair<long long, int> ExtractMinM() {

    pair<long long, int> out = time_heap[0];

    time_heap[0] = time_heap[time_heap.size()-1];
    
    time_heap.pop_back();

    SiftDownM(0);

    return out;
  }


  void SiftUpM(int i) {

    int parent = (i-1)/2;

    while ((i > 0) && (time_heap[parent].first > time_heap[i].first)) {

      pair<int, int> tmp = time_heap[parent];

      time_heap[parent] = time_heap[i];

      time_heap[i] = tmp;

      i = parent;

      parent = (i-1)/2;
    }
  }

  void InsertM(long long time, int idx) {

    time_heap.push_back(make_pair(time, idx));

    SiftUpM(time_heap.size()-1);
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    
    heap.resize(num_workers_);

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

      int idx = heap[0];

      assigned_workers_[i] = idx;
      start_times_[i] = time;

      if (jobs_[i] > 0) {
        int tmp = ExtractMin();
        InsertM(time + jobs_[i], idx);
      }
      
      if (heap.size() == 0) {

        /*cout << "inner" << std::endl;

        for(int j=0; j<time_heap.size(); j++) {
          cout << time_heap[j].first << "," << time_heap[j].second << " ";
        }

        cout << std::endl;*/

        pair<long long, int> out = ExtractMinM();

        //cout << out.first << " " << out.second << std::endl;

        //cout << time_heap.size() << std::endl;
        InsertHeap(out.second);

        while ((time_heap.size() > 0) && (time_heap[0].first == out.first)) {
          //cout << "inner while" << std::endl;
          
          pair<long long, int> tmp = ExtractMinM();
          //cout << tmp.first << " " << tmp.second << std::endl;
          //cout << time_heap.size() << std::endl;
          InsertHeap(tmp.second);
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
