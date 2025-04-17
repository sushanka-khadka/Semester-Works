//  Job Sequencing with deadline(Greedy Algorithm)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
	char id;
	int deadline, profit;	
};

bool JobCompare(Job j1, Job j2){
	return (j1.profit > j2.profit);
}

void JobSequencing (vector <Job> & jobs, int n){
	sort(jobs.begin(), jobs.end(), JobCompare);
	vector <int> result (n, -1);	// -1 means no jobs is scheduled
	int totalProfit= 0;
	for(int i=0; i<n; i++){
		for(int j=jobs[i].deadline -1; j>=0; j--){
			if(result[j] == -1){
				result[j] = i;
				totalProfit += jobs[i].profit;
				break;
			}
		}
	}
	cout<<"Job Sequence: ";
	for(int i=0; i<n; i++){
		if(result[i] != -1)
			cout<<jobs[result[i]].id <<' ';			
	}
	cout<<"\nTotal Profit: "<<totalProfit<<endl;	
}

int main(){
//	vector <Job> jobs = {{1,4,20}, {2,1,10}, {3,1,40}, {4,1,30}};
	vector<Job> jobs = {{'A', 2, 100}, {'B', 1, 50}, {'C', 2, 10}, {'D', 1, 20}, {'E', 3, 30}};

	int n= jobs.size();
	cout<<"---------Job Sequencing with deadline(Greedy Algorithm)---------"<<endl;
	JobSequencing(jobs,n);

	return 0;
}